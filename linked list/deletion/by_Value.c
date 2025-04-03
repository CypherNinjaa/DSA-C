#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
// fn prtp
void traverse(struct node *head);
void deleteByValue(struct node **head, int);
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
    deleteByValue(&head,44);
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
void deleteByValue(struct node **head, int value)
{
    if (*head == NULL)
        return; // If the list is empty, do nothing

    struct node *temp = *head;

    // If the node to be deleted is the head node
    if (temp->data == value)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    struct node *prev = NULL;

    // Traverse the list to find the node with the given value
    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return; // If value is not found, do nothing

    prev->next = temp->next; // Unlink the node from the list
    free(temp);              // Free memory of the deleted node
}