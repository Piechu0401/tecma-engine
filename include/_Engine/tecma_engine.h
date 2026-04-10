#ifndef __TECMA_ENGINE_H
#define __TECMA_ENGINE_H

#ifndef __TECMA_VK_RENDERER_H
    #include "../_Vulkan/tecma_vk_renderer.h"
#endif

namespace TecmaEngine {
    struct TecmaApplication_t {
        explicit TecmaApplication_t() noexcept;
        
        explicit TecmaApplication_t(
            const TecmaApplication_t& __other
        ) noexcept;

        explicit TecmaApplication_t(
            const TecmaApplication_t&& __other
        ) noexcept;
        
        ~TecmaApplication_t() noexcept;

        void InitEngineApplication();

        private:
            TecmaVkRenderer_t __renderer;

    };

};

#endif