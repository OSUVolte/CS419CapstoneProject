/******************************************************************
 * Carolyn Cheung
 * CS 362
 * Assignment 3
 * Description: Describe any bugs found in unit tests
 ******************************************************************/

 Bugs that were introduced in the refactor were found.
    * GreatHall did not add an extra card to the players hand
    * Adventurer drawnTreasure preset to 1, so only 1 extra treasure was obtained
      instead of 2
    * CouncilRoom every other player did not get to draw an extra card.
    * Smithy card was not discarded from hand
Bugs found
    * scoreFor does not correctly calculate the score. Calculates
      the amount of cards from discardCount for the deck, rather using
      calculating all deckCount for the deck
    * scoreFor uses fullDeckCount for gardens, but it does not count all the
      cards held that the player has.
    * Adventurer does not discard itself after being played
