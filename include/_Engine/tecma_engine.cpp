#include "tecma_engine.h"

namespace TecmaEngine {
    TecmaApplication_t::TecmaApplication_t() noexcept {}
    
    TecmaApplication_t::TecmaApplication_t(
        const TecmaApplication_t& __other
    ) noexcept {}
    
    TecmaApplication_t::TecmaApplication_t(
        const TecmaApplication_t&& __other
    ) noexcept {}
    
    TecmaApplication_t::~TecmaApplication_t() noexcept {}

    void TecmaApplication_t::InitEngineApplication() {
        __renderer.InitRenderer();

    }

};