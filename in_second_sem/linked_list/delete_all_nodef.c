#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*link;
};
void delete_all(struct node**);
int main()
{
    struct node* head;
    head = (struct node*)malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;
    struct node*current;
    current = (struct node*)malloc(sizeof(struct node));
    current->data = 44;
    current->link = NULL;
    head->link = current;
    current = (struct node*)malloc(sizeof(struct node));
    current->data = 43;
    current->link = NULL;
    head->link->link = current;
    current = (struct node*)malloc(sizeof(struct node));
    current->data = 41;
    current->link = NULL; 
    head->link->link->link = current;
    delete_all(&head);

}
void delete_all(struct node** head1)
{
    if(*head1 == NULL)
    {
        printf("\nlinked list is empty .");
        exit(0);
    }
    struct node* temp;
    temp = *head1;
    while(temp != NULL)
    {
        temp = temp->link;
        free(*head1);
        *head1 = NULL;
        *head1 = temp;
    }
    if(*head1 ==    NULL)
    {
        printf("linked list is empty.");
    }
}