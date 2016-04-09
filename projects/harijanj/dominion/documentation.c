/*
1. Smithy card

The Smithy card allows a player to draw 3 cards from deck.
From the code perspective, to implement Smithy is to use a for loop 
to call drawCard function 3 times. After that, discardCard function 
is called to discard Smithy card from player's hand.


2. Adventurer card

The Adventurer card makes a player keep drawing card until he/she
obtains 2 Treasure cards (example: cooper, silver and gold) in hand.
After that, the player has to discard all the drawn but non-treasure cards.
From the code perspective, a while loop with condition drawntreasure < 2
is used. Inside the loop, first there is an if statement to check whether
the deck is empty or not. It will shuffle the discard and add to deck. Afterwards,
it will keep calling drawCard function and compare the drawn card with cooper, silver
or gold. If yes, then it will increase the drawntreasure value by 1. If not, it will
be stored in temphand with unique index z. Finally, if player gets 2 treasure cards, 
the index stored in temphand indicates which cards need to be discarded.

3. discardCard()

In game, basically this function moves card from user's hand into discard pile.
From the code perspective, there is a flag called trashFlag that will check whether
to put the card in discard pile or trash pile (they are different!). After that, it
will set value of player card to -1, indicating that particular card can't be used
again. Then it starts removing cards from player's hand. If it reaches player's last card
or only card, then just decrease hand counter by 1. Other than that (else), replaced 
discarded card with last card in hand and decrease hand counter by 1.

4. updateCoins()

This function is called when user clicked "playedtreasure" in the desktop game.
User laydowns all his/her treasure cards from hands and sums all them.
From the code perspective, first it resets the value of coins to make sure
it starts from zero. Then using for loop with range of user's handcard, 
it compares the name and adds the value (1, 2, or 3) into coins. Some cards 
have effect to give bonus coins, this adds up to coins after it sums all coins
in user's hand.

By Jonathan Harijanto
*/