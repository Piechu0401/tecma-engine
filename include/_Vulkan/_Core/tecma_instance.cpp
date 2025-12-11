#include "../_Core/tecma_instance.hpp"
#include <cstring>
#include <vulkan/vulkan_core.h>

const VkBool32 TecmaVulkanInstance::InstanceSupportsLayers(
    const char* const* Layers,
    const TecmaUint32& LayersSize
) const {
    TecmaUint32 Count = 0;

    if(
        vkEnumerateInstanceLayerProperties(
            &Count,
            NULL
        ) != VK_SUCCESS
    ) return VK_FALSE;

    VkLayerProperties* Properties = (VkLayerProperties*)TECMA_MEMORY::TecmaMemoryAllocation(
        sizeof(
            VkLayerProperties
        ) * Count
    );

    if(
        vkEnumerateInstanceLayerProperties(
            &Count,
            Properties
        ) != VK_SUCCESS
    ) return VK_FALSE;

    uint32_t AvailableCount = 0;

    for(
        int i = 0; i < Count; i++
    )
        for(
            int j = 0; j < LayersSize; j++
        )
            if(
                strcmp(
                    Properties[i].layerName,
                    Layers[j]
                ) == 0
            ) AvailableCount++;

    return (AvailableCount == LayersSize) ? VK_TRUE : VK_FALSE;

}

const VkBool32 TecmaVulkanInstance::InstanceSupportsExtensions(
    const char* const* Extensions,
    const TecmaUint32& ExtensionsSize
) const {
    TecmaUint32 Count = 0;

    if(
        vkEnumerateInstanceExtensionProperties(
            NULL,
            &Count,
            NULL
        ) != VK_SUCCESS
    ) return VK_FALSE;

    VkExtensionProperties* Properties = (VkExtensionProperties*)TECMA_MEMORY::TecmaMemoryAllocation(
        sizeof(
            VkExtensionProperties
        ) * Count
    );

    if(
        vkEnumerateInstanceExtensionProperties(
            NULL,
            &Count,
            Properties
        ) != VK_SUCCESS
    ) return VK_FALSE;

    TecmaUint32 AvailableCount = 0;

    for(
        int i = 0; i < Count; i++
    ) 
        for(
            int j = 0; j < ExtensionsSize; j++
        )
            if(
                strcmp(
                    Properties[i].extensionName,
                    Extensions[j]
                ) == 0
            ) AvailableCount++;

    return (AvailableCount == ExtensionsSize) ? VK_TRUE : VK_FALSE;

}

const VkResult CreateTecmaVulkanInstance(
    TecmaVulkanInstance Instance,
    const TECMA_CREATE_INFO::TecmaVulkanInstanceCreateInfo* CreateInfo  
) {
    if(
        !CreateInfo->ValidCreateInfo()
    ) return VK_ERROR_INITIALIZATION_FAILED;
    else if(
        !Instance.InstanceSupportsExtensions(
            CreateInfo->ExtensionNames,
            CreateInfo->ExtensionCount
        )
    ) return VK_ERROR_EXTENSION_NOT_PRESENT;
    else if(
        !Instance.InstanceSupportsLayers(
            CreateInfo->LayerNames,
            CreateInfo->LayerCount
        )
    ) return VK_ERROR_LAYER_NOT_PRESENT;

    VkInstanceCreateInfo Info{};

    Info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    Info.pNext = NULL;
    Info.flags = 0;
    Info.pApplicationInfo = CreateInfo->ApplicationInfo;
    Info.ppEnabledExtensionNames = CreateInfo->ExtensionNames;
    Info.ppEnabledLayerNames = CreateInfo->LayerNames;
    Info.enabledExtensionCount = CreateInfo->ExtensionCount;
    Info.enabledLayerCount = CreateInfo->LayerCount;

    return vkCreateInstance(
        &Info,
        CreateInfo->AllocationCallbacks,
        &Instance.Instance
    );

}