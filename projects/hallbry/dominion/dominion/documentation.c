
 Smithy card will add 3 cards from the deck to the current hand of the player.  It will enter a for loop and call the draw card method 3 times. 
 It will then call the discardCard method to remove the smithy card from the current hand of the player
 
 
 Adventure
The adventurer card will go through the current players deck until 2 the first two treasure cards are drawn. The method has a drawntreasure variable declared to keep track of drawntreaure.  It will first start by checking if the deck is empty and if so shuffling in the discarded cards
It will then move by calling drawcard method to draw the first card and then pull this card from the first card drawn. It will then enter a if statement to evaluate if the card drawn was a treasure card. If it is a treaure card, the drawn treasure variable is incremented. If not, this card will be placed into a temphand that will then be discarded in a while statement

 
 discardCard()
This is the method for removing a card from the current hand. It works by first checking if the trash flag is active.  If the card isn't being trashed it will be added to the played card pile. This is done by manipulating properties in the state object member properties for played cards. 
It will then go on to update the cards in the current hand. The current card will be set to a value of -1. It will then go on to reduce the number of cards in the players hand. It has 3 scenarios, the first being the card just played is the last card. The 2nd is the where the user has exactly 1 card left. The final is where the card played is in the middle of the deck. In this final scenario
the last card in the deck will replace the card that was just played.
 
 
 
 updateCoins()
 This method will update the number of coins a current player has in there hand and set this new value in the game state struct.  It will first set the number of coins in the state object to 0. Then it will retrieve the current player from the game state struct, it will access the array 
 containing the hand for the current player. For each card in players hand (total number of cards is defined in the state object handcount), it will access the enum value
 for each card type. If it is defined as copper, silver, or gold, it will add that value coins in the gamestate object.
