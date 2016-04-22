/*
Author: Ryan Peters
Date: 04/20/16
Description: Unit test for buyCard().  Test conditions for failed 
execution.  Tests for the function executing without a problem.  
Tests that coins are decremented for the card purchased.  Tests
for purchased card added to the player's hand or deck.
*/

#include<stdio.h>
#include "dominion.h"

void testBuyCard()
{
	int r;
	int i;
	struct gameState state;
	
	/*Tests when player doesn't have a buy.*/
	state.numBuys = 0;
	state.supplyCount[1] = 1;
	state.coins = 10;
	r = buyCard(1, &state);
	if(r == -1)
		printf("buyCard(): PASS when numBuys is 0.\n");
	else
		printf("buyCard(): FAIL when numBuys is 0.\n");
	
	/*Test when player has one buy*/
	state.numBuys = 1;
	state.supplyCount[1] = 1;
	state.coins = 10;
	r = buyCard(1, &state);
	if(r == 0)
		printf("buyCard(): PASS when numBuys is 1.\n");
	else
		printf("buyCard(): FAIL when numBuys is 1.\n");
	
	/*Test when the player has multiple buys*/
	state.numBuys = 100;
	state.supplyCount[1] = 1;
	state.coins = 10;
	r = buyCard(1, &state);
	if(r == 0)
		printf("buyCard(): PASS when numBuys is 100.\n");
	else
		printf("buyCard(): FAIL when numBuys is 100.\n");
	
	/*Test when trying to buy a card when the card has none left to buy.*/
	state.numBuys = 1;
	state.supplyCount[1] = 0;
	state.coins = 10;
	r = buyCard(1, &state);
	if(r == -1)
		printf("buyCard(): PASS when supplyCount is 0.\n");
	else
		printf("buyCard(): FAIL when supplyCount is 0.\n");
	
	/*Test when there is a card to buy*/
	state.numBuys = 1;
	state.supplyCount[1] = 1;
	state.coins = 10;
	r = buyCard(1, &state);
	if(r == 0)
		printf("buyCard(): PASS when supplyCount is 1.\n");
	else
		printf("buyCard(): FAIL when supplyCount is 1.\n");
	
	/*Test when play does not have enough coins to the chosen card.*/
	state.numBuys = 1;
	state.supplyCount[1] = 1;
	state.coins = 1;
	r = buyCard(1, &state);
	if(r == -1)
		printf("buyCard(): PASS when player has insuffienct coins.\n");
	else
		printf("buyCard(): FAIL when player has insuffienct coins.\n");
	
	/*Test number of buys decrements after buying card.*/
	state.numBuys = 1;
	state.supplyCount[1] = 1;
	state.coins = 10;
	r = buyCard(1, &state);
	if(state.numBuys == 0)
		printf("buyCard(): PASS numBuys decremented.\n");
	else
		printf("buyCard(): FAIL numBuys decremented.\n");
	
	/*Test the game phase changes.*/
	state.numBuys = 1;
	state.supplyCount[1] = 1;
	state.coins = 10;
	r = buyCard(1, &state);
	if(state.phase == 1)
		printf("buyCard(): PASS state.phase is 1.\n");
	else
		printf("buyCard(): FAIL state.phase is 0.\n");

	/*Test that the bought card is added to the player's hand*/
	state.numBuys = 1;
	state.supplyCount[1] = 1;
	state.coins = 10;
	state.whoseTurn = 1;
	state.handCount[1] = 1;
	r = buyCard(1, &state);
	if(state.handCount[1] == 2)
		printf("buyCard(): PASS add card to hand.\n");
	else
		printf("buyCard(): FAIL add card to hand.\n");
	
	/*Test that the bought card is added to the player's deck*/
	state.numBuys = 1;
	state.supplyCount[1] = 1;
	state.coins = 10;
	state.whoseTurn = 1;
	state.handCount[1] = 1;
	r = buyCard(1, &state);
	if(state.deckCount[1] == 2)
		printf("buyCard(): PASS add card to player deck.\n");
	else
		printf("buyCard(): FAIL add card to player deck.\n");
	
	/*Test that the bought card is removed from the stack.*/
	state.numBuys = 1;
	state.supplyCount[1] = 1;
	state.coins = 10;
	state.whoseTurn = 1;
	state.handCount[1] = 1;
	r = buyCard(1, &state);
	if(state.supplyCount[1] == 0)
		printf("buyCard(): PASS card removed from supply.\n");
	else
		printf("buyCard(): FAIL card removed from supply.\n");
	
	/*Rest of the test are used to test buying each type of card.*/
	state.numBuys = 1;
	state.supplyCount[1] = 1;
	state.coins = 10;
	r = buyCard(1, &state);
	if(state.coins == 8)
		printf("buyCard(): PASS coins removed for estate.\n");
	else
		printf("buyCard(): FAIL coins removed for estate.\n");
	
	state.numBuys = 1;
	state.supplyCount[0] = 1;
	state.coins = 10;
	r = buyCard(0, &state);
	if(state.coins == 10)
		printf("buyCard(): PASS coins removed for curse.\n");
	else
		printf("buyCard(): FAIL coins removed for curse.\n");
	
	state.numBuys = 1;
	state.supplyCount[2] = 1;
	state.coins = 10;
	r = buyCard(2, &state);
	if(state.coins == 5)
		printf("buyCard(): PASS coins removed for duchy.\n");
	else
		printf("buyCard(): FAIL coins removed for duchy.\n");
	
	state.numBuys = 1;
	state.supplyCount[3] = 1;
	state.coins = 10;
	r = buyCard(3, &state);
	if(state.coins == 2)
		printf("buyCard(): PASS coins removed for province.\n");
	else
		printf("buyCard(): FAIL coins removed for province.\n");
	
	state.numBuys = 1;
	state.supplyCount[4] = 1;
	state.coins = 10;
	r = buyCard(4, &state);
	if(state.coins == 10)
		printf("buyCard(): PASS coins removed for copper.\n");
	else
		printf("buyCard(): FAIL coins removed for copper.\n");
	
	state.numBuys = 1;
	state.supplyCount[5] = 1;
	state.coins = 10;
	r = buyCard(5, &state);
	if(state.coins == 7)
		printf("buyCard(): PASS coins removed for silver.\n");
	else
		printf("buyCard(): FAIL coins removed for silver.\n");
	
	state.numBuys = 1;
	state.supplyCount[6] = 1;
	state.coins = 10;
	r = buyCard(6, &state);
	if(state.coins == 4)
		printf("buyCard(): PASS coins removed for gold.\n");
	else
		printf("buyCard(): FAIL coins removed for gold.\n");
	
	state.numBuys = 1;
	state.supplyCount[7] = 1;
	state.coins = 10;
	r = buyCard(7, &state);
	if(state.coins == 4)
		printf("buyCard(): PASS coins removed for adventurer.\n");
	else
		printf("buyCard(): FAIL coins removed for adventurer.\n");
	
	state.numBuys = 1;
	state.supplyCount[8] = 1;
	state.coins = 10;
	r = buyCard(8, &state);
	if(state.coins == 5)
		printf("buyCard(): PASS coins removed for council_room.\n");
	else
		printf("buyCard(): FAIL coins removed for council_room.\n");
	
	state.numBuys = 1;
	state.supplyCount[9] = 1;
	state.coins = 10;
	r = buyCard(9, &state);
	if(state.coins == 6)
		printf("buyCard(): PASS coins removed for feast.\n");
	else
		printf("buyCard(): FAIL coins removed for feast.\n");
	
	state.numBuys = 1;
	state.supplyCount[10] = 1;
	state.coins = 10;
	r = buyCard(10, &state);
	if(state.coins == 6)
		printf("buyCard(): PASS coins removed for gardens.\n");
	else
		printf("buyCard(): FAIL coins removed for gardens.\n");
	
	state.numBuys = 1;
	state.supplyCount[11] = 1;
	state.coins = 10;
	r = buyCard(11, &state);
	if(state.coins == 5)
		printf("buyCard(): PASS coins removed for mine.\n");
	else
		printf("buyCard(): FAIL coins removed for mine.\n");
	
	state.numBuys = 1;
	state.supplyCount[12] = 1;
	state.coins = 10;
	r = buyCard(12, &state);
	if(state.coins == 6)
		printf("buyCard(): PASS coins removed for remodel.\n");
	else
		printf("buyCard(): FAIL coins removed for remodel.\n");
	
	state.numBuys = 1;
	state.supplyCount[13] = 1;
	state.coins = 10;
	r = buyCard(13, &state);
	if(state.coins == 6)
		printf("buyCard(): PASS coins removed for smithy.\n");
	else
		printf("buyCard(): FAIL coins removed for smithy.\n");
	
	state.numBuys = 1;
	state.supplyCount[14] = 1;
	state.coins = 10;
	r = buyCard(14, &state);
	if(state.coins == 7)
		printf("buyCard(): PASS coins removed for village.\n");
	else
		printf("buyCard(): FAIL coins removed for village.\n");
	
	state.numBuys = 1;
	state.supplyCount[15] = 1;
	state.coins = 10;
	r = buyCard(15, &state);
	if(state.coins == 6)
		printf("buyCard(): PASS coins removed for baron.\n");
	else
		printf("buyCard(): FAIL coins removed for baron.\n");
	
	state.numBuys = 1;
	state.supplyCount[16] = 1;
	state.coins = 10;
	r = buyCard(16, &state);
	if(state.coins == 7)
		printf("buyCard(): PASS coins removed for great_hall.\n");
	else
		printf("buyCard(): FAIL coins removed for great_hall.\n");
	
	state.numBuys = 1;
	state.supplyCount[17] = 1;
	state.coins = 10;
	r = buyCard(17, &state);
	if(state.coins == 5)
		printf("buyCard(): PASS coins removed for minion.\n");
	else
		printf("buyCard(): FAIL coins removed for minion.\n");
	
	state.numBuys = 1;
	state.supplyCount[18] = 1;
	state.coins = 10;
	r = buyCard(18, &state);
	if(state.coins == 7)
		printf("buyCard(): PASS coins removed for steward.\n");
	else
		printf("buyCard(): FAIL coins removed for steward.\n");
	
	state.numBuys = 1;
	state.supplyCount[19] = 1;
	state.coins = 10;
	r = buyCard(19, &state);
	if(state.coins == 5)
		printf("buyCard(): PASS coins removed for tribute.\n");
	else
		printf("buyCard(): FAIL coins removed for tribute.\n");
	
	state.numBuys = 1;
	state.supplyCount[20] = 1;
	state.coins = 10;
	r = buyCard(20, &state);
	if(state.coins == 7)
		printf("buyCard(): PASS coins removed for ambassador.\n");
	else
		printf("buyCard(): FAIL coins removed for ambassador.\n");
	
	state.numBuys = 1;
	state.supplyCount[21] = 1;
	state.coins = 10;
	r = buyCard(21, &state);
	if(state.coins == 6)
		printf("buyCard(): PASS coins removed for cutpurse.\n");
	else
		printf("buyCard(): FAIL coins removed for cutpurse.\n");
	
	state.numBuys = 1;
	state.supplyCount[22] = 1;
	state.coins = 10;
	r = buyCard(22, &state);
	if(state.coins == 8)
		printf("buyCard(): PASS coins removed for embargo.\n");
	else
		printf("buyCard(): FAIL coins removed for embargo.\n");

	state.numBuys = 1;
	state.supplyCount[23] = 1;
	state.coins = 10;
	r = buyCard(23, &state);
	if(state.coins == 5)
		printf("buyCard(): PASS coins removed for outpost.\n");
	else
		printf("buyCard(): FAIL coins removed for outpost.\n");
	
	state.numBuys = 1;
	state.supplyCount[24] = 1;
	state.coins = 10;
	r = buyCard(24, &state);
	if(state.coins == 6)
		printf("buyCard(): PASS coins removed for salvager.\n");
	else
		printf("buyCard(): FAIL coins removed for salvager.\n");
	
	state.numBuys = 1;
	state.supplyCount[25] = 1;
	state.coins = 10;
	r = buyCard(25, &state);
	if(state.coins == 6)
		printf("buyCard(): PASS coins removed for sea_hag.\n");
	else
		printf("buyCard(): FAIL coins removed for sea_hag.\n");
	
	state.numBuys = 1;
	state.supplyCount[26] = 1;
	state.coins = 10;
	r = buyCard(26, &state);
	if(state.coins == 6)
		printf("buyCard(): PASS coins removed for treasure_map.\n");
	else
		printf("buyCard(): FAIL coins removed for treasure_map.\n");
	
	state.numBuys = 1;
	state.supplyCount[30] = 1;
	state.coins = 10;
	r = buyCard(30, &state);
	if(state.coins == 11)
		printf("buyCard(): PASS coins removed for invalid card.\n");
	else
		printf("buyCard(): FAIL coins removed for invalid card.\n");
	
	state.numBuys = 1;
	state.supplyCount[-1] = 1;
	state.coins = 10;
	r = buyCard(-1, &state);
	if(state.coins == 11)
		printf("buyCard(): PASS coins removed for invalid card.\n");
	else
		printf("buyCard(): FAIL coins removed for invalid card.\n");	
}

int main(int argc, char *argv[])
{
    testBuyCard();
    return 0;
}