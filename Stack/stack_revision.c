#include <stdio.h>
#define size 10
void push(int stack[], int *, int);
void pop(int stack[], int *);
void display(int stack[], int *);
int main()
{
    int stack[size]; // stack
    int top = -1;    // let stack is empty
    int n, choice;   // take input
    while (1)
    {
        printf("Stack Operation :");
        printf("\n1. push\n2. pop\n3. display\n4. exit\n");
        printf("Enter your Choice");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to push : ");
            scanf("%d", &n);
            push(stack, &top, n); // calling push function
            break;
        case 2:
            pop(stack, &top); // calling pop function
            break;
        case 3:
            display(stack, &top); // calling displa function
            break;
        case 4:
            return 0;
        default:
            printf("Invalid Choice!");
        }
    }
}
// push function
void push(int stack[], int *top, int n)
{
    if (*top == size - 1)
    {
        printf("\nstack is overflow!\n");
        return;
    }
    else
    {
        stack[++(*top)] = n;
        printf("\n%d is pushed into stack", n);
    }
}
// pop function
void pop(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("Stack is underflow!\n");
        return;
    }
    else
    {
        printf("%d is popped\n", stack[*top]);
        (*top)--;
    }
}
// display function
void display(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("Stack is empty!\n");
        return;
    }
    else
    {
        for (int i = 0; i <= *top; i++)
        {
            printf("%d\n", stack[i]);
        }
    }
}