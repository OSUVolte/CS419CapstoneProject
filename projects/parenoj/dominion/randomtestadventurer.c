#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

int checkAdventurer(int p, struct gameState *post, int r) {
  int q;
  struct gameState pre;
  
  memcpy(&pre, post, sizeof(struct gameState));
  
  q = adventurerCard(post, p);
  
  if(post->handCount[p] != pre.handCount[p] + 1)
  {
	//printf("TESTING that hand count for current player is 1 more than it started at (Gain 2 treasures, but lose adventurer card)\n");
	//printf("\tHand Count: %d\tExpected: %d\n", post->handCount[p], pre.handCount[p] + 1);
	
	r++;
  }
  assert (q == 0);
  
  return r;
}

int main () {

  int i, n, r, p, q, deckCount, discardCount, handCount;

  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  struct gameState G;

  printf ("Testing adventurerCard.\n");

  printf ("RANDOM TESTS.\n");

  SelectStream(2);
  PutSeed(7);
  r = 0;
  
  for (n = 0; n < 2500; n++) {
    for (i = 0; i < sizeof(struct gameState); i++) {
      ((char*)&G)[i] = floor(Random() * 256);
    }
    p = floor(Random() * 2);
    G.deckCount[p] = floor(Random() * MAX_DECK);
	//Here, I set every card in the deck to be a valid card, otherwise segfaults occur
	for(q = 0; q < G.deckCount[p]; q++)
	{
		G.deck[p][q] = floor(Random() * 27);
	}
    G.discardCount[p] = floor(Random() * MAX_DECK);
    G.handCount[p] = floor(Random() * MAX_HAND);
	//Here, I set every card in the hand to be a valid card, otherwise segfaults occur
	for(q = 0; q < G.handCount[p]; q++)
	{
		G.hand[p][q] = floor(Random() * 27);
	}
	G.playedCardCount = floor(Random() * MAX_DECK);
    r = checkAdventurer(p, &G, r);
  }

  
  printf ("ALL TESTS OK\n");
  printf("Number of Iterations: %d\nNumber of Unexpected Results: %d\n", n, r);
  exit(0);
  return 0;
}
