#include <stdio.h>
#include <stdlib.h>
sturct node{
    int data;
    struct node* next;
};
int main(){
    struct node* head;
    struct node* second;
    struct node* third;
    //allocate memory
    head = (struct node *) malloc(sizeof(struct node));
    second = (struct node *) malloc(sizeof(struct node));
    third = (struct node *) malloc(sizeof(struct node));

    //link first and second
    head->data=7;
    head->next=second;

    //link second and third
    second->data=44;
    second->next=third;

    //link last
    third->data=444;
    head->next=NULL;

    return 0;
}