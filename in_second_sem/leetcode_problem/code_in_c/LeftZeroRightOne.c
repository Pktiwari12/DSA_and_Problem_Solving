#include<stdio.h>
#include<stdlib.h>
void leftZeroRightOne(int arr[],int size){
    // two pointer apporach
    int i,j;
    i = 0;
    for( j=0;j<size ;j++)
    {
        if(arr[j]==0){
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            i++;
        }
    }
}
int main(){
    int n;
    printf("Enter the size of array :\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter 0 or 1 as elements of array :-\n");
    for(int i =0 ;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("The elements of array :\n");
    for(int i =0 ;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
    leftZeroRightOne(arr,n);
    printf("The elements of array after changing the 0 and 1 order :\n");
    for(int i =0 ;i<n;i++){
        printf("%d\t",arr[i]);
    }
    
}

