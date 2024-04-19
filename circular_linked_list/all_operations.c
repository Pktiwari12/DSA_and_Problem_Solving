// this file for store funtions of all the operation 
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
};

// function to print the function
void print_cll(struct node*tail1)
{
    struct node*temp = tail1->next;      // traversing pointer and assign the address of first node
    do{
        printf("%d\t",temp->data);
        temp = temp->next;
    }while(temp!=tail1->next); 	// stop the loop when temp is again point to first node
}


// function to create the  linked list
void createSinglyCircularLinkedList(struct node**tail,int data1)
{
	struct node*temp = *tail;	// this pointer always keep the value of tail.We use it only when we 
								// want to access the node member
	struct node *new_node = NULL;
    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        printf("Memory is not allocated.\n");

    }
    else
    {
        new_node->data = data1;
        new_node->next = NULL;
        // checking whether  list is empty or not
        if(*tail == NULL)
        {
            *tail = new_node;
            temp = *tail;		// previously temp contains NULL
            temp->next = *tail;
        }
        else{
        	//struct node*temp = *tail;
            new_node->next = temp->next;
            temp->next = new_node;
            *tail = new_node;
        }
    }

   


}
