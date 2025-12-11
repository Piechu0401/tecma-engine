#include "../_Core/tecma_memory.hpp"

namespace TECMA_MEMORY {
    TecmaMemoryStorage* FindFreeStorage(
        TecmaSize ChunkSize
    ) {
        TecmaMemoryStorage* Current = TecmaMemoryHead;

        while(
            Current
        ) {
            if(
                Current->Next && Current->Size >= ChunkSize
            ) return Current;

            Current = Current->Next;

        }

        return TECMA_NULL;

    }

    TecmaPtr TecmaMemoryAlignedAllocation(
        TecmaSize ChunkSize,
        TecmaSize ChunkAlignment
    ) {
        if(
            ChunkAlignment == 0 ||
            (
                (
                    ChunkAlignment & 
                    (
                        ChunkAlignment - TECMA_MEMORY_BLOCK_SIZE
                    )
                ) != 0
            )
        ) return TECMA_NULL;

        return TecmaMemoryAllocation(
            ChunkAlignment - TECMA_MEMORY_BLOCK_SIZE + ChunkSize 
        );

    }

    TecmaPtr TecmaMemoryAllocation(
        TecmaSize ChunkSize
    ) {
        TecmaMemoryStorage* Heap = FindFreeStorage(
            ChunkSize
        );

        if(
            !Heap
        ) {
            if(
                TECMA_NO_MMAP_SIZE > ChunkSize 
            ) {
                TecmaPtr SpaceRequest = (TecmaPtr)syscall(
                    SYS_brk, 0
                );
                TecmaPtr NewChunk = (char*)SpaceRequest + ChunkSize;
                TecmaPtr Return = (TecmaPtr)syscall(
                    SYS_brk, NewChunk
                );
                    if(
                        !Return
                    ) return TECMA_NULL;
                Heap = (TecmaMemoryStorage*)SpaceRequest;
            }
            else {
                TecmaPtr SpaceRequest = (TecmaPtr)syscall(
                    SYS_mmap,
                    TECMA_NULL,
                    ChunkSize,
                    PROT_READ | PROT_WRITE,
                    MAP_PRIVATE | MAP_ANONYMOUS | MAP_HUGE_MASK,
                    -1,
                    0
                );

                if(
                    SpaceRequest == (TecmaPtr)MAP_FAILED
                ) return TECMA_NULL;

                Heap = (TecmaMemoryStorage*)SpaceRequest;

            }
            Heap->Size = ChunkSize;
            Heap->Next = TECMA_NULL;
            Heap->FreeSpace = 0;
        }

        return (TecmaPtr)((char*)Heap + (int)TECMA_MEMORY_BLOCK_SIZE);

    }

    TecmaPtr TecmaMemoryReallocation(
        const TecmaPtr Chunk,
        TecmaSize NewChunkSize
    ) {
        if(
            !Chunk 
        )  return TecmaMemoryAllocation(
                NewChunkSize
            );

        if(
            NewChunkSize == 0
        ) {
            TecmaMemoryFree(
                Chunk
            );
            return TECMA_NULL;
        }

        TecmaMemoryStorage* NewChunk = (TecmaMemoryStorage*)Chunk - (int)TECMA_MEMORY_BLOCK_SIZE;

        if(
            NewChunk->Size >= NewChunkSize
        ) return Chunk;

        TecmaPtr NewPtr = TecmaMemoryAllocation(
            NewChunkSize
        );

        if(
            !NewPtr
        ) return TECMA_NULL;

        TecmaMemoryCopy(
            NewChunk,
            Chunk,
            NewChunkSize
        );

        TecmaMemoryFree(
            Chunk
        );

        return NewChunk;

    }

    TecmaFunc TecmaMemoryCopy(
        TecmaPtr* DestinationChunk,
        const TecmaPtr* SourceChunk,
        const TecmaSize& SourceChunkSize
    ) {
        if(
            SourceChunkSize > 0
        )
            for(
                int i = 0; i < SourceChunkSize; i++
            ) 
                DestinationChunk[i] = SourceChunk[i];

    }

    TecmaFunc TecmaMemoryFree(
        TecmaPtr Chunk
    ) {
        TecmaMemoryStorage* Block = (TecmaMemoryStorage*)Chunk - (int)TECMA_MEMORY_BLOCK_SIZE;
        Block->FreeSpace = 1;

    }

};