#include "tecma_engine.h"
#include <X11/Xlib.h>
#include <cstddef>
#include <unistd.h>

namespace TecmaEngine {
    TecmaEngineApplication::TecmaEngineApplication() noexcept : 
        _actionResult(TECMA_RESULT_SUCCESS),
        _engineRunning(TECMA_TRUE),
        _engineStatus(TECMA_STATUS_IDLE)
    {
        _coreModule.TecmaInitCore();
            
        // TecmaCreateProcess(
        //     TecmaCore::TecmaControlLoop,
        //     &_engineRunning,
        //     &_actionResult,
        //     &_engineStatus
        // );

    };

    TecmaEngineApplication::~TecmaEngineApplication() noexcept { _engineRunning = TECMA_FALSE; }

    void TecmaEngineApplication::TecmaRunEngine() {
        while( _engineRunning ) {
            _windowModule.TecmaCheckOutEvent( _engineRunning );

        }

    }

    void InitTecmaApplication(
        TecmaEngineApplication& _application,
        const TecmaEngineApplicationCreateInfo* _applicationInfo 
    ) { 
        TecmaWindowModuleCreateInfo _windowInfo{};

        _windowInfo._width = 3 * (_application._coreModule._screenWidth >> 2);
        _windowInfo._height = 3 * (_application._coreModule._screenHeight >> 2);
        _windowInfo._x = (_application._coreModule._screenWidth >> 1) - (_windowInfo._width >> 1);
        _windowInfo._y = (_application._coreModule._screenHeight >> 1) - (_windowInfo._height >> 1);
        _windowInfo._windowDepth = _application._coreModule._depth;
        _windowInfo._visiual = _application._coreModule._coreVisualInfo.visual;
        _windowInfo._windowAttributes = &_application._coreModule._coreAttributes;

        _application._actionResult = InitTecmaEngineWindow(
            _application._windowModule,
            _windowInfo 
        );

    };

    const TecmaResult InitTecmaEngineWindow(
        TecmaPlatform::TecmaWindowModule& _windowModule,
        TecmaWindowModuleCreateInfo& _windowInfo
    ) {
        _windowInfo._parent = nullptr;
        _windowInfo._windowClass = TecmaCore::TecmaCoreWindowGetWindowClass();
        _windowInfo._valueMask = TecmaCore::TecmaCoreWindowGetValuemask();

        return TecmaPlatform::TecmaCreateWindow(
            _windowModule,
            &_windowInfo
        );

    }

};