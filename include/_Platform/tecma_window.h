#ifndef __TECMA_WINDOW_H
#define __TECMA_WINDOW_H

#if defined(__TECMA_WAYLAND)
    #include <wayland-client.h>
#elif defined(__TECMA_XLIB)
    #include <X11/Xlib.h>
#elif defined(__TECMA_WINDOWS) 
    #include <windows.h>
#endif

#include "../_Core/tecma_core.h"

namespace TecmaEngine {
    struct TecmaWindow_t {
        explicit TecmaWindow_t() noexcept;
        
        explicit TecmaWindow_t(
            const TecmaWindow_t& __other
        ) noexcept;
        
        explicit TecmaWindow_t(
            const TecmaWindow_t&& __other
        ) noexcept;

        ~TecmaWindow_t() noexcept;

        void CreateWindow(
            const TecmaWindowCreateInfo_ci& __ci
        );

        void DestroyWindow();

        TecmaBool __open;
        TecmaVkSurfaceDependencies_t __surfDep;

    };

};

#endif