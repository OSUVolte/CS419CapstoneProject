/**********
Author: James Taylor
Date: 10/25/15
Updated: 4/10/16
**********/
smithy:
	The smithy card is an action card which when played adds three cards to the players hand. 
	
	The code executes a loop that calls the drawcard() function three times to add three cards 
	to the players hand. It then exits the loop and calls the discardCard() function to 
	discard the smithy card. 

adventurer:
	The adventurer card is an action card which when played draws cards until two treasure cards
	are drawn. It then adds the treasure cards to the players hand and discards the other drawn
	cards. 
	The code starts by entering a while loop controlled by the counter drawntreasure.
	The loop starts by checking the player deck and making sure it is not empty. If it is it
	reshuffles the cards and creates a new deck. The next block draws a card from the top. If it
	is a treasure card, it is added to the current players hand. If it is not a treasure, it is added to a temp hand for discard
	When the while loop discover two treasure cards have been drawn, it exits the loop, and the next portion of the code discards
	the temp hand.
	
discardCard():
	Helper function to discard a card from the current players hand and either trashes it or discards it. 
	
	The code starts by determining if the card is to be trashed or just added to the play pile. If not trashed, it is added to play pile. 
	Second, the players hand is reduced by one. It takes the played card and checks for two special cases. 1) if is the last card in the players hand it just removed.
	2) if there is one card in the players hand, it is removed.
	In all other cases, the card is removed from the array and the last card in the players hand is moved to that removed card's position in the hand. 
	
updateCoins():
	Helper function maintain coin count for each player during their turn. 
	
	Code initializes coincount to 0. It then iterates through the current players hand. If/then statements 
	then check each card and if it equals a treasure card, it adds the appropriate numbers of
	coins to the overall count. Finally, it hads any bonus points from function param bonus. 