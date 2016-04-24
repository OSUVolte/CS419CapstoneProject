/********************************
** filename:unittest2.c
** author: Candis Pike
** date: April 16, 2016
** description: unit test of gainCard()
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
	int MAXPLAY = 2;
	pre.whoseTurn = 0;
	int player=0;
	int card=0;
	int MAXCARD = 27;
	int MAXFLAG = 3;
	int flag = 0;
	int bugFlag =0;
	
	//set-up initial game board
	int k[10]= {adventurer, smithy, village, cutpurse, feast, minion, remodel, mine, gardens, sea_hag};
	
	//initializes 2 players, k for the kingdom, randomseed , and game state
	initializeGame(MAXPLAY, k, 42,&pre);
	
	//create a pre hand
	pre.hand[0][0] = silver; 
	pre.hand[0][1] = gold; 
	pre.hand[0][2] = village; 
	pre.hand[0][3] = feast; 
	pre.hand[0][4] = smithy; 
	
	pre.hand[0][0] = silver; 
	pre.hand[0][1] = gold; 
	pre.hand[0][2] = village; 
	pre.hand[0][3] = feast; 
	pre.hand[0][4] = minion; 

	//copy pre into post use post to run function
	memcpy(&post,&pre,sizeof(struct gameState));
	
	printf("----------------Testing gainCard()---------------------------\n");
	//use cards that are not in game
	
	//get vaild card - add to discard check that supply of that card is decreased
	
	//get valid card - add to deck check that supply of the card is decreased

	//get valid card - add to hand check that supply of the card is decreased
	
	//check that other players deck, hand, and discard are the same 
	
		for (player=0; player < MAXPLAY; player++){
		printf("Testing for player %d\n", (player+1));
		for (card=0; card < MAXCARD; card++){
			printf("Testing Card %d\n", card);
			for (flag= 0; flag < MAXFLAG; flag++){
				//check for supply card in use
				int use = gainCard(card, &post, flag, player);
				printf("Confirm if card is available or not 0 is available -1 if not return value: %d", use);
				if (use < 0){
					printf("Card is not in use or has 0 in the pile. Trying next card. \n");
					break;
				}
			
				if (flag==0){
					printf("Confirm that the card has been discarded.\n");
					printf("Top of discard deck is : %d\n", post.discard[player][post.discardCount[player]-1]);	
					if (card == post.discard[player][post.discardCount[player]-1])
						printf("PASSED\n");
					else{
						bugFlag++;
						printf("FAILED: BUG# %d\n", bugFlag);
					}			
					
					printf("Confirm that supply count of card %d has changed\n", card);
					printf("pre count: %d    post count: %d\n", supplyCount(card, &pre), supplyCount(card, &post));
					if(supplyCount(card, &pre) > supplyCount(card, &post))
						printf("PASSED\n");
					else{
						bugFlag++;
						printf("FAILED: BUG# %d\n", bugFlag);
					}			
					
				}

				if (flag==1){
					printf("Confirm that the card has been discarded.\n");
					printf("Top of discard deck is : %d", post.discard[player][post.discardCount[player]-1]);	
					if (card == post.discard[player][post.discardCount[player]-1])
						printf("PASSED\n");
					else{
						bugFlag++;
						printf("FAILED: BUG# %d\n", bugFlag);
					}			
					printf("Confirm that supply count of card %d has changed\n", card);
					printf("pre count: %d    post count: %d\n", supplyCount(card, &pre), supplyCount(card, &post));
					if(supplyCount(card, &pre)> supplyCount(card, &post))
						printf("PASSED\n");
					else{
						bugFlag++;
						printf("FAILED: BUG# %d\n", bugFlag);
					}				
					
				}

				if (flag==2){
					printf("Confirm that the card has been discarded.\n");
					printf("Top of discard deck is : %d\n", post.discard[player][post.discardCount[player]-1]);	
					if(card == post.discard[player][post.discardCount[player]-1])
						printf("PASSED\n");
					else{
						bugFlag++;
						printf("FAILED: BUG# %d\n", bugFlag);
					}			
					
					printf("Confirm that supply count of card %d has changed\n", card);
					printf("pre count: %d    post count: %d\n", supplyCount(card, &pre), supplyCount(card, &post));
					if(supplyCount(card, &pre)> supplyCount(card, &post))
						printf("PASSED\n");
					else{
						bugFlag++;
						printf("FAILED: BUG# %d\n", bugFlag);
					}			
				}
				
			}//end flag for
		}//end card for
	}//end outer for
	
	//deplete a kingdom card stack and try drawing from it using cutpurse. not in either initial hand
	memset(&pre, 0, sizeof(struct gameState));
	memset(&post, 0, sizeof(struct gameState));
	initializeGame(MAXPLAY, k, 42,&pre);
	memcpy(&post,&pre,sizeof(struct gameState));

	int inCount = supplyCount(cutpurse, &pre);
	printf("Depleting kingdom card cutpurse. Initial count %d\n",inCount);
	if(supplyCount(cutpurse, &pre)== supplyCount(cutpurse, &post))
		printf("PASSED\n");
	else{
		bugFlag++;
		printf("FAILED: BUG# %d\n", bugFlag);
	}				
	int deplete =0;

	for(deplete=1; deplete <= inCount+1; deplete++){
		int use = gainCard(cutpurse, &post, 2, 0);
		if(use<0){
			printf("Card has 0 in the pile. \n");
					break;
		}
		
		printf("Current cutpurse card count: %d\n", supplyCount(cutpurse, &post));
		int hCount = post.handCount[0];
		printf("Confirm that top hand card is cutpurse and hand count is +1. top: %d  count: %d\n", post.hand[0][hCount-1], hCount);
		if(post.hand[0][hCount-1] == cutpurse)
			printf("PASSED\n");
		else{
			bugFlag++;
			printf("FAILED: BUG# %d\n", bugFlag);
		}			
		
		printf("Confirm other players discard/deck are unchanged\n");
		if(post.deck[1][post.deckCount[1]] != pre.deck[1][pre.deckCount[1]]){
			bugFlag++;
			printf("FAILED: BUG# %d\n", bugFlag);
		}
		if(post.deckCount[1] != pre.deckCount[1]){
			bugFlag++;
			printf("FAILED: BUG# %d\n", bugFlag);
		}
		if(post.discard[1][post.discardCount[1]] != pre.discard[1][pre.discardCount[1]]){
			bugFlag++;
			printf("FAILED: BUG# %d\n", bugFlag);
		}
		if(post.discardCount[1] != pre.discardCount[1]){
			bugFlag++;
			printf("FAILED: BUG# %d\n", bugFlag);
		}
		printf("Other player discard and deck piles test complete\n");
	}//end deplete for
	
	printf("Total Bugs: %d\n", bugFlag);
	printf("----------------END Testing gainCard()---------------------------\n");

	return 0;
}
