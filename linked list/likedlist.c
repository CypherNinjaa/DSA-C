#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void traverse(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}
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

    // link first and second
    head->data = 7;
    head->next = second;

    // link second and third
    second->data = 44;
    second->next = third;

    // link third and fourth
    third->data = 44;
    third->next = fourth;

    // link last
    fourth->data = 66;
    fourth->next = NULL;

    traverse(head);
    return 0;
}