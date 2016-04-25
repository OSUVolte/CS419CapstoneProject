/*********************************************************************************************
 * Student: Nick Martin
 * ONID: martinn6
 * Date: 20160408
 * Project: Assignment 02
 * Description: Submit a file called documentation.c (.c file because github thinks you are 
	using github for file storage if you use many .txt files) that contains documentation of 
	smithy, adventurer cards. Documentation should contain your understanding of smithy 
	and adventurer cards (code). It should also contain documentation of your understanding 
	of discardCard() and updateCoins() method.  Keep your documentation short, though there 
	is no upper limit. Documentation.c file should contain at least 100 words.  
 * *******************************************************************************************/

 Smithy
 Price: 4 coins
 Action Description: When cardEffect() detects a smithy card, it calls the 'drawCard()' function for 3 cards. 
 It will then discard the 'Smithy' card from the hand.
 
 
 Advenurer
 Price: 6 coins
 Description: This card, when played, will allow a user to search through their deck to find the first two treasure cards. They can then
 put the treasure cards into their hand. They have to discard the other cards that are not treasure cards.
 
 discardCard()
 Description: When called, checks the card passed to the functino can be played. If so, then it will call the cardEffect function to play it.
 
 updateCoins()
 Description: This will return the coin amount for a particular card in a player's card in their hand or discard pile.