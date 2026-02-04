#include "tecma_core.h"
#include <X11/X.h>
#include <X11/Xlib.h>

namespace TecmaCore {
    #if __TECMA_USING_OS == __LINUX
        Visual* TecmaCoreWindowGetXlibVisual(
            const Display* _display
        ) noexcept { 
            Visual* _res = DefaultVisual(_display, DefaultScreen(_display)); 
            return _res;
        
        }
        
        XSetWindowAttributes TecmaCoreWindowGetXlibWindowAttributes(
            const Display* _display
        ) noexcept { 
            XSetWindowAttributes _res; 
        
            _res.background_pixel = WhitePixel(_display, DefaultScreen(_display));
            _res.border_pixel = BlackPixel(_display, DefaultScreen(_display));
            _res.event_mask = ButtonPress;

            return _res; 
        
        }
    
    #endif    

}