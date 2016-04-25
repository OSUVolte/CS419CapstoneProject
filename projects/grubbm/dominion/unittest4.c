#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "math.h"


int main (){



int cost;

printf("getCost Unit Test\n");

cost = getCost(adventurer);
assert(cost == 6); 

cost = getCost(copper);
assert(cost == 0); 


printf("getCost Test PASSED\n"); 


return 0;

}
