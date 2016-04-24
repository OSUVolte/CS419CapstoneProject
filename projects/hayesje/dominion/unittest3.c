#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define VERBOSE 0


void reset(struct gameState *G, int p, int handCount ) {
	int i;
    memset(G, 23, sizeof(struct gameState));
    G->playedCardCount = 0;
    G->playedCards[0]  = 0;
    G->handCount[p] = handCount;
    for(i=0; i<handCount; i++) {
    	G->hand[p][i] = adventurer + i;
    }
}

void set(struct gameState *G,  int p, int trash, int handPos ) {

    if (!trash) {
    	G->playedCards[G->playedCardCount] = G->hand[p][handPos];
    	G->playedCardCount++;
    }

    if (G->handCount[p] == 1) {
    	   G->hand[p][0] = -1;
    } else if(G->handCount[p] == handPos+1) {
    	   G->hand[p][handPos] = -1;
    } else {
    	   G->hand[p][handPos] = G->hand[p][G->handCount[p] - 1];
    	   G->hand[p][G->handCount[p] -1 ] = -1;
    }

    G->handCount[p]-- ;
}


int mycompare(struct gameState *G1, struct gameState *G2, int p) {

	int i,j,found;

	if (G1->handCount[p] != G2->handCount[p]) { return 1; }
	if (G1->playedCardCount != G2->playedCardCount) { return 1; }

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
   printf("deckCount:%d   handCount:%d   discardCount:%d\n", G->deckCount[p], G->handCount[p], G->discardCount[p]);
}


int main () {

  int pass = 0;
  int fail = 0;
  int  r, p, trashFlag, handCount, handPos;


  struct gameState post, pre;

  printf ("Unit Test: unittest3.c\n");
  printf ("   Target: discardCard Function\n");
  for (p = 0; p < 4; p++) {
      for (trashFlag = 0; trashFlag < 2; trashFlag++) {
	      for(handCount = 1; handCount <= 3; handCount++) {
	    	  for(handPos = 0; handPos < handCount; handPos++) {
	    	     reset(&post, p, handCount);
	    	     memcpy (&pre, &post, sizeof(struct gameState));
	    	     set(&pre, p, trashFlag, handPos);
	    	     discardCard(handPos, p, &post, trashFlag);
	    	     r = mycompare(&pre, &post, p);
				 if (r == 0) { pass++; }
				 else {
					  fail++;

					  if(VERBOSE){
						  printf("\nFailed Test: p:%d handCount:%d handPos:%d trashFlag:%d\n", p, handCount, handPos, trashFlag);
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
  }
  if (fail)
       printf ("   Status: FAILED\n");
   else
 	  printf ("   Status: PASSED\n");

   printf ("   Passed: %d\n", pass);
   printf ("   Failed: %d\n", fail);

  return 0;
}

