#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000


typedef struct cool_int{
	int n;
	struct cool_int *next;
}cool_int;


void printReverse(cool_int *number){
	//(recursion, lol)
	int i,n;
	
	if(number->next != NULL){
		printReverse(number->next);
		
		//print the appropriated number of 0
		for(i = 0, n = SIZE; n >= 10; n/=10,i++){}
		for(n = number->n; n > 0; n/=10,i--){}
		for(; i > 0;i--){printf("0");}	
	}
	
	if(number->n != 0)printf("%d",number->n);
	
}

void multiply(cool_int *number, int val){
	//(recursion again, lol)
	if(number->next != NULL){
		multiply(number->next,val);
	}
	
	number->n *= val;
	while(number->n >= SIZE){
		if(number->next == NULL){
			number->next = malloc(sizeof(cool_int));
			number->next->next = NULL;
			number->next->n = 0;
		}

		number->next->n += number->n/SIZE;
		number->n = (number->n)%SIZE;
		number = number->next;
	}
}


int main(){
	int number = 2000;
	cool_int result;
	int i;
	
	result.n = 1;
	result.next = NULL;
	
	
	printf("%d! = ",number);
	
	for(;number > 0; number--){
		multiply(&result,number);
	}
	
	printReverse(&result);
	
	/*
	printf("\n");
	while(result.next != NULL){
		printf("%d ",result.n);
		result = *(result.next);
	}
	printf("%d ",result.n);
	*/
	
}



















