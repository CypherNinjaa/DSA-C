#include <stdio.h>
#include <stdlib.h>
#define size 14
int queue[size], n, choice, front = -1, rear = -1;
void enqueue();
void dequeue();
void peek();
void display();
int main()
{
    while (1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Exit\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            return 0;
        default:
            printf("Invalid Input\n");
            break;
        }
    }
    return 0;
}
// enqueue function
void enqueue()
{
    if (rear == size - 1)
    {
        printf("Queue is full!\n");
        return;
    }
    if (front = -1)
    {
        front = 0;
    }
    printf("Enter the element : ");
    scanf("%d", &n);
    queue[++rear] = n;
    system("cls");
    printf("%d inserted into queue\n", n);
}
// dequeue function
void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("%d dequeued from queue\n", queue[front]);
    front++;
    if (front > rear)
    {
        front = rear = -1;
    }
}
// peek function
void peek()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return;
    }
    system("cls");
    printf("Front element : %d\n", queue[front]);
}
// display function
void display()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return;
    }
    system("cls");
    printf("Queue element :");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}