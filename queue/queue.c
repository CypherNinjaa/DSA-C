#include <stdio.h>
#define size 5
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
        printf("\n1. enqueue\n2. dequeue\n3. diplay\n4. peek\n5. Exit\nEnter choice : ");

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
            printf("Invalid Input");
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
            front = 0; // set front to 0 if inserting first element
        }
        printf("Enter the element to insert in queue : ");
        scanf("%d", &value);
        queue[++rear] = value;
        printf("%d inserted into the queue.\n", value);
    }
}

// Dequeue Function
void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is Empty!");
        return;
    }
    else
    {
        printf("%d removed from the queue.\n", queue[front]);
        front++;
        if (front > rear)
        {
            // reset when queue becomes empty
            front = rear = -1;
        }
    }
}

// Display function;
void display()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty!\n");
        return;
    }
    else
    {
        printf("Queue Elements : \n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
            
        }
    }
}

// peek function
void peek()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty!");
        return;
    }
    else
    {
        printf("Front element : %d", queue[front]);
    }
}