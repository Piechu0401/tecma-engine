#include "tecma_vk_descriptor_resources.h"

namespace TecmaEngine {
    TecmaVkDescriptorResources_t::TecmaVkDescriptorResources_t() noexcept {}

    TecmaVkDescriptorResources_t::TecmaVkDescriptorResources_t(
        const TecmaVkDescriptorResources_t& __other
    ) noexcept {}

    TecmaVkDescriptorResources_t::TecmaVkDescriptorResources_t(
        const TecmaVkDescriptorResources_t&& __other
    ) noexcept {}

    void TecmaVkDescriptorResources_t::DestroyVkDescriptorResources(
        const VkDevice& __dev
    ) {
        vkFreeDescriptorSets(
            __dev,
            __descPool,
            __descSets.size(),
            __descSets.data()
        );

        TecmaLogger(
            VK_SUCCESS,
            VK_FUNCTION_FLAG_VK_FREE_DESCRIPTOR_SETS
        );

        for( int __i{0}; __i < __descSetsLays.size(); ++__i ) {
            vkDestroyDescriptorSetLayout(
                __dev,
                __descSetsLays[__i],
                NULL
            );
            
            TecmaLogger(
                VK_SUCCESS,
                VK_FUNCTION_FLAG_VK_DESTROY_DESCRIPTOR_SET_LAYOUT
            );

        }

        vkDestroyDescriptorPool(
            __dev,
            __descPool,
            NULL
        );

        TecmaLogger(
            VK_SUCCESS,
            VK_FUNCTION_FLAG_VK_DESTROY_DESCRIPTOR_POOL
        );

    }

    void TecmaVkDescriptorResources_t::CreateVkDescriptorResources(
        const VkDevice& __dev,
        const unsigned int& __descCount,
        const std::vector<VkDescriptorPoolSize>& __descPoolSizes,
        const std::vector<VkDescriptorSetLayoutBinding>& __descBinds
    ) {
        __descSetsLays.resize( __descCount );
        __descSets.resize( __descCount );

        CreateDescriptorPool(
            __dev,
            __descPoolSizes
        );

        CreateDescriptorSetLayouts(
            __dev,
            __descBinds
        );

        AllocateDescriptorSets(
            __dev
        );

    }

    void TecmaVkDescriptorResources_t::CreateDescriptorPool(
        const VkDevice& __dev,
        const std::vector<VkDescriptorPoolSize>& __descPoolSizes
    ) {
        VkDescriptorPoolCreateInfo __info{};

        __info.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
        __info.pNext = NULL;
        __info.flags = VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT;
        __info.poolSizeCount = (unsigned int)(__descPoolSizes.size());
        __info.pPoolSizes = __descPoolSizes.data();
        __info.maxSets = 100;

        TecmaLogger(
            (TecmaVkResult)vkCreateDescriptorPool(
                __dev,
                &__info,
                NULL,
                &__descPool
            ),
            VK_FUNCTION_FLAG_VK_CREATE_DESCRIPTOR_POOL
        );

    }

    void TecmaVkDescriptorResources_t::CreateDescriptorSetLayouts(
        const VkDevice& __dev,
        const std::vector<VkDescriptorSetLayoutBinding>& __descBinds
    ) {
        VkDescriptorSetLayoutCreateInfo __info{};

        __info.sType = 
            VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
        __info.pNext = NULL;
        __info.flags = 0;
        __info.bindingCount = (unsigned int)(__descBinds.size());
        __info.pBindings = __descBinds.data();

        for( int __i{0}; __i < __descSetsLays.size(); ++__i )
            TecmaLogger(
                (TecmaVkResult)vkCreateDescriptorSetLayout(
                    __dev,
                    &__info,
                    NULL,
                    &__descSetsLays[__i]
                ),
                VK_FUNCTION_FLAG_VK_CREATE_DESCRIPTOR_SET_LAYOUT
            );

    }

    void TecmaVkDescriptorResources_t::AllocateDescriptorSets(
        const VkDevice& __dev
    ) {
        VkDescriptorSetAllocateInfo __info{};

        __info.sType =
            VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
        __info.pNext = NULL;
        __info.descriptorPool = __descPool;
        __info.descriptorSetCount = (unsigned int)(__descSets.size());
        __info.pSetLayouts = __descSetsLays.data();

        TecmaLogger(
            (TecmaVkResult)vkAllocateDescriptorSets(
                __dev,
                &__info,
                __descSets.data()
            ),
            VK_FUNCTION_FLAG_VK_ALLOCATE_DESCRIPTOR_SET
        );

    }

};