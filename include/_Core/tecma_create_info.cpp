#include "../_Core/tecma_create_info.hpp"

const VkBool32 ValidAllocationCallbacks(
    const VkAllocationCallbacks& AllocationCallbacks
) {
    return (
        AllocationCallbacks.pUserData == NULL ||
        AllocationCallbacks.pfnAllocation == NULL ||
        AllocationCallbacks.pfnReallocation == NULL ||
        AllocationCallbacks.pfnFree == NULL ||
        AllocationCallbacks.pfnInternalAllocation == NULL ||
        AllocationCallbacks.pfnInternalFree == NULL
    ) ? VK_FALSE : VK_TRUE;

};