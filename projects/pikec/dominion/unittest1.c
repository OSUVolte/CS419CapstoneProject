/********************************
** filename:unittest1.c
** author: Candis Pike
** date: April 16, 2016
** description: unit test of update coin function
***********************************/
#include "dominion_helpers.h"
#include "dominion.h"
#include "rngs.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#define NOISY_TEST 0

int main (){
	struct gameState pre;
	int NUMPLAYERS =2;
	pre.whoseTurn = 0;
	int currentPlayer = pre.whoseTurn;
	int otherPlayer = currentPlayer +1;
	int i=0;
	int j=0;
	int p=1;
	int MAXBONUS = 10;
	int MAXHAND = 5;
	int bugFlag=0;
		
	printf("----------------Testing updateCoins()---------------------------\n");
	
	//test with a regular hand
	printf("####Testing no coin cards - no bonus player 1#####\n");
	//set-up initial game board
	int k[10]= {adventurer, smithy, village, cutpurse, feast, minion, remodel, mine, gardens, sea_hag};
		
	//initializes 2 players, k for the kingdom, randomseed , and game state
	initializeGame(NUMPLAYERS, k, 42,&pre);
	
	//make sure no player has coin cards is in currentplayer hand
	pre.hand[currentPlayer][0] = remodel; 
	pre.hand[currentPlayer][1] = gardens; 
	pre.hand[currentPlayer][2] = village; 
	pre.hand[currentPlayer][3] = feast; 
	pre.hand[currentPlayer][4] = smithy; 
	
	updateCoins(currentPlayer, &pre, 0);
	printf("Coins with no coin cards or bonus in hand coins: %d\n ", pre.coins);
	if(pre.coins == 0)
		printf("PASSED\n");
	else{
		bugFlag++;
		printf("FAILED: BUG# %d\n", bugFlag);
	}			
	
	//test with no coins but a bonus
	printf("####Testing no coin cards and max bonus#####\n");
	updateCoins(currentPlayer, &pre, MAXBONUS);
	printf("Coins with no coin card in hand and maxbonus coins: %d\n", pre.coins);
	if(pre.coins == MAXBONUS)
		printf("PASSED\n");
	else{
		bugFlag++;
		printf("FAILED: BUG# %d\n", bugFlag);
	}			
	
	//make sure no player has coin cards is in currentplayer hand
	pre.hand[otherPlayer][0] = remodel; 
	pre.hand[otherPlayer][1] = gardens; 
	pre.hand[otherPlayer][2] = village; 
	pre.hand[otherPlayer][3] = feast; 
	pre.hand[otherPlayer][4] = smithy; 
	
	printf("####Testing no coin cards - no bonus player 2#####\n");
	updateCoins(otherPlayer, &pre, 0);
	printf("Coins count %d expected 0\n", pre.coins);
	if(pre.coins == 0)
		printf("PASSED\n");
	else{
		bugFlag++;
		printf("FAILED: BUG# %d\n", bugFlag);
	}			
	
	//test with no coins but a bonus
	printf("####Testing no coin cards and max bonus player 2#####\n");
	updateCoins(otherPlayer, &pre, MAXBONUS);
	printf("Coin count %d expected 10\n", pre.coins);
	if(pre.coins == MAXBONUS)
		printf("PASSED\n");
	else{
		bugFlag++;
		printf("FAILED: BUG# %d\n", bugFlag);
	}			
 
	//adapted from assignment example
    int coppers[MAXHAND];
    int silvers[MAXHAND];
    int golds[MAXHAND];
    for (i = 0; i < MAXHAND; i++)
    {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }

	printf("#####Testing coin cards with 1 to max hand and 0 to max bonus###### \n");
	for (p = 0; p <NUMPLAYERS; p++){
		printf("Testing coins for player %d\n", p+1);
		#if (NOISY_TEST == 1)
			for (i= 1; i<= MAXHAND; i++){
				for (j=0; j<=MAXBONUS; j++){
					pre.handCount[p]= i;
		#endif	
					printf("Testing copper cards in hand %d. with bonus %d \n", i, j);
					memcpy(pre.hand[p], coppers, sizeof(int)*i);
					updateCoins(p,&pre,j);
		#if(NOISY_TEST ==1)
					printf("Expected %d , Actual %d \n", (i*1+j), pre.coins);
					if(pre.coins == (i*1+j))
							printf("PASSED\n");
					else{
						bugFlag++;
						printf("FAILED: BUG# %d\n", bugFlag);
					}			
		#endif			
					printf("Testing silver cards, # in hand %d with bonus %d \n", i,j);
					memcpy(pre.hand[p], silvers, sizeof(int)*i);
					updateCoins(p,&pre,j);
		#if(NOISY_TEST ==1)	
					printf("Expected %d , Actual %d \n", (i*2+j), pre.coins);
					if (pre.coins == (i*2+j))
							printf("PASSED\n");
					else{
						bugFlag++;
						printf("FAILED: BUG# %d\n", bugFlag);
					}			
		#endif			
					printf("Testing gold cards. # in hand %d with bonus %d\n", i, j);
					memcpy(pre.hand[p], golds, sizeof(int)*i);
					updateCoins(p,&pre,j);
		#if(NOISY_TEST == 1)		
					printf("Expected %d , Actual %d \n", (i*3+j), pre.coins);
					if (pre.coins == (i*3+j))
						printf("PASSED\n");
					else{
						bugFlag++;
						printf("FAILED: BUG# %d\n", bugFlag);
					}			
				}//end inner for
			}//end for inner
		#endif	
	}//end outer for

	printf("Total Bugs: %d\n", bugFlag);
	printf("----------------END Testing updateCoins()---------------------------\n");		
			    
	return 0;
}
