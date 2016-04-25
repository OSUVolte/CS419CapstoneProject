/********************************
** filename:cardtest1.c
** author: Candis Pike
** date: April 16, 2016
** description: unit test of smithy card
***********************************/
#include "dominion_helpers.h"
#include "dominion.h"
#include "rngs.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main (){
	struct gameState pre, post;
	int handpos = 4;
	int choice1=0;
	int choice2=0;
	int choice3=0; 
	int bonus = 0;	
	pre.whoseTurn = 0;
	int currentPlayer = pre.whoseTurn;
	int otherPlayer = currentPlayer +1;
	int bugFlag = 0;
	
	//set-up initial game board
	int k[10]= {adventurer, smithy, village, cutpurse, feast, minion, remodel, mine, gardens, sea_hag};
	
	//initializes 2 players, k for the kingdom, randomseed , and game state
	initializeGame(2, k, 42,&pre);
	
	
	//make sure smithy is in currentplayer hand
	pre.hand[currentPlayer][0] = silver; 
	pre.hand[currentPlayer][1] = gold; 
	pre.hand[currentPlayer][2] = village; 
	pre.hand[currentPlayer][3] = feast; 
	pre.hand[currentPlayer][4] = smithy; 
	
	pre.hand[otherPlayer][0] = silver; 
	pre.hand[otherPlayer][1] = gold; 
	pre.hand[otherPlayer][2] = village; 
	pre.hand[otherPlayer][3] = feast; 
	pre.hand[otherPlayer][4] = minion; 

	//copy pre into post use post to run function
	memcpy(&post,&pre,sizeof(struct gameState));
	
	//set current and other player
	currentPlayer = post.whoseTurn;
	otherPlayer = currentPlayer+1;
	
	printf("------------------START Card Smithy-----------------------\n");
	//call smithy function
	cardEffect(smithy, choice1, choice2, choice3, &post, handpos, &bonus);
	
	//assert that current player got 3 new cards
	printf("Confirm 3 cards: post deck should be 3 less then pre. post: %d and pre: %d\n", (post.deckCount[currentPlayer]), (pre.deckCount[currentPlayer]));
	if(post.deck[currentPlayer][post.deckCount[currentPlayer]] == (pre.deck[currentPlayer][pre.deckCount[currentPlayer]]-3))
		printf("PASSED\n");
	else{
		bugFlag++;
		printf("FAILED: BUG# %d\n", bugFlag);
	}
	
	//assert that  cards came from the current players deck only
	printf("Confirm current player post deck count %d and pre deck count %d\n", post.deckCount[currentPlayer], pre.deckCount[currentPlayer]);
	printf("Confirm other playerhand count %d and expected hand count %d\n", post.deckCount[otherPlayer], pre.deckCount[otherPlayer]);
	if((post.deckCount[currentPlayer] < pre.deckCount[currentPlayer]) && (post.deckCount[otherPlayer] == pre.deckCount[otherPlayer]))
		printf("PASSED\n");
	else{
		bugFlag++;
		printf("FAILED: BUG# %d\n", bugFlag);
	}
	
	//assert that smithy was discarded and no longer in played hand 
	printf("Smithy discarded should increase the played card count by 1  post: %d and pre: %d\n", post.playedCardCount, pre.playedCardCount);
	printf("Top played card should be smithy post:%d \n", post.playedCards[post.playedCardCount-1]);
	if((post.playedCardCount > pre.playedCardCount) && (post.playedCards[post.playedCardCount-1]== smithy))
		printf("PASSED\n");
	else{
		bugFlag++;
		printf("FAILED: BUG# %d\n", bugFlag);
	}
	
	//assert that other player hand, discard, and deck didn't change
	printf("Confirm other players hand, discard and deck piles did not change\n");
	if(post.hand[otherPlayer][post.handCount[otherPlayer]] != pre.hand[otherPlayer][pre.handCount[otherPlayer]]){
		bugFlag++;
		printf("FAILED: BUG# %d\n", bugFlag);
	}
	if(post.handCount[otherPlayer] != pre.handCount[otherPlayer]){
		bugFlag++;
		printf("FAILED: BUG# %d\n", bugFlag);
	}
	if(post.deck[otherPlayer][post.deckCount[otherPlayer]] != pre.deck[otherPlayer][pre.deckCount[otherPlayer]]){
		bugFlag++;
		printf("FAILED: BUG# %d\n", bugFlag);
	}
	if(post.deckCount[otherPlayer] != pre.deckCount[otherPlayer]){
		bugFlag++;
		printf("FAILED: BUG# %d\n", bugFlag);
	}
	if(post.discard[otherPlayer][post.discardCount[otherPlayer]] != pre.discard[otherPlayer][pre.discardCount[otherPlayer]]){
		bugFlag++;
		printf("FAILED: BUG# %d\n", bugFlag);
	}
	if(post.discardCount[otherPlayer] != pre.discardCount[otherPlayer])	{
		bugFlag++;
		printf("FAILED: BUG# %d\n", bugFlag);
	}
	printf("Stack counts test finished.\n");
	
			
	//assert that remaing kingdom, coin, and provience cards are untouched
	printf("Testing remaining kingdom, coin, and provience card counts remained unchanged after smithy card play./n");
	if (supplyCount(smithy,&post) != supplyCount(smithy,&pre)){
		bugFlag++;
		printf("FAILED: BUG# %d\n", bugFlag);
	}
	if(supplyCount(adventurer,&post) != supplyCount(adventurer,&pre)){
		bugFlag++;
		printf("FAILED: BUG# %d\n", bugFlag);
	}
	if(supplyCount(village,&post) != supplyCount(village,&pre)){
		bugFlag++;
		printf("FAILED: BUG# %d\n", bugFlag);
	}
	if(supplyCount(cutpurse,&post) != supplyCount(cutpurse,&pre)){
		bugFlag++;
		printf("FAILED: BUG# %d\n", bugFlag);
	}
	if(supplyCount(feast,&post) != supplyCount(feast,&pre)){
		bugFlag++;
		printf("FAILED: BUG# %d\n", bugFlag);
	}
	if(supplyCount(minion,&post) != supplyCount(minion,&pre)){
		bugFlag++;
		printf("FAILED: BUG# %d\n", bugFlag);
	}
	if(supplyCount(remodel,&post) != supplyCount(remodel,&pre))	{
		bugFlag++;
		printf("FAILED: BUG# %d\n", bugFlag);
	}
	if(supplyCount(mine,&post) != supplyCount(mine,&pre)){	
		bugFlag++;
		printf("FAILED: BUG# %d\n", bugFlag);
	}
	if(supplyCount(gardens,&post) != supplyCount(gardens,&pre))	{
		bugFlag++;
		printf("FAILED: BUG# %d\n", bugFlag);
	}
	if(supplyCount(sea_hag,&post) != supplyCount(sea_hag,&pre))	{
		bugFlag++;
		printf("FAILED: BUG# %d\n", bugFlag);
	}
	
	if(supplyCount(estate,&post) != supplyCount(estate,&pre)){
		bugFlag++;
		printf("FAILED: BUG# %d\n", bugFlag);
	}
	if(supplyCount(duchy,&post) != supplyCount(duchy,&pre))	{
		bugFlag++;
		printf("FAILED: BUG# %d\n", bugFlag);
	}
	if(supplyCount(province,&post) != supplyCount(province,&pre)){
		bugFlag++;
		printf("FAILED: BUG# %d\n", bugFlag);
	}
	
	if(supplyCount(gold,&post) != supplyCount(gold,&pre)){
		bugFlag++;
		printf("FAILED: BUG# %d\n", bugFlag);
	}
	if(supplyCount(silver,&post) != supplyCount(silver,&pre)){
		bugFlag++;
		printf("FAILED: BUG# %d\n", bugFlag);
	}
	if(supplyCount(copper,&post) != supplyCount(copper,&pre)){
		bugFlag++;
		printf("FAILED: BUG# %d\n", bugFlag);
	}
	printf("Card counts test finished.\n");
	
	printf("Total Bugs: %d\n", bugFlag);
	printf("-------------------END Test Card Smithy-------------------------\n");
	
	return 0;
}
