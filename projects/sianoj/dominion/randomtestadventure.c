//Jessica Siano
//CS362 Software Engineering 2
//Random testing for adventurer

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "rngs.h"

int main(){

	//keep track of successes and failures
	int successful = 0;
	int failed = 0;	

	srand(time(NULL));

	//run 10000 tests
	int i;
	for(i = 0; i < 10000; i++){
		// set a random number of seeds
		int seed = srand() % 1000 + 1;
		//set a random number of players
		int players = srand() % 5 + 1;	
		int card1, card2;
		int treasures1, treasures2;

		int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
		//initialize the game
		struct gameState g;
		int o = initializeGame(players, k, seed, &g);
		
		//error checking the initialization
		if(o == -1){
			failed++;
			break;
		}
		
		struct gameState testGame;
		memcpy(&testGame, &g, sizeof(struct gameState));

		//give a random player the adventurer card
		int randPlayer = srand() % players;
		testGame.hand[randPlayer][testGame.handCount[randPlayer]] = adventurer;
		testGame.handCount[randPlayer]++;
	
		//check for the correct number of cards
		if((g.handCount[randPlayer]+1) != testGame.handCount[randPlayer]){
			failed++;
			break;
		}

		//play the adventurer card
		playAdventurer(randPlayer, &testGame);

		//check to make sure there are 2 extra tresure cards
		for(i = 0; i < testGame.handCount[randPlayer]; i++){
			card1 = testGame.hand[randPlayer][i];
			if(card1 == copper || card1 == silver || card1 == gold)
				treasures1++;
		}
		for(i = 0; i < g.handCount[randPlayer]; i++){
                        card2 = g.hand[randPlayer][i];
                        if(card2 == copper || card2 == silver || card2 == gold)
                                treasures2++;	
		}
		int drawnTreasure = treasures2 - treasures1;
		if(drawnTreasure != 2){
			failed++;
			break;
		}

		if(g.handCount[randPlayer] >= testGame.handCount[randPlayer]0){
			failed++;
			break;
		}

		success++;

	}
	
	printf("Successful tests: %d\n", successful);
    	printf("Failed tests: %d\n", failed);

    	return 0;


}
