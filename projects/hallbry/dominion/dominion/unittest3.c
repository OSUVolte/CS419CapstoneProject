

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

void runTest(int player, struct gameState * G, int type, int expectedResult );
int compareTest(int, int);

int main() {
    int i, j;
    int seed = 1000;
    int numPlayer = 2;
	int testResult =0;
    int p, result;

    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
	int pointsCards[6] = {curse, estate, duchy, province, great_hall, gardens};
    struct gameState G;
    int maxHandCount = 5;
    int cards[maxHandCount];	
	
	initializeGame(numPlayer, k, seed, &G); // initialize a new game
	result= scoreFor(0, &G);
	

	//Score For
	printf("-------------------UNITTEST3: SCOREFOR --------------------\n");	
	
	//evaluate individual sections
	printf("\nEvaluating Cards in hand\n\n");	
	for(p=0; p< G.numPlayers; p++){
		//evaluating points for cards in hand
		for( j = 0; j<6; j++){
			for (i = 0; i < maxHandCount; i++)  {
				cards[i]= pointsCards[j];   
			}
			
			//memset(&G, 33, sizeof(struct gameState));   // clear the game state
			memcpy(G.hand[p], cards, sizeof(curse) * maxHandCount);
			
			G.handCount[p] = maxHandCount;
			result= scoreFor(p, &G);
			if(j == 0){
				printf("Player %d\nCard in hand: CurseCard\nExpected Value: %d, Actual Value%d\n",p, -5  ,result);
				//assert (result == -5);
				testResult += compareTest(result, -5);
			}
			
			else if( j== 1){
				printf("Player %d\nCard in hand: estate\nExpected Value: %d, Actual Value%d\n",p, 5  ,result);
				//assert (result == 5);
				testResult += compareTest(result, 5);
			}
			else if(j==2){
				printf("Player %d\nCard in hand: Duchy \nExpected Value: %d, Actual Value%d\n",p, 15  ,result);
				//assert (result == 15);
				testResult += compareTest(result, 15);
			}
			else if(j==3){
				printf("Player %d\nCard in hand: Province \nExpected Value: %d, Actual Value%d\n",p, 30  ,result);
				//assert (result == 30);
				testResult += compareTest(result, 30);
			}
			else if(j==4){
				printf("Player %d\nCard in hand: Great Hall\nExpected Value: %d, Actual Value%d\n",p, 5  ,result);
				//assert (result == 5);
				testResult += compareTest(result, 5);
			}
			else if(j==5){
				printf("Player %d\nCard in hand: Great Hall\nExpected Value: %d, Actual Value%d\n",p, 6  ,result);
				//assert (result == 5);
				testResult += compareTest(result, 5);
			}
			
				
		}
	}
	
	
	initializeGame(numPlayer, k, seed, &G); // initialize a new game	
	printf("\nEvaluating Cards in deck\n\n");	
	for( j = 0; j<6; j++){
		for (i = 0; i < maxHandCount; i++)  {
			cards[i]= pointsCards[j];   
		}			
	
		memcpy(G.deck[p], cards, sizeof(curse) * maxHandCount);		
		G.handCount[p] = 0;
		G.discardCount[p] = 0;		
		G.deckCount[p] = maxHandCount;
		result= scoreFor(p, &G);
		if(j == 0){
			printf("Player %d\nCard in hand: CurseCard\nExpected Value: %d, Actual Value: %d\n",p, -5  ,result);
			//assert (result == -5);
			testResult += compareTest(result, -5);
		}
		
		else if( j== 1){
			printf("Player %d\nCard in hand: estate\nExpected Value: %d, Actual Value%d\n",p, 5  ,result);
			//assert (result == 5);
			testResult += compareTest(result , 5);
		}
		else if(j==2){
			printf("Player %d\nCard in hand: Duchy \nExpected Value: %d, Actual Value%d\n",p, 15  ,result);
			//assert (result == 15);
			testResult += compareTest(result,15);	
		}
		else if(j==3){
			printf("Player %d\nCard in hand: Province \nExpected Value: %d, Actual Value%d\n",p, 30  ,result);
			//assert (result == 30);
			testResult += compareTest(result,30);	
		}
		else if(j==4){
			printf("Player %d\nCard in hand: Great Hall\nExpected Value: %d, Actual Value%d\n",p, 5  ,result);
			//assert (result == 5);
			testResult += compareTest(result,5);		
		}
		else if(j==5){
			printf("Player %d\nCard in hand: Great Hall\nExpected Value: %d, Actual Value%d\n",p, 6  ,result);
			//assert (result == 5);
			testResult += compareTest(result,5);				
		}				
	}
	
		
		
	initializeGame(numPlayer, k, seed, &G); // initialize a new game
	//memset(&G, 33, sizeof(struct gameState));   // clear the game state
              
    
	
	printf("Starting Score: %d \n",scoreFor(p, &G) );
	printf("\nEvaluating Cards in Discard\n\n");	
	for(p=0; p< G.numPlayers; p++){
		//evaluating points for cards in hand
		for( j = 0; j<6; j++){
			for (i = 0; i < maxHandCount; i++)  {
				cards[i]= pointsCards[j];   
			}
			
			//memset(&G, 33, sizeof(struct gameState));   // clear the game state
			//set all cards to cards type
			memcpy(G.discard[p], cards, sizeof(curse) * maxHandCount);
			
			G.discardCount[p] = maxHandCount;
			G.handCount[p] = 0;
			G.deckCount[p] = 0;			
			result= scoreFor(p, &G);
			if(j == 0){
				printf("Player %d\nCard in hand: CurseCard\nExpected Value: %d, Actual Value%d\n",p, -5  ,result);
				//assert (result == -5);
				testResult += compareTest(result, -5);
			}
			
			else if( j== 1){
				printf("Player %d\nCard in hand: estate\nExpected Value: %d, Actual Value%d\n",p, 5  ,result);
				//assert (result == 5);
				testResult += compareTest(result, 5);
			}
			else if(j==2){
				printf("Player %d\nCard in hand: Duchy \nExpected Value: %d, Actual Value%d\n",p, 15  ,result);
				//assert (result == 15);
				testResult += compareTest(result, 15);
			}
			else if(j==3){
				printf("Player %d\nCard in hand: Province \nExpected Value: %d, Actual Value%d\n",p, 30  ,result);
				//assert (result == 30);
				testResult += compareTest(result, 30);
			}
			else if(j==4){
				printf("Player %d\nCard in hand: Great Hall\nExpected Value: %d, Actual Value%d\n",p, 5  ,result);
				//assert (result == 5);
				testResult += compareTest(result, 5);
				
			}
			else if(j==5){
				printf("Player %d\nCard in hand: Great Hall\nExpected Value: %d, Actual Value%d\n",p, 6  ,result);
				//assert (result == 5);
				testResult += compareTest(result, 5);
			}				
		}
	}
	
	//print out results
	if(testResult ==0){
		printf("\nUnit 3 Test Results Passed!\n");		
	}
	else{
		printf("\nUnit 3 Test Failed\n");
	}
	
	printf("--------------------------------------------------\n");	
	
	
	
	
	
	
	return 0;
	
}

int compareTest(int a, int b){
	if(a == b){
		printf("PASSED!\n");
		return 0; 	
	}
	else{
		printf("FAILED!\n");
		return 1;		
	}	
}