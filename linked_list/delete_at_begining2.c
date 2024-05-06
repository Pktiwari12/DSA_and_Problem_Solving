#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*link;
};
// function to printing and counting the linked list nodes
int printlinkedlist(struct node*head1);
void insert_at_end(struct node**head1,int data1);
void delete_at_beg(struct node**head1);
int main()
{
	struct node*head = NULL;
	insert_at_end(&head,42);
	insert_at_end(&head,43);
	insert_at_end(&head,44);
	insert_at_end(&head,45);
	printf("\nThe linked list is :\n");
	int length = printlinkedlist(head);
	printf("\n%d\n",length);
	printf("\nAfter the delteting the first node.\n");
	delete_at_beg(&head);
	// recieving the length of linked list
	length = printlinkedlist(head);
	printf("\n%d\n",length);
}
void insert_at_end(struct node**head1,int data1)
{
	struct node* new_node = NULL;
	new_node = (struct node*)malloc(sizeof(struct node));
	if(new_node == NULL){
		printf("Memory is not allocated.\n");
		
	}
	else
	{
		new_node->data = data1;
		new_node->link = NULL;\
		// if linked list is empty 
		if(*head1 == NULL)
		{
			*head1 = new_node;
		}
		else{
			// for traversing the linked list
			struct node*temp = *head1;
			while(temp->link != NULL)
			{
				temp = temp->link;
			}
			temp->link = new_node;
		}
	}
}

// function to printing and counting the linked list nodes
int printlinkedlist(struct node*head1)
{
	int count = 0;
	if(head1 == NULL)
	{
		printf("linked list is empty.");
		return count;
	}
	else{
		printf("\n");
		struct node*temp = head1;
		while(temp != NULL)
		{
			count++;
			printf("%d\t",temp->data);
			temp = temp->link;
		}
		printf("\n");
		return count;
		
	}
}

// function to delete the first node of the linked list
void delete_at_beg(struct node**head1)
{
	if(*head1 == NULL){
		printf("The linked list is already empty.");
	}
	else
	{
		// for free the deleted the node
		struct node*temp = *head1;
		*head1 = temp->link;
		free(temp);
		temp = NULL;
	}
}
