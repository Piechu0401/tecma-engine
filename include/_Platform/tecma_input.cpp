#include "tecma_input.h"
#include <stdio.h>

namespace TecmaEngine {
        TecmaInput_t::TecmaInput_t() noexcept {}
        
        TecmaInput_t::TecmaInput_t(
            TecmaInput_t& __other
        ) noexcept {}

        TecmaInput_t::TecmaInput_t(
            TecmaInput_t&& __other
        ) noexcept {}
        
        TecmaInput_t::~TecmaInput_t() noexcept {}

        #if defined( __TECMA_XLIB )
            void TecmaInput_t::CheckOutInput(
                XKeyEvent& __key
            ) noexcept {
                char __buff[32];
                unsigned long __ks;

                XLookupString(
                    &__key, 
                    __buff, 
                    sizeof(__buff), 
                    &__ks, 
                    NULL
                );

                if( __pressedCache.size() + 1 > __TECMA_INPUT_CACHE_LIMIT )
                    __pressedCache.pop_front();

                __pressedCache.emplace_back( __ks );
                
                printf(
                    "KEY: %lu %s\n", 
                    __ks,
                    GetTecmaInputFlagName( (TecmaInputFlag)__ks )
                );

            }

            void TecmaInput_t::CheckOutInput(
                XButtonEvent& __button
            ) noexcept {


            }

        #endif

}