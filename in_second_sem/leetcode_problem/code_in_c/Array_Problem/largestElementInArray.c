#include<stdio.h>
int largestElement(int arr[],int n){
	//printf("hi I am in largestElement function.");
	int largest = arr[0];
	printf("",largest);
	int i;
	for(i = 0 ; i<n ; i++){
		if(arr[i] > largest){
			largest = arr[i];
		}
	}
	return largest;
}
int main(){
	printf("Enter the size of array :-");
	int n;
	scanf("%d",&n);
	int arr[n];
	printf("Enter the element of array :-\n");
	int i; // counter variable
	for(i = 0 ; i < n ;i++){
		scanf("%d",&arr[i]);
	}
	printf("The element of array are :-\n");
	for(i = 0 ; i < n ;i++){
		printf("%d\t",arr[i]);
	}
	int largest = largestElement(arr,n);
	printf("",largest);
	printf("The largest Element of The array is \t:-",largest);
}