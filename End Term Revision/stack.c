#include <stdio.h>
#include <stdlib.h>
#define size 10

int top = -1, n, choice;
int stack[size];

// Function prototypes
void push();
void pop();
void peek();
void display();

int main()
{

    while (1)
    {
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
            break;
        }
    }
    return 0;
}

// Push function
void push()
{
    if (top == size - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    printf("Enter the element: ");
    scanf("%d", &n);
    stack[++top] = n;
    system("cls");
    printf("%d pushed onto stack\n", n);
}

// Pop function
void pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        return;
    }
    int popped = stack[top--];
    system("cls");
    printf("%d popped from stack\n", popped);
}

// Peek function
void peek()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    system("cls");
    printf("Top element is: %d\n", stack[top]);
}

// Display function
void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}