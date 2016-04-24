/*********************************************************************************************
 * Developer: Nick Martin (martinn6)
 * Date: 20160422
 * Project: Assignement 3
 * Description: unittest3.c Tests the gainCard() function
   //added card for [whoseTurn] current player:
   // toFlag = 0 : add to discard - Will add card to discard pile and increase discardCount.
   // toFlag = 1 : add to deck - WIll add card to deck and increase deckCount.
   // toFlag = 2 : add to hand - will add card to hand and increate handCount.
 * *******************************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

struct cards {
	char *name;
	int cost;
 };
 
 int constructCards(struct cards *card)
 {
	 /* cards and costs were researched from http://wiki.dominionstrategy.com */
	 card[curse].name = "curse";
	 card[curse].cost = 0;
	 
	 card[estate].name = "estate";
	 card[estate].cost = 2;
	 
	 card[duchy].name = "duchy";
	 card[duchy].cost = 5;
	 
	 card[province].name = "province";
	 card[province].cost = 8;
	 
	 card[copper].name = "copper";
	 card[copper].cost = 0;
	 
	 card[silver].name = "silver";
	 card[silver].cost = 3;

	 card[gold].name = "gold";
	 card[gold].cost = 6;
	 
	 card[adventurer].name = "adventurer";
	 card[adventurer].cost = 6;
	 
	 card[council_room].name = "council_room";
	 card[council_room].cost = 5;
	 
	 card[feast].name = "feast";
	 card[feast].cost = 4;
	 
	 card[gardens].name = "gardens";
	 card[gardens].cost = 4;
	 
	 card[mine].name = "mine";
	 card[mine].cost = 5;
	 
	 card[remodel].name = "remodel";
	 card[remodel].cost = 4;
	 
	 card[smithy].name = "smithy";
	 card[smithy].cost = 4;
	 
	 card[village].name = "village";
	 card[village].cost = 3;
	 
	 card[baron].name = "baron";
	 card[baron].cost = 4;
	 
	 card[great_hall].name = "great_hall";
	 card[great_hall].cost = 3;
	 
	 card[minion].name = "minion";
	 card[minion].cost = 5;	 
	 
	 card[steward].name = "steward";
	 card[steward].cost = 3;	 
	 
	 card[tribute].name = "tribute";
	 card[tribute].cost = 5;	 
	 
	 card[ambassador].name = "ambassador";
	 card[ambassador].cost = 3;
	 
	 card[cutpurse].name = "cutpurse";
	 card[cutpurse].cost = 4;
	 
	 card[embargo].name = "embargo";
	 card[embargo].cost = 2;
	 
	 card[outpost].name = "outpost";
	 card[outpost].cost = 5;
	 
	 card[salvager].name = "salvager";
	 card[salvager].cost = 4;
	 
	 card[sea_hag].name = "sea_hag";
	 card[sea_hag].cost = 4;
	 
	 card[treasure_map].name = "treasure_map";
	 card[treasure_map].cost = 4;
	 
	 return(0);
 }



int main() {
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
			   
	struct cards card[27];
	struct gameState state;
	int numPlayer = 2;
	int seed = 1000;
	int handPos = 1;
	int handCount = 1;
	int cardDrawn = -1;
	int players[MAX_PLAYERS];
	int player = 0,
		player1 = 0,
		player2 = 1,
		player3 = 2,
		player4 = 3;
	int bsc, asc, bdc, adc;
	int toFlag = 1;
	
	constructCards(&card);
	
	//printf("Test player %d with %d treasure card(s) and %d bonus.\n", player, handCount, bonus);
	memset(&state, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(numPlayer, k, seed, &state); // initialize a new game
	state.handCount[player1] = handCount;                 // set the number of cards on hand
	//memcpy(state.hand[player1], province, sizeof(int) * handCount); // set all the cards to copper
	
	//int gainCard(int supplyPos, struct gameState *state, int toFlag, int player)
	//copper = 4;
	
	//# of cards
	player = player1;
	toFlag = 1;
	for(int x = 0; x<27; x++)
	{
		bsc = supplyCount(x, &state);
		bdc = state.deckCount[player];
		printf("\nRuning gainCard() to add '%s' to deck...\n", card[x].name);
		gainCard(x, &state, toFlag, player);
		adc = state.deckCount[player];
		cardDrawn = state.deck[player][state.deckCount[player]-1]; //deckCount-1
		asc = supplyCount(x, &state);
		//test deckcount results
		if (bsc == -1)
			printf("%s is not in the supply. Skipping.\n", card[x].name);
		else
		{
			printf("player %d starting deckcount=%d; ending deckcount=%d ", player, bdc, adc);
			if(adc == (bdc + 1)) printf("PASSED\n"); else printf("FAILED\n");
			//test card Drawn results
			printf("cardDrawn = %s ", card[cardDrawn].name);
			if(x == cardDrawn) printf("PASSED\n"); else printf("FAILED\n");
			//test supply count results
			printf("Starting Supply Count for %s = %d; Ending Supply Count = %d ",card[x].name, bsc, asc);
			if(asc == (bsc - 1)) printf("PASSED\n"); else printf("FAILED\n");
		}
	}
	//Run tests for adding to hand.
	player = player2;
	toFlag = 2;
	for(int x = 0; x<27; x++)
	{
		bsc = supplyCount(x, &state);
		bdc = state.handCount[player];
		printf("\nRuning gainCard() to add '%s' to hand...\n", card[x].name);
		gainCard(x, &state, toFlag, player);
		adc = state.handCount[player];
		cardDrawn = state.hand[player][state.handCount[player]-1]; //handcount-1
		asc = supplyCount(x, &state);
		//test handcount results
		
		if (bsc == -1)
			printf("%s is not in the supply. Skipping.\n", card[x].name);
		else
		{
			
			printf("player %d starting handcount=%d; ending handcount=%d ", player, bdc, adc);
			
			if(adc == (bdc + 1)) printf("PASSED\n"); else printf("FAILED\n");
			//test card Drawn results
			printf("cardDrawn = %s ", card[cardDrawn].name);
			if(x == cardDrawn) printf("PASSED\n"); else printf("FAILED\n");
			//test supply count results
			printf("Starting Supply Count for %s = %d; Ending Supply Count = %d ",card[x].name, bsc, asc);
			if(asc == (bsc - 1)) printf("PASSED\n"); else printf("FAILED\n");
		}
		
	}
	//Run tests for adding to discard.
	player = player2;
	toFlag = 0;
	for(int x = 0; x<27; x++)
	{
		bsc = supplyCount(x, &state);
		bdc = state.discardCount[player];
		printf("\nRuning gainCard() to add '%s' to discard...\n", card[x].name);
		gainCard(x, &state, toFlag, player);
		adc = state.discardCount[player];
		cardDrawn = state.discard[player][state.discardCount[player]-1]; //discardCount-1
		asc = supplyCount(x, &state);
		//test discardCount results
		
		if (bsc == -1)
			printf("%s is not in the supply. Skipping.\n", card[x].name);
		else
		{
			
			printf("player %d starting discardCount=%d; ending discardCount=%d ", player, bdc, adc);
			
			if(adc == (bdc + 1)) printf("PASSED\n"); else printf("FAILED\n");
			//test card Drawn results
			printf("cardDrawn = %s ", card[cardDrawn].name);
			if(x == cardDrawn) printf("PASSED\n"); else printf("FAILED\n");
			//test supply count results
			printf("Starting Supply Count for %s = %d; Ending Supply Count = %d ",card[x].name, bsc, asc);
			if(asc == (bsc - 1)) printf("PASSED\n"); else printf("FAILED\n");
		}
		
	}
	printf("\ntest complete.\n");
	
    return 0;
}
