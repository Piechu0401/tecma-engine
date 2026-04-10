#include "tecma_logger.h"
#include "tecma_enum.h"

namespace TecmaEngine {
    TecmaLogger_t::TecmaLogger_t() noexcept {}
    TecmaLogger_t::~TecmaLogger_t() noexcept {}

    void TecmaLogger_t::operator()(
        const TecmaVkEnumType& __enType,
        const char* __name
    ) const {
        printf(
            "%s   -> %-16s : %s\n",
            TECMA_MESSAGE_USING,
            GetTecmaVkEnumTypeName(
                __enType
            ),
            __name
        );

    }

    void TecmaLogger_t::operator()(
        const TecmaVkObjectType& __objType,
        const char* __attr
    ) const noexcept {
        printf(
            "%s   -> %-16s : %s\n",
            TECMA_MESSAGE_USING,
            GetTecmaVkObjectTypeName(
                __objType
            ),
            __attr
        );

    }

    void TecmaLogger_t::operator()( 
        const TecmaErrorFlag& __flag 
    ) const {
        printf(
            "%s   -> %-43s",
            TECMA_MESSAGE_ERROR,
            GetTecmaErrorFlagMessage(
                __flag
            )
        );

        std::abort();
        
    }

    #if defined(__TECMA_INFO)
        void TecmaLogger_t::operator()( 
            const TecmaInfoFlag& __flag,
            const std::vector<const char*>& __available 
        ) const {
            printf(
                "%-9s->%-43s",
                TECMA_MESSAGE_INFO,
                GetTecmaInfoFlagMessage(
                    __flag
                )
            );

            for( auto& __a : __available )
                printf("\t%s\n", __a);

        }
    #endif

    void TecmaLogger_t::operator()( 
        const TecmaErrorFlag& __flag,
        const std::vector<const char*>& __missing 
    ) const {
        printf(
            "%-9s->%-43s",
            TECMA_MESSAGE_ERROR,
            GetTecmaErrorFlagMessage(
                __flag
            )
        );

        for( auto& __m : __missing )
            printf("\t\t%s\n", __m);

        std::abort();

    }

    void TecmaLogger_t::operator()( 
        const TecmaVkResult& __result,
        const TecmaVkFunctionFlag& __funcType 
    ) const {
        if( !__result ) {
            printf(
                "%s -> %-43s : { %s }\n",
                TECMA_MESSAGE_VALID, 
                GetTecmaVkFunctionFlagName( __funcType ),
                GetTecmaVkResultName( __result )
            );

        }
        else {
            printf(
                "%s   -> %-43s : { %s }\n",
                TECMA_MESSAGE_ERROR, 
                GetTecmaVkFunctionFlagName( __funcType ),
                GetTecmaVkResultName( __result )
            );

            std::abort();

        }
        
    }

};