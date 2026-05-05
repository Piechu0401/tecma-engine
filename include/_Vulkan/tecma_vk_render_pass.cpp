#include "tecma_vk_render_pass.h"

namespace TecmaEngine {
    TecmaVkRenderPass_t::TecmaVkRenderPass_t() noexcept {}
        
    TecmaVkRenderPass_t::TecmaVkRenderPass_t(
        TecmaVkRenderPass_t& __other
    ) noexcept {}
        
    TecmaVkRenderPass_t::TecmaVkRenderPass_t(
        TecmaVkRenderPass_t&& __other
    ) noexcept {}

    void TecmaVkRenderPass_t::BeginRenderPass(
        const unsigned int& __idx,
        const VkCommandBuffer& __cb
    ) {
        VkRenderPassBeginInfo __rpbi{};

        __rpbi.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
        __rpbi.pNext = NULL;    
        __rpbi.renderPass = __rendPass;
        __rpbi.renderArea = __rendArea;
        __rpbi.framebuffer = __frameBuffs[__idx];
        __rpbi.pClearValues = &__clrVal;
        __rpbi.clearValueCount = 1;

        vkCmdBeginRenderPass(
            __cb,
            &__rpbi,
            VK_SUBPASS_CONTENTS_INLINE
        );

    }
        
    void TecmaVkRenderPass_t::EndRenderPass(
        const VkCommandBuffer& __cb
    ) {
        vkCmdEndRenderPass(
            __cb
        );

    }

    void TecmaVkRenderPass_t::CreateVkRenderPass(
        const VkDevice& __dev
    ) {
        VkRenderPassCreateInfo __info{};

        __info.sType = 
            VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
        __info.pNext = NULL;
        __info.flags = 0;

        TecmaLogger(
            (TecmaVkResult)vkCreateRenderPass(
                __dev,
                &__info,
                NULL,
                &__rendPass
            ),
            VK_FUNCTION_FLAG_VK_CREATE_RENDER_PASS
        );

    }
    
    void TecmaVkRenderPass_t::DestroyVkRenderPass(
        const VkDevice& __dev
    ) {
        for( auto& __fb : __frameBuffs ) {
            vkDestroyFramebuffer(
                __dev,
                __fb,
                NULL
            );
            
            TecmaLogger(
                VK_SUCCESS,
                VK_FUNCTION_FLAG_VK_DESTROY_FRAMEBUFFER
            );

        }

        vkDestroyRenderPass(
            __dev,
            __rendPass,
            NULL
        );

        TecmaLogger(
            VK_SUCCESS,
            VK_FUNCTION_FLAG_VK_DESTROY_RENDER_PASS
        );

    }

    void TecmaVkRenderPass_t::CreateVkFramebuffers(
        const VkDevice& __dev,
        const std::vector<std::vector<VkImageView>>& __views,
        const VkExtent2D& __ext
    ) {
        __frameBuffs.resize( __views[0].size() );

        VkFramebufferCreateInfo __info{};

        __info.sType =
            VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
        __info.pNext = NULL;
        __info.flags = 0;
        __info.layers = 1;
        __info.renderPass = __rendPass;
        __info.width = __ext.width;
        __info.height = __ext.height;
        
        for( int __i{0}; __i < __frameBuffs.size(); ++__i ){
            std::vector<VkImageView> __payload;

            for( auto& __view : __views ) 
                __payload.emplace_back(
                    __view[__i]
                );

            __info.pAttachments = __payload.data();
            __info.attachmentCount = (unsigned int)(__payload.size());

            TecmaLogger(
                (TecmaVkResult)vkCreateFramebuffer(
                    __dev,
                    &__info,
                    NULL,
                    &__frameBuffs[__i]
                ),
                VK_FUNCTION_FLAG_VK_CREATE_FRAMEBUFFER
            );

        }

    }

};