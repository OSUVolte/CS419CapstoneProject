/* -----------------------------------------------------------------------
 * Name: Alex Marsh
 * CS362
 * unittest4.c
 * This tests the function whoseTurn() function in dominion.c
 * Include the following lines in your makefile:
 *
 * unittest4: unittest4.c dominion.o rngs.o
 *      gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
//to include printfs set to 1
#define NOISY_TEST 0

int main(){
    int numPlayer = 4;
    int seed = 1000;
    int r;
    int expected, returnedPlayer;
    int numOfGames, players;
    int errors = 0;
    int totalGames = 11; //test for 10 games
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    printf("----------------- Testing whoseTurn() ----------------\n");
    printf("\n"); 
    
    for(numOfGames = 1; numOfGames < totalGames; numOfGames++){     
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
 //       printf("Game %d\n", numOfGames);
        
        returnedPlayer = whoseTurn(&G);  //get current player
//        printf("returnedPlayer is %d\n", returnedPlayer);
//        printf("r is %d\n", r);  //printCurrent player
 
        expected = r; //expected player is 
        if(returnedPlayer != expected){//check if score is correct
            printf("****FAIL Returned Player = %d, expected = %d\n", returnedPlayer, expected); 
            errors++;
        }  
#if (NOISY_TEST == 1)
 
        else{
            printf("PASS Returned Player = %d, expected = %d\n", returnedPlayer, expected);}  
#endif        
        //loop through the players. Once all of the players have had
        //a turn, whoseTurn() should loop around to the first player
        for(players=0; players < numPlayer; players++){
            endTurn(&G); //end current players turn and change players
            returnedPlayer = whoseTurn(&G);
            if(players < numPlayer - 1){
                expected= expected + 1; 
    //        printf("returnedPlayer after endTurn is %d\n", returnedPlayer);
            }
            else{  //whoseTurn should loop back to 0
              expected = 0;    
            }
            if(returnedPlayer != expected){//check if score is correct
                printf("****FAIL Returned Player after endTurn = %d, expected = %d\n", returnedPlayer, expected); 
                errors++;
            }  

#if (NOISY_TEST == 1)
     
            else{
                printf("PASS Returned Player after endTurn = %d, expected = %d\n", returnedPlayer, expected);} 
#endif
        }
    
    }
    
    if(errors == 0){
     printf("ALL TESTS PASS for whoseTurn().\n");   
    }
    else{
     printf("FAIL: There are %d errors in whoseTurn.\n", errors);   
    }
    
 return 0;   
}