#include "../_Core/tecma_logical_device.hpp"
#include <vulkan/vulkan_core.h>

const VkDevice& TecmaVulkanLogicalDevice::GetVkDevice() const { return Device; }
const VkQueue& TecmaVulkanLogicalDevice::GetVkQueue(
    const TecmaUint64 QueueFamilyIndex,
    const TecmaUint64 QueueIndex
) { return Queues[QueueFamilyIndex][QueueIndex]; }

const VkBool32 TecmaVulkanLogicalDevice::DeviceSupportsLayers(
    const char* const* Layers
) const {
    TecmaUint32 Count = 0;

    return VK_TRUE;

}

const VkBool32 TecmaVulkanLogicalDevice::DeviceSupportsExtensions(
    const char* const* Extensions
) const {
    return VK_TRUE;

}

const VkResult CreateTecmaVulkanLogicalDevice(
    TecmaVulkanLogicalDevice& LogicalDevice,
    const TECMA_CREATE_INFO::TecmaVulkanLogicalDeviceCreateInfo* CreateInfo
) {
    VkDeviceCreateInfo Info{};

    Info.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    Info.pNext = TECMA_NULL;
    Info.flags = 0;
    Info.pEnabledFeatures = CreateInfo->PhysicalDeviceFeatures;
    Info.pQueueCreateInfos = CreateInfo->QueueCreateInfos;
    Info.queueCreateInfoCount = CreateInfo->QueueCreateInfoCount;

    return VK_SUCCESS;

}