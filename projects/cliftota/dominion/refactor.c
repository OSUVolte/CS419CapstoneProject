/*

Adventurer Card:   If the deck is empty it should shuffle discarded cards and add to deck.
                   I changed state->deckCount[currentPlayer] < 1; to
                   state->deckCount[currentPlayer] > 1;
				   Now, discarded cards will be shuffled and added to the deck while deck
				   has more then one card.

Smithy Card:       It should add three cards to the player's hand. I changed for (i = 0; i < 3; i++) to 
                   for (i = 0; i <= 3; i++)
				   Now, it add one more card, 4 total.

Minion Card:       It should add one action to the current player. I removed the line state->numActions++;
                   Now, it does not increment the action count.

Remodel Card:      It should store the cards that will be trashed. I changed
                   j = state->hand[currentPlayer][choice1]; to
			       j = state->hand[currentPlayer][choice2];
				   Now, it stores wrong cards that will be trashed.

Council Room Card: It makes each other player draws a card. I changed
                   i != currentPlayer to
				   i == currentPlayer
                   Now, the current player draws a card.
*/