#ifndef __TECMA_SPV_SHADER_H
#define __TECMA_SPV_SHADER_H

#ifndef __TECMA_CORE_H
    #include "../_Core/tecma_core.h"
#endif

namespace TecmaEngine {
    struct TecmaSpvShader_t {
        explicit TecmaSpvShader_t() noexcept;
        
        explicit TecmaSpvShader_t(
            TecmaSpvShader_t& __other
        ) noexcept;
        
        explicit TecmaSpvShader_t(
            TecmaSpvShader_t&& __other
        ) noexcept;

        ~TecmaSpvShader_t() noexcept;

        void FetchShaderData(
            const TecmaFileByteData<unsigned char> __data
        );

        // OpEntryPoints
        std::vector<TecmaSpirvEntryPointInfo_i> __entryPts;
        
        TecmaFileByteData<unsigned char> __shadFileData;

        private:
            void IdentirfyValidateInstruction(
                const unsigned int& __opcode,
                const unsigned int& __size,
                const unsigned int* __words,
                int __idx
            );

    };

};

#endif