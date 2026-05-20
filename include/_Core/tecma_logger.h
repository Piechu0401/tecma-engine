#ifndef __TECMA_LOGGER_H
#define __TECMA_LOGGER_H

#include <stdio.h>
#include <vector>
#include <cstdlib>

#include "tecma_enum.h"

#define TECMA_MESSAGE_VALID_STR_CLR "\033[38;2;0;120;0m"
#define TECMA_MESSAGE_ERROR_STR_CLR "\033[38;2;120;0;0m"
#define TECMA_MESSAGE_USING_STR_CLR "\033[38;2;120;60;0m"
#define TECMA_MESSAGE_INFO_STR_CLR "\033[38;2;0;0;120m"
#define TECMA_MESSAGE_RESET_STR_CLR "\033[0m"

#define TECMA_MESSAGE_VALID_STR "Message" 
#define TECMA_MESSAGE_INFO_STR  "Info" 
#define TECMA_MESSAGE_ERROR_STR "Error" 
#define TECMA_MESSAGE_USING_STR "Using"

#define TECMA_MESSAGE_VALID TECMA_MESSAGE_VALID_STR_CLR TECMA_MESSAGE_VALID_STR TECMA_MESSAGE_RESET_STR_CLR 
#define TECMA_MESSAGE_INFO  TECMA_MESSAGE_INFO_STR_CLR TECMA_MESSAGE_INFO_STR TECMA_MESSAGE_RESET_STR_CLR 
#define TECMA_MESSAGE_ERROR TECMA_MESSAGE_ERROR_STR_CLR TECMA_MESSAGE_ERROR_STR TECMA_MESSAGE_RESET_STR_CLR 
#define TECMA_MESSAGE_USING TECMA_MESSAGE_USING_STR_CLR TECMA_MESSAGE_USING_STR TECMA_MESSAGE_RESET_STR_CLR

namespace TecmaEngine {
    struct TecmaLogger_t {
        explicit TecmaLogger_t() noexcept;
        ~TecmaLogger_t() noexcept;

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

        void operator()(
            const TecmaVkObjectType& __objType,
            const char* __attr
        ) const noexcept;

        void operator()(
            const TecmaVkEnumType& __enType,
            const char* __attr
        ) const;

        void operator()(
            const char* __customMsg
        ) const;

    };

    // logger object, yeah yeah cry about how its used
    static TecmaLogger_t TecmaLogger;

};

#endif