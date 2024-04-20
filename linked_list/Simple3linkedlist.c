#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*link;
};
int main()
{
	struct node* head = NULL;				// This is the plur of the linked list
	head = (struct node*)malloc(sizeof(struct node));		// specific  node
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
	printf("%d\t%d\t%d",head->data,head->link->data,head->link->link->data);
	current= (struct node*)malloc(sizeof(struct node));
	current->data = 5;
	current->link = NULL;
	head->link->link->link = current;
	printf("\n%d\t%d\t\t%d\t%d",head->data,head->link->data,head->link->link->data,head->link->link->link->data);
}
// after creating a node , we have to link previous ave to use the concept  of pointer to pointer(head->link->link....)