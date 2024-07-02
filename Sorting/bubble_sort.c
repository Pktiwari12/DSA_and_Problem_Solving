 // Program to implement bubble sort algorithm
#include<stdbool.h>
#include<stdio.h>
void bubble_sort(int arr[],int size);
// driver code
int main()
{
    int n;
    printf("Enter the size of array:\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array:\n");
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nyour entered elements\n");
    for(i=0;i<n;i++)
    {
         printf("%d\t",arr[i]);
    }
    bubble_sort(arr,n);
    printf("\nElements after sorting:\n");
    for(i=0;i<n;i++)
    {
         printf("%d\t",arr[i]);
    }
}
// function definition of bubble sort
void bubble_sort(int arr[],int size)
{
    int temp;       // variable for swapping
    int i,j;        // counter variable
    bool swapped;		// check variable like boolean 
    for(i=0;i<size-1;i++)               // round loop 
    {
    	swapped = false;
        for(j=0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
            	swapped = true;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

            }
        }
        if (swapped = false)
        {
        	break;
		}
    }

}

// time complexity 
// best case O(n)
//worst case O(n^2)
// average case O(n^2)