


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1
int compareTest(int, int);


int main() {
    int i;
    int seed = 1000;
    int numPlayer = 2;
	int testResult=0;
    int p=0, r;
 
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;

    // arrays of all coppers, silvers, and golds

	
	
	//isGameOver
	printf("-------------------UNITTEST2: IsGameOver--------------------\n");
	r = initializeGame(numPlayer, k, seed, &G); // initialize a new game	

	
	printf("Testing Provinces in Deck End Condition\n");
	G.supplyCount[province] =0;
	r= isGameOver(&G);
	printf("%d province cards.\nExpected Result: %d, Actual Result: %d\n",G.supplyCount[province], 1, r);
	testResult += compareTest(r, 1);
	
	G.supplyCount[province] =1;
	r= isGameOver(&G);
	printf("%d province cards.\nExpected Result: %d, Actual Result: %d\n",G.supplyCount[province], 1, r);	

	testResult += compareTest(0, isGameOver(&G));
	
	G.supplyCount[province] =10;
	r= isGameOver(&G);
	printf("%d province cards.\nExpected Result: %d, Actual Result: %d\n",G.supplyCount[province], 1, r);

	testResult += compareTest(0 ,r);
	
	// 3 supply piles are empty
	printf("Check 3 empty pile conditions End Condition for 3 People\n");
	for(i=0; i<10; i++){	
		G.supplyCount[k[i]] =0; 		
		p++;
		r= isGameOver(&G);
		if(p>=3){
			printf("%d  empty piles.\nExpected Result: %d, Actual Result: %d\n\n",p, 1, r);
			testResult += compareTest(1 ,r);
		}
		else{
			printf("%d  empty piles.\nExpected Result: %d, Actual Result: %d\n",p, 0, r);
			testResult += compareTest(0 ,r);
		}
	}
	
	printf("Check 4 empty pile conditions End Condition for 4 People\n");
	for(i=0; i<10; i++){	
		G.supplyCount[k[i]] =0; 		
		p++;
		r= isGameOver(&G);
		if(p>=4){
			printf("%d  empty piles.\nExpected Result: %d, Actual Result: %d\n\n",p, 1, r);
			testResult += compareTest(1 ,r);
		}
		else{
			printf("%d  empty piles.\nExpected Result: %d, Actual Result: %d\n",p, 0, r);
			testResult += compareTest(0 ,r);
		}
	}
	
	// for loop go through and set various piles to 0
	if(testResult ==0){
		printf("\nUnit 2 Test Results Passed!\n");		
	}
	else{
		printf("\nUnit 2 Test Failed\n");
	}
	
	printf("--------------------------------------------------\n");	
	return 0;		
}


int compareTest(int a, int b){
	if(a == b){
		printf("PASSED!\n");
		return 0; 	
	}
	else{
		printf("FAILED!\n");
		return 1;		
	}	
}