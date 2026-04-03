#include "tecma_vk_surface.h"
#include <vulkan/vulkan_core.h>

namespace TecmaEngine {
    TecmaVkSurface::TecmaVkSurface() noexcept {}
    
    TecmaVkSurface::TecmaVkSurface(
        const TecmaVkSurface& __other
    ) noexcept {}

    TecmaVkSurface::TecmaVkSurface(
        const TecmaVkSurface&& __other
    ) noexcept {}

    TecmaVkSurface::~TecmaVkSurface() noexcept {}               

    #if defined(__TECMA_LINUX)
        #if defined(__TECMA_XLIB)
            void TecmaVkSurface::CreateVkSurface(
                const VkInstance& __inst,
                Display* __dsp,
                Window __wnd
            ) {
                if( !__dsp ) TecmaLogger( TECMA_ERROR_XLIB_DISPLAY_NULL );
                else if( !__wnd ) TecmaLogger( TECMA_ERROR_XLIB_WINDOW_ZERO );

                VkXlibSurfaceCreateInfoKHR __info{};

                __info.sType = VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR;
                __info.pNext = nullptr;
                __info.flags = 0;
                __info.dpy = __dsp;
                __info.window = __wnd;

                TecmaLogger(
                    (TecmaVkResult)vkCreateXlibSurfaceKHR(
                        __inst,
                        &__info,
                        NULL,
                        &__surf
                    ),
                    VK_FUNCTION_FLAG_VK_CREATE_SURFACE_KHR
                );

            }
        #endif
    #endif

    void TecmaVkSurface::DestroyVkSurface(
        const VkInstance& __inst
    ) const noexcept {
        vkDestroySurfaceKHR(
            __inst,
            __surf,
            NULL
        );

        TecmaLogger(
            VK_SUCCESS,
            VK_FUNCTION_FLAG_VK_DESTROY_SURFACE_KHR
        );

    }

};