#include "../platform/tecma_window.h"
#include <X11/X.h>
#include <X11/Xlib.h>

namespace TecmaPlatform {
    const TecmaResult CreateWindow(
        TecmaWindowModule& Window,
        const TecmaWindowModuleCreateInfo* WindowInfo
    ) {
        #if defined(__linux__) // linux goat
            Window._display = XOpenDisplay(
                NULL
            );

            if(
                !Window._display
            ) return TECMA_RESULT_X_OPEN_DISPLAY_FAILED;

            Window._window = XCreateWindow(
                Window._display,
                WindowInfo->_parent,
                WindowInfo->_x,
                WindowInfo->_y,
                WindowInfo->_width,
                WindowInfo->_height,
                WindowInfo->_borderWidth,
                WindowInfo->_depth,
                WindowInfo->_class,
                WindowInfo->_visual,
                WindowInfo->_valueMask,
                WindowInfo->_attributes
            );

            return (TecmaResult)Window._window;
        #elif defined(__WIN32) || defined(__WIN64) // whatever this piece of shit is supposed to be
        #endif

    }

}