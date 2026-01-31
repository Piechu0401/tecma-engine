#ifndef __TECMA_WINDOW_H
#define __TECMA_WINDOW_H

#if defined(__linux__)
    #include <X11/Xlib.h>
#elif defined(__WIN32) || defined(__WIN64)
    #include <windows.h>
#endif

#include "../core/tecma_core.h"

namespace TecmaPlatform {
    struct TecmaWindowModuleCreateInfo : TecmaCreateInfo {
        signed int _x;
        signed int _y;
        unsigned int _width;
        unsigned int _height;
        const char* _windowTitle;
        unsigned int _fullscreen : 1;    

        #if defined(__linux__)
            Window _parent;
            unsigned int _borderWidth;
            int _depth;
            unsigned int _class;
            Visual* _visual;
            unsigned long _valueMask;
            XSetWindowAttributes* _attributes;
        #endif

        const TecmaResult ValidInfo() override {
            return TECMA_RESULT_SUCCESS;

        };

    };

    struct TecmaWindowModule {
        explicit TecmaWindowModule() noexcept;

        friend const TecmaResult CreateWindow(
            TecmaWindowModule& Window,
            const TecmaWindowModuleCreateInfo* WindowInfo
        );    

        private:
            #if defined(__linux__)
                Window _window;
                Display* _display;
            #elif defined(__WIN32) || defined(__WIN64)
                HWND _hWindow;
                HINSTANCE _hInstance; 
            #endif

    };

    const TecmaResult CreateWindow(
        TecmaWindowModule& Window,
        const TecmaWindowModuleCreateInfo* WindowInfo
    );

};

#endif