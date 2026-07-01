/* Name: Vikas C
   Date: 30-06-2026
   
*/

#include "apc.h"

// Insert node at end of list
int insert_last(node **head, node **tail, int data)
{
    node *new = malloc(sizeof(node));
    if(!new)
    {
        printf("Memory Allocation is failed\n");
        return FAILURE;
    }

    new->prev = NULL;
    new->data = data;
    new->next = NULL;

    // If list is empty
    if(*head == NULL)
    {
        *head = new;
        *tail = new;
        return SUCCESS;
    }

    // Insert at end
    (*tail)->next = new;
    new->prev = *tail;
    *tail = new;

    return SUCCESS;
}

// Insert node at beginning of list
int insert_first(node **head, node **tail, int data)
{
    node *new = malloc(sizeof(node));
    if(!new)
    {
        printf("Memory Allocation is failed\n");
        return FAILURE;
    }

    new->prev = NULL;
    new->data = data;
    new->next = NULL;

    // If list is empty
    if(*head == NULL)
    {
        *head = new;
        *tail = new;
        return SUCCESS;
    }

    // Insert at beginning
    (*head)->prev = new;
    new->next = *head;
    *head = new;

    return SUCCESS;
}

// Print all elements of list
void print_list(node *head)
{
    if(head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    // Traverse and print
    while(head != NULL)
    {
        printf("%d", head->data);
        head = head->next;
    }

    printf("\n");
}

// Compare two lists
int compare_list(node *head1, node *head2)
{
    // Remove leading zeros
    remove_pre_zeros(&head1);
    remove_pre_zeros(&head2);

    int list1_len = list_len(head1);
    int list2_len = list_len(head2);

    // Compare lengths
    if (list1_len > list2_len)
        return OPERAND1;
    else if (list1_len < list2_len)
        return OPERAND2;
    else
    {
        // Compare digit by digit
        while (head1 != NULL && head2 != NULL)
        {
            if (head1->data > head2->data)
                return OPERAND1;
            else if (head1->data < head2->data)
                return OPERAND2;

            head1 = head1->next;
            head2 = head2->next;
        }

        return SAME;
    }
}

// Calculate length of list
int list_len(node *head)
{
    int count = 0;

    while(head != NULL)
    {
        count++;
        head = head->next;
    }

    return count;
}

// Remove leading zeros from list
void remove_pre_zeros(node **head)
{
    if (*head == NULL)
        return;

    node *temp = *head;

    // Delete nodes with zero data from start
    while (temp != NULL && temp->data == 0)
    {
        node *next = temp->next;

        free(temp);

        // If last node, set list empty
        if (next == NULL)
        {
            *head = NULL;
            return;
        }

        next->prev = NULL;
        *head = next;
        temp = next;
    }
}

// Free entire list
void free_list(node **head)
{
    if(*head == NULL)
        return;

    node *next;
    node *prev = *head;

    while(prev != NULL)
    {
        next = prev->next;
        free(prev);
        prev = next;
    }

    *head = NULL;
}