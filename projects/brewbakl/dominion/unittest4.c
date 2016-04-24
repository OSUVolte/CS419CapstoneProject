/********************************
Author: Luke Brewbaker
Date: 4/18/16
Modified:4/21/16
File: unittest4.c

Overview: Test  getCost function.  Test each card number to make sure the cost is correct

*******************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>

int main()
{
	//create game state
	int errors = 0;
	struct gameState *game = newGame();
	int kingdomCards[10] = {adventurer, council_room, mine, remodel, village, smithy, ambassador, embargo, sea_hag, mine};
	initializeGame(2, kingdomCards, 2, game);
	
	printf("\n\n --- getCost() Test Start -- \n\n");
	
	if(getCost(0) == 0){
		printf("PASS: Curse cost correct.\n");
	}
	else{
		errors++;
		printf("FAIL: Curse cost incorrect");
	}
	
	//test Estate
	if(getCost(1) == 2){
				printf("PASS: Curse cost correct.\n");
	}
	else{
		errors++;
		printf("FAIL: Curse cost incorrect");
	}
	
	//test duchy
	if(getCost(2) == 5){
		printf("PASS: duchy cost correct.\n");
	}
	else{
		errors++;
		printf("FAIL: duchy cost incorrect");
	}
	//test province
	if(getCost(3) == 8){
		printf("PASS: Province cost correct.\n");
	}
	else{
		errors++;
		printf("FAIL: Province cost incorrect");
	}
	
	//test copper
	if(getCost(4) == 0){
		printf("PASS: copper cost correct.\n");
	}
	else{
		errors++;
		printf("FAIL: copper cost incorrect");
	}
	
	//test silver
	if(getCost(5) == 3){
		printf("PASS: silver cost correct.\n");
	}
	else{
		errors++;
		printf("FAIL: silver cost incorrect");
	}
	
	//test gold
	if(getCost(6) == 6){
		printf("PASS: gold cost correct.\n");
	}
	else{
		errors++;
		printf("FAIL: gold cost incorrect");
	}
	
	//test adventurer
	if(getCost(7) == 6){
		printf("PASS: adventurer cost correct.\n");
	}
	else{
		errors++;
		printf("FAIL: adventurer cost incorrect");
	}
	
	//test council_room
	if(getCost(8) == 5){
		printf("PASS: council_room cost correct.\n");
	}
	else{
		errors++;
		printf("FAIL: council_room cost incorrect");
	}
	
	//test feast
	if(getCost(9) == 4){
		printf("PASS: feast cost correct.\n");
	}
	else{
		errors++;
		printf("FAIL: feast cost incorrect");
	}
	
	//test gardens
	if(getCost(10) == 4){
		printf("PASS: gardens cost correct.\n");
	}
	else{
		errors++;
		printf("FAIL: gardens cost incorrect");
	}
	
	//test mine
	if(getCost(11) == 5){
		printf("PASS: mine cost correct.\n");
	}
	else{
		errors++;
		printf("FAIL: mine cost incorrect");
	}
	
	//test remodel
	if(getCost(12) == 4){
		printf("PASS: remodle cost correct.\n");
	}
	else{
		errors++;
		printf("FAIL: remodel cost incorrect");
	}
	
	//test smithy
	if(getCost(13) == 4){
		printf("PASS: smithy cost correct.\n");
	}
	else{
		errors++;
		printf("FAIL: smithy cost incorrect");
	}
	
	//test village
	if(getCost(14) == 3){
		printf("PASS: village cost correct.\n");
	}
	else{
		errors++;
		printf("FAIL: village cost incorrect");
	}
	
	//test baron
	if(getCost(15) == 4){
		printf("PASS: baron cost correct.\n");
	}
	else{
		errors++;
		printf("FAIL: baron cost incorrect");
	}
	
	//test great_hall
	if(getCost(16) == 3){
		printf("PASS: great_hall cost correct.\n");
	}
	else{
		errors++;
		printf("FAIL: great_hall cost incorrect");
	}
	
	//test minion
	if(getCost(17) == 5){
		printf("PASS: minion cost correct.\n");
	}
	else{
		errors++;
		printf("FAIL: minion cost incorrect");
	}
	
	//test steward
	if(getCost(18) == 3){
		printf("PASS: Steward cost correct.\n");
	}
	else{
		errors++;
		printf("FAIL: steward cost incorrect");
	}
	
	//test tribute
	if(getCost(19) == 5){
		printf("PASS: tribute cost correct.\n");
	}
	else{
		errors++;
		printf("FAIL: tribute cost incorrect");
	}
	
	//test ambassador
	if(getCost(20) == 3){
		printf("PASS: ambassador cost correct.\n");
	}
	else{
		errors++;
		printf("FAIL: ambassador cost incorrect");
	}
	
	//test cutpurse
	if(getCost(21) == 4){
		printf("PASS: curse cost correct.\n");
	}
	else{
		errors++;
		printf("FAIL: curse cost incorrect");
	}
	
	//test embargo
	if(getCost(22) == 2){
		printf("PASS: embargo cost correct.\n");
	}
	else{
		errors++;
		printf("FAIL: embargo cost incorrect");
	}
	
	//test outpost
	if(getCost(23) == 5){
		printf("PASS: outpost cost correct.\n");
	}
	else{
		errors++;
		printf("FAIL: outpost cost incorrect");
	}
	
	//test salvager
	if(getCost(24) == 4){
		printf("PASS: salvager cost correct.\n");
	}
	else{
		errors++;
		printf("FAIL: salvager cost incorrect");
	}
	
	//test sea_hag
	if(getCost(25) == 4){
		printf("PASS: sea_hag cost correct.\n");
	}
	else{
		errors++;
		printf("FAIL: sea_hag cost incorrect");
	}
	
	//test treasure_map
	if(getCost(26) == 4){
		printf("PASS: Treasure_map cost correct.\n");
	}
	else{
		errors++;
		printf("FAIL: Treasure_map cost incorrect");
	}

	
	if (errors > 0){
		printf("There were %d errors in total\n", errors);
	}
	
	else {
		printf("\nAll Tests Successful.");
	}
	
		printf("\n\n --- getCost() Test End --- \n\n");
	return 0;
}