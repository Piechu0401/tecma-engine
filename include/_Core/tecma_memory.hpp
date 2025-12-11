#ifndef TECMA_MEMORY_HPP 
#define TECMA_MEMORY_HPP

#include "_Platform/tecma_os.hpp"

#define TECMA_NULL nullptr
#define TecmaTeraByte 1 << 40
#define TecmaGigaByte 1 << 30
#define TecmaMegaByte 1 << 20
#define TecmaKiloByte 1 << 10
#define TecmaByte 1
#define TECMA_NO_MMAP_SIZE 1 << 8 * TecmaKiloByte

namespace TECMA_MEMORY {
    struct TecmaMemoryStorage {
        friend TecmaPtr TecmaMemoryAllocation(
            TecmaSize ChunkSize
        );

        friend TecmaPtr TecmaMemoryReallocation(
            const TecmaPtr Chunk,
            TecmaSize NewChunkSize
        );

        friend TecmaFunc TecmaMemoryFree(
            TecmaPtr Chunk
        );

        friend TecmaMemoryStorage* FindFreeStorage(
            TecmaSize ChunkSize
        );

        private:
            TecmaSize Size;
            TecmaMemoryStorage* Next;
            int FreeSpace;

    };

    #define TECMA_MEMORY_BLOCK_SIZE sizeof(TecmaMemoryStorage)

    constexpr TecmaMemoryStorage* TecmaMemoryHead = NULL;

    TecmaMemoryStorage* FindFreeStorage(
        TecmaSize ChunkSize
    );

    TecmaPtr TecmaMemoryAlignedAllocation(
        TecmaSize ChunkSize,
        TecmaSize ChunkAligment
    );

    TecmaPtr TecmaMemoryAllocation(
        TecmaSize ChunkSize
    );

    TecmaPtr TecmaMemoryReallocation(
        const TecmaPtr Chunk,
        TecmaSize NewChunkSize
    );

    TecmaFunc TecmaMemoryCopy(
        TecmaPtr DestinationChunk,
        const TecmaPtr SourceChunk,
        const TecmaSize& SourceChunkSize
    );

    TecmaFunc TecmaMemoryFree(
        TecmaPtr Chunk
    );

};

#endif