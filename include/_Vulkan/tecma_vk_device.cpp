#include "tecma_vk_device.h"
#include <vulkan/vulkan_core.h>

namespace TecmaEngine {
    TecmaVkDevice_t::TecmaVkDevice_t() noexcept {}
    
    TecmaVkDevice_t::TecmaVkDevice_t(
        TecmaVkDevice_t& __other
    ) noexcept {}

    TecmaVkDevice_t::TecmaVkDevice_t(
        TecmaVkDevice_t&& __other
    ) noexcept {}
    
    TecmaVkDevice_t::~TecmaVkDevice_t() noexcept {}

    const unsigned int TecmaVkDevice_t::FindMemoryIndex(
        const VkMemoryPropertyFlagBits& __memProp
    ) const noexcept {
        for( auto& __prop : __physDevMemProps.memoryTypes )
            if(
                (__prop.propertyFlags & __memProp) == __memProp
            ) return __prop.heapIndex;

        TecmaLogger(
            TECMA_ERROR_VK_MEMORY_PROPERTY_NOT_FOUND
        );

        return -1;

    }

    const std::vector<unsigned int> TecmaVkDevice_t::GetFamilyIndices() const noexcept {
        std::vector<unsigned int> __res( 
            __queueInfos.size()
        );

        for( int __i{0}; __i < __res.size(); ++__i )
            __res[__i] = __i;

        return __res;

    }

    void TecmaVkDevice_t::PickBestAvailableDevice(
        const VkInstance& __inst
    ) {
        unsigned int __count{0};

        TecmaLogger(
            (TecmaVkResult)vkEnumeratePhysicalDevices(
                __inst,
                &__count,
                NULL
            ),
            VK_FUNCTION_FLAG_VK_ENUMERATE_PHYSICAL_DEVICES
        );

        std::vector<VkPhysicalDevice> __physDevs(__count);

        TecmaLogger(
            (TecmaVkResult)vkEnumeratePhysicalDevices(
                __inst,
                &__count,
                __physDevs.data()
            ),
            VK_FUNCTION_FLAG_VK_ENUMERATE_PHYSICAL_DEVICES
        );

        __physDev = __physDevs[0];

        vkGetPhysicalDeviceFeatures(
            __physDev,
            &__physDevFeat
        );

        vkGetPhysicalDeviceProperties(
            __physDev,
            &__physDevProps
        );

        vkGetPhysicalDeviceMemoryProperties(
            __physDev,
            &__physDevMemProps
        );

        TecmaLogger(
            (TecmaVkObjectType)VK_OBJECT_TYPE_PHYSICAL_DEVICE,
            __physDevProps.deviceName
        );

    }
    
    void TecmaVkDevice_t::InitVkDeviceQueueCreateInfos(
        const VkInstance& __inst
    ) {
        unsigned int __count{0};

        vkGetPhysicalDeviceQueueFamilyProperties(
            __physDev,
            &__count,
            NULL
        );

        std::vector<VkQueueFamilyProperties> __props(__count);

        vkGetPhysicalDeviceQueueFamilyProperties(
            __physDev,
            &__count,
            __props.data()
        );

        __queuePriorities.resize( __count );
        __queueInfos.resize( __count );

        for( unsigned int __i{0}; __i < __count; ++__i ) {
            __queuePriorities[__i].resize(
                __props[__i].queueCount
            ); 
            
            for( auto& __qp : __queuePriorities[__i] )
                __qp = 1.0f;

            __queueInfos[__i] = VkDeviceQueueCreateInfo{
                .sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO,
                .pNext = NULL,
                .flags = 0,
                .queueFamilyIndex = __i,
                .queueCount = (unsigned int)(__queuePriorities[__i].size()),
                .pQueuePriorities = __queuePriorities[__i].data()
            
            };

        }

    }

    void TecmaVkDevice_t::CreateVkDevice(
        const VkInstance& __inst
    ) {
        PickBestAvailableDevice( __inst );
        TecmaVkDeviceLayersSupported( __physDev );
        TecmaVkDeviceExtensionsSupported( __physDev );
        InitVkDeviceQueueCreateInfos( __inst );

        VkDeviceCreateInfo __info{};

        __info.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
        __info.pNext = nullptr;
        __info.flags = 0;
        __info.pQueueCreateInfos = __queueInfos.data();
        __info.queueCreateInfoCount = (unsigned int)(__queueInfos.size());
        __info.ppEnabledExtensionNames = TecmaVkDeviceExtensionNames.data();
        __info.ppEnabledLayerNames = TecmaVkDeviceLayerNames.data();
        __info.enabledExtensionCount = (unsigned int)(TecmaVkDeviceExtensionNames.size());
        __info.enabledLayerCount = (unsigned int)(TecmaVkDeviceLayerNames.size());
        __info.pEnabledFeatures = &__physDevFeat;

        TecmaLogger(
            (TecmaVkResult)vkCreateDevice(
                __physDev,
                &__info,
                NULL,
                &__dev
            ),
            VK_FUNCTION_FLAG_VK_CREATE_DEVICE
        );

    }

    void TecmaVkDevice_t::DestroyVkDevice() noexcept {
        vkDestroyDevice(
            __dev,
            NULL
        );

        __queueInfos.clear();
        __queuePriorities.clear();

        TecmaLogger(
            VK_SUCCESS,
            VK_FUNCTION_FLAG_VK_DESTROY_DEVICE
        );

    }

};