#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
// fn prtp
void traverse(struct node *head);
void delete(struct node **head);
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
    delete (&head);
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
void delete(struct node **head)
{
    // if head found null
    if (*head == NULL)
    {
        return;
    }
    // shift -> head & free
    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
}