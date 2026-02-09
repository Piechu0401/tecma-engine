#include "tecma_os.h"
#include <unistd.h>

void TecmaPrintTerminal(TecmaText ContnetBuffer, ...) noexcept {
    TecmaU64 ContentBufferSize = TecmaTextLen(
        ContnetBuffer
    );

    #if __TECMA_USING_OS == __LINUX
        syscall(
            __NR_write,
            STDOUT_FILENO,
            ContnetBuffer,
            ContentBufferSize
        );

    #endif

}

[[noreturn]] void TecmaTerminate() noexcept {
    #if __TECMA_USING_OS == __LINUX
        syscall(
            __NR_tgkill,
            TecmaCurrentProcessID(),
            TecmaCurrentThreadID(),
            SIGABRT
        );
        syscall(
            __NR_exit_group,
            0
        );
    #endif

    _exit(0);

}

const TecmaU64 TecmaCurrentProcessID() noexcept { 
    #if __TECMA_USING_OS == __LINUX
        return syscall(__NR_getpid); 
    #endif    
};

const TecmaU64 TecmaCurrentThreadID() noexcept {
    #if __TECMA_USING_OS == __LINUX
        return syscall(__NR_gettid); 
    #endif
}