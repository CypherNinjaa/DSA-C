#include <stdio.h>
#define size 10 // max size of stack
void push(int stack[], int *, int);
void pop(int stack[], int *top);
void display(int stack[], int);
int main()
{
    int stack[size];
    int top = -1;
    // take input
    int n, a;
    while (1)
    {
        printf("\nStack Operation\n");
        printf("1. push\n2. pop\n3. display\n4. exit\n");
        printf("Enter your choice : ");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("Enter the elemet to push : ");
            scanf("%d", &n);
            // call push function
            push(stack, &top, n);
            break;
        case 2:
            // call pop function
            pop(stack, &top);
        case 3:
            // call display function
            display(stack, top);
            break;
        case 4:
            return 0;
        default:

            printf("Invalid Choice\n");
        }
    }
}
// push function
void push(int stack[], int *top, int n)
{
    if (*top == size - 1)
    {
        printf("Stack overflow!");
        return;
    }
    else
        stack[++(*top)] = n;
    printf("%d pushed into stack\n", n);
}
// display function
void display(int stack[], int top)
{
    if (top== -1)
    {
        printf("\nStack is Empty!");
        return;
    }
    else
        printf("Stack element : \n");
    for (int i = 0; i <= top; i++)
    {
        printf("%d\n", stack[i]);
    }
}
// Pop function
void pop(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("Satck underflow!");
        return;
    }
    else

        printf("\n%d Popped from stack\n", stack[*top]);
    (*top)--;
}