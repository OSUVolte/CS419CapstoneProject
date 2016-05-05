/* 
Author: Jonathan Hardman
File name: unittest1.c

Function Requirements: initializeGame
1. Correct number of players with correct deck and hand sizes

2. Correct amount in each pile for treasure, kingdom, and victory cards

3. Correct Player 1 Initialize values
 
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTFUNCTION "initializeGame"

int main() {

	int p1deckCnt = 5,otherdeckCnt = 10;
	int p1handCnt = 5,otherhandCnt = 0;
	int totalCnt = 10;
	
    int curse2 = 10;
	int curse3 = 20;
	int curse4 = 30;
	int kingdomAmount = 10;
	int victoryAmount = 8;
	int victoryAmount2 = 12;
	
	int initOutpostPlayed = 0;
	int initPhase = 0;
	int initActions = 1;
	int initBuys = 1;
	int initplayedCards = 0;
	int initTurn = 0;
	
    int i = 2,j,r;
    int seed = 1000;
	struct gameState G;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};


	printf("----------------- Testing Function: %s ----------------\n", TESTFUNCTION);
	printf("TEST1: Without victory kingdom cards\n");
	
	for(i=2; i<5; i++){
	
		printf("\nPlayer Count: %d\n",i);
		
		// initialize a game state and player cards
		initializeGame(i, k, seed, &G);
		
		printf("\nChecking Players... \n");
		
		for(j=0;j<i;j++)
		{
			printf("Checking Player %d\n",j+1);
			if(j == 0){
				printf("deck count = %d, expected = %d\n", G.deckCount[j], p1deckCnt);
				printf("hand count = %d, expected = %d\n", G.handCount[j], p1handCnt);
				printf("total count = %d, expected = %d\n", G.deckCount[j] + G.handCount[j], totalCnt);
				assert(G.deckCount[j] == p1deckCnt);
				assert(G.handCount[j] == p1handCnt);
				assert((G.deckCount[j] + G.handCount[j]) == totalCnt);
			}else{
				printf("deck count = %d, expected = %d\n", G.deckCount[j], otherdeckCnt);
				printf("hand count = %d, expected = %d\n", G.handCount[j], otherhandCnt);
				printf("total count = %d, expected = %d\n", G.deckCount[j] + G.handCount[j], totalCnt);
				assert(G.deckCount[j] == otherdeckCnt);
				assert(G.handCount[j] == otherhandCnt);
				assert((G.deckCount[j] + G.handCount[j]) == totalCnt);
			}
		}
		
		printf("\nChecking Card Piles... \n");
		//Curse Check
		if(i == 2){
			printf("curse count = %d, expected = %d\n", supplyCount(curse,&G), curse2);
			assert(supplyCount(curse,&G) == curse2);
		}else if(i == 3){
			printf("curse count = %d, expected = %d\n", supplyCount(curse,&G), curse3);
			assert(supplyCount(curse,&G) == curse3);
		}else if(i == 4){
			printf("curse count = %d, expected = %d\n", supplyCount(curse,&G), curse4);
			assert(supplyCount(curse,&G) == curse4);
		}
		
		//Victory Check
		if(i == 2){
			printf("estate count = %d, expected = %d\n", supplyCount(estate,&G), victoryAmount);
			printf("duchy count = %d, expected = %d\n", supplyCount(duchy,&G), victoryAmount);
			printf("province count = %d, expected = %d\n", supplyCount(province,&G), victoryAmount);
			assert(supplyCount(estate,&G) == victoryAmount);
			assert(supplyCount(duchy,&G) == victoryAmount);
			assert(supplyCount(province,&G) == victoryAmount);
		}else{
			printf("estate count = %d, expected = %d\n", supplyCount(estate,&G), victoryAmount2);
			printf("duchy count = %d, expected = %d\n", supplyCount(duchy,&G), victoryAmount2);
			printf("province count = %d, expected = %d\n", supplyCount(province,&G), victoryAmount2);
			assert(supplyCount(estate,&G) == victoryAmount2);
			assert(supplyCount(duchy,&G) == victoryAmount2);
			assert(supplyCount(province,&G) == victoryAmount2);		
		}
		//Kingdom Checks
		printf("Checking Kingdom cards...");
		for (j=0; j<10; j++)
		{
			r = supplyCount(k[j],&G);
			assert(r == kingdomAmount);
		}
		printf("PASSED\n");
		printf("\nALL CARD PILES PASSED\n");
		printf("\nChecking Player State...");
		
		assert(G.outpostPlayed == initOutpostPlayed);
		assert(G.phase == initPhase);
		assert(G.numActions == initActions);
		assert(G.numBuys == initBuys);
		assert(G.playedCardCount == initplayedCards);
		assert(G.whoseTurn == initTurn);
		
		printf("PASSED\n");
	}
	
	printf("TEST2: With victory kingdom cards\n");
	int z[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, gardens, smithy, great_hall};

	for(i=2; i<5; i++){
	
		printf("\nPlayer Count: %d\n",i);
		
		// initialize a game state and player cards
		initializeGame(i, z, seed, &G);
		
		printf("\nChecking Players... \n");
		
		for(j=0;j<i;j++)
		{
			printf("Checking Player %d\n",j+1);
			if(j == 0){
				printf("deck count = %d, expected = %d\n", G.deckCount[j], p1deckCnt);
				printf("hand count = %d, expected = %d\n", G.handCount[j], p1handCnt);
				printf("total count = %d, expected = %d\n", G.deckCount[j] + G.handCount[j], totalCnt);
				assert(G.deckCount[j] == p1deckCnt);
				assert(G.handCount[j] == p1handCnt);
				assert((G.deckCount[j] + G.handCount[j]) == totalCnt);
			}else{
				printf("deck count = %d, expected = %d\n", G.deckCount[j], otherdeckCnt);
				printf("hand count = %d, expected = %d\n", G.handCount[j], otherhandCnt);
				printf("total count = %d, expected = %d\n", G.deckCount[j] + G.handCount[j], totalCnt);
				assert(G.deckCount[j] == otherdeckCnt);
				assert(G.handCount[j] == otherhandCnt);
				assert((G.deckCount[j] + G.handCount[j]) == totalCnt);
			}
		}
		
		printf("\nChecking Card Piles... \n");
		//Curse Check
		if(i == 2){
			printf("curse count = %d, expected = %d\n", supplyCount(curse,&G), curse2);
			assert(supplyCount(curse,&G) == curse2);
		}else if(i == 3){
			printf("curse count = %d, expected = %d\n", supplyCount(curse,&G), curse3);
			assert(supplyCount(curse,&G) == curse3);
		}else if(i == 4){
			printf("curse count = %d, expected = %d\n", supplyCount(curse,&G), curse4);
			assert(supplyCount(curse,&G) == curse4);
		}
		
		//Victory Check
		if(i == 2){
			printf("estate count = %d, expected = %d\n", supplyCount(estate,&G), victoryAmount);
			printf("duchy count = %d, expected = %d\n", supplyCount(duchy,&G), victoryAmount);
			printf("province count = %d, expected = %d\n", supplyCount(province,&G), victoryAmount);
			assert(supplyCount(estate,&G) == victoryAmount);
			assert(supplyCount(duchy,&G) == victoryAmount);
			assert(supplyCount(province,&G) == victoryAmount);
		}else{
			printf("estate count = %d, expected = %d\n", supplyCount(estate,&G), victoryAmount2);
			printf("duchy count = %d, expected = %d\n", supplyCount(duchy,&G), victoryAmount2);
			printf("province count = %d, expected = %d\n", supplyCount(province,&G), victoryAmount2);
			assert(supplyCount(estate,&G) == victoryAmount2);
			assert(supplyCount(duchy,&G) == victoryAmount2);
			assert(supplyCount(province,&G) == victoryAmount2);		
		}
		//Kingdom Checks
		printf("Checking Kingdom cards...");
		for (j=0; j<10; j++)
		{
			if (z[j] == great_hall || z[j] == gardens){
				if(i == 2){
					r = supplyCount(z[j],&G);
					assert(r == victoryAmount);
				}else{
					r = supplyCount(z[j],&G);
					assert(r == victoryAmount2);
				}
			}else{
				r = supplyCount(z[j],&G);
				assert(r == kingdomAmount);
			}
		}
		printf("PASSED\n");
		printf("\nALL CARD PILES PASSED\n");
		printf("\nChecking Player State...");
		
		assert(G.outpostPlayed == initOutpostPlayed);
		assert(G.phase == initPhase);
		assert(G.numActions == initActions);
		assert(G.numBuys == initBuys);
		assert(G.playedCardCount == initplayedCards);
		assert(G.whoseTurn == initTurn);
		
		printf("PASSED\n");
	}
	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTFUNCTION);


	return 0;
}


