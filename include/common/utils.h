#ifndef __COMMON_UTILS_H__
#define __COMMON_UTILS_H__

#include <stdint.h>
#include <stddef.h>

/* wrappers for common memory alloc functions;
 * the functions will fail if the memory allocation is not successful */void* dsc_malloc(size_t size);
void* dsc_calloc(size_t num, size_t size);

#endif /* __COMMON_UTILS_H__ */
