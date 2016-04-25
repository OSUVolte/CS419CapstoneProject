#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main (int argc, char* argv[]){

	struct gameState G;
	int i, r;
	int c[10];

	srand(time(NULL));

	printf("Testing numHandCards.\n");

	for(i=0; i<10; i++){
		c[i] = rand()%10;
		G.whoseTurn = i;
		G.handCount[i] = c[i];
		r = numHandCards(&G);

		if(c[i] == r){
			printf("  numHandCards(): PASS with result %d\n", r);
		} 
	}

	printf("Test complete.\n");
	
	return 0;
}
