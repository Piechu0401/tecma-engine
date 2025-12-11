#include "../_Core/tecma_physical_device.hpp"
#include <cstdint>
#include <stdexcept>
#include <vulkan/vulkan_core.h>

const VkSurfaceCapabilitiesKHR TecmaVulkanPhysicalDevice::GetSurfaceCapabilities(
    const VkSurfaceKHR& Surface
) {
    if(
        Surface != VK_NULL_HANDLE
    ) {
        VkSurfaceCapabilitiesKHR SurfaceCapabilities{};
        VkResult Result = vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
            PhysicalDevice,
            Surface,
            &SurfaceCapabilities
        );

        if(
            Result != VK_SUCCESS
        ) throw std::runtime_error("");

        return SurfaceCapabilities;

    }

    throw std::runtime_error("");

}

const long double TecmaVulkanPhysicalDevice::ScorePhysicalDevice(
    const VkPhysicalDevice& Candidate,
    VkPhysicalDeviceProperties& Properties,
    VkPhysicalDeviceMemoryProperties& MemoryProperties,
    VkPhysicalDeviceFeatures& Features
) {      
    long double PhysicalDeviceScore = 0;

    if(
        Properties.deviceType == VK_PHYSICAL_DEVICE_TYPE_OTHER
    ) PhysicalDeviceScore += 0.1L;
    else if(
        Properties.deviceType == VK_PHYSICAL_DEVICE_TYPE_CPU
    ) PhysicalDeviceScore += 0.2L;
    else if(
        Properties.deviceType == VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU
    ) PhysicalDeviceScore += 0.3L;
    else if(
        Properties.deviceType == VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU
    ) PhysicalDeviceScore += 0.4L;
    else if(
        Properties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU
    ) PhysicalDeviceScore += 0.5L;

    PhysicalDeviceScore += 
        (long double)Properties.limits.maxMemoryAllocationCount / (long double)UINT64_MAX + 
        (long double)Properties.limits.maxComputeSharedMemorySize / (long double)UINT64_MAX + 
        (long double)Properties.limits.maxPerStageDescriptorStorageBuffers / (long double)UINT64_MAX;

    for(
        int i = 0; i < MemoryProperties.memoryHeapCount; i++
    ) {
        double VramTypeWeight = 10;

        if(
            MemoryProperties.memoryHeaps->flags & VK_MEMORY_HEAP_DEVICE_LOCAL_BIT
        ) PhysicalDeviceScore -= (double)VK_MEMORY_HEAP_MULTI_INSTANCE_BIT / VramTypeWeight;
        else if( 
            MemoryProperties.memoryHeaps->flags & VK_MEMORY_HEAP_MULTI_INSTANCE_BIT
        ) PhysicalDeviceScore -= (double)VK_MEMORY_HEAP_MULTI_INSTANCE_BIT / VramTypeWeight;
        else if(
            MemoryProperties.memoryHeaps->flags & VK_MEMORY_HEAP_TILE_MEMORY_BIT_QCOM
        ) PhysicalDeviceScore -= (double)VK_MEMORY_HEAP_TILE_MEMORY_BIT_QCOM / VramTypeWeight;

        PhysicalDeviceScore += 
            (long double)MemoryProperties.memoryHeaps[i].size / (long double)(TecmaGigaByte);

    }

    return PhysicalDeviceScore;

}

const VkResult TecmaVulkanPhysicalDevice::PickPhysicalDevice(
    const VkInstance& Instance
) {
    uint32_t Count = 0;

    VkResult Result = vkEnumeratePhysicalDevices(
        Instance,
        &Count,
        NULL
    );

    if(
        Result != VK_SUCCESS
    ) return Result;

    TECMA_STD::TecmaDynamicArray<VkPhysicalDevice> PhysicalDevices(
        Count
    );

    Result = vkEnumeratePhysicalDevices(
        Instance,
        &Count,
        PhysicalDevices.GetData()
    );

    if(
        Result != VK_SUCCESS
    ) return Result;

    long double MaxScore = 0;

    for(auto& Device : PhysicalDevices) {
        VkPhysicalDeviceProperties Properties{};
        VkPhysicalDeviceMemoryProperties MemoryProperties{};
        VkPhysicalDeviceFeatures Features{};

        vkGetPhysicalDeviceProperties(
            Device,
            &Properties
        );

        vkGetPhysicalDeviceMemoryProperties(
            Device,
            &MemoryProperties
        );

        vkGetPhysicalDeviceFeatures(
            Device,
            &Features
        );
        
        long double PhysicalDeviceScore = ScorePhysicalDevice(
            Device,
            Properties,
            MemoryProperties,
            Features
        );
        
        if(
            MaxScore < PhysicalDeviceScore
        ) {
            MaxScore = PhysicalDeviceScore;
            PhysicalDevice = Device;
            PhysicalDeviceProperties = Properties;
            PhysicalDeviceMemoryProperties= MemoryProperties;
            PhysicalDeviceFeatures = Features;

        }

    }

    return Result;

}

const VkResult TecmaVulkanPhysicalDevice::CreateQueueCreateInfos() {
    uint32_t Count = 0;

    vkGetPhysicalDeviceQueueFamilyProperties(
        PhysicalDevice,
        &Count,
        NULL
    );

    if(
        Count == 0
    ) return VK_ERROR_UNKNOWN;

    TECMA_STD::TecmaDynamicArray<VkQueueFamilyProperties> QueueFamilyProperties(Count);
    Priorities.Resize(
        Count
    );

    uint32_t Index = 0;

    for(
        auto& Property : QueueFamilyProperties
    ) {
        Priorities[Index].Resize(
            Property.queueCount
        );
        QueueFamilyIndices.EmplaceBack(
            TECMA_STD::MakeTecmaPair(
                Property.queueFlags,
                Index
            )
        );

        for(
            int i = 0; i < Property.queueCount; i++
        ) Priorities[Index].EmplaceBack(1.0f);

        DeviceQueueCreateInfos.EmplaceBack(
            VkDeviceQueueCreateInfo{
                .sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO,
                .pNext = NULL,
                .flags = 0,
                .queueFamilyIndex = QueueFamilyIndices[Index].Second(),
                .queueCount = Property.queueCount,
                .pQueuePriorities = Priorities[Index].GetData()  
            }
        );

        Index++;

    }

    return VK_SUCCESS;

}


const VkResult CreateTecmaVulkanPhysicalDevice(
    TecmaVulkanPhysicalDevice& PhysicalDevice,
    const TECMA_CREATE_INFO::TecmaVulkanPhysicalDeviceCreateInfo* PhysicalDeviceCreateInfo
) {
    PhysicalDevice.PickPhysicalDevice(
        *PhysicalDeviceCreateInfo->Instance
    );
    PhysicalDevice.CreateQueueCreateInfos();

    return VK_SUCCESS;

}