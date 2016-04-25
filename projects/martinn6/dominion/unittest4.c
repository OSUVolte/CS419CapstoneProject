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
	int winner = 0,
		player1 = 0,
		player2 = 1,
		player3 = 2,
		player4 = 3;
	int bsc, asc, bdc, adc;
	int toFlag = 1;
	
	constructCards(&card);
	
	memset(&state, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(numPlayer, k, seed, &state); // initialize a new game
	state.handCount[player1] = handCount;                 // set the number of cards on hand
	
	//# of cards
	winner = player1;
	toFlag = 2;
	gainCard(province, &state, toFlag, winner);
	gainCard(province, &state, toFlag, winner);
	gainCard(province, &state, toFlag, winner);
	gainCard(province, &state, toFlag, winner);
	gainCard(province, &state, toFlag, winner);
	gainCard(province, &state, toFlag, winner);
	
	//int getWinners(int players[MAX_PLAYERS], struct gameState *state)
	getWinners(&players, &state);
	printf("Number of players: %d\n", state.numPlayers);
	
	for (int x = 0; x < 4; x++)
	{
		//int score = scoreFor(x, &state);
		//printf("Score for player: %d = %d", x, score);
		printf("players[%d] = %d; ", x, players[x]);
		if(x == winner && players[x] == 1)
			printf("Winner Found: PASSED\n");
		else if(x != winner && players[x] == 0)
			printf("Non-winner found: PASSED\n");
		else
			printf("FAIL\n");
	}
	
	//rest game
	memset(&state, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(numPlayer, k, seed, &state); // initialize a new game
	//state.handCount[player1] = handCount;                 // set the number of cards on hand
	
	//# of cards
	winner = player2;
	toFlag = 2;
	gainCard(province, &state, toFlag, winner);
	gainCard(province, &state, toFlag, winner);
	gainCard(province, &state, toFlag, winner);
	gainCard(province, &state, toFlag, winner);
	gainCard(province, &state, toFlag, winner);
	gainCard(province, &state, toFlag, winner);
	
	//int getWinners(int players[MAX_PLAYERS], struct gameState *state)
	getWinners(&players, &state);
	printf("Number of players: %d\n", state.numPlayers);
	
	for (int x = 0; x < 4; x++)
	{
		//int score = scoreFor(x, &state);
		//printf("Score for player: %d = %d", x, score);
		printf("players[%d] = %d; ", x, players[x]);
		if(x == winner && players[x] == 1)
			printf("Winner Found: PASSED\n");
		else if(x != winner && players[x] == 0)
			printf("Non-winner found: PASSED\n");
		else
			printf("FAIL\n");
	}
	
	//reset game
	numPlayer = 3;
	memset(&state, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(numPlayer, k, seed, &state); // initialize a new game
	//state.handCount[player1] = handCount;                 // set the number of cards on hand
	
	//# of cards
	
	winner = player3;
	toFlag = 2;
	gainCard(province, &state, toFlag, winner);
	gainCard(province, &state, toFlag, winner);
	gainCard(province, &state, toFlag, winner);
	gainCard(province, &state, toFlag, winner);
	gainCard(province, &state, toFlag, winner);
	gainCard(province, &state, toFlag, winner);
	
	//int getWinners(int players[MAX_PLAYERS], struct gameState *state)
	getWinners(&players, &state);
	printf("Number of players: %d\n", state.numPlayers);
	
	for (int x = 0; x < 4; x++)
	{
		//int score = scoreFor(x, &state);
		//printf("Score for player: %d = %d", x, score);
		printf("players[%d] = %d; ", x, players[x]);
		if(x == winner && players[x] == 1)
			printf("Winner Found: PASSED\n");
		else if(x != winner && players[x] == 0)
			printf("Non-winner found: PASSED\n");
		else
			printf("FAIL\n");
	}
		
	
	//reset game
	numPlayer = 4;
	memset(&state, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(numPlayer, k, seed, &state); // initialize a new game
	//state.handCount[player1] = handCount;                 // set the number of cards on hand
	
	//# of cards
	
	winner = player4;
	toFlag = 2;
	gainCard(province, &state, toFlag, winner);
	gainCard(province, &state, toFlag, winner);
	gainCard(province, &state, toFlag, winner);
	gainCard(province, &state, toFlag, winner);
	gainCard(province, &state, toFlag, winner);
	gainCard(province, &state, toFlag, winner);
	
	//int getWinners(int players[MAX_PLAYERS], struct gameState *state)
	getWinners(&players, &state);
	printf("Number of players: %d\n", state.numPlayers);
	
	for (int x = 0; x < 4; x++)
	{
		//int score = scoreFor(x, &state);
		//printf("Score for player: %d = %d", x, score);
		printf("players[%d] = %d; ", x, players[x]);
		if(x == winner && players[x] == 1)
			printf("Winner Found: PASSED\n");
		else if(x != winner && players[x] == 0)
			printf("Non-winner found: PASSED\n");
		else
			printf("FAIL\n");
	}
	
	//reset game
	numPlayer = 2;
	memset(&state, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(numPlayer, k, seed, &state); // initialize a new game
	//state.handCount[player1] = handCount;                 // set the number of cards on hand
	
	//# of cards
	
	toFlag = 2;
	gainCard(province, &state, toFlag, 0);
	gainCard(province, &state, toFlag, 0);
	gainCard(province, &state, toFlag, 0);
	gainCard(province, &state, toFlag, 1);
	gainCard(province, &state, toFlag, 1);
	gainCard(province, &state, toFlag, 1);
	gainCard(estate, &state, toFlag, 1);
	
	//int getWinners(int players[MAX_PLAYERS], struct gameState *state)
	getWinners(&players, &state);
	printf("Number of players: %d\n", state.numPlayers);
	
	for (int x = 0; x < numPlayer; x++)
	{
		int score = scoreFor(x, &state);
		printf("Score for player: %d = %d", x, score);
		printf("players[%d] = %d; ", x, players[x]);
		if(x == winner && players[x] == 1)
			printf("Winner Found: PASSED\n");
		else if(x != winner && players[x] == 0)
			printf("Non-winner found: PASSED\n");
		else
			printf("FAIL\n");
	}
	
		
	printf("\ntest complete.\n");
	
	
    return 0;
}
