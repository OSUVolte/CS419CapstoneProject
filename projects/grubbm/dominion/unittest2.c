#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "math.h"


int main (){

struct gameState G;
int retShuf; 
int k[10] = {adventurer, great_hall, embargo, village, minion, duchy, feast,
	       steward, estate, smithy};


printf("Shuffle Unit Test\n");

initializeGame(2, k, 499, &G); 

G.deckCount[1] = 0;
retShuf = shuffle(1, &G); 
assert(retShuf == -1);  
printf("Empty Deck Test PASSED\n"); 


G.deckCount[1] = 5;
retShuf = shuffle(1, &G); 
assert(retShuf == 0);  
printf("Full Deck Test PASSED\n"); 


return 0;

}
