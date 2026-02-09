#include "tecma_core.h"
#include "tecma_constants.h"
#include "tecma_enums.h"
#include <X11/X.h>
#include <X11/Xlib.h>

namespace TecmaCore {
    TecmaCoreModule::TecmaCoreModule() noexcept {}
    const TecmaResult TecmaCoreModule::TecmaInitCore() {
        Display* _temp = XOpenDisplay( NULL );

        if( !_temp ) return TECMA_RESULT_X_OPEN_DISPLAY_FAILED;
        
        _screenWidth = static_cast<TecmaU64>(XDisplayWidth(_temp, DefaultScreen(_temp)));
        _screenHeight = static_cast<TecmaU64>(XDisplayHeight(_temp, DefaultScreen(_temp)));

        _depth = XDefaultDepth(_temp, DefaultScreen(_temp));

        if( 
            !XMatchVisualInfo(
                _temp, 
                DefaultScreen(_temp), 
                _depth, 
                TrueColor, 
                &_coreVisualInfo
            ) 
        ) return TECMA_RESULT_X_FAILED_TO_MATCH_VISUAL_INFO;

        _coreAttributes.event_mask = 
            KeyPressMask | 
            KeyReleaseMask | 
            ButtonPressMask | 
            ButtonReleaseMask |
            Button1MotionMask; // for dragging shit around, not useful now  
        _coreAttributes.border_pixel = TecmaSetColors(10,10,10);
        _coreAttributes.background_pixel = TecmaSetColors(10,10,10);

        XCloseDisplay(_temp);

        return TECMA_RESULT_SUCCESS;
        
    }

    const TecmaU64 TecmaCoreModule::TecmaSetColors(
        const TecmaU64& __r,
        const TecmaU64& __g,
        const TecmaU64& __b
    ) noexcept { 
        return 
            (((__r << 16) & _coreVisualInfo.red_mask) |
            ((__g << 8) & _coreVisualInfo.green_mask) |
            (__b & _coreVisualInfo.blue_mask));

    };
    
    void* TecmaControlLoop(
        volatile TecmaBool* _engineRunning,
        TecmaResult* _actionResult,
        TecmaStatus* _engineStatus
    ) {
        while(
            *_engineRunning
        ) {
            if( *_actionResult ) throw TecmaError( *_actionResult );
            else if( *_engineStatus != TECMA_STATUS_IDLE ) { TecmaPrintTerminal(
                TecmaIdentifyTecmaStatus(*_engineStatus)
            ); *_engineStatus = TECMA_STATUS_IDLE; }

        }

        return nullptr;

    }

}