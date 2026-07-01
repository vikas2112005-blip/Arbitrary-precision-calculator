/* Name: Vikas C
   Date: 30-06-2026
   
*/

#include "apc.h"

void subtraction(node *tail1, node *tail2, node **headR, node **tailR)
{
    int borrow = 0;

    // Traverse both lists from last digit
    while (tail1 != NULL || tail2 != NULL)
    {
        int operand1 = 0, operand2 = 0;

        // Get digit from first operand
        if (tail1 != NULL)
        {
            operand1 = tail1->data;
            tail1 = tail1->prev;
        }

        // Get digit from second operand
        if (tail2 != NULL)
        {
            operand2 = tail2->data;
            tail2 = tail2->prev;
        }

        // Apply previous borrow
        operand1 -= borrow;

        // If operand1 is smaller, take borrow
        if (operand1 < operand2)
        {
            operand1 += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        // Perform subtraction
        int sub = operand1 - operand2;

        // Insert result digit at front
        if (insert_first(headR, tailR, sub) == FAILURE)
        {
            printf("Subtraction Failed\n");
            return;
        }
    }

    // Remove leading zeros from result
    remove_pre_zeros(headR);
}