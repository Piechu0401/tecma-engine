#include "tecma_vk_renderer.h"
#include <vulkan/vulkan_core.h>

namespace TecmaEngine {
    TecmaVkRenderer_t::TecmaVkRenderer_t() noexcept {}
    
    TecmaVkRenderer_t::TecmaVkRenderer_t(
        const TecmaVkRenderer_t& __other
    ) noexcept {}
    
    TecmaVkRenderer_t::TecmaVkRenderer_t(
        const TecmaVkRenderer_t&& __other
    ) noexcept {}
    
    TecmaVkRenderer_t::~TecmaVkRenderer_t() noexcept {}

    void TecmaVkRenderer_t::RenderFrame(
        const unsigned int& __idx
    ) {
        __UIRenderPass.BeginRenderPass(
            __idx,
            __commandResource.__commBuffs[__idx]
        );

        __commandResource.BeginCommandBuffer(
            __idx, 
            __UIRenderPass.__frameBuffs[__idx], 
            __UIRenderPass.__rendPass
        );

        __commandResource.EndCommandBuffer(
            __idx
        );

        __UIRenderPass.EndRenderPass(
            __commandResource.__commBuffs[__idx]
        );

    }

    void TecmaVkRenderer_t::DestroyRenderer(
        const VkInstance& __inst,
        const VkDevice& __dev
    ) {
        // __UIRenderPass.DestroyVkRenderPass(
        //     __dev
        // );
        
        __depthResource.DestroyImages(
            __dev
        );
        
        __swchain.DestroyVkSwapchain(
            __dev
        );

        __surf.DestroyVkSurface(
            __inst
        );

    }

    void TecmaVkRenderer_t::CreateRenderer(
        const TecmaVkInstance_t& __inst,
        const TecmaVkDevice_t& __dev,
        TecmaVkSurfaceDependencies_t& __dep
    ) {
        __surf.CreateVkSurface(
            __inst.__inst,
            __dev.__physDev,
            __dep
        );

        __swchain.CreateVkSwapchain(
            __dev.__dev, 
            __surf.__surf, 
            __surf.__surfColorForm,
            __surf.__surfCapa, 
            __surf.__presMode,
            __dev.GetFamilyIndices()
        );

        __depthResource.CreateImages(
            __dev.__dev,
            __surf.__surfCapa.minImageCount + 1,
            __dev.FindMemoryIndex( VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT ),
            __surf.__depthForm,
            VK_IMAGE_ASPECT_DEPTH_BIT,
            __surf.GetVkExtent3D(),
            __dev.GetFamilyIndices()
        );

        // __UIRenderPass.CreateVkRenderPass(
        //     __dev.__dev
        // );

    }

};