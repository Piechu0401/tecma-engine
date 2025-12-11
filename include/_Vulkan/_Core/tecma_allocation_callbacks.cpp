#include "../_Core/tecma_allocation_callbacks.hpp"
#include <vulkan/vulkan_core.h>

const VkAllocationCallbacks& TecmaVulkanAllocationCallbacks::GetAllocationCallbacks() const { return AllocationCallbacks; }

const VkBool32 CreateVulkanAllocationCallbacks(
    TecmaVulkanAllocationCallbacks& AllocationCallbacks,
    const TECMA_CREATE_INFO::TecmaVulkanAllocationCallbacksCreateInfo* CreateInfo
) {
    if(
        !CreateInfo->ValidCreateInfo()
    ) return VK_FALSE;

    AllocationCallbacks.AllocationCallbacks.pUserData = CreateInfo->UserData;
    AllocationCallbacks.AllocationCallbacks.pfnAllocation = CreateInfo->AllocationFunction;
    AllocationCallbacks.AllocationCallbacks.pfnReallocation = CreateInfo->ReallocationFunction;
    AllocationCallbacks.AllocationCallbacks.pfnFree = CreateInfo->FreeFunction;
    AllocationCallbacks.AllocationCallbacks.pfnInternalAllocation = CreateInfo->AllocationNotificationFunction;
    AllocationCallbacks.AllocationCallbacks.pfnInternalFree = CreateInfo->FreeNotificationFunction;

    return VK_TRUE;

}