#ifndef __TECMA_VULKAN_H
#define __TECMA_VULKAN_H

#include "tecma_vk_render_pass.h"
#ifndef __TECMA_VK_INSTANCE_H
    #include "tecma_vk_instance.h"
#endif

#ifndef __TECMA_VK_DEBUG_UTILS_H
    #include "tecma_vk_debug_utils.h"
#endif

#ifndef __TECMA_VK_DEVICE_H
    #include "tecma_vk_device.h"
#endif

#ifndef __TECMA_VK_RENDERER_H
    #include "tecma_vk_renderer.h"
#endif

namespace TecmaEngine {
    struct TecmaVulkan_t {
        explicit TecmaVulkan_t() noexcept;

        explicit TecmaVulkan_t(
            TecmaVulkan_t& __other
        ) noexcept;

        explicit TecmaVulkan_t(
            TecmaVulkan_t&& __other
        ) noexcept;

        ~TecmaVulkan_t() noexcept;

        void CreateVulkan(
            TecmaVkSurfaceDependencies_t& __dep
        );
        void DestroyVulkan();

        private:

        TecmaVkInstance_t __instance;
        TecmaVkDebugUtils_t __debugUtils;
        TecmaVkDevice_t __device;
        TecmaVkRenderer_t __renderer;

    };

}

#endif