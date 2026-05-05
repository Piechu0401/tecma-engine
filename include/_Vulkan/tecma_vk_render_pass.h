#ifndef __TECMA_VK_RENDER_PASS_H
#define __TECMA_VK_RENDER_PASS_H

#include "tecma_vk_core.h"

namespace TecmaEngine {
    struct TecmaVkRenderPass_t {
        explicit TecmaVkRenderPass_t() noexcept;
        
        explicit TecmaVkRenderPass_t(
            TecmaVkRenderPass_t& __other
        ) noexcept;
        
        explicit TecmaVkRenderPass_t(
            TecmaVkRenderPass_t&& __other
        ) noexcept;
        
        void BeginRenderPass(
            const unsigned int& __idx,
            const VkCommandBuffer& __cb
        );
        
        void EndRenderPass(
            const VkCommandBuffer& __cb
        );

        void CreateVkRenderPass(
            const VkDevice& __dev
        );

        void DestroyVkRenderPass(
            const VkDevice& __dev
        );

        VkRect2D __rendArea;
        VkClearValue __clrVal;
        VkRenderPass __rendPass;
        std::vector<VkFramebuffer> __frameBuffs;

        private:
            void CreateVkFramebuffers(
                const VkDevice& __dev,
                const std::vector<std::vector<VkImageView>>& __views,
                const VkExtent2D& __ext
            );

    };

}

#endif