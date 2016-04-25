/* -----------------------------------------------------------------------
		Unit Testing for buyCard() function in dominion.c
		**Used testUpdateCoins.c template for reference

		--buyCard()--
		Description: For a player, sets coins for player for that turn to equal
			the sum of the value of treasure cards in the player's hand plus bonus.

		Input: int player, struct gameState *state, int bonus
		Return: 0 on success
		
		Algorithm PseudoCode
			1. sets *state for coins to 0
			2. Loops over handCount for the player ( number of cards in player's hand)
				2.a. For each copper in the hand, add 1 to coins
				2.b. For each silver is in the hand, add 2 to coins
				2.c. For each gold in in the hand, add 3 to coins  
				note: implemented as a Loop from zero to handcount, using if statements at 
						each iteration
			3. Add bonus to coins
			4. return 0 on success
		
		Basic Requirements:
			1. All cards in a player's hand should be evaluated
			2. {Copper, Silver, Gold} should increment coins by {1,2,3}
			3. Bonus should be added to the total
			4. Other game state values shouldn't be effected

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
		int i;
    int seed = 777;
		int players = 2;
		int player = 1;
    int bonus = 0;
    int k[10] = {smithy, village, council_room, adventurer, feast
               , gardens, mine, remodel, baron, great_hall};
    struct gameState gState, gTest;
		initalizeGame( players, k, seed, &gState );
		
		gTest.coins = 0;
		int handCount = 5;
		int bronze = 1;
		int silver = 2;
		int gold = 3;
		int failFlag = 0;
		int successCount = 0;

    printf ("TESTING updateCoins():\n");
		
		//_____________________________
		//Test 1: All Bronze Cards. Bonus=0. Coin Count should equal 5
		printf ("***TEST 1: Hand Contains All Copper Cards & No Bonus***\n");
		memcpy( &gTest, &gState, sizeof(struct gameState));
		for( i=0; i < handCount; i++ ){
			gTest.hand[player][i] = copper;
		} 

		gTest.handCount[player] = handCount;
		updateCoins( player, &gTest, bonus );
		printf( "Coins = %d, expected = 5\n", gTest.coins );
		if( !(gTest.coins == handCount * bronze + bonus) ){
			printf( "TEST 1 Failed: G.coins != handCount * bronze + bonus\n" );
			failFlag = 1;
		} 
		if ( !(gTest.coins == 5 ) ){
			printf( "TEST 1 Failed: G.coins != 5\n" );
			failFlag = 1;
		} 
		if( failFlag == 0 ){
			printf( "TEST 1 Passed: G.coins = 5 = handCount * bronze + bonus\n" );
			successCount++;
		}
		
		//_____________________________
		//Test 2: All Silver Cards. Bonus=0. Coin Count should equal 10
		failFlag = 0;
		printf ("***TEST 2: Hand Contains All Silver Cards & No Bonus***\n");
		memcpy( &gTest, &gState, sizeof(struct gameState));
		for( i=0; i < handCount; i++ ){
			gTest.hand[player][i] = silver;
		} 

		gTest.handCount[player] = handCount;
		updateCoins( player, &gTest, bonus );
		printf( "Coins = %d, expected = 10\n", gTest.coins );
		if( !(gTest.coins == handCount * silver + bonus) ){
			printf( "TEST 2 Failed: G.coins != handCount * silver + bonus\n" );
			failFlag = 1;
		} 
		if ( !(gTest.coins == 10 ) ){
			printf( "TEST 2 Failed: G.coins != 10\n" );
			failFlag = 1;
		} 
		if( failFlag == 0 ){
			printf( "TEST 2 Passed: G.coins = 10 = handCount * silver + bonus\n" );
			successCount++;
		}

		//_____________________________
		//Test 3: All Gold Cards. Bonus=0. Coin Count should equal 15
		failFlag = 0;
		printf ("***TEST 3: Hand Contains All Gold Cards & No Bonus***\n");
		memcpy( &gTest, &gState, sizeof(struct gameState));
		for( i=0; i < handCount; i++ ){
			gTest.hand[player][i] = gold;
		} 

		gTest.handCount[player] = handCount;
		updateCoins( player, &gTest, bonus );
		printf( "Coins = %d, expected = 15\n", gTest.coins );
		if( !(gTest.coins == handCount * gold + bonus) ){
			printf( "TEST 3 Failed: G.coins != handCount * gold + bonus\n" );
			failFlag = 1;
		} 
		if ( !(gTest.coins == 15 ) ){
			printf( "TEST 3 Failed: G.coins != 15\n" );
			failFlag = 1;
		} 
		if( failFlag == 0 ){
			printf( "TEST 3 Passed: G.coins = 15 = (handCount * gold) + bonus\n" );
			successCount++;
		}

		//_____________________________
		//Test 4: No Coin Cards. Bonus=0. Coin Count should equal 0
		failFlag = 0;
		printf ("***TEST 2: Hand Contains All Silver Cards & No Bonus***\n");
		memcpy( &gTest, &gState, sizeof(struct gameState));
		for( i=0; i < handCount; i++ ){
			gTest.hand[player][i] = k[i];
		} 

		gTest.handCount[player] = handCount;
		updateCoins( player, &gTest, bonus );
		printf( "Coins = %d, expected = 0\n", gTest.coins );
		if( !(gTest.coins == handCount * 0 + bonus) ){
			printf( "TEST 4 Failed: G.coins != handCount * 0 + bonus\n" );
			failFlag = 1;
		} 
		if ( !(gTest.coins == 0 ) ){
			printf( "TEST 4 Failed: G.coins != 0\n" );
			failFlag = 1;
		} 
		if( failFlag == 0 ){
			printf( "TEST 4 Passed: G.coins = 0 = handCount * 0 * bonus\n" );
			successCount++;
		}

		//_____________________________
		//Test 5: Mix of Coin Cars. Bonus=0. Coin Count should equal 3+4+3 = 10
		failFlag = 0;
		printf ("***TEST 5: Hand Contains Mix of all coins: 3-Bronze, 2-Silver, 1-Gold Cards & No Bonus***\n");
		memcpy( &gTest, &gState, sizeof(struct gameState));
		for( i=0; i < handCount; i++ ){
			if( i == 0 ){
				gTest.hand[player][i] = gold;
			} else if( i == 1 || i == 2 ){
				gTest.hand[player][i] = silver;
			} else {	
				gTest.hand[player][i] = bronze;
			}
		} 

		gTest.handCount[player] = handCount;
		updateCoins( player, &gTest, bonus );
		printf( "Coins = %d, expected = 10\n", gTest.coins );
		if( !(gTest.coins == gold + (2 * silver) + (3*bronze) + bonus) ){
			printf( "TEST 5 Failed: G.coins != gold + 2*silver + 2*bronze + bonus\n" );
			failFlag = 1;
		} 
		if ( !(gTest.coins == 10 ) ){
			printf( "TEST 5 Failed: G.coins != 10\n" );
			failFlag = 1;
		} 
		if( failFlag = 0 ){
			printf( "TEST 6 Passed: G.coins = 10 = gold + 2*silver + 2*bronze + bonus\n" );
			successCount++;
		}

		//_____________________________
		//Test 6: Mix of Coin Cards with Bonus=2. Coin Count should equal 3+4+3+2 = 12
		failFlag = 0;
		printf ("***TEST 5: Hand Contains Mix of all coins: 3-Bronze, 2-Silver, 1-Gold Cards & No Bonus***\n");
		memcpy( &gTest, &gState, sizeof(struct gameState));
		for( i=0; i < handCount; i++ ){
			if( i == 0 ){
				gTest.hand[player][i] = gold;
			} else if( i == 1 || i == 2 ){
				gTest.hand[player][i] = silver;
			} else {	
				gTest.hand[player][i] = bronze;
			}
		} 

		bonus = 2;
		gTest.handCount[player] = handCount;
		updateCoins( player, &gTest, bonus );
		printf( "Coins = %d, expected = 12\n", gTest.coins );
		if( !(gTest.coins == gold + (2 * silver) + (3*bronze) + bonus) ){
			printf( "TEST 6 Failed: G.coins != gold + 2*silver + 2*bronze + bonus\n" );
			failFlag = 1;
		} 
		if ( !(gTest.coins == 12 ) ){
			printf( "TEST 6 Failed: G.coins != 12\n" );
			failFlag = 1;
		} 
		if( failFlag = 0 ){
			printf( "TEST 6 Passed: G.coins = 12 = gold + 2*silver + 2*bronze + bonus\n" );
			successCount++;
		}

		//_____________________________
		//Test 7: Mix of Coin Cards & 1 Non Coin Cards. Bonus=0.
		// Coin Count should equal Bronze:2 + Silver:1 + Gold:1 = 7
		failFlag = 0;
		printf ("***TEST 7: Hand Contains Mix of all coins and 1 non coin cards: 2-Bronze, 1-Silver, 1-Gold Cards & No Bonus***\n");
		memcpy( &gTest, &gState, sizeof(struct gameState));
		for( i=0; i < handCount; i++ ){
			if( i == 0 ){
				gTest.hand[player][i] = gold;
			} else if( i == 1 ){
				gTest.hand[player][i] = silver;
			} else if( i == 2 || i == 3 ){
				gTest.hand[player][i] = bronze;
			} else {
				gTest.hand[player][i] = k[i];
			}
		} 

		bonus = 0;
		gTest.handCount[player] = handCount;
		updateCoins( player, &gTest, bonus );
		printf( "Coins = %d, expected = 7\n", gTest.coins );
		if( !(gTest.coins == gold +  silver + (2*bronze) + bonus) ){
			printf( "TEST 7 Failed: G.coins != gold + silver + 2*bronze + bonus\n" );
			failFlag = 1;
		} 
		if ( !(gTest.coins == 7 ) ){
			printf( "TEST 7 Failed: G.coins != 7\n" );
			failFlag = 1;
		} 
		if( failFlag = 0 ){
			printf( "TEST 7 Passed: G.coins = 7 = gold + silver + 2*bronze + bonus\n" );
			successCount++;
		}
		
		//_____________________________
		//Test 8: Mix of Coin Cards & 1 Non Coin Cards. Bonus=2.
		// Coin Count should equal Bronze:2 + Silver:1 + Gold:1 + 2 = 9
		failFlag = 0;
		printf ("***TEST 8: Hand Contains Mix of all coins and 1 non coin cards: 2-Bronze, 1-Silver, 1-Gold Cards & 2 Bonus***\n");
		memcpy( &gTest, &gState, sizeof(struct gameState));
		for( i=0; i < handCount; i++ ){
			if( i == 0 ){
				gTest.hand[player][i] = gold;
			} else if( i == 1 ){
				gTest.hand[player][i] = silver;
			} else if( i == 2 || i == 3 ){
				gTest.hand[player][i] = bronze;
			} else {
				gTest.hand[player][i] = k[i];
			}
		} 

		bonus = 2;
		gTest.handCount[player] = handCount;
		updateCoins( player, &gTest, bonus );
		printf( "Coins = %d, expected = 9\n", gTest.coins );
		if( !(gTest.coins == gold +  silver + (2*bronze) + bonus) ){
			printf( "TEST 9 Failed: G.coins != gold + silver + 2*bronze + bonus\n" );
			failFlag = 1;
		} 
		if ( !(gTest.coins == 9 ) ){
			printf( "TEST 9 Failed: G.coins != 9\n" );
			failFlag = 1;
		} 
		if( failFlag = 0 ){
			printf( "TEST 8 Passed: G.coins = 9 = gold + silver + 2*bronze + bonus\n" );
			successCount++;
		}

		//_____________________________
		// Test 9: Coins = 0, Bonus =2, Expected Value = 4
		failFlag = 0;
		printf ("***TEST 9: No Coins, 4 Bonus, Expected value = 4\n");
		memcpy( &gTest, &gState, sizeof(struct gameState));
		for( i=0; i < handCount; i++ ){
				gTest.hand[player][i] = k[i];
		} 

		bonus = 4;
		gTest.handCount[player] = handCount;
		updateCoins( player, &gTest, bonus );
		printf( "P1 Coins = %d, expected = 4", gTest.coins );
		if( !(gTest.coins ==  bonus) ){
			printf( "TEST 9 Failed: G.coins != 0 + bonus\n" );
			failFlag = 1;
		} 
		if ( !(gTest.coins == 4 ) ){
			printf( "TEST 9 Failed: G.coins != 4\n" );
			failFlag = 1;
		} 
		if( failFlag = 0 ){
			printf( "TEST 9 Passed: G.coins = 4 =  bonus\n" );
			successCount++;
		}
		
		//_____________________________
		// Test 10: Was whoseTurn effected?
		//Coins = 0, Bonus =0, Expected Value = 0
		failFlag = 0;
		printf ("***TEST 10: whoseTurn Game States Shouldn't Change. No Coins, 0 Bonus, Expected value = 0\n");
		memcpy( &gTest, &gState, sizeof(struct gameState));
		for( i=0; i < handCount; i++ ){
				gTest.hand[player][i] = k[i];
		} 

		bonus = 0;
		gTest.handCount[player] = handCount;
		gTest.whoseTurn = 1;
		updateCoins( player, &gTest, bonus );
		printf( "Whose Turn = %d, expected = 1", gTest.whoseTurn );
		if( !(gTest.whoseTurn ==  1) ){
			printf( "TEST 10 Failed: G.whoseTurn != 1\n" );
			failFlag = 1;
		} else {
			printf( "TEST 10 Passed: G.whoseTurn = 1\n" );
			successCount++;
		}
		
		//_____________________________
		// Test 11: Was numAction effected?
		//Coins = 0, Bonus =0, Expected Value = 0
		failFlag = 0;
		printf ("***TEST 11: numActions game state should equal 1. No Coins, 0 Bonus, Expected value = 0\n");
		memcpy( &gTest, &gState, sizeof(struct gameState));
		for( i=0; i < handCount; i++ ){
				gTest.hand[player][i] = k[i];
		} 

		bonus = 0;
		gTest.handCount[player] = handCount;
		gTest.numActions = 1;
		updateCoins( player, &gTest, bonus );
		printf( "numActions = %d, expected = 1", gTest.numActions );
		if( !(gTest.numActions ==  1) ){
			printf( "TEST 11 Failed: G.whoseTurn != 1\n" );
			failFlag = 1;
		} else {
			printf( "TEST 11 Passed: G.whoseTurn = 1\n" );
			successCount++;
		}

		//_____________________________
		// Test 12: Was numBuys effected?
		//Coins = 0, Bonus =0, Expected Value = 0
		failFlag = 0;
		printf ("***TEST 12: numBuys game state should equal 1. No Coins, 0 Bonus, Expected value = 0\n");
		memcpy( &gTest, &gState, sizeof(struct gameState));
		for( i=0; i < handCount; i++ ){
				gTest.hand[player][i] = k[i];
		} 

		bonus = 0;
		gTest.handCount[player] = handCount;
		gTest.numBuys = 1;
		updateCoins( player, &gTest, bonus );
		printf( "numBuys = %d, expected = 1", gTest.numBuys );
		if( !(gTest.numBuys ==  1) ){
			printf( "TEST 12 Failed: G.numBuys != 1\n" );
			failFlag = 1;
		} else {
			printf( "TEST 12 Passed: G.numBuys = 1\n" );
			successCount++;
		}


		//_____________________________
		// Test 13: Was playedCardCount effected?
		//Coins = 0, Bonus =0, Expected Value = 0
		failFlag = 0;
		printf ("***TEST 13: playedCardCount game state should equal 0. No Coins, 0 Bonus, Expected value = 0\n");
		memcpy( &gTest, &gState, sizeof(struct gameState));
		for( i=0; i < handCount; i++ ){
				gTest.hand[player][i] = k[i];
		} 

		bonus = 0;
		gTest.handCount[player] = handCount;
		gTest.playedCardCount = 0;
		updateCoins( player, &gTest, bonus );
		printf( "playedCardCount = %d, expected = 0", gTest.playedCardCount );
		if( !(gTest.playedCardCount ==  0) ){
			printf( "TEST 13 Failed: G.playedCardCount != 0\n" );
			failFlag = 1;
		} else {
			printf( "TEST 13 Passed: G.playedCardCount = 0\n" );
			successCount++;
		}


	//Done Testing. Print Unit Test Results
		if( successCount == 13 ){
			printf("All tests passed!\n");
		} else {
			printf("%d tests passed -- %d tests failed\n", successCount, 9-successCount);

    return 0;
}
