Smithy card:
This card starts out by entering into a loop that lasts exactly 3 interations.
During the loop, the drawCard() function is called, with the currentPlayer and 
state variables as attributes. The function of this loop is for the current
player who's playing the smithy card is drawing three cards. After the cards
have been drawn, aka end of the loop, the discardCard() function is called, 
which discards the smithy card from the players hand. The card concludes by
returning 0 as part of the cardEffect() function.

Adventuer card:
This card begins by entering into a while loop, which will iterate until the
condition drawntreasure<2 is met, which is when the current player draws two
treasure cards. During this loop, it first checks the condition if the deck
becomes empty. If the condition is true, the deck gets shuffled so that the
player can continue drawing cards. The loop then calls drawCard() to draw a
card, then it goes into set of condition statements that checks to see if the 
drawn cards are treasure cards are not. If the drawn card is a treasure card,
it is added to their hand. If it not, it gets added to a temporary hand. As
stated before, the loop continues until the players draws two treasure cards.
Once the loop ends, the card enters another loop that goes through all the 
cards in the temporary hand and discards them. The card will conclude by
returning 0 as part of the cardEffect() function.

discardCard():
The purpose of this function is to discard cards from a player's hand. The
function begins by checking the condition if the card is to be trashed. If it
is not trashed, the card is added to the player's pile of played cards, then
increments the number of cards in the pile. The value of the card is then
changed to -1 to signify that it has been played. The function then goes into
a series of conditional statements that will deal with how to remove the card
from the players hand. If the card was the last card in the players hand or it
was the last card in the hand array, the handCount counter, which represents 
the numbers of cards in the players hand, is decremented by one to remove the 
card from the hand. However, if it mets neither of those conditions, then the
card is removed by first being replaced with the last card in the hand, then
the card at the end of the hand's status is changed to one to signify it as
"played". Finally, the handCount counter is decremented by one to remove that 
last card from the hand. Once the card is removed from the hand, function will
return a value of 0 to its caller, thus ending the function.

updateCoins():
This function updates the coins a player has available to use. It begins by
first resetting the coin counter to zero, so that coins do not get counted 
twice in case they were previously counted. Once the counter is reset, the 
function begins a "for" loop that will look through all the cards in the 
player's hand to find treasure cards. During the loop, if the card is a copper
treasure card, a value of one is added to the coin counter. If the card is a 
silver treasure card, a value of two is added to the coin counter. Or, if the 
card is a gold treasure card, a value of three is added to the coin counter.
Once the loop ends, any bonus coins from the cards that the players played
from his turn are added to the coin counter. Finally, the function ends by
returning a value of 0 to the caller. 
