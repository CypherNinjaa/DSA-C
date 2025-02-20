#include <stdio.h>
#define SIZE 5
void enqueue();
void dequeue();
void display();
void peek();

int queue[SIZE], front = -1, rear = -1;

int main()
{
    int choice;
    while (1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display Queue\n4. Peek\n5. Exit\nEnter your Choice: ");
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
            printf("Invalid input\n");
        }
    }
}

// **Enqueue Function (Sorted Order)**
void enqueue()
{
    if (rear == SIZE - 1)
    {
        printf("Queue is full!\n");
        return;
    }

    int value, i;
    printf("Enter the value to enqueue: ");
    scanf("%d", &value);

    if (front == -1) // If queue is empty
    {
        front = 0;
        queue[++rear] = value;
    }
    else
    {
        // Find correct position
        i = rear;
        while (i >= front && queue[i] > value)
        {
            queue[i + 1] = queue[i]; // Shift elements right
            i--;
        }
        queue[i + 1] = value;
        rear++;
    }
    printf("Inserted Successfully\n");
}

// **Dequeue Function**
void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("%d removed from the queue!\n", queue[front]);
    front++;

    if (front > rear) // Reset when queue is empty
    {
        front = rear = -1;
    }
}

// **Display Function**
void display()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue Elements: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// **Peek Function**
void peek()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Front element: %d\n", queue[front]);
}