// Osbaldo Esquivel
// CS 362
// 10APR2016
// Assignment 2

The five cards I picked are the following:
	1. Smithy
	2. Adventurer
	3. Remodel
	4. Mine
	5. Council Room
	
The functions I added to dominion.h:
	int adventurerPlay(int drawntreasure, struct gameState *state, int currentPlayer, int cardDrawn,
		int temphand[], int z);
	int smithyPlay(struct gameState *state, int handPos, int currentPlayer);
	int councilRoomPlay(int currentPlayer, struct gameState *state, int handPos);
	int minePlay(int j, struct gameState *state, int choice1, int choice2, int currentPlayer, int handPos);
	int remodelPlay(int j, struct gameState *state, int choice1, int choice2, int currentPlayer, int handPos);

The bugs that I have added to dominion.c are as follows:

	1. In remodelPlay:

		The for loop should like like this:
			for(i = 0; i < state->handCount[currentPlayer]; i++) {
				if(state->hand[currentPlayer][i] == j) {
					discardCard(i,currentPlayer,state,0);
					break;
				}
			}
			
		The bug is to add one position to the hand position for the game state:
			for(i = 0; i < state->handCount[currentPlayer]; i++) {
				if(state->hand[currentPlayer][i+1] == j) {
					discardCard(i,currentPlayer,state,0);
					break;
				}
			}
			
	2. In minePlay:

		The first if statement should read like this:
			if(state->hand[currentPlayer][choice1] < copper || state->hand[currentPlayer][choice1] > gold) {
				return -1;
			}
			
		The bug is to change the evaluation to >=:
			if(state->hand[currentPlayer][choice1] < copper || state->hand[currentPlayer][choice1] >= gold) {
				return -1;
			}
			
	3. In councilRoomPlay:

		The first for loop should read like this:
			for(i = 0; i < 4; i++) {
				drawCard(currentPlayer,state);
			}
			
		The bug is to make the loop exit when it equals 4 instead of 3:
			for(i = 0; i <= 4; i++) {
				drawCard(currentPlayer,state);
			}
			
	4. In adventurerPlay:

		The last while loop should look like this:
			while(z - 1 >= 0) {
				state->discard[currentPlayer][state->discardCount[currentPlayer]++] = temphand[z - 1];
				z = z - 1;
			}
			
		The bug is to make the loop true while z is greater than or equal to 0 instead of z - 1:
			while(z >= 0) {
				state->discard[currentPlayer][state->discardCount[currentPlayer]++] = temphand[z - 1];
				z = z - 1;
			}