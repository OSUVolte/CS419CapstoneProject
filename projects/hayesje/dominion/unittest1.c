#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define VERBOSE 0

void checkUpdateCoins(int p, struct gameState *post, int bonus, int ctotal, int hc, int *pass, int *fail) {

  int coins =  bonus + ctotal;
  updateCoins (p, post, bonus);

  if (post->coins == coins ) { *pass = *pass + 1 ; }
  else{
	  *fail = *fail + 1;
	  if (VERBOSE) {
		  printf("\nFAILED\n");
	 	  printf("Player:%d  HandCount:%d  Bonus:%d  Ctotal:%d  Coins:%d\n", p, post->handCount[p], bonus, ctotal, post->coins);
	  }
  }

}

void reset(struct gameState *G, int count, int players ) {
	int i;
    memset(G, 23, sizeof(struct gameState));
    G->numPlayers = players;
    for (i = 0; i < players; i++) {
         G->handCount[i] = count;
         memset(G->hand[i], 0, sizeof(int) * count);
    }
    G->coins = 100;
}



int main () {
  int pass = 0;
  int fail = 0;
  int p, bonus, ctotal, handCount;
  int players = 4;

  struct gameState G;

  printf ("Unit Test: unittest1.c\n");
  printf ("   Target: updateCoins Function\n");
  for (p = 0; p < players; p++) {
	for (handCount = 0; handCount <= 2; handCount++) {
	   for(bonus = 0; bonus <= 1; bonus++) {
	       switch(handCount) {
	           case 0:    // exercise for loop zero times
	        	   reset(&G, handCount, players);
	               ctotal = 0;
	               checkUpdateCoins(p, &G, bonus, ctotal, handCount, &pass, &fail);
	        	   break;
	            case 1:    // exercise for loop one time for each test
	               reset(&G, handCount, players);
	               G.hand[p][0] = copper;
	               ctotal = 1;
	               checkUpdateCoins(p, &G, bonus, ctotal, handCount, &pass, &fail);
	               reset(&G, handCount, players);
	               G.hand[p][0] = silver;
	               ctotal = 2;
	               checkUpdateCoins(p, &G, bonus, ctotal, handCount, &pass, &fail);
	               reset(&G, handCount, players);
	               G.hand[p][0] = gold;
	               ctotal = 3;
	               checkUpdateCoins(p, &G, bonus, ctotal, handCount, &pass, &fail);
	               reset(&G, handCount, players);
	               G.hand[p][0] = smithy;
	               ctotal = 0;
	               checkUpdateCoins(p, &G, bonus, ctotal, handCount, &pass, &fail);
	               break;
	           case 2:   // exercise for loop multiple times for each test
	               reset(&G, handCount, players);
	               G.hand[p][0] = copper;
	               G.hand[p][1] = copper;
	               ctotal = 2;
	               checkUpdateCoins(p, &G, bonus, ctotal, handCount, &pass, &fail);
	               reset(&G, handCount, players);
	               G.hand[p][0] = silver;
	               G.hand[p][1] = smithy;
	               ctotal = 2;
	               checkUpdateCoins(p, &G, bonus, ctotal, handCount, &pass, &fail);
	               reset(&G, handCount, players);
	               G.hand[p][0] = smithy;
	               G.hand[p][1] = gold;
	               ctotal = 3;
	               checkUpdateCoins(p, &G, bonus, ctotal, handCount, &pass, &fail);
	               reset(&G, handCount, players);
	               G.hand[p][0] = silver;
	               G.hand[p][1] = gold;
	               ctotal = 5;
	               checkUpdateCoins(p, &G, bonus, ctotal, handCount, &pass, &fail);
	               reset(&G, handCount, players);
	               G.hand[p][0] = smithy;
	               G.hand[p][1] = smithy;
	               ctotal = 0;
	               checkUpdateCoins(p, &G, bonus, ctotal, handCount, &pass, &fail);
	               break;
	           default:
	        	   reset(&G, handCount, players);
	               ctotal = 0;
	               checkUpdateCoins(p, &G, bonus, ctotal, handCount, &pass, &fail);
	               break;
	       }
	    }
	 }
  }
  if (fail)
       printf ("   Status: FAILED\n");
   else
 	  printf ("   Status: PASSED\n");

	  printf ("   Passed: %d\n", pass);
	  printf ("   Failed: %d\n", fail);
  return 0;
}

