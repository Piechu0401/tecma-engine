#ifndef __TECMA_VK_DEBUG_UTILS_H
#define __TECMA_VK_DEBUG_UTILS_H

#include "tecma_vk_core.h"
#include <vulkan/vulkan_core.h>

namespace TecmaEngine {
    typedef struct TecmaVkDebugUtils {
        explicit TecmaVkDebugUtils() noexcept;
        explicit TecmaVkDebugUtils( 
            TecmaVkDebugUtils& __other 
        ) noexcept;
        explicit TecmaVkDebugUtils( 
            TecmaVkDebugUtils&& __other 
        ) noexcept;

        void CreateVkDebugUtilsMessenger(
            const VkInstance& __inst
        );
        
        void DestroyVkDebugUtilsMessenger(
            const VkInstance& __inst
        ) const noexcept;

        static VkBool32 VKAPI_PTR TecmaDebugCallback(
            VkDebugUtilsMessageSeverityFlagBitsEXT __messSev,
            VkDebugUtilsMessageTypeFlagsEXT __messTypes,
            const VkDebugUtilsMessengerCallbackDataEXT* __callbackData,
            void* __userData
        );

        VkDebugUtilsMessengerEXT __debugUtils;

    } TecmaVkDebugUtils_t;

};

#endif