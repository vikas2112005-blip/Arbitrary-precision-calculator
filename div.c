/* Name:Vikas C
   Date: 30-06-2026
   
*/

#include "apc.h"

void division(node *head_l1, node *head_opr2, node *tail_opr2, node **headR, node **tailR)
{
    node *head_opr1 = NULL;
    node *tail_opr1 = NULL;

    // Traverse dividend digit by digit
    while (head_l1 != NULL)
    {
        int sub_count = 0;

        // Bring down next digit
        insert_last(&head_opr1, &tail_opr1, head_l1->data);
        head_l1 = head_l1->next;

        // Remove leading zeros
        remove_pre_zeros(&head_opr1);

        // Keep adding digits until dividend part >= divisor
        while (compare_list(head_opr1, head_opr2) == OPERAND2 && head_l1 != NULL)
        {
            insert_last(&head_opr1, &tail_opr1, head_l1->data);
            head_l1 = head_l1->next;
            remove_pre_zeros(&head_opr1);
        }

        // Perform repeated subtraction
        while (compare_list(head_opr1, head_opr2) == OPERAND1 || 
               compare_list(head_opr1, head_opr2) == SAME)
        {
            node *head_SR = NULL;
            node *tail_SR = NULL;

            node *temp = head_opr1;
            node *safe_tail = NULL;

            // Find tail of current dividend part
            while (temp != NULL)
            {
                safe_tail = temp;
                temp = temp->next;
            }

            // Subtract divisor from current part
            subtraction(safe_tail, tail_opr2, &head_SR, &tail_SR);
            sub_count++;

            // Free old list
            free_list(&head_opr1);

            // Update current dividend part
            head_opr1 = head_SR;
            tail_opr1 = tail_SR;

            remove_pre_zeros(&head_opr1);
        }

        // Store quotient digit
        insert_last(headR, tailR, sub_count);
    }
}