// Insert a node at the beginning of linked list
// O(1)
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
struct node* insert_at_beg(struct node* head,int data)
{
	struct node *temp=NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	if(temp == NULL)
	{
		printf("Memory is not allocated .");
		exit(0);
	}
	temp->data = data;
	temp->link = NULL;
	temp->link = head;
	head = temp;
	return head;
	
}
int main()
{
	struct node *head=NULL;
	head = (struct node*)malloc(sizeof(struct node));
	if(head == NULL)
	{
		printf("Memory is not allocated.");
	}
	head->data = 56;
	head->link = NULL;
	head = insert_at_beg(head,827);
	struct node *ptr;
	ptr = head;
	while(ptr !=NULL)
	{
		printf("\t%d",ptr->data);
		ptr = ptr->link;
	}
	printf("\n");
	head = insert_at_beg(head,67);
	head = insert_at_beg(head,567);
	ptr = head;
	while(ptr!=NULL)
	{
		printf("\t%d",ptr->data);
		ptr = ptr->link;
	}

}