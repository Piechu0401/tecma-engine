#ifndef __TECMA_CORE_H
#define __TECMA_CORE_H

#ifndef __TECMA_CONSTANTS_H
    #include "tecma_constants.h"
#endif

#ifndef __TECMA_CREATE_INFOS_H
    #include "tecma_create_infos.h"
#endif

#ifndef __TECMA_ENUMS_H
    #include "tecma_enums.h"
#endif

#ifndef __TECMA_ERROR_H
    #include "tecma_error.h"
#endif

#ifndef __TECMA_OS_H
    #include "../platform/tecma_os.h"
#endif

#ifndef __TECMA_TYPES_H
    #include "tecma_types.h"
#endif

#define _TECMA_ALIGN(_size, _align) ((_size - _align - 1) & ~(_align - 1))

namespace TecmaCore {
    

}

#endif