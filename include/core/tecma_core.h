#ifndef __TECMA_CORE_H
#define __TECMA_CORE_H

#include <X11/Xlib.h>
#ifndef __TECMA_CONSTANTS_H
    #include "tecma_constants.h"
#endif

#ifndef __TECMA_CREATE_INFOS_H
    #include "tecma_create_infos.h"
#endif

#ifndef __TECMA_ENUMS_H
    #include "tecma_enums.h"
#endif

#ifndef __TECMA_ERROR_H
    #include "tecma_error.h"
#endif

#ifndef __TECMA_OS_H
    #include "../platform/tecma_os.h"
#endif

#ifndef __TECMA_TYPES_H
    #include "tecma_types.h"
#endif

// ___________                            ___________              .__               
// \__    ___/___   ____   _____ _____    \_   _____/ ____    ____ |__| ____   ____  
//   |    |_/ __ \_/ ___\ /     \\__  \    |    __)_ /    \  / ___\|  |/    \_/ __ \ 
//   |    |\  ___/\  \___|  Y Y  \/ __ \_  |        \   |  \/ /_/  >  |   |  \  ___/ 
//   |____| \___  >\___  >__|_|  (____  / /_______  /___|  /\___  /|__|___|  /\___  >
//              \/     \/      \/     \/          \/     \//_____/         \/     \/ 

#define _TECMA_ALIGN(_size, _align) ((_size - _align - 1) & ~(_align - 1))

namespace TecmaCore {
    #if __TECMA_USING_OS == __LINUX
        inline TecmaU32 TecmaCoreWindowGetHalfWidth(const Display* _display) noexcept { return (DisplayWidth(_display, DefaultScreen(_display)) >> 1); }
        inline TecmaU32 TecmaCoreWindowGetHalfHeight(const Display* _display) noexcept { return (DisplayHeight(_display, DefaultScreen(_display)) >> 1); }
        inline TecmaU32 TecmaCoreWindowGetWindowClass() noexcept { return InputOutput; }
        inline TecmaU64 TecmaCoreWindowGetValuemask() noexcept { return CWBorderPixel | CWBackPixel | CWEventMask; }
        inline Window TecmaCoreWindowGetParentWindow(const Display* _display) noexcept { return DefaultRootWindow(_display); }
        inline TecmaI32 TecmaCoreWindowGetDepth(const Display* _display) { return DefaultDepth(_display, DefaultScreen(_display)); }
        Visual* TecmaCoreWindowGetXlibVisual(const Display* _display) noexcept;
        XSetWindowAttributes TecmaCoreWindowGetXlibWindowAttributes(const Display* _display) noexcept;
    #endif

}

#endif