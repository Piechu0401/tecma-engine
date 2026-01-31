#include "../include/engine/tecma_engine.h"

int main(
    const TecmaI32 TECMA_ARGUMENTS_COUNT,
    const char* TECMA_ARGUMENTS[]
) {
    TecmaApplicationCreateInfo _applicationInfo{
        ._windowInitWidth = TECMA_ENGINE_INIT_WINDOW_WIDTH,
        ._windowInitHeight = TECMA_ENGINE_INIT_WINDOW_HEIGHT,
        ._applicationVersion = TECMA_ENGINE_VERSION,
        ._applicationName = TECMA_ENGINE_NAME,
        ._tecmaEngineArgumentsCount = TECMA_ARGUMENTS_COUNT,
        ._tecmaEngineArguments = TECMA_ARGUMENTS 
    };
    
    TecmaEngine::TecmaApplication _application;

    try{
        InitTecmaApplication(
            _application,
            &_applicationInfo
        );
    } catch(
        TecmaResult Result
    ) {
        throw TecmaError(
            Result
        );     

    }

    return TECMA_RESULT_SUCCESS;

}