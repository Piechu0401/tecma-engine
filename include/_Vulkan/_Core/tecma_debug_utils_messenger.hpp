#ifndef TECMA_DEBUG_UTILS_MESSENGER_HPP 
#define TECMA_DEBUG_UTILS_MESSENGER_HPP

#include "../../_Core/tecma_create_info.hpp"

#define VK_CREATE_DEBUG_UTILS_MESSENGER_FUNCTION_NAME "vkCreateDebugUtilsMessengerEXT"

struct TecmaVulkanDebugUtilsMessenger {
    friend const VkResult CreateTecmaVulkanDebugUtilsMessenger(
        TecmaVulkanDebugUtilsMessenger& DebugUtilsMessenger,
        const TECMA_CREATE_INFO::TecmaVulkanDebugUtilsMessengerCreateInfo* CreateInfo
    );

    private:
        VkDebugUtilsMessengerEXT DebugUtilsMessenger;

};

const VkResult CreateTecmaVulkanDebugUtilsMessenger(
    TecmaVulkanDebugUtilsMessenger& DebugUtilsMessenger,
    const TECMA_CREATE_INFO::TecmaVulkanDebugUtilsMessengerCreateInfo* CreateInfo
);

#endif