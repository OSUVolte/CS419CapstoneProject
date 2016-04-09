/***********************************************************************************************
*Ben Fisher
*Cards modified adventurer, feast, remodel, smithy, and tribute
*
*myAdventurer
*Added a logic bug where cardDrawn is assigned gold instead of checking for equality
*if (cardDrawn == copper || cardDrawn == silver || cardDrawn = gold)
*
*myFeast
*Added a logic bug where current player + 1 has their coins updated instead of the current player
*updateCoins(++currentPlayer, state, 5);
*
*myRemodel
*Added logic bug where the card will not get discarded
*if (state->hand[currentPlayer][i] == --j)
*
*mySmithy
*Added logic bug set trash flag to 1 in call to discardCard function
*discardCard(handPos, currentPlayer, state, 1);
*
*myTribute
*Added logic bug where nextPlayer is initialized to current player
*int nextPlayer = currentPlayer;
************************************************************************************************/