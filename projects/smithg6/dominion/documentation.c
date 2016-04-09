/*
Grant Smith
CS362
Assignment2 Documentation
*/

/* SMITHY 
The smithy card, when played triggers a conditional
 loop that terminates after three cards have been drawn.
*/

/* ADVENTURER
The adventurer card first initiates a loop that terminates once two
cards matching any of "copper, silver, gold" are drawn.The first
step in the loop is to check if the deck is empty, if so, the current
player property of the state struct shuffles their deck. One card 
per iteration is then drawn and checked for a matching treasure name.
If a match is found, the drawntreasure index is incremented and the 
drawn card is added to the player's hand. If a match is not found,
the card drawn is placed into a temphand array until the drawntreasure
loop is complete. Once complete, the temphand array is decremented
down to 0, discarding each temporarily stored card along the way. 
*/

/* discardCard() 
Each time discardCard is called, it is passed:
 -the current handPos in the current player's hand
 -the current player
 -the game state struct
 -a trash flag

When the function is called, the first action is to check if the 
trash flag is set. If it is not, then the card is sent to the 
top of the playedCardCount array.

Next, the current player's hand position index array is decremented 
by 1 and an if-else statement decision is entered to determine the
final action. The first two checks are to see if the card was that
players last, but both result in the handCount decrementing by 1.
The last option defaults to dealing with an empty hand by setting
the last discarded card to the final card in hand and decrementing
(discarding) that card.

*/

/* updateCoins()
This function is passed a player, gamestate struct, and bonus value
to add the appropriate amount of coins. First an index (i) is set
to traverse the players coins in hand.
A for loop is then entered that will terminate after iterations
equal to the handCount of the current player. Each matching card is 
checked against the treasure name, and the state->coins value sum
is increased by the appropriate amount, followed by a check after the
loop to add any bonus value passed into the function, finally returning
0 with a successful completion.
*/