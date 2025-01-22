// Inserting the node(data)in the linked list at the end
// In main function I used a very simple and basic way to insert element but in this program, our focus is only in the inser_at_end 
/* optionally , We add one more thing which is to return the position of new data in the linked list 
O(n) for inserting only
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*link;
};
void insert_at_certain(struct node**,int data,int loc);
int printlinkedlist(struct node*head);
void insert_at_beg(struct node**head1, int data);
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
int main()
{
	struct node* head = NULL;				// This is the plur of the linked list
//	head = (struct node*)malloc(sizeof(struct node));		// specific  node
//	head->data = 45;
//	head->link = NULL;
//	struct node*current = NULL;
//	current = (struct node*)malloc(sizeof(struct node));			// Second node
//	current->data = 98;
//	current->link = NULL;
//	head->link = current;						// linking node to its previous node (specific )
//	current = (struct node*)malloc(sizeof(struct node));		// Third node
//	current->data = 3;
//	current->link = NULL;
//	head->link->link = current;						// linking node to its previous node(Second)
	//printf("%d\t%d\t%d",head->data,head->link->data,head->link->link->data);
//	current= (struct node*)malloc(sizeof(struct node));
//	current->data = 5;
//	current->link = NULL;
//	head->link->link->link = current;
	insert_at_end(&head,55);
	insert_at_end(&head,56);
	insert_at_end(&head,36);
	insert_at_end(&head,70);
	insert_at_end(&head,78);
	insert_at_certain(&head,65,2);
	insert_at_certain(&head,20,1);
	insert_at_certain(&head,45,1);
	insert_at_certain(&head,34,8);
	insert_at_certain(&head,90,10);
	insert_at_certain(&head,9,1);
	insert_at_certain(&head,91,5);
	insert_at_certain(&head,92,7);
	insert_at_beg(&head,23);
	insert_at_beg(&head,238);
	insert_at_beg(&head,123);
	insert_at_beg(&head,231);
	insert_at_beg(&head,234);
	insert_at_certain(&head,12345,1);
	insert_at_end(&head,222);
	insert_at_beg(&head,111);
	insert_at_certain(&head,5555,5);
	 int length = printlinkedlist(head);
	printf("\n length of linked list = %d",length);
	//printf("\n%d\t%d\t\t%d\t%d",head->data,head->link->data,head->link->link->data,head->link->link->link->data);
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





void insert_at_certain(struct node**head1,int newdata,int loc)		//double is used because if linked list is empty then we store the address of specific  node in the head of main function
{
	int count=0;
	loc--;						// Here pay attension we reduce location 1 time
	struct node*ptr = NULL;			// Create a new node
	if(ptr = NULL)
	{
		printf("\nMemory is not allocated.");
		exit(0);
	}
	ptr = (struct node*)malloc(sizeof(struct node));	
	ptr->data = newdata;
	ptr->link = NULL;
	if(*head1 == NULL)						// LIst is empty
	{
		*head1 = ptr;
				
	}
	else{
	struct node*ptr2 = NULL;					// For travershing means finding the last node in existing linked list
	ptr2 = *head1;
	if(count==loc){								// User want to put data in specific  position 
		ptr->link = *head1;
		*head1 = ptr;
	}
	while(ptr2!=NULL && count!=loc)
	{
		count++;
		if(count==loc)
		{
			ptr->link= ptr2->link;
			ptr2->link=ptr;
			break;
		}
		ptr2 = ptr2->link; 
	}
	if(loc>count)
	{
		printf("\nPlease Enter a vaild postion to insert a new data into linked list.");  
		
	}
	
	
	}
	//return count;				//this gives us correct length if we pass position which is greater than length of linked list
}




void insert_at_beg(struct node**head1,int newdata)
{
	struct node*ptr = NULL;
	ptr = (struct node*)malloc(sizeof(struct node)); // creating a new node of given data
	if(ptr == NULL)
	{
		printf("\nMemory is not allocated .");
		exit(0);
	}
	ptr->link = NULL;
	ptr->data = newdata;
	// Now we isert at beginning
	ptr->link = *head1;
	*head1 = ptr;
	
}