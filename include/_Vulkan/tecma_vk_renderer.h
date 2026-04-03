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

namespace TecmaEngine {
    typedef struct TecmaVkRenderer {
        explicit TecmaVkRenderer() noexcept;
        explicit TecmaVkRenderer(
            const TecmaVkRenderer& __other
        ) noexcept;
        explicit TecmaVkRenderer(
            const TecmaVkRenderer&& __other
        ) noexcept;
        ~TecmaVkRenderer() noexcept;

        void InitRenderer();

        private:
            #if defined(__TECMA_XLIB)
                Display* __dsp;
                Window __wnd;
            #endif

            TecmaVkInstance_t __tecmaInst;
            TecmaVkDebugUtils_t __tecmaDebug;
            TecmaVkSurface_t __tecmaSurf;
            std::vector<TecmaVkDevice_t> __tecmaDevs;

            void CreateEngineWindow();
            void GetAvailableDevices();

    } TecmaVkRenderer_t;

};

#endif
