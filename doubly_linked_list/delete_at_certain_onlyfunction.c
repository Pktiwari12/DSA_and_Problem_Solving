//Program to delete the certain nodes
// in this program , we add seprate condition for deleting first and last node
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
