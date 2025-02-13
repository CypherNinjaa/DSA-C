#include <stdio.h>
#include <ctype.h> // For isalnum()
#include <string.h>
#define SIZE 100
char stack[SIZE];
int top = -1;
void push(char);
char pop();
int precedence(char);
void infixToPostfix(char[], char[]);
int main()
{
    char infix[SIZE], postfix[SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);
    return 0;
}
void infixToPostfix(char infix[], char postfix[])
{
    int i, j = 0;
    char token;

    for (i = 0; infix[i] != '\0'; i++)
    {
        token = infix[i];
        // If operand, add to postfix output
        if (isalnum(token))
        {
            postfix[j++] = token;
        }
        // If '(', push to stack
        else if (token == '(')
        {
            push(token);
        }
        // If ')', pop until '(' is found
        else if (token == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            pop(); // Remove '(' from stack
        }
        // If operator, pop higher precedence operators first
        else
        {
            while (top != -1 && precedence(stack[top]) >= precedence(token))
            {
                postfix[j++] = pop();
            }
            push(token);
        }
    }

    // Pop remaining operators
    while (top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // Null terminate string
}
// Push to stack
void push(char c)
{
    stack[++top] = c;
}
// Pop from stack
char pop()
{
    return stack[top--];
}
// Define operator precedence
int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}
