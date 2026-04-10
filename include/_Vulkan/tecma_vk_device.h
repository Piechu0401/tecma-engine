#ifndef __TECMA_VK_DEVICE_H
#define __TECMA_VK_DEVICE_H

#include "tecma_vk_core.h"
#include <vulkan/vulkan_core.h>

namespace TecmaEngine {
    struct TecmaVkDevice_t {
        explicit TecmaVkDevice_t() noexcept;
        explicit TecmaVkDevice_t(
            const TecmaVkDevice_t& __other
        ) noexcept;
        explicit TecmaVkDevice_t(
            const TecmaVkDevice_t&& __other
        ) noexcept;
        ~TecmaVkDevice_t() noexcept;

        const unsigned int FindMemoryIndex(
            const VkMemoryPropertyFlagBits& __memProp
        ) const noexcept;
        const std::vector<unsigned int> GetFamilyIndices() const noexcept;

        VkDevice __dev = VK_NULL_HANDLE;
        VkPhysicalDevice __physDev = VK_NULL_HANDLE;
        VkPhysicalDeviceFeatures __physDevFeat;
        VkPhysicalDeviceProperties __physDevProps;
        VkPhysicalDeviceMemoryProperties __physDevMemProps;
        std::vector<VkDeviceQueueCreateInfo> __queueInfos;
        std::vector<std::vector<float>> __queuePriorities;
        float __prior = 1.0f;

        void CreateVkDevice(
            const VkInstance& __inst
        );

        void DestroyVkDevice() noexcept;

        private:

        void PickBestAvailableDevice(
            const VkInstance&
        );

        void InitVkDeviceQueueCreateInfos(
            const VkInstance& __inst
        );

    };

};

#endif