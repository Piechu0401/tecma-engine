#ifndef TECMA_VULKAN_CORE_HPP
#define TECMA_VULKAN_CORE_HPP

#include "../_Core/tecma_allocation_callbacks.hpp"
#include "../_Core/tecma_debug_utils_messenger.hpp"
#include "../_Core/tecma_instance.hpp"
#include "../_Core/tecma_physical_device.hpp"
#include "../_Core/tecma_logical_device.hpp"
#include "../_Core/tecma_user_data.hpp"
#include <vulkan/vulkan_core.h>

struct TecmaVulkanCore {
    friend const VkResult CreateTecmaVulkanCore(
        TecmaVulkanCore& VulkanCore
    );
    
    private:
        TECMA_STD::TecmaUniquePtr<TecmaVulkanUserData> UserData = NULL;
        TECMA_STD::TecmaUniquePtr<TecmaVulkanAllocationCallbacks> AllocationCallbacks = NULL;
        TECMA_STD::TecmaUniquePtr<TecmaVulkanDebugUtilsMessenger> DebugUtilsMessenger = NULL;
        TECMA_STD::TecmaUniquePtr<TecmaVulkanInstance> EngineVulkanInstance = NULL;
        TECMA_STD::TecmaUniquePtr<TecmaVulkanPhysicalDevice> EnginePhysicalDevice = NULL;
        TECMA_STD::TecmaUniquePtr<TecmaVulkanLogicalDevice> EngineLogicalDevice = NULL;

        const VkResult CreateAllocationCallbacks();
        const VkResult CreateDebugUtilsMessenger();
        const VkResult CreateEngineVulkanInstance();
        const VkResult CreateEnginePhysicalDevice();
        const VkResult CreateEngineLogicalDevice(); 

};

const VkResult CreateTecmaVulkanCore(
    TecmaVulkanCore& VulkanCore
);

TecmaPtr TecmaVulkanAllocationFunction(
    TecmaPtr UserData,
    TecmaSize Size,
    TecmaSize Aligment,
    VkSystemAllocationScope AllocationScope
);

TecmaPtr TecmaVulkanReallocationFunction(
    TecmaPtr UserData,
    TecmaPtr Original,
    TecmaSize Size,
    TecmaSize Aligment,
    VkSystemAllocationScope AllocationScope
);

TecmaFunc TecmaVulkanFreeFunction(
    TecmaPtr UserData,
    TecmaPtr Memory
);

TecmaFunc TecmaVulkanAllocationNotificationFunction(
    TecmaPtr UserData, 
    TecmaSize Size,
    VkInternalAllocationType AllocationType,
    VkSystemAllocationScope AllocationScope
);

TecmaFunc TecmaVulkanFreeNotificationFunction(
    TecmaPtr UserData, 
    TecmaSize Size,
    VkInternalAllocationType AllocationType,
    VkSystemAllocationScope AllocationScope
);

VkBool32 TecmaUserCallbackFunction(
    VkDebugUtilsMessageSeverityFlagBitsEXT Severity,
    VkDebugUtilsMessageTypeFlagsEXT Type,
    const VkDebugUtilsMessengerCallbackDataEXT* CallbackData, 
    TecmaPtr UserData
);

#endif