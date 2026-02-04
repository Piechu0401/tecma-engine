#ifndef __TECMA_CONSTANTS_H
#define __TECMA_CONSTANTS_H

// basic shit for the engine

#ifndef TECMA_ENGINE_NAME
    #define TECMA_ENGINE_NAME "Tecma Engine"
#endif

#ifndef TECMA_ENGINE_VERSION
    #define TECMA_ENGINE_VERSION 1
#endif

#ifndef TECMA_ENGINE_INIT_BORDER_WIDTH
    #define TECMA_ENGINE_INIT_BORDER_WIDTH (1 << 2)
#endif

#ifndef TECMA_TRUE
    #define TECMA_TRUE 1
#endif

#ifndef TECMA_FALSE
    #define TECMA_FALSE 0
#endif

// error core messages and shit

#define TECMA_ERROR_FROM_X                      "Error from xlib says -> "
#define TECMA_ERROR_FROM_VK                     "Error from vulkan says -> "
#define TECMA_ERROR_FROM_WINDOWS                "Error from Windows OS says -> "
#define TECMA_ERROR_FROM_LINUX                  "Error from Linux OS says -> "

// root cause of the error part, kinda bullshit but idc

#define TECMA_ERROR_PART_EXECUTE_FAILED         "Tecma Engine failed to execute: "
#define TECMA_ERROR_PART_INVALID_ARG_FAILED     "Tecma Engine failed with argument: "

// errors and stuff

#define TECMA_ERROR_X_OPEN_DISPLAY_FAILED       "'XOpenDisplay()'\n"
#define TECMA_ERROR_X_CREATE_WINDOW_BAD_VALUE   "'Window'\n"
#define TECMA_ERROR_X_CREATE_WINDOW_BAD_WINDOW  "'Window'\n"
#define TECMA_ERROR_X_CREATE_WINDOW_BAD_PIXMAP  
#define TECMA_ERROR_X_CREATE_WINDOW_BAD_CURSOR
#define TECMA_ERROR_X_CREATE_WINDOW_BAD_MATCH
#define TECMA_ERROR_X_CREATE_WINDOW_BAD_ALLOC
#define TECMA_ERROR_X_CREATE_WINDOW_BAD_COLOR

#define TECMA_I8_MIN    (-(1 << 7)) // limits and  blah blah blah
#define TECMA_I16_MIN   (-(1 << 15))
#define TECMA_I32_MIN   (-(1 << 31))
#define TECMA_I64_MIN   (-(1 << 63))
#define TECMA_I8_MAX    (1 << 7)
#define TECMA_I16_MAX   (1 << 15)
#define TECMA_I32_MAX   (1 << 31)
#define TECMA_I64_MAX   (1 << 63)
#define TECMA_U8_MAX    (1 << 8)
#define TECMA_U16_MAX   (1 << 16)
#define TECMA_U32_MAX   (1 << 32)
#define TECMA_U64_MAX   ((((1 << 63) - 1) << 1) + 1)

#endif
