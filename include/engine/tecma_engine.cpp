#include "tecma_engine.h"
#include <X11/Xlib.h>
#include <unistd.h>

namespace TecmaEngine {
    TecmaApplication::TecmaApplication() noexcept {};

    void InitTecmaApplication(
        TecmaApplication& Application,
        const TecmaApplicationCreateInfo* ApplicationInfo 
    ) {
        if(
            ApplicationInfo->_tecmaEngineApplicationType == TECMA_ENGINE_CLIENT_APPLICATION
        )   {
            TecmaWindowModuleCreateInfo _windowInfo{};
            
            TecmaPlatform::TecmaCreateWindow(
                Application._windowModule,
                &_windowInfo
            );

        }

        TecmaPlatform::TecmaCreateWindow(
            Application._windowModule,
            NULL
        );

    };

};