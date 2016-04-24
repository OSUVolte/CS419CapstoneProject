/* Martha Gebremariam
CS362_Spring2016_Assignment2
Description: Domumentation of smithy & adventurer cards AND discardCard() & updateCoins() methods in dominion.c

smithy: Is an action card that allows the player to draw three more cards.
Implementation: when cardEffect function is passed smithy card, it defaults to case smithy. Case smithy has a for loop that iterates 3 times. In each iteration of the for loop, drawCard function is called. After completing the for loop, it calls the discardCard function to discard smithy. Then, it returns 0.

adventurer: Is also an action card that requires the player to reveal cards from his/her deck until 2 treasure cards are revealed. When treasure cards are revealed, player puts those into his/her hand and discard all other revealed cards
Implementation: when cardEffect function is passed adventurer card, it defaults to case adventurer. Case adventurer has two while loops. The first one will loop as long as drawnTreasure (variable used to keep track of number of treasure cards revealed) is less than 2. 
The first if statement in while loop checks if deck is empty or not by checking deckCount of current player. If deckCount is found to be less than 1, shuffle function will be called to shuffle discarded cards. 
Then the drawCard function is called to draw a card.
Then the drawn card is checked to see if it’s a treasure card by comparing the card to copper, silver, and gold. If it equals one of them, drawnTreasure gets incremented. If not, it records the hand in tempHand (an array used to temporarily store revealed non treasure cards) and removes the card from hand by decrementing handCount. 
The second while loop is used to discard non treasure revealed cards by adding the cards in tempHand to current’s players discardList.
Then, it returns 0

discardCard(): Is a function used to discard a card from players’ hand
Implementation: discardCard receives handpost, currentPlayer, state, and trashFlag as parameters. 
The first if statement in discardCard checks the trashFlag to see if card was trashed. If card was not trashed (trashFlag < 1), card gets added to playedCards (an array used to record played cards) and the played card in hand gets set to -1. 
Then, it checks if last card in hand array is played or if there’s only one card in hand. In both cases, the number of cards in hand get reduced. 
If last card in hand array is not played and there’s more than one card in hand, discarded card gets replaced with last card in hand, last card gets set to -1, and number of cards in hand get decremented
Then it returns 0

updateCoins(): Is a function used to update number of coins player has for a turn. Which includes coins from treasure cards and bonus coins from other cards. 
Implementation: updateCoins receives player, state, and bonus as paramenter.
It first initializes coins to 0.
Then, it runs through a for loop which iterates for handCount numbers. At each iteration of the for loop, the current card gets compared with copper, silver, and gold. For copper, 1 gets added to coins. For silver, 2 gets added to coins, and for gold, 3 gets added to coins. After for loop, bonus gets added to coins.
Then it returns 0
*/



