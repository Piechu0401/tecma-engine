#ifndef __TECMA_CREATE_INFOS_H 
#define __TECMA_CREATE_INFOS_H

#ifndef __TECMA_ENUMS_H
    #include "tecma_enums.h"
#endif

#ifndef __TECMA_OS_H
    #include "../platform/tecma_os.h"
#endif

#ifndef __TECMA_TYPES_H
    #include "tecma_types.h"
#endif

struct TecmaApplicationCreateInfo  {
    TecmaU32 _windowInitWidth;
    TecmaU32 _windowInitHeight;
    TecmaU32 _applicationVersion;
    TecmaText _applicationName;
    TecmaI32 _tecmaEngineArgumentsCount;
    TecmaText* _tecmaEngineArguments;
    TecmaApplicationType _tecmaEngineApplicationType;

};

struct TecmaWindowModuleCreateInfo {
    TecmaI32 _x;
    TecmaI32 _y;
    TecmaU32 _width;
    TecmaU32 _height;
    TecmaText _windowTitle;
    TecmaBool _fullscreen;    

    #if __TECMA_USING_OS == 0
        Window _parent;
        unsigned int _borderWidth;
        int _depth;
        unsigned int _class;
        Visual* _visual;
        unsigned long _valueMask;
        XSetWindowAttributes* _attributes;
    #endif

};

struct TecmaInstanceCreateInfo {
    const char* const* _exts;
    unsigned int _extCount;
    const char* const* _lays;
    unsigned int _layCount;
    const char* _tecmaApplicationName;
    unsigned int _tecmaApplicationVersion;

};

#endif