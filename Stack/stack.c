#include <stdio.h>
#define size 10 // max size of stack

void push(int stack[], int *top, int);
void pop(int stack[], int *top);
void display(int stack[], int *top);

int main()
{
    int stack[size];
    int top = -1; // let stack is empty
    int n, Choice;

    while (1)
    {
        printf("\nStack Operation\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &Choice);

        switch (Choice)
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
            display(stack, &top);
            break;
        case 4:
            return 0;
        default:
            printf("Invalid Choice\n");
        }
    }
}

// Push function
void push(int stack[], int *top, int n)
{
    if (*top == size - 1)
    {
        printf("Stack overflow!\n");
        return;
    }
    stack[++(*top)] = n;
    printf("%d pushed into stack\n", n);
}

// Display function
void display(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("\nStack is Empty!\n");
        return;
    }

    printf("Stack elements:\n");
    for (int i = *top; i >= 0; i--) // Display from top to bottom
    {
        printf("%d\n", stack[i]);
    }
}

// Pop function
void pop(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("Stack underflow!\n"); // Fixed typo
        return;
    }

    printf("%d popped from stack\n", stack[*top]);
    (*top)--;
}
