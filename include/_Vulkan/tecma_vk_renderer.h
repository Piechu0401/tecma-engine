#ifndef __TECMA_VK_RENDERER_H
#define __TECMA_VK_RENDERER_H

#include <stdlib.h>

#ifndef __TECMA_VK_INSTANCE_H
    #include "tecma_vk_instance.h"
#endif

#ifndef __TECMA_VK_DEBUG_UTILS_H
    #include "tecma_vk_debug_utils.h"
#endif

#ifndef __TECMA_VK_SURFACE_H
    #include "tecma_vk_surface.h"
#endif

#ifndef __TECMA_VK_DEVICE_H
    #include "tecma_vk_device.h"
#endif

#ifndef __TECMA_VK_SWAPCHAIN_H
    #include "tecma_vk_swapchain.h"
#endif

#ifndef __TECMA_VK_IMAGE_H
    #include "tecma_vk_image.h"
#endif

namespace TecmaEngine {
    struct TecmaVkRenderer_t {
        explicit TecmaVkRenderer_t() noexcept;
        explicit TecmaVkRenderer_t(
            const TecmaVkRenderer_t& __other
        ) noexcept;
        explicit TecmaVkRenderer_t(
            const TecmaVkRenderer_t&& __other
        ) noexcept;
        ~TecmaVkRenderer_t() noexcept;

        void InitRenderer();

        private:
            #if defined(__TECMA_XLIB)
                Display* __dsp = nullptr;
                Window __wnd = 0;
            #endif

            TecmaVkInstance_t __tecmaInst;
            TecmaVkDebugUtils_t __tecmaDebug;
            TecmaVkSurface_t __tecmaSurf;
            TecmaVkDevice_t __tecmaDev;
            TecmaVkSwapchain_t __tecmaSwchain;
            TecmaVkImage_t __tecmaDepthResource;

            void CreateEngineWindow();
            void GetAvailableDevices();

    };

};

#endif
