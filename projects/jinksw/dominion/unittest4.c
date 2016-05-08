/* -----------------------------------------------------------------------
		Unit Testing for isGameOver() function in dominion.c
		**Used testUpdateCoins.c template for reference

		--isGameOver()--
		Description: Checks number of provinces=0 or three supply piles=0 to determine if game is over

		Input:  struct gameState *state
		Return: 0 on if game is not over, 1 if game is over
		
		Basic Requirements
			1. If Province pile is Empty or 3 Supply piles are empty, game state should be over
			2. If province pile isn't empty and 0, 1, or 2 supply piles are empty game state should not be over		

 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <assert.h>
#include <stdlib.h>

int main() {

		//Initialize Game
    int seed = 777;
		int players = 2;
    int k[10] = {smithy, village, council_room, adventurer, feast
               , gardens, mine, remodel, baron, great_hall};
    struct gameState gState, gTest;
		initializeGame( players, k, seed, &gState );
		
		int failFlag = 0;
		int successCount = 0;
		int returnVal;

    printf ("TESTING isGameOver():\n");
		
		//_____________________________
		//Test 1: No province cards remain: game over
		printf ("***TEST 1: If No Province Cards Remain, isGameOver returns 1***\n");
		memcpy( &gTest, &gState, sizeof(struct gameState));
		
		gTest.supplyCount[province] = 0;
		returnVal = isGameOver( &gTest );		

		printf( "GameOver Returns = %d, expected = 1\n", returnVal  );
		if( returnVal != 1 ){
			printf( "TEST 1 Failed: isGameOver doesn't return 1\n" );
			failFlag = 1;
		} 
		if( failFlag == 0 ){
			printf( "TEST 1 Passed: isGameOver returns 1\n" );
			successCount++;
		}

		//_____________________________
		//Test 2: 3 Supply Piles are at 0, game over
		failFlag = 0;
		printf ("***TEST 2: 3 Supply Piles are at 0, isGameOver returns 1***\n");
		memcpy( &gTest, &gState, sizeof(struct gameState));
		
		gTest.supplyCount[copper] = 0;
		gTest.supplyCount[adventurer] = 0;
		gTest.supplyCount[smithy] = 0;

		returnVal = isGameOver( &gTest );		

		printf( "GameOver Returns = %d, expected = 1\n", returnVal  );
		if( returnVal != 1 ){
			printf( "TEST 2 Failed: isGameOver doesn't return 1\n" );
			failFlag = 1;
		} 
		if( failFlag == 0 ){
			printf( "TEST 2 Passed: isGameOver returns 1\n" );
			successCount++;
		}
		
		//_____________________________
		//Test 3: Province > 0 && 0  Supply Piles are at 0, game not over
		failFlag = 0;
		printf ("***TEST 2: Province is greater than 0, and No Supply Piles are at 0, isGameOver returns 0***\n");
		memcpy( &gTest, &gState, sizeof(struct gameState));
		
		returnVal = isGameOver( &gTest );		

		printf( "GameOver Returns = %d, expected = 0\n", returnVal  );
		if( returnVal != 1 ){
			printf( "TEST 3 Failed: isGameOver doesn't return 0\n" );
			failFlag = 1;
		} 
		if( failFlag == 0 ){
			printf( "TEST 3 Passed: isGameOver returns 0\n" );
			successCount++;
		}
		
		//_____________________________
		//Test 4: Province > 0 && 1 Supply Piles are at 0, game not over
		failFlag = 0;
		printf ("***TEST 4: Province is greater than 0, and 1 Supply Piles are at 0, isGameOver returns 0***\n");
		memcpy( &gTest, &gState, sizeof(struct gameState));
		
		gTest.supplyCount[silver] = 0;
		returnVal = isGameOver( &gTest );		

		printf( "GameOver Returns = %d, expected = 0\n", returnVal  );
		if( returnVal != 1 ){
			printf( "TEST 4 Failed: isGameOver doesn't return 0\n" );
			failFlag = 1;
		} 
		if( failFlag == 0 ){
			printf( "TEST 4 Passed: isGameOver returns 0\n" );
			successCount++;
		}

		//_____________________________
		//Test 5: Province > 0 && 2 Supply Piles are at 0, game not over
		failFlag = 0;
		printf ("***TEST 5: Province is greater than 0, and 1 Supply Piles are at 0, isGameOver returns 0***\n");
		memcpy( &gTest, &gState, sizeof(struct gameState));
		
		gTest.supplyCount[gold] = 0;
		gTest.supplyCount[council_room] = 0;	
		returnVal = isGameOver( &gTest );		

		printf( "GameOver Returns = %d, expected = 0\n", returnVal  );
		if( returnVal != 1 ){
			printf( "TEST 5 Failed: isGameOver doesn't return 0\n" );
			failFlag = 1;
		} 
		if( failFlag == 0 ){
			printf( "TEST 5 Passed: isGameOver returns 0\n" );
			successCount++;
		}
	//Done Testing. Print Unit Test Results
		if( successCount == 5 ){
			printf("All tests passed!\n");
		} else {
			printf("%d tests passed -- %d tests failed\n", successCount, 5-successCount);
		}
    return 0;
}
