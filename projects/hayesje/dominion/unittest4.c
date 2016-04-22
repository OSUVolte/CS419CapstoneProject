#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define VERBOSE 0


void reset(struct gameState *G) {
	int i;
    memset(G, 23, sizeof(struct gameState));
    for(i=curse; i <= treasure_map; i++) {
        G->supplyCount[i] = 1;
    }
}

int main () {

  int pass = 0;
  int fail = 0;
  int target;
  int i, j, k, r;
  struct gameState G;

  printf ("Unit Test: unittest4.c\n");
  printf ("   Target: isGameOver Function\n");
  reset(&G);       // Check with all piles not empty
  r = isGameOver(&G);
  if (r == 0) { pass++; }
  else {
	  fail++;
	  if (VERBOSE)
		  printf("FAILED:   No Empty piles\n");
  }

  //Check that only an empty 'province' pile ends the game when 1 or 2 piles are empty
  for(i = curse; i <= treasure_map; i++) {
	  for (j = curse; j <= treasure_map; j++) {
         reset(&G);
         G.supplyCount[i] = 0;
         G.supplyCount[j] = 0;
         r = isGameOver(&G);
         if ((i == province) || (j == province)) {
    	     target = 1;
         } else {
    	     target = 0;
         }
         if (r == target) { pass++; }
         else {
       	  fail++;
       	  if (VERBOSE)
       		  printf("FAILED:   One/Two Piles Empty: %d  %d\n", i, j);
         }
	  }
  }
  //Check that all combines of 3 'province' pile ends the game
  for(i = curse; i <= treasure_map-2; i++) {
	  for (j = i+1; j <= treasure_map-1; j++) {
		  for (k = j+1; k <= treasure_map; k++) {
             reset(&G);
             G.supplyCount[i] = 0;
             G.supplyCount[j] = 0;
             G.supplyCount[k] = 0;
             r = isGameOver(&G);
             if (r == 1) { pass++; }
             else {
           	  fail++;
           	  if (VERBOSE)
           		  printf("FAILED:   Three piles empty:  %d  %d  %d\n", i, j, k);
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


