#ifndef __TECMA_INSTANCE_H 
#define __TECMA_INSTANCE_H

#ifndef __VULKAN_H
    #define __VULKAN_H
    #include <vulkan/vulkan.h>
    #include <vulkan/vulkan_core.h>
#endif

#include "../core/tecma_core.h"

namespace TecmaVulkan {
    struct TecmaInstance {
        explicit TecmaInstance() noexcept;

        friend const VkResult TecmaCreateInstance(
            TecmaInstance& Instance,
            const TecmaInstanceCreateInfo* InstanceInfo,
            const VkAllocationCallbacks* AllocCalls  
        );

        friend void TecmaDestroyInstance(
            TecmaInstance& Instance,
            const VkAllocationCallbacks* AllocCalls
        );

        private:
            void initTecmaEngineApplicationInfo(
                TecmaText tecmaApplicationName,
                const TecmaU32& tecmaApplicationVersion
            );

            TecmaBool layersAvailable(
                TecmaTexts layerNames,
                const TecmaU32& layerCount    
            );

            TecmaBool extensionsAvailable(
                TecmaTexts extensionNames,
                const TecmaU32& extensionCount    
            );

            VkInstance _instance = VK_NULL_HANDLE;
            VkApplicationInfo _applicationInfo;

    };

    const VkResult TecmaCreateInstance(
        TecmaInstance& Instance,
        const TecmaInstanceCreateInfo* InstanceInfo,
        const VkAllocationCallbacks* AllocCalls  
    );

    void TecmaDestroyInstance(
        TecmaInstance& Instance,
        const VkAllocationCallbacks& AllocCalls
    );

};

#endif