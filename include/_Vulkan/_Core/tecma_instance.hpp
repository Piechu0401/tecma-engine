#ifndef TECMA_VULKAN_INSTANCE_HPP 
#define TECMA_VULKAN_INSTANCE_HPP

#include "../../_Core/tecma_create_info.hpp"
#include "../../_Core/tecma_memory.hpp"

struct TecmaVulkanInstance {
    friend const VkResult CreateTecmaVulkanInstance(
        TecmaVulkanInstance Instance,
        const TECMA_CREATE_INFO::TecmaVulkanInstanceCreateInfo* CreateInfo  
    );
    
    const VkInstance& GetInstance() const;

    private:

    VkInstance Instance = VK_NULL_HANDLE;

    const VkBool32 InstanceSupportsLayers(
        const char* const* Layers,
        const TecmaUint32& LayersSize
    ) const;
    const VkBool32 InstanceSupportsExtensions(
        const char* const* Extensions,
        const TecmaUint32& ExtensionsSize
    ) const;

};

const VkResult CreateTecmaVulkanInstance(
    TecmaVulkanInstance Instance,
    const TECMA_CREATE_INFO::TecmaVulkanInstanceCreateInfo* CreateInfo  
);

#endif