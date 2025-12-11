#ifndef TECMA_OS_HPP
#define TECMA_OS_HPP

typedef unsigned long TecmaSize;
typedef const char* TecmaText;
typedef void* TecmaPtr;
typedef void TecmaFunc;

#if defined(__linux__)
    #include <unistd.h>
    #include <sys/syscall.h>
    #include <sys/mman.h>

    #include "../tecma_int.hpp"

    #define TECMA_OS_VAR __linux__

    #define TECMA_SYS_CALL_READ_FLAG SYS_read
    #define TECMA_SYS_CALL_WRITE_FLAG SYS_write
    #define TECMA_SYS_CALL_VIRTUAL_ALLOC_FLAG SYS_mmap
    #define TECMA_SYS_CALL_HEAP_ALLOC_FLAG SYS_brk
    #define TECMA_SYS_CALL_THREAD SYS_clone

#elif defined(__WIN32) || defined (__WIN64)
    #define TECMA_OS (defined(__WIN32)) ? __WIN32 : __WIN64 

    #define TECMA_SYS_CALL(SystemCallFlag, SystemCallArgs...) 
    // gonna expand in the future, fuck windows

#endif

namespace TECMA_OS {
    TecmaPtr TecmaHeapAllocCall(
        TecmaPtr Memory,
        TecmaSize Size
    );

    TecmaPtr TecmaVirtualAllocCall(
        TecmaPtr Memory,
        TecmaSize Size
    );

    TecmaPtr TecmaReadCall(
        TecmaText Location
    );

    TecmaPtr TecmaWriteCall(
        TecmaText Location,
        TecmaPtr WriteData
    );

    template<typename SystemCallReturnType, typename... SystemCallArguements>
    inline SystemCallReturnType TecmaOSCall(
        TecmaInt64 SystemCallFlag,
        SystemCallArguements... SystemCallArgs
    ) { 
        #if defined(__linux__)
            if(
               SystemCallFlag == TECMA_SYS_CALL_HEAP_ALLOC_FLAG 
            ) TecmaHeapAllocCall(SystemCallArgs...);
            else if(
               SystemCallFlag == TECMA_SYS_CALL_VIRTUAL_ALLOC_FLAG 
            ) TecmaVirtualAllocCall(SystemCallArgs...);
        #endif
        
    }

};

#endif