#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*link;
};
int printlinkedlist(struct node*);
void insert_at_end(struct node**,int );
void delete_at_certain(struct node**head1);
void delete_last_node(struct node**);
int main()
{
    struct node*head = NULL;
    insert_at_end(&head,45);
    insert_at_end(&head,34);
    insert_at_end(&head,24);
    insert_at_end(&head,14);
    insert_at_end(&head,4);
    int length = printlinkedlist(head);
    printf("\n length of linked list is  = %d ",length);
    delete_at_certain(&head);
    printf("\nAfter deleting the specific  element of linked list.");
    length = printlinkedlist(head);
    printf("\nlength of linked list is  = %d",length);
    delete_last_node(&head);
    printf("\nAfter deleting the last element of linked list.");
    length = printlinkedlist(head);
    printf("\nlength of linked list is  = %d",length);


}

// for deleting specific  node
void delete_at_certain(struct node**head1)
{
    struct node*ptr;					// this pointer point to specific  node
    ptr = *head1;
    *head1 = ptr->link;					// now head pointer is modified to the addrees of second node address
    free(ptr);
    ptr = NULL;
}



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
}



// Printing the data and finding the length

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
