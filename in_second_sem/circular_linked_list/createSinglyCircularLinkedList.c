// Program to create a singly circular linked list
// this program is for integer data
#include<stdio.h>
#include<stdlib.h>
#include"traverse_cll.c"
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
int main()
{
    //In Singly Circular  linked list we control the list by tail pointer in place of head pointer
    struct node*tail = NULL;
    createSinglyCircularLinkedList(&tail,45);
    createSinglyCircularLinkedList(&tail,55);
    createSinglyCircularLinkedList(&tail,53);
    createSinglyCircularLinkedList(&tail,51);
    createSinglyCircularLinkedList(&tail,50);
	print_cll(tail);
	printf("\n");
	//checking the last node's next contain the address of first node
	printf("%d",tail->next->data);

    
   



    
}