#ifndef __TECMA_ENGINE_H
#define __TECMA_ENGINE_H

#include "../vulkan/tecma_vulkan.h"
#include "../platform/tecma_window.h"

namespace TecmaEngine {
    struct TecmaApplication {
        explicit TecmaApplication() noexcept;

        friend const TecmaResult InitTecmaApplication(
            TecmaApplication& Application,
            const TecmaApplicationCreateInfo* ApplicationInfo 
        );

        private:
            TecmaVulkan::TecmaVulkanModule* VulkanModule;
            TecmaPlatform::TecmaWindowModule* WindowModule;

    };

    const TecmaResult InitTecmaApplication(
        TecmaApplication& Application,
        const TecmaApplicationCreateInfo* ApplicationInfo 
    );

}

#endif