#include "tecma_error.h"

TecmaError::TecmaError(
    const TecmaResult& ResultCode
) noexcept {
    TecmaPrintTerminal( TECMA_TERMINATE_MESSAGE );

    TecmaTerminate();

}