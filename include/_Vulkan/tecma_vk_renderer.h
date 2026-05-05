#ifndef __TECMA_VK_RENDERER_H
#define __TECMA_VK_RENDERER_H

#include "tecma_vk_render_pass.h"

#ifndef __TECMA_VK_INSTANCE_H
    #include "tecma_vk_instance.h"
#endif

#ifndef __TECMA_VK_SURFACE_H
    #include "tecma_vk_surface.h"
#endif

#ifndef __TECMA_VK_DEVICE_H
    #include "tecma_vk_device.h"
#endif

#ifndef __TECMA_VK_SWAPCHAIN_H
    #include "tecma_vk_swapchain.h"
#endif

#ifndef __TECMA_VK_IMAGE_H
    #include "tecma_vk_image.h"
#endif

#ifndef __TECMA_VK_COMMAND_RESOURCES_H
    #include "tecma_vk_command_resources.h"
#endif

namespace TecmaEngine {
    struct TecmaVkRenderer_t {
        explicit TecmaVkRenderer_t() noexcept;
        
        explicit TecmaVkRenderer_t(
            TecmaVkRenderer_t& __other
        ) noexcept;
        
        explicit TecmaVkRenderer_t(
            TecmaVkRenderer_t&& __other
        ) noexcept;
        
        ~TecmaVkRenderer_t() noexcept;

        void RenderFrame(
            const unsigned int& __idx
        );

        void CreateRenderer(
            const TecmaVkInstance_t& __inst,
            const TecmaVkDevice_t& __dev,
            TecmaVkSurfaceDependencies_t& __dep
        );

        void DestroyRenderer(
            const VkInstance& __inst,
            const VkDevice& __dev
        );

        private:
            TecmaVkSurface_t __surf;
            TecmaVkSwapchain_t __swchain;
            TecmaVkImage_t __depthResource;
            TecmaVkCommandResources_t __commandResource;
            TecmaVkRenderPass_t __UIRenderPass;
            
            void GetAvailableDevices();

    };

};

#endif
