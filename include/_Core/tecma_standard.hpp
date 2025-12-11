#ifndef TECMA_STANDARD_HPP 
#define TECMA_STANDARD_HPP

#include "tecma_int.hpp"
#include "tecma_memory.hpp"

namespace TECMA_STD {
    // pair thing
    
    template<typename TecmaTypeFirst, typename TecmaTypeSecond>
    struct TecmaPair {
        const TecmaTypeFirst& First() { return First; };
        const TecmaTypeFirst& Second() { return First; };

        private:
            TecmaTypeFirst FirstElement;
            TecmaTypeSecond SecondElement;

    };

    template<typename TecmaTypeFirst, typename TecmaTypeSecond>
    const TecmaPair<TecmaTypeFirst, TecmaTypeSecond> MakeTecmaPair(
        const TecmaTypeFirst& FirstElement,
        const TecmaTypeSecond& SecondElement
    ) {
        return TecmaPair<TecmaTypeFirst, TecmaTypeSecond>(
            FirstElement,
            SecondElement
        );

    }

    // Constant array var

    template<typename TecmaType, TecmaSize Size>
    struct TecmaArray {
        private:
            TecmaType* Data;
            TecmaSize DataSize;

    };

    // custom dynamic array type of shit

    template<typename TecmaType>
    struct TecmaDynamicArray {
        TecmaDynamicArray() {
            CurrentDataSize = 0;
            Data = (TecmaType*)TECMA_MEMORY::TecmaMemoryAllocation(
                sizeof(TecmaType) * CurrentDataSize
            );
        }
        TecmaDynamicArray(
            const TecmaSize DynamicArraySize
        ) {  
            CurrentDataSize = DynamicArraySize;
            Data = (TecmaType*)TECMA_MEMORY::TecmaMemoryAllocation(
                sizeof(TecmaType) * CurrentDataSize
            );
        }

        TecmaType& operator[](
            const TecmaUint32 Index
        ) { 
            return Index < CurrentDataSize ? Data[Index] : TECMA_NULL; 
        };

        TecmaType* GetData() { return Data; }
        TecmaType* begin() { return Data; }
        TecmaType* end() { return Data + CurrentDataSize; }
        TecmaFunc Resize(
            const TecmaSize NewSize
        ) {
            CurrentDataSize = NewSize;
            TecmaMemoryReallocation(
                Data,
                CurrentDataSize
            );

        }
        TecmaFunc EmplaceBack(
            const TecmaType& Element
        ) {
            if(
                CurrentDataSize + 1 != TECMA_UINT_64_MAX
            ) {
                CurrentDataSize += 1;
                TecmaMemoryReallocation(
                    Data,
                    CurrentDataSize
                );

            }

        }
        const TecmaSize GetSize() { return CurrentDataSize; }

        private:
            TecmaType* Data;
            TecmaSize CurrentDataSize;

    };

    template<typename TecmaType>
    struct TecmaUniquePtr {
        TecmaUniquePtr(decltype(TECMA_NULL)) noexcept : StoreElement(TECMA_NULL) {}
        explicit TecmaUniquePtr() noexcept : StoreElement(TECMA_NULL) {}
        explicit TecmaUniquePtr(
            TecmaType Element
        ) noexcept : StoreElement(Element) {}

        TecmaType& operator=(
            decltype(TECMA_NULL) 
        ) {
            StoreElement = TECMA_NULL;
            return *this;
        }

        TecmaType& operator=(
            const TecmaType& Element
        ) { 
            if(
                StoreElement != Element    
            ) 
                StoreElement = Element;

            return *this;

        }

        const TecmaType* operator=(
            const TecmaType* Element
        ) { 
            if(
                StoreElement != Element    
            ) 
                StoreElement = Element;

            return this;

        }
        
        TecmaType* Get() { return StoreElement; };

        private:
            TecmaType* StoreElement;

    };

    template<typename TecmaType, typename... TecmaArugments>
    const TecmaUniquePtr<TecmaType> MakeTecmaUniquePtr(
        TecmaArugments&&... Arguments
    ) {
        return TecmaUniquePtr<TecmaType>(
            new TecmaType(
                Arguments...
            )
        );

    }

};

#endif