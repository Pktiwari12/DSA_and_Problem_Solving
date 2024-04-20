// Traversing in the linked list{Counting the nodes}
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* link;
};
int counting_nodes(struct node*head)
{
	int count = 0;					// counter variable (for length of linked list)
	if(head == NULL)
	{
		printf("linked list is empty.");
		return count;
	}
	struct node*ptr =head;
	while(ptr!=NULL){
		count++;
		ptr = ptr->link;			// Here we are updating ptr in every iteration 
	}
	return count;
}
void printlinkedlist(struct node*head)
{
	if(head == NULL)
	{
		printf("The linked list is empty.");
	}
	struct node *ptr=NULL;
	ptr  = head;
	printf("The linked list elements =\n");
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr = ptr->link;
	}
}

int main()
{
	struct node *head = NULL;
	head = (struct node*)malloc(sizeof(struct node));
	head->data = 45;
	head->link = NULL;
	struct node*current = NULL;
	current = (struct node*)malloc(sizeof(struct node));			// Second node
	current->data = 98;
	current->link = NULL;
	head->link = current;						// linking node to its previous node (specific )
	current = (struct node*)malloc(sizeof(struct node));		// Third node
	current->data = 3;
	current->link = NULL;
	head->link->link = current;						// linking node to its previous node(Second)
	//printf("%d\t%d\t%d",head->data,head->link->data,head->link->link->data);
	current= (struct node*)malloc(sizeof(struct node));			// Forth node
	current->data = 5;
	current->link = NULL;
	head->link->link->link = current;
	current = (struct node*)malloc(sizeof(struct node));		//fifth node 
	current->data = 211;
	current->link =NULL;
	head->link->link->link->link = current;
	printlinkedlist(head);
	//printf("\n%d\t%d\t\t%d\t%d",head->data,head->link->data,head->link->link->data,head->link->link->link->data);
	int n = counting_nodes(head);
	printf("\nThe number of node is \t=%d",n);
	return 0;
}
	
	
 