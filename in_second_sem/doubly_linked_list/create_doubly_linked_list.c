// Doubly linked list . creation of nodes 
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
    struct node*prev;

};
void insert_node(struct node**head1,int new_data)
{

    struct node*new_node;
    struct node*temp;       // this pointer to avoid to use of head->next->next..
    new_node = (struct node*)malloc(sizeof(struct node));   // first node is also created by head pointer . but for clearity we
                                                            //use another pointer which always point to current creating node
    new_node->data = new_data;
    new_node->next = NULL;
    new_node->prev = NULL;              // first node is created
    if(*head1 == NULL)
    {
        *head1 = new_node;
        temp = new_node;            // temp is pointed to current node in linked list

    }
    else{
        temp->next = new_node;
        new_node->prev = temp;
        temp = new_node;
    }


}
int main()
{
    struct node*head = NULL;
    insert_node(&head,45);
    insert_node(&head,34);
    insert_node(&head,32);
    insert_node(&head,33);
    struct node*temp = head;       // for printing 
    while(temp != NULL)         // We is not using the concept of dll . just we use traversing upward
    {
        printf("%d\t",temp->data);
        temp = temp->next;

    }

}
