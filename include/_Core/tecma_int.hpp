#ifndef TECMA_INT_HPP
#define TECMA_INT_HPP

#define TECMA_UINT_N_MAX(N) ((1 << (unsigned int)(N)) - 1)
#define TECMA_UINT_64_MAX ((1 << 64) - 1)
#define TECMA_UINT_32_MAX ((1 << 32) - 1)
#define TECMA_UINT_16_MAX ((1 << 16) - 1)
#define TECMA_UINT_8_MAX ((1 << 8) - 1)
#define TECMA_INT_N_MAX(N) ((1 << ((unsigned int)(N - 1))) - 1)
#define TECMA_INT_64_MAX ((1 << 63) - 1)
#define TECMA_INT_32_MAX ((1 << 31) - 1)
#define TECMA_INT_16_MAX ((1 << 15) - 1)
#define TECMA_INT_8_MAX ((1 << 7) - 1)

typedef unsigned char TecmaUint8;
typedef unsigned short TecmaUint16;
typedef unsigned int TecmaUint32;
typedef unsigned long long TecmaUint64;
typedef signed char TecmaInt8;
typedef signed short TecmaInt16;
typedef signed int TecmaInt32;
typedef signed long long TecmaInt64;

namespace TECMA_INT {

};

#endif