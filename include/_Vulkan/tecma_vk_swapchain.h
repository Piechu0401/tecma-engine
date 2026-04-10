#ifndef __TECMA_VK_SWAPCHAIN_H 
#define __TECMA_VK_SWAPCHAIN_H

#include "tecma_vk_core.h"

namespace TecmaEngine {
    struct TecmaVkSwapchain_t {
        explicit TecmaVkSwapchain_t() noexcept;
        explicit TecmaVkSwapchain_t(
            const TecmaVkSwapchain_t& __other
        ) noexcept;
        explicit TecmaVkSwapchain_t(
            const TecmaVkSwapchain_t&& __other
        ) noexcept;
        ~TecmaVkSwapchain_t() noexcept;

        void CreateVkSwapchain(
            const VkDevice& __dev,
            const VkSurfaceKHR& __surf,
            const VkSurfaceFormatKHR& __surfForm,
            const VkSurfaceCapabilitiesKHR& __surfCapa,
            const VkPresentModeKHR& __presMode,
            const std::vector<unsigned int>& __inds
        );
        void RecreateVkSwapchain();
        void DestroyVkSwapchain(
            const VkDevice& __dev
        ) const noexcept;

        VkSwapchainKHR __swchain;
        std::vector<VkImage> __swchainImgs;
        std::vector<VkImageView> __swchainImgsViews;

        private:

        void CreateSwapchainImages(
            const VkDevice& __dev,
            const VkFormat& __form
        );

    };

};

#endif