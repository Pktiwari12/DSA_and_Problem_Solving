#include<stdio.h>
#include<stdlib.h>
int countDigits(int );
int*extractDigit(int num){
	 int*digit = NULL;
	 int count = countDigits(num);
	 digit = (int *)malloc((count-1)*sizeof(int));
	 if(digit == NULL){
	 	printf("Dynamically memory is not allocated.");
	 	exit(1);
	 }
	// To find the digits fo decimal number , we divide and module the number
	// the module operator gives the last digit
	// and the divide gives the remaining number
	// break condition when the quatiant would be 0
	int quotient;
	int i = 0;
	while(quotient!=0 && i<count){
		digit[i] = num%10;
		num = num/10;
		i++;
		
	}	
	return digit;
}
int countDigits(int num){
	int count = 0;
	while(num != 0){
		num = num/10;
		count++;
	}
	return count;
}
//int main(){
//	int num;
//	printf("Enter the number ");
//	scanf("%d",&num);
//	int* digits;
//	int count = countDigits(num);
//	printf("%d\n",count);
//	 digits = extractDigit( num);
//	
//	// printing the digits
//	for(int i = count-1; i>=0 ;i--){
//		printf("%d\t",digits[i]);
//	}	
//}