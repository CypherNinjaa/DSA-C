#include <stdio.h>
#define SIZE 5

int queue[SIZE], front = -1, rear = -1;

// Function to insert an element in the queue (Enqueue)
void enqueue(int value)
{
    if (rear == SIZE - 1)
    {
        printf("Queue is Full!\n");
    }
    else
    {
        if (front == -1)
            front = 0; // Set front to 0 if inserting first element
        queue[++rear] = value;
        printf("%d inserted into the queue.\n", value);
    }
}

// Function to remove an element from the queue (Dequeue)
void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is Empty!\n");
    }
    else
    {
        printf("%d removed from the queue.\n", queue[front]);
        front++;
        if (front > rear)
        { // Reset when queue becomes empty
            front = rear = -1;
        }
    }
}

// Function to display the queue elements
void display()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is Empty!\n");
    }
    else
    {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    enqueue(40);
    enqueue(50);
    enqueue(60);
    display();
    return 0;
}
