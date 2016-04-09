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
