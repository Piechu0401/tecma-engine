#include "tecma_vk_instance.h"
#include <vulkan/vulkan_core.h>

namespace TecmaEngine {
    TecmaVkInstance_t::TecmaVkInstance_t() noexcept {}
    
    TecmaVkInstance_t::TecmaVkInstance_t(
        TecmaVkInstance_t& __other
    ) noexcept {}
    
    TecmaVkInstance_t::TecmaVkInstance_t(
        TecmaVkInstance_t&& __other
    ) noexcept {}
    
    TecmaVkInstance_t::~TecmaVkInstance_t() noexcept {}

    void TecmaVkInstance_t::CreateVkInstance(
        const char* __appName,
        const unsigned int& __appVersion
    ) {
        __appInfo = CreateApplicationInfo(
            __appName,
            __appVersion    
        );

        VkInstanceCreateInfo __info{
            .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
            .pNext = nullptr,
            .flags = 0,
            .pApplicationInfo = &__appInfo,
            .enabledLayerCount = (unsigned int)(TecmaVkInstanceLayerNames.size()),
            .ppEnabledLayerNames = TecmaVkInstanceLayerNames.data(),
            .enabledExtensionCount = (unsigned int)(TecmaVkInstanceExtensionNames.size()),
            .ppEnabledExtensionNames = TecmaVkInstanceExtensionNames.data()
        
        };

        TecmaLogger(
            (TecmaVkResult)vkCreateInstance(
                &__info,
                NULL,
                &__inst
            ),
            VK_FUNCTION_FLAG_VK_CREATE_INSTANCE
        );

    }

    void TecmaVkInstance_t::DestroyVkInstance() const noexcept {
        vkDestroyInstance(
            __inst,
            NULL
        );

        TecmaLogger(
            VK_SUCCESS,
            VK_FUNCTION_FLAG_VK_DESTROY_INSTANCE
        );

    }

    const VkApplicationInfo TecmaVkInstance_t::CreateApplicationInfo(
        const char* __appName,
        const unsigned int& __appVersion
    ) const noexcept {
        return VkApplicationInfo{
            .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
            .pNext = nullptr,
            .pApplicationName = __appName,
            .applicationVersion = __appVersion,
            .pEngineName = __TECMA_ENGINE_NAME,
            .engineVersion = __TECMA_ENGINE_VERSION
        };

    }

};