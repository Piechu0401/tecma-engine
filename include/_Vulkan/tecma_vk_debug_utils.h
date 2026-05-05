#ifndef __TECMA_VK_DEBUG_UTILS_H
#define __TECMA_VK_DEBUG_UTILS_H

#include "tecma_vk_core.h"

namespace TecmaEngine {
    struct TecmaVkDebugUtils_t {
        explicit TecmaVkDebugUtils_t() noexcept;
        
        explicit TecmaVkDebugUtils_t( 
            TecmaVkDebugUtils_t& __other 
        ) noexcept;
        
        explicit TecmaVkDebugUtils_t( 
            TecmaVkDebugUtils_t&& __other 
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

    };

};

#endif