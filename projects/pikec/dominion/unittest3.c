/********************************
** filename:unittest3.c
** author: Candis Pike
** date: April 16, 2016
** description: unit test of drawCard()
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
	pre.whoseTurn = 0;
	int currentPlayer = pre.whoseTurn;
	int otherPlayer = currentPlayer +1;
	int bugFlag =0;
	
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

	//test with no discard pile to ensure shuffle is triggered deck count pre = 0, post > 0   discard pre > 0 post == 0
	//non shuffle post hand count +1 of pre, deck count -1 of pre, top card of hand is draw card
	//both conditions other player unchanged
	
	printf("----------------START Testing drawCard()---------------------------\n");
	printf("Testing that discard becomes deck when deck is at 0\n");
	pre.deckCount[currentPlayer]=0;
	pre.discardCount[currentPlayer]= 5;
	pre.discard[currentPlayer][0]= adventurer;
	pre.discard[currentPlayer][2]= remodel;
	pre.discard[currentPlayer][3]= copper;
	pre.discard[currentPlayer][4]= mine;
	pre.discard[currentPlayer][5]= gardens;
	
	//copy pre into post use post to run function
	memcpy(&post,&pre,sizeof(struct gameState));
	
	printf("Calling drawCard(). If return is not 0 then deck was empty and not shuffled.\n");
	int complete = drawCard(currentPlayer, &post);
	if (complete == 0)
		printf("PASSED\n");
	else{
		bugFlag++;
		printf("FAILED: BUG# %d\n", bugFlag);
	}
	
	printf("Confirm deck count is now 4 pre: %d and post: %d \n", pre.deckCount[currentPlayer], post.deckCount[currentPlayer]);
	printf("Confirm discard count is now 0 pre: %d and post: %d \n", pre.deckCount[currentPlayer], post.deckCount[currentPlayer]);
	if((pre.deckCount[currentPlayer] < post.deckCount[currentPlayer])&& (pre.discardCount[currentPlayer] > post.discardCount[currentPlayer]))
		printf("PASSED\n");
	else{
		bugFlag++;
		printf("FAILED: BUG# %d\n", bugFlag);
	}
	
	printf("Confirm that hand count of current player is increased by 1. pre: %d    post: %d\n",pre.handCount[currentPlayer], post.handCount[currentPlayer]);
	if (pre.handCount[currentPlayer] < post.handCount[currentPlayer])	
		printf("PASSED\n");
	else{
		bugFlag++;
		printf("FAILED: BUG# %d\n", bugFlag);
	}
	
	printf("Testing with no shuffle.\n");
	memset(&pre, 0, sizeof(struct gameState));
	memset(&post, 0, sizeof(struct gameState));
	initializeGame(2, k, 42,&pre);
	memcpy(&post,&pre,sizeof(struct gameState));

	printf("Calling drawCard(). If return is not 0 then deck was empty and not shuffled.\n");
	complete = drawCard(currentPlayer, &post);
	if (complete == 0)
		printf("PASSED\n");
	else{
		bugFlag++;
		printf("FAILED: BUG# %d\n", bugFlag);
	}
	
	printf("Confirm deck count is now 1 less pre: %d and post: %d \n", pre.deckCount[currentPlayer], post.deckCount[currentPlayer]);
	printf("Confirm that hand count of current player is increased by 1. pre: %d    post: %d\n",pre.handCount[currentPlayer], post.handCount[currentPlayer]);
	if((pre.deckCount[currentPlayer] =  post.deckCount[currentPlayer]+1)&& (pre.handCount[currentPlayer] = post.handCount[currentPlayer]+1))
		printf("PASSED\n");
	else{
		bugFlag++;
		printf("FAILED: BUG# %d\n", bugFlag);
	}
	
	printf("Confirm that top card of hand was from the top of deck  pre: %d     post: %d\n", pre.deck[currentPlayer][pre.deckCount[currentPlayer]-1],post.hand[currentPlayer][post.handCount[currentPlayer]-1] );
	if(pre.deck[currentPlayer][pre.deckCount[currentPlayer]-1] == post.hand[currentPlayer][post.handCount[currentPlayer]-1]) 
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
	printf("Testing remaining kingdom, coin, and provience card counts remained unchanged.\n");
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
	printf("----------------END Testing drawCard()---------------------------\n");

	return 0;
}
