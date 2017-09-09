#ifndef __LIST_PRIVATE_H__
#define __LIST_PRIVATE_H__

#include <stdint.h>

/**********************/
/* singly linked list */
/**********************/
struct sll
{
    void* data;
    struct sll* next;
};

#endif /* __LIST_PRIVATE_H__ */
