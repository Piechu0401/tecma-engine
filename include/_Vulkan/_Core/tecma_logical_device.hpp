#ifndef TECMA_LOGICAL_DEVICE_HPP 
#define TECMA_LOGICAL_DEVICE_HPP

#include "../../_Core/tecma_create_info.hpp"
#include "../../_Core/tecma_standard.hpp"

struct TecmaVulkanLogicalDevice {
    friend const VkResult CreateTecmaVulkanLogicalDevice(
        TecmaVulkanLogicalDevice& LogicalDevice,
        const TECMA_CREATE_INFO::TecmaVulkanLogicalDeviceCreateInfo* CreateInfo
    );

    const VkDevice& GetVkDevice() const;
    const VkQueue& GetVkQueue(
        const TecmaUint64 QueueFamilyIndex,
        const TecmaUint64 QueueIndex
    );

    private:
        VkDevice Device;
        TECMA_STD::TecmaDynamicArray<TECMA_STD::TecmaDynamicArray<VkQueue>> Queues;

        const VkBool32 DeviceSupportsLayers(
            const char* const* Layers
        ) const;
        const VkBool32 DeviceSupportsExtensions(
            const char* const* Extensions
        ) const;

};

const VkResult CreateTecmaVulkanLogicalDevice(
    TecmaVulkanLogicalDevice& LogicalDevice,
    const TECMA_CREATE_INFO::TecmaVulkanLogicalDeviceCreateInfo* CreateInfo
);

#endif