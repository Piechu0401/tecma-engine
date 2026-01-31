#include "../include/engine/tecma_engine.h"

int main(
    const int TECMA_ARGUMENTS_COUNT,
    const char* TECMA_ARGUMENTS[]
) {
    TecmaApplicationCreateInfo _applicationInfo{
        .applicationName = TECMA_ENGINE_NAME,
        .applicationVersion = TECMA_ENGINE_VERSION,
        .windowInitWidth = TECMA_ENGINE_INIT_WINDOW_WIDTH,
        .windowInitHeight = TECMA_ENGINE_INIT_WINDOW_HEIGHT,
        .tecmaEngineArguments = TECMA_ARGUMENTS,
        .tecmaEngineArgumentsCount = TECMA_ARGUMENTS_COUNT 
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


    }

    return TECMA_RESULT_SUCCESS;

}