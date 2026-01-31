#ifndef __TECMA_ERROR_H
#define __TECMA_ERROR_H

#ifndef __TECMA_TYPES_H
    #include "tecma_types.h"
#endif

#ifndef __TECMA_ENUMS_H
    #include "tecma_enums.h"
#endif

#ifndef __TECMA_OS_H
    #include "tecma_enums.h"
#endif

struct TecmaError {
    explicit TecmaError() noexcept;
    explicit TecmaError(
        TecmaText Message
    ) noexcept;
    explicit TecmaError(
        char Message[]
    ) noexcept;
    explicit TecmaError(
        const TecmaResult& ResultCode
    ) noexcept;

    private:
        TecmaText IdentifyMessage(
            const TecmaResult& ResultCode
        );
        TecmaText Message;

};

#endif