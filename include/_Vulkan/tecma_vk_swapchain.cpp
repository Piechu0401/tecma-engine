#include "tecma_vk_swapchain.h"

namespace TecmaEngine {
    TecmaVkSwapchain_t::TecmaVkSwapchain_t() noexcept {}
    
    TecmaVkSwapchain_t::TecmaVkSwapchain_t(
        const TecmaVkSwapchain_t& __other
    ) noexcept {}
    
    TecmaVkSwapchain_t::TecmaVkSwapchain_t(
        const TecmaVkSwapchain_t&& __other
    ) noexcept {}
    
    TecmaVkSwapchain_t::~TecmaVkSwapchain_t() noexcept {}
 
    void TecmaVkSwapchain_t::CreateSynchronizationResources(
        const VkDevice& __dev
    ) {
        VkFenceCreateInfo __fInfo{};
        VkSemaphoreCreateInfo __sInfo{};

        __fInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
        __fInfo.pNext = NULL;
        __fInfo.flags = 0;

        __sInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
        __sInfo.pNext = NULL;
        __sInfo.flags = 0;

        for( int __i{0}; __i < __swchainImgs.__imgs.size(); ++__i ) {
            vkCreateSemaphore(
                __dev,
                &__sInfo,
                NULL,
                &__imgAvalSems[__i]
            );

            vkCreateSemaphore(
                __dev,
                &__sInfo,
                NULL,
                &__rendFinSems[__i]
            );

            vkCreateFence(
                __dev,
                &__fInfo,
                NULL,
                &__inFlightFens[__i]
            );

        }

    }

    void TecmaVkSwapchain_t::CreateVkSwapchain(
        const VkDevice& __dev,
        const VkSurfaceKHR& __surf,
        const VkSurfaceFormatKHR& __surfForm,
        const VkSurfaceCapabilitiesKHR& __surfCapa,
        const VkPresentModeKHR& __presMode,
        const std::vector<unsigned int>& __inds
    ) {
        VkSwapchainCreateInfoKHR __info{};

        __info.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
        __info.pNext = NULL;
        __info.flags = 0;
        __info.clipped = __TECMA_FALSE;
        __info.surface = __surf;
        __info.oldSwapchain = VK_NULL_HANDLE;
        __info.presentMode = __presMode;
        __info.pQueueFamilyIndices = __inds.data();
        __info.queueFamilyIndexCount = (unsigned int)(__inds.size());
        __info.compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
        __info.imageUsage = 
            VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;        
        __info.imageSharingMode = VK_SHARING_MODE_CONCURRENT;
        __info.imageArrayLayers = 1;
        __info.minImageCount = __surfCapa.minImageCount + 1;
        __info.imageExtent = __surfCapa.currentExtent;
        __info.preTransform = __surfCapa.currentTransform; 
        __info.imageFormat = __surfForm.format;
        __info.imageColorSpace = __surfForm.colorSpace; 

        TecmaLogger(
            (TecmaVkResult)vkCreateSwapchainKHR(
                __dev,
                &__info,
                NULL,
                &__swchain
            ),
            VK_FUNCTION_FLAG_VK_CREATE_SWAPCHAIN_KHR
        );

        CreateSwapchainImages(
            __dev,
            __info.imageFormat
        );

    }

    void TecmaVkSwapchain_t::CreateSwapchainImages(
        const VkDevice& __dev,
        const VkFormat& __form
    ) {
        unsigned int __count{0};

        TecmaLogger(
            (TecmaVkResult)vkGetSwapchainImagesKHR(
                __dev,
                __swchain,
                &__count,
                NULL
            ),
            VK_FUNCTION_FLAG_VK_GET_SWAPCHAIN_IMAGES_KHR
        );

        __swchainImgs.__imgs.resize( __count );
        __swchainImgs.__imgsViews.resize( __count );

        TecmaLogger(
            (TecmaVkResult)vkGetSwapchainImagesKHR(
                __dev,
                __swchain,
                &__count,
                __swchainImgs.__imgs.data()
            ),
            VK_FUNCTION_FLAG_VK_GET_SWAPCHAIN_IMAGES_KHR
        );

        VkImageViewCreateInfo __info{};

        __info.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
        __info.pNext = NULL;
        __info.flags = 0;
        __info.components.r = VK_COMPONENT_SWIZZLE_R;
        __info.components.g = VK_COMPONENT_SWIZZLE_G;
        __info.components.b = VK_COMPONENT_SWIZZLE_B;
        __info.components.a = VK_COMPONENT_SWIZZLE_A;
        __info.format = __form;
        __info.viewType = VK_IMAGE_VIEW_TYPE_2D;
        __info.subresourceRange.aspectMask =
            VK_IMAGE_ASPECT_COLOR_BIT;
        __info.subresourceRange.baseArrayLayer = 0;
        __info.subresourceRange.baseMipLevel = 0;
        __info.subresourceRange.layerCount = 1;
        __info.subresourceRange.levelCount = 1;

        for( int __i{0}; __i < __count; ++__i ) {
            __info.image = __swchainImgs.__imgs[__i];

            TecmaLogger(
                (TecmaVkResult)vkCreateImageView(
                    __dev,
                    &__info,
                    NULL,
                    &__swchainImgs.__imgsViews[__i]
                ),
                VK_FUNCTION_FLAG_VK_CREATE_IMAGE_VIEW
            );

        }

    }

    void TecmaVkSwapchain_t::RecreateVkSwapchain() {}

    void TecmaVkSwapchain_t::DestroyVkSwapchain(
        const VkDevice& __dev
    ) const noexcept {
        for( auto& __iView : __swchainImgs.__imgsViews ) {
            vkDestroyImageView(
                __dev,
                __iView,    
                NULL
            );

            TecmaLogger(
                VK_SUCCESS,
                VK_FUNCTION_FLAG_VK_DESTROY_IMAGE_VIEW
            );

        }
        
        vkDestroySwapchainKHR(
            __dev,
            __swchain,
            NULL
        );

        TecmaLogger(
            VK_SUCCESS,
            VK_FUNCTION_FLAG_VK_DESTROY_SWAPCHAIN_KHR
        );

    }

};


