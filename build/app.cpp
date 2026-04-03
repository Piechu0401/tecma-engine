#include "../include/_Engine/tecma_engine.h"

int main(
    const int __argc,
    const char* __argv[]
) {
    TecmaEngine::TecmaApplication TecmaEngineApp;

    TecmaEngineApp.InitEngineApplication();

    return 0;

}

// g++ -o0 build/app.cpp include/_*/*.cpp -Iinclude/*.h -o build/app -lvulkan