/*
*******************************************************************************
CHANGES MADE TO DOMINION.C
*******************************************************************************
ADVENTURER - adventurerEffect()
  This function takes two parameters a pointer to a gameState struct and an
  integer holding the current player. The cardEffect function passes these two
  variables when it calls the adventurerEffect function. Four variables have 
  been moved into the adventurerEffect function from the cardEffect function, 
  these are: drawntreasure, cardDrawn, temphand and z.

  Bugs:
    -  This function now only checks if the card drawn is Copper or Silver, 
       instead of also checking for Gold. 
    -  The cardDrawn is set to 2 less than the handCount instead of 1 less, this
       means that it is set to the second from the top card of the hand instead 
       of the top card. 


SMITHY - smithyEffect()
  This function takes three parameters, an integer with the current player, a
  pointer to a gameState struct and an integer with the hand position. These
  three variables are passed by cardEffect. 

  Bugs:
    -  Two cards are drawn instead of three since the iterator is now initialized
       to 1 instead of 0.
    -  The trash flag is set to 1 in discardCard, so the card is trashed instead
       of discarded. 

BARON - baronEffect()
  This function takes three parameters, an integer with the current player, a
  pointer to a gameState struct and an integer with a player's choice (whether 
  they will discard an estate). These values are passed by the cardEffect
  function.  

  Bugs:
    -  The iterator p is set to 2, so the function only begins looking at the 
       second card in the player's hand.
    -  The state of the card is set to 1 after being discarded instead of -1.
    -  In the gain card function the estate and the current player are swapped.

MINION - minionEffect()
  This function takes four parameters, an integer with the current player, a
  pointer to a gameState struct, two integers with each of the two choices and 
  an integer with the position of the current player's hand. The two choices the
  player has is to get +2 coins or to draw 4 cards (and force each of the other
  players who have more than 4 cards to discard their hand and draw four new
  cards).

  Bugs:
    - The choices are swapped, so if a player chooses to get +2 coins they will
      draw 4 cards instead and vice versa.
    - The loop for drawing 4 cards for the current player has been altered to 
      instead draw 5 cards. 

TRIBUTE - tributeEffect()
  This function takes three parameters, integers for both the current player and 
  the next player and a pointer to a gameState struct. All are passed to the 
  function when it is called by cardEffect.  

  Bugs: None added.
*/

