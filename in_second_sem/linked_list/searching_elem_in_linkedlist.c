#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*link;
};
int search_element(struct node*,int);
int main()
{
    struct node*head=NULL;
    head = (struct node*)malloc(sizeof(struct node));
    head->data = 54;
	head->link = NULL;
	struct node *current;
    current = (struct node*)malloc(sizeof(struct node));
    current->data = 55;
    current->link = NULL;
    head->link = current;
        current = (struct node*)malloc(sizeof(struct node));
    current->data = 56;
    current->link = NULL;
    head->link->link = current;
        current = (struct node*)malloc(sizeof(struct node));
    current->data = 57;
    current->link = NULL;
    head->link->link->link = current;
    
    int index = search_element(head,57);
    printf("\nThe position of the element in the linked list is =  %d",index);
    return 0;

}
int search_element(struct node *head1,int requiredata)
{
    if(head1 == NULL)
    {
        printf("\nthe linked list is empty");
        return 0;

    }
    struct node *temp;
    temp = head1;
    int count = 0;
    while(temp != NULL)
    {
        count++;
        if(temp->data == requiredata)
        {
            return count;
        }
        temp = temp->link;
    }
    // if data is not encountered that send alert message
    printf("\nData is not found. please enter vaild data.");
    return 0;

    

}
