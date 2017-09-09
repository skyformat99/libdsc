#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include <common/utils.h>
#include <common/debug.h>

/* failes if mem alloc fails */
void* dsc_malloc(size_t size)
{
    void* ptr = malloc(size);
    if(ptr == NULL)
    {
        perror("malloc:");
        dbg_info("malloc failed\n");
        exit(-1);
    }
    return ptr;
}

/* fails if mem alloc fails */
void* dsc_calloc(size_t num, size_t size)
{
    void* ptr = calloc(num, size);
    if(ptr == NULL)
    {
        perror("calloc:");
        dbg_info("calloc failed\n");
        exit(-1);
    }
    return ptr;
}
