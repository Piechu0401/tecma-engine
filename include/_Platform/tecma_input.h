#ifndef __TECMA_INPUT_H 
#define __TECMA_INPUT_H

#include <unordered_map>

namespace TecmaEngine {
    struct TecmaInput_t {
        explicit TecmaInput_t() noexcept;
        
        explicit TecmaInput_t(
            const TecmaInput_t& __other
        ) noexcept;

        explicit TecmaInput_t(
            const TecmaInput_t&& __other
        ) noexcept;
        
        ~TecmaInput_t() noexcept;

        const void operator()(
            const int& __key
        ) const noexcept;

        // unordered map of pointers to function which will handle
        // response to given input value
        // pretty straight forward

        std::unordered_map<int, void*> __inputResponse;

    };

};

#endif