#ifndef __TECMA_CREATE_INFOS_H 
#define __TECMA_CREATE_INFOS_H

#ifndef __TECMA_ENUMS_H
    #include "tecma_enums.h"
#endif

#ifndef __TECMA_OS_H
    #include "tecma_os.h"
#endif

#ifndef __TECMA_TYPES_H
    #include "tecma_types.h"
#endif

struct TecmaCreateInfo {
    virtual ~TecmaCreateInfo();
    virtual const TecmaResult ValidInfo();
    virtual TecmaCreateInfo& operator=(
        const TecmaCreateInfo& other
    );

};

struct TecmaApplicationCreateInfo : TecmaCreateInfo {
    TecmaU32 windowInitWidth;
    TecmaU32 windowInitHeight;
    TecmaU32 applicationVersion;
    TecmaText applicationName;
    TecmaU32 tecmaEngineArgumentsCount;
    TecmaText tecmaEngineArguments[];

};

struct TecmaWindowModuleCreateInfo : TecmaCreateInfo {
    TecmaI32 _x;
    TecmaI32 _y;
    TecmaU32 _width;
    TecmaU32 _height;
    TecmaText _windowTitle;
    TecmaU32 _fullscreen : 1;    

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

#endif