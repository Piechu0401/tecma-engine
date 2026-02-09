#ifndef __TECMA_CONSTANTS_H
#define __TECMA_CONSTANTS_H

// basic shit for the engine

#ifndef TECMA_ENGINE_NAME
    #define TECMA_ENGINE_NAME "Tecma Engine"
#endif

#ifndef TECMA_ENGINE_VERSION
    #define TECMA_ENGINE_VERSION 1
#endif

#ifndef TECMA_TRUE
    #define TECMA_TRUE 1
#endif

#ifndef TECMA_FALSE
    #define TECMA_FALSE 0
#endif

#ifndef TECMA_EOF   
    #define TECMA_EOF '\0'
#endif

// status messages 
//      |
//      |
//      |
//     \|/

#define TECMA_STATUS_INIT_ENGINE_MESSAGE "[ Status ] : { Iniciating Tecma Engine dependencies... }\n"
#define TECMA_STATUS_CREATING_NEW_THREAD_MESSAGE "[ Status ] : { Creating new thread... }\n"
#define TECMA_STATUS_INIT_WINDOW_MESSAGE "[ Status ] : { Iniciating window dependencies... }\n"
#define TECMA_STATUS_INIT_VULKAN_MESSAGE "[ Status ] : { Iniciating Vulkan SDK dependencies... }\ns"

// error entry

#define TECMA_TERMINATE_MESSAGE                 "[ The program has been terminated due to ] :\n"

// error core messages and shit

#define TECMA_ERROR_FROM_X                      "[ Error from xlib says ] -> "
#define TECMA_ERROR_FROM_VK                     "[ Error from vulkan says ] -> "
#define TECMA_ERROR_FROM_WINDOWS                "[ Error from Windows says ] -> "
#define TECMA_ERROR_FROM_LINUX                  "[ Error from Linux says ] -> "

// root cause of the error part, kinda bullshit but idc

#define TECMA_ERROR_PART_EXECUTE_FAILED         "'Tecma Engine failed to execute'"
#define TECMA_ERROR_PART_INVALID_ARG_FAILED     "'Tecma Engine failed with argument'"

// errors and stuff

#define TECMA_ERROR_X_OPEN_DISPLAY_FAILED       "'XOpenDisplay()'\n"
#define TECMA_ERROR_X_CREATE_WINDOW_BAD_VALUE   "'Window'\n"
#define TECMA_ERROR_X_CREATE_WINDOW_BAD_WINDOW  "'Window'\n"
#define TECMA_ERROR_X_CREATE_WINDOW_BAD_PIXMAP  
#define TECMA_ERROR_X_CREATE_WINDOW_BAD_CURSOR
#define TECMA_ERROR_X_CREATE_WINDOW_BAD_MATCH
#define TECMA_ERROR_X_CREATE_WINDOW_BAD_ALLOC
#define TECMA_ERROR_X_CREATE_WINDOW_BAD_COLOR

#define TECMA_I8_MIN    (-((TecmaI8)(1) << 7)) // limits and  blah blah blah
#define TECMA_I16_MIN   (-((TecmaI16)(1) << 15))
#define TECMA_I32_MIN   (-((TecmaI32)(1) << 31))
#define TECMA_I64_MIN   (-((TecmaI64)(1) << 63))
#define TECMA_I8_MAX    (((TecmaI8)(1) << 7))
#define TECMA_I16_MAX   (((TecmaI16)(1) << 15))
#define TECMA_I32_MAX   (((TecmaI32)(1) << 31))
#define TECMA_I64_MAX   (((TecmaI64)(1) << 63))
#define TECMA_U8_MAX    ((((((TecmaU8)(1) << 7) - 1) << 1) + 1 ))
#define TECMA_U16_MAX   ((((((TecmaU16)(1) << 15) - 1) << 1) + 1))
#define TECMA_U32_MAX   ((((((TecmaU32)(1) << 31) - 1) << 1) + 1))
#define TECMA_U64_MAX   ((((((TecmaU64)(1) << 63) - 1) << 1) + 1))

#endif
