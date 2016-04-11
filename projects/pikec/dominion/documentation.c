smithy - during the action phase of the game. If the current player choses this card, 3 additional 
cards will be drawn from the players deck and placed in his/her current hand.
The smithy card will be discarded from the current hand.

adventurer - If this card is in the players current hand and is played during the action phase, this card will inatiate a loop where
cards are drawn from the players deck and placed in the current hand if the card is a treasure card. 
The loop runs until 2 treasure cards are placed in the current hand. Before starting the draw from deck the loop checks for cards in the deck
if none are present the discard pile is shuffled and used as the deck.

discard() - function removes a card fom the current hand. Function has a discard flag, if the flag is set to < 1
the current card is placed into the played pile. Otherwise remove the last card in the current players hand 
and reduce the current hand count. If there is only one card in the hand, change the hand count to zero.
Else replace the disacarded card with the next card in the hand and decreas the current card count by 1.

update_coin() - function gives the current coin balance of the current hand. Starts by zeroing out any 
previous coin balance. Then loops through the hands looking for gold, silver, and copper coin cards. Adds 
the denomination of those cards if found. Finally, if there is any bonus coins for the round they are applied to the 
total.