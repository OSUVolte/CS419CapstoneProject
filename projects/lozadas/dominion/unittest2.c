/* -----------------------------------------------------------------------
*Name: Suyana Lozada 
*Unit Test # 2 
*isGameOver() 
*Reference:testUpdateCoins.c and carditest4.c  
*Test description:
*Determine if the game is over after game initialization, stack of province cards is empty, if three supply cards are empty 
* -----------------------------------------------------------------------
 */
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 5;
    int p, r, handCount;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G,testG;
    int maxHandCount = 5;
    
	printf ("Unit Test #2 \n");
    printf ("TESTING isGameOver():\n");

	//Clear Game state and initialize new game  
     memset(&G, 23, sizeof(struct gameState));   // clear the game state
     r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

	//Copy game state to a test state 
	memcpy(&testG,&G,sizeof(struct gameState));

	printf ("TESTING if game is over after game initialization:\n");
	if(isGameOver(&testG)==isGameOver(&G))	
	{
		printf("PASS:test: %d, expected:%d \n",isGameOver(&testG),isGameOver(&G)); 	
	}
	else
	{
		printf("FAIL:test: %d, expected:%d \n",isGameOver(&testG),isGameOver(&G)); 	
	}
	printf ("TESTING if game is over when stack of Province cards is empty:\n");
	testG.supplyCount[province]=0;
	if(isGameOver(&testG)!=isGameOver(&G))	
	{
		printf("PASS:test: %d, expected:%d \n",isGameOver(&testG),!isGameOver(&G)); 	
	}
	else
	{
		printf("FAIL:test: %d, expected:%d \n",isGameOver(&testG),!isGameOver(&G)); 	
	}
	
	printf ("TESTING if game is over when 1 supply pile is empty:\n");
	//Clear Game state and initialize new game 
    memset(&testG, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
	testG.supplyCount[village]=0;
	
	if(isGameOver(&testG)==isGameOver(&G))	
	{
		printf("PASS:test: %d, expected:%d \n",isGameOver(&testG),isGameOver(&G)); 	
	}
	else
	{
		printf("FAIL:test: %d, expected:%d \n",isGameOver(&testG),isGameOver(&G)); 	
	}
	printf ("TESTING if game is over when 3 supply piles are empty:\n");
	//Clear Game state and initialize new game 
	testG.supplyCount[gardens]=0;
	testG.supplyCount[mine]=0;
	if(isGameOver(&testG)!=isGameOver(&G))	
	{
		printf("PASS:test: %d, expected:%d \n",isGameOver(&testG),!isGameOver(&G)); 	
	}
	else
	{
		printf("FAIL:test: %d, expected:%d \n",isGameOver(&testG),!isGameOver(&G)); 	
	}
    printf("End Unit Test #2\n");

    return 0;
}
