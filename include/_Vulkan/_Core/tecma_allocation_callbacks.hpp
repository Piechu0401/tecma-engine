#ifndef TECMA_ALLOCATION_CALLBACKS_HPP 
#define TECMA_ALLOCATION_CALLBACKS_HPP

#include "../../_Core/tecma_create_info.hpp"

struct TecmaVulkanAllocationCallbacks {
    const VkAllocationCallbacks& GetAllocationCallbacks() const;

    friend const VkBool32 CreateVulkanAllocationCallbacks(
        TecmaVulkanAllocationCallbacks& AllocationCallbacks,
        const TECMA_CREATE_INFO::TecmaVulkanAllocationCallbacksCreateInfo* CreateInfo
    );

    private:
        VkAllocationCallbacks AllocationCallbacks;

};

const VkBool32 CreateVulkanAllocationCallbacks(
    TecmaVulkanAllocationCallbacks& AllocationCallbacks,
    const TECMA_CREATE_INFO::TecmaVulkanAllocationCallbacksCreateInfo* CreateInfo
);

#endif