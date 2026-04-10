#ifndef __TECMA_VK_INSTANCE_H 
#define __TECMA_VK_INSTANCE_H

#include "tecma_vk_core.h"

namespace TecmaEngine {
    struct TecmaVkInstance_t {
        explicit TecmaVkInstance_t() noexcept;
        explicit TecmaVkInstance_t(
            const TecmaVkInstance_t& __other
        ) noexcept;
        explicit TecmaVkInstance_t(
            const TecmaVkInstance_t&& __other
        ) noexcept;
        ~TecmaVkInstance_t() noexcept;

        VkInstance __inst;
        VkApplicationInfo __appInfo;

        void CreateVkInstance(
            const char* __appName,
            const unsigned int& __appVersion
        );

        void DestroyVkInstance() const noexcept;

        private:

        const VkApplicationInfo CreateApplicationInfo(
            const char* __appName,
            const unsigned int& __appVersion
        ) const noexcept;

    };

}

#endif