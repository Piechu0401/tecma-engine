#ifndef __TECMA_CREATE_INFOS_H 
#define __TECMA_CREATE_INFOS_H

#include <X11/Xlib.h>
#ifndef __TECMA_ENUMS_H
    #include "tecma_enums.h"
#endif

#ifndef __TECMA_OS_H
    #include "../platform/tecma_os.h"
#endif

#ifndef __TECMA_TYPES_H
    #include "tecma_types.h"
#endif

// might need girlfriend create info asap lads

struct TecmaEngineApplicationCreateInfo  {
    TecmaI32 _tecmaEngineArgumentsCount;
    TecmaText* _tecmaEngineArguments;
};

struct TecmaWindowModuleCreateInfo {
    TecmaI32 _x;
    TecmaI32 _y;
    TecmaU32 _width;
    TecmaU32 _height;
    TecmaU32 _borderWidth;
    TecmaText _windowTitle;
    TecmaBool _fullscreen;

    #if __TECMA_USING_OS == __LINUX
        Window* _parent;
        Visual* _visiual;
        XSetWindowAttributes* _windowAttributes;
        TecmaU32 _windowClass;
        TecmaU32 _windowDepth;
        TecmaU64 _valueMask;
    #endif

};

// UI bullshit

struct TecmaButtonCreateInfo {
    TecmaButtonFunctionalityType _functionalityType;
    Display* _rootDisplay;
    Window* _rootWindow;
    TecmaBool _fromImage;
    TecmaU8 _buttonWidth;
    TecmaU8 _buttonHeight;
    TecmaI32 _buttonWindowX; // those fuckers will apply to coordinates within the root window
    TecmaI32 _buttonWindowY; //
    TecmaU64 _regularBttBckgrColor;
    TecmaU64 _overMouseBttBckgrColor;
    TecmaU64 _regularBttTextColor;
    TecmaU64 _overMouseBttTextColor;
    TecmaText _textContent;    

};

// Vulkan bullshit

struct TecmaInstanceCreateInfo {  // Daniel
    const char* const* _exts;
    unsigned int _extCount;
    const char* const* _lays;
    unsigned int _layCount;
    const char* _tecmaApplicationName;
    unsigned int _tecmaApplicationVersion;

};

struct TecmaDeviceCreateInfo { // The cooler Daniel
    const char* const* _exts;
    unsigned int _extCount;
    const char* const* _lays;
    unsigned int _layCount;

};

#endif