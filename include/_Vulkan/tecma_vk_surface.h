#ifndef __TECMA_VK_SURFACE_H
#define __TECMA_VK_SURFACE_H

#include "tecma_vk_core.h"

namespace TecmaEngine {
    struct TecmaVkSurface_t {
        explicit TecmaVkSurface_t() noexcept;
        explicit TecmaVkSurface_t(
            const TecmaVkSurface_t& __other
        ) noexcept;
        explicit TecmaVkSurface_t(
            const TecmaVkSurface_t&& __other
        ) noexcept;
        ~TecmaVkSurface_t() noexcept;

        inline const VkExtent3D GetVkExtent3D() const noexcept { 
            return VkExtent3D{ 
                .width = __surfCapa.currentExtent.width,
                .height = __surfCapa.currentExtent.height,
                .depth = 1
            }; 
        
        }
        inline const VkExtent2D& GetVkExtent2D() const noexcept { return __surfCapa.currentExtent; }

        void CreateVkSurface(
            const VkInstance& __inst,
            const VkPhysicalDevice& __physDev,
            TecmaVkSurfaceDependencies_t& __dep
        );

        void DestroyVkSurface(
            const VkInstance& __inst
        ) const noexcept;

        VkSurfaceKHR __surf;
        VkSurfaceCapabilitiesKHR __surfCapa;
        VkSurfaceFormatKHR __surfColorForm;
        VkFormat __depthForm;
        VkPresentModeKHR __presMode;
 
        private:
            void GetCapabilities(
                const VkPhysicalDevice& __physDev
            );

            void PickVkSurfaceFormat(
                const VkPhysicalDevice& __physDev
            );

            void PickVkPresentMode(
                const VkPhysicalDevice& __physDev
            );

            void PickSupportedDepthVkFormat(
                const VkPhysicalDevice& __physDev
            );

    };

};

#endif