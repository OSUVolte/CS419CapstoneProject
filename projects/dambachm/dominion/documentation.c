Smithy Documentation:
The smithy card is a moderately usefull card. When played it allows you to draw three more cards from your deck into your hand.
The code draws three more card into your hand and then discards the smithy card from your hand.

Adventurer Documentation:
The adventurer card is very handy to have later in the game after you have converted your copper cards to gold cards.
It allows you to get two more treasury cards into your hand. If you get a gold card in your hand and you have mostly
gold treasury cards, it provides you a very good chance to buy a Provence card which go a long way to winning the game.
The code keeps drawing cards from the player's deck until two treasury cards have been drawn. It also shuffles the discard
pile whenever necessary. It then adds all cards drawn that were not treasury cards into the discard pile.

discardCard() Documentation:
The discardCard() function handles all the discarding rules.
First, it adds the card to the playedCard array. It then removes it from the player's hand.

updateCoins() Documentation:
The updateCoins() function handles how many coins a play has in their hand.
It sets the number of coins to zero. It then goes through each card in the player's hand and adds 1, 2, or 3
to the number coins for copper, silver and gold treasury cards.
It then adds any bonus coins called for by an action card previously played.
