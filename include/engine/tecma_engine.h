#ifndef __TECMA_ENGINE_H
#define __TECMA_ENGINE_H

#include <stdio.h>

#include "../vulkan/tecma_vulkan.h"
#include "../platform/tecma_window.h"

namespace TecmaEngine {
    struct TecmaEngineApplication {
        explicit TecmaEngineApplication() noexcept;
        ~TecmaEngineApplication() noexcept;

        friend void InitTecmaApplication(
            TecmaEngineApplication& _application,
            const TecmaEngineApplicationCreateInfo* _applicationInfo 
        );

        const TecmaResult InitTecmaWindow(
            TecmaPlatform::TecmaWindowModule& _windowModule,
            TecmaWindowModuleCreateInfo& _windowInfo
        );

        void TecmaRunEngine();

        inline void TecmaStatusUpdate( const TecmaStatus& _new ) { _engineStatus = _new; };

        private:
            volatile TecmaBool _engineRunning;      //
            TecmaResult _actionResult;              // the trio that will hold everything by balls or strain of hair depending
            TecmaStatus _engineStatus;              // on the developers power of autism.
            TecmaCore::TecmaCoreModule _coreModule;
            TecmaVulkan::TecmaVulkanModule _vulkanModule;
            TecmaPlatform::TecmaWindowModule _windowModule;

    };

    void InitTecmaEngineApplication(
        TecmaEngineApplication& _application,
        const TecmaEngineApplicationCreateInfo* _applicationInfo 
    );

    const TecmaResult InitTecmaEngineWindow(
        TecmaPlatform::TecmaWindowModule& _windowModule,
        TecmaWindowModuleCreateInfo& _windowInfo
    );

}

#endif