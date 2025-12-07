// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
#pragma once

#ifdef _WIN64
#define USE_PIX_ON_ALL_ARCHITECTURES
#endif

#ifdef USE_PIX
#include <pix3.h>
#endif

#ifndef  __in_range
#define __in_range(...)
#endif

#ifndef __in_ecount_opt
#define __in_ecount_opt(...)
#endif

#ifndef __field_ecount_part
#define __field_ecount_part(...)
#endif

#ifndef __if_exists
#define __if_exists(...) if constexpr (requires { __VA_ARGS__; })
#endif

#ifndef __analysis_assume
#define __analysis_assume(...)
#endif

#ifndef __assume
#define __assume(...) __builtin_expect(__VA_ARGS__, 1)
#endif

#ifndef __in
#define __in
#endif

#ifndef __nullterminated
#define __nullterminated
#endif


//Library Headers
#define TRANSLATION_API
#include "VideoViewHelper.hpp"
#include "SubresourceHelpers.hpp"
#include "Util.hpp"
#include "DeviceChild.hpp"

#include <BlockAllocators.h>
#include "Allocator.h"
#include "XPlatHelpers.h"

#include <ThreadPool.hpp>
#include <segmented_stack.h>
#include <formatdesc.hpp>
#include <dxgiColorSpaceHelper.h>

#include "MaxFrameLatencyHelper.hpp"
#include "Shader.hpp"
#include "Sampler.hpp"
#include "View.hpp"
#include "PipelineState.hpp"
#include "SwapChainManager.hpp"
#include "ResourceBinding.hpp"
#include "Fence.hpp"
#include "Residency.h"
#include "ResourceState.hpp"
#include "RootSignature.hpp"
#include "Resource.hpp"
#include "Query.hpp"
#include "ResourceCache.hpp"
#include "BlitHelper.hpp"
#include "ImmediateContext.hpp"
#include "BatchedContext.hpp"
#include "BatchedResource.hpp"
#include "BatchedQuery.hpp"
#include "CommandListManager.hpp"
#include "VideoDecodeStatistics.hpp"
#include "VideoReferenceDataManager.hpp"
#include "VideoDecode.hpp"
#include "VideoDevice.hpp"
#include "VideoProcess.hpp"
#include "VideoProcessEnum.hpp"

#include "View.inl"
#include "Sampler.inl"
#include "Shader.inl"
#include "ImmediateContext.inl"
#include "CommandListManager.inl"
#include <BlockAllocators.inl>

#ifndef MICROSOFT_TELEMETRY_ASSERT
#define MICROSOFT_TELEMETRY_ASSERT(x) assert(x)
#endif

namespace D3D12TranslationLayer
{
#if 0
extern TraceLoggingHProvider g_hTracelogging;
void SetTraceloggingProvider(TraceLoggingHProvider hTracelogging);
#endif
}
