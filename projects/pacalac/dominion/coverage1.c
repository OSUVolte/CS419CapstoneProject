As far as coverage goes, my tests had 33.16% total line coverage of dominion.c after all 8 tests completed.

Looking at the gcov file, it seems that there are some very large gaps where entire functions were never called.
The functions I never called were those that actually control the gameplay (e.g. playCard or endTurn) as the
functions I tested did not rely on the turns being completed.

As for the coverage of the functions I did test:

unittest1 - fullDeckCount. The function was called 5 times total and each line of the function was run.
	Most lines were run at least 50 times (and some over 1500 times) though.

unittest2 - gainCard. Again, the function was called 5 times and each line of the function was run.
	However, most lines were only run one or two times.
	
unittest3 - discardCard. The function was called 5 times. One line was not run, the statement if the player
	only had a single card in his/her hand.
	
unittest4 - buyCard. The function was called 4 times. Other than the DEBUG messages, every line was run
	at least once. However most lines were only run a single time.
	
	
cardtest1 - playAdventurer. The function was called a single time. The function did not run all lines as the deck
	was not empty (so shuffle wasn't called) and the cards picked up were always treasure cards (so the function 
	did not need to handle drawing and discarding non-treasure cards).

cardtest2 - playSmithy. The function was called a single time. Every statment was covered.

cardtest3 - playCouncil. The function was called a single time. Every statement was covered.

cardtest4 - playSteward. The function was called 3 times. Every statement was covered at least once.