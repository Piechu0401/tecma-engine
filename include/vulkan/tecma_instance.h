#ifndef __TECMA_INSTANCE_H 
#define __TECMA_INSTANCE_H

#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>

#include "../core/tecma_core.h"

namespace TecmaVulkan {
    struct TecmaInstanceCreateInfo : TecmaCreateInfo {
        const char* const* _exts;
        unsigned int _extCount;
        const char* const* _lays;
        unsigned int _layCount;
        const char* _tecmaApplicationName;
        unsigned int _tecmaApplicationVersion;
        const VkAllocationCallbacks* _allocCalls;

    };

    struct TecmaInstance {
        explicit TecmaInstance() noexcept;

        friend const VkResult TecmaCreateInstance(
            TecmaInstance& Instance,
            const TecmaInstanceCreateInfo* InstanceInfo  
        );

        friend void TecmaDestroyInstance(
            TecmaInstance& Instance,
            const VkAllocationCallbacks& AllocCalls
        );

        private:
            void initTecmaEngineApplicationInfo(
                const char* tecmaApplicationName,
                unsigned int tecmaApplicationVersion
            );

            VkBool32 layersAvailable(
                const char* const* layerNames,
                const unsigned int& layerCount    
            );

            VkBool32 extensionsAvailable(
                const char* const* extensionNames,
                const unsigned int& extensionCount    
            );

            VkInstance _instance = VK_NULL_HANDLE;
            VkApplicationInfo _applicationInfo;

    };

    const VkResult TecmaCreateInstance(
        TecmaInstance& Instance,
        const TecmaInstanceCreateInfo* InstanceInfo  
    );

    void TecmaDestroyInstance(
        TecmaInstance& Instance,
        const VkAllocationCallbacks& AllocCalls
    );

};

#endif