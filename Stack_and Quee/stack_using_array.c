// Program to implement the all the operation of stack using array
#include<stdio.h>
#include<stdbool.h>
#define N 6        // the size of stack
int top = -1;       // Initially top to be initialized -1 that determine the stack is empty
int stack[N];
void push(int);
void display();
void pop();
void isFull();
int stackSize();
void isEmpty();

void peek();
int main()
{
	 isFull();
	 isEmpty();
     display();
     push(4);
     display();
     printf("the size of stack is = %d\n",stackSize());
     push(5);
     push(6);
     push(7);
     display();
    printf("the size of stack is = %d\n",stackSize());
     push(8);
     push(9);
     printf("stack elements are :\n");
     display();
     printf("the size of stack is = %d\n",stackSize());
     // call the peek function to print the top element 
     peek();
     isFull();
     isEmpty();
     push(10);
     pop();
     display();
     peek();
     printf("The size of stack is = %d\n",stackSize());
	 pop();
     display();
     pop();
     

}
// function to push the elements
void push(int x)
{
    // if stack is full
    if(top >= N-1)
    {
        printf("Stack Overflow.\n");
    }
    //push the element into the top postion
    else{
        top++;
        stack[top] = x;

    }
}

// function to display the all stack elements
void display()
{
    if(top < 0)
    {
        printf("Stack is empty.\n");

    }
    else{
        int i;      // counter variable 
        for(i = top;i>=0;i--)
        {
            printf("%d\t",stack[i]);
        }
    }
    printf("\n");

}

// function to delete the element from the stack
void pop()
{
    // checking the underflow condition
    if(top < 0)
    {
        printf("Stack Underflow.");
    }
    else{
        int item;   // store deleted item
        item = stack[top];
        top--;
        printf("The deleted element is = %d\n",item);
    }
}

// check whether stack is full or not
void isFull()
{
	if(top == N-1)
	{
		printf("Stack is full.\n");
	}
	else
	{
		printf("Stack is not full.\n");
	}
}

// function to check whether stack is empty or not
void isEmpty()
{
	if(top < 0)
	{
		printf("Stack is empty of function is empty\n");
	}
	else{
		printf("stack is not empty\n");
	}
}
// function to find the size of stack
int stackSize()
{
    int count = 0;  // counter variable
    while(count <= top)
    {
        count++;
    }
    return count;
}
//fuction to find the top element of stack
void peek()
{
	if(top<0)
	{
		printf("The stack is empty.\n");
	}
	else
	{
		printf("The top element of the stack is = %d\n",stack[top]);
	}
}