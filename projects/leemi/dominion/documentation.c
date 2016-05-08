/*************************************************
 * Michael Lee   
 * CS362    
 * Assignment 2
 *************************************************/

//Smithy Card understanding

The Smithy card allows the player to draw three extra cards and then it  calls dicardhand to discard itself.


//Adventure Card understanding
The adventure card draws cards until they get two treasure cards. The case loops until this condition is met and it will reshuffle the discard pile if the deck is empty. Finally the cards that aren't treasure cards are all put into the discard pile.

//discardCard() understanding
input: handpos, player, gamestate, trashflag
output: returns nothing
description: Removes card from player hand (takes out of play),card is trashed if trashflag is >=1, number of cards in hand is decremented, next card is put up for play

either the card in play goes to the trash pile or the discard pile and the player gets the next card in his hand.

//updateCoins() understanding

input: player, gamestate, bonus
output: returns nothing (updates state)
description: adds coins based on the treasures in the players hands; the players purchasing power

when the player has a new hand he can purchase with his coins: copper, silver, gold. He can also get a bonus from the card he plays.



