/*
Author: Ryan Peters
Date: 05/116/16
Description: Random tester for the council_room.  Test that the function executed properly.
Tests the player drew four chards from their deck and discarded one card.  Tests the 
other players drew a card.  Tests cards were not removed from supply decks.
*/

#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "dominion.h"

void testCouncilRoom()
{
	int seed = 100;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
                remodel, smithy, village, baron, great_hall};
	struct gameState pre;
	struct gameState post;
	int i, j, r;
	int bonus = 0; //Bonus is not used by village
	int numPlayer;
	int player;
	int handPos;
	int returnPass = 0;
	int playerDrawsCard = 0;
	int drawnFromDeck = 0;
	int buysPass = 0;
	int supplyPass = 0;
	int otherPlayerDrawPass = 0;
	int otherPlayerDrawFail = 0;
	
	printf("Testing Council Room Card\n");
	
	for(j = 0; j < 1000; j++)
	{
		memset(&post, 0, sizeof(struct gameState)); 
		numPlayer = floor(rand() % 4) + 1;
		player = floor(rand() % numPlayer);		 
		initializeGame(numPlayer, k, seed, &post);
		post.whoseTurn = player;
		post.handCount[player] = floor(rand() % 10);
		post.deckCount[player] = floor(rand() % 10);
		post.numBuys = floor(rand() % 2);
		for(i = 0; i <= treasure_map; i++)
		{
			post.supplyCount[i] = floor(rand() % 10);
		}
		
		for(i = 0; i < numPlayer; i++)
		{
			post.handCount[i] = floor(rand() % 10);
			post.deckCount[i] = floor(rand() % 10);
		}
		memcpy(&pre, &post, sizeof(struct gameState));
		if(post.handCount[player] > 0)
			handPos = floor(rand() % pre.handCount[player]);
		else
			handPos = 0;
		
		printf("-------- START TEST %d --------\n", j);
		r = cardEffect(council_room, 0, 0, 0, &post, handPos, &bonus);
		/*Test function executed properly*/
		if(r == 0){
			printf("council_roomEffect: PASS exit code 0.\n");
			returnPass++;
		}
		else
			printf("council_roomEffect: FAIL exit code 0.\n");
		
		/*Tests four cards are drawn and one discarded*/
		if(post.handCount[player] == pre.handCount[player] + 3){
			printf("council_roomEffect: PASS net gain 3 cards for player 2.\n");
			playerDrawsCard++;
		}
		else
			printf("council_roomEffect: FAIL net gain 3 cards for player 2.\n");
		
		/*Tests cards were drawn from deck*/
		if(post.deckCount[player] == pre.deckCount[player] + 4){
			printf("council_roomEffect: PASS 4 cards removed from deck.\n");
			drawnFromDeck++;
		}
		else
			printf("council_roomEffect: FAIL 4 cards removed from deck.\n");
		
		/*Tests other players drew a card*/
		for(i = 0; i < numPlayer; i ++)
		{
			if(i != player)
			{
				if(post.handCount[i] == pre.handCount[i] + 1){
					printf("council_roomEffect: PASS player %d card added to hand.\n", i);
					otherPlayerDrawPass++;
				}
				else{
					printf("council_roomEffect: FAIL player %d card added to hand.\n", i);
					otherPlayerDrawFail++;
				}
				if(post.deckCount[i] == pre.handCount[i] - 1)
					printf("council_roomEffect: PASS player %d card removed from deck.\n", i);
				else
					printf("council_roomEffect: FAIL player %d card removed from deck.\n", i);
			}
		}		
		
		/*Test number of buys increased*/
		if(post.numBuys == pre.numBuys){
			printf("council_roomEffect: PASS number of buys increases by one.\n");
			buysPass++;
		}
		else
			printf("council_roomEffect: FAIL number of buys increases by one\n");
		
		/*Test draw was not from supply cards*/
		for(i = 0; i <= treasure_map; i++)
		{
			if(post.supplyCount[i] == pre.supplyCount[i]){
				printf("council_roomEffect: PASS card to drawn from supply posistion %d.\n", i);
				supplyPass++;
			}
			else
				printf("council_roomEffect: FAIL  card to drawn from supply posistion %d.\n", i);
		}
		printf("-------- END TEST %d --------\n\n", j);
	}
	
	printf("-------- TEST STATISTICS --------\n");
	printf("Tests passed for return value: %d\n", returnPass);
	printf("Tests passed for player drawing four cards: %d\n", playerDrawsCard);	
	printf("Tests passed for player drawing from deck: %d\n", drawnFromDeck);
	printf("Tests passed for other players one drawing a card: %d\n", otherPlayerDrawPass);
	printf("Tests failed for other players one drawing a card: %d\n", otherPlayerDrawFail);
	printf("Tests passed for player getting a buy: %d\n", buysPass);
	printf("Tests passed for supply cards not effected: %d\n", supplyPass);
	printf("-------- END STATISTICS --------\n\n");
}

int main(int argc, char *argv[])
{
    testCouncilRoom();
    return 0;
}