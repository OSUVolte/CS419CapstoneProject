#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define VERBOSE 0

void reset(struct gameState *G, int p, int stack ) {
	int i;
    memset(G, 23, sizeof(struct gameState));
    G->deckCount[p] = 0;
    G->handCount[p] = 0;
    G->discardCount[p] = 0;
    for(i=curse; i <= treasure_map; i++) {
        G->supplyCount[i] = stack;
    }
}

void set(struct gameState *G, int p, int tf, int sp ) {
    switch (tf) {
        case 0:
        	G->discard[p][G->discardCount[p]] = sp;
        	G->discardCount[p]++;
            break;
        case 1:
        	G->deck[p][G->deckCount[p]] = sp;
        	G->deckCount[p]++;
            break;
        case 2:
        	G->hand[p][G->handCount[p]] = sp;
        	G->handCount[p]++;
        	break;
        default:
        	break;
    }
    G->supplyCount[sp]--;
}


int mycompare(struct gameState *G1, struct gameState *G2, int p) {

	int i,j,found;

	if (G1->deckCount[p] != G2->deckCount[p]) { return 1; }
	if (G1->handCount[p] != G2->handCount[p]) { return 1; }
	if (G1->discardCount[p] != G2->discardCount[p]) { return 1; }

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

	for(i=0; i<G1->discardCount[p]; i++) {
		found = 0;
		for(j=0; j<G2->discardCount[p]; j++) {
			if (G1->discard[p][i] == G2->discard[p][j]) { found = 1; }
	    }
		if (found == 0)	{ return 1; }
	}

    for(i=curse; i <= treasure_map; i++) {
        if (G1->supplyCount[i] != G2->supplyCount[i]) { return 1; }
    }

	return 0;
}
void myprint(struct gameState *G, int p, int supplyPos) {
   int i;
   for(i=0; i<5; i++) {
	   printf("i:%d  deck:%d   hand:%d   discard:%d   played:%d\n", i, G->deck[p][i], G->hand[p][i], G->discard[p][i], G->playedCards[i]);
   }
   printf("deckCount:%d   handCount:%d   discardCount:%d  supplyCount[%d]:%d\n", G->deckCount[p], G->handCount[p], G->discardCount[p], supplyPos,  G->supplyCount[supplyPos]);
}

int main () {
  int pass = 0;
  int fail = 0;
  int r1, r2, p, supplyPos, toFlag;

  struct gameState post, pre;

  printf ("Unit Test: unittest2.c\n");
  printf ("   Target: gainCard Function\n");
  for (p = 0; p < 4; p++) {
      for (toFlag = 0; toFlag<=2; toFlag++) {
	      for(supplyPos = curse; supplyPos <= treasure_map; supplyPos++) {
	    	  reset(&post, p, 1);
	    	  memcpy (&pre, &post, sizeof(struct gameState));
	    	  set(&pre, p, toFlag, supplyPos);
	    	  r1 = gainCard(supplyPos, &post, toFlag, p);
	    	  r2 = mycompare(&pre, &post, p);
	    	  if ( ( r1 == 0 ) && ( r2 == 0) ) { pass++; }
	    	  else {
	    		  fail++;
	    		  if(VERBOSE) {
	    			  printf("\nFAIL:  p:%d  toFlag:%d  supplyPos:%d\n", p, toFlag, supplyPos);
	    			  printf("ORACLE\n");
	    			  myprint(&pre, p, supplyPos);
	    			  printf("RESULTS\n");
	    			  myprint(&post, p, supplyPos);
	                  printf("\n");
	    		  }
	    	  }
	      }
	  }
  }
  for(supplyPos = curse; supplyPos <= treasure_map; supplyPos++) {
	  reset(&post, p, 0);
	  r1 = gainCard(supplyPos, &post, 0, p);
	  if (r1 == -1) { pass++; }
	  else {
		  fail++;
		  if(VERBOSE) {
			  printf("FAIL:  p:%d  toFlag:%d  supplyPos:%d\n", p, toFlag, supplyPos);
			  printf("\nORACLE\n");
			  myprint(&pre, p, supplyPos);
			  printf("RESULTS\n");
			  myprint(&post, p, supplyPos);
              printf("\n");
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

