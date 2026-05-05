#ifndef __TECMA_CORE_H
#define __TECMA_CORE_H

#include <algorithm>
#include <array>
#include <vector>
#include <string.h>

#ifndef __TECMA_LOGGER_H
    #include "tecma_logger.h"
#endif

#if defined(__linux__)
    #define __TECMA_LINUX __linux__
    #include <unistd.h>
#elif defined(__WIN32) || defined(__WIN64)
    #define __TECMA_WINDOWS (__WIN32 ? __WIN32 : __WIN64) 
    #include <windows.h>
#endif

#if defined(__TECMA_WAYLAND)
    #include <wayland-client.h>
#elif defined(__TECMA_XLIB)
    #define __TECMA_ATOM_WM_DELETE_WINDOW "WM_DELETE_WINDOW"
    #include <X11/Xlib.h>
#endif

#ifndef __TECMA_DEPENDENCIES_H
    #include "tecma_dependencies.h"
#endif

#ifndef __TECMA_CREATE_INFO_H
    #include "tecma_create_info.h"
#endif

#ifndef __TECMA_ENGINE_NAME
    #define __TECMA_ENGINE_NAME "Tecma Engine"
#endif

#ifndef __TECMA_ENGINE_VERSION
    #define __TECMA_ENGINE_VERSION 0
#endif

#ifndef __TECMA_INPUT_H
    #include "../_Platform/tecma_input.h"
#endif

#define __TECMA_INIT_WND_W 1000
#define __TECMA_INIT_WND_H 1000
#define __TECMA_INIT_WND_X 0
#define __TECMA_INIT_WND_Y 0

namespace TecmaEngine {
    // I didnt find any other elegant way to do this, so fuck this shit
    struct TecmaVkSurfaceDependencies_t {
        #if defined(__TECMA_XLIB)
            Display* __dsp = nullptr;
            Window __wnd = 0;
        #elif defined(__TECMA_WAYLAND)
            struct wl_display* __dsp = nullptr;
            struct wl_surface* __surf = nullptr;
        #elif defined(__TECMA_WINDOWS)
            HINSTANCE __hins = nullptr;
            HWND __hwnd = nullptr;
        #endif

    };

    // logger object, yeah yeah cry about how its used
    static TecmaLogger_t TecmaLogger;

    // input object, anything you will press will be harshly
    // judged by this individual
    static TecmaInput_t TecmaInput;
    
};

#endif