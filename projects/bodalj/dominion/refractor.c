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

## Smithy Card

* Moved Smithy card effect to own method
* Cleaned up whitespace and code formatting

## Council Room Card

* Moved Councel Room card effect to own method
* Cleaned up whitespace and code formatting

## Feast Card

* Moved Feast card effect to own method
* Renamed variable `x` to `buying`
* Cleaned up code whitespace and comments

## Baron Card

* Moved Baron card effect to own method
* Cleaned up code format and comments
