/*
Author: Ryan Peters
Date: 04/21/16
Description: Unit test for council_room card.  The council_room card allows the
player to draw 4 cards and the other players can draw one card.  The current player
gains one buy.  Tests the player draws four cards from their deck and adds them to
their hand.  Test the number of buys increases by one.  Tests the other players
draw one card from their decks and adds them to their hands.  Test the exit code is
0.
*/

#include<stdio.h>
#include<string.h>
#include "dominion.h"

void testVillage()
{
	int seed = 100;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
                remodel, smithy, village, baron, great_hall};
	struct gameState state;
	int r;
	int i;
	int bonus = 0; //Bonus is not used by village
	int numPlayer = 3;
	int player = 1;
	int handPos;
	
	/*Test 4 cards are drawn and one discarded, and exit code is 0*/
	memset(&state, 0, sizeof(struct gameState));  
    initializeGame(numPlayer, k, seed, &state);
	handPos = 1;
	state.whoseTurn = player;
	state.handCount[player] = 3;
	state.deckCount[player] = 10;
	r = cardEffect(council_room, 0, 0, 0, &state, handPos, &bonus);
	if(r == 0)
		printf("council_roomEffect: PASS exit code 0.\n");
	else
		printf("council_roomEffect: FAIL exit code 0.\n");
	if(state.handCount[player] == 6)
		printf("council_roomEffect: PASS net gain 3 cards for player 2.\n");
	else
		printf("council_roomEffect: FAIL net gain 3 cards for player 2.\n");
	if(state.deckCount[player] == 6)
		printf("council_roomEffect: PASS 4 cards removed from deck.\n");
	else
		printf("council_roomEffect: FAIL 4 cards removed from deck.\n");
	
	/*Test other players draw one card*/
	memset(&state, 0, sizeof(struct gameState));  
    initializeGame(numPlayer, k, seed, &state);
	handPos = 1;
	state.whoseTurn = player;
	for(i = 0; i < numPlayer; i++)
	{
		state.handCount[i] = 5;
		state.deckCount[i] = 5;
	}
	state.numPlayers = numPlayer;
	r = cardEffect(council_room, 0, 0, 0, &state, handPos, &bonus);
	if(state.handCount[0] == 6)
		printf("council_roomEffect: PASS player 1 card added to hand.\n");
	else
		printf("council_roomEffect: FAIL player 1 card added to hand.\n");
	if(state.deckCount[0] == 4)
		printf("council_roomEffect: PASS player 1 card removed from deck.\n");
	else
		printf("council_roomEffect: FAIL player 1 card removed from deck.\n");
	if(state.handCount[2] == 6)
		printf("council_roomEffect: PASS player 3 card added to hand.\n");
	else
		printf("council_roomEffect: FAIL player 3 card added to hand.\n");
	if(state.deckCount[2] == 4)
		printf("council_roomEffect: PASS player 3 card removed from deck.\n");
	else
		printf("council_roomEffect: FAIL player 3 card removed from deck.\n");
	
	/*Test number of buys increases by one*/
	memset(&state, 0, sizeof(struct gameState));  
    initializeGame(numPlayer, k, seed, &state);
	handPos = 1;
	state.whoseTurn = player;
	state.numBuys = 1;
	state.handCount[player] = 3;
	state.deckCount[player] = 10;
	r = cardEffect(council_room, 0, 0, 0, &state, handPos, &bonus);
	if(state.numBuys == 2)
		printf("council_roomEffect: PASS number of buys increases by one.\n");
	else
		printf("council_roomEffect: FAIL number of buys increases by one\n");
}

int main(int argc, char *argv[])
{
    testVillage();
    return 0;
}