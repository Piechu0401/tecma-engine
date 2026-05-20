#ifndef __TECMA_VK_DESCRIPTOR_RESOURCES_H
#define __TECMA_VK_DESCRIPTOR_RESOURCES_H

#include "tecma_vk_core.h"

namespace TecmaEngine {
    struct TecmaVkDescriptorResources_t {
        explicit TecmaVkDescriptorResources_t() noexcept;

        explicit TecmaVkDescriptorResources_t(
            TecmaVkDescriptorResources_t& __other
        ) noexcept;

        explicit TecmaVkDescriptorResources_t(
            TecmaVkDescriptorResources_t&& __other
        ) noexcept;

        VkDescriptorPool __descPool;
        std::vector<VkDescriptorSet> __descSets;
        std::vector<VkDescriptorSetLayout> __descSetsLays;
        
        void CreateVkDescriptorResources(
            const std::string& __shaderPath,
            const std::vector<std::string>& __shaderExts
        );

        void DestroyVkDescriptorResources(
            const VkDevice& __dev
        );

        private:
            void CreateDescriptorPool(
            
            );

            void CreateDescriptorSetLayouts(
            
            );

            void AllocateDescriptorSets(
            
            );

            void UpdateDescriptorSets();
            
            void InterpretInstruction(
                const unsigned int* __data,
                int& __idx,
                const unsigned int& __opcode,
                const unsigned int& __count
            );

    };

};

#endif