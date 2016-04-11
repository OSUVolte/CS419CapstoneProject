Susan Eldridge
refactor.c
CS 362
Spring 2016

pAdventurer:
I changed temphand[z] to temphand[0], this makes the temphand only contain the current drawn card instead
of all of the drawn cards.
I added smithy to the list of cards that would cause drawnTreasure to increase.
I also changed "state->deckCount[currentPlayer] <1" to "state->deckCount[currentPlayer] <3".  This will
cause the cards to reshuffle early.

pSmithy:
Changed the trash flag to 1.
Also changed the hand position to 1 if the "real" handPos was 2.

pVillage:
Made it so that if the current player was not the last player (before going back to player zero),
the player gets to draw a card.  If they are the last player, they do not.

pGreatHall:
Gave a card to each other player (in addition to the current player).

pRemodel:
Changed the card gained from choice2 to 13 (the enum for Smithy).
