#ifndef __TECMA_VK_CORE_H
#define __TECMA_VK_CORE_H

#include "../_Core/tecma_core.h"

#include <vulkan/vulkan.h>

#ifndef __VULKAN_INCLUDED
    #define __VULKAN_INCLUDED
    #if defined(__TECMA_LINUX)
        #if defined(__TECMA_WAYLAND)
            #define VK_INST_EXTENSION_OS_SURFACE_NAME "VK_KHR_wayland_surface"
            #include <wayland-client.h>
            #include <vulkan/vulkan_wayland.h>
        #elif defined(__TECMA_XLIB)
            #define VK_INST_EXTENSION_OS_SURFACE_NAME "VK_KHR_xlib_surface"
            #include <X11/Xlib.h>
            #include <vulkan/vulkan_xlib.h>
        #else
            #define VK_INST_EXTENSION_OS_SURFACE_NAME "No surface"        
        #endif
    #endif
    #elif defined(__WIN32) || defined(__WIN64) 
        #define VK_INST_EXTENSION_OS_SURFACE_NAME "VK_KHR_win32_surface"
    #include <vulkan/vulkan.h>
#endif

#define VK_INST_LAYER_KHR_VALIDATION_NAME "VK_LAYER_KHRONOS_validation"

#define VK_INST_EXTENSION_KHR_SURFACE_NAME "VK_KHR_surface"
#define VK_INST_EXTENSION_DEBUG_UTILS_NAME "VK_EXT_debug_utils"

namespace TecmaEngine {
    constexpr std::array<const char*, 1> TecmaVkInstanceLayerNames = {
        VK_INST_LAYER_KHR_VALIDATION_NAME
    };

    constexpr std::array<const char*, 3> TecmaVkInstanceExtensionNames = {
        VK_INST_EXTENSION_KHR_SURFACE_NAME,
        VK_INST_EXTENSION_OS_SURFACE_NAME,
        VK_INST_EXTENSION_DEBUG_UTILS_NAME
    };

    constexpr std::array<const char*, 1> TecmaVkDeviceLayerNames = {
        VK_INST_LAYER_KHR_VALIDATION_NAME
    };

    constexpr std::array<const char*, 1> TecmaVkDeviceExtensionNames = {
        VK_KHR_SWAPCHAIN_EXTENSION_NAME
    };

    void TecmaVkInstanceLayersSupported();
    void TecmaVkInstanceExtensionsSupported();
    void TecmaVkDeviceLayersSupported(
        const VkPhysicalDevice& __physDev
    );
    void TecmaVkDeviceExtensionsSupported(
        const VkPhysicalDevice& __physDev
    );
    
};

#endif