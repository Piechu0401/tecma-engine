#ifndef __TECMA_OS_H
#define __TECMA_OS_H

#if defined(__linux__)
    #ifndef __TECMA_USING_OS
        #define __TECMA_USING_OS 0
    #endif
    #if !defined(__TECMA_USING_XLIB)
        #include <X11/Xlib.h>
    #endif
    #include <unistd.h>
    #include <syscall.h>
    #define SIGABRT 6 // to not include csignal bullshit

#elif defined(__WIN32) || defined(__WIN64)
    #ifndef __TECMA_USING_OS
        #define __TECMA_USING_OS 1
    #endif
    #include <windows.h>
#endif

#ifndef __TECMA_TYPES_H
    #include "tecma_types.h"
#endif

void TecmaPrintTerminal(
    TecmaText ContnetBuffer, ...
) noexcept;
[[noreturn]] void TecmaTerminate() noexcept;
const TecmaU64 TecmaCurrentProcessID() noexcept; 
const TecmaU64 TecmaCurrentThreadID() noexcept; 

#endif