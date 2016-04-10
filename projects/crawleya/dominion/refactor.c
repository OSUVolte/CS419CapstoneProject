refactor.c
This is documentation of changes for Assignment 2: Choose 5 cards and refactor the code so that these cards are implmeented in their own functions, rather than as part of the switch statement in cardEffect(). The implmentation of at least 4 of these 5 cards should be incorrect in some way.

The 5 cards that I chose to refactor:

1. Smithy
2. Adventurer
3. Village
4. Great Hall
5. Council Room

*********
1. Smithy

Function: int doSmithy(struct gameState *state, int handPos, int currentPlayer)

Description: This function will add three cards to the current player's current hand and then discard the smithy card.

Parameters: the state of the game, the position of the card in the hand, and the current player.

Postcondition: The state of the game will show three additional cards in the current player's current hand.

Return Value: 0

Bug introduced: In the for loop, changed < to <= so 4 cards will be added to the player's hand instead of 3
**********

**********
2. Adventurer

Function: int doAdventurer(struct gameState *state, int handPos, int currentPlayer)

Description: This function will add cards to the current player's current hand until two treasure cards are revealed. Those two treasure cards will remain in the hand, while the other cards that were revealed will be discarded.

Parameters: the state of the game, the position of the card in the hand, and the current player

Postcondition: The state of the game will be updated to show two additional treasure cards in the current player's current hand.

Return value: 0

Bug introduced: In the switch statement, under case adventurer, the function is called, but nothing is returned. The line is "doAdventurer(state, handPos, currentPlayer)" but it should be "return doAdventurer(state, handPos, currentPlayer)". Also, in the first while loop, <2 was changed to <=2 so that 3 Treasure Cards will be added (instead of 2).
**********

**********
3. Village

Function: int doVillage(struct gameState *state, int handPos, int currentPlayer)

Description: This function will add one card to the current player's current hand, give the player an extra 2 actions, and then discard the Village card from the player's hand

Parameters: the state of the game, the position of the card in the hand, and the current player.

Postcondition: The state of the game will show an extra card in the player's current hand, and the player will have an additional 2 actions.

Return Value: 0

Bug introduced: Changed line state->numActions = state->numActions + 2 to state->numActions++ so only one additional action will be added.
************

**********
4. Great Hall

Function: int doGreatHall(struct gameState *state, int handPos, int currentPlayer)

Description: This function will add one card to the current player's hand, give the player an extra action, and then discard the card from the player's hand.

Parameters: the state of the game, the position of the card in the hand, and the current player.

Postcondition: The state of the game will show an extra card in the player's current hand, and the player will have an additional action.

Return value: 0

Bug introduced: Set the trashFlag flag in the call to discardCard so that the card will be trashed instead of put in the played card pile. discardCard(handPos, currentPlayer, state, 1) should be discardCard(handPos, currentPlayer, state, 0)
**********

**********
5. Council Room

Function: int doCouncilRoom(struct gameState *state, int handPos, int currentPlayer)

Description: This function will add 4 cards to the current player's hand, give the player an extra buy, have all other players draw an extra card, and then discard the Council Room card from the player's hand

Parameters: the state of the game, the position of the card in the hand, and the current player

Postcondition: The state of the game will show 4 extra cards in the current player's hand, an additional buy for the current player, and each other player will have an extra card in their hand.

Return value: 0

Bugs introduced: There is a loop for all players (except the current) to draw an additional card. The line "if (i != currentPlayer)" was modified to "if (i == currentPlayer)," with the consequence that the current player will have 5 extra cards instead of 4, and the other players will have 0 extra cards instead of 1.
