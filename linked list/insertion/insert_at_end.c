#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
// fnct prtp
void traverse(struct node *head);
void insert_End(struct node **head, int);
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

    // head -> second
    head->data = 14;
    head->next = second;

    // second->third
    second->data = 24;
    second->next = third;

    // third->fourth
    third->data = 34;
    third->next = fourth;

    // fourth->NULL
    fourth->data = 64;
    fourth->next = NULL;

    // traverse function
    traverse(head);
    printf("After added last node\n");
    // at end
    insert_End(&head, 84);
    traverse(head);
    return 0;
}
// traverse function definition
void traverse(struct node *head)
{
    if (head == NULL)
    {
        printf("Node is empty\n");
        return;
    }
    else
    {
        while (head != NULL)
        {
            printf("Element: %d\n", head->data);
            head = head->next;
        }
    }
}
// Inser->End dfn
void insert_End(struct node **head, int value)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
//if we get null on head then update null and return it
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    //now find null and then update
    struct node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}