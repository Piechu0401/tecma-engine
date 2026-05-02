#ifndef __TECMA_VK_COMMAND_RESOURCES_H
#define __TECMA_VK_COMMAND_RESOURCES_H

#include "tecma_vk_core.h"
#include <vulkan/vulkan_core.h>

namespace TecmaEngine {
    struct TecmaVkCommandResources_t {
        explicit TecmaVkCommandResources_t() noexcept;

        explicit TecmaVkCommandResources_t(
            const TecmaVkCommandResources_t& __other
        ) noexcept;

        explicit TecmaVkCommandResources_t(
            const TecmaVkCommandResources_t&& __other
        ) noexcept;

        ~TecmaVkCommandResources_t() noexcept;

        void BeginCommandBuffer(
            const unsigned int& __idx,
            const VkFramebuffer& __fb,
            const VkRenderPass& __rp
        );

        void EndCommandBuffer(
            const unsigned int& __idx
        );

        void CreateVkCommandResources();

        void DestroyVkCommandResources();

        VkCommandPool __commPool;
        std::vector<VkCommandBuffer> __commBuffs;

        private:
            
            void CreateCommandPool();

            void AllocateCommandBuffers();

    };

};

#endif