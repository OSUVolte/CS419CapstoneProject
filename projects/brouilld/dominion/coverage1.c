

Coverage results:

	File 'dominion.c'
	Lines executed: 33.69% of 564

	Statement:
		From my analysis of the results, it seems that the statement coverage of the
			card unit tests avoided blockages. The function tests, however, did
			not eliminate the possibility that there are blockages within the functions.
			Further analysis and testing is needed to check for blockages in the functions
			targeted.

	Branch Testing:
		Each test was first conceived from the view of branching logic. Some functions such as
			'getCard' and the card 'Council Room' proved rather easy to branch. These 
			functions and cards achieved 100% statement coverage. The more complicated
			functions such as 'playCard' and 'buyCard' were hard to branch which caused them
			to not achieve 100% statement coverage.

	Boundary Testing:
		Boundary Testing was employed for the functions and cards that allowed for such. Of
			particular note was 'updateCoins()'. The bonus and number of treasure cards
			were pushed into the negative as well as quadruple digits.


	Conclusion:
		Overall, the unit tests implemented didn't provide enough coverage. Additional
			functions need to be unit tested. Of particular interest is the function
			'drawCard' as many of the errors discovered revolved around the use of that
			function. In addition, more boundary testing should be incorporated to
			ensure the edge cases are accounted for. Finally, it appears the 
			card effects should be a strong focus for unit testing as numerous
			errors have already been found in just a few of the cards. This leads
			one to believe that the other cards contain just a severe bugs.