#ifndef __TECMA_VK_DESCRIPTOR_RESOURCES_H
#define __TECMA_VK_DESCRIPTOR_RESOURCES_H

#include "tecma_vk_core.h"

namespace TecmaEngine {
    struct TecmaVkDescriptorResources_t {
        explicit TecmaVkDescriptorResources_t() noexcept;

        explicit TecmaVkDescriptorResources_t(
            const TecmaVkDescriptorResources_t& __other
        ) noexcept;

        explicit TecmaVkDescriptorResources_t(
            const TecmaVkDescriptorResources_t&& __other
        ) noexcept;

        VkDescriptorPool __descPool;
        std::vector<VkDescriptorSet> __descSets;
        std::vector<VkDescriptorSetLayout> __descSetsLays;
        
        void CreateVkDescriptorResources(
            const VkDevice& __dev,
            const unsigned int& __descCount,
            const std::vector<VkDescriptorPoolSize>& __descPoolSizes,
            const std::vector<VkDescriptorSetLayoutBinding>& __descBinds
        );

        void DestroyVkDescriptorResources(
            const VkDevice& __dev
        );

        private:
            void CreateDescriptorPool(
                const VkDevice& __dev,
                const std::vector<VkDescriptorPoolSize>& __descPoolSizes
            );

            void CreateDescriptorSetLayouts(
                const VkDevice& __dev,
                const std::vector<VkDescriptorSetLayoutBinding>& __descBinds
            );

            void AllocateDescriptorSets(
                const VkDevice& __dev
            );

            void UpdateDescriptorSets();

    };

};

#endif