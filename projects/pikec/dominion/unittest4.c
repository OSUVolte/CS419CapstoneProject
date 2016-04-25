/********************************
** filename: unittest4.c
** author: Candis Pike
** date: April 16, 2016
** description: unit test of initializeGame()
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
	struct gameState pre;
	pre.whoseTurn = 0;
	int bugFlag = 0;
	int play = 0;
	int count = 0;
	int ret = 0;
	int i=0, j=0, n=0;
	int MAX_PLAYER = 4;
		
	//set-up initial game board
	int k[10]= {adventurer, smithy, village, cutpurse, feast, minion, remodel, mine, gardens, sea_hag};
	
	//initialize a game using 0 to maxplayers +1 confirm that player< 2 and > maxplayer are not allowed
	//check for numPlayers set
	//check supply cards are properly set some differ dependent on players
	//check initial decks
	//chekc embargo
	//check first player stats and other player stats
	
	printf("----------------START Testing initializeGame()---------------------------\n");
	for (play=0; play <= (MAX_PLAYER+1); play++){
		ret = initializeGame(play,k, 42, &pre);
		printf("Confirm that game initialized with %d players. \n", play);		
		if (ret == 0)
			printf("PASSED: initialized game with 2-4 players\n");
		else if(ret == -1){
			printf("Players was not between 2-4\n");
			if (play < 2 || play > MAX_PLAYERS)
				printf("PASSED\n");
			else{
				bugFlag++;
				printf("FAILED: BUG# %d\n", bugFlag);
			}
		}
		if(ret==0){
		printf("Confirm numPlayers = %d players.i\n", play);
		if(pre.numPlayers == play)
			printf("PASSED\n");
		else{
			bugFlag++;
			printf("FAILED: BUG# %d\n", bugFlag);
		}
		
		printf("Confirm curse card count for %d players: ", play);
		//curse cards
		if(play == 2){
			printf("should be 10");
			count = supplyCount(curse, &pre);
			printf (" actual: %d\n", count);
			if(count == 10)
				printf("PASSED\n");
			else{
				bugFlag++;
				printf("FAILED: BUG# %d\n", bugFlag);
			}
		}
		
		if(play == 3){
			printf("should be 20");
			count = supplyCount(curse, &pre);
			printf (" actual: %d\n", count);
			if(count == 20)
				printf("PASSED\n");
			else{
				bugFlag++;
				printf("FAILED: BUG# %d\n", bugFlag);
			}
		}
		if(play == 4){
			printf("should be 30");
			count = supplyCount(curse, &pre);
			printf (" actual: %d\n", count);
			if(count == 30)
				printf("PASSED\n");
			else{
				bugFlag++;
				printf("FAILED: BUG# %d\n", bugFlag);
			}
		}
		
		printf("Confirm provience card for %d players i", play);
		//provience cards
		if(play == 2){
			printf("estate, duchy and province should be 8 ");
			count = supplyCount(estate, &pre);
			int count2 =supplyCount(duchy, &pre);
			int count3 =supplyCount(province, &pre);
			printf (" actual esate: %d  actual duchy: %d    acutal provience: %d\n", count,count2, count3);
			if((count == count2) && (count == count3) && (count3==count2))
				printf("PASSED\n");
			else{
				bugFlag++;
				printf("FAILED: BUG# %d\n", bugFlag);
			}
		}
		
		else{
			printf("estate, duchy and province should be 12 ");
			count = supplyCount(estate, &pre);
			int count2 =supplyCount(duchy, &pre);
			int count3 =supplyCount(province, &pre);
			printf (" actual esate: %d  actual duchy: %d    acutal provience: %d\n", count, count2, count3);
			if((count == count2) && (count == count3) && (count3==count2))
				printf("PASSED\n");
			else{
				bugFlag++;
				printf("FAILED: BUG# %d\n", bugFlag);
			}
		}
		
		//treasure cards
		printf("Confirm coin card counts copper: 60 - (7*%d) silver: 40 gold: 30 actual: %d  %d  %d\n",play, supplyCount(copper, &pre),supplyCount(silver, &pre),supplyCount(gold, &pre));
		int coppers =supplyCount(copper, &pre); 
		int silvers = supplyCount(silver, &pre);
		int golds = supplyCount(gold, &pre);
		if ((coppers == 60-(7*play)) && (silvers == 40) && (golds == 30))
			printf("PASSED\n");
			else{
				bugFlag++;
				printf("FAILED: BUG# %d\n", bugFlag);
			}
			
		//test kingdom cards
		for(i=0; i<10; i++){
			if (k[i]== gardens || k[i] == great_hall ){
				if(play ==2 && k[i] == gardens){
					printf("Confirming that gardens is 8. actual: %d\n", supplyCount(gardens, &pre));
						if(supplyCount(gardens, &pre) == 8)
								printf("PASSED\n");
						else{
							bugFlag++;
							printf("FAILED 1: BUG# %d\n", bugFlag);
						}
				}
				else if (play ==2 && k[i] == great_hall){
					printf("Confirming that great hall is 8. actual: %d\n", supplyCount(great_hall, &pre));
						if(supplyCount(great_hall, &pre) == 8)
							printf("PASSED\n");
						else{
							bugFlag++;
							printf("FAILED: BUG# %d\n", bugFlag);
						}
				}
				else if (play > 2 && k[i] == gardens){
							printf("Confirming that gardens is 12. actual: %d\n", supplyCount(gardens, &pre));
						if(supplyCount(gardens, &pre) == 12)
							printf("PASSED\n");
						else{
							bugFlag++;
							printf("FAILED: BUG# %d\n", bugFlag);
						}
				}
				else if (play > 2 && k[i] == great_hall){
					printf("Confirming that great hall is 12. actual: %d\n", supplyCount(great_hall, &pre));
						if(supplyCount(great_hall, &pre) == 12)
							printf("PASSED\n");
						else{
							bugFlag++;
							printf("FAILED: BUG# %d\n", bugFlag);
						}
			    }
			}//end gardens/great hall
			else if((k[i] != great_hall) && (k[i] != gardens)){ 
				printf("Confirm kingdom card %d is 10 actual: %d \n", k[i], supplyCount(k[i], &pre));
				if(supplyCount(k[i], &pre) == 10)
					printf("PASSED \n");
				else{
					bugFlag++;
					printf("FAILED : BUG# %d\n", bugFlag);
				}
			}
		}//end kingdom for
		
		//confim embargo coins are 0
		for (j=0; j< treasure_map; j++){
			if(pre.embargoTokens[j]!=0){
				bugFlag++;
				printf("FAILED card: %d: BUG# %d\n", j, bugFlag);
			}
		}

		//check total cards	
		for(n=0; n< play; n++){
		printf("Confim initial total card count is 10. player %d actual: %d\n",n, (pre.handCount[n]+pre.deckCount[n]+pre.discardCount[n]));
		if((pre.handCount[n]+pre.deckCount[n]+pre.discardCount[n]) == 10)
			printf("PASSED\n");
		else{
			bugFlag++;
			printf("FAILED: BUG# %d\n", bugFlag);
		}
		}
		}			
		memset(&pre, 0, sizeof(struct gameState));
	}//end for
	
	printf("Total Bugs: %d\n", bugFlag);
	printf("----------------END Testing drawCard()---------------------------\n");

	return 0;
}
