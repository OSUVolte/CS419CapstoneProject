James Guerra
cs 362 spring 2016
assignment 2

Explaination of functions
 1) int updateCoins(int player, struct gameState *state, int bonus) 
 This functions takes the player number, game state and any applicable coin bonus, then  first creates an 
 empty integer, i, for later use in a for loop.  Next the function resets the coin count, and for each treasure in the player's hand,
via a for loop, adds a number of coins to the count, saved in the pointer state->coins, determined by the type of tresure.  ie 3 for gold.  lastly it adds any bonus to the
 count and saves this number under the pointer state->coins variable and returns 0.       
 
 2) discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)
This function handles the trash for each player.  If the trashflag is <1 then it is added to the player pile and 
the played count is increased by one.  The gameState->hand for the card is set to -1.  
if the card is the last in the players hand, then the number of cards in the players hand is decreased by 1.  
otherwise the last card in the hand is set to -1 and replaces the discarded card and the number of cards in their hand is reduced by 1.       
Explainations of cards

1) 
smithy card

This card when played during the action portion of their turn causes the player to draw three cards from their deck to their hand.  
In the code this works through a for loop which calls the draw card function three times, then discards the smithy card before returning 0.
2)
Adventurer 
This card when played during the action portion of their turn causes the player to see cards from their deck, until 2 treasures are found.  These two tresures are then
moved into the hand of the player, leaving the revealed cards to be discarded along with the adventure card.  
In the code this ensures that the deck is not empty, or shuffles the discarded cards if it is.     
