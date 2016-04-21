
//unit test for scorefoer
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove asserts
#define NOISY_TEST 1

int compareTest(int, int);


int main() {
    int i;
    int seed = 2000;
    int numPlayer = 2;
    int maxBonus = 5;
    int p, handCount;
    int bonus;
	int testResult=0;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    // arrays of all coppers, silvers, and golds
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];
	int noCoins[MAX_HAND];
    for (i = 0; i < MAX_HAND; i++)
    {
		noCoins[i]= smithy;
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }
		printf("-------------------UNITTEST1: UPDATE COINS--------------------\n");
    for (p = 0; p < numPlayer; p++)
    {
        for (handCount = 1; handCount <= maxHandCount; handCount++)
        {
            for (bonus = 0; bonus <= maxBonus; bonus++)
            {
				initializeGame(numPlayer, k, seed, &G); // initialize a new game
				memset(&G, 33, sizeof(struct gameState));   // clear the game state
              
                G.handCount[p] = handCount;                 // set the number of cards on hand
				memcpy(G.hand[p], noCoins, sizeof(int) * handCount);
				//no valid coins in hand 
				printf("\nTest Player %d with 0 coins in hand\n", p);
				
				updateCoins(p, &G, bonus); 
				
				printf("G.coins = %d,  expected= %d\n", G.coins, bonus);
				testResult += compareTest(G.coins,bonus);				
				

                printf("Test player %d with %d treasure card(s) and %d bonus.\n", p, handCount, bonus);
                memcpy(G.hand[p], coppers, sizeof(int) * handCount); // set all the cards to copper
                updateCoins(p, &G, bonus);
                printf("G.coins = %d, expected = %d\n", G.coins, handCount * 1 + bonus);
                testResult += compareTest(G.coins, handCount * 1 + bonus); // check if the number of coins is correct
                memcpy(G.hand[p], silvers, sizeof(int) * handCount); // set all the cards to silver
                updateCoins(p, &G, bonus);

                printf("G.coins = %d, expected = %d\n", G.coins, handCount * 2 + bonus);

      
				testResult += compareTest(G.coins, handCount * 2 + bonus);
                memcpy(G.hand[p], golds, sizeof(int) * handCount); // set all the cards to gold
                updateCoins(p, &G, bonus);

                printf("G.coins = %d, expected = %d\n", G.coins, handCount * 3 + bonus);

                //assert(G.coins == handCount * 3 + bonus); // check if the number of coins is correct
				testResult += compareTest(G.coins, handCount * 3 + bonus);
				
			//set last card to zero
				G.hand[p][handCount-1] = smithy;
				printf("Test Player %d with %d treasure cards\n", p, handCount-1);
				
				updateCoins(p, &G, bonus);
				printf("G.coins = %d,  expected= %d\n", G.coins, (handCount-1) *3 + bonus );
				
				//assert(G.coins == (handCount-1) *3 + bonus);
				testResult += compareTest(G.coins , (handCount-1) *3 + bonus);
            }
        }
    }
	
	
	if(testResult ==0){
		printf("\nUnit 1 Test Results Passed!\n");
		
	}
	else{
		printf("\nUnit 1 Test Failed\n");
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
