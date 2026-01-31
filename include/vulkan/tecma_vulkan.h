#ifndef __TECMA_VULKAN_H 
#define __TECMA_VULKAN_H

#include "../vulkan/tecma_instance.h"

namespace TecmaVulkan {
    struct TecmaVulkanModule {
        explicit TecmaVulkanModule() noexcept;

        private:
            TecmaInstance* EngineInstance;

    };

}

#endif