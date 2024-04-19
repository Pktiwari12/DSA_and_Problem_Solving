// Program to insert the element at the end
#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node*next;
	struct node*prev;
	int data;
};
void delete_at_certain(struct node**,struct node**,int );
void insert_at_end(struct node**,struct node**,int );
int main()
{
	struct node*head = NULL;
	struct node*tail = NULL;
	insert_at_end(&head,&tail,45);
	insert_at_end(&head,&tail,4);
	insert_at_end(&head,&tail,41);
	insert_at_end(&head,&tail,42);
	// Printing the linked list so we create a temp pointer
	struct node*temp=NULL;
	temp = head;
	while(temp!=NULL) 
	{
		printf("%d\t",temp->data);
		temp = temp->next;
	}
	printf("\n");
	delete_at_certain(&head,&tail,4);
	temp = head;
	while(temp!=NULL) 
	{
		printf("%d\t",temp->data);
		temp = temp->next;
	}
	
	
	
	
}
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

void delete_at_certain(struct node**head1,struct node**tail1,int pos)
{
	
    if(*head1 == NULL)			// this condition is for empty linked list
    {
        printf("list is empty.");
    }
    else if(pos == 1)			// this condition is for when deleting the first node
    {
    	struct node*temp = *head1;
    	*head1 = temp->next;
    	temp->next->prev = NULL;
    	free(temp);
    	temp = NULL;
    	
	}
    else						// this condition is for deleting the other node
    {

        // variable and pointer to traverse the linked list
        int count = 1;
       struct node*temp = *head1;
       struct node*certain = *head1;    // It hold the address of previously node of deleting node 
        while( temp!= NULL)
            {
                if(count == pos)
                {
                	break;
                	
				}
                certain = temp;
                temp = temp->next;
                count++;
            }
            if(pos>count)
            {
                printf("Your enteed position is greater than the linked list length.");
            }
            else if(pos == count )
            {
            	*tail1 = temp->prev;
            	temp->prev->next = NULL;
            	free(temp);
            	temp = NULL;
			}
            else
            {
                certain->next = temp->next;
                temp->next->prev = certain;
                free(temp);
                temp = NULL;


           
		   }

	}
}

