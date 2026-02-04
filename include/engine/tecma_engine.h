#ifndef __TECMA_ENGINE_H
#define __TECMA_ENGINE_H

#include "../vulkan/tecma_vulkan.h"
#include "../platform/tecma_window.h"

namespace TecmaEngine {
    struct TecmaApplication {
        explicit TecmaApplication() noexcept;

        friend void InitTecmaApplication(
            TecmaApplication& Application,
            const TecmaApplicationCreateInfo* ApplicationInfo 
        );

        private:
            TecmaVulkan::TecmaVulkanModule _vulkanModule;
            TecmaPlatform::TecmaWindowModule _windowModule;

    };

    void InitTecmaApplication(
        TecmaApplication& Application,
        const TecmaApplicationCreateInfo* ApplicationInfo 
    );

}

#endif