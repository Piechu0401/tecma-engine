#include "tecma_vulkan.h"

namespace TecmaEngine {
        TecmaVulkan_t::TecmaVulkan_t() noexcept {}

        TecmaVulkan_t::TecmaVulkan_t(
            TecmaVulkan_t& __other
        ) noexcept {}

        TecmaVulkan_t::TecmaVulkan_t(
            TecmaVulkan_t&& __other
        ) noexcept {}

        TecmaVulkan_t::~TecmaVulkan_t() noexcept {}

        void TecmaVulkan_t::CreateVulkan(
            TecmaVkSurfaceDependencies_t& __dep
        ) {
            TecmaVkInstanceLayersSupported();
            TecmaVkInstanceExtensionsSupported();
            
            __instance.CreateVkInstance(
                __TECMA_ENGINE_NAME, 
                __TECMA_ENGINE_VERSION
            );

            __debugUtils.CreateVkDebugUtilsMessenger(
                __instance.__inst
            );

            __device.CreateVkDevice(
                __instance.__inst
            );

            __renderer.CreateRenderer(
                __instance,
                __device,
                __dep
            );

        }

        void TecmaVulkan_t::DestroyVulkan() {
            __renderer.DestroyRenderer(
                __instance.__inst,
                __device.__dev
            );

            __device.DestroyVkDevice();

            __debugUtils.DestroyVkDebugUtilsMessenger(
                __instance.__inst
            );

            __instance.DestroyVkInstance();

        }


}