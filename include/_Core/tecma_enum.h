#ifndef __TECMA_ENUM_H
#define __TECMA_ENUM_H

namespace TecmaEngine {
    enum TecmaInfoFlag {
        TECMA_INFO_AVAILABLE_VK_INSTANCE_EXT = 0,
        TECMA_INFO_AVAILABLE_VK_INSTANCE_LAY = 1,
        TECMA_INFO_AVAILABLE_VK_DEVICE_EXT = 2,
        TECMA_INFO_AVAILABLE_VK_DEVICE_LAY = 3,
        TECMA_INFO_AVAILABLE_VK_PHYSICAL_DEVICES = 4,

    };
    
    enum TecmaErrorFlag {
        TECMA_ERROR_VK_INSTANCE_MISSING_EXT = 0,
        TECMA_ERROR_VK_INSTANCE_MISSING_LAY = 1,
        TECMA_ERROR_VK_DEVICE_MISSING_EXT = 2,
        TECMA_ERROR_VK_DEVICE_MISSING_LAY = 3,
        #if defined(__TECMA_XLIB)
            TECMA_ERROR_XLIB_DISPLAY_NULL = 4,
            TECMA_ERROR_XLIB_WINDOW_ZERO = 5,
            TECMA_ERROR_XLIB_DISPLAY_FAILED = 6,
            TECMA_ERROR_XLIB_WINDOW_FAILED = 7,
        #endif
        TECMA_ERROR_VK_FORMAT_DEPTH_NOT_SUITABLE = 8,
        TECMA_ERROR_VK_FORMAT_COLOR_NOT_SUITABLE = 9,
        TECMA_ERROR_VK_PRESENT_MODE_NOT_FOUND = 10,
        TECMA_ERROR_VK_MEMORY_PROPERTY_NOT_FOUND = 11,
    
    };

    enum TecmaVkResult {
        VK_SUCCESS = 0,
        VK_NOT_READY = 1,
        VK_TIMEOUT = 2,
        VK_EVENT_SET = 3,
        VK_EVENT_RESET = 4,
        VK_INCOMPLETE = 5,
        VK_ERROR_OUT_OF_HOST_MEMORY = -1,
        VK_ERROR_OUT_OF_DEVICE_MEMORY = -2,
        VK_ERROR_INITIALIZATION_FAILED = -3,
        VK_ERROR_DEVICE_LOST = -4,
        VK_ERROR_MEMORY_MAP_FAILED = -5,
        VK_ERROR_LAYER_NOT_PRESENT = -6,
        VK_ERROR_EXTENSION_NOT_PRESENT = -7,
        VK_ERROR_FEATURE_NOT_PRESENT = -8,
        VK_ERROR_INCOMPATIBLE_DRIVER = -9,
        VK_ERROR_TOO_MANY_OBJECTS = -10,
        VK_ERROR_FORMAT_NOT_SUPPORTED = -11,
        VK_ERROR_FRAGMENTED_POOL = -12,
        VK_ERROR_UNKNOWN = -13,
        VK_ERROR_VALIDATION_FAILED = -1000011001,
        VK_ERROR_OUT_OF_POOL_MEMORY = -1000069000,
        VK_ERROR_INVALID_EXTERNAL_HANDLE = -1000072003,
        VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS = -1000257000,
        VK_ERROR_FRAGMENTATION = -1000161000,
        VK_PIPELINE_COMPILE_REQUIRED = 1000297000,
        VK_ERROR_NOT_PERMITTED = -1000174001,
        VK_ERROR_SURFACE_LOST_KHR = -1000000000,
        VK_ERROR_NATIVE_WINDOW_IN_USE_KHR = -1000000001,
        VK_SUBOPTIMAL_KHR = 1000001003,
        VK_ERROR_OUT_OF_DATE_KHR = -1000001004,
        VK_ERROR_INCOMPATIBLE_DISPLAY_KHR = -1000003001,
        VK_ERROR_INVALID_SHADER_NV = -1000012000,
        VK_ERROR_IMAGE_USAGE_NOT_SUPPORTED_KHR = -1000023000,
        VK_ERROR_VIDEO_PICTURE_LAYOUT_NOT_SUPPORTED_KHR = -1000023001,
        VK_ERROR_VIDEO_PROFILE_OPERATION_NOT_SUPPORTED_KHR = -1000023002,
        VK_ERROR_VIDEO_PROFILE_FORMAT_NOT_SUPPORTED_KHR = -1000023003,
        VK_ERROR_VIDEO_PROFILE_CODEC_NOT_SUPPORTED_KHR = -1000023004,
        VK_ERROR_VIDEO_STD_VERSION_NOT_SUPPORTED_KHR = -1000023005,
        VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT = -1000158000,
        VK_ERROR_PRESENT_TIMING_QUEUE_FULL_EXT = -1000208000,
        VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT = -1000255000,
        VK_THREAD_IDLE_KHR = 1000268000,
        VK_THREAD_DONE_KHR = 1000268001,
        VK_OPERATION_DEFERRED_KHR = 1000268002,
        VK_OPERATION_NOT_DEFERRED_KHR = 1000268003,
        VK_ERROR_INVALID_VIDEO_STD_PARAMETERS_KHR = -1000299000,
        VK_ERROR_COMPRESSION_EXHAUSTED_EXT = -1000338000,
        VK_INCOMPATIBLE_SHADER_BINARY_EXT = 1000482000,
        VK_PIPELINE_BINARY_MISSING_KHR = 1000483000,
        VK_ERROR_NOT_ENOUGH_SPACE_KHR = -1000483000,

    };

    enum TecmaVkEnumType {
        VK_ENUM_TYPE_VK_PRESENT_MODE = 0,
        VK_ENUM_TYPE_VK_FORMAT = 1,
        VK_ENUM_TYPE_VK_COLOR_SPACE = 2,

    };

    enum TecmaVkObjectType {
        VK_OBJECT_TYPE_UNKNOWN = 0,
        VK_OBJECT_TYPE_INSTANCE = 1,
        VK_OBJECT_TYPE_PHYSICAL_DEVICE = 2,
        VK_OBJECT_TYPE_DEVICE = 3,
        VK_OBJECT_TYPE_QUEUE = 4,
        VK_OBJECT_TYPE_SEMAPHORE = 5,
        VK_OBJECT_TYPE_COMMAND_BUFFER = 6,
        VK_OBJECT_TYPE_FENCE = 7,
        VK_OBJECT_TYPE_DEVICE_MEMORY = 8,
        VK_OBJECT_TYPE_BUFFER = 9,
        VK_OBJECT_TYPE_IMAGE = 10,
        VK_OBJECT_TYPE_EVENT = 11,
        VK_OBJECT_TYPE_QUERY_POOL = 12,
        VK_OBJECT_TYPE_BUFFER_VIEW = 13,
        VK_OBJECT_TYPE_IMAGE_VIEW = 14,
        VK_OBJECT_TYPE_SHADER_MODULE = 15,
        VK_OBJECT_TYPE_PIPELINE_CACHE = 16,
        VK_OBJECT_TYPE_PIPELINE_LAYOUT = 17,
        VK_OBJECT_TYPE_RENDER_PASS = 18,
        VK_OBJECT_TYPE_PIPELINE = 19,
        VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT = 20,
        VK_OBJECT_TYPE_SAMPLER = 21,
        VK_OBJECT_TYPE_DESCRIPTOR_POOL = 22,
        VK_OBJECT_TYPE_DESCRIPTOR_SET = 23,
        VK_OBJECT_TYPE_FRAMEBUFFER = 24,
        VK_OBJECT_TYPE_COMMAND_POOL = 25,
        VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE = 1000085000,
        VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION = 1000156000,
        VK_OBJECT_TYPE_PRIVATE_DATA_SLOT = 1000295000,
        VK_OBJECT_TYPE_SURFACE_KHR = 1000000000,
        VK_OBJECT_TYPE_SWAPCHAIN_KHR = 1000001000,
        VK_OBJECT_TYPE_DISPLAY_KHR = 1000002000,
        VK_OBJECT_TYPE_DISPLAY_MODE_KHR = 1000002001,
        VK_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT = 1000011000,
        VK_OBJECT_TYPE_VIDEO_SESSION_KHR = 1000023000,
        VK_OBJECT_TYPE_VIDEO_SESSION_PARAMETERS_KHR = 1000023001,
        VK_OBJECT_TYPE_CU_MODULE_NVX = 1000029000,
        VK_OBJECT_TYPE_CU_FUNCTION_NVX = 1000029001,
        VK_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT = 1000128000,
        VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR = 1000150000,
        VK_OBJECT_TYPE_VALIDATION_CACHE_EXT = 1000160000,
        VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV = 1000165000,
        VK_OBJECT_TYPE_PERFORMANCE_CONFIGURATION_INTEL = 1000210000,
        VK_OBJECT_TYPE_DEFERRED_OPERATION_KHR = 1000268000,
        VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_NV = 1000277000,
        #ifdef VK_ENABLE_BETA_EXTENSIONS
            VK_OBJECT_TYPE_CUDA_MODULE_NV = 1000307000,
        #endif
        #ifdef VK_ENABLE_BETA_EXTENSIONS
            VK_OBJECT_TYPE_CUDA_FUNCTION_NV = 1000307001,
        #endif
        VK_OBJECT_TYPE_BUFFER_COLLECTION_FUCHSIA = 1000366000,
        VK_OBJECT_TYPE_MICROMAP_EXT = 1000396000,
        VK_OBJECT_TYPE_TENSOR_ARM = 1000460000,
        VK_OBJECT_TYPE_TENSOR_VIEW_ARM = 1000460001,
        VK_OBJECT_TYPE_OPTICAL_FLOW_SESSION_NV = 1000464000,
        VK_OBJECT_TYPE_SHADER_EXT = 1000482000,
        VK_OBJECT_TYPE_PIPELINE_BINARY_KHR = 1000483000,
        VK_OBJECT_TYPE_DATA_GRAPH_PIPELINE_SESSION_ARM = 1000507000,
        VK_OBJECT_TYPE_EXTERNAL_COMPUTE_QUEUE_NV = 1000556000,
        VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_EXT = 1000572000,
        VK_OBJECT_TYPE_INDIRECT_EXECUTION_SET_EXT = 1000572001,
        VK_OBJECT_TYPE_SHADER_INSTRUMENTATION_ARM = 1000607000,

    };

    enum TecmaVkFunctionFlag {
        VK_FUNCTION_FLAG_VK_DESTROY_IMAGE_VIEW = -6,
        VK_FUNCTION_FLAG_VK_DESTROY_SWAPCHAIN_KHR = -5,
        VK_FUNCTION_FLAG_VK_DESTROY_DEVICE = -4,
        VK_FUNCTION_FLAG_VK_DESTROY_SURFACE_KHR = -3,
        VK_FUNCTION_FLAG_VK_DESTROY_DEBUG_UTILS_MESSENGER_EXT = -2,
        VK_FUNCTION_FLAG_VK_DESTROY_INSTANCE = -1,
        VK_FUNCTION_FLAG_VK_CREATE_INSTANCE = 0,
        VK_FUNCTION_FLAG_VK_CREATE_DEBUG_UTILS_MESSENGER_EXT = 1,
        VK_FUNCTION_FLAG_VK_CREATE_SURFACE_KHR = 2,
        VK_FUNCTION_FLAG_VK_CREATE_DEVICE = 3,
        VK_FUNCTION_FLAG_VK_CREATE_SWAPCHAIN_KHR = 4,
        VK_FUNCTION_FLAG_VK_ENUMERATE_INSTANCE_LAYER_PROPERTIES = 5,
        VK_FUNCTION_FLAG_VK_ENUMERATE_INSTANCE_EXTENSION_PROPERTIES = 6,
        VK_FUNCTION_FLAG_VK_ENUMERATE_DEVICE_LAYER_PROPERTIES = 7,
        VK_FUNCTION_FLAG_VK_ENUMERATE_DEVICE_EXTENSION_PROPERTIES = 8,
        VK_FUNCTION_FLAG_VK_ENUMERATE_PHYSICAL_DEVICES = 9,
        VK_FUNCTION_FLAG_VK_GET_PHYSICAL_DEVICE_SURFACE_CAPABILITIES_KHR = 10,
        VK_FUNCTION_FLAG_VK_GET_PHYSICAL_DEVICE_SURFACE_FORMATS_KHR = 11,
        VK_FUNCTION_FLAG_VK_GET_PHYSICAL_DEVICE_SURFACE_PRESENT_MODES_KHR = 12,
        VK_FUNCTION_FLAG_VK_GET_SWAPCHAIN_IMAGES_KHR = 13,
        VK_FUNCTION_FLAG_VK_CREATE_IMAGE_VIEW = 14,
        VK_FUNCTION_FLAG_VK_CREATE_IMAGE = 15,

    };

    inline static const char* GetTecmaInfoFlagMessage(
        const TecmaInfoFlag& __infoFlag
    ) {
        switch( __infoFlag ) {
            case TECMA_INFO_AVAILABLE_VK_INSTANCE_EXT: return "VkInstance available extensions:\n";
            case TECMA_INFO_AVAILABLE_VK_INSTANCE_LAY: return "VkInstance available layers:\n";
            case TECMA_INFO_AVAILABLE_VK_DEVICE_EXT: return "VkDevice available extensions:\n";
            case TECMA_INFO_AVAILABLE_VK_DEVICE_LAY: return "VkDevice available layers:\n";;
            case TECMA_INFO_AVAILABLE_VK_PHYSICAL_DEVICES: return "VkPhysicalDevice available devices:\n";
            default: return "Info unknown";

        }

    }

    inline static const char* GetTecmaErrorFlagMessage(
        const TecmaErrorFlag& __errorFlag
    ) {
        switch( __errorFlag ) {
            case TECMA_ERROR_VK_INSTANCE_MISSING_EXT: return "VkInstance requires these specified extensions:\n";
            case TECMA_ERROR_VK_INSTANCE_MISSING_LAY: return "VkInstance requires these specified layers:\n";
            case TECMA_ERROR_VK_DEVICE_MISSING_EXT: return "VkDevice requires these specified extensions:\n";
            case TECMA_ERROR_VK_DEVICE_MISSING_LAY: return "VkDevice requires these specified layers:\n";
            #if defined( __TECMA_XLIB )
                case TECMA_ERROR_XLIB_DISPLAY_NULL: return "Given value of Display is set to NULL!\n";
                case TECMA_ERROR_XLIB_WINDOW_ZERO: return "Given value of Window is set to zero!\n";
                case TECMA_ERROR_XLIB_DISPLAY_FAILED: return "XOpenDisplay() resulted in Display = NULL!\n";
                case TECMA_ERROR_XLIB_WINDOW_FAILED: return "XCreateWindow() resulted in Window = 0!\n";
            #endif
            case TECMA_ERROR_VK_FORMAT_DEPTH_NOT_SUITABLE: return "Tecma Engine could not find any suitable depth VkFormat!\n";
            case TECMA_ERROR_VK_FORMAT_COLOR_NOT_SUITABLE: return "Tecma Engine could not find any suitable color VkFormat!\n";
            case TECMA_ERROR_VK_PRESENT_MODE_NOT_FOUND: return "Tecma Engine could not find any VkPresentModeKHR!\n";
            case TECMA_ERROR_VK_MEMORY_PROPERTY_NOT_FOUND: return "Tecma Engine could not find any suitable memory index!\n";
            default: return "Error unknown";

        }

    }

    inline static const char* GetTecmaVkFunctionFlagName(
        const TecmaVkFunctionFlag& __funcType
    ) noexcept {
        switch( __funcType ) {
            case VK_FUNCTION_FLAG_VK_DESTROY_IMAGE_VIEW: return "vkDestroyVkImageView()";
            case VK_FUNCTION_FLAG_VK_DESTROY_SWAPCHAIN_KHR: return "vkDestroySwapchainKHR()";
            case VK_FUNCTION_FLAG_VK_DESTROY_DEVICE: return "vkDestroyDevice()";
            case VK_FUNCTION_FLAG_VK_DESTROY_SURFACE_KHR: return "vkDestroySurfaceKHR()";
            case VK_FUNCTION_FLAG_VK_DESTROY_DEBUG_UTILS_MESSENGER_EXT: return "vkDestroyDebugUtilsMessengerEXT()";
            case VK_FUNCTION_FLAG_VK_DESTROY_INSTANCE: return "vkDestroyInstance()";
            case VK_FUNCTION_FLAG_VK_CREATE_INSTANCE: return "VkCreateInstance()";
            case VK_FUNCTION_FLAG_VK_CREATE_DEBUG_UTILS_MESSENGER_EXT: return "vkCreateDebugUtilsMessenger()";
            case VK_FUNCTION_FLAG_VK_CREATE_DEVICE: return "VkCreateDevice()";
            case VK_FUNCTION_FLAG_VK_CREATE_SURFACE_KHR: return "VkCreateSurfaceKHR()";
            case VK_FUNCTION_FLAG_VK_CREATE_SWAPCHAIN_KHR: return "VkCreateSwapchainKHR()";
            case VK_FUNCTION_FLAG_VK_ENUMERATE_INSTANCE_LAYER_PROPERTIES: return "vkEnumerateInstanceLayerProperties()";
            case VK_FUNCTION_FLAG_VK_ENUMERATE_INSTANCE_EXTENSION_PROPERTIES: return "vkEnumerateInstanceExtensionProperties()";
            case VK_FUNCTION_FLAG_VK_ENUMERATE_DEVICE_LAYER_PROPERTIES: return "vkEnumerateDeviceLayerProperties()";
            case VK_FUNCTION_FLAG_VK_ENUMERATE_DEVICE_EXTENSION_PROPERTIES: return "vkEnumerateDeviceExtensionProperties()";
            case VK_FUNCTION_FLAG_VK_ENUMERATE_PHYSICAL_DEVICES: return "vkEnumeratePhysicalDevices()";
            case VK_FUNCTION_FLAG_VK_GET_PHYSICAL_DEVICE_SURFACE_CAPABILITIES_KHR: return "vkGetPhysicalDeviceSurfaceCapabilitiesKHR()";
            case VK_FUNCTION_FLAG_VK_GET_PHYSICAL_DEVICE_SURFACE_FORMATS_KHR: return "vkGetPhysicalDeviceSurfaceFormatsKHR()";
            case VK_FUNCTION_FLAG_VK_GET_PHYSICAL_DEVICE_SURFACE_PRESENT_MODES_KHR: return "vkGetPhysicalDeviceSurfacePresentModesKHR()";
            case VK_FUNCTION_FLAG_VK_GET_SWAPCHAIN_IMAGES_KHR: return "vkGetSwapchainImagesKHR()";
            case VK_FUNCTION_FLAG_VK_CREATE_IMAGE_VIEW: return "vkCreateImageView()";
            case VK_FUNCTION_FLAG_VK_CREATE_IMAGE: return "vkCreateImage()";
            default: return "VK_FUNCTION_FLAG_UNKNOWN";

        }

    }

    inline static const char* GetTecmaVkEnumTypeName(
        const TecmaVkEnumType& __enType
    ) noexcept {
        switch( __enType ) {
            case VK_ENUM_TYPE_VK_PRESENT_MODE: return "VkPresentModeKHR";
            case VK_ENUM_TYPE_VK_FORMAT: return "VkFormat";
            case VK_ENUM_TYPE_VK_COLOR_SPACE: return "VkColorSpaceKHR";
            default: return "VK_ENUM_UNKNOWN";

        }

    }

    inline static const char* GetTecmaVkResultName(
        const TecmaVkResult& __result
    ) noexcept {
        switch( __result ) {
            case VK_SUCCESS: return "VK_SUCCESS";
            case VK_NOT_READY: return "VK_NOT_READY";
            case VK_TIMEOUT: return "VK_TIMEOUT";
            case VK_EVENT_SET: return "VK_EVENT_SET";
            case VK_EVENT_RESET: return "VK_EVENT_RESET";
            case VK_INCOMPLETE: return "VK_INCOMPLETE";
            case VK_ERROR_OUT_OF_HOST_MEMORY: return "VK_ERROR_OUT_OF_HOST_MEMORY";
            case VK_ERROR_OUT_OF_DEVICE_MEMORY: return "VK_ERROR_OUT_OF_DEVICE_MEMORY";
            case VK_ERROR_INITIALIZATION_FAILED: return "VK_ERROR_INITIALIZATION_FAILED";
            case VK_ERROR_DEVICE_LOST: return "VK_ERROR_DEVICE_LOST";
            case VK_ERROR_MEMORY_MAP_FAILED: return "VK_ERROR_MEMORY_MAP_FAILED";
            case VK_ERROR_LAYER_NOT_PRESENT: return "VK_ERROR_LAYER_NOT_PRESENT";
            case VK_ERROR_EXTENSION_NOT_PRESENT: return "VK_ERROR_EXTENSION_NOT_PRESENT";
            case VK_ERROR_FEATURE_NOT_PRESENT: return "VK_ERROR_FEATURE_NOT_PRESENT";
            case VK_ERROR_INCOMPATIBLE_DRIVER: return "VK_ERROR_INCOMPATIBLE_DRIVER";
            case VK_ERROR_TOO_MANY_OBJECTS: return "VK_ERROR_TOO_MANY_OBJECTS";
            case VK_ERROR_FORMAT_NOT_SUPPORTED: return "VK_ERROR_FORMAT_NOT_SUPPORTED";
            case VK_ERROR_FRAGMENTED_POOL: return "VK_ERROR_FRAGMENTED_POOL";
            case VK_ERROR_UNKNOWN: return "VK_ERROR_UNKNOWN";
            case VK_ERROR_VALIDATION_FAILED: return "VK_ERROR_VALIDATION_FAILED";
            case VK_ERROR_OUT_OF_POOL_MEMORY: return "VK_ERROR_OUT_OF_POOL_MEMORY";
            case VK_ERROR_INVALID_EXTERNAL_HANDLE: return "VK_ERROR_INVALID_EXTERNAL_HANDLE";
            case VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS: return "VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS";
            case VK_ERROR_FRAGMENTATION: return "VK_ERROR_FRAGMENTATION";
            case VK_PIPELINE_COMPILE_REQUIRED: return "VK_PIPELINE_COMPILE_REQUIRED";
            case VK_ERROR_NOT_PERMITTED: return "VK_ERROR_NOT_PERMITTED";
            case VK_ERROR_SURFACE_LOST_KHR: return "VK_ERROR_SURFACE_LOST_KHR";
            case VK_ERROR_NATIVE_WINDOW_IN_USE_KHR: return "VK_ERROR_NATIVE_WINDOW_IN_USE_KHR";
            case VK_SUBOPTIMAL_KHR: return "VK_SUBOPTIMAL_KHR";
            case VK_ERROR_OUT_OF_DATE_KHR: return "VK_ERROR_OUT_OF_DATE_KHR";
            case VK_ERROR_INCOMPATIBLE_DISPLAY_KHR: return "VK_ERROR_INCOMPATIBLE_DISPLAY_KHR";
            case VK_ERROR_INVALID_SHADER_NV: return "VK_ERROR_INVALID_SHADER_NV";
            case VK_ERROR_IMAGE_USAGE_NOT_SUPPORTED_KHR: return "VK_ERROR_IMAGE_USAGE_NOT_SUPPORTED_KHR";
            case VK_ERROR_VIDEO_PICTURE_LAYOUT_NOT_SUPPORTED_KHR: return "VK_ERROR_VIDEO_PICTURE_LAYOUT_NOT_SUPPORTED_KHR";
            case VK_ERROR_VIDEO_PROFILE_OPERATION_NOT_SUPPORTED_KHR: return "VK_ERROR_VIDEO_PROFILE_OPERATION_NOT_SUPPORTED_KHR";
            case VK_ERROR_VIDEO_PROFILE_FORMAT_NOT_SUPPORTED_KHR: return "VK_ERROR_VIDEO_PROFILE_FORMAT_NOT_SUPPORTED_KHR";
            case VK_ERROR_VIDEO_PROFILE_CODEC_NOT_SUPPORTED_KHR: return "VK_ERROR_VIDEO_PROFILE_CODEC_NOT_SUPPORTED_KHR";
            case VK_ERROR_VIDEO_STD_VERSION_NOT_SUPPORTED_KHR: return "VK_ERROR_VIDEO_STD_VERSION_NOT_SUPPORTED_KHR";
            case VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT: return "VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT";
            case VK_ERROR_PRESENT_TIMING_QUEUE_FULL_EXT: return "VK_ERROR_PRESENT_TIMING_QUEUE_FULL_EXT";
            case VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT: return "VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT";
            case VK_THREAD_IDLE_KHR: return "VK_THREAD_IDLE_KHR";
            case VK_THREAD_DONE_KHR: return "VK_THREAD_DONE_KHR";
            case VK_OPERATION_DEFERRED_KHR: return "VK_OPERATION_DEFERRED_KHR";
            case VK_OPERATION_NOT_DEFERRED_KHR: return "VK_OPERATION_NOT_DEFERRED_KHR";
            case VK_ERROR_INVALID_VIDEO_STD_PARAMETERS_KHR: return "VK_ERROR_INVALID_VIDEO_STD_PARAMETERS_KHR";
            case VK_ERROR_COMPRESSION_EXHAUSTED_EXT: return "VK_ERROR_COMPRESSION_EXHAUSTED_EXT";
            case VK_INCOMPATIBLE_SHADER_BINARY_EXT: return "VK_INCOMPATIBLE_SHADER_BINARY_EXT";
            case VK_PIPELINE_BINARY_MISSING_KHR: return "VK_PIPELINE_BINARY_MISSING_KHR";
            case VK_ERROR_NOT_ENOUGH_SPACE_KHR: return "VK_ERROR_NOT_ENOUGH_SPACE_KHR";
            default: return "VK_RESULT_UNKNOWN";

        }

    }

    inline static const char* GetTecmaVkObjectTypeName(
        const TecmaVkObjectType& __objectType        
    ) noexcept {
        switch( __objectType ) {
            case VK_OBJECT_TYPE_INSTANCE: return "VkInstance";
            case VK_OBJECT_TYPE_PHYSICAL_DEVICE: return "VkPhysicalDevice";
            case VK_OBJECT_TYPE_DEVICE: return "VkDevice";
            case VK_OBJECT_TYPE_QUEUE: return "VkQueue";
            case VK_OBJECT_TYPE_SEMAPHORE: return "VkSemaphore";
            case VK_OBJECT_TYPE_COMMAND_BUFFER: return "VkCommandBuffer";
            case VK_OBJECT_TYPE_FENCE: return "VkFence";
            case VK_OBJECT_TYPE_DEVICE_MEMORY: return "VkDeviceMemory";
            case VK_OBJECT_TYPE_BUFFER: return "VkBuffer";
            case VK_OBJECT_TYPE_IMAGE: return "VkImage";
            case VK_OBJECT_TYPE_EVENT: return "VkEvent";
            case VK_OBJECT_TYPE_QUERY_POOL: return "VkQueryPool";
            case VK_OBJECT_TYPE_BUFFER_VIEW: return "VkBufferView";
            case VK_OBJECT_TYPE_IMAGE_VIEW: return "VkImageView";
            case VK_OBJECT_TYPE_SHADER_MODULE: return "VkShaderModule";
            case VK_OBJECT_TYPE_PIPELINE_CACHE: return "VkPipelineCache";
            case VK_OBJECT_TYPE_PIPELINE_LAYOUT: return "VkPipelineLayout";
            case VK_OBJECT_TYPE_RENDER_PASS: return "VkRenderPass";
            case VK_OBJECT_TYPE_PIPELINE: return "VkPipeline";
            case VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT: return "VkDescriptorSetLayout";
            case VK_OBJECT_TYPE_SAMPLER: return "VkSampler";
            case VK_OBJECT_TYPE_DESCRIPTOR_POOL: return "VkDescriptorPool";
            case VK_OBJECT_TYPE_DESCRIPTOR_SET: return "VkDescriptorSet";
            case VK_OBJECT_TYPE_FRAMEBUFFER: return "VkFramebuffer";
            case VK_OBJECT_TYPE_COMMAND_POOL: return "VkCommandPool";
            case VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE: return "VkDescriptorUpdateTemplate";
            case VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION: return "VkSamplerYcbcrConversion";
            case VK_OBJECT_TYPE_PRIVATE_DATA_SLOT: return "VkPrivateDataSlot";
            case VK_OBJECT_TYPE_SURFACE_KHR: return "VkSurfaceKHR";
            case VK_OBJECT_TYPE_SWAPCHAIN_KHR: return "VkSwapchainKHR";
            case VK_OBJECT_TYPE_DISPLAY_KHR: return "VkDsiplayKHR";
            case VK_OBJECT_TYPE_DISPLAY_MODE_KHR: return "VkDsiplayModeKHR";
            case VK_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT: return "VkDebugReportCallbackEXT";
            case VK_OBJECT_TYPE_VIDEO_SESSION_KHR: return "VkVideoSessionKHR";
            case VK_OBJECT_TYPE_VIDEO_SESSION_PARAMETERS_KHR: return "VkVideoSessionParametersKHR";
            case VK_OBJECT_TYPE_CU_MODULE_NVX: return "VkCuModuleNVX";
            case VK_OBJECT_TYPE_CU_FUNCTION_NVX: return "VkCuFunctionNVX";
            case VK_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT: return "VkDebugUtilsMessengerEXT";
            case VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR: return "VkAccelerationStructureKHR";
            case VK_OBJECT_TYPE_VALIDATION_CACHE_EXT: return "VkValidationCacheEXT";
            case VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV: return "VkAccelerationStructureNV";
            case VK_OBJECT_TYPE_PERFORMANCE_CONFIGURATION_INTEL: return "VkPerformanceConfigurationINTEL";
            case VK_OBJECT_TYPE_DEFERRED_OPERATION_KHR: return "VkDeferedOperationKHR";
            case VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_NV: return "VkIndirectCommandsLayoutNV";
            #ifdef VK_ENABLE_BETA_EXTENSIONS
                case VK_OBJECT_TYPE_CUDA_MODULE_NV: return "VkCudaModuleNV";
            #endif
            #ifdef VK_ENABLE_BETA_EXTENSIONS
                case: VK_OBJECT_TYPE_CUDA_FUNCTION_NV: return "VkCudaFunctionNV"
            #endif
            case VK_OBJECT_TYPE_BUFFER_COLLECTION_FUCHSIA: return "VkBufferCollectionFUCHSIA";
            case VK_OBJECT_TYPE_MICROMAP_EXT: return "VkMicromapEXT";
            case VK_OBJECT_TYPE_TENSOR_ARM: return "VkTensorARM";
            case VK_OBJECT_TYPE_TENSOR_VIEW_ARM: return "VkTensorViewARM";
            case VK_OBJECT_TYPE_OPTICAL_FLOW_SESSION_NV: return "VkOpticalFlowSessionNV";
            case VK_OBJECT_TYPE_SHADER_EXT: return "VkShaderEXT";
            case VK_OBJECT_TYPE_PIPELINE_BINARY_KHR: return "VkPipelineBinaryKHR";
            case VK_OBJECT_TYPE_DATA_GRAPH_PIPELINE_SESSION_ARM: return "VkDataGraphPipelineSessionARM";
            case VK_OBJECT_TYPE_EXTERNAL_COMPUTE_QUEUE_NV: return "VkExternalComputeQueueNV";
            case VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_EXT: return "VkIndirectCommandsLayoutEXT";
            case VK_OBJECT_TYPE_INDIRECT_EXECUTION_SET_EXT: return "VkIndirectExecutionSetEXT";
            case VK_OBJECT_TYPE_SHADER_INSTRUMENTATION_ARM: return "VkShaderInstrumentationARM";
            case VK_OBJECT_TYPE_UNKNOWN: return "VK_OBJECT_TYPE_UNKNOWN";
            default: return "VK_OBJECT_TYPE_UNKNOWN";            

        };

    }

};

#endif