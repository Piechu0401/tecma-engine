#ifndef __TECMA_VK_SURFACE_H
#define __TECMA_VK_SURFACE_H

#include "tecma_vk_core.h"

namespace TecmaEngine {
    typedef struct TecmaVkSurface {
        explicit TecmaVkSurface() noexcept;
        explicit TecmaVkSurface(
            const TecmaVkSurface& __other
        ) noexcept;
        explicit TecmaVkSurface(
            const TecmaVkSurface&& __other
        ) noexcept;
        ~TecmaVkSurface() noexcept;

        #if defined(__TECMA_LINUX)
            #if defined(__TECMA_XLIB)
                void CreateVkSurface(
                    const VkInstance& __inst,
                    Display* __dsp,
                    Window __wnd
                );
            #endif
        #endif

        void DestroyVkSurface(
            const VkInstance& __inst
        ) const noexcept;

        VkSurfaceKHR __surf;

    } TecmaVkSurface_t;

};

#endif