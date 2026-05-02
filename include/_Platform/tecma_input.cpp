#include "tecma_input.h"

namespace TecmaEngine {
        TecmaInput_t::TecmaInput_t() noexcept {}
        
        TecmaInput_t::TecmaInput_t(
            const TecmaInput_t& __other
        ) noexcept {}

        TecmaInput_t::TecmaInput_t(
            const TecmaInput_t&& __other
        ) noexcept {}
        
        TecmaInput_t::~TecmaInput_t() noexcept {}

        const void TecmaInput_t::operator()(
            const int& __key
        ) const noexcept {} 

}