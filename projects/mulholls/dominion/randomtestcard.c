#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "assert.h"

#include "rngs.h"
#include "dominion.h"
#include "unitTestLib.h"

#define TERM_ON_ERROR 0
#define MAX_ERROR 1000

void smithCard(struct gameState*, int, int*);

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

      int curPlayer = randState->numPlayers;
      curPlayer = (int)(curPlayer * Random());

      int handPos = randState->handCount[curPlayer];
      handPos = (int)(handPos * Random());

      randState->hand[curPlayer][handPos] = smithy;

      struct gameState cpyState;
      memcpy(&cpyState, randState, sizeof(struct gameState));

      smithyCard(randState, curPlayer, handPos);

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

   int i;
   int errCount = 0;

   printf("Basic Function Errors:\n");
   fflush(stdout);
   //After hand count should be increased by 2; 3 draws - 1 smithy
   if(after->handCount[curPlayer] != 2 + before->handCount[curPlayer]){
      printf("Basic Function Check: Didn't end up with net +2 cards in hand\n");
      fflush(stdout);
      errCount++;
   }

   if(after->discard[curPlayer][after->discardCount[curPlayer]-1] != smithy){
      printf("Basic Function Check: Didn't discard smithy to top of pile\n");
      fflush(stdout);
      errCount++;
   }

   if(errCount){
      printf("\n");
      printGameStateDifferences(curPlayer, before, after);
      printf("\n");
      if(TERM_ON_ERROR)
	 exit(1);
   } else {
      printf("None\n");
   }
   
   return errCount;
}
     

int fullCardCheck(int curPlayer, struct gameState* cpyState, struct gameState* randState){

   int i;
   int errCount = 0;
   int* prevCount = getDeckCount(curPlayer, cpyState);
   int* curCount = getDeckCount(curPlayer, randState);

   printf("Full Card Check Errors:\n");
   fflush(stdout);
   int prevTotal = 0, curTotal = 0;
   for(i = 0; i < treasure_map+1; i++){
      if(prevCount[i] != curCount[i]){
	 printf("Full Card Check: Card value %i has different count of cards before than after\n", i);
	 fflush(stdout);
	 errCount++;
      }
      prevTotal += prevCount[i];
      curTotal += curCount[i];
   }

   if(prevTotal != curTotal){
      printf("Full Card Check: Total card counts didn't match before and after\n");
      fflush(stdout);
      errCount++;
   }

   free(prevCount);
   free(curCount);

   if(errCount){
      printf("\n");
      printGameStateDifferences(curPlayer, cpyState, randState);
      printf("\n");
      if(TERM_ON_ERROR)
	 exit(1);
   } else {
      printf("None\n");
   }

   return errCount;
}


