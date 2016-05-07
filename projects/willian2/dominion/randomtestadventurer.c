/******************************************************************************
* ASSIGNMENT 4 - randomtestadventurer.c
* AUTHOR: Nickolas A. Williams
* CLASS: CS362
* DATE: 05/08/2016
* NOTES: random testing of the refactored playAdventurer() function
* REQUIREMENTS for playAdventurer():
*  1. Draw cards from deck and discard pile until two treasure cards are drawn
*  2. Discard cards drawn that are not treasure cards
*  3. All cards must be drawn from the player's deck/discard
*  4. Adventurer card is discarded
* TESTING tasks for playAdventurer():
*  1. Test that two cards are added to hand
*  2. Test that two cards are drawn from deck and discard pile
*  3. Test that player ends up with one more card in hand than start (+2 treasure,
*     -1 adventurer card)
*  4. Test that if there are <2 treasure, 1/0 treasure cards added to hand
*  5. Test that if there are <2 treasure, 1/0 cards removed from deck/discard
*  6. Test that if there are <2 treasure, player ends up with 0 or -1 card in
*     hand than start (+1/0 treasure, -1 adventurer card)
*  7. Test that other players' hands are not adjusted
*  8. Test that other players' decks are not adjuste
*  9. Test that other players' discards are not adjusted
******************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 0
// set number of tests to perform
#define NUM_TESTS 10000
//number of cards in the game as of this build
#define CARDS_IN_GAME 26

int main() 
{
	int i, j;
    int test, player;
    int seed, numPlayer;
    int r, handCount;
	int maxHandCount = 10;
    int trashflag;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState StartState;
	struct gameState TestState;
	int errorflag, generalErrorFlag;
	srand(time(NULL));
	int case1 = 0;
	int case2 = 0;
	int case3 = 0;
	int case4 = 0;
	int case5 = 0;
	int case6 = 0;
	int case7 = 0;
	int case8 = 0;
	int case9 = 0;

	printf("TESTING playAdventurer():\n");
	
	for (test = 0; test < NUM_TESTS; test++)
	{
		seed = rand(); //provide dominion's fancy RNGesus with a random number
		numPlayer = (rand() % 3) + 2; //no fewer than 2 players, no more than 4
		errorflag = 0;
		
		memset(&StartState, 23, sizeof(struct gameState)); //ensures state clear
		initializeGame(numPlayer, k, seed, &StartState);
		
		//create hands for every player
		for (player = 0; player < numPlayer; player++) //for each player
		{
			//give player random number of cards in deck, discard, & hand
			StartState.deckCount[player] = floor(Random() * MAX_DECK);
			StartState.discardCount[player] = floor(Random() * MAX_DECK);
			StartState.handCount[player] = floor(Random() * MAX_HAND);
			
			for (i = 0; i < StartState.deckCount[player]; i++)
			{
				//fill deck with random cards
				StartState.deck[player][i] = floor(Random() * CARDS_IN_GAME);
			}
			for (i = 0; i < StartState.discardCount[player]; i++)
			{
				//fill discard with random cards
				StartState.discard[player][i] = floor(Random() * CARDS_IN_GAME);
			}
			for (i = 0; i < StartState.handCount[player]; i++)
			{
				//fill hand with random cards
				StartState.hand[player][i] = floor(Random() * CARDS_IN_GAME);
			}
		}
		
		//pick random player, verify adventurer is in hand, if not give them one
		//then, save state and call playAdventurer
		player = rand() % numPlayer;
		int adventurerInHand = 0;
		int handPos;
		for (handPos = 0; handPos < StartState.handCount[player]; handPos++)
		{
			if (StartState.hand[player][handPos] == adventurer)
			{
				adventurerInHand = 1;
				break;
			}
		}
		if (adventurerInHand == 0)
		{
			handPos = floor(Random() * StartState.handCount[player]);
			StartState.hand[player][handPos] = adventurer;
		}

		//count where all the treasure cards are
		int treasureInHand = 0;
		int treasureInDeck = 0;
		int treasureInDiscard = 0;
		int lessThanTwoTreasures = -1;
		for (i = 0; i < StartState.handCount[player]; i++)
		{
			if (StartState.hand[player][i] == copper ||
				StartState.hand[player][i] == silver ||
				StartState.hand[player][i] == gold)
			{
				treasureInHand++;
			}
		}			
		for (i = 0; i < StartState.deckCount[player]; i++)
		{
			if (StartState.deck[player][i] == copper ||
				StartState.deck[player][i] == silver ||
				StartState.deck[player][i] == gold)
			{
				treasureInDeck++;
			}
		}
		for (i = 0; i < StartState.discardCount[player]; i++)
		{
			if (StartState.discard[player][i] == copper ||
				StartState.discard[player][i] == silver ||
				StartState.discard[player][i] == gold)
			{
				treasureInDiscard++;
			}
		}
		//lessThanTwoTreasures > -1 if there are less than 2 treasures to draw
		//otherwise, we will later check to see if it's -1 to indicate this special case
		if ((treasureInDeck + treasureInDiscard < 2))
		{
			lessThanTwoTreasures = treasureInDeck + treasureInDiscard;
		}

		//save gamestate for comparison
		memcpy(&TestState, &StartState, sizeof(struct gameState));
		//call playAdventurer()
		playAdventurer(&TestState, player, handPos);

#if (NOISY_TEST == 1)
		printf("\n===========================\n");
		printf("==   TEST #%d\n", test);
		printf("===========================\n");
		printf("Player #%d has adventurer card.\n", player);
		printf("Treasures: %d hand, %d deck, %d discard, %d deck + discard\n", treasureInHand, treasureInDeck, treasureInDiscard, treasureInDeck + treasureInDiscard);
#endif
		//PERFORM TESTS ON ALL PLAYERS
		for (j = 0; j < numPlayer; j++)
		{
#if (NOISY_TEST == 1)
			printf("TESTING PLAYER #%d\n", j);
#endif	
			if (j == player) //current player tested is caller of playAdventurer()
			{
#if (NOISY_TEST == 1)
				printf("Testing treasure card counts for adventurer player\n");
#endif	
				//now test the treasure card counts for the test state
				int testTreasureInHand = 0;
				int testTreasureInDeck = 0;
				int testTreasureInDiscard = 0;
				for (i = 0; i < TestState.handCount[j]; i++)
				{
					if (TestState.hand[j][i] == copper ||
						TestState.hand[j][i] == silver ||
						TestState.hand[j][i] == gold)
					{
						testTreasureInHand++;
					}
				}			
				for (i = 0; i < TestState.deckCount[j]; i++)
				{
					if (TestState.deck[j][i] == copper ||
						TestState.deck[j][i] == silver ||
						TestState.deck[j][i] == gold)
					{
						testTreasureInDeck++;
					}
				}
				for (i = 0; i < TestState.discardCount[j]; i++)
				{
					if (TestState.discard[j][i] == copper ||
						TestState.discard[j][i] == silver ||
						TestState.discard[j][i] == gold)
					{
						testTreasureInDiscard++;
					}
				}
				
				//if there are at least two treasure in deck/discard, lessThanTwoTreasures
				//will be -1, otherwise it will be 0 (no treasures) or 1 (1 treasure)
				if (lessThanTwoTreasures == -1)
				{
					//test that hand has +2 treasures
					if (testTreasureInHand != (treasureInHand + 2))
					{
						case1++;
						errorflag = 1;
					}
					//test that deck + discard is -2 treasures
					if ((testTreasureInDeck + testTreasureInDiscard) != (treasureInDeck + treasureInDiscard - 2))
					{
						case2++;
						errorflag = 1;
					}
#if (NOISY_TEST == 1)
					printf("Adventurer player has %d treasures in hand, %d treasures in deck and discard.\n", testTreasureInHand, testTreasureInDeck + testTreasureInDiscard);
					printf("             Expected %d treasures in hand, %d treasures in deck and discard.\n", (treasureInHand + 2), (treasureInDeck + treasureInDiscard - 2));
#endif				
					//test that hand count is up by 1
					if (TestState.handCount[j] != (StartState.handCount[j] + 1))
					{
						case3++;
						errorflag = 1;
					}
#if (NOISY_TEST == 1)
					printf("TestState.handCount[%d] = %d, expected = %d\n", j, TestState.handCount[j], StartState.handCount[j] + 1);
#endif
				}
				
				//there are only 1 or 0 treasure cards to put into player's hand
				else
				{
					//test that either 1 or 0 cards have been placed in hand
					if ((testTreasureInHand + lessThanTwoTreasures) != (treasureInHand + lessThanTwoTreasures))
					{
						case4++;
						errorflag = 1;
					}
					//test that either 1 or 0 cards have been removed from deck/discard
					if ((testTreasureInDeck + testTreasureInDiscard - lessThanTwoTreasures) != (treasureInDeck + treasureInDiscard - lessThanTwoTreasures))
					{
						case5++;
						errorflag = 1;
					}
#if (NOISY_TEST == 1)
					printf("Adventurer player has %d treasures in hand, %d treasures in deck and discard.\n", testTreasureInHand, testTreasureInDeck + testTreasureInDiscard);
					printf("             Expected %d treasures in hand, %d treasures in deck and discard.\n", (treasureInHand + lessThanTwoTreasures), (treasureInDeck + treasureInDiscard - lessThanTwoTreasures));
#endif				
					//test that hand count is up by 0 (replace advent w/treasure) or down by 1 (no treasure, discard adven)
					if (TestState.handCount[j] != (StartState.handCount[j] + (lessThanTwoTreasures - 1)))
					{
						case6++;
						errorflag = 1;
					}
#if (NOISY_TEST == 1)
					printf("TestState.handCount[%d] = %d, expected = %d\n", j, TestState.handCount[j], StartState.handCount[j] + (lessThanTwoTreasures - 1));
#endif
				}
			}

			//test the rest of the players
			else
			{
				//test handcount
				if (TestState.handCount[j] != (StartState.handCount[j]))
				{	
					case7++;
					errorflag = 1;
				}
#if (NOISY_TEST == 1)
				printf("TestState.handCount[%d] = %d, expected = %d\n", j, TestState.handCount[j], StartState.handCount[j]);
#endif

				//test deckcount
				if (TestState.deckCount[j] != (StartState.deckCount[j]))
				{
					case8++;
					errorflag = 1;
				}
#if (NOISY_TEST == 1)
				printf("TestState.deckCount[%d] = %d, expected = %d\n", j, TestState.deckCount[j], StartState.deckCount[j]);
#endif	
				
				//test discardcount
				if (TestState.discardCount[j] != (StartState.discardCount[j]))
				{
					case9++;
					errorflag = 1;
				}
#if (NOISY_TEST == 1)
				printf("TestState.discardCount[%d] = %d, expected = %d\n", j, TestState.discardCount[j], StartState.discardCount[j]);
#endif	
			}
		}
		if (errorflag = 1)
		{
			generalErrorFlag = 1;
#if (NOISY_TEST == 1)
			printf("TEST #%d has failed.\n", test);
#endif	
		}
	}
	
	//give error even if not in NOISY_TEST mode
	if (generalErrorFlag)
	{
		printf("\n===========================\n");
		printf("== TEST REPORT FOR %d TESTS\n", NUM_TESTS);
		printf("===========================\n");
		printf("Failed tests:\n");
		if (case1 > 0) 
		{ 
			printf("Adventurer player's hand has +2 treasures: %d failed\n", case1);
		}
		if (case2 > 0)
		{ 
			printf("Adventurer player's deck + discard -2 treasures: %d failed\n", case2);
		}
		if (case3 > 0)
		{ 
			printf("Adventurer player's handCount +1: %d failed\n", case3);
		}
		if (case4 > 0)
		{ 
			printf("SPECIAL CASE, adventurer player's hand +1/0 if <2 treasures: %d failed\n", case4);
		}
		if (case5 > 0)
		{ 
			printf("SPECIAL CASE, adventurer player's deck + discard -1/0 if <2 treasures: %d failed\n", case5);
		}
		if (case6 > 0)
		{ 
			printf("SPECIAL CASE, adventurer player's handCount +0/-1 if <2 treasures: %d failed\n", case6);
		}
		if (case7 > 0)
		{ 
			printf("Another player's handCount adjusted: %d failed\n", case7);
		}
		if (case8 > 0)
		{ 
			printf("Another player's deckCount adjusted: %d failed\n", case8);
		}
		if (case9 > 0)
		{ 
			printf("Another player's discardCount adjusted: %d failed\n", case9);
		}
		printf("\n");
	}
	return 0;
}