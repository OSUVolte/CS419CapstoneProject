/********************************
** filename:cardtest2.c
** author: Candis Pike
** date: April 16, 2016
** description: unit test of adventure card
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
	int i =0;
	int bugFlag=0;
	
	//set-up initial game board
	int k[10]= {adventurer, smithy, village, cutpurse, feast, minion, remodel, mine, gardens, sea_hag};
	
	//initializes 2 players, k for the kingdom, randomseed , and game state
	initializeGame(2, k, 42,&pre);
	
	
	//make sure smithy is in currentplayer hand
	pre.hand[currentPlayer][0] = silver; 
	pre.hand[currentPlayer][1] = gold; 
	pre.hand[currentPlayer][2] = village; 
	pre.hand[currentPlayer][3] = feast; 
	pre.hand[currentPlayer][4] = adventurer; 

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
	
	printf("------------------START Test Card Adventurer-----------------------\n");
	//call adventurer function
	cardEffect(adventurer, choice1, choice2, choice3, &post, handpos, &bonus);
	
	//current player should have 2 more cards in the hand and that they are gold,copper,silver
	printf("Confirm current player has 2 new cards in the hand post (should show 1 difference beacause of discard): %d and pre: %d \n", post.handCount[currentPlayer],pre.handCount[currentPlayer]);
	if (post.handCount[currentPlayer] == (pre.handCount[currentPlayer]+1))       //when adventurer is discarded will only show 1 card has been added
		printf("PASSED\n");
	else{
		bugFlag++;
		printf("FAILED: BUG# %d\n", bugFlag);
	}
	
	printf("Confirm that new cards in hand are coin cards.\n");
	for (i=5; i < post.handCount[currentPlayer]; i++){
		printf("hand position %d with card %d \n", i, post.hand[currentPlayer][i]);
		if(post.hand[currentPlayer][i]==gold || post.hand[currentPlayer][i]==silver || post.hand[currentPlayer][i] == copper)
			printf("PASSED\n");
		else{
			bugFlag++;
			printf("FAILED: BUG# %d\n", bugFlag);
		}
	}//end for loop
	
	//assert that cards came from the current players deck only
	printf("Confirm current player post deck count %d and pre deck count %d\n", post.deckCount[currentPlayer], pre.deckCount[currentPlayer]);
	printf("Confirm other playerhand count %d and expected hand count %d\n", post.deckCount[otherPlayer], pre.deckCount[otherPlayer]);
	if((post.deckCount[currentPlayer] < pre.deckCount[currentPlayer]) && (post.deckCount[otherPlayer] == pre.deckCount[otherPlayer]))
		printf("PASSED\n");
	else{
		bugFlag++;
		printf("FAILED: BUG# %d\n", bugFlag);
	}
		
	//assert that no coin cards were disarded
	printf("Confrim no coin cards were discarded during adventurer card play\n");
	for(i= pre.playedCardCount; i < post.playedCardCount; i++){
		printf("Played card #%d is %d\n", i, post.playedCards[i]);
		if(post.playedCards[i] != gold || post.playedCards[i] != silver || post.playedCards[i] != copper)
			printf("PASSED\n");
		else{
			bugFlag++;
			printf("FAILED: BUG# %d\n", bugFlag);
		}	
	}//end for	
	
	//asert that coin count changes
	printf("Confirm that coin count updates for current player and stays the same for other player.\n");
	updateCoins(currentPlayer, &pre, 0);
	int preCurrentCoin = pre.coins;
	updateCoins(currentPlayer, &post, 0);
	int postCurrentCoin = post.coins;
	updateCoins(otherPlayer, &pre, 0);
	int preOtherCoin = pre.coins;
	updateCoins(otherPlayer, &post, 0);
	int postOtherCoin = post.coins;
	printf("Coin count for current player - post %d and pre %d \n", postCurrentCoin, preCurrentCoin);
	printf("Coin count for other player - post %d and pre %d \n", postOtherCoin, preOtherCoin);
	if((postCurrentCoin > preCurrentCoin) && (postOtherCoin==preOtherCoin))
		printf("PASSED\n");
	else{
		bugFlag++;
		printf("FAILED: BUG# %d\n", bugFlag);
	}
	
	//assert that adventurer was discarded and no longer in played hand 
	printf("Smithy discarded should increase the played card count by 1  post: %d and pre: %d\n", post.playedCardCount, pre.playedCardCount);
	printf("Top played card should be adventurer post:%d \n", post.playedCards[post.playedCardCount-1]);
	if((post.playedCardCount > pre.playedCardCount) && (post.playedCards[post.playedCardCount-1]== adventurer))
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

	printf("------------------END Test Card Adventurer-----------------------\n");

	return 0;
}
