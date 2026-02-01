#ifndef __TECMA_OS_H
#define __TECMA_OS_H

#ifndef __LINUX
    #define __LINUX 0
#endif

#ifndef __WINDOWS
    #define __WINDOWS 1
#endif

#if defined(__linux__)
    #ifndef __TECMA_USING_OS
        #define __TECMA_USING_OS __LINUX
    #endif
    #if !defined(__TECMA_USING_XLIB)
        #include <X11/Xlib.h>
    #endif
    #include <unistd.h>
    #include <syscall.h>
    #define SIGABRT 6 // to not include csignal bullshit

#elif defined(__WIN32) || defined(__WIN64)
    #ifndef __TECMA_USING_OS
        #define __TECMA_USING_OS __WINDOWS
    #endif
    #include <windows.h>
#endif

#ifndef __TECMA_TYPES_H
    #include "../core/tecma_types.h"
#endif

void TecmaPrintTerminal(
    TecmaText ContnetBuffer, ...
) noexcept;
[[noreturn]] void TecmaTerminate() noexcept;
const TecmaU64 TecmaCurrentProcessID() noexcept; 
const TecmaU64 TecmaCurrentThreadID() noexcept; 

template<typename _functionType, typename... _type>
inline void TecmaCreateProcess(
    _functionType (*ProcessFunction)(_type...),
    _type&&... ProcessFunctionArgs
) noexcept {
    #if __TECMA_USING_OS == __LINUX
        TecmaU64 pID = syscall(
            __NR_fork
        );

        if(
            pID == 0
        ) {
            // syscall(
            //     __NR_write,
            //     STDOUT_FILENO,
            //     "deez nuts fucker\n",
            //     18
            // );

            ProcessFunction(
                ProcessFunctionArgs... 
            );
            syscall(
                __NR_exit,
                0
            );

        }

    #endif

}

#endif