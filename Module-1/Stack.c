#include <stdio.h>
#define size 10
void push(int stack[], int *);
void pop(int stack[], int *);
void peek(int stack[], int *);
void display(int stack[], int *);
int main()
{
    int stack[size];
    int top = -1;
    int choice;
    while (1)
    {
        printf("1. push\n2. pop\n3. peek\n4. display\n5. Exit\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push(stack, &top);
            break;
        case 2:
            pop(stack, &top);
            break;
        case 3:
            peek(stack, &top);
            break;
        case 4:
            display(stack, &top);
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice\n");
            break;
        }
        
    }
    return 0;
}
// Push function
void push(int stack[], int *top)
{
    int n;
    if (*top == size - 1)
    {
        printf("Stack overflow!\n");
        return;
    }
    else
    {
        printf("Enter the Element : ");
        scanf("%d", &n);
        stack[++(*top)] = n;
        printf("%d pushed into stack\n", n);
    }
}
// Pop function
void pop(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("Stack underflow!\n");
        return;
    }
    else
    {
        printf("%d is poped successfully", stack[*top]);
        (*top)--;
    }
}
// peek function
void peek(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    else
    {
        printf("Top Element = %d\n", stack[*top]);
    }
}
// Display function
void display(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    else
    {
        printf("Stack element : \n");

        for (int i = *top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}