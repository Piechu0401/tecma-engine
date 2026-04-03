#include "tecma_vk_device.h"
#include <vulkan/vulkan_core.h>

namespace TecmaEngine {
    TecmaVkDevice::TecmaVkDevice() noexcept {}
    TecmaVkDevice::TecmaVkDevice(
        const TecmaVkDevice& __other
    ) noexcept {}
    TecmaVkDevice::TecmaVkDevice(
        const TecmaVkDevice&& __other
    ) noexcept {}
    TecmaVkDevice::~TecmaVkDevice() noexcept {}
    
    void TecmaVkDevice::InitVkDeviceQueueCreateInfos(
        const VkInstance& __inst
    ) {
        unsigned int __count{0};

        vkGetPhysicalDeviceQueueFamilyProperties(
            __physDev,
            &__count,
            NULL
        );

        VkQueueFamilyProperties __props[__count];

        vkGetPhysicalDeviceQueueFamilyProperties(
            __physDev,
            &__count,
            __props
        );

        __queuePriorities.resize( __count );

        for( unsigned int __i{0}; __i < __count; ++__i ) {
            __queuePriorities[__i] = std::vector<float>(
                __props[__i].queueCount,
                1.0f
            );

            __queueInfos.emplace_back(
                VkDeviceQueueCreateInfo{
                    .sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO,
                    .pNext = NULL,
                    .flags = 0,
                    .queueFamilyIndex = __i,
                    .queueCount = (unsigned int)__queuePriorities[__i].size(),
                    .pQueuePriorities = __queuePriorities[__i].data()
                }
            );

        }

    }

    void TecmaVkDevice::CreateVkDevice(
        const VkInstance& __inst,
        const VkPhysicalDevice& __physicalDev
    ) {
        VkDeviceCreateInfo __info{};

        __physDev = __physicalDev;
        
        InitVkDeviceQueueCreateInfos( __inst );
        vkGetPhysicalDeviceFeatures(
            __physDev,
            &__physDevFeat
        );

        __info.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
        __info.pNext = nullptr;
        __info.flags = 0;
        __info.pQueueCreateInfos = __queueInfos.data();
        __info.queueCreateInfoCount = (unsigned int)__queueInfos.size();
        __info.ppEnabledExtensionNames = TecmaVkDeviceExtensionNames.data();
        __info.ppEnabledLayerNames = TecmaVkDeviceLayerNames.data();
        __info.enabledExtensionCount = (unsigned int)TecmaVkDeviceExtensionNames.size();
        __info.enabledLayerCount = (unsigned int)TecmaVkDeviceLayerNames.size();
        __info.pEnabledFeatures = &__physDevFeat;

        TecmaLogger(
            (TecmaVkResult)vkCreateDevice(
                __physDev,
                &__info,
                NULL,
                &__dev
            ),
            VK_FUNCTION_FLAG_VK_CREATE_DEVICE
        );

    }

    void TecmaVkDevice::DestroyVkDevice() noexcept {
        __queueInfos.clear();
        __queuePriorities.clear();

        vkDestroyDevice(
            __dev,
            NULL
        );

        TecmaLogger(
            VK_SUCCESS,
            VK_FUNCTION_FLAG_VK_DESTROY_DEVICE
        );

    }

};