#ifndef __TECMA_ENGINE_H
#define __TECMA_ENGINE_H

#ifndef __TECMA_VK_RENDERER_H
    #include "../_Vulkan/tecma_vk_renderer.h"
#endif

namespace TecmaEngine {
    typedef struct TecmaApplication {
        explicit TecmaApplication() noexcept;
        ~TecmaApplication() noexcept;

        void InitEngineApplication();

        private:
            TecmaVkRenderer __renderer;

    } TecmaApplication_t;

};

#endif