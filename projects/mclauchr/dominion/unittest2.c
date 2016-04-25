/***********************************************************************
** Class:  CS 362 - Software Engineering II - 400
** Author:  Chris McLaughlin
** File:  unittest2.c
** Date:  4/23/16
** Due Date: 4/24/16
**
** Description:  Test for dominion.c function getCost.  This function 
** takes a cardNumber and returns the cost that the player would have to
** incur to purchase said card.  The important features or this function
** is that the cost must be appropriate for every type of card.  I'll
** need to lookup each card again to make sure that my tests have the 
** appropriate conditionals as well.
**		1. Test that each card will return appropriate cost
**		2. Test that inappropriate card will return error
**			a. card number too high
**			b. card number too low
**		
** Makefile: gcc -o unittest2 -g unittest2.c dominion.o rngs.o $(CFLAGS)
************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "interface.h"


int main()
{
	//NOTE: Here are the integers which represent each card (see dominion.h)
	/*
	0 curse
	1 estate
	2 duchy
	3 province
	4 copper
	5 silver
	6 gold
	7 adventurer
	8 council room
	9 feast
	10 gardens
	11 mine
	12 remodel
	13 smithy
	14 village
	15 baron
	16 great_hall
	17 minion
	18 steward
	19 tribute
	20 ambassador
	21 cutpurse
	22 embargo
	23 outpost
	24 salvager
	25 sea_hag
	26 treasure_map
	*/
	
	//declare array of ints to represent all cards
	int testCost;
	int testCard;
	int i;
		
		//NOTE: The costs are set as constants in interface.h...I will make the assumption that
		//these constant values are correct and have not been tampered with in any way.  I will also
		//verify these costs through online resources before testing on these values.
	
		/*
		COPPER_COST 0
		SILVER_COST 3
		GOLD_COST 6
		ESTATE_COST 2
		DUCHY_COST 5
		PROVINCE_COST 8
		CURSE_COST 0
		ADVENTURER_COST 6
		COUNCIL_ROOM_COST 5
		FEAST_COST 4
		GARDEN_COST 4
		MINE_COST 5
		REMODEL_COST 4
		SMITHY_COST 4
		VILLAGE_COST 3
		BARON_COST 4
		GREAT_HALL_COST 3
		MINION_COST 5
		STEWARD_COST 3
		TRIBUTE_COST 5
		AMBASSADOR_COST 3
		CUTPURSE_COST 4
		EMBARGO_COST 2
		OUTPOST_COST 5
		SALVAGER_COST 4
		SEA_HAG_COST 4
		TREASURE_MAP_COST 4
		*/
		
		printf("*****TEST: getCost() - BEGIN ***********\n\n");
		
			for (i = 0; i < 27; i++)
			{
				testCost = getCost(i);
				
				//curse test
				if (i == 0)
				{
					if (testCost == CURSE_COST)
					{
						printf("Test1: Curse Cost: PASS\n");
					}
					else
					{	
						printf("Test1: Curse Cost: FAIL\n");
					}
				}
				
				//estate test
				if (i == 1)
				{
					if (testCost == ESTATE_COST)
					{
						printf("Test1: Estate Cost: PASS\n");
					}
					else
					{
						printf("Test1: Estate Cost: FAIL\n");
					}
				}
				
				//duchy test
				if (i == 2)
				{
					if (testCost == DUCHY_COST)
					{
						printf("Test1: Duchy Cost: PASS\n");
					}
					else
					{
						printf("Test1: Duchy Cost: FAIL\n");
					}
				}
				
				//province test
				if (i == 3)
				{
					if (testCost == PROVINCE_COST)
					{
						printf("Test1: Province Cost: PASS\n");
					}
					else
					{
						printf("Test1: Province Cost: FAIL\n");
					}
				}
				
				//copper test
				if (i == 4)
				{
					if (testCost == COPPER_COST)
					{
						printf("Test1: Copper Cost: PASS\n");
					}
					else
					{
						printf("Test1: Copper Cost: FAIL\n");
					}
				}
				
				//silver test
				if (i == 5)
				{
					if (testCost == SILVER_COST)
					{
						printf("Test1: Silver Cost: PASS\n");
					}
					else
					{
						printf("Test1: Silver Cost: FAIL\n");
					}
				}
				
				//gold test
				if (i == 6)
				{
					if (testCost == GOLD_COST)
					{
						printf("Test1: Gold Cost: PASS\n");
					}
					else
					{
						printf("Test1: Gold Cost: FAIL\n");
					}
				}
				
				//adventurer test
				if (i == 7)
				{
					if (testCost == ADVENTURER_COST)
					{
						printf("Test1: Adventurer Cost: PASS\n");
					}
					else
					{
						printf("Test1: Adventurer Cost: FAIL\n");
					}
				}
				
				//council_room test
				if (i == 8)
				{
					if (testCost == COUNCIL_ROOM_COST)
					{
						printf("Test1: Council_room Cost: PASS\n");
					}
					else
					{
						printf("Test1: Council_room Cost: FAIL\n");
					}
				}
				
				//feast test
				if (i == 9)
				{
					if (testCost == FEAST_COST)
					{
						printf("Test1: Feast Cost: PASS\n");
					}
					else
					{
						printf("Test1: Feast Cost: FAIL\n");
					}
				}
				
				//gardens test
				if (i == 10)
				{
					if (testCost == GARDEN_COST)
					{
						printf("Test1: Gardens Cost: PASS\n");
					}
					else
					{
						printf("Test1: Gardens Cost: FAIL\n");
					}
				}
				
				//mine test
				if (i == 11)
				{
					if (testCost == MINE_COST)
					{
						printf("Test1: Mine Cost: PASS\n");
					}
					else
					{
						printf("Test1: Mine Cost: FAIL\n");
					}
				}
				
				//remodel test
				if (i == 12)
				{
					if (testCost == REMODEL_COST)
					{
						printf("Test1: Remodel Cost: PASS\n");
					}
					else
					{
						printf("Test1: Remodel Cost: FAIL\n");
					}
				}
				
				//smithy test
				if (i == 13)
				{
					if (testCost == SMITHY_COST)
					{
						printf("Test1: Smithy Cost: PASS\n");
					}
					else
					{
						printf("Test1: Smithy Cost: FAIL\n");
					}
				}
				
				//Village test
				if (i == 14)
				{
					if (testCost == VILLAGE_COST)
					{
						printf("Test1: Village Cost: PASS\n");
					}
					else
					{
						printf("Test1: Village Cost: FAIL\n");
					}
				}
				
				//baron test
				if (i == 15)
				{
					if (testCost == BARON_COST)
					{
						printf("Test1: Baron Cost: PASS\n");
					}
					else
					{
						printf("Test1: Baron Cost: FAIL\n");
					}
				}
				
				//great_hall test
				if (i == 16)
				{
					if (testCost == GREAT_HALL_COST)
					{
						printf("Test1: Great_hall Cost: PASS\n");
					}	
					else
					{
						printf("Test1: Great_hall Cost: FAIL\n");
					}
				}
				
				//minion test
				if (i == 17)
				{
					if (testCost == MINION_COST)
					{
						printf("Test1: Minion Cost: PASS\n");
					}
					else
					{
						printf("Test1: Minion Cost: FAIL\n");
					}
				}
				
				//steward test
				if (i == 18)
				{
					if (testCost == STEWARD_COST)
					{
						printf("Test1: Steward Cost: PASS\n");
					}
					else
					{
						printf("Test1: Steward Cost: FAIL\n");
					}
				}
				
				//tribute test
				if (i == 19)
				{
					if (testCost == TRIBUTE_COST)
					{
						printf("Test1: Tribute Cost: PASS\n");
					}
					else
					{
						printf("Test1: Tribute Cost: FAIL\n");
					}
				}
				
				//ambassador test
				if (i == 20)
				{
					if (testCost == AMBASSADOR_COST)
					{
						printf("Test1: Ambassador Cost: PASS\n");
					}
					else
					{
						printf("Test1: Ambassador Cost: FAIL\n");
					}
				}
				
				//cutpurse test
				if (i == 21)
				{
					if (testCost == CUTPURSE_COST)
					{
						printf("Test1: Cutpurse Cost: PASS\n");
					}
					else
					{
						printf("Test1: Cutpurse Cost: FAIL\n");
					}
				}
				
				//embargo test
				if (i == 22)
				{
					if (testCost == EMBARGO_COST)
					{
						printf("Test1: Embargo Cost: PASS\n");
					}
					else
					{
						printf("Test1: Embargo Cost: FAIL\n");
					}
				}
				
				//outpost test
				if (i == 23)
				{
					if (testCost == OUTPOST_COST)
					{
						printf("Test1: Outpost Cost: PASS\n");
					}
					else
					{
						printf("Test1: Outpust Cost: FAIL\n");
					}
				}
				
				//salvager test
				if (i == 24)
				{
					if (testCost == SALVAGER_COST)
					{
						printf("Test1: Salvager Cost: PASS\n");
					}
					else
					{
						printf("Test1: Salvager Cost: FAIL\n");
					}
				}
				
				//sea-hag test
				if (i == 25)
				{
					if (testCost == SEA_HAG_COST)
					{
						printf("Test1: Sea_hag Cost: PASS\n");
					}
					else
					{
						printf("Test1: Sea_hag Cost: FAIL\n");
					}
				}
				
				//treasure_map test
				if (i == 26)
				{
					if (testCost == TREASURE_MAP_COST)
					{
						printf("Test1: Treasure_map Cost: PASS\n");
					}
					else
					{
						printf("Test1: Treasure_map Cost: FAIL\n");
					}
				}
				
			}
			
			printf("\n");
				
				//boundary case too low -1
				testCard = -1;
					
					testCost = getCost(testCard);
					
						if (testCost == -1)
						{
							printf("Test2: Catch Card Number TOO LOW: PASS\n");
						}
						else 
						{
							printf("Test2: Catch Card Number TOO LOW: FAIL\n");
						}
			
				//boundary case too high 27
				testCard = 27;
				
					testCost = getCost(testCard);
					
						if (testCost == -1)
						{
							printf("Test2: Catch Card Number TOO HIGH: PASS\n\n");
						}
						else 
						{
							printf("Test2: Catch Card Number TOO HIGH: FAIL\n\n");
						}
			
		printf("*****TEST: getCost() - END *************\n\n");
	
	return 0;
}