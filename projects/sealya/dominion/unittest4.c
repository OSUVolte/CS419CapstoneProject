/*
Aaron Sealy
Quiz 2
CS 362
Spring 2016

Tests getCost()
Tested behavior:  Function returns cost of card
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int i,inval;
    int val = 1;
    int everything[] = {curse, estate, duchy, province, copper, silver, gold, adventurer,
    council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall, minion,
    steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map};

    int values[] = {0,2,5,8,0,3,6,6,5,4,4,5,4,4,3,4,3,5,3,5,3,4,2,5,4,4,4};

    /////// Announce testing
    printf("Testing getCost() function:\n");
    for (i = 0; i<27;i++){
        if (getCost(everything[i]) != values[i]){
            val = 0;
            printf("Error for card number: %d", i);
        }
    }

    // Success message if everything passes
    if(val == 1){
        printf("Success: All valid inputs passed!\n");
    }

    inval = getCost(-1); // below valid range
    if (inval != -1){
        printf("Error:  On invalid inputs");
    }

    inval = getCost(27); // above valid range
    if (inval != -1){
        printf("Error:  On invalid inputs");
    }

    // Success message if everything passes
    if(inval == -1){
        printf("Success: All invalid inputs returned -1 as expected\n");
    }

    return 0;
}
