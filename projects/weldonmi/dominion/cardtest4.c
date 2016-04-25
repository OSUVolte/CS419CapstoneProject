/*
 * Miranda Weldon
 * April 23, 2016
 * CS 362 Spring 2016
 * Assignment 3
 * cardtest4.c
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

//main function
int main(){
	//declare variables
	int i, j, numPlayers = 3, scCount = 0, ophModCount = 0;
	struct gameState Game, testGame;
	int k[10] = {feast, gardens, salvager, remodel, tribute, mine, cutpurse, ambassador, great_hall, smithy};

	//start up original game and create a copy
	initializeGame(numPlayers, k, 1000, &Game);
	memcpy(&testGame, &Game, sizeof(struct gameState));

	printf("Testing Feast Card\n\n");

	for(i = 0; i < numPlayers; i++){
		//reset game copy 
		memcpy(&testGame, &Game, sizeof(struct gameState));
	
		//play card
		cardEffect(feast, 0, 0, 0, &testGame, 0, 0);

		printf("Player %d:\n", i);

		//test that the hand has no change in the number of cards
		printf("\tExpected HandCount: %d\n\tActual HandCount: %d\n", Game.handCount[i], testGame.handCount[i]);
		testGame.handCount[i] == Game.handCount[i] ? printf("\tTest Pass\n") : printf("\tTest Fail\n");

		//test that only lost 1 card was taken from supply
		//first check the victory cards
		if(Game.supplyCount[estate] != testGame.supplyCount[estate])
			scCount++;
		if(Game.supplyCount[duchy] != testGame.supplyCount[duchy])
			scCount++;
		if(Game.supplyCount[province] != testGame.supplyCount[province])
			scCount++;
		//then the treasure cards
		if(Game.supplyCount[copper] != testGame.supplyCount[copper])
			scCount++;
		if(Game.supplyCount[silver] != testGame.supplyCount[silver])
			scCount++;
		if(Game.supplyCount[gold] != testGame.supplyCount[gold])
			scCount++;
		if(Game.supplyCount[curse] != testGame.supplyCount[curse])
			scCount++;
		//then the action cards
		if(Game.supplyCount[council_room] != testGame.supplyCount[council_room])
			scCount++;
		if(Game.supplyCount[feast] != testGame.supplyCount[feast])
			scCount++;
		if(Game.supplyCount[gardens] != testGame.supplyCount[gardens])
			scCount++;
		if(Game.supplyCount[mine] != testGame.supplyCount[mine])
			scCount++;
		if(Game.supplyCount[remodel] != testGame.supplyCount[remodel])
			scCount++;
		if(Game.supplyCount[smithy] != testGame.supplyCount[smithy])
			scCount++;
		if(Game.supplyCount[village] != testGame.supplyCount[village])
			scCount++;
		if(Game.supplyCount[baron] != testGame.supplyCount[baron])
			scCount++;
		if(Game.supplyCount[great_hall] != testGame.supplyCount[great_hall])
			scCount++;
		if(Game.supplyCount[minion] != testGame.supplyCount[minion])
			scCount++;
		if(Game.supplyCount[steward] != testGame.supplyCount[steward])
			scCount++;
		if(Game.supplyCount[tribute] != testGame.supplyCount[tribute])
			scCount++;
		if(Game.supplyCount[ambassador] != testGame.supplyCount[ambassador])
			scCount++;
		if(Game.supplyCount[cutpurse] != testGame.supplyCount[cutpurse])
			scCount++;
		if(Game.supplyCount[embargo] != testGame.supplyCount[embargo])
			scCount++;
		if(Game.supplyCount[outpost] != testGame.supplyCount[outpost])
			scCount++;
		if(Game.supplyCount[salvager] != testGame.supplyCount[salvager])
			scCount++;
		if(Game.supplyCount[sea_hag] != testGame.supplyCount[sea_hag])
			scCount++;
		if(Game.supplyCount[treasure_map] != testGame.supplyCount[treasure_map])
			scCount++;
		//then check how many changes made, must be only one
		printf("\tExpected Supply Changes: at most 1\n\tActual Supply Changes: %d\n", scCount);
		scCount == 1 || scCount == 0 ? printf("\tTest Pass\n") : printf("\tTest Fail\n");

		//test that no cards drawn from other player's hands
		printf("\tExpected Changes to Other Player(s) Hands: 0\n");
		for (j = 0; j < numPlayers; j++)
			if (j != i)
				if(testGame.handCount[j] != Game.handCount[j]){
					printf("\tTest Fail: Modified Player %d's Hand\n", j);
					ophModCount++;
				}
		if(ophModCount == 0)
			printf("\tTest Pass\n");

		//test that only 1 card is discarded
		printf("\tExpected DiscardCount: %d\n\tActual DiscardCount: %d\n", Game.discardCount[i] + 1, testGame.discardCount[i]);
		testGame.discardCount[i] == Game.discardCount[i] + 1 ? printf("\tTest Pass\n") : printf("\tTest Fail\n");

		//test which player's turn
		printf("\tExpected Player's Turn: %d\n\tActual Player's Turn: %d\n", Game.whoseTurn, testGame.whoseTurn);
		Game.whoseTurn == testGame.whoseTurn ? printf("\tTest Pass\n") : printf("\tTest Fail\n");

		scCount = 0;
		Game.whoseTurn++;
	}

	//zero if no errors
	return 0;
}

