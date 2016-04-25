coverage1.c
David Hite

unittest1 tested the kingdomCards() function. It had 100% coverage of the kingdomCards()
function, which has 0 branches. It had a 2.33% coverage of all the lines in dominion.c.

unittest2 tested the initializeGame() function. It had 98.38% of the 62 lines in 
initializeGame() executed, with 100% of the 46 branches executed, and 100% of its 5 calls
executed. The line that was not executed in the function was an error condition that
would have been produced by another function, which I had no control over without 
modifying that function. 20.07% of all the lines in dominion.c were executed.

unittest3 tested the shuffle() function. 92.75% of the 16 lines in the function were 
executed, and 100% of its 8 branches were executed. Both of its calls were executed.
3.94% of the total lines in dominion.c were executed. The line of code within the 
shuffle() function that was not covered was an error case that my test did not cover,
so that could be improved in the future.

unittest4 tested fullDeckCount(). 100% of its 9 lines and its 12 branches were covered.
2.15% of all the lines in dominion.c were covered by this test.

cardtest1 tested playSmithy(). 100% of its 6 lines and 2 branches were covered. 5.02% of
all the lines in dominion.c were covered by this test.

cardtest2 tested playAdventurer(). 100% of its 16 lines and 12 branches were covered. 10.93%
of dominion.c was covered by this test.

cardtest3 tested playVillage(). 100% of 5 its 5 lines were executed. 4.84% of the lines in
dominion.c were covered by this test.