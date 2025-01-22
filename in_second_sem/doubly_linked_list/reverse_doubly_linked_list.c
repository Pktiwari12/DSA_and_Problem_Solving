// Program to reverse the linked list
// time complexity is O(n)
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node*prev;
};
void insert_at_end(struct node**,struct node**,int data);
void reverse_dll(struct node**head1,struct node**tail1);
void print_dll(struct node*);
int main()
{
    struct node*head = NULL,*tail = NULL;
    insert_at_end(&head,&tail,11);
    insert_at_end(&head,&tail,12);
    insert_at_end(&head,&tail,13);
    insert_at_end(&head,&tail,14);
    insert_at_end(&head,&tail,15);
    insert_at_end(&head,&tail,16);
    insert_at_end(&head,&tail,17);
    insert_at_end(&head,&tail,18);
    insert_at_end(&head,&tail,19);
    print_dll(head);
    reverse_dll(&head,&tail); 
    printf("\ndoubly linked list after reversing.\n");
    print_dll(head);

}
void reverse_dll(struct node**head1,struct node**tail1)
{
    // check whether dll is empty or not
    if(*head1 == NULL && *tail1 == NULL)
    {
        printf("doubly linked list is empty");
    }
    // interchange the value of head and tail 
    struct node*temp = *head1;
    *head1 = *tail1;
    *tail1 = temp;
    temp = *head1;
    // another temporary variable
    struct node*temp1;
    // We observe that while reversing only every node's prev and next is interchanged
    while(temp !=NULL)
    {
        temp1 = temp->next;
        temp->next = temp->prev;
        temp->prev = temp1; 
        temp = temp->next;
    }
}

// function to insert_at_end

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
// printing the list by using the head (forward direction)
void print_dll(struct node*head1)
{
    if(head1 == NULL)
    {
        printf("doubly linkd list is empty.");
    }
    struct node*temp = head1;
    while(temp != NULL)
    {
        printf("%d\t",temp->data);
        temp = temp->next;
    }
}
