// Program to delete first node from doubly linked list 
// focus only delete_first_node function only
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
    struct node*prev;
};
// function declaration
void delete_first_node(struct node**head,struct node**tail);
void insert_at_end(struct node**,struct node**,int data);
// we use forward traversing
void print_doubly_linked_list(struct node*,struct node*);

// driver function
int main()
{
    struct node*head = NULL;
    struct node*tail = NULL;
    insert_at_end(&head,&tail,46);
    insert_at_end(&head,&tail,45);
    insert_at_end(&head,&tail,47);
    print_doubly_linked_list(head,tail);
    printf("\n");
    delete_first_node(&head,&tail);
    print_doubly_linked_list(head,tail);
    printf("\n");
	delete_first_node(&head,&tail);
    print_doubly_linked_list(head,tail);

}
// defination of deleting first node from doubly linked list
void delete_first_node(struct node**head1,struct node**tail1)
{
    // check wheather list is empty or not
    if(*head1 == NULL || *tail1 == NULL)
    {
        printf("Doubly linked list is empty.");
    }
    else
    {
        // assign address of first node of temporary variable
        struct node*temp = *head1;
        *head1 = temp->next;
        // check wheather dll has only single node or not
        if(*head1 == NULL)
        {
            *tail1 == NULL;
        }
        else{
            // upgrade the prev of second node to NULL
            temp->next->prev = NULL;

        }
        // After all first node is deleted
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