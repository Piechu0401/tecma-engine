#include "tecma_vk_core.h"

namespace TecmaEngine {
    void TecmaVkInstanceLayersSupported() {
        unsigned int __count{0};
        unsigned char __supported{0};

        TecmaLogger(
            (TecmaVkResult)vkEnumerateInstanceLayerProperties(
                &__count,
                NULL
            ),
            VK_FUNCTION_FLAG_VK_ENUMERATE_INSTANCE_LAYER_PROPERTIES
        );

        VkLayerProperties __props[__count];

        TecmaLogger(
            (TecmaVkResult)vkEnumerateInstanceLayerProperties(
                &__count,
                __props
            ),
            VK_FUNCTION_FLAG_VK_ENUMERATE_INSTANCE_LAYER_PROPERTIES
        );

        int __i{0};
        bool __present{0};
        std::vector<const char*> __absent;
        std::vector<const char*> __available;

        while( __supported < TecmaVkInstanceLayerNames.size() ) {
            if(
                !strcmp(
                    TecmaVkInstanceLayerNames[__supported],
                    __props[__i].layerName
                )
            ) __present = 1;

            if( __available.size() < __count ) __available.emplace_back(__props[__i].layerName);

            ++__i;

            if( __i == __count ) {
                if( !__present ) 
                    __absent.emplace_back(
                        TecmaVkInstanceLayerNames[__supported]
                    );

                __i = 0;
                __present = 0;
                ++__supported;

            }

        }

        #if defined(__TECMA_INFO)
            TecmaLogger(
                TECMA_INFO_AVAILABLE_VK_INSTANCE_LAY,
                __available
            );
        #endif
            
        if( __absent.size() )
            TecmaLogger(
                TECMA_ERROR_VK_INSTANCE_MISSING_LAY,
                __absent
            );

    }
    void TecmaVkInstanceExtensionsSupported() {
        unsigned int __count{0};
        unsigned char __supported{0};

        TecmaLogger(
            (TecmaVkResult)vkEnumerateInstanceExtensionProperties(
                NULL,
                &__count,
                NULL
            ),
            VK_FUNCTION_FLAG_VK_ENUMERATE_INSTANCE_EXTENSION_PROPERTIES
        );

        VkExtensionProperties __props[__count];

        TecmaLogger(
            (TecmaVkResult)vkEnumerateInstanceExtensionProperties(
                NULL,
                &__count,
                __props
            ),
            VK_FUNCTION_FLAG_VK_ENUMERATE_INSTANCE_EXTENSION_PROPERTIES
        );

        int __i{0};
        bool __present{0};
        std::vector<const char*> __absent;
        std::vector<const char*> __available;

        while( __supported < TecmaVkInstanceExtensionNames.size() ) {
            if(
                !strcmp(
                    TecmaVkInstanceExtensionNames[__supported],
                    __props[__i].extensionName
                )
            ) __present = 1;

            if( __available.size() < __count ) __available.emplace_back(__props[__i].extensionName);

            ++__i;

            if( __i == __count ) {
                if( !__present ) 
                    __absent.emplace_back(
                        TecmaVkInstanceExtensionNames[__supported]
                    );

                __i = 0;
                __present = 0;
                ++__supported;

            }

        }

        #if defined(__TECMA_INFO)
            TecmaLogger(
                TECMA_INFO_AVAILABLE_VK_INSTANCE_EXT,
                __available
            );
        #endif
            
        if( __absent.size() ) {
            TecmaLogger(
                TECMA_ERROR_VK_INSTANCE_MISSING_EXT,
                __absent
            );

        }

    }

    void TecmaVkDeviceLayersSupported(
        const VkPhysicalDevice& __physDev 
    ) {
        unsigned int __count{0};
        unsigned char __supported{0};

        TecmaLogger(
            (TecmaVkResult)vkEnumerateDeviceLayerProperties(
                __physDev,
                &__count,
                NULL
            ),
            VK_FUNCTION_FLAG_VK_ENUMERATE_DEVICE_LAYER_PROPERTIES
        );

        VkLayerProperties __props[__count];

        TecmaLogger(
            (TecmaVkResult)vkEnumerateDeviceLayerProperties(
                __physDev,
                &__count,
                __props
            ),
            VK_FUNCTION_FLAG_VK_ENUMERATE_DEVICE_LAYER_PROPERTIES
        );

        int __i{0};
        bool __present{0};
        std::vector<const char*> __absent;
        std::vector<const char*> __available;

        while( __supported < TecmaVkDeviceLayerNames.size() ) {
            if(
                !strcmp(
                    TecmaVkDeviceLayerNames[__supported],
                    __props[__i].layerName
                )
            ) __present = 1;

            if( __available.size() < __count ) __available.emplace_back(__props[__i].layerName);

            ++__i;

            if( __i == __count ) {
                if( !__present ) 
                    __absent.emplace_back(
                        TecmaVkDeviceLayerNames[__supported]
                    );

                __i = 0;
                __present = 0;
                ++__supported;

            }

        }

        #if defined(__TECMA_INFO)
            TecmaLogger(
                TECMA_INFO_AVAILABLE_VK_DEVICE_LAY,
                __available
            );
        #endif
            
        if( __absent.size() )
            TecmaLogger(
                TECMA_ERROR_VK_DEVICE_MISSING_LAY,
                __absent
            );

    }

    void TecmaVkDeviceExtensionsSupported(
        const VkPhysicalDevice& __physDev
    ) {
        unsigned int __count{0};
        unsigned char __supported{0};

        TecmaLogger(
            (TecmaVkResult)vkEnumerateDeviceExtensionProperties(
                __physDev,
                NULL,
                &__count,
                NULL
            ),
            VK_FUNCTION_FLAG_VK_ENUMERATE_DEVICE_EXTENSION_PROPERTIES
        );

        VkExtensionProperties __props[__count];

        TecmaLogger(
            (TecmaVkResult)vkEnumerateDeviceExtensionProperties(
                __physDev,
                NULL,
                &__count,
                __props
            ),
            VK_FUNCTION_FLAG_VK_ENUMERATE_DEVICE_EXTENSION_PROPERTIES
        );

        int __i{0};
        bool __present{0};
        std::vector<const char*> __absent;
        std::vector<const char*> __available;

        while( __supported < TecmaVkDeviceExtensionNames.size() ) {
            if(
                !strcmp(
                    TecmaVkDeviceExtensionNames[__supported],
                    __props[__i].extensionName
                )
            ) __present = 1;

            if( __available.size() < __count ) __available.emplace_back(__props[__i].extensionName);

            ++__i;

            if( __i == __count ) {
                if( !__present ) 
                    __absent.emplace_back(
                        TecmaVkDeviceExtensionNames[__supported]
                    );

                __i = 0;
                __present = 0;
                ++__supported;

            }

        }

        #if defined(__TECMA_INFO)
            TecmaLogger(
                TECMA_INFO_AVAILABLE_VK_DEVICE_EXT,
                __available
            );
        #endif
            
        if( __absent.size() ) {
            TecmaLogger(
                TECMA_ERROR_VK_DEVICE_MISSING_EXT,
                __absent
            );

        }

    }

};