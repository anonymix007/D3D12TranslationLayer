// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
#include "pch.h"

namespace D3D12TranslationLayer
{
    ID3D12Resource* InternalHeapAllocator::Allocate(UINT64 size)
    {
        // Transfer ownership of ID3D12Resource to the calling allocator
        return m_pContext->AcquireTransitionableUploadBuffer(m_HeapType, size).release();
    }

    void InternalHeapAllocator::Deallocate(ID3D12Resource* pResource)
    {
#if defined(_MSC_VER) || !defined(_WIN32)
        auto Width = pResource->GetDesc().Width;
#else
        D3D12_RESOURCE_DESC resDesc;
        pResource->GetDesc(&resDesc);
        auto Width = resDesc.Width;
#endif

        m_pContext->ReturnTransitionableBufferToPool(
            m_HeapType, 
            Width,
            std::move(unique_comptr<ID3D12Resource>(pResource)), 
            // Guaranteed to be finished since this is only called after
            // all suballocations have been through the deferred deletion queue
            m_pContext->GetCompletedFenceValue(CommandListType(m_HeapType)));

        // Leave ownership to the buffer pool
        pResource->Release();
    }

}
