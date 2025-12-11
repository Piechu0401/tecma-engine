#include "../_Core/tecma_debug_utils_messenger.hpp"

const VkResult CreateTecmaVulkanDebugUtilsMessenger(
    TecmaVulkanDebugUtilsMessenger& DebugUtilsMessenger,
    const TECMA_CREATE_INFO::TecmaVulkanDebugUtilsMessengerCreateInfo* CreateInfo
) {
    VkDebugUtilsMessengerCreateInfoEXT Info{};

    Info.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
    Info.pNext = NULL;
    Info.flags = 0;
    Info.messageType = 
        VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT |
        VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT |
        VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
    Info.messageSeverity = 
        VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT |
        VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT |
        VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
        VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
    Info.pUserData = CreateInfo->UserData;
    Info.pfnUserCallback = CreateInfo->UserCallback;

    PFN_vkCreateDebugUtilsMessengerEXT CreateDebugUtilsMessenger = (
        PFN_vkCreateDebugUtilsMessengerEXT
    ) vkGetInstanceProcAddr(
        *CreateInfo->Instance,
        VK_CREATE_DEBUG_UTILS_MESSENGER_FUNCTION_NAME
    );

    return CreateDebugUtilsMessenger(
        *CreateInfo->Instance,
        &Info,
        CreateInfo->AllocationCallbacks,
        &DebugUtilsMessenger.DebugUtilsMessenger
    );

}