#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define VERBOSE 0


void reset(struct gameState *G, int p, int source, int offset, int cardIndex) {
	int i;
	int tmp[5];
    memset(G, 23, sizeof(struct gameState));
    G->whoseTurn = p;

    for(i=0;i<5;i++) {
    	if (i == offset)   {
    		tmp[i] = cardIndex;
    	} else if (i == offset+1) {
    		tmp[i] = cardIndex+1;
    	} else { tmp[i] = adventurer+i;}
    }

    if (source == 1) {
    	for(i=0; i < 5; i++) {
    	    G->deck[p][i] = tmp[i];
    	}
    	G->deckCount[p]=5;
    	G->discardCount[p]=0;
    } else {
    	for(i=0; i < 5; i++) {
        	 G->discard[p][i] = tmp[i];
        }
        G->deckCount[p]=0;
        G->discardCount[p]=5;
    }
    G->handCount[p]=0;
    G->playedCardCount = 0;
}


void set(struct gameState *G, int p, int source) {
	int i, tcount=0;
	if (source == 0) {
	   for(i=0; i<G->discardCount[p]; i++) {
		   G->deck[p][i] = G->discard[p][i];
		   G->discard[p][i] = -1;
	   }
	   G->deckCount[p] = G->discardCount[p];
	   G->discardCount[p] = 0;
	}
	for(i=4; i>=0; i--) {
		if((G->deck[p][i] >= copper) && (G->deck[p][i] <= gold)) {
			G->hand[p][G->handCount[p]] = G->deck[p][i];
			G->handCount[p]++;
			G->deckCount[p]--;
			tcount++;
		} else {
			G->discard[p][G->discardCount[p]] = G->deck[p][i];
			G->discardCount[p]++;
			G->deckCount[p]--;
		}
		if(tcount == 2) {
			break;
		}
	}
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
	return 0;
}


void myprint(struct gameState *G, int p) {
   int i;
   for(i=0; i<5; i++) {
	   printf("i:%d  deck:%d   hand:%d   discard:%d\n", i, G->deck[p][i], G->hand[p][i], G->discard[p][i]);
   }
   printf("deckCount:%d   handCount:%d   discardCount:%d\n", G->deckCount[p], G->handCount[p], G->discardCount[p]);
}

int main () {
	  int pass = 0;
	  int fail = 0;
	  int offset;
      int r;
	  int p;
	  int source;
	  int cardIndex;
	  struct gameState post, pre;

	  printf ("Unit Test: cardtest2.c\n");
	  printf ("   Target: Adventurer Card\n");
      for(p=0; p<4; p++) {
    	  for(source=0; source<2; source++) {
    		  for(cardIndex=4; cardIndex<6; cardIndex++) {
    			  for(offset=0; offset<4; offset++) {
    			      reset(&post, p, source, offset, cardIndex);
    			      memcpy (&pre, &post, sizeof(struct gameState));
    			      set(&pre, p, source);
    			      playAdventurer(&post);
    			      r = mycompare(&pre, &post, p);
					  if (r == 0) { pass++; }
					  else {
						  fail++;
						  if(VERBOSE){
							  printf("\nFailed Test: p:%d source:%d cardIndex:%d\n", p, source, cardIndex);
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


