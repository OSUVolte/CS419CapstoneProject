/******************************************************************************
* ASSIGNMENT 4 - randomtestcard.c
* AUTHOR: Nickolas A. Williams
* CLASS: CS362
* DATE: 05/08/2016
* NOTES: random testing of the refactored playSmithy() function
* REQUIREMENTS for playSmithy():
*  1. Player draws exactly three cards
*  2. Cards are drawn only from the player's deck
*  3. Smithy card is discarded
* TESTING tasks for playSmithy():
*  1. Test that three cards are added to hand
*  2. Test that three cards are drawn from deck
*  3. Test that smithy card was discarded
*  4. Test that if there are <3 cards in deck, 0/1 or -1 cards were added to
*     hand (deck 0 hand -1, deck 1 hand 0, deck 2 hand 1)
*  5. Test that if there are <3 cards in deck, there are no cards left in deck
*  6. Test that if there are <3 cards in deck, smithy still discarded
*  7. Test that other players' hands were not adjusted
*  8. Test that other players' decks were not adjusted
*  9. Test that other players' discards were not adjusted
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

	printf("TESTING playSmithy():\n");
	
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
		
		//pick random player, verify smithy is in hand, if not give them one
		//then, save state and call playSmithy
		player = rand() % numPlayer;
		int smithyInHand = 0;
		int handPos;
		for (handPos = 0; handPos < StartState.handCount[player]; handPos++)
		{
			if (StartState.hand[player][handPos] == smithy)
			{
				smithyInHand = 1;
				break;
			}
		}
		if (smithyInHand == 0)
		{
			handPos = floor(Random() * StartState.handCount[player]);
			StartState.hand[player][handPos] = smithy;
		}

		//save gamestate for comparison
		memcpy(&TestState, &StartState, sizeof(struct gameState));
		//call playSmithy()
		playSmithy(&TestState, player, handPos);

#if (NOISY_TEST == 1)
		printf("\n=====================================\n");
		printf("==   TEST playSmithy() #%d\n", test);
		printf("=====================================\n");
		printf("Player #%d has smithy card.\n", player);
		printf("Cards: %d hand, %d deck, %d discard\n", StartState.handCount[player], StartState.deckCount[player], StartState.discardCount[player]);
#endif
		//PERFORM TESTS ON ALL PLAYERS
		for (j = 0; j < numPlayer; j++)
		{
#if (NOISY_TEST == 1)
			printf("TESTING PLAYER #%d\n", j);
#endif	
			if (j == player) //current player tested is caller of playSmithy()
			{
#if (NOISY_TEST == 1)
				printf("Testing card counts for smithy player\n");
#endif	
				//test card counts for the test state
				//if there are cards in the deck, test that operations performed normally
				if (StartState.deckCount[j] > 3)
				{
					//test that hand has +2 cards (+3 from deck, -1 smithy card)
					if (TestState.handCount[j] != StartState.handCount[j] + 2)
					{
						case1++;
						errorflag = 1;
					}
					//test that deck has -3 cards
					if (TestState.deckCount[j] != StartState.deckCount[j] - 3)
					{
						case2++;
						errorflag = 1;
					}
					//test that discard has +1 cards (smithy card)
					if (TestState.discardCount[j] != StartState.discardCount[j] + 1)
					{
						case3++;
						errorflag = 1;
					}
#if (NOISY_TEST == 1)
					printf("Smithy player has: %d hand, %d deck, %d discard.\n", TestState.handCount[j], TestState.deckCount[j], TestState.discardCount[j]);
					printf("         Expected: %d hand, %d deck, %d discard.\n", StartState.handCount[j] + 2, StartState.deckCount[j] - 3, StartState.discardCount[j] + 1);
#endif			
				}
				//there are less than 3 cards in deck to draw, so those should get drawn
				else
				{
					//test that hand has -1 cards (smithy discarded)
					if (TestState.handCount[j] != StartState.handCount[j] + (StartState.deckCount[j] - 1))
					{
						case4++;
						errorflag = 1;
					}
					//test that deck is now empty (either started with 0 cards, or all cards drawn)
					if (TestState.deckCount[j] != 0)
					{
						case5++;
						errorflag = 1;
					}
					//test that smithy has been discarded
					if (TestState.discardCount[j] != StartState.discardCount[j] + 1)
					{
						case6++;
						errorflag = 1;
					}
#if (NOISY_TEST == 1)
					printf("Smithy player has: %d hand, %d deck, %d discard.\n", TestState.handCount[j], TestState.deckCount[j], TestState.discardCount[j]);
					printf("         Expected: %d hand, %d deck, %d discard.\n", StartState.handCount[j] + StartState.deckCount[j], 0, TestState.discardCount[j] + 1);
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

				//test deckcount
				if (TestState.deckCount[j] != (StartState.deckCount[j]))
				{
					case8++;
					errorflag = 1;
				}
				
				//test discardcount
				if (TestState.discardCount[j] != (StartState.discardCount[j]))
				{
					case9++;
					errorflag = 1;
				}
#if (NOISY_TEST == 1)
				printf("Non-smithy player has: %d hand, %d deck, %d discard.\n", TestState.handCount[j], TestState.deckCount[j], TestState.discardCount[j]);
				printf("             Expected: %d hand, %d deck, %d discard.\n", StartState.handCount[j], StartState.deckCount[j], TestState.discardCount[j]);
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
		printf("\n===============================================\n");
		printf("== TEST REPORT FOR playSmithy(), %d TESTS\n", NUM_TESTS);
		printf("===============================================\n");
		printf("Failed tests:\n");
		if (case1 > 0) 
		{ 
			printf("Smithy player's hand has +3 cards: %d failed\n", case1);
		}
		if (case2 > 0)
		{ 
			printf("Smithy player's deck has -3 cards: %d failed\n", case2);
		}
		if (case3 > 0)
		{ 
			printf("Smithy player's discard has +1 cards: %d failed\n", case3);
		}
		if (case4 > 0)
		{ 
			printf("SPECIAL CASE, smithy player's hand added 0/1 or -1 cards: %d failed\n", case4);
		}
		if (case5 > 0)
		{ 
			printf("SPECIAL CASE, smithy player's deck has 0 cards: %d failed\n", case5);
		}
		if (case6 > 0)
		{ 
			printf("SPECIAL CASE, smithy player's discard has +1 cards: %d failed\n", case6);
		}
		if (case7 > 0)
		{ 
			printf("Another player's hand adjusted: %d failed\n", case7);
		}
		if (case8 > 0)
		{ 
			printf("Another player's deck adjusted: %d failed\n", case8);
		}
		if (case9 > 0)
		{ 
			printf("Another player's discard adjusted: %d failed\n", case9);
		}
		printf("\n");
	}
	return 0;
}