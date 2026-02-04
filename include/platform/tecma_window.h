#ifndef __TECMA_WINDOW_H
#define __TECMA_WINDOW_H

#if defined(__linux__)
    #include <X11/Xlib.h>
#elif defined(__WIN32) || defined(__WIN64)
    #include <windows.h>2
#endif

#include "../core/tecma_core.h"

namespace TecmaPlatform {
    struct TecmaWindowModule {
        explicit TecmaWindowModule() noexcept;

        friend const TecmaResult TecmaCreateWindow(
            TecmaWindowModule& Window,
            const TecmaWindowModuleCreateInfo* WindowInfo
        );    

        private:
            #if defined(__linux__)
                Window _window;
                Display* _display;
                XEvent* _event;
            #elif defined(__WIN32) || defined(__WIN64)
                HWND _hWindow;
                HINSTANCE _hInstance; 
            #endif

    };

    const TecmaResult TecmaCreateWindow(
        TecmaWindowModule& Window,
        const TecmaWindowModuleCreateInfo* WindowInfo
    );

};

#endif