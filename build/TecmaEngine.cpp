#include "../build/TecmaEngine.hpp"

#define VALIDATION_LAYER_NAME "VK_LAYER_KHRONOS_validation"
#define VK_KHR_XLIB_SURFACE_EXTENSION_NAME "VK_KHR_xlib_surface"

int main() {
    TecmaVulkanInstance Instance;
    TECMA_CREATE_INFO::TecmaVulkanInstanceCreateInfo Info;

    VkApplicationInfo ApplicationInfo{};

    const uint32_t ExtensionsSize = 2;
    const uint32_t LayersSize = 1;
    const char* Layers[] = {
        VALIDATION_LAYER_NAME
    };
    const char* Extensions[] = {
        VK_KHR_SURFACE_EXTENSION_NAME,
        VK_KHR_XLIB_SURFACE_EXTENSION_NAME
    };

    const char* AppName = "AAAA";
    const char* EngName = "BBBB";

    ApplicationInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    ApplicationInfo.pNext = NULL;
    ApplicationInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    ApplicationInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    ApplicationInfo.apiVersion = VK_API_VERSION_1_4;
    ApplicationInfo.pEngineName = EngName;
    ApplicationInfo.pApplicationName = AppName;

    Info.ApplicationInfo = &ApplicationInfo;
    Info.ExtensionNames = Extensions;
    Info.LayerNames = Layers;
    Info.ExtensionCount = ExtensionsSize;
    Info.LayerCount = LayersSize;

    printf(
        "%i\n",
        CreateTecmaVulkanInstance(
            Instance,
            &Info
        )
    );

    return 0;

}