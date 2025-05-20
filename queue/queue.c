#include <stdio.h>
#define size 4 

void enqueue();
void dequeue();
void display();
void peek();

int queue[size], front = -1, rear = -1;

int main()
{
    int choice;
    while (1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Exit\nEnter choice : ");
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

// Enqueue function
void enqueue()
{
    int value;
    if (rear == size - 1)
    {
        printf("Queue is full!\n");
        return;
    }
    else
    {
        if (front == -1)
        {
            front = 0; // Set front to 0 if inserting first element
        }
        printf("Enter the element to insert in queue: ");
        scanf("%d", &value);
        queue[++rear] = value;
        printf("%d inserted into the queue.\n", value);
    }
}

// Dequeue function
void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is Empty!\n");
        return;
    }
    else
    {
        printf("%d removed from the queue.\n", queue[front]);
        front++;
        if (front > rear)
        {
            // Reset when queue becomes empty
            front = rear = -1;
        }
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
        printf("Queue Elements: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// Peek function
void peek()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty!\n");
        return;
    }
    else
    {
        printf("Front element: %d\n", queue[front]);
    }
}
