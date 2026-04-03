#include "tecma_logger.h"
#include <cstdlib>

#define TECMA_MESSAGE_VALID_STR "Message -> "
#define TECMA_MESSAGE_INFO_STR  "Info    -> "
#define TECMA_MESSAGE_ERROR_STR "\tError -> "

namespace TecmaEngine {
    TecmaLogger::TecmaLogger() noexcept {}
    TecmaLogger::~TecmaLogger() noexcept {}

    void TecmaLogger::operator()( 
        const TecmaErrorFlag& __flag 
    ) const {
        printf(
            "%s%s",
            TECMA_MESSAGE_ERROR_STR,
            GetTecmaErrorFlagMessage(
                __flag
            )
        );

        std::abort();
        
    }

    #if defined(__TECMA_INFO)
        void TecmaLogger::operator()( 
            const TecmaInfoFlag& __flag,
            const std::vector<const char*>& __available 
        ) const {
            printf(
                "%s%s",
                TECMA_MESSAGE_INFO_STR,
                GetTecmaInfoFlagMessage(
                    __flag
                )
            );

            for( auto& __a : __available )
                printf("\t%s\n", __a);

        }
    #endif

    void TecmaLogger::operator()( 
        const TecmaErrorFlag& __flag,
        const std::vector<const char*>& __missing 
    ) const {
        printf(
            "%s%s",
            TECMA_MESSAGE_ERROR_STR,
            GetTecmaErrorFlagMessage(
                __flag
            )
        );

        for( auto& __m : __missing )
            printf("\t\t%s\n", __m);

        std::abort();

    }

    void TecmaLogger::operator()( 
        const TecmaVkResult& __result,
        const TecmaVkFunctionFlag& __funcType 
    ) const {        
        printf(
            "%s%-40s : { %s }\n",
            TECMA_MESSAGE_VALID_STR, 
            GetTecmaVkFunctionFlagName( __funcType ),
            GetTecmaVkResultName( __result )
        );
        
    }

};