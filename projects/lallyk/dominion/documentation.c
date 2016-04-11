/* 
Kara Franco											documentation.c
CS.362-400
Assignment #2
Due: April 10, 2016

*** Smithy Card ***
The Smithy Card is an action card that costs 4 coins. This card allows the player to draw three cards. Smithy 
is implemented with a simple for loop that counts to three, starting from zero, that calls drawCard( ) in each
loop. After the for loop executes, the Smithy Card is discarded by calling dicardCard( ). 

*** Adventurer Card *** 
The Adventurer Card is an action card that costs 6 coins. This card reveals cards from your deck until you come
across two Treasure Cards. This is implemented with a while loop that runs while drawnTreasure is less than 
two. If there are no more cards in the deck, we will first shuffle the discard pile and add to the deck. Next,
a card is drawn from the top of the deck, if it is either silver, copper or gold; then we keep the card and 
increase drawnTreasure by one. If the card pulled is not a treasure card, then we remove the top card, 
and increase the counter to look at the next card in the deck. 

Once the player finds two Treasure Cards, the first while loop will end, and we will go into another while loop
 that discards the unwanted, non-treasure cards from the hand. This final step discards the revealed cards 
back into the hand. And the player is left with two Treasure Cards in their hand. 

*** discardCard( ) ***
Description: A method that removes a card from the player’s hand. discardCard( ) takes in four parameters; the
handPosition, currentPlayer, gameState and the trashFlag. If the trashFlag is set to 0 (not trashed), then we
add the card to the playedCards[ ] pile. Next we remove the card from the hand by subtracting 1 from the array,
removing the last element. We have an additional statement for if the hand only has one card. Lastly, return 
with 0 for success.  

*** updateCoins( ) ***
Description: A method that loops through the player’s hand, and counts the coin values to determine the coin 
count. updateCoins( ) takes in three parameters; player, gameState and bonus. Coin summation is implemented 
through a for loop that looks at each card in the player’s hand and if a card is a Treasure Card, then the coin
count in the game state, will be increased (according to the Treasure Cards type +1 Silver, +2 Copper, +3 Gold.
If there was a bonus, then the bonus is added after the for loop. Lastly, return 0 for success. 

*/
