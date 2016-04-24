/********************************
** filename:cardtest3.c
** author: Candis Pike
** date: April 16, 2016
** description: unit test of cutpurse card
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
	int bugFlag = 0;

	//set-up initial game board
	int k[10]= {adventurer, smithy, village, cutpurse, feast, minion, remodel, mine, gardens, sea_hag};
	
	//initializes 2 players, k for the kingdom, randomseed , and game state
	initializeGame(2, k, 42,&pre);
	
	
	//make sure smithy is in currentplayer hand
	pre.hand[currentPlayer][0] = silver; 
	pre.hand[currentPlayer][1] = silver; 
	pre.hand[currentPlayer][2] = copper; 
	pre.hand[currentPlayer][3] = gold; 
	pre.hand[currentPlayer][4] = cutpurse; 
	pre.handCount[currentPlayer]=5;
	
	pre.handCount[otherPlayer]=5;
	pre.hand[otherPlayer][0] = silver; 
	pre.hand[otherPlayer][1] = copper; 
	pre.hand[otherPlayer][2] = copper; 
	pre.hand[otherPlayer][3] = copper; 
	pre.hand[otherPlayer][4] = minion; 

	//copy pre into post use post to run function
	memcpy(&post,&pre,sizeof(struct gameState));
	
	//set current and other player
	currentPlayer = post.whoseTurn;
	otherPlayer = currentPlayer+1;
	
	printf("------------------START Test Card Cutpurse-----------------------\n");
	//call village card
	cardEffect(cutpurse, choice1, choice2, choice3, &post, handpos, &bonus);
	
	//assert current player receives 2 bonus coins, other player unchanged
	updateCoins(currentPlayer, &pre, 0);
	int preCurrentCoin = pre.coins;
	updateCoins(currentPlayer, &post, 2);
	int postCurrentCoin = post.coins;
	printf("Confirm current player has 2 additional coins. post: %d and pre: %d \n", postCurrentCoin, preCurrentCoin);
	if(postCurrentCoin == (preCurrentCoin +2))
		printf("PASSED\n");
	else{
		bugFlag++;
		printf("FAILED: BUG# %d\n", bugFlag);
	}
	
	//assert currentplayer has only 1ess card
	printf("Confirm current player hand count is 1 less pre:  %d   post:  %d\n", pre.handCount[currentPlayer],  post.handCount[currentPlayer]);
	if (post.handCount[currentPlayer] == (pre.handCount[currentPlayer]-1))	
		printf("PASSED\n");
	else{
		bugFlag++;
		printf("FAILED: BUG #%d\n", bugFlag);
	} 
	
	//assert that other player has all copper coin cards in hand removed
	printf("Confim other player has no copper coin cards in hand");
	for(i=0; i< post.handCount[otherPlayer]; i++){
		printf("Hand card # %d is %d \n", i, post.hand[otherPlayer][i]);
		if(post.hand[otherPlayer][i] != copper)
			printf("PASSED\n");
		else{
			bugFlag++;
			printf("FAILED: BUG# %d\n", bugFlag);
		}			
	}//end for
		
	//assert that removed copper coins are in played pile
	printf("Confim copper cards are discarded into played pile.\n");
	for(i=pre.playedCardCount; i < (post.playedCardCount-1); i++){
		printf("Played card # %d is %d. \n", i, post.playedCards[i]);
		if(post.playedCards[i] == copper)
			printf("PASSED\n");
		else{
			bugFlag++;
			printf("FAILED: BUG# %d\n", bugFlag);
		}
	}//end for
		
	//assert other player hand count is less if copper cards were removed
	printf("Confirm that coin count decrease for other player.\n");
	int flag = 0;
	int n;
	
	for (n=0; n < post.handCount[otherPlayer]; n++){
		if (pre.hand[otherPlayer][n] == copper){
			flag = 1;
			break;
		}	
	}//end for
	if (flag == 1){
		int preCopper = 0;
		int k=0;
		for (k=0; k < pre.handCount[otherPlayer]; k++){
			if ( pre.hand[otherPlayer][k] == copper)
				preCopper++;
		}
		
		updateCoins(otherPlayer, &pre, 0);
		int preOtherCoin = pre.coins;
		updateCoins(otherPlayer, &post, 0);
		int postOtherCoin = post.coins;
		printf("Confirm other player coin count decreases with copper coin removal. pre coins: %d   copper coins: %d  post coin:%d \n", preOtherCoin, preCopper, postOtherCoin);
		if((postOtherCoin + preCopper) == preOtherCoin)
			printf("PASSED\n");
		else{
			bugFlag++;
			printf("FAILED: BUG# %d\n", bugFlag);
		}
	}//end if
	

	//assert cutpurse was discarded	
	printf("Cutpurse should be top of played cards if discarded  post:%d \n", post.playedCards[post.playedCardCount-1]);
	
	if((post.playedCardCount > pre.playedCardCount) && (post.playedCards[post.playedCardCount-1]== cutpurse))
		printf("PASSED\n");
	else{
		bugFlag++;
		printf("FAILED: BUG# %d\n", bugFlag);
	}
		
	//assert that other player deck didn't change
	printf("Confirm other players deck pile did not change\n");
	if(post.deck[otherPlayer][post.deckCount[otherPlayer]]!= pre.deck[otherPlayer][pre.deckCount[otherPlayer]]){
		bugFlag++;
		printf("FAILED top of deck: BUG# %d\n", bugFlag);
	}
	if(post.deckCount[otherPlayer] != pre.deckCount[otherPlayer]){
		bugFlag++;
		printf("FAILED deck count: BUG# %d\n", bugFlag);
	}
	printf("Other player deck pile check complete.\n");
	
	//assert that remaing kingdom, coin, and provience cards are untouched
	printf("Testing remaining kingdom, coin, and provience card counts remained unchanged after smithy card play.\n");
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

	printf("------------------END Test Card Cutpurse-----------------------\n");

	return 0;
}
