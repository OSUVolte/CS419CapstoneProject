/********************************************************
*	Name: 	Robert Tang
*	Class:	CS 362
*	File:	unittest1.c
*
*	Description: 
*		Test for card cost
********************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>

void testCardCost (int cardNumber)
{	
	// create information parts
	char* testCardName;
	int	testCardValue;
	
	//	set values 
	switch( cardNumber )
    {
		case 0:
			testCardName = "curse";
			testCardValue = 0;
			break;
		case 1:
			testCardName = "estate";
			testCardValue = 2;
			break;
		case 2:
			testCardName = "duchy";
			testCardValue =  5;
			break;
		case 3:
			testCardName = "province";
			testCardValue =  8;
			break;
		case 4:
			testCardName = "copper";
			testCardValue =  0;
			break;
		case 5:
			testCardName = "silver";
			testCardValue =  3;
			break;
		case 6:
			testCardName = "gold";
			testCardValue =  6;
			break;
		case 7:
			testCardName = "adventurer";
			testCardValue =  6;
			break;
		case 8:
			testCardName = "council_room";
			testCardValue =  5;
			break;
		case 9:
			testCardName = "feast";
			testCardValue =  4;
			
		case 10:
			testCardName = "gardens";
			testCardValue =  4;
			break;
		case 11:
			testCardName = "mine";
			testCardValue =  5;
			break;
		case 12:
			testCardName = "remodel";
			testCardValue =  4;
			break;
		case 13:
			testCardName = "smithy";
			testCardValue =  4;
			break;
		case 14:
			testCardName = "village";
			testCardValue =  3;
			break;
		case 15:
			testCardName = "baron";
			testCardValue =  4;
			break;
		case 16:
			testCardName = "great_hall";
			testCardValue =  3;
			break;
		case 17:
			testCardName = "minion";
			testCardValue =  5;
			break;
		case 18:
			testCardName = "steward";
			testCardValue =  3;
			break;
		case 19:
			testCardName = "tribute";
			testCardValue =  5;
			break;
			
		case 20:
			testCardName = "ambassador";
			testCardValue =  3;
			break;
		case 21:
			testCardName = "cutpurse";
			testCardValue =  4;
			break;
		case 22:
			testCardName = "embargo";
			testCardValue =  2;
			break;
		case 23:
			testCardName = "outpost";
			testCardValue =  5;
			break;
		case 24:
			testCardName = "salvager";
			testCardValue =  4;
			break;
		case 25:
			testCardName = "sea_hag";
			testCardValue =  4;
			break;
		case 26:
			testCardName = "treasure_map";
			testCardValue =  4;
			break;
		
    }	

	printf("Card Number : %d \tCard Name : %s \n", cardNumber, testCardName);
	printf("Card Cost : %d \t", testCardValue);
	// check values
	if (testCardValue == getCost(cardNumber))
		printf("checked \n");
	else
		printf("error: Wrong Cost\n");
		
}

void cardCostTest()
{
	printf("Testing for 27 card cost values\n");
	printf("-------------------------------\n");

	int index;
	for (index = 0; index < 27; index++)
		testCardCost(index);
}

int main()
{
	cardCostTest();
	return 0;
}
