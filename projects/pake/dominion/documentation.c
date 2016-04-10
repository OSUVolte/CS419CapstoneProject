/*

Name: Eugene Pak
Course: CS362 Spring 2016
Assignment 2 - documentation.c

Smithy – This is an action card that draws 3 additional cards to the player’s hand.  This action is
accomplishedby calling the drawCard function three times to add to the player’s hand and then calling
the discardCard todiscard the Smith card.

Adventurer – This is an action card that removes cards from the player’s hand until 2 treasure cards
are revealed. A loop checks if less than 2 treasure cards has been drawn, then it will check if the
deck is empty. If so, it will reshuffle the deck. Next it calls the drawCard function to draw a card
and if it’s a treasure card, increments drawnteasure. The non-treasure cards are placed into pile to
be discarded.

discardCard() – This function deals with cards discarded by the player. It can either be removed from
the hand and trashed, or moved into a discard pile and have its state set to -1. handCount keeps track
of the number of cards in the player’s hand.
 
updateCoins() – This function keeps track of treasure cards in a player’s hand and counts the number
of corresponding coins. It checks for copper, silver, and gold and adds the number of coins for each
in the hand.

*/