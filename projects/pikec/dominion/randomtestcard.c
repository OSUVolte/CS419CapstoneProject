/********************************
** filename: 
** author: Candis Pike
** date: April 22, 2016
** description: random tester of village card
** radomize: deck/hand/discard
** create random kingdom cards. randomize village and place in hand
** create random deck/hand/discard for 4 players
**********************************/
#include "dominion_helpers.h"
#include "dominion.h"
#include "rngs.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h> 

static int MAX_PLAY = 4;
static int MAX_CARD = 150;
static int MAX_TEST = 50;

int main (){
	struct gameState pre, post;
	int i, play;
	int success=0, failure=0;
	int ts, tf;
	int handpos=0;
	int choice1=0;
	int choice2=0;
	int choice3=0; 
	int bonus = 0;
			
	srand(time(NULL));       //seed random

	printf("---------------START RANDOM TESTING ADVENTURE---------------\n");
	
	for(i=1; i <= MAX_TEST; i++){
		//initialize a game
		
		int ranNum;
		
		//create kingdom
		int x = 0, j=0;
		int k[10];
		int flag = 0;
		
		for (x=0; x < 10; x++){
			do {
				ranNum = (7+rand())/(RAND_MAX/21);
				for (j=0; j < x; j++){
					if (k[j] == ranNum){
					flag = 0;
				}//end if			
			}//end check for
			flag = 1;
			}while (flag == 0);
			k[x] = ranNum;
		}//end create for
	
		//initialize the game
		initializeGame(MAX_PLAY, k, 42, &pre);
	
		//check for village
		int ck=0;
		int ckFlag = 0;
		for (ck=0; ck < 10; ck++){
			if (k[ck] == village)
			ckFlag = 1;
		}
		if (ckFlag == 0){
			ranNum = rand()% 9;
			k[ranNum]= village;
		}
	
		//create hand array
		int cards[14];
		int n = 0;
		for (n=0; n < 10; n++){
			cards[n]= k[n];
		}
		cards[11] = copper;
		cards[12]= silver;
		cards[13]= gold;
		cards[14] = estate;
	
		int plays;
		for (plays = 0; plays < MAX_PLAY; plays++){
		//randomize deck count
			pre.deckCount[plays] = rand()%MAX_CARD;
			int y;
			for ( y= 0; y < pre.deckCount[plays]; y++){
				ranNum = rand()%13;
				pre.deck[play][y] = cards[ranNum]; 
			}
		
			//radommize hand count
			pre.handCount[plays] = rand()%MAX_CARD;
			for (y = 0; y < pre.handCount[plays]; y++){
				ranNum = rand()%13;
				pre.hand[plays][y] = cards[ranNum]; 
			}
			
			//make sure adventurer is in the hand if the handcount is 0 or 1 ignore
			if (pre.handCount[plays] <1){
				handpos=rand()%(pre.handCount[plays]-1);	
				pre.hand[plays][handpos]= village;
			}
			
			//randomize discard count
			pre.discardCount[plays] = rand()%MAX_CARD;
			for (y = 0; i < pre.discardCount[plays]; y++){
			ranNum = rand()%13;
			pre.discard[plays][y] = cards[ranNum]; 
			}
		
		}//end create decks

		memcpy(&post, &pre, sizeof(struct gameState));	
		
		for(play = 0; play< MAX_PLAY; play++){
			post.whoseTurn = play;
			printf ("STARTING TEST #%d for PLAYER %d\n", i, play);
			printf("hand count: %d and deck count: %d discard count: %d\n", post.handCount[play], post.deckCount[play], post.discardCount[play]);
			//reset individual test bug counts 
			ts = 0;
			tf = 0;
			
			//play adventurer
			cardEffect(village, choice1, choice2, choice3, &post, handpos, &bonus);			
						
			//check for 1 additional card and that it came from the players deck
			printf("Confirm current player has a new cards in the hand post (because of discard should see same value): %d and pre: %d \n", post.handCount[play],pre.handCount[play]);
			if (post.handCount[play] == pre.handCount[play]){       //when village is discarded net hand count is zero
				if (pre.deckCount[play] > 0 ){
					if(pre.deckCount[play] > post.deckCount[play]){
						success++;
						ts++;
						printf("PASSED\n");
					}
					else{
						failure++;
						tf++;
						printf("FAILED\n");
					}	
				}
			}			
			else{
				failure++;
				tf++;
				printf("FAILED\n");
			}
	
			//assert that village was discarded and no longer in played hand 
			printf("Village discarded should increase the played card count  post: %d and pre: %d\n", post.playedCardCount, pre.playedCardCount);
			printf("Top played card should be village post:%d \n", post.playedCards[post.playedCardCount-1]);
			if((post.playedCardCount > pre.playedCardCount) && (post.playedCards[post.playedCardCount-1]== village)){
				if(post.hand[play][handpos]!= village){
					success++;
					ts++;
					printf("PASSED\n");
				}
				else{
					printf("FAILED\n");
					failure++;
					tf++;
				}
			}
			else{
				printf("FAILED\n");
				failure++;
				tf++;
			}
					
			//assert that player now has 2 actions
			printf("Village increases actions to 2. pre: %d and post: %d\n", pre.numActions, post.numActions);
			if((pre.numActions+2) == post.numActions){
					success++;
					ts++;
					printf("PASSED\n");
				}
			else{
				printf("FAILED\n");
				failure++;
				tf++;
			}
				
			//assert that other players have no changes
			int test = 0;
			for (test = 0; test< MAX_PLAY; test++){
				if(test != play){
					printf("Confirm other players hand, discard and deck piles did not change Player: %d\n", test);
					if(post.hand[test][post.handCount[test]] != pre.hand[test][pre.handCount[test]]){
						printf("FAILED hand count\n");
						failure++;
						tf++;
					}
					else {
						success ++;
						ts++;
					}
					if(post.handCount[test] != pre.handCount[test]){
						printf("FAILED hand count\n");
						failure++;
						tf++;
					}
					else {
						success ++;
						ts++;
					}
					if(post.deck[test][post.deckCount[test]] != pre.deck[test][pre.deckCount[test]]){
						printf("FAILED hand count\n");
						failure++;
						tf++;
					}
					else {
						success ++;
						ts++;
					}
					if(post.deckCount[test] != pre.deckCount[test]){
						printf("FAILED deck count\n");
						failure++;
						tf++;
					}
					else {
						success ++;
						ts++;
					}
					if(post.discard[test][post.discardCount[test]] != pre.discard[test][pre.discardCount[test]]){
						printf("FAILED discard deck\n");
						failure++;
						tf++;
					}
					else {
						success ++;
						ts++;
					}
					if(post.discardCount[test] != pre.discardCount[test])	{
						printf("FAILED discard count\n");
						failure++;
						tf++;
					}
					else {
						success ++;
						ts++;
					}
					printf("Stack counts test finished.\n");
				
					printf("Confirm other player coin counts did not change\n");
					updateCoins (test, &pre, 0);
					int preCoin = pre.coins;
					updateCoins (test, &post, 0);
					int postCoin = post.coins;
					if(preCoin != postCoin){
						printf("FAILED coin count\n");
						failure++;
						tf++;
					}
					else {
						success ++;
						ts++;
					}
					
				}//end if not current
			}//end test other players
				
		//assert that remaing kingdom, coin, and provience cards are untouched
			printf("Testing remaining kingdom, coin, and provience card counts remained unchanged after smithy card play.\n");
			int king;
			for (king=0; king < 28; king++){
				if(pre.supplyCount[king] != post.supplyCount[king]){
					printf("FAILED supply count\n");
					failure++;
					tf++;
				}
				else {
					success++;
					ts++;
				}
		}
				
		//copy post to pre for next player
		memset(&pre, 0, sizeof(struct gameState));
		memcpy(&pre, &post, sizeof(struct gameState));
		memset(&post,  0, sizeof(struct gameState));
		memcpy(&post, &pre, sizeof(struct gameState));
		}//end player for		
	
	//print current test results
	printf("Test # %d success: %d, failures: %d\n", i, ts, tf);
	//reset pre and post
		
	}//end for  	
	
	printf("Total Tests: %d   Success: %d   Failures: %d\n", MAX_TEST, success, failure);
	printf("-------------------END RANDOM TESTING VILLAGE------------------------\n");
	
	return 0;
}