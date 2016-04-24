/********************************************************************
 * Kara Franco
 * unittest1: compare() function
 * Due Date: April 24, 2016
 * ****************************************************************/

#include "dominion.h"
#include <stdio.h>

int main(){

	printf("\n------------------------Unit Test 1-----------------------------\n\n");
	printf("---Test compare()---\n");

	// compare() looks at two values for inequality
	// in this test we will look at each sign: < > =
	int less = 1;
	int greater = 2;
	int* lessThan = &less;
	int* greaterThan = &greater;

	printf("Testing value1 is less than value2...\n");
	if(compare(lessThan, greaterThan) == -1){
		printf("PASS\n");
	} else {
		printf("FAIL\n");
	}
	printf("Testing value1 is greater than value2...\n");
	if(compare(greaterThan, lessThan) == 1){
		printf("PASS\n");
	} else {
		printf("FAIL\n");
	}
	printf("Testing for equality...\n");
	if(compare(greaterThan, greaterThan) == 0){
		printf("PASS\n");
	} else {
		printf("FAIL\n");
	}

	printf("---compare() Test Complete---\n\n");
	return 0;
}
