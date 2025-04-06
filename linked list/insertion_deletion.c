#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// Function prototypes
void traverse(struct node *head);
void insertatbegining(struct node **head, int value);
void insertAtIndex(struct node **head, int value, int index);
void insert_End(struct node **head, int value);
void deleteAtBeginning(struct node **head);
void deleteAtEnd(struct node **head);
void deleteAtIndex(struct node **head, int index);

int main()
{
    struct node *head = NULL;
    int choice, value, index;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Traverse\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Index\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at End\n");
        printf("7. Delete at Index\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            traverse(head);
            break;
        case 2:
            printf("Enter value to insert at beginning: ");
            scanf("%d", &value);
            insertatbegining(&head, value);
            break;
        case 3:
            printf("Enter value to insert at end: ");
            scanf("%d", &value);
            insert_End(&head, value);
            break;
        case 4:
            printf("Enter value and index to insert: ");
            scanf("%d %d", &value, &index);
            insertAtIndex(&head, value, index);
            break;
        case 5:
            deleteAtBeginning(&head);
            break;
        case 6:
            deleteAtEnd(&head);
            break;
        case 7:
            printf("Enter index to delete: ");
            scanf("%d", &index);
            deleteAtIndex(&head, index);
            break;
        case 8:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Traverse function
void traverse(struct node *head)
{
    if (head == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

    printf("Linked list elements:\n");
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Insert at beginning
void insertatbegining(struct node **head, int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = *head;
    *head = newnode;
}

// Insert at end
void insert_End(struct node **head, int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert at index
void insertAtIndex(struct node **head, int value, int index)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;

    if (index == 0)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct node *temp = *head;
    for (int i = 0; temp != NULL && i < index - 1; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Index out of bounds\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete at beginning
void deleteAtBeginning(struct node **head)
{
    if (*head == NULL)
    {
        printf("List is already empty.\n");
        return;
    }

    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("First node deleted.\n");
}

// Delete at end
void deleteAtEnd(struct node **head)
{
    if (*head == NULL)
    {
        printf("List is already empty.\n");
        return;
    }

    struct node *temp = *head;

    // Only one node
    if (temp->next == NULL)
    {
        free(temp);
        *head = NULL;
        printf("Last node deleted.\n");
        return;
    }

    // Traverse to second last
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    printf("Last node deleted.\n");
}

// Delete at index
void deleteAtIndex(struct node **head, int index)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = *head;

    // Deleting first node
    if (index == 0)
    {
        *head = temp->next;
        free(temp);
        printf("Node at index 0 deleted.\n");
        return;
    }

    for (int i = 0; temp != NULL && i < index - 1; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        printf("Index out of bounds.\n");
        return;
    }

    struct node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    printf("Node at index %d deleted.\n", index);
}
