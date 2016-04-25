/*
 *Created By Sam Schultz
 Date: 4/10/2016
 Refactor.c

--------------------------------- Refactor Documentation -------------------------------------------------------
 *
 *playSmithy():
 Inputs: struct gameState *state: game state struct.
 int handPos: Hand posistion of Smithy.
 Returns 1 if correct -1 if hand is full.

The function checks to see if the hand can take more cards then draws 3 cards using drawCard(). After the cards are drawn the played smithy card is discarded.

Bugs: No checks to see if the deckCount has 3 cards in it. No reshuffle of discard pile if deck has less than 3 cards. No increase of handCount in state. 

 playAdventurer():
Input: struct gameState *state
Returns 0

Draws cards from deck until 2 treasure cards have been drawn then places all other drawn cards into the discard pile.

Known Bugs: No deck state check. No reshffle if there are no more cards in the deck.


 playRemodel():
Inputs: struct gameState *state: state struct.
int handPos: Hand posistion of Remodel.
int choice1: card to be trashed.
int choice2: card to be gained.
Returns 0

Player picks a card to trash which is choice 1, then the player is able to gain a new card of 2+the cost of choice1 and is stored as choice2.

Known Bugs: Currently no checks for supplyCount of card gained. No check for if the card gained is within the cost range. No hand state management such as #discarded.

playVillage():
Inputs: struct gameState *state: state struct.
int handPos: posisition of Village in hand.

When the player plays this card they draw a card and also increase state->numActions by 2.

Known Bugs: when this card is played insteas of discarding to the discard pile it is discarded to the trashed pile.

playGreat_hall():
Inputs: struct gameState *state, int handPos

The player who plays this card draws a card using drawCard() and increase # of state->numActions by 1.

Known Bugs: No known Bugs at this time. 
  
