/*
	Rosa Tung
	CS362
	(20 points) Write unit tests for four functions (not card implementations or cardEffect) in dominion.c. 
	Check these tests in as unittest1.c,unittest2.c, unittest3.c, and unittest4.c. 
	(for example, you can create a test for updateCoins() method)
	
	Testing:
		int getCost(int cardNumber);
*/

#include "dominion.h" 

#include <stdio.h> //printf scanf

int main(){
	//check for cost of each card
	const char* cardNames[] = {"curse", "estate", "duchy", "province", "copper", "silver", "gold", "adventurer", "council_room", "feast", 
	"gardens", "mine", "remodel", "smithy", "village", "baron", "great_hall", "minion", "steward", "tribute", "ambassador", "cutpurse", 
	"embargo", "outpost", "salvager", "sea_hag", "treasure_map"};
	int costs[27] = {0, 2, 5, 8, 0, 3, 6, 6, 5, 4, 4, 5, 4, 4, 3, 4, 3, 5, 3, 5, 3, 4, 2, 5, 4, 4, 4};
	int numCards;
	
	printf("---Testing getCost function START---\n\n");
	//go through and check all the card values 
	for(numCards = 0; numCards<27; numCards++){
		printf("Testing %s cost (should be %d)\n", cardNames[numCards], costs[numCards]);
		if(getCost(numCards) == costs[numCards]){
			printf("	PASS\n");
		} else {
			printf("	FAIL\n");
			printf("		Cost: %d\n", getCost(numCards));
		}		
	}
	
	printf("\n---Testing getCost function COMPLETE---\n\n\n\n");
	return 0;
}