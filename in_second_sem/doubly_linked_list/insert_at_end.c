// Program to insert the element at the end
#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node*next;
	struct node*prev;
	int data;
};
void insert_at_end(struct node**,struct node**,int );
int main()
{
	struct node*head = NULL;
	struct node*tail = NULL;
	insert_at_end(&head,&tail,45);
	insert_at_end(&head,&tail,4);
	insert_at_end(&head,&tail,41);
	insert_at_end(&head,&tail,42);
	// Printing the linked list so we create a temp pointer
	struct node*temp=NULL;
	temp = head;
	while(temp!=NULL) 
	{
		printf("%d\t",temp->data);
		temp = temp->next;
	}
	
	
	
	
}
void insert_at_end(struct node**head1,struct node**tail1,int newdata)
{
	// Create a new node
	struct node*new_node=NULL;
	new_node=(struct node*)malloc(sizeof(struct node));
	// check memory allocation
	if(new_node == NULL)
	{
		printf(" dynamic Memory is not allocated.");
		exit(1);
	}
	new_node->data = newdata;
	new_node->next = NULL;
	new_node->prev = NULL;
	if(*head1==NULL)
	{
		*head1 = new_node;
		*tail1 = new_node;
	
	}
	else{
	new_node->prev = *tail1;
	new_node->prev->next = new_node;
	*tail1 = new_node;
	}
	


}