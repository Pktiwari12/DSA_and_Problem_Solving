#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
// stack is a data structure
void push(struct node**top,int data,)
{
    struct node new_node = NULL;
    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        printf("Memory is not allocated.");

    }
    else{

    }

}
int main()
{
    struct node*stack = NULL;
    push(&stack,4);
}