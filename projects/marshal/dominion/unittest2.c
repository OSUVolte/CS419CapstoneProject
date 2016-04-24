/* -----------------------------------------------------------------------
 * Name: Alex Marsh
 * CS362
 * unittest2.c
 * This tests the function getCost() function in dominion.c
 * Include the following lines in your makefile:
 *
 * unittest2: unittest2.c dominion.o rngs.o
 *      gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main(){
    int error = 0; 
    printf("----------------- Testing getCost() ----------------\n");

    printf("\n");
    
    if(getCost(copper)!= 0){
        printf("FAIL: copper incorrect\n");
        error++;
    }
    
    if(getCost(silver)!= 3){
        printf("FAIL: silver incorrect\n");
        error++;
    }
    
    if(getCost(gold)!= 6){
        printf("FAIL: gold incorrect\n");
        error++;
    }
    
    if(getCost(estate)!= 2){
        printf("FAIL: estate incorrect\n");
        error++;
    }
    
    if(getCost(duchy)!= 5){
        printf("FAIL: duchy incorrect\n");
        error++;
    }
    
    if(getCost(province)!= 8){
        printf("FAIL: province incorrect\n");
        error++;
    }
    
    if(getCost(curse)!= 0){
        printf("FAIL: curse incorrect\n");
        error++;
    }
    
    if(getCost(adventurer)!= 6){
        printf("FAIL: adventurer incorrect\n");
        error++;
    }
    
    if(getCost(council_room)!= 5){
        printf("FAIL: council_room incorrect\n");
        error++;
    }
    
    if(getCost(feast)!= 4){
        printf("FAIL: feast incorrect\n");
        error++;
    }
    
    if(getCost(gardens)!= 4){
        printf("FAIL: garden incorrect\n");
        error++;
    }
    
    if(getCost(mine)!= 5){
        printf("FAIL: mine incorrect\n");
        error++;
    }
    
 /**   if(getCost(moneylender)!= 4){
        printf("FAIL: moneylender incorrect\n");
        error++;
    }**/
    
    if(getCost(remodel)!= 4){
        printf("FAIL: remodel incorrect\n");
        error++;
    }
    
    if(getCost(smithy)!= 4){
        printf("FAIL: smithy incorrect\n");
        error++;
    }
    
    if(getCost(village)!= 3){
        printf("FAIL: village incorrect\n");
        error++;
    }
    
/**    if(getCost(woodcutter)!= 3){
        printf("FAIL: woodcutter incorrect\n");
        error++;
    }**/
    
    if(getCost(baron)!= 4){
        printf("FAIL: baron incorrect\n");
        error++;
    }
    
    if(getCost(great_hall)!= 3){
        printf("FAIL: great_hall incorrect\n");
        error++;
    }
    
    if(getCost(minion)!= 5){
        printf("FAIL: minion incorrect\n");
        error++;
    }
    
/**    if(getCost(shanty_town)!= 3){
        printf("FAIL: shanty_town incorrect\n");
        error++;
    }**/
    
    if(getCost(steward)!= 3){
        printf("FAIL: steward incorrect\n");
        error++;
    }
    
    if(getCost(tribute)!= 5){
        printf("FAIL: tribute incorrect\n");
        error++;
    }
    
 /**   if(getCost(wishing_well)!= 3){
        printf("FAIL: wishing_well incorrect\n");
        error++;
    }**/
    
    if(getCost(ambassador)!= 3){
        printf("FAIL: ambassador incorrect\n");
        error++;
    }
    
    if(getCost(cutpurse)!= 4){
        printf("FAIL: cutpurse incorrect\n");
        error++;
    }
    
    if(getCost(embargo)!= 2){
        printf("FAIL: embargo incorrect\n");
        error++;
    }
    
    if(getCost(outpost)!= 5){
        printf("FAIL: outpost incorrect\n");
        error++;
    }
    
    if(getCost(salvager)!= 4){
        printf("FAIL: salvager incorrect\n");
        error++;
    }
    
    if(getCost(sea_hag)!= 4){
        printf("FAIL: sea_hag incorrect\n");
        error++;
    }
    
    if(getCost(treasure_map)!= 4){
        printf("FAIL: treasure_map incorrect\n");
        error++;
    }
    
    if(error == 0)
        printf("ALL TESTS PASSED FOR getCost()\n");
    else
        printf("There are %d errors\n", error);
    
    return 0;
}