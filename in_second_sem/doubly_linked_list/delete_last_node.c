// Program to delete the last node of doubly linked list
// my main function is only delete_last_nodes
#include<stdio.h>
#include<stdlib.h>
// blue print of node
struct node{
    int data;
    struct node *next;
    struct node *prev;

};
// declaration of functions
void delete_last_node(struct node**head,struct node**tail);
void insert_at_end(struct node**,struct node**,int data);
// we use forward traversing
void print_doubly_linked_list(struct node*,struct node*);

int main()
{
    struct node *head = NULL;
    struct node *tail = NULL;
    insert_at_end(&head,&tail,46);
    insert_at_end(&head,&tail,45);
    insert_at_end(&head,&tail,47);
    print_doubly_linked_list(head,tail);
    printf("\n");
    delete_last_node(&head,&tail);
    print_doubly_linked_list(head,tail);

}
// function deifination to delete last node of doubly linked list
void delete_last_node(struct node**head1,struct node**tail1)
{
    // check wheather dll is empty or not
    if(*head1 == NULL)
    {
        printf("\nLinked list is empty.");
    }
    else
    {
		// here we assign the address of last node to the temporary variable
    	struct node*temp = *tail1;
    	// upgrading the tail with address of second last node and second last node 's next is null
    	*tail1  = temp->prev;
    	// This case is when doubly linked list has only single node
    	if(*tail1 == NULL)
    	{
    		*head1 == NULL;
		}
		else
		{
	
    		temp->prev->next = NULL;
		}
    	// free the last node
    	free(temp);
    	temp = NULL;
	}
}

// we use insertion function

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


// printing list
void print_doubly_linked_list(struct node*head1,struct node*tail1)
{
    if(head1 == NULL || tail1 == NULL)
    {
        printf("\n doubly linked list is empty.");
    }
    else
    {
	
    	struct node*temp = head1;
    	while(temp != NULL)
    	{
        	printf("%d\t",temp->data);
        	temp = temp->next;
    	}
	}
}