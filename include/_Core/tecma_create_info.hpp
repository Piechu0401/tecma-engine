#ifndef TECMA_CREATE_INFO_HPP 
#define TECMA_CREATE_INFO_HPP

#include <cstdint>
#include <stdint.h>
#include <optional>
#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>
#include <X11/Xlib.h>

namespace TECMA_CREATE_INFO {
    const VkBool32 ValidAllocationCallbacks(
        const VkAllocationCallbacks& AllocationCallbacks
    );

    template <typename DataPointerType>
    const VkBool32 ValidArrayData(
        DataPointerType Data,
        const uint32_t& DataSize
    ) {
        return (
            (
                Data == NULL &&
                DataSize > 0
            ) ||
            (
                Data != NULL &&
                DataSize == 0
            ) 
        ) ? VK_FALSE : VK_TRUE;

    }

    struct TecmaVulkanCreateInfo {
        virtual ~TecmaVulkanCreateInfo() = default;
        virtual const VkBool32 ValidCreateInfo() const { return VK_FALSE; };

    };

    struct TecmaWindowCreateInfo {


    };

    struct TecmaVulkanAllocationCallbacksCreateInfo : TecmaVulkanCreateInfo {
        void* UserData;
        void* (*AllocationFunction)(
            void* UserData,
            size_t Size,
            size_t Alignment,
            VkSystemAllocationScope AllocScope
        );
        void* (*ReallocationFunction)(
            void* UserData,
            void* Original,
            size_t Size,
            size_t Alignment,
            VkSystemAllocationScope AllocScope
        );
        void (*FreeFunction)(
            void* UserData,
            void* Memory
        );
        void (*AllocationNotificationFunction)(
            void* UserData,
            size_t Size,
            VkInternalAllocationType AllocType,
            VkSystemAllocationScope AllocScope
        );
        void (*FreeNotificationFunction)(
            void* UserData,
            size_t Size,
            VkInternalAllocationType AllocType,
            VkSystemAllocationScope AllocScope
        );

        const VkBool32 ValidCreateInfo() const override {
            if(
                UserData == NULL ||
                AllocationFunction == NULL ||
                ReallocationFunction == NULL ||
                FreeFunction == NULL ||
                AllocationNotificationFunction == NULL ||
                FreeNotificationFunction == NULL
            ) return VK_FALSE;

            return VK_TRUE;

        };

    };

    struct TecmaVulkanDebugUtilsMessengerCreateInfo : TecmaVulkanCreateInfo {
        const VkInstance* Instance;
        const VkAllocationCallbacks* AllocationCallbacks;
        void* UserData;
        VkBool32 (*UserCallback)(
            VkDebugUtilsMessageSeverityFlagBitsEXT Severity,
            VkDebugUtilsMessageTypeFlagsEXT Types,
            const VkDebugUtilsMessengerCallbackDataEXT* CallbackData,
            void* UserData
        );

        const VkBool32 ValidCreateInfo() const override { 
            if(
                Instance == VK_NULL_HANDLE ||
                !ValidAllocationCallbacks(
                    *AllocationCallbacks
                ) ||
                UserData == NULL ||
                UserCallback == NULL
            ) return VK_FALSE;

            return VK_TRUE; 
        
        };

    };

    struct TecmaVulkanInstanceCreateInfo : TecmaVulkanCreateInfo {
        const VkAllocationCallbacks* AllocationCallbacks;
        const char* const* ExtensionNames;
        const char* const* LayerNames;
        uint32_t ExtensionCount;
        uint32_t LayerCount;
        const VkApplicationInfo* ApplicationInfo; 

        const VkBool32 ValidCreateInfo() const override {
            if(
                AllocationCallbacks == NULL ||
                ApplicationInfo == NULL ||
                !ValidArrayData<const char* const*>(
                    LayerNames,
                    LayerCount
                ) ||
                !ValidArrayData<const char* const*>(
                    ExtensionNames,
                    ExtensionCount
                )
            ) return VK_FALSE;

            return VK_TRUE;

        };

    };

    struct TecmaVulkanSurfaceCreateInfo {
        const VkInstance* Instance;
        const VkAllocationCallbacks* AllocationCallbacks;
        #if defined(__linux__)
            Display* display;
            Window* window;
        #elif defined(__WIN32) || defined(__WIN64)
            HINSTANCE display;
            HWND window;
        #endif

    };

    struct TecmaVulkanPhysicalDeviceCreateInfo : TecmaVulkanCreateInfo {
        const VkInstance* Instance;

    };

    struct TecmaVulkanLogicalDeviceCreateInfo : TecmaVulkanCreateInfo {
        const VkInstance* Instance;
        const VkAllocationCallbacks* AllocationCallbacks;
        const char* const* ExtensionNames;
        const char* const* LayerNames;
        const VkPhysicalDeviceFeatures* PhysicalDeviceFeatures;
        const VkDeviceQueueCreateInfo* QueueCreateInfos;
        uint32_t QueueCreateInfoCount;
        uint32_t ExtensionCount;
        uint32_t LayerCount;

        const VkBool32 ValidCreateInfo() const override {
            if(
                Instance == VK_NULL_HANDLE || 
                PhysicalDeviceFeatures == NULL ||
                !ValidAllocationCallbacks(
                    *AllocationCallbacks
                ) ||
                !ValidArrayData<const char* const*>(
                    LayerNames,
                    LayerCount
                ) ||
                !ValidArrayData<const char* const*>(
                    ExtensionNames,
                    ExtensionCount
                ) ||
                !ValidArrayData<const VkDeviceQueueCreateInfo*>(
                    QueueCreateInfos,
                    QueueCreateInfoCount
                )
            ) return VK_FALSE;

            return VK_TRUE;

        };

    };

};

#endif