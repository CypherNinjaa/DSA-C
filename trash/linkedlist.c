#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void traverse(struct node *ptr);

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    // allocate memory
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 4;
    head->next = second;

    second->data = 44;
    second->next = third;

    third->data = 444;
    third->next = fourth;

    fourth->data = 4444;
    fourth->next = NULL;

    traverse(head);
    return 0;
}

void traverse(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}