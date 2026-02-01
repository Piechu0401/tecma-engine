#include "tecma_engine.h"
#include <unistd.h>

namespace TecmaEngine {
    TecmaApplication::TecmaApplication() noexcept {};

    const TecmaResult InitTecmaApplication(
        TecmaApplication& Application,
        const TecmaApplicationCreateInfo* ApplicationInfo 
    ) {
        TecmaWindowModuleCreateInfo _windowInfo{};

        _windowInfo._width = ApplicationInfo->_windowInitWidth;
        _windowInfo._height = ApplicationInfo->_windowInitHeight;
        _windowInfo._windowTitle = ApplicationInfo->_applicationName;
        _windowInfo._fullscreen = TECMA_FALSE;

        return TECMA_RESULT_SUCCESS;

    };

};