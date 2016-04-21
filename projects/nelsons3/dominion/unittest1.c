#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

int main(int argc, char* argv[])
{
	int counter;

	printf("Test creation of new games.\n");
	printf("only one will run at a time but 1000 will be created.\n");
	printf("Unit test 1.\n");
	//heres our simple test...create the game struct as shown on 
	//line 16 of dominion.c and then make sure the game actually exists!
	for (counter = 0; counter < 1000; counter++) 
	{
		struct gameState *g = newGame();
		assert(g != NULL);
		free(g);
	}
	printf("unit Test 1 Passed \n");
return 0;
}
