//
// Created by temdisponivel on 27/02/2018.
//

#ifndef ENGINE_TYPES_H
#define ENGINE_TYPES_H

#include <cstdint>
#include <malloc.h>

#define null NULL

typedef int8_t byte;

typedef uint8_t ubyte;
typedef uint16_t ushort;
typedef uint32_t uint;
typedef uint64_t ulong;

typedef uint gl_handle;

typedef void *(*allocator)(uint size);
typedef void (*deallocator)(void *ptr);
typedef void *(*reallocator)(void *ptr, uint new_size);

const allocator __default_allocator = &malloc;
const deallocator __default_deallocator = &free;
const reallocator __default_reallocator = &realloc;

const allocator memalloc = __default_allocator;
const deallocator memfree = __default_deallocator;
const reallocator memrealloc = __default_reallocator;

#endif //ENGINE_TYPES_H
