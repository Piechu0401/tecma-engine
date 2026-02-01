#include "tecma_os.h"
#include <unistd.h>

void TecmaPrintTerminal(TecmaText ContnetBuffer, ...) noexcept {
    auto ContentBufferSize = [
        &ContnetBuffer
    ]() -> const TecmaU64 {
        TecmaU64 _size = 0;

        while(
            ContnetBuffer[_size] != '\0'
        ) ++_size;

        return ++_size;

    };
    
    syscall(
        __NR_write,
        STDOUT_FILENO,
        ContnetBuffer,
        ContentBufferSize
    );

}

[[noreturn]] void TecmaTerminate() noexcept {
    #if __TECMA_USING_OS == 0
        syscall(
            __NR_tgkill,
            TecmaCurrentProcessID(),
            TecmaCurrentThreadID(),
            SIGABRT
        );
        syscall(
            __NR_exit_group,
            1
        );
    #endif
    _exit(1);

}

const TecmaU64 TecmaCurrentProcessID() noexcept { 
    #if __TECMA_USING_OS == 0
        return syscall(__NR_getpid); 
    #endif    
};

const TecmaU64 TecmaCurrentThreadID() noexcept {
    #if __TECMA_USING_OS == 0
        return syscall(__NR_gettid); 
    #endif
}