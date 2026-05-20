#ifndef __TECMA_WINDOW_H
#define __TECMA_WINDOW_H

#if defined(__TECMA_WAYLAND)
    #include <wayland-client.h>
#elif defined(__TECMA_XLIB)
    #include <X11/Xlib.h>
#elif defined(__TECMA_WINDOWS) 
    #include <windows.h>
#endif

#ifndef __TECMA_CORE_H
    #include "../_Core/tecma_core.h"
#endif

#ifndef __TECMA_INPUT_H
    #include "../_Platform/tecma_input.h"
#endif

namespace TecmaEngine {
    struct TecmaWindow_t {
        explicit TecmaWindow_t() noexcept;
        
        explicit TecmaWindow_t(
            TecmaWindow_t& __other
        ) noexcept;
        
        explicit TecmaWindow_t(
            TecmaWindow_t&& __other
        ) noexcept;

        ~TecmaWindow_t() noexcept;

        void CreateWindow(
            const TecmaWindowCreateInfo_ci& __ci
        );

        void DestroyWindow();

        void CheckForEvents() noexcept;

        TecmaBool __open;
        TecmaVkSurfaceDependencies_t __surfDep;

        private:
            #if defined(__TECMA_XLIB)
                Atom __WM_CLOSE;
            #endif

    };

};

#endif