#ifndef __TECMA_VK_SWAPCHAIN_H 
#define __TECMA_VK_SWAPCHAIN_H

#include "tecma_vk_core.h"

#ifndef __TECMA_VK_IMAGE_H
    #include "tecma_vk_image.h"
#endif

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
        TecmaVkImage_t __swchainImgs;
        std::vector<VkSemaphore> __imgAvalSems;
        std::vector<VkSemaphore> __rendFinSems;
        std::vector<VkFence> __inFlightFens;
        std::vector<VkFence> __inFlightImgs;

        private:

        void CreateSwapchainImages(
            const VkDevice& __dev,
            const VkFormat& __form
        );

        void CreateSynchronizationResources(
            const VkDevice& __dev
        );

    };

};

#endif