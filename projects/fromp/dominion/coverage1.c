Statement coverage:

	gcov results: 
		File 'dominion.c'
		Lines executed:37.70% of 557
		Creating 'dominion.c.gcov'
	
	Coverage for the function unit tests is quite a bit higher than for the cards. While each statement was covered at least once, the number of times the statements in the cards was covered was low. This is because loops were used for the function unit tests while the tests for the cards used only a few calls to the target cards. While I believe the statement coverage for the function unit tests was okay, I think it would be a good idea to have each statement covered more times. There is one exception to this, where the "return -1;" statement in the remodel card was never executed. This is actually the result of a bug in the function -- the if statement should be "less than" instead of "greater than".

Branch coverage: 
	
	gcov results:
		File 'dominion.c'
		Lines executed:37.70% of 557
		Branches executed:37.32% of 418
		Taken at least once:29.67% of 418
		Calls executed:26.88% of 93
		Creating 'dominion.c.gcov'
	
	Aside from the branch corresponding to the bug mentioned above, most of the branches in card and fucntions tested were taken at least once. However, the fallthrough percentage was low or zero for some functions, in the future, it is necessary to write tests with greater "fallthrough." That said, aside from the remodel card, all functions and cards tested had 100% of their blocks executed. The remodel card had only 94% of its blocks executed, due to the bug noted above.


