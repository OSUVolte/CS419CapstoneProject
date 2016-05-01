/******************************************************************************
 * Filename:		cardtest2.c
 * Author:		David Hite
 * Date Created:	4/24/2016
 * Last Date Edited:	4/24/2016
 *
 * Description:
 * Tests the gamestate after running playAdventurer().
 *****************************************************************************/
#include <stdio.h>
#include "dominion.h"

int main()
{
	printf("Testing playAdventurer()...\n");
	struct gameState* state = newGame();
	int player = 0;
	int failCount = 0;
	
	state->deckCount[player] = 5;
	state->handCount[player] = 5;
	state->discardCount[player] = 5;
	
	state->deck[player][0] = estate;
	state->deck[player][1] = smithy;
	state->deck[player][2] = gold;
	state->deck[player][3] = copper;
	state->deck[player][4] = adventurer;
	
	state->hand[player][0] = adventurer;
	state->hand[player][1] = copper;
	state->hand[player][2] = copper;
	state->hand[player][3] = steward;
	state->hand[player][4] = tribute;
	
	int i;
	for (i = 0; i < 5; i++)
		state->discard[player][i] = copper;
	printf("Player's deck: { estate, smithy, gold, copper, adventurer }\n");
	printf("Player's hand: { adventurer, copper, copper, steward, tribute }\n");
	printf("Player's discard pile: { copper, copper, copper, copper, copper }\n");
	
	printf("\nCalling playAdventurer...\n");
	playAdventurer(state, player);
	
	// one card should be discarded from deck, two should move from deck to hand
	// discard should be 6, hand should be 7, deck should be 2
	if (state->deckCount[player] != 2)
	{
		printf("Error: deckCount is %d instead of 2\n", state->deckCount[player]);
		failCount++;
	}
	if (state->handCount[player] != 7)
	{
		printf("Error: handCount is %d instead of 7\n", state->handCount[player]);
		failCount++;
	}
	if (state->discardCount[player] != 6)
	{
		printf("Error: discardCount is %d instead of 6\n", state->discardCount[player]);
		failCount++;
	}
	
	// current state:
	// deck = { estate, smithy }
	// hand = { adventurer, copper, copper, steward, tribute, copper, gold }
	// discard = { copper, copper, copper, copper, copper, adventurer }
	printf("Calling playAdventurer() again...\n");
	playAdventurer(state, player);
	
	// deck cards should be used up, then discard moved to deck
	// estate, adventurer, and smithy should be in discard pile, 
	// 3 coppers in deck,
	// 9 cards in hand
	if (state->deckCount[player] != 3)
	{
		printf("Error: deckCount is %d instead of 2\n", state->deckCount[player]);
		failCount++;
	}
	if (state->handCount[player] != 9)
	{
		printf("Error: handCount is %d instead of 7\n", state->handCount[player]);
		failCount++;
	}
	if (state->discardCount[player] != 3)
	{
		printf("Error: discardCount is %d instead of 6\n", state->discardCount[player]);
		failCount++;
	}
	
	printf("Testing complete!\n%d errors found.\n", failCount);
	
	return 0;
}