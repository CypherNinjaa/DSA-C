#include <stdio.h>
#define size 5
// function prototype
void arrayinput(int *);
void push(int stack[], int *, int *);
void display(int stack[], int *);
void pop(int stack[], int *);
// main function
int main()
{
    int top = -1;
    int arr[size];
    int *ptr = arr;
    int stack[size];
    int choice;
    int w = 1;

    if (w == 1)
    {
        while (1)
        {
            printf("1. input\n2. push\n3. display\n4.pop\n5. Exit\n");
            printf("Enter your Choice : ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                // calling input function
                arrayinput(ptr);
                break;
            case 2:
                // calling push function
                push(stack, ptr, &top);
                break;
            case 3:
                // calling display function
                display(stack, &top);
                break;
            case 4:
                // calling stack function
                pop(stack, &top);
                break;
            case 5:
                printf("Exiting!");
                return 0;
            default:
                printf("Invalid input!\n");
            }
            printf("\nPress 1 to continue, 0 to exit: ");
            scanf("%d", &w);
        }
    }
    else
    {
        return 0;
    }
}
// array input
void arrayinput(int *ptr)
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter the [%d] element : ", i);
        scanf("%d", &ptr[i]);
    }
    printf("//Array filled up!\n");
    return;
}
// push operation
void push(int stack[], int *ptr, int *top)
{

    printf("pushing array to stack : \n");
    if (*top == size - 1)
    {
        printf("Your stack is overflow\n");
        return;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            stack[++(*top)] = ptr[i];
        }
        printf("//Pushed successfully!\n");
    }
}
// displaying stack;
void display(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("Your stack is empty!\n");
        return;
    }
    else
    {
        printf("Your stack element : \n");
        for (int i = 0; i <= *top; i++)
        {
            printf("%d\n", stack[i]);
        }
    }
    printf("//Stack printed successfully!\n");
}
// pop function
void pop(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("Stack is underflow\n");
        return;
    }
    else
    {
        printf("%d element is poped\n", stack[*top]);
        (*top)--;
    }
}