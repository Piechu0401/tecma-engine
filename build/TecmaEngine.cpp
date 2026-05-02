#ifndef __TECMA_WINDOW_H
    #include "../include/_Platform/tecma_window.h"
#endif

#ifndef __TECMA_VULKAN_H
    #include "../include/_Vulkan/tecma_vulkan.h"
#endif

inline static void InitTecmaEngine(
    TecmaEngine::TecmaWindow_t& __wnd,
    TecmaEngine::TecmaVulkan_t& __vk
) {
    __wnd.CreateWindow(
        {
            .__w = __TECMA_INIT_WND_W,
            .__h = __TECMA_INIT_WND_H,
            .__x = __TECMA_INIT_WND_X,
            .__y = __TECMA_INIT_WND_Y,
            .__bordSize = 0,
            .__backgrdClr = 0,
            .__bordClr = 0,
            .__title = __TECMA_ENGINE_NAME,
        }
    );
    __vk.CreateVulkan( __wnd.__surfDep );

}

inline static void ShutdownTecmaEngine(
    TecmaEngine::TecmaWindow_t& __wnd,
    TecmaEngine::TecmaVulkan_t& __vk   
) {
    __vk.DestroyVulkan();
    __wnd.DestroyWindow();

}

int main(
    const int __argc,
    const char* __argv[]
) {
    TecmaEngine::TecmaWindow_t __wnd;
    TecmaEngine::TecmaVulkan_t __vk;

    InitTecmaEngine(
        __wnd,
        __vk
    );

    while( __wnd.__open ) {
        #if defined(__TECMA_XLIB)
            XEvent __eve;
            while( XPending( __wnd.__surfDep.__dsp ) ) { 
                XNextEvent( 
                    __wnd.__surfDep.__dsp, 
                    &__eve 
                );

                if( // temporary escape from loop so i dont need to pkill TecmaEngine every fucking time
                    __eve.type == KeyPress ||
                    __eve.type == ButtonPress
                ) { __wnd.__open = __TECMA_FALSE; }
            
            }
    
        #endif
    
    }

    ShutdownTecmaEngine(
        __wnd,
        __vk
    );

    return 0;

}

// g++ -o0 build/Te.cpp include/_*/*.cpp -Iinclude/*.h -o build/app -lvulkan