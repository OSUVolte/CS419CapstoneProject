/*
Alex Samuel
Assignment 3
unittest1.c
Tests getCost() function
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {

    printf ("TESTING getCost():\n");

    int cards[] = {curse, estate, duchy, province, copper, silver, gold, adventurer, council_room, feast, gardens,
    mine, remodel, smithy, village, baron, great_hall, minion, steward, tribute, ambassador, cutpurse, embargo, outpost,
    salvager, sea_hag, treasure_map}; // array containing all 27 card possibilities

    int randHand[MAX_HAND];

    int i;
    int errorFlag;
    SelectStream(2);
    PutSeed(3);

    for (i = 0; i < MAX_HAND; i++) {
        errorFlag = 0;
        int cardIndex;
        cardIndex = floor(Random() * 27); //generates a random value between 0 and 27
        randHand[i] = cards[cardIndex]; //randomly assigns a card to the hand

        if (randHand[i] == curse) {
#if (NOISY_TEST == 1)
            printf("Cost of Curse Card = %d, expected = 0\n", getCost(randHand[i]));
/*
Values from getCost() function are then compared with cost value obtained directly from
Dominion specification (websites that list the cost of each card). If cost values don't
match, error message is trigger and the error flag is set.
*/
            if (getCost(randHand[i]) != 0) {
                printf("Cost of Curse card returned by getCost() is incorrect");
                errorFlag = 1;
            }
#endif
        }

        if (randHand[i] == estate) {
#if (NOISY_TEST == 1)
            printf("Cost of estate card = %d, expected = 2\n", getCost(randHand[i]));
            if (getCost(randHand[i]) != 2) {
                printf("Cost of estate card returned by getCost() is incorrect");
                errorFlag = 1;
            }
#endif
        }

        if (randHand[i] == duchy) {
#if (NOISY_TEST == 1)
            printf("Cost of duchy card = %d, expected = 5\n", getCost(randHand[i]));
            if (getCost(randHand[i]) != 5) {
                printf("Cost of duchy card returned by getCost() is incorrect");
                errorFlag = 1;
            }
#endif
        }

        if (randHand[i] == province) {
#if (NOISY_TEST == 1)
            printf("Cost of province card = %d, expected = 8\n", getCost(randHand[i]));
            if (getCost(randHand[i]) != 8) {
                printf("Cost of province card returned by getCost() is incorrect");
                errorFlag = 1;
            }
#endif
        }

        if (randHand[i] == copper) {
#if (NOISY_TEST == 1)
            printf("Cost of copper card = %d, expected = 0\n", getCost(randHand[i]));
            if (getCost(randHand[i]) != 0) {
                printf("Cost of copper card returned by getCost() is incorrect");
                errorFlag = 1;
            }
#endif
        }

        if (randHand[i] == silver) {
#if (NOISY_TEST == 1)
            printf("Cost of silver card = %d, expected = 3\n", getCost(randHand[i]));
            if (getCost(randHand[i]) != 3) {
                printf("Cost of silver card returned by getCost() is incorrect");
                errorFlag = 1;
            }
#endif
        }

        if (randHand[i] == gold) {
#if (NOISY_TEST == 1)
            printf("Cost of gold card = %d, expected = 6\n", getCost(randHand[i]));
            if (getCost(randHand[i]) != 6) {
                printf("Cost of gold card returned by getCost() is incorrect");
                errorFlag = 1;
            }
#endif
        }

        if (randHand[i] == adventurer) {
#if (NOISY_TEST == 1)
            printf("Cost of adventurer card = %d, expected = 6\n", getCost(randHand[i]));
            if (getCost(randHand[i]) != 6) {
                printf("Cost of adventurer card returned by getCost() is incorrect");
                errorFlag = 1;
            }
#endif
        }

        if (randHand[i] == council_room) {
#if (NOISY_TEST == 1)
            printf("Cost of council_room card = %d, expected = 5\n", getCost(randHand[i]));
            if (getCost(randHand[i]) != 5) {
                printf("Cost of council_room card returned by getCost() is incorrect");
                errorFlag = 1;
            }
#endif
        }

        if (randHand[i] == feast) {
#if (NOISY_TEST == 1)
            printf("Cost of feast card = %d, expected = 4\n", getCost(randHand[i]));
            if (getCost(randHand[i]) != 4) {
                printf("Cost of feast card returned by getCost() is incorrect");
                errorFlag = 1;
            }
#endif
        }

        if (randHand[i] == gardens) {
#if (NOISY_TEST == 1)
            printf("Cost of gardens card = %d, expected = 4\n", getCost(randHand[i]));
            if (getCost(randHand[i]) != 4) {
                printf("Cost of gardens card returned by getCost() is incorrect");
                errorFlag = 1;
            }
#endif
        }

        if (randHand[i] == mine) {
#if (NOISY_TEST == 1)
            printf("Cost of mine card = %d, expected = 5\n", getCost(randHand[i]));
            if (getCost(randHand[i]) != 5) {
                printf("Cost of mine card returned by getCost() is incorrect");
                errorFlag = 1;
            }
#endif
        }

        if (randHand[i] == remodel) {
#if (NOISY_TEST == 1)
            printf("Cost of remodel card = %d, expected = 4\n", getCost(randHand[i]));
            if (getCost(randHand[i]) != 4) {
                printf("Cost of remodel card returned by getCost() is incorrect");
                errorFlag = 1;
            }
#endif
        }

        if (randHand[i] == smithy) {
#if (NOISY_TEST == 1)
            printf("Cost of smithy card = %d, expected = 4\n", getCost(randHand[i]));
            if (getCost(randHand[i]) != 4) {
                printf("Cost of smithy card returned by getCost() is incorrect");
                errorFlag = 1;
            }
#endif
        }

        if (randHand[i] == village) {
#if (NOISY_TEST == 1)
            printf("Cost of village card = %d, expected = 3\n", getCost(randHand[i]));
            if (getCost(randHand[i]) != 3) {
                printf("Cost of village card returned by getCost() is incorrect");
                errorFlag = 1;
            }
#endif
        }

        if (randHand[i] == baron) {
#if (NOISY_TEST == 1)
            printf("Cost of baron card = %d, expected = 4\n", getCost(randHand[i]));
            if (getCost(randHand[i]) != 4) {
                printf("Cost of baron card returned by getCost() is incorrect");
                errorFlag = 1;
            }
#endif
        }

        if (randHand[i] == great_hall) {
#if (NOISY_TEST == 1)
            printf("Cost of great_hall card = %d, expected = 3\n", getCost(randHand[i]));
            if (getCost(randHand[i]) != 3) {
                printf("Cost of great_hall card returned by getCost() is incorrect");
                errorFlag = 1;
            }
#endif
        }

        if (randHand[i] == minion) {
#if (NOISY_TEST == 1)
            printf("Cost of minion card = %d, expected = 5\n", getCost(randHand[i]));
            if (getCost(randHand[i]) != 5) {
                printf("Cost of minion card returned by getCost() is incorrect");
                errorFlag = 1;
            }
#endif
        }

        if (randHand[i] == steward) {
#if (NOISY_TEST == 1)
            printf("Cost of steward card = %d, expected = 3\n", getCost(randHand[i]));
            if (getCost(randHand[i]) != 3) {
                printf("Cost of steward card returned by getCost() is incorrect");
                errorFlag = 1;
            }
#endif
        }

        if (randHand[i] == tribute) {
#if (NOISY_TEST == 1)
            printf("Cost of tribute card = %d, expected = 5\n", getCost(randHand[i]));
            if (getCost(randHand[i]) != 5) {
                printf("Cost of tribute card returned by getCost() is incorrect");
                errorFlag = 1;
            }
#endif
        }

        if (randHand[i] == ambassador) {
#if (NOISY_TEST == 1)
            printf("Cost of ambassador card = %d, expected = 3\n", getCost(randHand[i]));
            if (getCost(randHand[i]) != 3) {
                printf("Cost of ambassador card returned by getCost() is incorrect");
                errorFlag = 1;
            }
#endif
        }

        if (randHand[i] == cutpurse) {
#if (NOISY_TEST == 1)
            printf("Cost of cutpurse card = %d, expected = 4\n", getCost(randHand[i]));
            if (getCost(randHand[i]) != 4) {
                printf("Cost of cutpurse card returned by getCost() is incorrect");
                errorFlag = 1;
            }
#endif
        }

        if (randHand[i] == embargo) {
#if (NOISY_TEST == 1)
            printf("Cost of embargo card = %d, expected = 2\n", getCost(randHand[i]));
            if (getCost(randHand[i]) != 2) {
                printf("Cost of embargo card returned by getCost() is incorrect");
                errorFlag = 1;
            }
#endif
        }

        if (randHand[i] == outpost) {
#if (NOISY_TEST == 1)
            printf("Cost of outpost card = %d, expected = 5\n", getCost(randHand[i]));
            if (getCost(randHand[i]) != 5) {
                printf("Cost of outpost card returned by getCost() is incorrect");
                errorFlag = 1;
            }
#endif
        }

        if (randHand[i] == salvager) {
#if (NOISY_TEST == 1)
            printf("Cost of salvager card = %d, expected = 4\n", getCost(randHand[i]));
            if (getCost(randHand[i]) != 4) {
                printf("Cost of salvager card returned by getCost() is incorrect");
                errorFlag = 1;
            }
#endif
        }

        if (randHand[i] == sea_hag) {
#if (NOISY_TEST == 1)
            printf("Cost of sea_hag card = %d, expected = 4\n", getCost(randHand[i]));
            if (getCost(randHand[i]) != 4) {
                printf("Cost of sea_hag card returned by getCost() is incorrect");
                errorFlag = 1;
            }
#endif
        }

        if (randHand[i] == treasure_map) {
#if (NOISY_TEST == 1)
            printf("Cost of treasure_map card = %d, expected = 4\n", getCost(randHand[i]));
            if (getCost(randHand[i]) != 4) {
                printf("Cost of treasure_map card returned by getCost() is incorrect");
                errorFlag = 1;
            }
#endif
        }

    }

    if (errorFlag == 0) {
        printf("\nAll tests have passed\n");
    }

    return 0;

}
