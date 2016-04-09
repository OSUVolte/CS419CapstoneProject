//Created By: Derek Wong
//Create Date: 4/7/2016


//Smithy

This card simply adds 3 card to the players hand. The codes uses a for loop to loop the drawCard function 3 times, which adds 3 cards to the player's hand. Finally it calls the discardCard function to discard the smithy card.

//Adventurer

The adventuruer card reveals card from the deck until 2 treasure cards (copper, silver, gold) are revealed. The player then keeps the 2 treasure cards in his/her hand and discard the other revealed cards. The code uses a drawntreasure variable in a while loop to keep track of how many treasure cards are revealed. When the variable increments to 2, the loop would then stop. Inside the loop, the shuffle function is called if the deck is empty. Each loop would call the drawCard function and if the card drawn is a treasure card it would increment the drawntreasure variable by 1. If it is not a treasure then the card would be stored in the temphand and the handCount of the player would be decremented by 1. There is also a temp variable to keep track of how many non-treasure cards are drawn. After the player has drawn 2 cards, a while loop is used again to remove all the non-treasure card from the temphand. The temp variable is used to loop through the temphand.

//discardCard()

There is a played pile which is where the cards go after the player has used them, and then there is a trash pile which is where cards are discarded to (you can't get them back). This function discards a card from a players hand by using the index of where the card is. It first checks if the card is trashed, if it is not then the card would be added to the played pile, by taking the index of where the card is from the players hand and adding it to the playedCard array and incrementing the number of cards in the array by 1. The next part in the code is the if, else if, and else statements. It is used to remove the card from the player's hand. If it is the last card in the player's hand then decrement it by 1. If it is the only card in hand then decrement it by 1. Else if it was from somewhere else then replace the discarded card with the last card in hand. Then decrement it by 1.

//updateCoins()

This function updates how many coins a player has. It uses a for loop to loop through all the cards in the player's hand. Inside the for loop there are if statements so that the correct amount of coins get added. For example, cooper adds 1 coin, silver adds 2, and gold adds 3. Once it is out of the for loop it will add the total amount of coin in the player's hand to the bonus coin if there are any. The bonus amount is passed into the function. 

