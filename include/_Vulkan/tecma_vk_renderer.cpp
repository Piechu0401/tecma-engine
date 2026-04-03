#include "tecma_vk_renderer.h"

namespace TecmaEngine {
    TecmaVkRenderer::TecmaVkRenderer() noexcept {}
    TecmaVkRenderer::TecmaVkRenderer(
        const TecmaVkRenderer& __other
    ) noexcept {}
    TecmaVkRenderer::TecmaVkRenderer(
        const TecmaVkRenderer&& __other
    ) noexcept {}
    TecmaVkRenderer::~TecmaVkRenderer() noexcept {
        for( auto& __dev : __tecmaDevs )
            __dev.DestroyVkDevice();

        __tecmaSurf.DestroyVkSurface( 
            __tecmaInst.__inst
        );

        __tecmaDebug.DestroyVkDebugUtilsMessenger(
            __tecmaInst.__inst
        );

        __tecmaInst.DestroyVkInstance();

        #if defined(__TECMA_XLIB)
            XUnmapWindow( __dsp, __wnd );
            XCloseDisplay( __dsp );
        #endif

    }

    void TecmaVkRenderer::GetAvailableDevices() {
        unsigned int __count{0};

        TecmaLogger(
            (TecmaVkResult)vkEnumeratePhysicalDevices(
                __tecmaInst.__inst,
                &__count,
                NULL
            ),
            VK_FUNCTION_FLAG_VK_ENUMERATE_PHYSICAL_DEVICES
        );

        VkPhysicalDevice __physDevs[__count];

        TecmaLogger(
            (TecmaVkResult)vkEnumeratePhysicalDevices(
                __tecmaInst.__inst,
                &__count,
                __physDevs
            ),
            VK_FUNCTION_FLAG_VK_ENUMERATE_PHYSICAL_DEVICES
        );

        __tecmaDevs.resize( __count );

        for( int __i{0}; __i < __count; ++__i ) {
            TecmaVkDeviceLayersSupported( __physDevs[__i] );
            TecmaVkDeviceExtensionsSupported( __physDevs[__i] );

            __tecmaDevs[__i].CreateVkDevice(
                __tecmaInst.__inst,
                __physDevs[__i]
            );

        }

    }

    void TecmaVkRenderer::CreateEngineWindow() {
        #if defined(__TECMA_XLIB)
            __dsp = XOpenDisplay(NULL);
            if( !__dsp ) TecmaLogger(TECMA_ERROR_XLIB_DISPLAY_FAILED);
            
            __wnd = XCreateSimpleWindow(
                __dsp,
                DefaultRootWindow( __dsp ),
                0,
                0,
                800,
                800,
                0,
                0,
                0
            );

            if( !__wnd ) TecmaLogger(TECMA_ERROR_XLIB_WINDOW_FAILED);

            XMapWindow( __dsp, __wnd );
            
        #endif

    }

    void TecmaVkRenderer::InitRenderer() {
        TecmaVkInstanceLayersSupported();
        TecmaVkInstanceExtensionsSupported();

        CreateEngineWindow();

        __tecmaInst.CreateVkInstance(
            __TECMA_ENGINE_NAME,
            __TECMA_ENGINE_VERSION
        );

        __tecmaDebug.CreateVkDebugUtilsMessenger(
            __tecmaInst.__inst
        );

        #if defined(__TECMA_XLIB)
            __tecmaSurf.CreateVkSurface(
                __tecmaInst.__inst,
                __dsp,
                __wnd
            );
        #endif

        GetAvailableDevices();

    }

};