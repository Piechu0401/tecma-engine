#ifndef __TECMA_CONSTANTS_H
#define __TECMA_CONSTANTS_H

// basic shit for the engine

#ifndef TECMA_ENGINE_NAME
    #define TECMA_ENGINE_NAME "Tecma Engine"
#endif

#ifndef TECMA_ENGINE_VERSION
    #define TECMA_ENGINE_VERSION 1
#endif

#ifndef TECMA_ENGINE_INIT_WINDOW_WIDTH
    #define TECMA_ENGINE_INIT_WINDOW_WIDTH 1000
#endif

#ifndef TECMA_ENGINE_INIT_WINDOW_HEIGHT
    #define TECMA_ENGINE_INIT_WINDOW_HEIGHT 600
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

#define TECMA_CREATE_ERROR(from, cause, message) ((char*)(from) + (char*)(cause) + (char*)(message))

#endif
