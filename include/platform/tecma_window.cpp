#include "../platform/tecma_window.h"
#include "tecma_os.h"
#include <X11/X.h>
#include <X11/Xlib.h>

namespace TecmaPlatform {
    TecmaWindowModule::TecmaWindowModule() noexcept {}

    void TecmaWindowModule::TecmaCheckOutEvent(
        volatile TecmaBool& __running
    ) noexcept {
        #if __TECMA_USING_OS == __LINUX
            XNextEvent(
                _display,
                _event
            );          // here whole event shit will be handled

            if( !_display || _event->type == DestroyNotify ) { __running = TECMA_FALSE; return; }

        #endif

    }

    const TecmaResult TecmaCreateWindow(
        TecmaWindowModule& _Window,
        const TecmaWindowModuleCreateInfo* WindowInfo
    ) {
        #if defined(__linux__) // linux goat
            _Window._display = XOpenDisplay( NULL );

            if( !_Window._display ) return TECMA_RESULT_X_OPEN_DISPLAY_FAILED;

            _Window._window = XCreateWindow(
                _Window._display,
                WindowInfo->_parent == nullptr ? XDefaultRootWindow(_Window._display) : *WindowInfo->_parent,
                WindowInfo->_x, 
                WindowInfo->_y, 
                WindowInfo->_width,
                WindowInfo->_height,
                WindowInfo->_borderWidth,
                WindowInfo->_windowDepth,
                WindowInfo->_windowClass,
                WindowInfo->_visiual,
                WindowInfo->_valueMask,
                WindowInfo->_windowAttributes
            ); 
            
            if( !_Window._window ) return TECMA_RESULT_X_CREATE_WINDOW_BAD_WINDOW;
            
            XMapWindow(
                _Window._display, 
                _Window._window
            );

            return TECMA_RESULT_SUCCESS;
        #elif defined(__WIN32) || defined(__WIN64) // whatever this piece of shit is supposed to be
        #endif

    }

    void TecmaDestroyWindow(
        TecmaWindowModule& _Window
    ) {
        XUnmapWindow(
            _Window._display,
            _Window._window   
        );

        XCloseDisplay(
            _Window._display
        );

    }

}