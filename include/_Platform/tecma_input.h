#ifndef __TECMA_INPUT_H
#define __TECMA_INPUT_H

#include <stdio.h>
#include <deque>
#include <vector>

#if defined( __TECMA_XLIB )
    #include <X11/Xlib.h>
    #include <X11/Xutil.h>
#endif

#ifndef __TECMA_CORE_H
    #include "../_Core/tecma_core.h"
#endif

#ifndef __TECMA_INPUT_CACHE_LIMIT
    #define __TECMA_INPUT_CACHE_LIMIT 16
#endif

namespace TecmaEngine {
    struct TecmaInput_t {
        explicit TecmaInput_t() noexcept;
        
        explicit TecmaInput_t(
            TecmaInput_t& __other
        ) noexcept;

        explicit TecmaInput_t(
            TecmaInput_t&& __other
        ) noexcept;
        
        ~TecmaInput_t() noexcept;

        template<typename __alignType> inline const TecmaFileByteData<__alignType> ReadFileData(
            const char* __path
        ) const {
            FILE* __f{ fopen( __path, "rb" ) };

            if( !__f ) TecmaLogger( TECMA_ERROR_FAILED_TO_OPEN_FILE );

            TecmaFileByteData<__alignType> __res;

            fseek( __f, 0, SEEK_END);
            __res.__size = ftell( __f );
            rewind( __f );

            __res.__data = (__alignType*)malloc(
                sizeof(__alignType) * __res.__size
            );

            fread(
                __res.__data,
                sizeof( __alignType ),
                __res.__size,
                __f
            );
            fclose( __f );

            return __res;

        }

        #if defined( __TECMA_XLIB )
            void CheckOutInput(
                XKeyEvent& __key
            ) noexcept;

            void CheckOutInput(
                XButtonEvent& __button
            ) noexcept;

        #endif

        std::deque<unsigned long> __pressedCache;

    };

    static TecmaInput_t TecmaInput;

};

#endif