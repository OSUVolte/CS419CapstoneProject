#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define VERBOSE 0


void reset(struct gameState *G, int p,  int handCount, int handPos) {
	int i;
    memset(G, 23, sizeof(struct gameState));
    G->whoseTurn = p;
    for(i=0; i < 5; i++) {
    	G->deck[p][i] = adventurer+i;
    }
    G->deckCount[p] = 5;
    for(i=0; i < handCount; i++) {
    	if (handPos == i) {
    		G->hand[p][i] = smithy;
    	} else {
    	    G->hand[p][i] = curse+i;
    	}
    }
    G->handCount[p] = handCount;
    G->playedCardCount = 0;
    G->playedCards[0] =  0;
}


void set(struct gameState *G,  int p,  int handPos ) {
	int i;
	// Remove deck cards from deck
    for(i=0; i < 2; i++) {
    	G->deck[p][i] = adventurer+i;
    }
    G->deckCount[p] = 2;
    // Add deck cards to hand
    G->hand[p][G->handCount[p]+0] = adventurer+4;
    G->hand[p][G->handCount[p]+1] = adventurer+3;
    G->hand[p][G->handCount[p]+2] = adventurer+2;
    G->handCount[p] += 3;
    // Discard smithy card from hand
    G->hand[p][handPos] = G->hand[p][G->handCount[p]-1];
    G->hand[p][G->handCount[p]-1] = -1;
    G->handCount[p]--;
    // Add smithy card to played pile
    G->playedCards[0] = smithy;
    G->playedCardCount = 1;
}

int mycompare(struct gameState *G1, struct gameState *G2, int p) {

	int i,j,found;

	if (G1->deckCount[p] != G2->deckCount[p]) { return 1; }
	if (G1->handCount[p] != G2->handCount[p]) { return 1; }
	if (G1->playedCardCount != G2->playedCardCount) { return 1; }

	for(i=0; i<G1->deckCount[p]; i++) {
		found = 0;
		for(j=0; j<G2->deckCount[p]; j++) {
			if (G1->deck[p][i] == G2->deck[p][j]) { found = 1; }
	    }
		if (found == 0)	{ return 1; }
	}

	for(i=0; i<G1->handCount[p]; i++) {
		found = 0;
		for(j=0; j<G2->handCount[p]; j++) {
			if (G1->hand[p][i] == G2->hand[p][j]) { found = 1; }
	    }
		if (found == 0)	{ return 1; }
	}

	for(i=0; i<G1->playedCardCount; i++) {
		found = 0;
		for(j=0; j<G2->playedCardCount; j++) {
			if (G1->playedCards[i] == G2->playedCards[j]) { found = 1; }
	    }
		if (found == 0)	{ return 1; }
	}

	return 0;
}


void myprint(struct gameState *G, int p) {
   int i;
   for(i=0; i<5; i++) {
	   printf("i:%d  deck:%d   hand:%d   discard:%d   played:%d\n", i, G->deck[p][i], G->hand[p][i], G->discard[p][i], G->playedCards[i]);
   }
   printf("deckCount:%d   handCount:%d    playedCardCount:%d\n", G->deckCount[p], G->handCount[p], G->playedCardCount);
}

int main () {
      int  pass=0;
      int  fail=0;
	  int  r, p;
	  int  handPos;
	  int  handCount;

	  struct gameState post, pre;

	  printf ("Unit Test: cardtest1.c\n");
      printf ("   Target: Smithy Card\n");
	  for (p=0; p < 4; p++) {
		  for(handCount=1; handCount<=3; handCount++) {
			  for(handPos=0; handPos<handCount; handPos++) {
				  reset(&post, p, handCount, handPos);
				  memcpy (&pre, &post, sizeof(struct gameState));
				  set(&pre, p, handPos);
				  playSmithy(&post, handPos);
    			  r = mycompare(&pre, &post, p);
				  if (r == 0) { pass++; }
				  else {
					  fail++;
					  if(VERBOSE){
						  printf("\nFailed Test: p:%d handCount:%d handPos:%d\n", p, handCount, handPos);
						  printf("ORACLE\n");
						  myprint(&pre, p);
						  printf("RESULTS\n");
						  myprint(&post, p);
						  printf("\n");
					  }
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

