#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "cbmc_dominion.h"
#include "dominion_helpers.h"
#include "dominion.h"
#include "rngs.h"
#include "interface.h"

int main()
{
	struct gameState *game = newGame();
	int tmp = 0;
	int player = 3;
	int choice1 = 1;
	
	printf("Running Unit Test: Feast\n");
    
	int result = func_feast(player, &tmp, choice1, game);
	assert(result == 0);
	printf("unit Test: Feast test successful \n");	
return 0;
}