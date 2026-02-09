#ifndef __TECMA_ERROR_H
#define __TECMA_ERROR_H

#ifndef __TECMA_TYPES_H
    #include "tecma_types.h"
#endif

#ifndef __TECMA_ENUMS_H
    #include "tecma_enums.h"
#endif

#ifndef __TECMA_CONSTANTS_H
    #include "tecma_constants.h"
#endif

#ifndef __TECMA_OS_H
    #include "../platform/tecma_os.h"
#endif

// to be honest whole project could end by just throwing this shit in main cpp and ending this misery for good

struct TecmaError {
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