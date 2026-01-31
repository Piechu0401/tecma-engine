#ifndef __TECMA_OS_H
#define __TECMA_OS_H

#if defined(__linux__)
    #ifndef __TECMA_USING_OS
        #define __TECMA_USING_OS 0
    #endif
    #if !defined(__TECMA_USING_XLIB)
        #include <X11/Xlib.h>
    #endif
#elif defined(__WIN32) || defined(__WIN64)
    #ifndef __TECMA_USING_OS
        #define __TECMA_USING_OS 1
    #endif
    #include <windows.h>
#endif

#endif