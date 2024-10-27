#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 * @list: Double pointer to the head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *prev_node, *next_node;

    /* Check for NULL pointer or list with less than 2 nodes */
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = (*list)->next;
    while (current != NULL)
    {
        next_node = current->next;
        prev_node = current->prev;

        /* Move current node backward until it's in the right position */
        while (prev_node != NULL && prev_node->n > current->n)
        {
            /* Update next pointer of previous node */
            prev_node->next = current->next;
            if (current->next != NULL)
                current->next->prev = prev_node;

            /* Move current node one position backward */
            current->next = prev_node;
            current->prev = prev_node->prev;

            /* Update previous pointer of the previous node */
            prev_node->prev = current;

            /* Update head if necessary */
            if (current->prev == NULL)
                *list = current;
            else
                current->prev->next = current;

            /* Print list after each swap */
            print_list(*list);

            prev_node = current->prev;
        }
        current = next_node;
    }
}
