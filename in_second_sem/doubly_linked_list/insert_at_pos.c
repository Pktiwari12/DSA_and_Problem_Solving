// Program to insert node at certain position 
#include<stdio.h>
#include<stdlib.h>
// The structure of node
struct node{
    int data;
    struct node*next;
    struct node*prev;
};
// function declaration to insert element at any certain position
void insert_at_pos(struct node**,struct node**,int,int );
int main()
{
    struct node*head=NULL;
    struct node*tail=NULL;
    insert_at_pos(&head,&tail,34,1);
    insert_at_pos(&head,&tail,33,2);
    insert_at_pos(&head,&tail,32,3);
    insert_at_pos(&head,&tail,30,2);
    insert_at_pos(&head,&tail,35,4);
    insert_at_pos(&head,&tail,38,5);
    insert_at_pos(&head,&tail,65,4);
    insert_at_pos(&head,&tail,45,4);
    //for traversing or printing;
    
    struct node*ptr = head;
    printf("\n");
    while(ptr!= NULL)
    {
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }
    printf("\n%d",tail->data);
}
void insert_at_pos(struct node**head1,struct node**tail1,int newdata,int position)
{
    struct node*new_node = NULL;
    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        printf("Dynamic memory is not allocated.");
        exit(1);
    }
    new_node->data = newdata;
    new_node->next = NULL;
    new_node->prev = NULL;
    int count =0;
    if(*head1 == NULL)
    {
    	printf("\nLinked list is empty.and node is created as a first node.");
        *head1 = new_node;
        *tail1 = new_node;
        // Here we use exit to avoid else block . but right way to use else block
        
    }
    // in this else block all the node is insert at position
    else
	{
	
   	 	// we create a counter variable sothat we may know our traversing point to which node
    	struct node*temp = NULL;
    	temp = *head1;
    	// when we want to insert at beginnig
    	if(count == position-1)
    	{
        	new_node->next = temp;
        	temp->prev = new_node;
        	*head1 = new_node;
    	}
    	else
		{
		
    		while(temp!= NULL && count!=(position-1))
    		{
        		count++;
        		if(count == (position-1))
        		{
            		new_node->prev = temp;
            		new_node->next = temp->next;
            		temp->next = new_node;
            		new_node->next->prev == new_node;
            		break;

        		}
        		temp = temp->next;

    		}
        	// checking wheather inserting node is last node or not
        	if(*tail1 == temp)
       	 	{
            	*tail1 = new_node;
        	}
    	}
	}
    // if position is not valid in the doubly linked list
    // remark : if position = lenth of dll +1. this is valid
    if(position-1>count)
    {
        printf("Position is not valid in the list. because enterd position is the greatear than length.");
    }


}
// The output is always showing ."linked liste is empty and node is created as a first" because 
// we are creating a linked list by using inser_at_pos function. 
// This is not error.
