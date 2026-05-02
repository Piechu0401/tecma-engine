#include "tecma_vk_command_resources.h"
#include <vulkan/vulkan_core.h>

namespace TecmaEngine {
        TecmaVkCommandResources_t::TecmaVkCommandResources_t() noexcept {}

        TecmaVkCommandResources_t::TecmaVkCommandResources_t(
            const TecmaVkCommandResources_t& __other
        ) noexcept {}

        TecmaVkCommandResources_t::TecmaVkCommandResources_t(
            const TecmaVkCommandResources_t&& __other
        ) noexcept {}

        TecmaVkCommandResources_t::~TecmaVkCommandResources_t() noexcept {}

        void TecmaVkCommandResources_t::BeginCommandBuffer(
            const unsigned int& __idx,
            const VkFramebuffer& __fb,
            const VkRenderPass& __rp
        ) {
            VkCommandBufferBeginInfo __cbbi{};
            VkCommandBufferInheritanceInfo __cbii{
                .sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO,
                .pNext = NULL,
                .renderPass = __rp,
                .framebuffer = __fb,
            };

            __cbbi.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
            __cbbi.pNext = NULL;
            __cbbi.flags = 0;
            __cbbi.pInheritanceInfo = &__cbii;

            vkBeginCommandBuffer(
                __commBuffs[__idx],
                &__cbbi
            );

        }

        void TecmaVkCommandResources_t::EndCommandBuffer(
            const unsigned int& __idx
        ) {
            vkEndCommandBuffer(
                __commBuffs[__idx]
            );

        }

        void TecmaVkCommandResources_t::CreateVkCommandResources() {

        }
        
        void TecmaVkCommandResources_t::DestroyVkCommandResources() {

        }
        

};