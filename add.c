/* Name:Vikas C
   Date: 30-06-2026
   
*/

#include "apc.h"

// Perform addition of two numbers represented as linked lists
int addition(node *tail1, node *tail2, node **headR, node **tailR)
{
    int carry = 0;

    // Traverse both lists from last digit
    while(tail1 != NULL || tail2 != NULL)
    {
        int operand1 = 0, operand2 = 0, sum = 0;

        // Get digit from first operand
        if(tail1 != NULL)
        {
            operand1 = tail1->data;
            tail1 = tail1->prev;
        }

        // Get digit from second operand
        if(tail2 != NULL)
        {
            operand2 = tail2->data;
            tail2 = tail2->prev;
        }

        // Add digits along with carry
        sum = operand1 + operand2 + carry;

        // Handle carry
        if(sum > 9)
        {
            carry = 1;
            sum = sum - 10;
        }
        else
            carry = 0;

        // Insert result digit at beginning
        if(insert_first(headR, tailR, sum) == FAILURE)
        {
            printf("Addition Failed\n");
            return FAILURE;
        }
    }

    // If carry remains, insert it
    if(carry)
        insert_first(headR, tailR, carry);

    return SUCCESS;
}