#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#include <list/list.h>
#include <common/utils.h>

void data_free_fn(const void* data)
{
    free((int*)data);
}

void print_data_fn(const void* data)
{
    fprintf(stdout, "data: %d", *(int*)data);
}

int* get_data(int data)
{
    int* val = dsc_malloc(sizeof(int));
    *val = data;
    return val;
}

int main(int argc, char *argv[])
{
    /* initialize singlyList variables to NULL, always */
    singlyList_t l1 = NULL, l2 = NULL;
    int d1 = 5;
    int* d2 = dsc_malloc(sizeof(int));
    *d2 = 10;

    dsc_sll_insert_head(&l1, &d1);
    dsc_sll_insert_head(&l2, d2);

    dsc_sll_print_list("list-1", &l1, print_data_fn);
    dsc_sll_print_list("list-2", &l2, print_data_fn);

    dsc_sll_list_length(&l1);
    dsc_sll_list_length(&l2);

    for(int i = 1; i < 5; ++i)
    {
        dsc_sll_insert_head(&l2, get_data(i));
        dsc_sll_print_list("list-2", &l2, print_data_fn);
    }

    dsc_sll_insert(&l2, get_data(15));
    dsc_sll_print_list("list-2", &l2, print_data_fn);
    dsc_sll_insert(&l2, get_data(20));
    dsc_sll_print_list("list-2", &l2, print_data_fn);

    dsc_sll_destroy_list(&l1, NULL);
    dsc_sll_destroy_list(&l2, data_free_fn);
    
    return 0;
}
