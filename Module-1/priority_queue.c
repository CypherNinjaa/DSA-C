#include <stdio.h>
#define size 10
void enqueue();
void dequeue();
void peek();
void display();
int queue[size];
int front = -1, rear = -1;
int main()
{

    int choice;
    while (1)
    {
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\nEnter your Choice : ");
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
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice!,try again\n");
            break;
        }
    }
    return 0;
}
// enqueue Function
void enqueue()
{
    int value;
    if (rear == size - 1)
    {
        printf("Queue is overflow!\n");
        return;
    }

    if (front == -1)
    {
        front = 0;
    }
    printf("Enter element to insert : ");
    scanf("%d", &value);
    queue[++rear] = value;
    printf("%d is inserted successfully\n", value);
    for (int i = front; i <= rear; i++)
    {
        if (queue[i] > value)
        {
            queue[i + 1] = queue[i];
        }
        else
        {
            break;
        }
    }
}
// dequeue function
void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty!\n");
        return;
    }
    else
    {
        printf("%d Removed from the queue\n", queue[front]);
        front++;
        if (front > rear)
        {
            front = rear = -1;
        }
    }
}
// peek function
void peek()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty!\n");
        return;
    }
    else
    {
        printf("Front element : %d\n", queue[front]);
    }
}
// Display function
void display()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty!\n");
        return;
    }
    else
    {
        printf("Queue element : ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}