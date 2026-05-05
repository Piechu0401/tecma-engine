#ifndef __TECMA_VK_IMAGE_H
#define __TECMA_VK_IMAGE_H

#include "tecma_vk_core.h"

namespace TecmaEngine {
    struct TecmaVkImage_t {
        explicit TecmaVkImage_t() noexcept;
        
        explicit TecmaVkImage_t(
            TecmaVkImage_t& __other
        ) noexcept;
        
        explicit TecmaVkImage_t(
            TecmaVkImage_t&& __other
        ) noexcept;

        void CreateImages(
            const VkDevice& __dev,
            const unsigned int& __imgCount,
            const unsigned int& __memIndex,
            const VkFormat& __form,
            const VkImageAspectFlags& __flags,
            const VkExtent3D& __ext,
            const std::vector<unsigned int> __indices
        );

        void CreateImages(
            const VkDevice& __dev,
            const std::vector<VkImage> __fromImgs,
            const unsigned int& __memIndex,
            const VkFormat& __form,
            const VkImageAspectFlags& __flags
        );
        void DestroyImages(
            const VkDevice& __dev
        );

        std::vector<VkImage> __imgs;
        std::vector<VkDeviceMemory> __imgsMem;
        std::vector<VkImageView> __imgsViews;

        private:
            inline const VkComponentMapping GetDefaultComponentMapping() const noexcept {
                return VkComponentMapping{
                    .r = VK_COMPONENT_SWIZZLE_R,
                    .g = VK_COMPONENT_SWIZZLE_G,
                    .b = VK_COMPONENT_SWIZZLE_B,
                    .a = VK_COMPONENT_SWIZZLE_A,
                };

            }
            
            inline const VkComponentMapping GetIdentityComponentMapping() const noexcept {
                return VkComponentMapping{
                    .r = VK_COMPONENT_SWIZZLE_IDENTITY,
                    .g = VK_COMPONENT_SWIZZLE_IDENTITY,
                    .b = VK_COMPONENT_SWIZZLE_IDENTITY,
                    .a = VK_COMPONENT_SWIZZLE_IDENTITY,
                };

            }

            void CreateVkImages(
                const VkDevice& __dev,
                const unsigned int& __imgCount,
                const VkFormat __form,
                const VkExtent3D& __ext,
                const std::vector<unsigned int> __indices
            );
            void AllocVkImages(
                const VkDevice& __dev,
                const unsigned int& __memIndex
            );
            void CreateVkImagesViews(
                const VkDevice& __dev,
                const VkFormat& __form,
                const VkImageAspectFlags& __flags
            );

    };

};

#endif