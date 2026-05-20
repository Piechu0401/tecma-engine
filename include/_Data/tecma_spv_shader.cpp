#include "tecma_spv_shader.h"

namespace TecmaEngine {
    TecmaSpvShader_t::TecmaSpvShader_t() noexcept :
        __shadFileData({ nullptr, 0 })
    {}
        
    TecmaSpvShader_t::TecmaSpvShader_t(
        TecmaSpvShader_t& __other
    ) noexcept {}
        
    TecmaSpvShader_t::TecmaSpvShader_t(
        TecmaSpvShader_t&& __other
    ) noexcept {}

    TecmaSpvShader_t::~TecmaSpvShader_t() noexcept {}

    void TecmaSpvShader_t::IdentirfyValidateInstruction(
        const unsigned int& __opcode,
        const unsigned int& __size,
        const unsigned int* __words,
        int __idx
    ) {
        TecmaLogger( std::string( __TECMA_ENUM_SPIRV_OP_NAME ": " + std::string( GetTecmaSpirvOpFlagMessage( (TecmaSpirvOpFlag)__opcode ) ) + __TECMA_ENDL ).c_str() );
        // [ Execution model ] [ ID entry point ] [ Literal name ] [ interface ]
        if( __opcode == TECMA_SPV_OP_ENTRY_POINT ) {
            // execution model will provide info on what
            // stage that fucker is
            // no two entry points with same
            
            TecmaSpirvEntryPointInfo_i __info{};

            __info.__execModel = 
                (TecmaSpirvExecutionModelFlag)*(__words + __idx + 1);
            __info.__id = *(__words + __idx + 2);

            __idx += 3;

            std::vector<char> __utf8Chars;
            while( *(__words + __idx + (__utf8Chars.size() >> 2)) ) {
                __utf8Chars.emplace_back(
                    (char)((*(__words + __idx + (__utf8Chars.size() >> 2))))
                );

                __utf8Chars.emplace_back(
                    (char)((*(__words + __idx + (__utf8Chars.size() >> 2))) >> 8)
                );

                __utf8Chars.emplace_back(
                    (char)((*(__words + __idx + (__utf8Chars.size() >> 2))) >> 16)
                );

                __utf8Chars.emplace_back(
                    (char)((*(__words + __idx + (__utf8Chars.size() >> 2))) >> 24)
                );

            }

            __info.__name = ReadUTF8(
                __utf8Chars
            );

            __entryPts.emplace_back( __info );
            // __entryPts.back().DisplayEntryPointInfo();

        }
        else if( __opcode == TECMA_SPV_OP_CAPABILITY ) {
            TecmaSpirvCapabilityInfo_i __info{ (TecmaSpirvCapabilityFlag)*(__words + __idx + 1) };

            // __info.DisplayCapabilityInfo();

        }


    }

    void TecmaSpvShader_t::FetchShaderData(
        const TecmaFileByteData<unsigned char> __data
    ) {
        __shadFileData = __data;
    
        const unsigned int* __words{
            reinterpret_cast<unsigned int*>( __shadFileData.__data )
        }; // yeah yeah very evil cast, but who cares

        // this is magic number and besides telling us its .spv
        // it also gives a hint on if for example literals should be read in reverse
        // atleast from what I understood
        // like m a i n and n i a m hidden in bytes of let's say EntryPoint section
        // for now im only checking one value: 0x07230203
        if( *__words != __TECMA_SPIRV_WIZARD_NUM ) TecmaLogger( TECMA_ERROR_SPV_FILE_IS_INVALID );

        for( int __i{5}; __i < (__shadFileData.__size >> 2); ) {
            // here will be some shit to intepret it
            IdentirfyValidateInstruction(
                (*(__words + __i) & 0xFFFF),
                (*(__words + __i) >> 16),
                __words,
                __i
            );

            if( !(*(__words + __i) >> 16) ) break;
                __i += (*(__words + __i) >> 16);
        
        }


    }

};