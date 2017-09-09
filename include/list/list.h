#ifndef __DS_LIST_H__
#define __DS_LIST_H__

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

/* typedefs */
typedef void* singlyList_t;

/* this function should cast the pointer to appropriate type
 * and free it; this will point to the data field inside list node */
typedef void (*free_fn_t)(const void* data);

/* this function should return:
 * -1: if list_data should be higher in rank than cur_data
 *  0: if they are equal
 *  1: if list_data should be lower in rank than cur_data */
typedef bool (*comp_fn_t)(const void* list_data, const void* cur_data);

/* this function will be called iteratively for each data item
 * in the list; this should print the data on "stdout" using
 * fprintf or similar functions */
typedef void (*print_data_fn_t)(const void* data);

/**********************/
/* singly linked list */
/**********************/

/* insert a new node after the current list node */
void dsc_sll_insert(singlyList_t* list, void* data);

/* insert a new node at the list head and update head */
void dsc_sll_insert_head(singlyList_t* head, void* data);

/* insert new nodes in sorted order in the list */
void dsc_sll_sorted_insert(singlyList_t* head, void* data, comp_fn_t comp_fn);

/* remove node with given value through out the list */
void dsc_sll_remove(singlyList_t* head, void* data, comp_fn_t comp_fn);

/* remove all nodes from the list,
 * and frees data fields mem as well if data_fn is non-null;
 * and destroys the instance of the list */
void dsc_sll_destroy_list(singlyList_t* head, free_fn_t data_fn);

/* returns the length of the list */
size_t dsc_sll_list_length(const singlyList_t* head);

/* prints the contents of list */
void dsc_sll_print_list(const char* list_name, const singlyList_t* head, print_data_fn_t data_fn);

/* sort the given singly list */
void dsc_sll_sort(singlyList_t* head, comp_fn_t comp_fn);

/* reverse the given singly list */
void dsc_sll_reverse_list(singlyList_t* head);

#endif /* __DS_LIST_H__ */
