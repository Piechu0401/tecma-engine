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
//
// welcome to the core, and source of all shitty architecture choices. Watch your step.

#include <stdio.h>

#define _TECMA_ALIGN(_size, _align) ((_size - _align - 1) & ~(_align - 1))

namespace TecmaCore {
    struct TecmaCoreModule {
        explicit TecmaCoreModule() noexcept;

        const TecmaResult TecmaInitCore();

        TecmaU64 _screenWidth;
        TecmaU64 _screenHeight;
        TecmaI32 _depth;
    
        #if __TECMA_USING_OS == __LINUX
            XVisualInfo _coreVisualInfo;
            XSetWindowAttributes _coreAttributes;
        #endif

        private:
            const TecmaU64 TecmaSetColors(
                const TecmaU64& __r,
                const TecmaU64& __g,
                const TecmaU64& __b
            ) noexcept;

    };

    #if __TECMA_USING_OS == __LINUX
        inline TecmaU32 TecmaCoreWindowGetWindowClass() noexcept { return InputOutput; }
        inline TecmaU64 TecmaCoreWindowGetValuemask() noexcept { return CWBorderPixel | CWBackPixel | CWEventMask; }
        Visual* TecmaCoreWindowGetXlibVisual() noexcept;
        XSetWindowAttributes* TecmaCoreWindowGetXlibWindowAttributes() noexcept;
    #endif

    void* TecmaControlLoop( // this ptr func will control if everything in this dumpster clicks in (hopefully)
        volatile TecmaBool* _engineRunning,
        TecmaResult* _actionResult,
        TecmaStatus* _engineStatus
    );

    inline TecmaText TecmaIdentifyTecmaStatus(
        const TecmaStatus& _status
    ) {
        if( _status == TECMA_STATUS_INIT_ENGINE) return TECMA_STATUS_INIT_ENGINE_MESSAGE;
        else if( _status == TECMA_STATUS_CREATING_NEW_THREAD) return TECMA_STATUS_CREATING_NEW_THREAD_MESSAGE;
        else if( _status == TECMA_STATUS_INIT_WINDOW) return TECMA_STATUS_INIT_WINDOW_MESSAGE;
        else if( _status == TECMA_STATUS_INIT_VULKAN) return TECMA_STATUS_INIT_VULKAN_MESSAGE;
        else throw TecmaError(TECMA_RESULT_TE_UNKNOWN_STATUS_TYPE);

    }

}

#endif