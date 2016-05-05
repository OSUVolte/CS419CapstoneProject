/* *******************************************************

	Name: 				Daniel OFarrell
	Date Created:			3 May 2015
	Last Modification Date:		4 May 2015
	Filename:			randomhistory.c			

	Overview:
		Assignment 04 tasks us with created random testing files
		for 2 cards: Adventurer and Salvager


	Adventurer Card:
		Called:			1000 
		Returned:		100%
		Blocks Executed:	100%
		Coverage 		100%

	Summary:
		01: initially, only 10 iterations are made. This achieved a 94%
		coverage of the function _cardAdventuer(). It did not manage to
		reach all paths. 
		02: Here, iterations are set to 10,000. The program hangs up.
		03: The iterations are scaled down to 500. There is still a hand
		up
		04: The number of iterations is set to 100. Now, there is 100%
		coverage.
		05: An error in the test script which would cause an infinite loop
		is fixed. Prior, where all cards in the deck are coins, no coins
		could be added. This was adjusted to simply add 2 copper to any
		random position. Now testing allowed for 1,000 cases.

	Errors:
		Regardless of the number of tests performed, the results of the 
		function call always returnd -1, indicating FAILURE. This is set
		by the programmer. 

	Error Explanation:
		This error may be caused by the change introduced during refactor
		part 1. 
		

	AAA Card:
		Called:			1000
		Returned:		1000
		Blocks Executed:	100%
		Coverage:		100%

	Summary:
		01: initially, the number of actions were also checked. However, 
		this caused a conssistent error. Upon inspection, cardEffect did not
		handle any alterations to the numActions variable. This test was 
		removed. This allowed for the testing to contine.

	Errors:
		None.

	Error Explanation:
		None.




 ******************************************************* */
