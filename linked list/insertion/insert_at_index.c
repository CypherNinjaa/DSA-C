#include <stdio.h>
#include <stdlib.h>
struct node
// structutre
{
    int data;
    struct node *next;
};
// functn proto
void traverse(struct node *head);
void insertAtIndex(struct node **head, int value, int index);
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

    // fourht->NULL
    fourth->data = 64;
    fourth->next = NULL;

    // traverse function
    traverse(head);

    // Insert  at a specific index
    insertAtIndex(&head, 12, 2);
    printf("after inserting\n");
    traverse(head);
    return 0;
}

//traverse definition
void traverse(struct node *head)
{
    while (head != NULL)
    {
        printf("Element: %d\n", head->data);
        head = head->next;
    }
}

//insert at index
void insertAtIndex(struct node** head,int value,int index){
    struct node *newNode;
    newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=value;

    //if index input 0
    if (index == 0)
    {
        newNode->next = *head;
        *head = newNode;
        return;

    }

    //finding 
    struct node *temp = *head;
    for (int i = 0; temp != NULL && i < index - 1; i++)
    {
        temp = temp->next;
    }

    //index not found
    if (temp == NULL)
    {
        printf("Index out of bounds\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}