#include "../include/engine/tecma_engine.h"

int main(
    const TecmaI32 TECMA_ARGUMENTS_COUNT,
    TecmaText TECMA_ARGUMENTS[]
) {
    TecmaEngineApplicationCreateInfo _applicationInfo{
        ._tecmaEngineArgumentsCount = TECMA_ARGUMENTS_COUNT,
        ._tecmaEngineArguments = TECMA_ARGUMENTS
    }; 
    
    TecmaEngine::TecmaEngineApplication _application;

    InitTecmaApplication(
        _application,
        &_applicationInfo
    );

    _application.TecmaRunEngine();

    return TECMA_RESULT_SUCCESS;

}

// basic shitty command to compile
// bear -- g++ -O0 build/app.cpp include/*/*.cpp -I*/include/*/*.h -I1.4.328.1/x86_64/include/vulkan -o app -lvulkan -lX11

// here I will place somehow useful commented shit that maybe will get its use in the future

    // TecmaCreateProcess<const TecmaResult, TecmaEngine::TecmaApplication&, const TecmaApplicationCreateInfo *>(
    //     TecmaEngine::InitTecmaApplication,
    //     _application,
    //     &_applicationInfo    
    // );