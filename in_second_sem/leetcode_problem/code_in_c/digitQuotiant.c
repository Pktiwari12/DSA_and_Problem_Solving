#include<stdio.h>
#include<stdlib.h>
#include "ExtractDigitsFromNumberAndCounting.c"
int*quotiantDigit(int num){
	int *digits = extractDigit(num);
	int count = countDigits(num);
	int i = 0;
	int *Qdigits = (int *)malloc(sizeof((count-1)*sizeof(int)));
	int j = 0;
	while(i<count && j<count){
		if(num%digits[i]){
			Qdigits[j] = digits[i];
			j++;
		}
		i++;
	}
}
int main()
{
	int num;
	printf("Enter any number :-");
	scanf("%d",&num);
	int *qdigits = quotiantDigit(num);
	int count = countDigits(num);
	for(int i = 0;i<count ;i++){
		printf("%d\t",qdigits[i]);
	}
	
}
//test issue resolved