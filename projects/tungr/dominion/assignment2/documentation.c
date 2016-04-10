/*
	Rosa Tung
	Assignment 2: Task 2
*/

/*documentation of smithy cards*/
	//Action card that costs 4 coins.
	//It increases your handsize by drawing 3 cards and costs 4 coins.
	
/*documentation of adventurer cards*/
	//Action card that costs 6 coins. 
	//Reveal cards from your deck until you reveal 2 Treasure cards. 
	//Put those treasure cards into your hand and dsicard the other revealed cards. 
	
/* * * * * * * * * * * * * * * * * * * *
 understanding of discardCard() method
 * * * * * * * * * * * * * * * * * * * */
 
//method takes in 
	//card position(in players hand)
	//which player
	//pointer to current game state 
	//if player is trashing or keeping card

//General Method Steps
	//Check: card trashed? 
	//	if no: add to played pile
	//
	//Set that spot in players hand to -1
	//
	//Check: last card in hand is played?
	//	if yes: reduce card count by 1
	//	if no Check: only one card in hand?
	//		if yes: reduce card count by 1
	//		if no: replace discarded card with last card in hand, change last card value to -1, reduce card count by 1

/* * * * * * * * * * * * * * * * * * * *
 understanding of updateCoins() method
 * * * * * * * * * * * * * * * * * * * */
 
//method takes in 
	//which player 
	//pointer to current game state
	//bonus value 
	
//General Method Steps 
	//go through players hand
	//		Check: copper card?
	//			if yes: add one to coin counter
	//			if no Check: silver card?
	//				if yes: add two to coin counter
	//				if no Check: gold card bb!
	//					if yes: add three to coin counter
	//
	//After everything add bonus amount to coin counter