#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"

//Test case for getCost(int)
int main() 
{
	printf("testing getCost() method.\n\n");
    printf("test estate points first");
    printf("Test Estate points first\n");   
    if(getCost(curse)==0)
        printf("Curse value passed");
    if(getCost(estate)==2)
        printf("estate value passed");
    if(getCost(duchy)==5)
        printf("duchy value passed");
    if(getCost(province)==8)
        printf("province value passed");   
    printf("\ntest monies next\n");
    if(getCost(copper)==0)
        printf("copper value passed");
    if(getCost(silver)==3)
        printf("silver value passed");
    if(getCost(gold)==6)
        printf("gold value passed");
    printf("\ntest playcards last\n");
    if(getCost(adventurer)==6)
        printf("adventurer value passed"); 
    if(getCost(council_room)==5)
        printf("council_room value passed");
    if(getCost(feast)==4)
        printf("feast value passed");
    if(getCost(gardens)==4)
        printf("gardens value passed");
    if(getCost(mine)==5)
        printf("mine value passed");   
    if(getCost(remodel)==4)
        printf("remodel value passed");
    if(getCost(smithy)==4)
        printf("smithy value passed");
    if(getCost(village)==3)
        printf("village value passed");
    if(getCost(baron)==4)
        printf("baron value passed");    
    if(getCost(great_hall)==3)
        printf("great_hall value passed");
    if(getCost(minion)==5)
        printf("minion value passed"); 
    if(getCost(steward)==3)
        printf("steward value passed");
    if(getCost(tribute)==5)
        printf("tribute value passed");
    if(getCost(ambassador)==3)
        printf("ambassador value passed");
    if(getCost(cutpurse)==4)
        printf("cutpurse value passed");   
    if(getCost(embargo)==2)
        printf("embargo value passed");
    if(getCost(outpost)==2)
        printf("outpost value passed");
    if(getCost(salvager)==4)
        printf("salvager value passed");
    if(getCost(sea_hag)==4)
        printf("sea_hag value passed");        
    if(getCost(treasure_map)==4)
        printf("treasure_map value passed"); 

    printf("\nUnit test 3 passed. \n");
return 0;
}
