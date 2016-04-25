/******************************************************************************
** bug1.c 
** Emily Snyder
** Spring 2016
** CS 362-400
** Bugs found by test suite (unittestresults.out)
*******************************************************************************

getCost() - no bugs

shuffle() - no bugs

discard()
  - Cards are never added to the discard pile
  - Cards played is not increased if the trash flag is set.

isGameOver()
  - Game is not ended if one of the empty supply piles is Sea Hag or Treasure
    Map, positions 25 and 26 in the dominion.h CARD enum.

Smithy card
  - Three cards are not drawn from the deck
  - Smithy card is not added to the played card count

Adventurer card
  - All cards in hand are discarded
  - Treasure cards are not added to the hand
  - Played cards is not incremented when there are cards in the hand
  - Played cards is increased too much if the card is played with an empty deck. 

Great Hall card
  - Card is not discarded after play.

Council Room
  - Card is not discarded after play.


