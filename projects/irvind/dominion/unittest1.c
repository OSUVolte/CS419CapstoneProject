/*---------------------------------------
* Brett Irvin
* 4/20/16
* CS362_400 Software Engineering II
* Assignment 3--unittest1.c
* Unit test for updateCoins function
*---------------------------------------*/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* The updateCoins function needs to:
1. Reset the coin count.
2. Add up the value of the treasure cards in each player's hand.
3. Add in any bonus.
*/

int main() {
    int i, p;
    int seed = 1000;
    int numPlayers = 2;
    int maxBonus = 10;
    int handCount;
    int bonus;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
    struct gameState G;
    int maxHandCount = 5;
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];

    for (i = 0; i < MAX_HAND; i++) {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }

    printf("\n---Testing the updateCoins function:---\n");

    for (p = 0; p < numPlayers; p++) {
        for (handCount = 1; handCount <= maxHandCount; handCount++) {
            for (bonus = 0; bonus <= maxBonus; bonus++) {
                printf ("Player %d has %d treasure card(s) and a bonus of %d.\n", p, handCount, bonus);
                memset(&G, 23, sizeof(struct gameState));
				initializeGame(numPlayers, k, seed, &G);
                G.handCount[p] = handCount;
				/*---------------------------------------------------------*/
                
				printf("\nTest 1: Testing with Gold treasure cards:\n");
				memcpy(G.hand[p], golds, sizeof(int) * handCount);
                updateCoins(p, &G, bonus);
                printf ("G.coins = %d, expected = %d\n", G.coins, handCount * 3 + bonus);
                if(G.coins != handCount * 3 + bonus){
					printf("Failure: Incorrect coin count.\n");
				}
				else {
					printf("Success: coins updated correctly.\n");
				}	
				/*---------------------------------------------------------*/
				
				printf("\nTest 2: Testing with Silver treasure cards:\n");
				memcpy(G.hand[p], silvers, sizeof(int) * handCount);
                updateCoins(p, &G, bonus);
                printf ("G.coins = %d, expected = %d\n", G.coins, handCount * 2 + bonus);
				if(G.coins != handCount * 2 + bonus){
					printf("Failure: Incorrect coin count.\n");
				}
				else {
					printf("Success: coins updated correctly.\n");
				}
				/*---------------------------------------------------------*/
				
				printf("\nTest 3: Testing Copper treasure cards:\n");
				memcpy(G.hand[p], coppers, sizeof(int) * handCount);
                updateCoins(p, &G, bonus);
                printf ("G.coins = %d, expected = %d\n", G.coins, handCount * 1 + bonus);
				if(G.coins != handCount * 1 + bonus){
					printf("Failure: Incorrect coin count.\n");
				}
				else { 
					printf("Success: coins updated correctly.\n");
				}	
            }
        }
    }
    printf("\n---updateCoins test complete---\n\n");
    return 0;
}