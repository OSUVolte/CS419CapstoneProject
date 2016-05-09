#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

int checkGreatHall(int p, struct gameState *post, int handPos, int r) {
  int q;
  struct gameState pre;
  
  memcpy(&pre, post, sizeof(struct gameState));

  q = great_hallCard(p, post, handPos);
  
  if(post->handCount[p] != pre.handCount[p])
  {
	  printf("TESTING that hand count for current player has stayed the same(draw a new card and discard great_hall)\n");
	  printf("\tHand Count: %d\tExpected: %d\n", post->handCount[p], pre.handCount[p]);
	  r++;
  }
  if(pre.deckCount[p] == 0 && post->deckCount[p] != pre.discardCount[p] - 1)
  {
	printf("TESTING that deck card count for current player has decreased by 1\n");
	printf("\tDeck Count: %d\tExpected: %d\n", post->deckCount[p], pre.discardCount[p] - 1);
	printf("Player: %d, DeckCountPost: %d, DeckCountPre: %d\n", p, post->deckCount[p], pre.deckCount[p]);
	r++;
  }
  else if(pre.deckCount[p] != 0 && post->deckCount[p] != pre.deckCount[p] - 1)
  {
	printf("TESTING that deck card count for current player has decreased by 1\n");
	printf("\tDeck Count: %d\tExpected: %d\n", post->deckCount[p], pre.deckCount[p] - 1);
	printf("Player: %d, DeckCountPost: %d, DeckCountPre: %d\n", p, post->deckCount[p], pre.deckCount[p]);
	r++;	
  }
  
  assert (r == 0);
  return r;
}

int main () {

  int i, n, r, p, deckCount, discardCount, handCount;

  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  struct gameState G;

  printf ("Testing great_hallCard.\n");

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
    G.discardCount[p] = floor(Random() * MAX_DECK);
    G.handCount[p] = floor(Random() * MAX_HAND);
	G.playedCardCount = floor(Random() * MAX_DECK);
    r = checkGreatHall(p, &G, 0, r);
  }

  printf ("ALL TESTS OK\n");
  printf("Number of Iterations: %d\nNumber of Unexpected Results: %d\n", n, r);
  exit(0);

  return 0;
}
