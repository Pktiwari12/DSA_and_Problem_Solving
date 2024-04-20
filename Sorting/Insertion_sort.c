 // Program to implement insertion sort algorithm
#include<stdio.h>
void insertion_sort(int arr[],int size);
int main()
{
	printf("Enter the size of array :\n");
	int n;
	scanf("%d",&n);
	int i;
    int arr[n];
	for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    } 
    printf("\nYour Entered elements:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    insertion_sort(arr,n);
    printf("\n elements after sorting\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}
// in algorithm we divide array into two parts : one is sorted array and another is unsorted array
void insertion_sort(int arr[],int size)
{
    int i,j;         // counter variable
    int key;        // store elemetnt of unsorted array to insert at correct position in sorted array   
    // outer loop is incremented loop which is runnig left to rigth
    for(i=1;i<size;i++)
    {
        key = arr[i];
        j = i-1;
        // inner while loop is decremented loop which is running reght to left in sorted array part
        while(j>=0 && key<arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
// time complexity
//O(n^2)
// best case = O(n)
// worst case = O(n^2)