#include "tecma_vk_image.h"

namespace TecmaEngine {
    TecmaVkImage_t::TecmaVkImage_t() noexcept {}
    
    TecmaVkImage_t::TecmaVkImage_t(
        const TecmaVkImage_t& __other
    ) noexcept {}
    
    TecmaVkImage_t::TecmaVkImage_t(
        const TecmaVkImage_t&& __other
    ) noexcept {}

    void TecmaVkImage_t::CreateVkImages(
        const VkDevice& __dev,
        const unsigned int& __imgCount,
        const VkFormat __form,
        const VkExtent3D& __ext,
        const std::vector<unsigned int> __indices
    ) {
        VkImageCreateInfo __info{};
        __imgs.resize( __imgCount );

        __info.sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
        __info.pNext = NULL;
        __info.flags = 0;
        __info.format = __form;
        __info.imageType = VK_IMAGE_TYPE_2D;
        __info.arrayLayers = 1;
        __info.usage = 
            VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT;
        __info.initialLayout = 
            VK_IMAGE_LAYOUT_UNDEFINED;
        __info.tiling = 
            VK_IMAGE_TILING_OPTIMAL;
        __info.mipLevels = 1;
        __info.sharingMode = 
            VK_SHARING_MODE_CONCURRENT;
        __info.samples = 
            VK_SAMPLE_COUNT_1_BIT;
        __info.extent = __ext;
        __info.queueFamilyIndexCount = (unsigned int)(__indices.size());
        __info.pQueueFamilyIndices = __indices.data();

        for( int __i{0}; __i < __imgCount; ++__i ) 
            TecmaLogger(
                (TecmaVkResult)vkCreateImage(
                    __dev,
                    &__info,
                    NULL,
                    &__imgs[__i]
                ),
                VK_FUNCTION_FLAG_VK_CREATE_IMAGE
            );

    }

    void TecmaVkImage_t::AllocVkImages(
        const VkDevice& __dev,
        const unsigned int& __memIndex     
    ) {
        VkMemoryAllocateInfo __info{};

        __imgsMem.resize( __imgs.size() );

        __info.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
        __info.pNext = NULL;
        __info.memoryTypeIndex = __memIndex;
    
        for( int __i{0}; __i < __imgs.size(); ++__i ) {
            VkMemoryRequirements __req{};
            
            vkGetImageMemoryRequirements(
                __dev,
                __imgs[__i],
                &__req
            );

            __info.allocationSize = __req.size;
            
            TecmaLogger(
                (TecmaVkResult)vkAllocateMemory(
                    __dev,
                    &__info,
                    NULL,
                    &__imgsMem[__i]
                ),
                VK_FUNCTION_FLAG_VK_ALLOCATE_MEMORY
            );

            TecmaLogger(
                (TecmaVkResult)vkBindImageMemory(
                    __dev,
                    __imgs[__i],
                    __imgsMem[__i],
                    0
                ),
                VK_FUNCTION_FLAG_VK_ALLOCATE_MEMORY
            );

        }

    }

    void TecmaVkImage_t::CreateVkImagesViews(
        const VkDevice& __dev,
        const VkFormat& __form,
        const VkImageAspectFlags& __flags
    ) {
        VkImageViewCreateInfo __info{};

        __imgsViews.resize( __imgs.size() );

        __info.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
        __info.pNext = NULL;
        __info.flags = 0;
        __info.format = __form;
        __info.viewType = VK_IMAGE_VIEW_TYPE_2D;
        __info.subresourceRange.aspectMask = __flags;
        __info.subresourceRange.baseArrayLayer = 0;
        __info.subresourceRange.baseMipLevel= 0;
        __info.subresourceRange.layerCount = 1;
        __info.subresourceRange.levelCount = 1;
        __info.components = GetDefaultComponentMapping();

        for( int __i{0}; __i < __imgs.size(); ++__i ) {
            __info.image = __imgs[__i];
            
            TecmaLogger(
                (TecmaVkResult)vkCreateImageView(
                    __dev,
                    &__info,
                    NULL,
                    &__imgsViews[__i]
                ),
                VK_FUNCTION_FLAG_VK_CREATE_IMAGE_VIEW
            );

        }

    }

    void TecmaVkImage_t::CreateImages(
        const VkDevice& __dev,
        const std::vector<VkImage> __fromImgs,
        const unsigned int& __memIndex,
        const VkFormat& __form,
        const VkImageAspectFlags& __flags
    ) {
        __imgs = __fromImgs;

        AllocVkImages(
            __dev,
            __memIndex
        );

        CreateVkImagesViews(
            __dev,
            __form,
            __flags
        );

    }

    void TecmaVkImage_t::CreateImages(
        const VkDevice& __dev,
        const unsigned int& __imgCount,
        const unsigned int& __memIndex,
        const VkFormat& __form,
        const VkImageAspectFlags& __flags,
        const VkExtent3D& __ext,
        const std::vector<unsigned int> __indices
    ) {
        CreateVkImages(
            __dev,
            __imgCount,
            __form,
            __ext,
            __indices
        );

        AllocVkImages(
            __dev,
            __memIndex
        );

        CreateVkImagesViews(
            __dev,
            __form,
            __flags
        );

    }

    void TecmaVkImage_t::DestroyImages(
        const VkDevice& __dev
    ) {
        for( int __i{0}; __i < __imgs.size(); ++__i ) {
            vkDestroyImageView(
                __dev,
                __imgsViews[__i],
                NULL
            );

            vkFreeMemory(
                __dev,
                __imgsMem[__i],
                NULL
            );

            vkDestroyImage(
                __dev,
                __imgs[__i],
                NULL
            );

        }

    }

};