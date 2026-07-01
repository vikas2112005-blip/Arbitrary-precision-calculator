/* Name: Vikas C
   Date: 30-06-2026
  
*/

#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Return values
#define SUCCESS		1
#define FAILURE		0

// Comparison results
#define SAME		0
#define OPERAND1	1
#define OPERAND2	2

// Doubly linked list node
typedef struct node
{
    struct node *prev;   // pointer to previous node
    int data;            // digit data
    struct node *next;   // pointer to next node
} node;

// Arithmetic operations
int addition(node *tail1, node *tail2, node **headR, node **tailR);
void subtraction(node *tail1, node *tail2, node **headR, node **tailR);
void multiplication(node *tail1, node *tail2, node **headR, node **tailR);
void division(node *head_l1, node *head_opr2, node *tail_opr2, node **headR, node **tailR);

// Command line argument validation
int cla_validation(int argc, char *argv[]);

// Create linked list from string
void create_list(char *opr, node **head, node **tail);

// List operations
int insert_first(node **head, node **tail, int data);
int insert_last(node **head, node **tail, int data);
int delete_list(node **head, node **tail);
void print_list(node *head);

// Utility functions
int compare_list(node *head1, node *head2);
int list_len(node *head);
void remove_pre_zeros(node **head);
void free_list(node **head);

// Operand validation
int validation_opd(char *str);

#endif