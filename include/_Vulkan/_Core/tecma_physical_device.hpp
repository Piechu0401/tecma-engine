#ifndef TECMA_PHYSICAL_DEVICE_HPP 
#define TECMA_PHYSICAL_DEVICE_HPP

#include "../../_Core/tecma_create_info.hpp"
#include "../../_Core/tecma_standard.hpp"

struct TecmaVulkanPhysicalDevice {
    friend const VkResult CreateTecmaVulkanPhysicalDevice(
        TecmaVulkanPhysicalDevice& PhysicalDevice,
        const TECMA_CREATE_INFO::TecmaVulkanPhysicalDeviceCreateInfo* PhysicalDeviceCreateInfo
    );
    
    const VkPhysicalDevice& GetPhysicalDevice() const;
    const VkPhysicalDeviceProperties& GetPhysicalDeviceProperties() const;
    const VkPhysicalDeviceFeatures& GetPhysicalDeviceFeatures() const;
    const VkDeviceQueueCreateInfo& GetDeviceQueueCreateInfos() const;
    const VkSurfaceCapabilitiesKHR GetSurfaceCapabilities(
        const VkSurfaceKHR& Surface
    );
    const VkBool32 IsVkPresentModeAvailable(
        const VkSurfaceKHR& Surface,
        const VkPresentModeKHR DesiredPresentMode
    );

    private:
        VkPhysicalDevice PhysicalDevice;
        VkPhysicalDeviceProperties PhysicalDeviceProperties;
        VkPhysicalDeviceFeatures PhysicalDeviceFeatures;
        VkPhysicalDeviceMemoryProperties PhysicalDeviceMemoryProperties;
        TECMA_STD::TecmaDynamicArray<VkDeviceQueueCreateInfo> DeviceQueueCreateInfos; 
        TECMA_STD::TecmaDynamicArray<TECMA_STD::TecmaDynamicArray<float>> Priorities;
        TECMA_STD::TecmaDynamicArray<TECMA_STD::TecmaPair<VkQueueFlags, uint32_t>> QueueFamilyIndices;

        const VkResult PickPhysicalDevice(
            const VkInstance& Instance
        );
        const long double ScorePhysicalDevice(
            const VkPhysicalDevice& Candidate,
            VkPhysicalDeviceProperties& Properties,
            VkPhysicalDeviceMemoryProperties& MemoryProperties,
            VkPhysicalDeviceFeatures& Features
        );
        const VkResult CreateQueueCreateInfos();

};

const VkResult CreateTecmaVulkanPhysicalDevice(
    TecmaVulkanPhysicalDevice& PhysicalDevice,
    const TECMA_CREATE_INFO::TecmaVulkanPhysicalDeviceCreateInfo* PhysicalDeviceCreateInfo
);

#endif