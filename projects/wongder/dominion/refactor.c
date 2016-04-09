//Created By: Derek Wong
//Create Date: 4/8/2016

I copied the code of the 5 cards I chose in the cardEffect function into their own individual functions. I gave them the correct parameters that the code requires. For the adventurerCard function I passed in struct gameState *state, int currentPlayer, and int* temphand. The other 4 cards all have the same parameters which are struct gameState *state, int currentPlayer, and int handPos. The functions are located on top of the cardEffect function. My 5 cards are adventurerCard, smithyCard, council_roomCard, villageCard, and stewardCard. 

//adventurerCard bug 

I changed the if statement where it checks if a player draws a treasure card. It use to be "if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)", but I took away 1 "=" sign from each of them so its "cardDrawn = cooper". This makes it so that it is true everytime this part of the code used. It will always think the player is drawing a treasure card which is not correct. 

//smithyCard bug

I changed the trashFlag parameter when the function calls the discardCard function. I switched it from a 0 to a 2. This makes it so that the card is trashed instead of being discarded to the played pile.

//council_roomCard

After the player draws 4 cards and gets 1 extra buy, every other player gets to draw one card. So in the code where it lets every other player draw a card I took out the if statement that prevents the current player from drawing a card. This will make it so that everyone will draw a card which is incorrect because it should be every other player not every player. 

//villageCard

This card adds 1 card and 2 action to the player. In the code I changed it so that it adds 2 extra buy for the player instead. 


//stewardCard
