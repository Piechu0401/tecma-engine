#include "tecma_vk_renderer.h"
#include <vulkan/vulkan_core.h>

namespace TecmaEngine {
    TecmaVkRenderer_t::TecmaVkRenderer_t() noexcept {}
    TecmaVkRenderer_t::TecmaVkRenderer_t(
        const TecmaVkRenderer_t& __other
    ) noexcept {}
    TecmaVkRenderer_t::TecmaVkRenderer_t(
        const TecmaVkRenderer_t&& __other
    ) noexcept {}
    TecmaVkRenderer_t::~TecmaVkRenderer_t() noexcept {
        __tecmaDepthResource.DestroyImages(
            __tecmaDev.__dev
        );
        
        __tecmaSwchain.DestroyVkSwapchain(
            __tecmaDev.__dev
        );
        
        __tecmaDev.DestroyVkDevice();

        __tecmaSurf.DestroyVkSurface( 
            __tecmaInst.__inst
        );

        __tecmaDebug.DestroyVkDebugUtilsMessenger(
            __tecmaInst.__inst
        );

        __tecmaInst.DestroyVkInstance();

        #if defined(__TECMA_XLIB)
            XUnmapWindow( __dsp, __wnd );
            // XCloseDisplay( __dsp );
        #endif

    }

    void TecmaVkRenderer_t::CreateEngineWindow() {
        #if defined(__TECMA_XLIB)
            __dsp = XOpenDisplay( NULL );
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

    void TecmaVkRenderer_t::InitRenderer() {
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

        __tecmaDev.CreateVkDevice(
            __tecmaInst.__inst
        );

        #if defined(__TECMA_XLIB)
            __tecmaSurf.CreateVkSurface(
                __tecmaInst.__inst,
                __tecmaDev.__physDev,
                &__dsp,
                __wnd
            );
        #endif

        __tecmaSwchain.CreateVkSwapchain(
            __tecmaDev.__dev, 
            __tecmaSurf.__surf, 
            __tecmaSurf.__surfColorForm,
            __tecmaSurf.__surfCapa, 
            __tecmaSurf.__presMode,
            __tecmaDev.GetFamilyIndices()
        );

        __tecmaDepthResource.CreateImages(
            __tecmaDev.__dev,
            __tecmaSurf.__surfCapa.minImageCount + 1,
            __tecmaDev.FindMemoryIndex( VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT ),
            __tecmaSurf.__depthForm,
            VK_IMAGE_ASPECT_DEPTH_BIT,
            __tecmaSurf.GetVkExtent3D(),
            __tecmaDev.GetFamilyIndices()
        );

    }

};