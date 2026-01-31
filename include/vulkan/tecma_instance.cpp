#include "../vulkan/tecma_instance.h"

namespace TecmaVulkan {
    TecmaInstance::TecmaInstance() noexcept {}

    void TecmaInstance::initTecmaEngineApplicationInfo(
        const char* tecmaApplicationName,
        unsigned int tecmaApplicationVersion
    ) {
        _applicationInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        _applicationInfo.pNext = NULL;
        _applicationInfo.pApplicationName = tecmaApplicationName;
        _applicationInfo.applicationVersion = tecmaApplicationVersion;
        _applicationInfo.apiVersion = VK_API_VERSION_1_4;

    }

    const VkResult TecmaCreateInstance(
        TecmaInstance& Instance,
        const TecmaInstanceCreateInfo* InstanceInfo  
    ) {
        if(
            !Instance.layersAvailable(
                InstanceInfo->_lays,
                InstanceInfo->_layCount
            ) 
        ) return VK_ERROR_LAYER_NOT_PRESENT;
        else if(
            !Instance.extensionsAvailable(
                InstanceInfo->_exts,
                InstanceInfo->_extCount
            )
        ) return VK_ERROR_EXTENSION_NOT_PRESENT;

        Instance.initTecmaEngineApplicationInfo(
            InstanceInfo->_tecmaApplicationName,
            InstanceInfo->_tecmaApplicationVersion
        );

        VkInstanceCreateInfo Info{};

        Info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        Info.pNext = NULL;
        Info.flags = 0;
        Info.enabledExtensionCount = InstanceInfo->_extCount;
        Info.enabledLayerCount = InstanceInfo->_layCount;
        Info.ppEnabledExtensionNames = InstanceInfo->_exts;
        Info.ppEnabledLayerNames = InstanceInfo->_lays;
        Info.pApplicationInfo = &Instance._applicationInfo;

        return vkCreateInstance(
            &Info,
            InstanceInfo->_allocCalls,
            &Instance._instance
        );

    }

    void TecmaDestroyInstance(
        TecmaInstance& Instance,
        const VkAllocationCallbacks& AllocCalls
    ) {
        vkDestroyInstance(
            Instance._instance,
            &AllocCalls
        );

    }

}