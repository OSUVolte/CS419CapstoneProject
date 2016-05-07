#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int main() {
    int seed = 1000;
    int numPlayers = 4;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G, testG;
    int errorCount = 0;
    initializeGame(numPlayers, k, seed, &G);
    memcpy(&testG, &G, sizeof(struct gameState));
    printf("Testing gainCost function.\n\n");
    int cost;


     printf("Testing curse\n");
     if( getCost(curse) != 0)
     {
     printf("ERROR, curse card cost != 0\n");
     errorCount++;
     }

     printf("Testing estate\n");
     if( getCost(estate) != 2)
     {
     printf("ERROR, estate card cost != 2\n");
     errorCount++;
     }

     printf("Testing duchy\n");
     if( getCost(duchy) != 5)
     {
     printf("ERROR, dutchy card cost != 5\n");
     errorCount++;
     }

     printf("Testing province\n");
     if( getCost(province) != 8)
     {
     printf("ERROR, province card cost != 8\n");
     errorCount++;
     }

     printf("Testing copper\n");
     if( getCost(copper) != 0)
     {
     printf("ERROR, copper card cost != 0\n");
     errorCount++;
     }

     printf("Testing silver\n");
     if( getCost(silver) != 3)
     {
     printf("ERROR, silver card cost != 3\n");
     errorCount++;
     }

     printf("Testing gold\n");
     if( getCost(gold) != 6)
     {
     printf("ERROR, gold card cost != 6\n");
     errorCount++;
     }

     printf("Testing adventurer\n");
     if( getCost(adventurer) != 6)
     {
     printf("ERROR, adventurer card cost != 6\n");
     errorCount++;
     }

     printf("Testing Council Room\n");
     if( getCost(council_room) != 5)
     {
     printf("ERROR, council_room card cost != 5\n");
     errorCount++;
     }

     printf("Testing feast\n");
     if( getCost(feast) != 4)
     {
     printf("ERROR, feast card cost != 4\n");
     errorCount++;
     }

     printf("Testing gardens\n");
     if( getCost(gardens) != 4)
     {
     printf("ERROR, gardens card cost != 4\n");
     errorCount++;
     }

     printf("Testing mine\n");
     if( getCost(mine) != 5)
     {
     printf("ERROR, mine card cost != 5\n");
     errorCount++;
     }

     printf("Testing remodel\n");
     if( getCost(remodel) != 4)
     {
     printf("ERROR, remodel card cost != 4\n");
     errorCount++;
     }

     printf("Testing smithy\n");
     if( getCost(smithy) != 4)
     {
     printf("ERROR, smithy card cost != 4\n");
     errorCount++;
     }

     printf("Testing village\n");
     if( getCost(village) != 3)
     {
     printf("ERROR, village card cost != 3\n");
     errorCount++;
     }

     printf("Testing baron\n");
     if( getCost(baron) != 4)
     {
     printf("ERROR, baron card cost != 4\n");
     errorCount++;
     }

     printf("Testing great_hall\n");
     if( getCost(great_hall) != 3)
     {
     printf("ERROR, great_hall card cost != 3\n");
     errorCount++;
     }

     printf("Testing minion\n");
     if( getCost(minion) != 5)
     {
     printf("ERROR, minion card cost != 5\n");
     errorCount++;
     }

     printf("Testing steward\n");
     if( getCost(steward) != 3)
     {
     printf("ERROR, steward card cost != 3\n");
     errorCount++;
     }

     printf("Testing tribute\n");
     if( getCost(tribute) != 5)
     {
     printf("ERROR, tribute card cost != 5\n");
     errorCount++;
     }

     printf("Testing ambassador\n");
     if( getCost(ambassador) != 3)
     {
     printf("ERROR, ambassador card cost != 3\n");
     errorCount++;
     }

     printf("Testing cutpurse\n");
     if( getCost(cutpurse) != 4)
     {
     printf("ERROR, cutpurse card cost != 4\n");
     errorCount++;
     }

     printf("Testing embargo\n");
     if( getCost(embargo) != 2)
     {
     printf("ERROR, embargo card cost != 2\n");
     errorCount++;
     }

     printf("Testing outpost\n");
     if( getCost(outpost) != 5)
     {
     printf("ERROR, outpost card cost != 5\n");
     errorCount++;
     }

     printf("Testing salvager\n");
     if( getCost(salvager) != 4)
     {
     printf("ERROR, salvager card cost != 4\n");
     errorCount++;
     }

     printf("Testing sea_hag\n");
     if( getCost(sea_hag) != 4)
     {
     printf("ERROR, sea_hag card cost != 4\n");
     errorCount++;
     }

     printf("Testing treasure_map\n");
     if( getCost(treasure_map) != 4)
     {
     printf("ERROR, treasure_map card cost != 4\n");
     errorCount++;
     }


    printf("\n >>>>> Testing complete with %i errors <<<<<\n\n\n", errorCount);
    return 0;
}



