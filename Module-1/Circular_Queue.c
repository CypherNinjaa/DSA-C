#include <stdio.h>
#define size 10
void enqueue();
void dequeue();
void peek();
void display();
int front = -1, rear = -1;
int queue[size];
int main()
{
    int choice;
    while (1)
    {
        printf("1. enqueue\n2. dequeue\n3. peek\n4. display\n5. exit\nEnter your choice : ");
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
            printf("Invalid choice!\n");
            break;
        }
    }
    return 0;
}
// Enqueue function
void enqueue()
{
    int value;
    if ((rear + 1) % size == front)
    {
        printf("Queue is overflow\n");
        return;
    }

    printf("Enter the value to insert : ");
    scanf("%d", &value);

    if (front == -1)
    {
        front = 0;
    }

    rear = (rear + 1) % size;
    queue[rear] = value;

    printf("%d inserted successfully!\n", value);
}

// dequeue function
void dequeue()
{
    if (front == -1)
    {
        printf("Queue underflow!\n");
        return;
    }

    printf("%d removed Successfully!\n", queue[front]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % size;
    }
}
// Peek function
void peek()
{
    if (front == -1)
    {
        printf("Queue is empty!\n");
        return;
    }
    else
    {
        printf("Front element : %d\n", queue[front]);
    }
}
//  Display Queue
void display()
{
    if (front == -1)
    {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Circular Queue Elements: ");
    int i = front;
    while (1)
    {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % size;
    }
    printf("\n");
}