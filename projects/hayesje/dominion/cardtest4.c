#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define VERBOSE 0


void reset(struct gameState *G, int p, int index, int handPos) {
	int i;
    memset(G, 23, sizeof(struct gameState));
    G->whoseTurn = p;
    G->numActions = 1;
    for(i=0; i<5; i++) {
       G->deck[p][i] = curse+i+index;
    }
    for(i=0; i<5; i++) {
       if (i == handPos) {
    	   G->hand[p][i] = village;
       } else {
           G->hand[p][i] = adventurer+i;
       }
    }
    G->deckCount[p]=5;
    G->handCount[p]=5;
    G->discardCount[p]=0;
    G->playedCardCount=0;
}


void set(struct gameState *G, int p, int handPos) {
   G->numActions = 3;
   G->hand[p][G->handCount[p]] = G->deck[p][G->deckCount[p]-1];
   G->handCount[p]++;
   G->deckCount[p]--;

   // update played card pile
   G->playedCards[0] = G->hand[p][handPos];
   G->playedCardCount++;

   G->hand[p][handPos] = G->hand[p][G->handCount[p]-1];
   G->handCount[p]--;
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
    if (G1->numActions != G2->numActions)  { return 1; }

	return 0;
}

void myprint(struct gameState *G, int p) {
   int i;
   for(i=0; i<5; i++) {
	   printf("i:%d  deck:%d   hand:%d   discard:%d   played:%d\n", i, G->deck[p][i], G->hand[p][i], G->discard[p][i], G->playedCards[i]);
   }
   printf("deckCount:%d   handCount:%d   discardCount:%d  playedCount:%d\n", G->deckCount[p], G->handCount[p], G->discardCount[p], G->playedCardCount);
   printf("numActions:%d\n", G->numActions);
}

int main () {
	  int pass = 0;
	  int fail = 0;
	  int r;
	  int p;
	  int index;
	  int handPos;

      struct gameState post, pre;

      printf ("Unit Test: cardtest4.c\n");
      printf ("   Target: Village Card\n");
      for(p=0; p<4; p++) {
    	  for(index=0; index<20; index++) {
    		  for(handPos=0; handPos<5; handPos++) {
    			  reset(&post, p, index, handPos);
    			  memcpy (&pre, &post, sizeof(struct gameState));
    			  set(&pre, p, handPos);
    			  playVillage(&post, handPos);
    			  r = mycompare(&pre, &post, p);
				  if (r == 0) { pass++; }
				  else {
					  fail++;
					  if(VERBOSE){
						  printf("\nFailed Test: p:%d index:%d handPos:%d\n", p, index, handPos);
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
