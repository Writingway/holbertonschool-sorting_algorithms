#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort
 * @list: Address of pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *temp;

    if (!list || !*list || !(*list)->next)
        return;

    current = (*list)->next;

    while (current)
    {
        temp = current;
        current = current->next;

        while (temp->prev && temp->prev->n > temp->n)
        {
            listint_t *prev = temp->prev;

            prev->next = temp->next;
            if (temp->next)
                temp->next->prev = prev;

            temp->next = prev;
            temp->prev = prev->prev;

            if (prev->prev)
                prev->prev->next = temp;
            prev->prev = temp;

            if (!temp->prev)
                *list = temp;

            print_list(*list);
        }
    }
}
