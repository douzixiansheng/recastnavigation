//
// Copyright (c) 2009-2010 Mikko Mononen memon@inside.org
//
// This software is provided 'as-is', without any express or implied
// warranty.  In no event will the authors be held liable for any damages
// arising from the use of this software.
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would be
//    appreciated but is not required.
// 2. Altered source versions must be plainly marked as such, and must not be
//    misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.
//

#ifndef DETOURALLOCATOR_H
#define DETOURALLOCATOR_H

#include <stddef.h>

/// Provides hint values to the memory allocator on how long the
/// memory is expected to be used.
/// 向内存分配器提供关于预期使用内存多长时间的提示值
enum dtAllocHint
{
	DT_ALLOC_PERM,		///< Memory persist after a function call. 函数调用后，内存会持续存在
	DT_ALLOC_TEMP		///< Memory used temporarily within a function.函数中临时使用的内存
};

/// A memory allocation function. 内存分配函数
//  @param[in]		size			The size, in bytes of memory, to allocate. 要分配的内存大小(以字节为单位)。
//  @param[in]		rcAllocHint	A hint to the allocator on how long the memory is expected to be in use. 向分配器提示内存预期使用多长时间。
//  @return A pointer to the beginning of the allocated memory block, or null if the allocation failed.
//  返回一个指向已分配内存块开头的指针，如果分配失败则为null。
///  @see dtAllocSetCustom
typedef void* (dtAllocFunc)(size_t size, dtAllocHint hint);

/// A memory deallocation function. 一个内存回收函数
///  @param[in]		ptr		A pointer to a memory block previously allocated using #dtAllocFunc.指向先前使用#dtAllocFunc分配的内存块的指针。
/// @see dtAllocSetCustom
typedef void (dtFreeFunc)(void* ptr);

/// Sets the base custom allocation functions to be used by Detour. 设置Detour使用的基本自定义分配函数。
///  @param[in]		allocFunc	The memory allocation function to be used by #dtAlloc #dtAlloc要使用的内存分配函数
///  @param[in]		freeFunc	The memory de-allocation function to be used by #dtFree #dtFree将使用的内存回收函数
void dtAllocSetCustom(dtAllocFunc *allocFunc, dtFreeFunc *freeFunc);

/// Allocates a memory block. 分配一个内存块。
///  @param[in]		size	The size, in bytes of memory, to allocate. 要分配的内存大小(以字节为单位)。
///  @param[in]		hint	A hint to the allocator on how long the memory is expected to be in use. 向分配器提示内存预期使用多长时间。
///  @return A pointer to the beginning of the allocated memory block, or null if the allocation failed. 一个指向已分配内存块开头的指针，如果分配失败则为空。
/// @see dtFree
void* dtAlloc(size_t size, dtAllocHint hint);

/// Deallocates a memory block. 释放一个内存块。
///  @param[in]		ptr		A pointer to a memory block previously allocated using #dtAlloc. 指向先前使用#dtAlloc分配的内存块的指针。
/// @see dtAlloc
void dtFree(void* ptr);

#endif
