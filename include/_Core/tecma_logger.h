#ifndef __TECMA_LOGGER_H
#define __TECMA_LOGGER_H

#include <stdio.h>
#include <vector>

#include "tecma_enum.h"

namespace TecmaEngine {
    typedef struct TecmaLogger {
        explicit TecmaLogger() noexcept;
        ~TecmaLogger() noexcept;

        void operator()( 
            const TecmaErrorFlag& __flag 
        ) const;

        void operator()( 
            const TecmaErrorFlag& __flag,
            const std::vector<const char*>& __missing 
        ) const;

        #if defined(__TECMA_INFO)
            void operator()( 
                const TecmaInfoFlag& __flag,
                const std::vector<const char*>& __missing 
            ) const;
        #endif

        void operator()( 
            const TecmaVkResult& __result,
            const TecmaVkFunctionFlag& __funcType 
        ) const;

    } TecmaLogger_t;

};

#endif