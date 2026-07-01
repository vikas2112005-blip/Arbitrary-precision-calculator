/* Name: Vikas C
   Date: 30-06-2026
  
*/
#include "apc.h"

int main(int argc, char *argv[])
{
    node *head1 = NULL, *tail1 = NULL;
    node *head2 = NULL, *tail2 = NULL;
    node *headR = NULL, *tailR = NULL;

    // Check if correct number of arguments are passed
    if (argc < 4)
    {
        printf("Exactly 3 arguments required\n");
        return FAILURE;
    }

    // Validate command line input
    if (cla_validation(argc, argv) == FAILURE)
        return FAILURE;

    char *operand1 = argv[1];
    char *operand2 = argv[3];
    char oper = argv[2][0];

    int sign1 = 1, sign2 = 1;

    // Check sign of first operand
    if (operand1[0] == '-')
    {
        sign1 = -1;
        operand1++;
    }
    else if (operand1[0] == '+')
        operand1++;

    // Check sign of second operand
    if (operand2[0] == '-')
    {
        sign2 = -1;
        operand2++;
    }
    else if (operand2[0] == '+')
        operand2++;

    // Convert operand1 into linked list
    for (int i = 0; operand1[i] != '\0'; i++)
        insert_last(&head1, &tail1, operand1[i] - '0');

    // Convert operand2 into linked list
    for (int i = 0; operand2[i] != '\0'; i++)
        insert_last(&head2, &tail2, operand2[i] - '0');

    switch (oper)
    {
        case '+':
        {
            // If both signs are same → perform addition
            if (sign1 == sign2)
            {
                addition(tail1, tail2, &headR, &tailR);

                printf("%s + %s = ", argv[1], argv[3]);

                if (sign1 == -1)
                    printf("-");

                remove_pre_zeros(&headR);
                if (headR == NULL)
                    insert_first(&headR, &tailR, 0);
                print_list(headR);
            }
            else
            {
                // If signs differ → perform subtraction
                int cmp = compare_list(head1, head2);

                if (cmp == SAME)
                {
                    insert_first(&headR, &tailR, 0);
                    printf("%s + %s = ", argv[1], argv[3]);
                    print_list(headR);
                    break;
                }

                if (cmp == OPERAND1)
                {
                    subtraction(tail1, tail2, &headR, &tailR);

                    if (sign1 == -1)
                        printf("-");
                }
                else
                {
                    subtraction(tail2, tail1, &headR, &tailR);

                    if (sign2 == -1)
                        printf("-");
                }

                printf("%s + %s = ", argv[1], argv[3]);
                remove_pre_zeros(&headR);
                if (headR == NULL)
                    insert_first(&headR, &tailR, 0);
                print_list(headR);
            }
            break;
        }

        case '-':
        {
            printf("%s - %s = ", argv[1], argv[3]);

            // If signs differ → convert to addition
            if (sign1 != sign2)
            {
                addition(tail1, tail2, &headR, &tailR);

                if (sign1 == -1)
                    printf("-");
            }
            else
            {
                int cmp = compare_list(head1, head2);

                if (cmp == SAME)
                {
                    insert_first(&headR, &tailR, 0);
                }
                else if (cmp == OPERAND1)
                {
                    subtraction(tail1, tail2, &headR, &tailR);

                    if (sign1 == -1)
                        printf("-");
                }
                else
                {
                    subtraction(tail2, tail1, &headR, &tailR);

                    if (sign1 == 1)
                        printf("-");
                }
            }

            remove_pre_zeros(&headR);
            if (headR == NULL)
                insert_first(&headR, &tailR, 0);
            print_list(headR);
            break;
        }

        case 'x':
        case 'X':
        {
            multiplication(tail1, tail2, &headR, &tailR);

            // FIRST normalize result
            remove_pre_zeros(&headR);
            if (headR == NULL)
                insert_first(&headR, &tailR, 0);

            printf("%s x %s = ", argv[1], argv[3]);

            // THEN check sign
            if ((sign1 != sign2) && !(headR->data == 0 && headR->next == NULL))
                printf("-");

            print_list(headR);
            break;
        }

        case '/':
        {
            // Check for division by zero
            if (strcmp(argv[3], "0") == 0)
            {
                printf("Error : You Cannot Divide By Zero\n");
                return FAILURE;
            }

            // Remove leading zeros
            remove_pre_zeros(&head1);
            remove_pre_zeros(&head2);

            // Find tail of second operand
            node *temp = head2;
            tail2 = NULL;

            while (temp)
            {
                tail2 = temp;
                temp = temp->next;
            }

            int cmp = compare_list(head1, head2);

            if (cmp == OPERAND2)
                insert_first(&headR, &tailR, 0);
            else if (cmp == SAME)
                insert_first(&headR, &tailR, 1);
            else
                division(head1, head2, tail2, &headR, &tailR);

            printf("%s / %s = ", argv[1], argv[3]);

            // Print sign only if result is not zero
            if ((sign1 != sign2) && !(headR && headR->data == 0 && headR->next == NULL))
                printf("-");

            remove_pre_zeros(&headR);
            if (headR == NULL)
                insert_first(&headR, &tailR, 0);
            print_list(headR);
            break;
        }

        default:
            printf("Invalid operator\n");
    }
}

int cla_validation(int argc, char *argv[])
{
    char *operand1 = argv[1];
    char *operator = argv[2];
    char *operand2 = argv[3];

    int i = 0;

    // Check operand1
    if (operand1[0] == '+' || operand1[0] == '-')
        i = 1;

    if (operand1[i] == '\0')
    {
        printf("Invalid Operand\n");
        return FAILURE;
    }

    for (; operand1[i] != '\0'; i++)
    {
        if (!(operand1[i] >= '0' && operand1[i] <= '9'))
        {
            printf("Operands Must Be Integers\n");
            return FAILURE;
        }
    }

    // Check operand2
    i = 0;
    if (operand2[0] == '+' || operand2[0] == '-')
        i = 1;

    if (operand2[i] == '\0')
    {
        printf("Invalid Operand\n");
        return FAILURE;
    }

    for (; operand2[i] != '\0'; i++)
    {
        if (!(operand2[i] >= '0' && operand2[i] <= '9'))
        {
            printf("Operands Must Be Integers\n");
            return FAILURE;
        }
    }

    // Check operator length
    if (operator[1] != '\0')
    {
        printf("Error: Invalid Operator\n");
        return FAILURE;
    }

    // Check valid operator
    if (!(operator[0] == '+' || operator[0] == '-' ||
          operator[0] == 'x' || operator[0] == 'X' ||
          operator[0] == '/'))
    {
        printf("Operator Must Be Arithmetic Operator\n");
        return FAILURE;
    }

    return SUCCESS;
}