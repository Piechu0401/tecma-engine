#include "tecma_vk_descriptor_resources.h"
#include <filesystem>

namespace TecmaEngine {
    TecmaVkDescriptorResources_t::TecmaVkDescriptorResources_t() noexcept {}

    TecmaVkDescriptorResources_t::TecmaVkDescriptorResources_t(
        TecmaVkDescriptorResources_t& __other
    ) noexcept {}

    TecmaVkDescriptorResources_t::TecmaVkDescriptorResources_t(
        TecmaVkDescriptorResources_t&& __other
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

    void TecmaVkDescriptorResources_t::InterpretInstruction(
        const unsigned int* __data,
        int& __idx,
        const unsigned int& __opcode,
        const unsigned int& __count
    ) {
        if( __opcode == TECMA_SPV_OP_ENTRY_POINT ) {
            // 4th index stores entry point literal name
            // so we can decode it and fetch valuable info
            // its not like most of the time its just main, but who cares

            unsigned long __encoded = __data[__idx + 3];
            


        }

        // printf( "opcode: %u count: %u\n", __opcode, __count );
        // for( int __i{0}; __i < __count; ++__i ) {
        //     printf(
        //         "\t%u ",
        //         *(__data + __idx + __i)
        //     );
        // 
        // }
        printf("\n");

    }

    void TecmaVkDescriptorResources_t::CreateVkDescriptorResources(
        const std::string& __shaderPath,
        const std::vector<std::string>& __shaderExts
    ) {

    }

    void TecmaVkDescriptorResources_t::CreateDescriptorPool(
    
    ) {
        
    }

    void TecmaVkDescriptorResources_t::CreateDescriptorSetLayouts(
        
    ) {
    
    }

    void TecmaVkDescriptorResources_t::AllocateDescriptorSets(
    
    ) {
    
    }

};