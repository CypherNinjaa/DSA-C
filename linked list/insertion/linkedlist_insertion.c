#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

// traverse prototype
void traverse(struct node *head);
void insertatbegining(struct node **head, int value);
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

    // link -> second
    head->data = 10;
    head->next = second;

    // second -> third
    second->data = 12;
    second->next = third;

    // third-> fourth
    third->data = 14;
    third->next = fourth;

    // fourth -> null
    fourth->data = 16;
    fourth->next = NULL;
    // call traverse
    traverse(head);
    insertatbegining(&head, 8);
    printf("Linked list ater insertion\n");
    traverse(head);

    return 0;
}
// traverse function definition
void traverse(struct node *head)
{
    while (head != 0)
    {
        printf("Element: %d\n", head->data);
        head = head->next;
    }
}

// insertion function definitrion
void insertatbegining(struct node **head, int value)
{
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=*head;
    *head=newnode;
}