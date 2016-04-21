#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {
	printf("\ntesting council_room_card\n");
	struct gameState game, afterCard;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
//create game
//4 players, cards, seed, game struct
	initializeGame(2, k, 10, &game);
	memcpy(&afterCard, &game, sizeof(struct gameState));
	playCouncil_Room(&afterCard, 1, 0);
	
	printf("hand count: %d, After card played: %d (council room should increase the players hand by 4)\n", game.handCount[0], afterCard.handCount[0]);
	printf("number of buys: %d, After card played number of buys: %d (card increases buys by 1)\n", game.numBuys, afterCard.numBuys);
	printf("Player 2's amount of cards: %d, After player one plays council room:  %d (new should be 1 more)\n", game.handCount[1], afterCard.handCount[1]);

	printf("\nAll tests passed.\n\n");
return 0;
}
