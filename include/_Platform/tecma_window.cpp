#include "tecma_window.h"

namespace TecmaEngine {
    TecmaWindow_t::TecmaWindow_t() noexcept :
        __open(__TECMA_TRUE)
    {
        #if defined(__TECMA_XLIB)
            __surfDep.__dsp = nullptr;
            __surfDep.__wnd = 0;
        #elif defined(__TECMA_WAYLAND)
            __surfDep.__dsp = nullptr;
            __surfDep.__surf = nullptr;
        #elif defined(__TECMA_WINDOWS)
            __surfDep.__hins = nullptr;
            __surfDep.__hwnd = nullptr;
        #endif

    }
    
    TecmaWindow_t::TecmaWindow_t(
        const TecmaWindow_t& __other
    ) noexcept {}
    
    TecmaWindow_t::TecmaWindow_t(
        const TecmaWindow_t&& __other
    ) noexcept {}

    TecmaWindow_t::~TecmaWindow_t() noexcept {}

    void TecmaWindow_t::CreateWindow(
        const TecmaWindowCreateInfo_ci& __ci
    ) {
        #if defined(__TECMA_XLIB)
            __surfDep.__dsp = XOpenDisplay( NULL );
            if( !__surfDep.__dsp ) TecmaLogger(TECMA_ERROR_XLIB_DISPLAY_FAILED);
            
            __surfDep.__wnd = XCreateSimpleWindow(
                __surfDep.__dsp,
                DefaultRootWindow( __surfDep.__dsp ),
                __ci.__x,
                __ci.__y,
                __ci.__w,
                __ci.__h,
                __ci.__bordSize, 
                __ci.__bordClr,
                __ci.__backgrdClr
            );

            if( !__surfDep.__wnd ) TecmaLogger(TECMA_ERROR_XLIB_WINDOW_FAILED);

            XSelectInput(
                __surfDep.__dsp, 
                __surfDep.__wnd,
                KeyPressMask |
                ButtonPressMask |
                ExposureMask
            );

            XMapWindow( __surfDep.__dsp, __surfDep.__wnd );

        #elif defined(__TECMA_WAYLAND)
        #elif defined(__TECMA_WINDOWS)
        #endif

    }

    void TecmaWindow_t::DestroyWindow() {
        #if defined(__TECMA_XLIB)
            XDestroyWindow( __surfDep.__dsp, __surfDep.__wnd );
        #endif

    }

}