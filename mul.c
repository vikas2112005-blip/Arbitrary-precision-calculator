/* Name: Vikas C
   Date: 30-06-2026
   
*/
#include "apc.h"

void multiplication(node *tail1, node *tail2, node **headR1, node **tailR1)
{
    int count = 0, first = 0, check = 0, carry = 0;

    // Loop through each digit of second operand (from last)
    while (tail2 != NULL)
    {
        node *headR2 = NULL;
        node *tailR2 = NULL;
        node *tailR3 = NULL;
        node *headR3 = NULL;

        int operand1 = 0, operand2 = 0, product = 0;
        check = 0;
        carry = 0;

        // Add zeros for shifting (place value)
        for (int i = 0; i < count; i++)
            insert_last(&headR2, &tailR2, 0);

        operand2 = tail2->data;

        node *temp1 = tail1;

        // Multiply each digit of first operand
        while (temp1 != NULL)
        {
            operand1 = temp1->data;

            product = operand1 * operand2 + carry;

            carry = product / 10;     // get carry
            product = product % 10;   // get single digit

            // Insert result digit into temporary list
            insert_first(&headR2, &tailR2, product);

            check = 1;
            temp1 = temp1->prev;
        }

        // If carry remains, insert it
        if (carry)
        {
            insert_first(&headR2, &tailR2, carry);
            check = 1;
        }

        // First partial result → directly assign
        if (first == 0)
        {
            *headR1 = headR2;
            *tailR1 = tailR2;
        }
        else if (check == 1)
        {
            // Add partial result to final result
            addition(*tailR1, tailR2, &headR3, &tailR3);

            // Free old lists
            free_list(headR1);
            free_list(&headR2);

            // Update result list
            *headR1 = headR3;
            *tailR1 = tailR3;
        }

        first++;
        count++;                 // increase shift
        tail2 = tail2->prev;     // move to next digit
    }
}