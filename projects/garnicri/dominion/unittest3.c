//Unit test 3: fullDeckCount
//Rick Garnica
//CS 362

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>



int main(int argc, char const *argv[]){
	int r;
	int player;
	int numPlayer = 2;
	int seed = 1000;
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	struct gameState game;
	int totalCount;
	int deckCount;
	int handCount;
	int discardCount;
	int maxCards = 10; 
	int testResult;
	const char* cards[] = 
	{
		"curse","estate","duchy","province","copper","silver","gold","adventurer","council_room","feast","gardens","mine","remodel","smithy",
		"village","baron","great_hall","minion","steward","tribute","ambassador","cutpurse","embargo","outpost","salvager","sea_hag","treasure_map"
	};

	int numTests = 0; 
	int failedTests = 0;
	int passedTests = 0;

	printf("==============================================\r\n");
	printf("\n   Beginning testing for fullDeckCount():\r\n");
	printf("==============================================\r\n");

	for (player = 0; player < numPlayer; player++)
	{
		int i;
		int j;
		for (i = 0; i <= 26; i++) 
		{
			for (discardCount = 0; discardCount <= maxCards; discardCount++)
			{
				for (handCount = 0; handCount <= maxCards; handCount++)
				{
					for (deckCount = 0; deckCount <= maxCards; deckCount++)
					{
						totalCount = discardCount + handCount + deckCount;

						printf("Testing player %d with %d total card(s): Deck: %d card(s), Hand: %d card(s), /n Discard pile: %d card(s). Card name: %s \r\n", player, totalCount, deckCount, handCount, discardCount, cards[i]);
						int testDeck[deckCount];
						for (j = 0; j < deckCount; j++)
						{
							testDeck[j] = i;
						}
						int testHand[handCount];
						for (j = 0; j < handCount; j++)
						{
							testHand[j] = i;
						}
						int testDiscard[discardCount];
						for (j = 0; j < discardCount; j++)
						{
							testDiscard[j] = i;
						}
						// clear the game state
						memset(&game, 23, sizeof(struct gameState));   
						// initialize a new game
						r = initializeGame(numPlayer, k, seed, &game); 
						//number of cards on hand
						game.handCount[player] = handCount;        
						//number of cards in deck
						game.deckCount[player] = deckCount;        
						//number of cards in discard pile
						game.discardCount[player] = discardCount;  

						memcpy(game.hand[player], testHand, sizeof(int) * handCount);
						memcpy(game.deck[player], testDeck, sizeof(int) * deckCount);
						memcpy(game.discard[player], testDiscard, sizeof(int) * discardCount);

						testResult = fullDeckCount(player, i, &game);
						numTests++;

						if (totalCount == testResult)
						{
							passedTests++;
						}
						else
						{
							failedTests++;

						}

						printf("fullDeckCount = %d, Expected = %d\r\n", testResult, totalCount);
		

					}
				}
			}
		}
	}

	printf("%d out of %d tests passed!\r\n", passedTests, numTests);
	printf("%d out of %d tests failed!\r\n", failedTests, numTests);

	return 0;
}