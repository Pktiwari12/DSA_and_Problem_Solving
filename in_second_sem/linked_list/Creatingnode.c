// Simple Program to create a node in C
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
int main()
{
	struct node* head = NULL;
	head =(struct node*)malloc(sizeof(struct node));
	if(head == NULL)
	{
		printf("Memory is not allocated .");
		exit(0);
		
	}	
	printf("Enter any integer data.");
	scanf("%d",&head->data);
	head->link = NULL;
	printf("%d",head->data);
	printf("\n%s",head->link);
	return 0;
}