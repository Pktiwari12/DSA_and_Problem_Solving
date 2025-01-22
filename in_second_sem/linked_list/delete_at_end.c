 #include<stdio.h>
 #include<stdlib.h>
 struct node{
    int data;
    struct node*link;
 };
 void insert_at_end(struct node**,int);
 int printlinkedlist(struct node*);
 void delete_at_end(struct node**head1);
 int main()
 {
    struct node*head=NULL;
    insert_at_end(&head,34);
    insert_at_end(&head,32);
    insert_at_end(&head,23);
    insert_at_end(&head,56);
    insert_at_end(&head,123);
    int length = printlinkedlist(head);
    printf("\n length of linked list is  = %d ",length);
    delete_at_end(&head);
    printf("\nAfter deleting the specific  element of linked list.");
    length = printlinkedlist(head);
    printf("\nlength of linked list is  = %d",length);
    delete_at_end(&head);
    printf("\nAfter deleting the specific  element of linked list.");
    length = printlinkedlist(head);
    printf("\nlength of linked list is  = %d",length);
    
    delete_at_end(&head);
    printf("\nAfter deleting the specific  element of linked list.");
    length = printlinkedlist(head);
    printf("\nlength of linked list is  = %d",length);
    delete_at_end(&head);
    printf("\nAfter deleting the specific  element of linked list.");
    length = printlinkedlist(head);
    printf("\nlength of linked list is  = %d",length);
    delete_at_end(&head);
    printf("\nAfter deleting the specific  element of linked list.");
    length = printlinkedlist(head);
    printf("\nlength of linked list is  = %d",length);
    delete_at_end(&head);
    printf("\nAfter deleting the specific  element of linked list.");
    length = printlinkedlist(head);
    printf("\nlength of linked list is  = %d",length);
    
    
 }
 void delete_at_end(struct node**head1)      // this is not proper running for single node elm
{
    struct node*temp;
    struct node*end;
    if(*head1==NULL)
    {
        printf("The linked list is empty.");
        exit(1);

    }
    temp = *head1;
    end = *head1;
    int check = 0;			// This is for checking the list has only one node or not
    while(temp->link != NULL)
    {
    	check =1;
        end = temp;
        temp = temp->link;

    }
    end->link = NULL;
    free(temp);
    if(check == 0)			// it determines that list has only one node
    {
    	*head1 = NULL;
	}
    temp = NULL;
    
    
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

int printlinkedlist(struct node*head1)
{
	int count =0;
	if(head1 == NULL)
	{
		printf("\nThe linked list is empty.");
	}
	struct node *ptr=NULL;
	ptr  = head1;
	printf("\nThe linked list elements =\n");
	while(ptr!=NULL)
	{
		count++; 
		printf("%d\t",ptr->data);
		ptr = ptr->link;
	}
	return count;
}
