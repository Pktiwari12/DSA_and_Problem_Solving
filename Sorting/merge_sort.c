// Program to implement the merge sort
#include<stdio.h>
// this function is nothing but recursive function . we put only three function in it
void merge_sort(int[],int,int);
// merge function is for merge sub array with sorting
void merge(int[],int,int,int);
// driver code
int main()
{
    int n;
    printf("Enter the size of array:\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array :\n");
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    // printting the array
    printf("Your entered array is :\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    merge_sort(arr,0,n-1);
    // printting the array after sorting
    printf("\nYour sorted  array is :\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}

// definition of mearge_ sort 
void merge_sort(int arr[],int lb,int ub)
{
   int mid = (lb+ub)/2;
   if(lb<ub)
   {
    merge_sort(arr,lb,mid);
    merge_sort(arr,mid+1,ub);
    merge(arr,lb,mid,ub);
   }
}


// defintion of merge fucnction including mearge with sortin and copy elemens
void merge(int arr[],int lb,int mid,int ub)
{
    //int b[ub+1];			// Here we waste out memory because if 
    int b[ub-lb+1];			// finnaly we avoid to waste memory
	int i,j,k;
    i = lb;
    j = mid+1;
    k = 0;	
    // we copy the elements of both sub array into new array with sorting. so we use two ponter concept
    while(i <= mid && j <= ub)
    {
        if(arr[i]<arr[j])
        {
            b[k]= arr[i];
            i++;
            k++;
        }
        else{
            b[k]= arr[j];
            j++;
            k++;
        }
    }
    // if left sub array is exhaused . so we copy all the elemets of rigth array
    if(i>mid)
    {
        while(j<=ub)
        {
            b[k] = arr[j];
            j++;
            k++;
        }
    }
    //if right sub array is exhaused . so we copy all the elemets of left array
    else
    {
        while(i<=mid)
        {
            b[k] = arr[i];
            i++;
            k++;
        }
    }
    // Copy the elements into arr from array b 
    // we use counter i and k again with assigning lower bound and 0
    i = lb;
	k = 0;
    while(k<=ub && i<=ub)       // here k<=ub is not necessary. and this condition id logically wrong
    {
        arr[i] = b[k];
        i++;
        k++;
    }

}