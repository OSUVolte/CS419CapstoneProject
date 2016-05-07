/******************************************************************************
** Filename: randomhistory.c
** Emily Snyder
** Spring 2016
** CS 362-400
** Random testing documentation 
******************************************************************************* 

Adventurer
  
  The random tests for the Adventurer card starts by initializing the game with
  a random number of players. A random number of treasure cards is then selected
  and placed in the current player's deck at random positions. Each treasure card
  is also randomly selected from the three options: copper, silver, and gold. 
  The Adventurer card is then played and the resulting game state is compared to
  see if the correct actions were taken by the card. This test process occurs
  10,000 times.

  The only changes that should be made to the state of the game is that
  the current player should draw how many cards are necessary to get 2 treasure
  cards from their deck. Those two cards are added to their hand and all other
  drawn cards are discarded. 

  After running the random tests, the coverage is as follows:
    Function 'adventurerEffect'
    Lines executed:100.00% of 17
    Branches executed:100.00% of 10
    Taken at least once:100.00% of 10
    Calls executed:100.00% of 2

  Bugs found:
    1. When 0 treasure is in the deck:
         - 1 card that is drawn from the deck remains in the hand instead of 
           being discarded
         - No cards are added to the players discard pile, they are moved to 
           the played card pile 
    2. Multiple treasure cards (all combinations) 
         - Incorrect number of cards in the hand, somtimes too many, some times
           too few, not consistent
    3. When gold cards are added
         - Too many cards are drawn from the deck
         - When only gold cards are present, the entire deck is drawn

  I originally had planned on selecting a random player to play the adventurer
  card, but decided that it would have required more complex initialization and
  would not improve the coverage. However, adding the random selection of the
  type of treasure card let me find the bug that occured when gold cards were
  present.

Minion

  The random tests for the Minion card starts by initializing the game with a
  random number of players. It then sets the number of actions to a random number
  from 0 - 9 and randomly selects either CHOICE 1 or CHOICE 2. The position
  of the card is also randomly selected in the player's hand. Then all of the 
  other players in the game are given a hand of a random size full of random
  cards.

  The state of the game after the Minion card is played should depend upon the
  choice the player makes. If the CHOICE 2 is selected, nothing should change for
  any of the other players, but the number of actions should increase by 1 and the
  player gains two coins. If CHOICE 1 is selected, the number of actions is 
  increased by 1 and the current player discards their hand and gets 4 new cards.
  All other players with 5 or more cards in their hand must also discard and
  draw 4 new cards.

  After running the random tests, the coverage is as follows:
    Function 'minionEffect'
    Lines executed:100.00% of 18
    Branches executed:100.00% of 18
    Taken at least once:94.44% of 18
    Calls executed:100.00% of 6

  Bugs found:
    1. When CHOICE 1 is played, the player who plays it ends up with 5 cards in
       their hand instead of 4.
    2. All cards from hands that must be discarded and redrawn should be moved
       to the played card pile, but only a portion do so. 

  By adding in the random hand counts for the other players, I was able to learn
  more about the disard bug. If CHOICE 2 is selected (and the player only disards
  the current card) that card is moved to the played card pile. However, if
  multiple players discard their hands, cards are moved to the played card pile
  but not in the correct quantities.    

*/
