#include "tecma_error.h"

TecmaError::TecmaError(
    const TecmaResult& ResultCode
) noexcept {
    if(
        ResultCode == TECMA_RESULT_X_OPEN_DISPLAY_FAILED
    )   {
        //TecmaString _message(
        //    {
        //        TECMA_ERROR_FROM_X,
        //        TECMA_ERROR_PART_EXECUTE_FAILED,
        //        TECMA_ERROR_X_OPEN_DISPLAY_FAILED
        //    }
        //);
        
        // TecmaPrintTerminal(
        //     "%s",
        //     _message
        // );

    }

    TecmaTerminate();

}