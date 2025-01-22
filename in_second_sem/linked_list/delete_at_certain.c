//#include<stdio.h>
//#include<stdlib.h>
struct node{
    int data;
    struct node*link;
};
void delete_at_certain(struct node**,int);
void insert_at_end(struct node**,int);
int printlinkedlist(struct node*);
/*int main()
{
    struct node*head = NULL;
    insert_at_end(&head,45);
    insert_at_end(&head,34);
    insert_at_end(&head,24);
    insert_at_end(&head,14);
    insert_at_end(&head,4);
    int length = printlinkedlist(head);
    printf("\n length of linked list is  = %d ",length);
    delete_at_certain(&head,2);
    printf("\nAfter deleting the specific  element of linked list.");
    length = printlinkedlist(head);
    printf("\nlength of linked list is  = %d",length);
    delete_at_certain(&head,1);
    printf("\nAfter deleting the specific  element of linked list.");
    length = printlinkedlist(head);
    printf("\nlength of linked list is  = %d",length);
    
    delete_at_certain(&head,7);
    printf("\nAfter deleting the specific  element of linked list.");
    length = printlinkedlist(head);
    printf("\nlength of linked list is  = %d",length);
    delete_at_certain(&head,3);
    printf("\nAfter deleting the specific  element of linked list.");
    length = printlinkedlist(head);
    printf("\nlength of linked list is  = %d",length);
    delete_at_certain(&head,2);
    printf("\nAfter deleting the specific  element of linked list.");
    length = printlinkedlist(head);
    printf("\nlength of linked list is  = %d",length);
    delete_at_certain(&head,1);
    printf("\nAfter deleting the specific  element of linked list.");
    length = printlinkedlist(head);
    printf("\nlength of linked list is  = %d",length);

    

}*/
void delete_at_certain(struct node**head1,int loc)
{
     struct node *temp;				//here we use two pointer sothat first for to free desired node and second 
     								// Second for update the link part of previous node into next location
     struct node*certain;
    if(*head1 == NULL)
    {
        printf("\nLinked list is empty .");
        exit(0);
    }
    
    int count =1;				// here initially we assign  1 to counter variable while in counting
    							// the length we assign 0 to the counter variable this is not big issue just logically assigned
    temp = *head1;
    certain = *head1;
    while(temp->link !=    NULL)			// For traversing we always while loop
    {
    	
        if(count == loc)
        {
            break;
        }
        certain = temp;
        temp = temp->link;
        count++;
    }
    if(count == 1)				// this is specially for updating the head pointer
    {
    	*head1 = temp->link;
    	free(temp);
    	temp = NULL;	
	}
	else if(count != loc)   			// when position is greater than length of linked list
	{
		printf("\nyour entered number is greater than length of linked list.");
	}
	else{				// this condition is rest of all
	
    certain->link = temp->link;
    free(temp);
    temp = NULL;
	}
}

// For input data into linked list
void insert_at_end(struct node**head1,int newdata)		//double is used because if linked list is empty then we store the address of specific  node in the head of main function
{
	if(*head1 == NULL)						// LIst is empty
	{
		struct node*temp;
		temp = (struct node*)malloc(sizeof(struct node));			// Creating specific  new node
		if(temp==NULL)
		{
			printf("\nMemory is not allocated.");
			exit(0);
		}
		temp->data = newdata;
		temp->link = NULL;
		*head1 = temp;
		
	}
	else{
	struct node*temp=NULL;					// For creating a new node
	temp = (struct node*)malloc(sizeof(struct node));
	if(temp == NULL)
	{
		printf("\nMemory is not allocated .");
		exit(0);
	}
	temp->data = newdata;
	temp->link = NULL;
	struct node*ptr = NULL;					// For travershing means finding the last node in existing linked list
	ptr = *head1;
	while(ptr->link!=NULL)
	{
		ptr = ptr->link;
	}
	ptr->link = temp;
	}
}



// Printing the data and finding the length

int printlinkedlist(struct node*head)
{
	int count =0;
	if(head == NULL)
	{
		printf("\nThe linked list is empty.");
	}
	struct node *ptr=NULL;
	ptr  = head;
	printf("\nThe linked list elements =\n");
	while(ptr!=NULL)
	{
		count++; 
		printf("%d\t",ptr->data);
		ptr = ptr->link;
	}
	return count;
}
