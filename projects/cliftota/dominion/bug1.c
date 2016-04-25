/***************************************************************************
                           FUNCTIONS:
****************************************************************************
	isGameOver():
	One bug was found in the code:
		for (i = 0; i < 25; i++){
			if (state->supplyCount[i] == 0){
			j++;
			}
		}
	It does not check the pile of sea_hag and tresure_map cards.
	25 should be 27.


	gainCard():
	No bugs were found


	scoreFor():
	One bug was found in the code:
		for (i = 0; i < state->discardCount[player]; i++){
			  if (state->deck[player][i] == curse) { score = score - 1; };
			  if (state->deck[player][i] == estate) { score = score + 1; };
			  if (state->deck[player][i] == duchy) { score = score + 3; };
			  if (state->deck[player][i] == province) { score = score + 6; };
			  if (state->deck[player][i] == great_hall) { score = score + 1; };
			  if (state->deck[player][i] == gardens) { score = score +
                                    ( fullDeckCount(player, 0, state) / 10 ); };
		}
	It loops based on the discard count not based on the deck count.
	state->discardCount[player] should be state->deckCount[player]


	fullDeckCount():
	No bugs were found

***************************************************************************
                                    CARDS:
***************************************************************************
    smithy:
        One bag was found. It was the bag introduced in the previous assignment.
        It should add three cards to the player's hand. It adds four.
        As a result, deck also has one card less than expected.
        for (i = 0; i <= 3; i++) should be for (i = 0; i < 3; i++)


    adventurer:
        Some bags were found. The deck count was not accurate.
        The played count was not increased.
        The number of treasure cards in hand after playing adventure
        was not accurate. The player does not receive exactly 2 cards.
        The bag that was introduced in the previous assignment was
        not found due to other bags presence. Some of the bags may be cause
        the absence of calling the discardCard method.


    village:
        No bugs were found


    great_hall:
        No bugs were found
***************************************************************************/

