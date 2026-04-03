#ifndef __TECMA_VK_INSTANCE_H 
#define __TECMA_VK_INSTANCE_H

#include "tecma_vk_core.h"

namespace TecmaEngine {
    typedef struct TecmaVkInstance {
        explicit TecmaVkInstance() noexcept;
        explicit TecmaVkInstance(
            const TecmaVkInstance& __other
        ) noexcept;
        explicit TecmaVkInstance(
            const TecmaVkInstance&& __other
        ) noexcept;
        ~TecmaVkInstance() noexcept;

        VkInstance __inst;

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

    } TecmaVkInstance_t;

}

#endif