#include "tecma_types.h"
#include "tecma_constants.h"

TecmaString::TecmaString() noexcept {}

TecmaString::TecmaString(
    TecmaText Str
) noexcept {}

TecmaString::TecmaString(
    TecmaTexts
) noexcept {
    

}

TecmaU64 TecmaTextLen(
    TecmaText _src    
) {
    TecmaU64 _res{0};

    while(
        _src[_res] != TECMA_EOF
    ) ++_res;

    return _res;

}

TecmaText TecmaIntToText(
    TecmaI64 _src 
) {
    char _buff[64];
    TecmaU8 _size{64};

    while(
        _src > 0
    ) {
        _buff[--_size] = (_src % 10);
        _src /= 10;

    }

    return "";

}

TecmaText TecmaDoubleToText(
    const double& _src 
);