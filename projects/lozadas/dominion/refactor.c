/*
********Refactoring changes*********

1.Implemented function for adventurer card: int adventurerCard(int drawntreasure, struct gameState *state,int currentPlayer,int cardDrawn, int z,int temphand[MAX_HAND])2.
2.Implemented function for smithy card:int remodelCard(int currentPlayer,struct gameState *state,int choice1,int choice2,int handPos)
3.Implemented function for council_room card:int council_roomCard(int currentPlayer,struct gameState *state,int handPos)4.Implemented 4.Implemented function for cutpurse card: int cutpurseCard(int currentPlayer,struct gameState *state,int handPos)
5.Implemented function for remodel card: int remodelCard(int currentPlayer,struct gameState *state,int choice1,int choice2,int handPos)

*********Bugs introduced**************

Adventurer:
	-Reveal cards until one treasure card is drawn.
	-Not counting gold as a treasure card.
Smithy:
	-Draw only two cards from deck.

Council_room:
	-i is not initialized to zero.
	-Draw only three cards from deck instead of four.

Cutpurse:
	-i,j,k are not initialized to zero.
	-i==current current player discards a copper card or reveals a hand with no copper.
*/
