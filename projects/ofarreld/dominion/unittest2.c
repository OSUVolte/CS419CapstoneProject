#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>

#include "testHelper.h"

#define TESTCARD "getCost"

int main() {

	int newCards = 0;
	int discarded = 1;
	int newCoins = 0;
	int shuffledCards = 0;
	int a = 0, b = 0, c= 0;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int remove1, remove2;
	int seed = 1000;
	int numPlayers = 2;
	int thisPlayer = 0;
	int otherPlayer = 1;
	int found = 0;

	int allCards[27] = {curse, estate, duchy, province, copper, silver, gold, adventurer, 
		council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall, 
		minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, 
		sea_hag, treasure_map};
	int allCosts[27] = {0, 2, 5, 8, 0, 3, 6, 6, 5, 4, 4, 5, 4, 4, 3, 4, 3, 5, 3, 5, 3, 4, 2, 
		5, 4, 4,4};
	const char *card[27];
	card[0] = "curse"; 
	card[1] = "estate"; 
	card[2] = "duchy"; 
	card[3] = "province"; 
	card[4] = "copper"; 
	card[5] = "silver"; 
	card[6] = "gold"; 
	card[7] = "adventurer"; 
	card[8] = "council_room"; 
	card[9] = "feast"; 
	card[10] = "gardens"; 
	card[11] = "mines"; 
	card[12] = "remodel"; 
	card[13] = "smithy"; 
	card[14] = "village"; 
	card[15] = "baron"; 
	card[16] = "great_hall"; 
	card[17] = "minion"; 
	card[18] = "steward"; 
	card[19] = "tribute"; 
	card[20] = "ambassador"; 
	card[21] = "cutpurse"; 
	card[22] = "embargo"; 
	card[23] = "outpost"; 
	card[24] = "salvager"; 
	card[25] = "sea_hag"; 
	card[26] = "treasure_map"; 
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room};
	
	initializeGame(numPlayers, k, seed, &G);

	printf("\t Testing Card: %s \n", TESTCARD);
	// boot up the perfect version
	memcpy(&testG, &G, sizeof(struct gameState));
	// Test 01 -----------------------------------------------------------------

	printf("Testing return values for all cards...\t");	
	while (a < (sizeof(allCards) / sizeof(int))) {
		if (allCosts[a] != getCost(allCards[a])) {
			printf("ERROR\n");
			printf("%s: cost %d, expected %d\n" ,card[a], allCosts[a], getCost(allCards[a]));
			found = 1;
		}
		a++;
	}
	if ( found == 0) {
		printf("PASS\n");
	}

	genericTest(G, testG, otherPlayer, 0);

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
	return 0;
}




