#ifndef __TECMA_WINDOW_H
#define __TECMA_WINDOW_H

#if defined(__linux__)
    #include <X11/Xlib.h>
#elif defined(__WIN32) || defined(__WIN64)
    #include <windows.h>
#endif

#include "../core/tecma_core.h"

namespace TecmaPlatform {
    struct TecmaWindowModule {
        explicit TecmaWindowModule() noexcept;

        friend const TecmaResult TecmaCreateWindow(
            TecmaWindowModule& _Window,
            const TecmaWindowModuleCreateInfo* WindowInfo
        );    

        friend void TecmaDestroyWindow(
            TecmaWindowModule& _Window
        );

        void TecmaCheckOutEvent(
            volatile TecmaBool& __running
        ) noexcept;

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
        TecmaWindowModule& _Window,
        const TecmaWindowModuleCreateInfo* WindowInfo
    );

    void TecmaDestroyWindow(
        TecmaWindowModule& _Window
    );

};

#endif