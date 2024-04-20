







#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*link;
};
void insertatend(struct node**ptr,int newdata)
{
	struct node*temp = (struct node*)malloc(sizeof(struct node));
	if(temp == NULL)
	{
		printf("Memory is not allocated.");
		exit(0);
	}
	temp->data = newdata;
	temp->link = NULL;
	if(*ptr == NULL)
	{
		*ptr = temp;
	}
	else{
	struct node*currentlast = *ptr;
	while(currentlast->link!=NULL){
		currentlast = currentlast->link;
	}
	currentlast->link = temp;
	}


}
int main()
{
	struct node*head=NULL;
	insertatend(&head,45);
	insertatend(&head,456);
	printf("\n%d  %d",head->data,head->link->data);	
}
