#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack structure
typedef struct
{
    char *items[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack *s)
{
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *s)
{
    return s->top == -1;
}

// Function to push an element onto the stack
void push(Stack *s, char *str)
{
    if (s->top == MAX - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    s->items[++(s->top)] = str;
}

// Function to pop an element from the stack
char *pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow\n");
        return NULL;
    }
    return s->items[(s->top)--];
}

// Function to convert postfix to infix
void postfixToInfix(char *postfix)
{
    Stack s;
    initStack(&s);

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char ch = postfix[i];

        // If the character is an operand, push it onto the stack
        if (isalnum(ch))
        {
            char *operand = (char *)malloc(2 * sizeof(char));
            operand[0] = ch;
            operand[1] = '\0';
            push(&s, operand);
        }
        // If the character is an operator
        else
        {
            char *op2 = pop(&s);
            char *op1 = pop(&s);

            if (op1 == NULL || op2 == NULL)
            {
                printf("Invalid postfix expression\n");
                return;
            }

            // Allocate memory for the new infix expression
            char *expr = (char *)malloc(strlen(op1) + strlen(op2) + 4);
            sprintf(expr, "(%s%c%s)", op1, ch, op2);

            // Push the new expression onto the stack
            push(&s, expr);

            // Free the old operands
            free(op1);
            free(op2);
        }
    }

    // The final element in the stack is the infix expression
    char *result = pop(&s);
    if (!isEmpty(&s))
    {
        printf("Invalid postfix expression\n");
        return;
    }

    printf("Infix expression: %s\n", result);
    free(result);
}

int main()
{
    char postfix[MAX];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    postfixToInfix(postfix);

    return 0;
}