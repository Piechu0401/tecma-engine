#ifndef __TECMA_CREATE_INFO_H
#define __TECMA_CREATE_INFO_H

namespace TecmaEngine {
    struct TecmaWindowCreateInfo_ci {
        unsigned int __w;
        unsigned int __h;
        int __x;
        int __y;
        unsigned int __bordSize;
        unsigned long __backgrdClr;
        unsigned long __bordClr;
        const char* __title;

    };
    
};

#endif