//smithy
smithy is an action card. The card allows you to draw 3 cards. The cost of smithy is 4 coins. Smithy generates card draws with which
you can buy gold. With the gold you can buy provinces.

//adventurer
Adventurer is a action card. The adventurer lets you extract 2 treasure cards from your deck.
The cost of Adventurer is 6 coin. 

discardCard()
discardCard function validates that the card being played can be played. The function cardEffect is called to play said card.
inputs include a struct gameState state , which holds a pointer to a gameState variable. It also inputs a int called 
handPost, which is the position of the hand of the card to return. An int currentPLayer is input. Lastly, a int trashFlag is input.
The functions returns 0 on success.

updateCoins()
The function the count of a specific card in the player's discard deck, and also his hand. The function inputs a gameState state, which 
holds a pointer to a gameState variable. The functions also inputs two ints called player and bonus. The function
returns 0 on success.