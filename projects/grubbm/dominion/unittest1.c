#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "math.h"

int main(){

int score; 
struct gameState G;
int k[10] = {adventurer, great_hall, embargo, village, minion, duchy, feast,
	       steward, estate, smithy};


printf("scoreFor Unit Test\n");
initializeGame(2, k, 17, &G);

G.hand[1][0] = curse; // -1
G.hand[1][1] = estate; // +1
G.hand[1][2] = duchy; // +3 
G.hand[1][3] = province; // +6
G.hand[1][4] = great_hall; // +1

G.handCount[1] = 5;

score = scoreFor(1, &G);
printf("Score: %i\n", score);
assert(score == 10);
printf("scoreFor Test SuccEss\n");

return 0; 

}
