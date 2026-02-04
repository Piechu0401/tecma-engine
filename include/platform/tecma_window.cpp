#include "../platform/tecma_window.h"
#include <X11/X.h>
#include <X11/Xlib.h>

namespace TecmaPlatform {
    TecmaWindowModule::TecmaWindowModule() noexcept {}

    const TecmaResult TecmaCreateWindow(
        TecmaWindowModule& _Window,
        const TecmaWindowModuleCreateInfo* WindowInfo
    ) {
        #if defined(__linux__) // linux goat
            _Window._display = XOpenDisplay(
                NULL
            );

            if(
                !_Window._display
            ) return TECMA_RESULT_X_OPEN_DISPLAY_FAILED;

            if(
                WindowInfo != NULL
            ) {


            }
            else {
                Window _pw = TecmaCore::TecmaCoreWindowGetParentWindow(_Window._display);
                TecmaI32 _x = TecmaCore::TecmaCoreWindowGetHalfWidth(_Window._display);
                TecmaI32 _y = TecmaCore::TecmaCoreWindowGetHalfHeight(_Window._display);
                TecmaI32 _w = TecmaCore::TecmaCoreWindowGetHalfWidth(_Window._display);
                TecmaI32 _h = TecmaCore::TecmaCoreWindowGetHalfHeight(_Window._display);
                TecmaI32 _wd = TecmaCore::TecmaCoreWindowGetDepth(_Window._display);
                TecmaU32 _wc = TecmaCore::TecmaCoreWindowGetWindowClass();
                Visual* _xv = TecmaCore::TecmaCoreWindowGetXlibVisual(_Window._display);
                TecmaU64 _xvm = TecmaCore::TecmaCoreWindowGetValuemask();
                XSetWindowAttributes _swa = TecmaCore::TecmaCoreWindowGetXlibWindowAttributes(_Window._display);

                _Window._window = XCreateWindow(
                    _Window._display,
                    _pw,
                    _x, 
                    _y, 
                    _w,
                    _h,
                    TECMA_ENGINE_INIT_BORDER_WIDTH,
                    _wd,
                    _wc,
                    _xv,
                    _xvm,
                    &_swa
                ); 

                if(
                    !_Window._window
                ) return (TecmaResult)_Window._window;

                XMapWindow(
                    _Window._display, 
                    _Window._window
                );

                while(
                    true
                ) {
                    XNextEvent(
                        _Window._display, 
                        _Window._event);

                }

            }

            return (TecmaResult)_Window._window;
        #elif defined(__WIN32) || defined(__WIN64) // whatever this piece of shit is supposed to be
        #endif

    }

}