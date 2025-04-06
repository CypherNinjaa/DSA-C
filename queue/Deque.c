#include <stdio.h>
#define SIZE 10

int deque[SIZE];
int front = -1, rear = -1;

void insertFront(int value);
void insertRear(int value);
void deleteFront();
void deleteRear();
void getFront();
void getRear();
void display();

int main()
{
    int choice, value;
    while (1)
    {
        printf("\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Get Front\n6. Get Rear\n7. Display\n8. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert at front: ");
            scanf("%d", &value);
            insertFront(value);
            break;
        case 2:
            printf("Enter value to insert at rear: ");
            scanf("%d", &value);
            insertRear(value);
            break;
        case 3:
            deleteFront();
            break;
        case 4:
            deleteRear();
            break;
        case 5:
            getFront();
            break;
        case 6:
            getRear();
            break;
        case 7:
            display();
            break;
        case 8:
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}

int isFull()
{
    return ((front == 0 && rear == SIZE - 1) || (front == rear + 1));
}

int isEmpty()
{
    return (front == -1);
}

void insertFront(int value)
{
    if (isFull())
    {
        printf("Deque is Full!\n");
        return;
    }
    if (isEmpty())
    {
        front = rear = 0;
    }
    else if (front == 0)
    {
        front = SIZE - 1;
    }
    else
    {
        front--;
    }
    deque[front] = value;
    printf("%d inserted at front.\n", value);
}

void insertRear(int value)
{
    if (isFull())
    {
        printf("Deque is Full!\n");
        return;
    }
    if (isEmpty())
    {
        front = rear = 0;
    }
    else if (rear == SIZE - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    deque[rear] = value;
    printf("%d inserted at rear.\n", value);
}

void deleteFront()
{
    if (isEmpty())
    {
        printf("Deque is Empty!\n");
        return;
    }
    printf("%d deleted from front.\n", deque[front]);
    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == SIZE - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

void deleteRear()
{
    if (isEmpty())
    {
        printf("Deque is Empty!\n");
        return;
    }
    printf("%d deleted from rear.\n", deque[rear]);
    if (front == rear)
    {
        front = rear = -1;
    }
    else if (rear == 0)
    {
        rear = SIZE - 1;
    }
    else
    {
        rear--;
    }
}

void getFront()
{
    if (isEmpty())
    {
        printf("Deque is Empty!\n");
    }
    else
    {
        printf("Front element: %d\n", deque[front]);
    }
}

void getRear()
{
    if (isEmpty())
    {
        printf("Deque is Empty!\n");
    }
    else
    {
        printf("Rear element: %d\n", deque[rear]);
    }
}

void display()
{
    if (isEmpty())
    {
        printf("Deque is Empty!\n");
        return;
    }
    printf("Deque elements: ");
    int i = front;
    while (1)
    {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}
