/* -----------------------------------------------------------------------
 * Martha Gebremariam
 * CS362_SP2016
 * Assignment 4
 * Description: Random test for adventurer card in dominion.c
 * 
 * The following lines were also included makefile:
 *
 * randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
 * gcc -o randomtestadventurer -g  randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include "math.h"
#include <time.h>
#include <stdlib.h>

int main() {
    printf("\n\n*************************\n");
    printf ("Random testing adventurer card\n");
    printf("*************************\n\n");
    int passedTest=0;
    int failedTest=0;
   int b;   
   	int i, j, n, r, p, deckCount, discardCount, handCount;  	
 	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	SelectStream(2);
  	PutSeed(3);
	srand (time(NULL));
	p = rand() % 2;
	
//	printf("p: %d\n", p);
	int seed=1000;
  	struct gameState G;
	
	//initialize game
	initializeGame(2, k, seed, &G);
	G.supplyCount[adventurer]=9;
	G.whoseTurn=p;
	int cardCount[treasure_map+1]={0};
	int maxCount[treasure_map+1];

	//copy supplyCount into maxCount
	memcpy(maxCount, G.supplyCount, sizeof(maxCount));

    	int found=0;	

	//set deckCount and discardCount to random number
	//between 0 and 90. Can also use MAX_DECK-10
	//10 subtracted for the original estate and copper cards 
        G.deckCount[p] = rand() % (100-10);
       //printf("G.deckCount[p]:%d\n",G.deckCount[p]);
	    G.discardCount[p] = rand() % (100-10);
        //printf("G.discardCount[p]:%d\n",G.discardCount[p]);
        //
        //set hand count 
	    G.handCount[p] = rand() % ((20-10)-3+1) + 3;
	  //printf("G.handCount[p]:%d\n",G.handCount[p]);
    
	    //create a random deck
	    for (i=0; i<G.deckCount[p]; i++){
	    	int rnd=(rand()%(treasure_map+1));
		    //printf("rnd[%d]: %d\n",i,rnd);
	    	if (rnd>=adventurer){
	    		for (j=0; j<10; j++){
	    			if (k[j]==rnd){
	    				cardCount[rnd]++;
	    				if (cardCount[rnd]<=maxCount[rnd]){
	    					G.deck[p][i]=rnd;
	    					G.supplyCount[rnd]--;
						found=1;
	    				}
	    				break;
	    			}
	    		}
			if (found==0)
				i--;
			else
				found=0;
	
	    	}
	    	else{
		    	cardCount[rnd]++;
		    	if (cardCount[rnd]<=maxCount[rnd]){
		    		G.deck[p][i]=rnd;
		    		G.supplyCount[rnd]--;	    	
		    	}	
                else
				    i--;
	    	}
	    } 	
    
         //create a random discard pile
    	    for (i=0; i<G.discardCount[p]; i++){
	    	int rnd=(rand()%(treasure_map+1));
		    //printf("rnd[%d]: %d\n",i,rnd);
	    	if (rnd>=adventurer){
	    		for (j=0; j<10; j++){
	    			if (k[j]==rnd){
	    				cardCount[rnd]++;
	    				if (cardCount[rnd]<=maxCount[rnd]){
	    					G.discard[p][i]=rnd;
	    					G.supplyCount[rnd]--;
						found=1;
	    				}
	    				break;
	    			}
	    		}
			if (found==0)
				i--;
			else
				found=0;
	
	    	}
	    	else{
		    	cardCount[rnd]++;
		    	if (cardCount[rnd]<=maxCount[rnd]){
		    		G.discard[p][i]=rnd;
		    		G.supplyCount[rnd]--;	    	
		    	}	
                else
				    i--;
	    	}
	    } 	
	
	    //create a random hand
    	    for (i=0; i<G.handCount[p]; i++){
	    	int rnd=(rand()%(treasure_map+1));
		    //printf("rnd[%d]: %d\n",i,rnd);
	    	if (rnd>=adventurer){
	    		for (j=0; j<10; j++){
	    			if (k[j]==rnd){
	    				cardCount[rnd]++;
	    				if (cardCount[rnd]<=maxCount[rnd]){
	    					G.hand[p][i]=rnd;
	    					G.supplyCount[rnd]--;
						found=1;
	    				}
	    				break;
	    			}
	    		}
			if (found==0)
				i--;
			else
				found=0;
	
	    	}
	    	else{
		    	cardCount[rnd]++;
		    	if (cardCount[rnd]<=maxCount[rnd]){
		    		G.hand[p][i]=rnd;
		    		G.supplyCount[rnd]--;	    	
		    	}	
                else
				    i--;
	    	}
	    }
    //checkAdventurerCard(p, &G);
   /* 
	for (i=0; i<G.deckCount[p]; i++)
	 	printf("deck[%d]: %d\n", i, G.deck[p][i]);
	
	for (i=0; i<G.discardCount[p]; i++)
	 	printf("discard[%d]: %d\n", i, G.discard[p][i]);

	for (i=0; i<G.handCount[p]; i++)
	 	printf("hand[%d]: %d\n", i, G.hand[p][i]);
*/
	//place original estate and copper cards randomly within 
	//deck or discard or hand
	for (i=0; i<3; i++){
		int s=rand() % 3;
		if (s==0){
		 if (G.deckCount[p]!=0){
		   int idx=rand() % G.deckCount[p];
		   int temp = G.deck[p][idx];
		   G.deck[p][idx]= estate;
		   G.deck[p][G.deckCount[p]]=temp;
		   G.deckCount[p]++;
		 }
		 else
		   s=rand() % 2 + 1;
		   int s1=1;
		}
		if (s==1){
		 if (G.discardCount[p]!=0){
		   int idx=rand() % G.discardCount[p];
		   int temp = G.discard[p][idx];
		   G.discard[p][idx]= estate;
		   G.discard[p][G.discardCount[p]]=temp;
		   G.discardCount[p]++;
		 }
		 else
		   s=2;
		   	   
		}	
		if (s==2) {
		   int idx=rand() % G.handCount[p];
		   int temp = G.hand[p][idx];
		   G.hand[p][idx]= estate;
		   G.hand[p][G.handCount[p]]=temp;
		   G.handCount[p]++;
		}	
	
	}
	for (i=0; i<7; i++){
		int s=rand() % 3;
		if (s==0){
		   int idx=rand() % G.deckCount[p];
		   int temp = G.deck[p][idx];
		   G.deck[p][idx]= copper;
		   G.deck[p][G.deckCount[p]]=temp;
		   G.deckCount[p]++;
		}
		else if (s==1){
		   int idx=rand() % G.discardCount[p];
		   int temp = G.discard[p][idx];
		   G.discard[p][idx]= copper;
		   G.discard[p][G.discardCount[p]]=temp;
		   G.discardCount[p]++;
		}	
		else {
		   int idx=rand() % G.handCount[p];
		   int temp = G.hand[p][idx];
		   G.hand[p][idx]= copper;
		   G.hand[p][G.handCount[p]]=temp;
		   G.handCount[p]++;
		}	
	
	}
	
	//place adventurer card in hand  
	int handpos=rand() % G.handCount[p];
	int temp = G.hand[p][handpos];
	G.hand[p][handpos]=adventurer;
	G.hand[p][G.handCount[p]]=temp;
	G.handCount[p]++;
/*	printf("deck: \n");
	for (i=0; i<G.deckCount[p]; i++)
	 	printf("%d, ", G.deck[p][i]);
	printf("\ndiscard:\n");
	for (i=0; i<G.discardCount[p]; i++)
	 	printf("%d, ", G.discard[p][i]);
	printf("\nhand: \n");
	for (i=0; i<G.handCount[p]; i++)
	 	printf("%d, ", G.hand[p][i]);
*/

	 int origHand=G.handCount[p];
	 int origCardCount=origHand+G.deckCount[p]+G.discardCount[p];
	
	//call cardEffect with adventurer and state
	cardEffect(adventurer, 0, 0, 0, &G, handpos, 0);

	printf("Expected HandSize: %d - Result %d\n", origHand+2, G.handCount[p]);
    if (G.handCount[p] == origHand+2){
        printf("Passed hand count test\n\n");
        passedTest++;
    }
    else{
        printf("failed hand count test\n\n");
        failedTest++;
    }

    printf("Expected Card size (deck+discard+hand) for player: %d - Result %d\n", origCardCount, G.handCount[p]+G.deckCount[p]+G.discardCount[p]);
    if (G.handCount[p]+G.deckCount[p]+G.discardCount[p] == origCardCount){
        printf("Passed card count test\n\n");
        passedTest++;
    }
    else{
        printf("failed card count test\n\n");
        failedTest++;
    }

	printf("Passed %d and failed %d of the random tests\n", passedTest, failedTest);
       	return 0;
  }

