#ifndef __TECMA_DEPENDENCIES_H
#define __TECMA_DEPENDENCIES_H

#include <vector>
#include <string>

typedef unsigned int TecmaBool;

#define __TECMA_TRUE  1
#define __TECMA_FALSE 0 

#define __TECMA_EOF '\0' 
#define __TECMA_ENDL "\n"
#define __TECMA_TAB "\t"

#define __TECMA_FILE_RB "rb"

#define __TECMA_SHADER_EXT_LEN 9
#define __TECMA_VERT_SHADER_EXT ".vert.spv"
#define __TECMA_FRAG_SHADER_EXT ".frag.spv"
#define __TECMA_COMP_SHADER_EXT ".comp.spv"

#define __TECMA_SPIRV_WIZARD_NUM 0x07230203

// shit for utf8.
#define __TECMA_UTF8_SIZE_1 ((1 << 7))
#define __TECMA_UTF8_SIZE_2 ((1 << 8) + (1 << 7))
#define __TECMA_UTF8_SIZE_3 ((1 << 8) + (1 << 7) + (1 << 6))
#define __TECMA_UTF8_SIZE_4 ((1 << 8) + (1 << 7) + (1 << 6) + (1 << 5))

#ifndef __TECMA_ENUM_H
    #include "tecma_enum.h"
#endif

#ifndef __TECMA_LOGGER_H
    #include "tecma_logger.h"
#endif

// op entry point util messages shit

#define __SPV_INFO_OP_ETNRY_POINT_MSG "TecmaSpirvInstructionFlag: "
#define __SPV_INFO_EXECUTION_MODEL_MSG __TECMA_TAB "OpEntryPoint execution model:" __TECMA_TAB
#define __SPV_INFO_ID_MSG __TECMA_TAB "OpEntryPoint ID:" __TECMA_TAB __TECMA_TAB
#define __SPV_INFO_NAME_MSG __TECMA_TAB "OpEntryPoint name:" __TECMA_TAB __TECMA_TAB

// op capability

#define __SPV_INFO_OP_CAPABILITY_MSG "TecmaSpirvCapabilityFlag: "
#define __SPV_INFO_CAPABILITY_MSG __TECMA_TAB "OpCapability:" __TECMA_TAB __TECMA_TAB

namespace TecmaEngine {
    template<typename __alignType>
    struct TecmaFileByteData { __alignType* __data; long __size; };

    struct TecmaSpirvMemberName {
        std::string __member;
        std::string __name;

    };

    struct TecmaSpirvEntryPointInfo_i { // 15
        TecmaSpirvExecutionModelFlag __execModel;
        unsigned int __id;
        std::string __name;

        inline void DisplayEntryPointInfo() const noexcept {
            TecmaLogger( std::string(
                    std::string( __SPV_INFO_EXECUTION_MODEL_MSG ) + 
                    GetTecmaSpirvExecutionModelFlagMessage( __execModel ) + __TECMA_ENDL +
                    __SPV_INFO_ID_MSG +
                    std::to_string( __id ) + __TECMA_ENDL +
                    __SPV_INFO_NAME_MSG +
                    __name + __TECMA_ENDL
                ).c_str() 
            );

        }

    };

    struct TecmaSpirvCapabilityInfo_i { // 17
        TecmaSpirvCapabilityFlag __capa;
        
        inline void DisplayCapabilityInfo() {
            TecmaLogger(
                std::string(
                    std::string( __SPV_INFO_CAPABILITY_MSG ) + 
                    GetTecmaSpirvCapabilityFlagMessage( __capa ) + __TECMA_ENDL
                ).c_str() 
            );

        }

    };

}

#endif