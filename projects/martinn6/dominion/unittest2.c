/*********************************************************************************************
 * Developer: Nick Martin (martinn6)
 * Date: 20160422
 * Project: Assignement 3
 * Description: unittest1.c Tests the getCost() function.
 * *******************************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

 struct cards {
	char *name;
	int cost;
 };
 
 int constructCards(struct cards *card)
 {
	 /* cards and costs were researched from http://wiki.dominionstrategy.com */
	 card[curse].name = "curse";
	 card[curse].cost = 0;
	 
	 card[estate].name = "estate";
	 card[estate].cost = 2;
	 
	 card[duchy].name = "duchy";
	 card[duchy].cost = 5;
	 
	 card[province].name = "province";
	 card[province].cost = 8;
	 
	 card[copper].name = "copper";
	 card[copper].cost = 0;
	 
	 card[silver].name = "silver";
	 card[silver].cost = 3;

	 card[gold].name = "gold";
	 card[gold].cost = 6;
	 
	 card[adventurer].name = "adventurer";
	 card[adventurer].cost = 6;
	 
	 card[council_room].name = "council_room";
	 card[council_room].cost = 5;
	 
	 card[feast].name = "feast";
	 card[feast].cost = 4;
	 
	 card[gardens].name = "gardens";
	 card[gardens].cost = 4;
	 
	 card[mine].name = "mine";
	 card[mine].cost = 5;
	 
	 card[remodel].name = "remodel";
	 card[remodel].cost = 4;
	 
	 card[smithy].name = "smithy";
	 card[smithy].cost = 4;
	 
	 card[village].name = "village";
	 card[village].cost = 3;
	 
	 card[baron].name = "baron";
	 card[baron].cost = 4;
	 
	 card[great_hall].name = "great_hall";
	 card[great_hall].cost = 3;
	 
	 card[minion].name = "minion";
	 card[minion].cost = 5;	 
	 
	 card[steward].name = "steward";
	 card[steward].cost = 3;	 
	 
	 card[tribute].name = "tribute";
	 card[tribute].cost = 5;	 
	 
	 card[ambassador].name = "ambassador";
	 card[ambassador].cost = 3;
	 
	 card[cutpurse].name = "cutpurse";
	 card[cutpurse].cost = 4;
	 
	 card[embargo].name = "embargo";
	 card[embargo].cost = 2;
	 
	 card[outpost].name = "outpost";
	 card[outpost].cost = 5;
	 
	 card[salvager].name = "salvager";
	 card[salvager].cost = 4;
	 
	 card[sea_hag].name = "sea_hag";
	 card[sea_hag].cost = 4;
	 
	 card[treasure_map].name = "treasure_map";
	 card[treasure_map].cost = 4;
	 
	 return(0);
 }
 
 

int main() {
	struct cards card[27];
	
	constructCards(&card);
	
	int r;
    
	//test all costs of cards in deck and matching to definitions found on http://wiki.dominionstrategy.com
	for (int x = 0; x < 27; x++)
	{
		r = getCost(x);
		printf("Test card '%s': Cost returned:%d and expected:%d ", card[x].name, r, card[x].cost);
		if(r == card[x].cost)
			printf("PASSED\n");
		else
			printf("FAIL\n");
	}
	
	//test a failure (negative number)
	r = getCost(-10);
	printf("Test invalid input -10: Cost returned:%d and expected:-1 ", r);
	if(r == -1)
			printf("PASSED\n");
		else
			printf("FAIL\n");
	
	//boundary test failure (# gretaer then enum)
	r = getCost(28);
	printf("Test invalid input 28: Cost returned:%d and expected:-1 ", r);
	if(r == -1)
			printf("PASSED\n");
		else
			printf("FAIL\n");
		
    return 0;
}
