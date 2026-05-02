#include "tecma_vk_surface.h"
#include "tecma_vk_core.h"
#include <vulkan/vulkan_core.h>

namespace TecmaEngine {
    TecmaVkSurface_t::TecmaVkSurface_t() noexcept {}
    
    TecmaVkSurface_t::TecmaVkSurface_t(
        const TecmaVkSurface_t& __other
    ) noexcept {}

    TecmaVkSurface_t::TecmaVkSurface_t(
        const TecmaVkSurface_t&& __other
    ) noexcept {}

    TecmaVkSurface_t::~TecmaVkSurface_t() noexcept {}               

    void TecmaVkSurface_t::CreateVkSurface(
        const VkInstance& __inst,
        const VkPhysicalDevice& __physDev,
        TecmaVkSurfaceDependencies_t& __dep
    ) {
        #if defined(__TECMA_XLIB)
            if( !__dep.__dsp ) TecmaLogger( TECMA_ERROR_XLIB_DISPLAY_NULL );
            else if( !__dep.__wnd ) TecmaLogger( TECMA_ERROR_XLIB_WINDOW_ZERO );

            VkXlibSurfaceCreateInfoKHR __info{};

            __info.sType = VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR;
            __info.pNext = nullptr;
            __info.flags = 0;
            __info.dpy = __dep.__dsp;
            __info.window = __dep.__wnd;

            TecmaLogger(
                (TecmaVkResult)vkCreateXlibSurfaceKHR(
                    __inst,
                    &__info,
                    NULL,
                    &__surf
                ),
                VK_FUNCTION_FLAG_VK_CREATE_SURFACE_KHR
            );

        #endif

            GetCapabilities(
                __physDev
            );

            PickVkSurfaceFormat(
                __physDev
            );

            PickVkPresentMode(
                __physDev
            );

            PickSupportedDepthVkFormat(
                __physDev
            );

    }

    void TecmaVkSurface_t::PickSupportedDepthVkFormat(
        const VkPhysicalDevice& __physDev
    ) {
        for( auto& __form : TecmaVkSurfaceDepthFormats ) {
            if(
                TecmaVkFormatSupported(
                    __physDev,
                    __form,
                    VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT,
                    0,
                    0
                )
            ) {
                __depthForm = __form;

                TecmaLogger(
                    VK_ENUM_TYPE_VK_FORMAT,
                    GetVkFormatName( __form )
                );

                return;

            }

            TecmaLogger(
                TECMA_ERROR_VK_FORMAT_DEPTH_NOT_SUITABLE
            );

        }

    }

    void TecmaVkSurface_t::DestroyVkSurface(
        const VkInstance& __inst
    ) const noexcept {
        vkDestroySurfaceKHR(
            __inst,
            __surf,
            NULL
        );

        TecmaLogger(
            VK_SUCCESS,
            VK_FUNCTION_FLAG_VK_DESTROY_SURFACE_KHR
        );

    }

    void TecmaVkSurface_t::GetCapabilities(
        const VkPhysicalDevice& __physDev
    ) {
        TecmaLogger(
            (TecmaVkResult)vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
                __physDev,
                __surf,
                &__surfCapa
            ),
            VK_FUNCTION_FLAG_VK_GET_PHYSICAL_DEVICE_SURFACE_CAPABILITIES_KHR
        );

    }

    void TecmaVkSurface_t::PickVkSurfaceFormat(
        const VkPhysicalDevice& __physDev
    ) {
        unsigned int __count{0};

        TecmaLogger(
            (TecmaVkResult)vkGetPhysicalDeviceSurfaceFormatsKHR(
                __physDev,
                __surf,
                &__count,
                NULL
            ),
            VK_FUNCTION_FLAG_VK_GET_PHYSICAL_DEVICE_SURFACE_FORMATS_KHR
        );

        std::vector<VkSurfaceFormatKHR> __formats(__count);

        TecmaLogger(
            (TecmaVkResult)vkGetPhysicalDeviceSurfaceFormatsKHR(
                __physDev,
                __surf,
                &__count,
                __formats.data()
            ),
            VK_FUNCTION_FLAG_VK_GET_PHYSICAL_DEVICE_SURFACE_FORMATS_KHR
        );

        __surfColorForm = __formats[0];

        bool __col{0};
        
        for( auto& __colForm : TecmaVkSurfaceColorFormats ) {
            for( int __i{0}; __i < __count; ++__i )
                if( __formats[__i].format == __colForm ) {
                    __col = 1;
                    __surfColorForm = __formats[__i];
                    break; 

                }
            
            if( __col ) break;

        }

        if( !__col )
            TecmaLogger(
                TECMA_ERROR_VK_FORMAT_COLOR_NOT_SUITABLE
            );

        TecmaLogger(
            (TecmaVkEnumType)VK_ENUM_TYPE_VK_FORMAT,
            GetVkFormatName( __surfColorForm.format )
        );

        TecmaLogger(
            (TecmaVkEnumType)VK_ENUM_TYPE_VK_COLOR_SPACE,
            GetVkColorSpaceKHR( __surfColorForm.colorSpace )
        );

        // for( auto& __depForm : TecmaVkSurface_tDepthFormats ) {
        //     for( int __i{0}; __i < __count; ++__i ) {
        //         if( __show )
        //             printf(
        //                 "\t%s\n",
        //                 GetVkFormatName(
        //                     __formats[__i].format        
        //                 )
        //             );
        //
        //         if( __formats[__i].format == __depForm ) {
        //             __dep = 1;
        //             __surfDepthForm = __formats[__i];
        //             break; 
        // 
        //         }
        // 
        //     }
        // 
        //     __show = 0;
        //     
        //     if( __dep ) break;
        // 
        // }
        //     
        // 
        // if( !__dep )
        //     TecmaLogger(
        //         TECMA_ERROR_VK_FORMAT_DEPTH_NOT_SUITABLE
        //     );
        // 
        // TecmaLogger(
        //     (TecmaVkEnumType)VK_ENUM_TYPE_VK_FORMAT,
        //     GetVkFormatName( __surfDepthForm.format )
        // );
        // 
        // TecmaLogger(
        //     (TecmaVkEnumType)VK_ENUM_TYPE_VK_COLOR_SPACE,
        //     GetVkColorSpaceKHR( __surfDepthForm.colorSpace )
        // );

    }

    void TecmaVkSurface_t::PickVkPresentMode(
        const VkPhysicalDevice& __physDev
    ) {
        unsigned int __count{};

        TecmaLogger(
            (TecmaVkResult)vkGetPhysicalDeviceSurfacePresentModesKHR(
                __physDev,
                __surf,
                &__count,
                NULL
            ),
            VK_FUNCTION_FLAG_VK_GET_PHYSICAL_DEVICE_SURFACE_PRESENT_MODES_KHR
        );

        std::vector<VkPresentModeKHR> __presModes(__count);

        TecmaLogger(
            (TecmaVkResult)vkGetPhysicalDeviceSurfacePresentModesKHR(
                __physDev,
                __surf,
                &__count,
                __presModes.data()
            ),
            VK_FUNCTION_FLAG_VK_GET_PHYSICAL_DEVICE_SURFACE_PRESENT_MODES_KHR
        );

        bool __found{0};

        for( auto& __pMode : TecmaSurfacePresentModes ) {
            for( int __i{0}; __i < __count; ++__i )
                if( __pMode == __presModes[__i] ) {
                    __found = 1;
                    __presMode = __pMode;
                    break;

                }
            if( __found ) break;

        }

        if( !__found )
            TecmaLogger(
                TECMA_ERROR_VK_PRESENT_MODE_NOT_FOUND 
            );

        TecmaLogger(
            (TecmaVkEnumType)VK_ENUM_TYPE_VK_PRESENT_MODE,
            GetVkPresentModeName( __presMode )
        );

    }

};