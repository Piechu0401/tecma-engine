#ifndef __TECMA_WINDOW_UI_H 
#define __TECMA_WINDOW_UI_H

#ifndef __TECMA_OS_H
    #include "tecma_os.h"
#endif

#ifndef __TECMA_CREATE_INFOS_H
    #include "../core/tecma_create_infos.h"
#endif

namespace TecmaPlatfrom {
    struct TecmaRect {
        explicit TecmaRect() noexcept;

    };
    
    struct TecmaButton {
        explicit TecmaButton() noexcept;

        Window _buttonWindow;

    };

    const TecmaResult TecmaCreateButton();
    const TecmaResult TecmaCreateRect();

};

#endif