#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "dominion.h"
//makefile was taken from https://github.com/aburasali/cs362sp16/blob/master/projects/batese/dominion/Makefile


/*
int compare(const void* a, const void* b) {
  if (*(int*)a > *(int*)b)
    return 1;
  if (*(int*)a < *(int*)b)
    return -1;
  return 0;
}

*/


void testCompare() {
    printf("\n\ncompare() Function test\n");
	int smaller = 5;
	int larger = 8;
	int* smaller2 = &smaller;
	int* larger2 = &larger;
	if(compare(smaller2, larger2) == -1){
		printf("Smaller value was detected correctly\n");
	} else {
		printf("Smaller values was not detected correctly\n");
	}
	if(compare(larger2, smaller2) == 1){
		printf("Smaller value was detected correctly\n");
	} else {
		printf("Smaller values was not detected correctly\n");
	}
	if(compare(smaller2, smaller2) == 0){
		printf("Both values are the same and this was correctly detected\n");
	} else {
		printf("Both values are the same and the function did not produce correct results\n");
	}
	return 0;
}


int main () {
    testCompare();
    exit(0);
}
