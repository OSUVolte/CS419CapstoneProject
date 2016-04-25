#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "math.h"


int main (){

struct gameState *G = newGame();
int p, turn; 
int players = 3; 
int k[10] = {adventurer, great_hall, embargo, village, minion, duchy, feast,
	       steward, estate, smithy};


printf("whoseTurn Unit Test\n");

initializeGame(2, k, 544, G); 

for(p = 0; p < players; p++){

	G->whoseTurn = p;
	turn = whoseTurn(G);
	assert(turn == p); 
}


printf("whoseTurn Test PASSED\n"); 


return 0;

}
