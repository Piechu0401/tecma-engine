#ifndef __TECMA_INPUT_H
#define __TECMA_INPUT_H

#include <deque>

#if defined( __TECMA_XLIB )
    #include <X11/Xlib.h>
    #include <X11/Xutil.h>
#endif

#ifndef __TECMA_ENUM_H
    #include "../_Core/tecma_enum.h"
#endif

#ifndef __TECMA_INPUT_CACHE_LIMIT
    #define __TECMA_INPUT_CACHE_LIMIT 16
#endif

namespace TecmaEngine {
    struct TecmaInput_t {
        explicit TecmaInput_t() noexcept;
        
        explicit TecmaInput_t(
            TecmaInput_t& __other
        ) noexcept;

        explicit TecmaInput_t(
            TecmaInput_t&& __other
        ) noexcept;
        
        ~TecmaInput_t() noexcept;

        #if defined( __TECMA_XLIB )
            void CheckOutInput(
                XKeyEvent& __key
            ) noexcept;

            void CheckOutInput(
                XButtonEvent& __button
            ) noexcept;

        #endif

        std::deque<unsigned long> __pressedCache;

    };

};

#endif