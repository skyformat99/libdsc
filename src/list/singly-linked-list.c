#include <stdlib.h>
#include <common/utils.h>
#include <common/debug.h>
#include <list/list.h>

#include "list-private.h"


/* prints each element in the list */
void dsc_sll_print_list(const char* list_name, const singlyList_t* head, print_data_fn_t print_fn)
{
    if(head == NULL)
        return;
    if(print_fn == NULL)
        print_output("%s\n", "print function needed!\n");

    const struct sll* list_head = (*head);
    size_t id = 0;
    if(list_name != NULL)
        print_output("[printing list: %s]\n", list_name);
    while(list_head)
    {
        print_output("[node %ld @addr: %p]: ", id++, list_head);
        (*print_fn)(list_head->data);
        print_output("%s","\n");
        list_head = list_head->next;
    }
    print_output("[summary]: list length: %ld\n", id); 
}


/* create an instance of singly list */
static struct sll* dsc_p_sll_get_new_node(void* data)
{
    if(data == NULL) return NULL;

    struct sll* list = dsc_calloc(1, sizeof(struct sll));
    list->data = data;
    list->next = NULL;
    dbg_trace("addr(node): %p, addr(node->data): %p\n",
         list, list->data);
    return list;
}


/* destroys the singly list */
void dsc_sll_destroy_list(void** head, free_fn_t data_free_fn)
{
    if(head == NULL) return;

    /* current list head */
    struct sll* list_head = (*head);
    struct sll* next = NULL;

    while(list_head)
    {
        /* save the next node */
        next = list_head->next;
        /* free the current node */
        if(data_free_fn != NULL)
        {
            if(list_head->data != NULL)
            {
                (*data_free_fn)(list_head->data);
                list_head->data = NULL;
            }
        }
        free(list_head);
        /* next node */
        list_head = next;
    }
    (*head) = NULL;
}


/* returns the length of the list */
size_t dsc_sll_list_length(const singlyList_t* head)
{
    if(head == NULL) return 0;

    const struct sll* list_head = (*head);
    size_t len = 0;
    while(list_head)
    {
        ++len;
        list_head = list_head->next;
    }
    dbg_trace("list_length: %ld\n", len);
    return len;
}


/* inserts node at the head of the list */
void dsc_sll_insert_head(void** list, void* data)
{
    if(list == NULL || data == NULL)
        return;
    struct sll** list_head = (struct sll**) list;
    struct sll* new_node = dsc_p_sll_get_new_node(data);
    new_node->next = (*list_head);
    (*list_head) = new_node;
}


/* inserts node after the current node */
void dsc_sll_insert(void** list, void* data)
{
    if(list == NULL || data == NULL)
        return;
    struct sll** list_head = (struct sll**) list;
    struct sll* new_node = dsc_p_sll_get_new_node(data);
    
    /* check if we're at null node;
     * this means that we're the first node, or might be last;
     * update head and return after this */
    if((*list_head) == NULL)
    {
        (*list_head) = new_node;
        return;
    }
    /* else add the node after current head;
     * and do not update the head */
    struct sll* next = (*list_head)->next;
    (*list_head)->next = new_node;
    new_node->next = next;
}

