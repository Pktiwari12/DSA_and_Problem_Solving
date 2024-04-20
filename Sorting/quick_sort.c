#include<stdio.h>
void quick_sort(int[],int,int);
int partition(int[],int,int);
void swap(int*a,int*b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    
    int n;
    printf("Enter the size of array :\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array :\n");
    int i;
    for(i = 0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Your Entered elements are :\n");
    for(i = 0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    // passing the lower boud and upper bound
    quick_sort(arr,0,n-1);
    printf("\narray after sorting :\n");
    for(i = 0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }

}
void quick_sort(int arr[],int lb,int ub)
{
	int loc;
    // if lower bound is greater than ub . it means array has single elements
    if(lb<ub)
    {
        // do not confuse in parameters because we use recursion
         loc = partition(arr,lb,ub);
        quick_sort(arr,lb,loc);
        quick_sort(arr,loc+1,ub);
        
    }
}
// this fxn is important for quick sort.in this function array is partitioned and find out
// the appropriate position of pivot
int partition(int arr[],int lb,int ub)
{
    int pivot = arr[lb];        // we can choose any elements of array as pivot
    int start,end;              // counter variable
    start = lb;
    end = ub;
    while(start<end)
    {
        // here we add three while condition to find out the appropriate pos of pivot
        // and partition the array into sub arrays inwhich left array is smaller  than equal to pivot
        // and right array is greater than pivot  

        while(arr[start]<=pivot && start<=ub)
        {
            start++;
        }
        while(arr[end]>pivot && end >=lb)
        {
            end--;
        }
        if(start<end)
        {
            // if arr[end]<=pivot then 
            // swap the elements of arr[start] and arr[end] 
            // so smaller element will reach on left and greater element will reach on right
            //printf("in if");
            swap(&arr[start],&arr[end]);
            
        }
    }
    // swaping the pivot elements and current element at end
    swap(&arr[lb],&arr[end]);
    return end;
}