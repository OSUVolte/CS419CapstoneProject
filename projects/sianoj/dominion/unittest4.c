//Jessica Siano
//CS362 Software Development 2
//Testing the isGameOver function

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>

int main(){
	struct gameState gS;

	int prov, i, card, s = 0, result;

	SelectStream(2);
	PutSeed(3);

	printf("\n\nTesting the isGameOver() function\n\n");

	//test that the game ends when the pile of provinces is empty
	for(prov = 0; prov < 3; prov++){
		for(i = 0; i < sizeof(struct gameState); i++)
			((char*)&gS)[i] = random() % 256;

		gS.supplyCount[province] = prov;

		result = isGameOver(&gS);

		if(gS.supplyCount[province] == 0){
			if(result == 0)
		 		printf("Test 1 passed - the isGameOverFunction was called successfully\n");
			else{
				printf("Test 1 failed - the isGameOverFunction was not called successfully\n");
				printf("\n\nTest for isGameOver() complete.\n\n");
				return 0;
			}
		}

		for(card = 0; card <= treasure_map; card++)
			if(gS.supplyCount[card] == 0)
				s++;

		if(s >= 3 && result != 1)
			printf("Test 2 failed - the game should have been over.\n");
		else
			printf("Test 2 passed - game exited successfully.\n");				
		
	}

	printf("\n\nTest for isGameOver() complete.\n\n");
        return 0;
}
