Jacob McMillen
CS 362 - Assignment 2
10 April 2016

Changes to dominion.c

Functionality for the following 5 cards was removed from cardEffect() and placed into individual functions:
1. adventurer
2. smithy
3. village
4. remodel
5. council room

Bugs were introduced into these five functions for the purpose of testing. See notes below for details on each refactored function, including information on the added bugs.

int playAdventurer(struct gameState *state)	

	Parameters: current state of game

	Effect: Reveal cards from deck until 2 treasure cards have been revealed. Place the 2 treasure cards into hand and discard other revealed cards.
	
	Notes: the integer variables drawnTreasure, cardDrawn, and z were removed from the cardEffect() function and placed in playAdventurer() function since they are unique to the adventurer card.
	
	Bug introduced: adventurer only counts copper and silver as treasure cards, but it should also count gold.
	

int playSmithy(struct gameState *state, int handPos){
	Parameters: current state of game, position in hand of played smithy card

	Effect: current player gets +3 cards; played smithy card is discarded from hand.
	
	Bug introduced: In addition to giving +3 cards, the smithy card provides +1 action after it is played, which it should not.


int playVillage(struct gameState *state, int handPos)	
	Parameters: current state of game, position in hand of played village card

	Effect: current player gets +1 card and +2 actions; played village card is discarded from hand.	

	Bug introduced: The village now only supplies +1 card and +1 action instead of the +1 card and +2 actions it should.

	
int playRemodel(struct gameState *state, int handPos, int choice1, int choice2){
	Parameters: current state of game, position in hand of played villed cardEffect, choice1 of card to be trashed, choice2 of card to be gained.

	Effect: current player trashes a card and gains a card costing up to 2 more than the trashed card; played remodel card is discarded from hand.
	
	Notes: a new local copy of the variable int j used to store card to be trashed is created in the refactored function. The variable j also remains in cardEffect since other cards still use it, but it can later be removed if all relevant cards are refactored into separate functions.

	Bug introduced: The card that is marked to be trashed in now only discared and the remodel card, which should be discarded, is now trashed.
	
	
int playCouncil_Room(struct gameState *state, int handPos)
	Parameters: current state of game, position in hand of played council room card

	Effect: current player gets +4 cards and +1 buy; each other player gets +1 card; played council room card is discarded from hand.
	
	Bug introduced: Provided a player other than Player0 has played the council room, Player0 no longer gets +1 card as she should.