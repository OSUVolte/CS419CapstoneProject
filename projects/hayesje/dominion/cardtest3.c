#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define VERBOSE 0


void reset(struct gameState *G, int p, int salPos) {
	int i;
    memset(G, 23, sizeof(struct gameState));
    G->numBuys = 1;
    G->coins = 1;
    G->whoseTurn = p;
    G->hand[p][salPos] = salvager;
    for(i=0; i < 5; i++) {
    	if (i != salPos) { G->hand[p][i] = copper+i; }
    }
    G->handCount[p]=5;
    G->discardCount[p]=0;
    G->deckCount[p]=0;
    G->playedCardCount = 0;
}


void set(struct gameState *G, int p,  int choice, int salPos) {
	int i;
	int tmp[5];
	int j = 0;
	G->numBuys++;
	G->coins = 1;
    if (choice >= 0) {
    	switch(G->hand[p][choice]) {
    	    case 4:  G->coins = 1;
    		    break;
    	    case 5:  G->coins = 4;
    			break;
    	    case 6:  G->coins = 7;
    			break;
    	    case 7:  G->coins = 7;
    			break;
    	    case 8:  G->coins = 6;
    			break;
    	    default: G->coins = 1;
    			break;
    	}
    	G->hand[p][choice] = -1;
    	G->handCount[p]--;
    }
	G->playedCards[0] = G->hand[p][salPos];
	G->handCount[p]--;
	G->hand[p][salPos] = -1;
	G->playedCardCount++;

	for(i=0; i< 5; i++) {
		if (G->hand[p][i] != -1) {
			tmp[j] = G->hand[p][i];
			j++;
			G->hand[p][i] = -1;
		}
	}
	for(i=0; i<G->handCount[p];i++) {
        G->hand[p][i] = tmp[i];
	}
}

int mycompare(struct gameState *G1, struct gameState *G2, int p) {

	int i,j,found;
	if (G1->handCount[p] != G2->handCount[p])       { return 1; }
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
    if (G1->numBuys != G2->numBuys)  { return 1; }
    if (G1->coins   != G2->coins)    { return 1; }
	return 0;
}

void myprint(struct gameState *G, int p) {
   int i;
   for(i=0; i<5; i++) {
	   printf("i:%d  deck:%d   hand:%d   discard:%d   played:%d\n", i, G->deck[p][i], G->hand[p][i], G->discard[p][i], G->playedCards[i]);
   }
   printf("deckCount:%d   handCount:%d   discardCount:%d  playedCount:%d\n", G->deckCount[p], G->handCount[p], G->discardCount[p], G->playedCardCount);
   printf("numBuys:%d    coins:%d\n", G->numBuys, G->coins);
}

int main () {
	  int pass=0;
	  int fail=0;
	  int r;
	  int p = 0;
	  int choice = 3;
	  int salPos = 4;
	  struct gameState post, pre;
	  printf ("Unit Test: cardtest3.c\n");
	  printf ("   Target: Salvager Card\n");
	  for(p=0; p<4; p++) {
		  for(salPos=0; salPos<5; salPos++) {
			  for(choice=0; choice<5; choice++) {
				  if (choice != salPos) {
					  reset(&post, p, salPos);
					  memcpy (&pre, &post, sizeof(struct gameState));
					  set(&pre, p, choice, salPos);
					  playSalvager(&post, choice, salPos);
					  r = mycompare(&pre, &post, p);
					  if (r == 0) { pass++; }
					  else {
					      fail++;
					      if(VERBOSE){
						      printf("\nFailed Test: p:%d salPos:%d choice:%d\n", p, salPos, choice);
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



