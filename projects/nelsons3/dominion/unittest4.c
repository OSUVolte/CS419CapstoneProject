#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	 printf("testing isGameOver\n");
	int counter;
	struct gameState *state = malloc(sizeof(struct gameState));
//no more province cards ends the game
//set provinces == 0 then test for running game
	state->supplyCount[province] = 0 ; 
	if( isGameOver(state) == 1 )
    {
		printf("game ends when all provinces are gone\n");
	} else if ( isGameOver(state) == 0 ){
		printf("error->isGameOver: no provinces available but game still running\n");
	}
//game also ends when 3 supply piles are consumed 
//set the supply count to 3 then test for running game
	for (counter = 0; counter < 3 ; counter++)
    {
		state->supplyCount[counter] = 0;
	} 
	if( isGameOver(state) == 0 )
    {
		printf("error->isGameOver: returned false with win condition\n");
	} else if (isGameOver(state) == 1){
		printf("supply pile Win Condition properly returned as true \n");
	}
	printf("Unit test 4 passed. \n");
return 0;
}
