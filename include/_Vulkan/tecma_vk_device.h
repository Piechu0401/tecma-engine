#ifndef __TECMA_VK_DEVICE_H
#define __TECMA_VK_DEVICE_H

#include "tecma_vk_core.h"
#include <vulkan/vulkan_core.h>

namespace TecmaEngine {
    typedef struct TecmaVkDevice {
        explicit TecmaVkDevice() noexcept;
        explicit TecmaVkDevice(
            const TecmaVkDevice& __other
        ) noexcept;
        explicit TecmaVkDevice(
            const TecmaVkDevice&& __other
        ) noexcept;
        ~TecmaVkDevice() noexcept;

        VkDevice __dev;
        VkPhysicalDevice __physDev;
        VkPhysicalDeviceFeatures __physDevFeat;
        std::vector<VkDeviceQueueCreateInfo> __queueInfos;
        std::vector<std::vector<float>> __queuePriorities;
        
        void CreateVkDevice(
            const VkInstance& __inst,
            const VkPhysicalDevice& __physicalDev
        );

        void DestroyVkDevice() noexcept;

        private:

        void InitVkDeviceQueueCreateInfos(
            const VkInstance& __inst
        );

    } TecmaVkDevice_t;

};

#endif