#include "../_Core/tecma_vulkan_core.hpp"
#include "tecma_allocation_callbacks.hpp"
#include "tecma_instance.hpp"
#include "tecma_logical_device.hpp"
#include "tecma_physical_device.hpp"
#include "tecma_user_data.hpp"
#include <vulkan/vulkan_core.h>

const VkResult TecmaVulkanCore::CreateAllocationCallbacks() {
    TECMA_CREATE_INFO::TecmaVulkanAllocationCallbacksCreateInfo AllocationCallbacksInfo;

    AllocationCallbacks = (TecmaVulkanAllocationCallbacks*)TECMA_MEMORY::TecmaMemoryAllocation(
        sizeof(
            TecmaVulkanAllocationCallbacks
        )
    );

    AllocationCallbacksInfo.UserData = UserData.Get();
    AllocationCallbacksInfo.AllocationFunction = TecmaVulkanAllocationFunction;
    AllocationCallbacksInfo.ReallocationFunction = TecmaVulkanReallocationFunction;
    AllocationCallbacksInfo.FreeFunction = TecmaVulkanFreeFunction;
    AllocationCallbacksInfo.AllocationNotificationFunction = TecmaVulkanAllocationNotificationFunction;
    AllocationCallbacksInfo.FreeNotificationFunction = TecmaVulkanFreeNotificationFunction;

    if(
        !CreateVulkanAllocationCallbacks(
            *AllocationCallbacks.Get(),
            &AllocationCallbacksInfo
        )
    ) return VK_ERROR_INITIALIZATION_FAILED;

    return VK_SUCCESS;

}

const VkResult TecmaVulkanCore::CreateDebugUtilsMessenger() {
    DebugUtilsMessenger = (TecmaVulkanDebugUtilsMessenger*)TECMA_MEMORY::TecmaMemoryAllocation(
        sizeof(
            TecmaVulkanDebugUtilsMessenger
        )
    );

    TECMA_CREATE_INFO::TecmaVulkanDebugUtilsMessengerCreateInfo CreateInfo;

    CreateInfo.Instance = &EngineVulkanInstance.Get()->GetInstance();
    CreateInfo.AllocationCallbacks = &AllocationCallbacks.Get()->GetAllocationCallbacks();
    CreateInfo.UserData = &UserData;
    CreateInfo.UserCallback = TecmaUserCallbackFunction;

    return CreateTecmaVulkanDebugUtilsMessenger(
        *DebugUtilsMessenger.Get(),
        &CreateInfo
    );

}

const VkResult TecmaVulkanCore::CreateEngineVulkanInstance() {
    EngineVulkanInstance = (TecmaVulkanInstance*)TECMA_MEMORY::TecmaMemoryAllocation(
        sizeof(
            TecmaVulkanInstance
        )
    );

    TECMA_CREATE_INFO::TecmaVulkanInstanceCreateInfo CreateInfo;

    CreateInfo.AllocationCallbacks = &AllocationCallbacks.Get()->GetAllocationCallbacks();

    return CreateTecmaVulkanInstance(
        *EngineVulkanInstance.Get(), 
        &CreateInfo
    );

}

const VkResult TecmaVulkanCore::CreateEnginePhysicalDevice() {
    EnginePhysicalDevice = (TecmaVulkanPhysicalDevice*)TECMA_MEMORY::TecmaMemoryAllocation(
        sizeof(
            TecmaVulkanPhysicalDevice
        )
    );

    TECMA_CREATE_INFO::TecmaVulkanPhysicalDeviceCreateInfo CreateInfo;

    CreateInfo.Instance = &EngineVulkanInstance.Get()->GetInstance();

    return CreateTecmaVulkanPhysicalDevice(
        *EnginePhysicalDevice.Get(),
        &CreateInfo
    );

}

const VkResult TecmaVulkanCore::CreateEngineLogicalDevice() {
    EngineLogicalDevice = (TecmaVulkanLogicalDevice*)TECMA_MEMORY::TecmaMemoryAllocation(
        sizeof(
            TecmaVulkanLogicalDevice
        )
    );

    TECMA_CREATE_INFO::TecmaVulkanLogicalDeviceCreateInfo CreateInfo;

    CreateInfo.Instance = &EngineVulkanInstance.Get()->GetInstance();
    CreateInfo.AllocationCallbacks = &AllocationCallbacks.Get()->GetAllocationCallbacks();
    CreateInfo.PhysicalDeviceFeatures = &EnginePhysicalDevice.Get()->GetPhysicalDeviceFeatures();
    CreateInfo.QueueCreateInfos = &EnginePhysicalDevice.Get()->GetDeviceQueueCreateInfos();

    return CreateTecmaVulkanLogicalDevice(
        *EngineLogicalDevice.Get(), 
        &CreateInfo
    );

}

const VkResult CreateTecmaVulkanCore(
    TecmaVulkanCore& VulkanCore
) {
    VulkanCore.UserData = (TecmaVulkanUserData*)TECMA_MEMORY::TecmaMemoryAllocation(
        sizeof(
            TecmaVulkanUserData
        )
    );

    VkResult Result = VulkanCore.CreateAllocationCallbacks();

    if(
        Result != VK_SUCCESS
    ) return Result;

    Result = VulkanCore.CreateEngineVulkanInstance();

    if(
        Result != VK_SUCCESS
    ) return Result;

    Result = VulkanCore.CreateDebugUtilsMessenger();

    if(
        Result != VK_SUCCESS
    ) return Result;

    Result = VulkanCore.CreateEnginePhysicalDevice();

    if(
        Result != VK_SUCCESS
    ) return Result;

    return VulkanCore.CreateEngineLogicalDevice();

}