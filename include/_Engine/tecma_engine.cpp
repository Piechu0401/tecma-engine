#include "tecma_engine.h"

namespace TecmaEngine {
    TecmaApplication::TecmaApplication() noexcept {}
    TecmaApplication::~TecmaApplication() noexcept {}

    void TecmaApplication::InitEngineApplication() {
        __renderer.InitRenderer();

    }

};