#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "dominion.h"
//makefile was taken from https://github.com/aburasali/cs362sp16/blob/master/projects/batese/dominion/Makefile


void testWhoseTurn() {
    printf("\n\nwhoseTurn() Function test\n");
    //initialize game
    struct gameState* g = malloc(sizeof(struct gameState));
    //assign cards
    int k[10] = {smithy, adventurer, feast, council_room, embargo, village, minion, mine, cutpurse, sea_hag, tribute};
    int player;
    printf("Test WhoseTurn() #1 - once the game is initialized, first player goes 1st.\n");
    for (player = 0; player < 2; player++){
        //initialize game for each player
        initializeGame(player, k, 100, g);
        //check to make sure that whoseTurn function work as expected
        //no matter with how many players the game is initializes, the first
        //players should go first
        if (whoseTurn(g) == g->whoseTurn){
            printf("WhoseTurn(): function works as expected after game is initialized. \n");
            printf("WhoseTurn(): %d \n", g->whoseTurn );
        }
        else{
            printf("ERROR: There is an error in WhoseTurn():function  \n" );
            printf("WhoseTurn(): %d \n", g->whoseTurn );
        }
    }
    printf("Test WhoseTurn() # 2- check that function works as expected during the game. \n");
    //assign turn to player 5 and make sure that it works as expectec
    int r = 5;
    //assign whoseturn to r
    g->whoseTurn = r;
    if (whoseTurn(g) == r){
        printf("WhoseTurn(): function works as expected for a specific player. \n");
        printf("WhoseTurn(): %d \n", whoseTurn(g));
    }
    else{
        printf("ERROR: There is an error in WhoseTurn():function  \n" );
        printf("WhoseTurn(): %d \n", whoseTurn(g) );
    }


}

int main () {
    testWhoseTurn();
    exit(0);
}
