#include "tecma_vk_debug_utils.h"
#include <vulkan/vulkan_core.h>

namespace TecmaEngine {
    TecmaVkDebugUtils::TecmaVkDebugUtils() noexcept {}
    
    TecmaVkDebugUtils::TecmaVkDebugUtils( 
        TecmaVkDebugUtils& __other 
    ) noexcept {}
    
    TecmaVkDebugUtils::TecmaVkDebugUtils( 
        TecmaVkDebugUtils&& __other 
    ) noexcept {}

    VkBool32 VKAPI_PTR TecmaVkDebugUtils::TecmaDebugCallback(
        VkDebugUtilsMessageSeverityFlagBitsEXT __messSev,
        VkDebugUtilsMessageTypeFlagsEXT __messTypes,
        const VkDebugUtilsMessengerCallbackDataEXT* __callbackData,
        void* __userData
    ) { return __TECMA_TRUE; }
    
    void TecmaVkDebugUtils::CreateVkDebugUtilsMessenger(
        const VkInstance& __inst
    ) {
        PFN_vkCreateDebugUtilsMessengerEXT CreateDebugUtilsMessenger = 
        (PFN_vkCreateDebugUtilsMessengerEXT)vkGetInstanceProcAddr(
            __inst,
            "vkCreateDebugUtilsMessengerEXT"
        );
        
        VkDebugUtilsMessengerCreateInfoEXT __info;

        __info.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
        __info.pNext = NULL;
        __info.flags = 0;
        __info.messageSeverity = 
            VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT |
            VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT |
            VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
            VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
        __info.messageType = 
            VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT |
            VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT |
            VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
        __info.pfnUserCallback = TecmaDebugCallback;
        __info.pUserData = NULL;

        TecmaLogger(
            (TecmaVkResult)CreateDebugUtilsMessenger(
                __inst,
                &__info,
                NULL,
                &__debugUtils
            ),
            VK_FUNCTION_FLAG_VK_CREATE_DEBUG_UTILS_MESSENGER_EXT
        );

    }

    void TecmaVkDebugUtils::DestroyVkDebugUtilsMessenger(
        const VkInstance& __inst
    ) const noexcept {
        PFN_vkDestroyDebugUtilsMessengerEXT DestroyDebugUtilsMessenger = 
        (PFN_vkDestroyDebugUtilsMessengerEXT)vkGetInstanceProcAddr(
            __inst,
            "vkDestroyDebugUtilsMessengerEXT"
        );
        
        DestroyDebugUtilsMessenger(
            __inst,
            __debugUtils,
            NULL
        );

        TecmaLogger(
            VK_SUCCESS,
            VK_FUNCTION_FLAG_VK_CREATE_DEBUG_UTILS_MESSENGER_EXT
        );

    }

};