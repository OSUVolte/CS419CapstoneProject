# Documentation of refractored cards

This file details the refractoring that was done to move the below cards to their own functions and the subtle
bugs that were introduced. There were existing function prototypes for some cards in `dominion.h`, so I have went
ahead and added my own prototypes there and/or reused those that existed for the cards I worked with. 

The prototypes were reworked to include passing the currentPlayer to the function as this is needed for every
card effect.

## General Info

* There were existing prototypes for card effects in dominion.h.  Those were slightly rewritten to fit the 
method signature of existing functions (e.g. gameState goes last, player is first)
* Fixed whitespace, variable capitalizations, and code format to conform with a consistent style in method bodies
that I worked on.
* Alphabetized function order for card effects
* Added comment in the form of `## Effect: ...` to denote card's effect above the function bodies for those card
effects implemented into functions

## Adventurer Card

* Moved Adventurer card effect to own method
* Cleaned up code and whitespace and variable names

** Bug Introduced **

* Created `TREASURES_TO_DRAW` variable and incorrectly set to 3.  This is a red herring as the variable is not used
* Set main while loop to only draw up to 1 treasure instead of 2.  This is where the bug is introduced and causes
less treasures to be drawn for this card.  
* `TREASURES_TO_DRAW` should be set to 2 and used in the while loop.

## Smithy Card

* Moved Smithy card effect to own method
* Cleaned up whitespace and code formatting

** Bug Introduced **

* After Smithy card is played the card before it is discarded rather than the Smithy card.
* `discard(handPos, currentPlayer, state, 0)` becomes discard(handPos-1, currentPlayer, state, 0)`

## Council Room Card

* Moved Councel Room card effect to own method
* Cleaned up whitespace and code formatting

** Bug Introduced **

* Created `NUM_CARDS_TO_DRAW` variable and set to 4
* Variable alludes to the effect where the player that plays the card receives 4 cards
* Variable is used in loop for each other player drawing a card, where instead of them drawing 1 card each of
them will draw 4 cards.

## Feast Card

* Moved Feast card effect to own method
* Renamed variable `x` to `buying`
* Cleaned up code whitespace and comments

## Baron Card

* Moved Baron card effect to own method
* Cleaned up code format and comments

** Bug Introduced**

* Baron card adds 40 treasures to your hand instead of 4 when an estate card is discarded.
* Simply set the incrementer from `state->coins += 4` to `state->coins += 40`
