#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*link;
};
int printlinkedlist(struct node*);
void insert_at_end(struct node**,int);
// for deleting last node
// we should have two pointer specific  is traversing and second is deleting node to free
void delete_last_node(struct node**head1)
{
	struct node*ptr = NULL;
	ptr = *head1;
	struct node*ptr2=NULL;
	ptr2 = *head1;
	if(head1 == NULL)
	{
		printf("The linked list is empty.");
	}
	else if(ptr->link = NULL)
	{
		*head1 = NULL;
		free(ptr);
		ptr = NULL;
	}
	else
	{
		
		while(ptr->link != NULL)
		{
			ptr2 = ptr;
			ptr = ptr->link;
						
		}	
		ptr2->link = NULL;
		free(ptr);
		ptr = NULL;
	}
}
int main()
{
	struct node*head = NULL;
	insert_at_end(&head,45);
	//insert_at_end(&head,43);
	//int n;
	//insert_at_end(&head,44);
	//scanf("%d",&n);
	int length = printlinkedlist(head);
	printf("\nlength = %d",length);
	delete_last_node(&head);
	length = printlinkedlist(head);
	printf("\nlength = %d",length);
}



// For input data into linked list
void insert_at_end(struct node**head1,int newdata)		//double is used because if linked list is empty then we store the address of specific  node in the head of main function
{
	if(*head1 == NULL)						// LIst is empty
	{
		struct node*temp;
		temp = (struct node*)malloc(sizeof(struct node));			// Creating specific  new node
		if(temp==NULL)
		{
			printf("Memory is not allocated.");
			exit(0);
		}
		temp->data = newdata;
		temp->link = NULL;
		*head1 = temp;
		
	}
	else{
	struct node*temp=NULL;					// For creating a new node
	temp = (struct node*)malloc(sizeof(struct node));
	if(temp == NULL)
	{
		printf("Memory is not allocated .");
		exit(0);
	}
	temp->data = newdata;
	temp->link = NULL;
	struct node*ptr = NULL;					// For travershing means finding the last node in existing linked list
	ptr = *head1;
	while(ptr->link!=NULL)
	{
		ptr = ptr->link;
	}
	ptr->link = temp;
	}
	printf("insert at end successfully");
}



// Printing the data and finding the length

/*int printlinkedlist(struct node*head)
{
	int count =0;
	if(head == NULL)
	{
		printf("The linked list is empty.");
	}
	struct node *ptr=NULL;
	ptr  = head;
	printf("\nThe linked list elements =\n");
	while(ptr!=NULL)
	{
		
		count++; 
		printf("%d\t",ptr->data);
		ptr = ptr->link;
		
	}
	return count;
}*/


int printlinkedlist(struct node*head)
{
	int count =0;
	if(head == NULL)
	{
		printf("The linked list is empty.");
	}
	struct node *ptr=NULL;
	ptr  = head;
	printf("\nThe linked list elements =\n");
	while(ptr!=NULL)
	{
		count++; 
		printf("%d\t",ptr->data);
		ptr = ptr->link;
	}
	return count;
}

