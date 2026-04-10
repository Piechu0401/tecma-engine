#ifndef __TECMA_CORE_H
#define __TECMA_CORE_H

#include <algorithm>
#include <array>
#include <vector>
#include <string.h>

#ifndef __TECMA_LOGGER_H
    #include "tecma_logger.h"
#endif

#if defined(__linux__)
    #define __TECMA_LINUX __linux__
    #include <unistd.h>
#elif defined(__WIN32) || defined(__WIN64)
    #define __TECMA_WINDOWS __WIN32 
    #include <windows.h>
#endif

#ifndef __TECMA_DEPENDENCIES_H
    #include "tecma_dependencies.h"
#endif

#ifndef __TECMA_ENGINE_NAME
    #define __TECMA_ENGINE_NAME "Tecma Engine"
#endif

#ifndef __TECMA_ENGINE_VERSION
    #define __TECMA_ENGINE_VERSION 0
#endif

namespace TecmaEngine {
    const TecmaLogger_t TecmaLogger;
    
};

#endif