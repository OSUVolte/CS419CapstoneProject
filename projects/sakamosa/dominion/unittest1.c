#include "dominion.h" 
#include "dominion_helpers.h"  
#include <stdio.h> 
#include <stdlib.h>

//testing of getCost function

int main(){
//compare returned value to correct value for each card type
CARD card_array = [curse, estate, duchy, province, copper, silver, gold, adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall, minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map];
int value_array = [0, 2, 5, 8, 0, 3, 6, 6, 5, 4, 4, 5, 4, 4, 3, 4, 3, 5, 3, 5, 3, 4, 2, 5, 4, 4, 4];
int length = 27;
int i;
int passed = 0;
for(i = 0; i< length; i++){
    int cost = getCost(card_array[i]);
    if(cost != value_array[i]{
        prinf("%d: FAIL value should be %d but is %d\n", i, value_array[i], cost);
    } 
    else
        passed++;
}
printf("\nPassed %d of %d card tests\n", passed, length);
//test against invalid card type
if(getCost(length + 1) != -1){
    printf("FAIL invalid card value does not return -1\n");
}
else
    printf("Passed invalid card test\n");    
}