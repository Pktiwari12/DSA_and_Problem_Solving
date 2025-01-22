#include<stdio.h>
#include<stdlib.h>
// structure of node
struct node{
    int data;
    struct node* next;
    struct node*prev;

};
void insert_at_beg(struct node**,struct node**,int );
int main()
{
	// head and tail pointer declaration which is required
    struct node*head=NULL;
    struct node*tail=NULL;
    insert_at_beg(&head,&tail,45);
	insert_at_beg(&head,&tail,415);
	insert_at_beg(&head,&tail,145);
	insert_at_beg(&head,&tail,5);    
    //printing the dll by traversing
    struct node* temp = head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp = temp->next;
    }
	return 0;

}
void insert_at_beg(struct node** head1,struct node**tail1,int new_data){
    struct node*new_node=NULL;
    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        printf(" Dynamic Memory is not allocated");
        exit(1);
    }
    // Creation a new node
    new_node->data = new_data;
    new_node->next = NULL;
    new_node->prev = NULL;
    // If dll is empty then create a linked list
    if(*head1 == NULL){
        *head1 = new_node;
        *tail1 = new_node;

    }
    // otherwise update the head pointer
    else{
        new_node->next = *head1;
        new_node->next->prev = new_node;
        *head1 = new_node;



    }



}