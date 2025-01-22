// Optimal insertion code . O(1)
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
void printlinkedlist(struct node*);
struct node*insert_at_end(struct node*ptr,int newdata)
{
	struct node*temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = newdata;
	temp->link = NULL;
	ptr->link = temp;
	ptr = temp;
	return ptr;
	
}
int main()
{
	struct node*head = NULL;		// in main fxn, I want only three thing head,data,insertfxn
	head = (struct node*)malloc(sizeof(struct node));		// here we create specific  node .I dont want to create . I want to input and output like 'insertion by traversing' with this optimal formula
	head->data = 56;
	head->link = NULL;
	struct node*ptr = head;
	ptr = insert_at_end(ptr,45);						// In main fxn,I dont want to crate and store any address in ptr 
	ptr = insert_at_end(ptr,67);
	ptr = insert_at_end(ptr,34);
	ptr = insert_at_end(ptr,90);
	printlinkedlist(head);
	return 0;
}
void printlinkedlist(struct node*head)
{
	struct node*temp;
	temp = head;
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp = temp->link;
	}
}
// In optimal code we want to create only head in main method and pass head and data to insert_fun . Then responsiblity on insert_fun that where data store and when create specific  node and assign the address  of node


/*//int count=0;
/void printlinkedlist(struct node*);
struct node* insert_at_end(struct node*ptr,int data)
{
	if(ptr==NULL)
	{
		ptr = (struct node*)malloc(sizeof(struct node));
		ptr->data = data;
		ptr->link = NULL;
		printf("\n if of insert at end");
		return ptr;
	}
	struct node*temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->link = NULL;
	ptr->link = temp;
	return (temp);
	//count = count++;
}
int main()
{
	struct node* head = NULL;
	 insert_at_end(head or &head,44);
	 insert_at_end(head,74);
	 insert_at_end(head,40);
	 insert_at_end(head,55);
	 insert_at_end(head,87);
	printlinkedlist(head);
}

void printlinkedlist(struct node*head)
{
	if(head == NULL)
	{
		printf("The linked list is empty.");
		exit(0);
	}
	struct node *ptr=NULL;
	ptr  = head;
	printf("The linked list elements =\n");
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr = ptr->link;
	}
}*/