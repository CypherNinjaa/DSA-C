#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
// fn prtp
void traverse(struct node *head);
void deleteAtIndex(struct node **head);
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

    // link second and third
    third->data = 44;
    third->next = fourth;

    // link last
    fourth->data = 66;
    fourth->next = NULL;
    // traverse fn call
    traverse(head);
    printf("After deleting\n");
    deleteAtIndex(&head);
    traverse(head);
    return 0;
}
// traverse fn dfn
void traverse(struct node *head)
{
    while (head != NULL)
    {
        printf("Element : %d\n", head->data);
        head = head->next;
    }
}

// delet fn dfn
void deleteAtIndex(struct node **head)
{
    // if head is null
    if (*head == NULL)
    {
        return;
    }

    struct node *temp = *head;

    // if list has one node
    if (temp->next == NULL)
    {
        free(temp);
        *head = NULL;
        return;
    }

    struct node *prev = NULL;
    // find last node
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
 
    // unlink the node
    prev->next = NULL;
    free(temp);
}