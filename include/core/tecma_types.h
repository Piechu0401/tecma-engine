#ifndef __TECMA_TYPES_H
#define __TECMA_TYPES_H

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

#endif