#ifndef __TECMA_INPUT_H
    #include "../include/_Platform/tecma_input.h"
#endif

#ifndef __TECMA_WINDOW_H
    #include "../include/_Platform/tecma_window.h"
#endif

#ifndef __TECMA_SPV_SHADER_H
    #include "../include/_Data/tecma_spv_shader.h"
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
    __vk.CreateVulkan( 
        __wnd.__surfDep, 
        { "../TecmaEngine/shaders" }
    );

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
    // TecmaEngine::TecmaWindow_t __wnd;
    // TecmaEngine::TecmaVulkan_t __vk;

    // InitTecmaEngine(
    //     __wnd,
    //     __vk
    // );

    // while( __wnd.__open ) {
    //     #if defined(__TECMA_XLIB)
    //         __wnd.CheckForEvents();
    // 
    //     #endif
    // 
    // }

    //ShutdownTecmaEngine(
    //    __wnd,
    //    __vk
    //);

    TecmaEngine::TecmaSpvShader_t __shader;

    const char* __path{"../TecmaEngine/shaders/shad.vert.spv"};

    TecmaEngine::TecmaFileByteData<unsigned char> __data{
        TecmaEngine::TecmaInput.ReadFileData<unsigned char>(
            __path
        )
    };
    
    __shader.FetchShaderData(
        __data
    );

    return 0;

}

// ignore this, you can see what it was, now its relict of the past.
// g++ -o0 build/Te.cpp include/_*/*.cpp -Iinclude/*.h -o build/app -lvulkan