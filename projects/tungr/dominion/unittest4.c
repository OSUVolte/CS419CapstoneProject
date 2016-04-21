/*
	Rosa Tung
	CS362
	(20 points) Write unit tests for four functions (not card implementations or cardEffect) in dominion.c. 
	Check these tests in as unittest1.c,unittest2.c, unittest3.c, and unittest4.c. 
	(for example, you can create a test for updateCoins() method)
	
	Testing:
		int compare(const void* a, const void* b);
*/

#include "dominion.h"  

#include <stdio.h> //printf scanf

int main(){
	//set our values to test
	int small = 1;
	int big = 2;
	int* smaller = &small;
	int* bigger = &big;
	
	int flag;
	printf("---Testing compare function START---\n\n");
	
	printf("Testing [left < right]...\n");
	if(compare(smaller, bigger) == -1){
		printf("	PASS\n");
	} else {
		printf("	FAIL\n");
	}
	printf("Testing [left > right]...\n");
	if(compare(bigger, smaller) == 1){
		printf("	PASS\n");
	} else {
		printf("	FAIL\n");
	}
	printf("Testing [left = right]...\n");
	if(compare(smaller, smaller) == 0){
		printf("	PASS\n\n");
	} else {
		printf("	FAIL\n\ns");
	}
	
	printf("---Testing compare function COMPLETE---\n\n\n\n");
	return 0;
}