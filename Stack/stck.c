#include <stdio.h>
#define SIZE 10 // Max size of stack

void push(int stack[], int *top, int n);
void pop(int stack[], int *top);
void display(int stack[], int top);

int main()
{
    int stack[SIZE];
    int top = -1; // Stack is initially empty
    int choice, n;

    while (1)
    {
        printf("\nStack Operations:\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to push: ");
            scanf("%d", &n);
            push(stack, &top, n);
            break;
        case 2:
            pop(stack, &top);
            break;
        case 3:
            display(stack, top);
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
}

// Push function
void push(int stack[], int *top, int n)
{
    if (*top == SIZE - 1)
    {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++(*top)] = n;
    printf("%d pushed into stack\n", n);
}

// Pop function
void pop(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("Stack Underflow!\n");
        return;
    }
    printf("%d popped from stack\n", stack[(*top)--]);
}

// Display function
void display(int stack[], int top)
{
    if (top == -1)
    {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
