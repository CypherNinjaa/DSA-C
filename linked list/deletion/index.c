#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
// fn prtp
void traverse(struct node *head);
void deleteAtIndex(struct node **head, int index);
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
    deleteAtIndex(&head, 2);
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
void deleteAtIndex(struct node **head, int index)
{
    // if head is null
    if (*head == NULL)
    {
        return;
    }

    struct node *temp = *head;

    // if index is 0
    if (index == 0)
    {
        *head = (*head)->next;
        free(temp);
        return;
    }

    struct node *prev = NULL;
    int i = 0;
    while (temp != NULL && i < index)
    {
        prev = temp;
        temp = temp->next;
        i++;
    }
    // if temp=null -> last index
    if (temp == NULL)
    {
        return;
    }
    // unlink the node
    prev->next = temp->next;
    free(temp);
}