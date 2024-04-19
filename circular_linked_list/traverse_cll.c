// Program to traverse the singly circular singly linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
};
void print_cll(struct node*tail1)
{
    struct node*temp = tail1->next;      // traversing pointer and assign the address of first node
    do{
        printf("%d\t",temp->data);
        temp = temp->next;
    }while(temp!=tail1->next); 	// stop the loop when temp is again point to first node
}