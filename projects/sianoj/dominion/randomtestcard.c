//Jessica Siano
//CS362 Software Engineering 2
//Random Card Test

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <math.h>
#include "rngs.h"

int main(){
	struct gameState g;
	SelectStream(2);
	PutSeed(3);

	srand(time(NULL));

	//track the number of succesful and failed runs
	int succesful = 0;
	int failed = 0;

	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};


	//run 10000 tests
	int i;
	for(i = 0; i < 10000; i++){
		//create random seed value and number of players
		int players = rand() % 5 + 1;
		int seed = rand() % 1000 + 1;
		//initialize the game
		struct gameState g;
		int o = initializeGame(players, k, seed, &g);
		//error checking
		if(o == -1){
			failed++;
			break;
		}

		struct gameState testGame;

		memcpy(&testGame, &g, sizeof(struct gameState));

		//make sure the first player has a smithy card
		testGame.hand[0][testGame.handCount[0]] = smithy;
		testGame.handCount[0]++;
		//check to see if the card was given successfully
		if((g.handCount[0]+1) != testGame.handCount[0]){
			failure++;
			break;
		}
		
		//play the smithy card
		playSmithy(0, &testGame, 0);

		//check to see if the player now has the correct number of cards
		if((g.handCount[0]+3) != testGame.handCount[0]){
			failure++;
			break;
		}
		
		//if the tests were passed, increment the number of successful runs
		successful++;
	}
	//print the results
	printf("Successful tests: %d\n", successful);
    	printf("Failed tests: %d\n", failed);


	return 0;
}
