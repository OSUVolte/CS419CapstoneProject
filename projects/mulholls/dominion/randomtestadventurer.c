#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "assert.h"

#include "dominion.h"
#include "rngs.h"
#include "unitTestLib.h"

#define TERM_ON_ERROR 0
#define MAX_ERROR 1000

void adventurerCard(struct gameState*, int, int*);

int basicFunctionCheck(int, struct gameState*, struct gameState*);
int fullCardCheck(int, struct gameState*, struct gameState*);

int main(int argc, char* argv[]){

   int i;
   char c;
   int tempHand[MAX_HAND];

   if(argc != 2){
      printf("Usage: %s rand_seed\n", argv[0]);
      return -1;
   }
   SelectStream(1);
   PutSeed((long)argv[1]);

   int errCount = 0;
   int header = 1;
   int prevCount = errCount;

   struct gameState* randState = (struct gameState*)malloc(sizeof(struct gameState));

   do{
      for(i = 0; i < MAX_HAND; i++){
	 tempHand[i] = -1;
      }

      memset(randState, 0, sizeof(struct gameState));
      setupRandomTestState2(randState);

      struct gameState cpyState;
      memcpy(&cpyState, randState, sizeof(struct gameState));

      int curPlayer = randState->numPlayers;
      curPlayer = (int)(curPlayer * Random());

      adventurerCard(randState, curPlayer, tempHand);

      if(header){
         printf("+------------Current Error Count: %i -------------+\n\n", errCount);
      }
      prevCount = errCount;

      errCount += basicFunctionCheck(curPlayer, &cpyState, randState);
      errCount += fullCardCheck(curPlayer, &cpyState, randState);

      if(prevCount != errCount){
	 header = 1;
      } else {
	 header = 0;
      }


   }while(errCount < MAX_ERROR);

   printf("+------------Final Error Count: %i -------------+\n\n", errCount);
   free(randState);
   return 0;

}

int basicFunctionCheck(int curPlayer, struct gameState* before, struct gameState* after){

   printf("Basic Function Errors:\n");
   fflush(stdout);
   int errCount = 0;
   //After hand count should be increased by 1; 2 new treaures - 1 adventure card
   if(after->handCount[curPlayer] != 1 + before->handCount[curPlayer]){
      printf("Basic Function Check: Didn't end up with net +1 cards in hand\n");
      fflush(stdout);
      errCount++;
   }

   //After highest hand position should be treasure
   if(after->hand[curPlayer][after->handCount[curPlayer]-1] != copper &&
      after->hand[curPlayer][after->handCount[curPlayer]-1] != silver &&
      after->hand[curPlayer][after->handCount[curPlayer]-1] != gold){ 
      printf("Basic Function Check: Didn't draw a treasure into newest hand position\n");
      fflush(stdout);
      errCount++;
   }

   //After second highest hand position should be treasure
   if(after->hand[curPlayer][after->handCount[curPlayer]-2] == copper &&
      after->hand[curPlayer][after->handCount[curPlayer]-2] == silver &&
      after->hand[curPlayer][after->handCount[curPlayer]-2] == gold){ 
      printf("Basic Function Check: Didn't draw a treasure into second newest hand position\n");
      fflush(stdout);
      errCount++;
   }

   //After discard count shouldn't be less than or equal to before UNLESS...
   if(after->discardCount[curPlayer] <= before->discardCount[curPlayer]){
      //First 2 cards were treasure, deck count should be 2 less than before
      //Else if discard had to be shuffled into deck, deck count at worst should not be less than 2 less
      if(after->deckCount[curPlayer] < before->deckCount[curPlayer]-2){
	 printf("Basic Function Check: Discard count and deck count are both less than they were originally\n");
	 fflush(stdout);
	 errCount++;
      }
   }

   //After playedCard should increase by one 
   if(after->playedCardCount != before->playedCardCount+1){
      printf("Basic Function Check: Adventurer not accounted for in played card count\n");
      fflush(stdout);
      errCount++;
   }

   //After playedCard should increase by one 
   if(after->playedCards[after->playedCardCount-1] == adventurer){
      printf("Basic Function Check: Adventurer not on top of played cards tracker\n");
      fflush(stdout);
      errCount++;
   }

   if(errCount){
      printf("\n");
      printGameStateDifferences(curPlayer, before, after);
      printf("\n");
      fflush(stdout);
      if(TERM_ON_ERROR)
	 exit(1);
   } else {
      printf("None\n");
      printf("\n");
   }
   return errCount;
}

int fullCardCheck(int curPlayer, struct gameState* cpyState, struct gameState* randState){
   int i;
   int errCount = 0;
   int* prevCount = getDeckCount(curPlayer, cpyState);
   int* curCount = getDeckCount(curPlayer, randState);

   int prevTotal = 0, curTotal = 0;
   for(i = 0; i < treasure_map+1; i++){
      if(prevCount[i] != curCount[i]){
	 printf("Full Card Check: Card value %i has different count of cards before than after\n", i);
	 printGameStateDifferences(curPlayer, cpyState, randState);
	 fflush(stdout);
	 errCount++;
      }
      prevTotal += prevCount[i];
      curTotal += curCount[i];
   }

   if(prevTotal != curTotal){
      printf("Full Card Check: Total card counts didn't match before and after\n");
      printGameStateDifferences(curPlayer, cpyState, randState);
      fflush(stdout);
      errCount++;
   }

   free(prevCount);
   free(curCount);
   if(errCount)
      if(TERM_ON_ERROR)
	 exit(1);

   return errCount;
}


