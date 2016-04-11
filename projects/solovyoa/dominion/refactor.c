/*************************************************************************
 * Andriy Solovyov
 * CS 362
 * Assignment 2: refactor.c
 * 4/10/16
 * Description: 
 Pick five cards implemented in dominion.c. Choose 3 cards of your choice and smithy and adventurer cards are mandatory. 
 Refactor the code so that these cards are implemented in their own functions, rather than as part of the switch statement 
 in cardEffect. You should call the functions for these cards in the appropriate place in cardEffect. Check in your changes, 
 with appropriate git commit messages. Document your changes in a text file in your dominion source directory, called 
 “refactor.c.” Your implementation of at least 4 of these 5 cards should be incorrect in some way, i.e., you should introduce 
 subtle bugs that are hard to catch in your changes. Introducing bugs in smithy and adventurer is mandatory.  Write information 
 of your bugs also in refactor.c  Later in this class, other students will test your code, so try to keep your bugs not superficial.
 Refactored program should compile without any error.  
 ************************************************************************/

/****** 

	Refactored Code Summary: 

		For this part of the assignment, the cards I chose to refactor:
			1) Smithy 
			
			2) Adventure 
			
			3) Village 
			
			4) Great Hall
			
			5) Council Room

        Added Bugs:

        	1) Smitthy: A bug created to add the incorrect number of cards. So in addition of receiving 3 cards from this card, a player will receive two actions along. 
        	
        	2) Adventure: A bug added to make player unable to discard the card they haven't drawn. 

        	3) Village: A bug created to give current player 3 cards and no action cards.
        	
        	4) Great Hall: A bug create to not give any action variables
        	
        	5) Council Room: A bug created draw 3 cards instead of 4 as it intended



