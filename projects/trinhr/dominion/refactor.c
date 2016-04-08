smithyCard()
--The loop will run five times instead of three so it will draw five cards
instead of three.  

adventurerCard()
--After the drawn card function, the drawntreasures variable is incremented by one. Thus 
the while loop will only run once or twice at most. There will be two different scenarios. 
It'll run once after the player draws one card and the  the first card is a treasure card. 
It'll run twice after the player draws two cards regardless if there were treasure cards
or not.

villageCard()
--This card is supposed to allow the player to draw one card and allot them two additional actions.
 However, this will reset the number of actions to two, without accounting for any other action bonuses 
or other action points they might have accumulated previously.
Original: state->numActions = state->numActions + 2;
Edit: state->numActions = 2;
