#ifndef __TECMA_TYPES_H
#define __TECMA_TYPES_H

#ifndef __TECMA_CONSTANTS_H
    #include "tecma_constants.h"
#endif

#ifndef __TECMA_CONSTANTS_H
    #include "tecma_constants.h"
#endif

typedef signed char             TecmaI8;
typedef signed short            TecmaI16;
typedef signed int              TecmaI32;
typedef signed long             TecmaI64;
typedef unsigned char           TecmaU8;
typedef unsigned short          TecmaU16;
typedef unsigned int            TecmaU32;
typedef unsigned long           TecmaU64;
typedef unsigned long long      TecmaSize;
typedef const char*             TecmaText;
typedef const char* const*      TecmaTexts;
typedef unsigned int            TecmaBool;

class TecmaString {
    public:
    explicit TecmaString() noexcept;
    explicit TecmaString(
        TecmaText Str
    ) noexcept;
    explicit TecmaString( // for more than one const char*, i aint lazy
        TecmaTexts
    ) noexcept;

    const TecmaString& operator+( const TecmaString& Other );
    const TecmaString& operator=( const TecmaString& Other );
    TecmaText operator=( TecmaText Other );
    TecmaText operator()();
    const TecmaBool& operator==( const TecmaString& Other );

    private:
        TecmaText Data;

};

struct TecmaColor {
    TecmaU64 _r;
    TecmaU64 _g;
    TecmaU64 _b;

};

template<typename __first, typename __second>
class TecmaPair {
    public:
    explicit TecmaPair() noexcept {};
    explicit TecmaPair(
        const __first& _f,
        const __second& _s
    ) noexcept {}

    __first _first;
    __second _second;

};

// functions that I might need in the future :

template<typename __first, typename __second>
TecmaPair<__first, __second> TecmaMakePair(
    const __first& _f,
    const __second& _s
) { return TecmaPair<__first, __second>(_f,_s); }

TecmaU64 TecmaTextLen(
    TecmaText _src    
);

TecmaText TecmaIntToText(
    TecmaI64 _src 
);

TecmaText TecmaDoubleToText(
    const double& _src 
);

#endif