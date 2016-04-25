/*

Author: 	Charles Siebert
Class:	CS362-400
Date:	4/24/16 
File:	bug1.c

Description: File used to discuss the information of unit test coverage of each test

--- UNIT TEST #1 ---

Function 'main'
Lines executed:90.00% of 60
Branches executed:100.00% of 22
Taken at least once:72.73% of 22
Calls executed:76.92% of 26

File 'unittest1.c'
Lines executed:90.00% of 60
Branches executed:100.00% of 22
Taken at least once:72.73% of 22
Calls executed:76.92% of 26
Creating 'unittest1.c.gcov'

--- UNIT TEST #2 ---

Function 'main'
Lines executed:89.29% of 28
Branches executed:100.00% of 6
Taken at least once:50.00% of 6
Calls executed:80.00% of 15

File 'unittest2.c'
Lines executed:89.29% of 28
Branches executed:100.00% of 6
Taken at least once:50.00% of 6
Calls executed:80.00% of 15
Creating 'unittest2.c.gcov'

--- UNIT TEST #3 ---

Function 'main'
Lines executed:87.50% of 40
Branches executed:100.00% of 10
Taken at least once:50.00% of 10
Calls executed:77.27% of 22

File 'unittest3.c'
Lines executed:87.50% of 40
Branches executed:100.00% of 10
Taken at least once:50.00% of 10
Calls executed:77.27% of 22
Creating 'unittest3.c.gcov'

--- UNIT TEST #4 ---

Function 'main'
Lines executed:96.97% of 33
Branches executed:100.00% of 2
Taken at least once:50.00% of 2
Calls executed:77.78% of 9

Function 'testHand'
Lines executed:79.31% of 29
Branches executed:100.00% of 12
Taken at least once:50.00% of 12
Calls executed:60.00% of 30

File 'unittest4.c'
Lines executed:88.71% of 62
Branches executed:100.00% of 14
Taken at least once:50.00% of 14
Calls executed:64.10% of 39
Creating 'unittest4.c.gcov'

-----------

Discussion: These unit tests show a high % coverage in main when executed. When
test function calls on the function in main, tracking it shows there's a large
percentage that the code was executed, and with proper testing with expected values
this helps us determine, more likely, more bugs that exist in our code.

Looking at the code that is executed, a large amount of it is within the if/else
statements where code isn't executed because we've already gotten the determined
value off of those branches. Missing lines also come from basic initialization, such
as making a value in the function defaulted value.

-----------

--- CARD TEST #1 ---

Function 'main'
Lines executed:86.96% of 23
Branches executed:100.00% of 6
Taken at least once:50.00% of 6
Calls executed:75.00% of 12

File 'cardtest1.c'
Lines executed:86.96% of 23
Branches executed:100.00% of 6
Taken at least once:50.00% of 6
Calls executed:75.00% of 12
Creating 'cardtest1.c.gcov'

--- CARD TEST #2 ---

Function 'main'
Lines executed:84.62% of 26
Branches executed:100.00% of 8
Taken at least once:50.00% of 8
Calls executed:69.23% of 13

File 'cardtest2.c'
Lines executed:84.62% of 26
Branches executed:100.00% of 8
Taken at least once:50.00% of 8
Calls executed:69.23% of 13
Creating 'cardtest2.c.gcov'

--- CARD TEST #3 ---

Function 'main'
Lines executed:88.89% of 18
Branches executed:100.00% of 4
Taken at least once:50.00% of 4
Calls executed:80.00% of 10

Function 'initDecks'
Lines executed:100.00% of 5
Branches executed:100.00% of 2
Taken at least once:100.00% of 2
Calls executed:100.00% of 2

File 'cardtest3.c'
Lines executed:91.30% of 23
Branches executed:100.00% of 6
Taken at least once:66.67% of 6
Calls executed:83.33% of 12
Creating 'cardtest3.c.gcov'

--- CARD TEST #4 ---

Function 'main'
Lines executed:83.87% of 31
Branches executed:100.00% of 12
Taken at least once:58.33% of 12
Calls executed:66.67% of 15

File 'cardtest4.c'
Lines executed:83.87% of 31
Branches executed:100.00% of 12
Taken at least once:58.33% of 12
Calls executed:66.67% of 15
Creating 'cardtest4.c.gcov'

-----------

Discussion:In these card tests, lines that are executed and called within cardtest
has a large percentage of lines executed and branches executed. The lines that may
not be covered in main is initialized values that aren't executed by the called test
and branch values that will take a different result.

Though largly, all of the cards have 100% branch coverage, so it follows through the
logic given, but the lines not executed will show up as missed coverage. Still have high
results of our given tests.

-----------

---FUNCTION CALLS dominion.c ---

Function 'cardCouncilRoom'
Lines executed:100.00% of 8
Branches executed:100.00% of 4
Taken at least once:100.00% of 4
Calls executed:100.00% of 3

Function 'cardVillage'
Lines executed:100.00% of 5
No branches
Calls executed:100.00% of 2

Function 'cardSmithy'
Lines executed:100.00% of 5
Branches executed:100.00% of 2
Taken at least once:100.00% of 2
Calls executed:100.00% of 2

Function 'cardAdventurer'
Lines executed:64.71% of 17
Branches executed:100.00% of 12
Taken at least once:66.67% of 12
Calls executed:50.00% of 2

Function 'updateCoins'
Lines executed:100.00% of 11
Branches executed:100.00% of 8
Taken at least once:100.00% of 8
No calls

Function 'gainCard'
Lines executed:100.00% of 13
Branches executed:100.00% of 6
Taken at least once:100.00% of 6
Calls executed:100.00% of 1

Function 'isGameOver'
Lines executed:100.00% of 10
Branches executed:100.00% of 8
Taken at least once:100.00% of 8
No calls

Function 'scoreFor'
Lines executed:100.00% of 24
Branches executed:100.00% of 42
Taken at least once:100.00% of 42
Calls executed:100.00% of 3

---dominion.c:---
File 'dominion.c'
Lines executed:35.60% of 559
Branches executed:38.55% of 415
Taken at least once:34.22% of 415
Calls executed:21.05% of 95
Creating 'dominion.c.gcov'

File 'dominion.c'
Lines executed:35.60% of 559
Creating 'dominion.c.gcov'

-----------

Discussion: This is the coverage of the entirety of dominion.c. This shows the coverage
given by the branches and lines executed by all of the previous tests. As above, this
shows that the lines executed is 35.6%, and branches executed is 38.55%. The reason
the results are so low, compared to the high coverages given above, is because we have
only test 8 functions.

To increase our coverage on dominion.c, we have to create more tests that will execute a
larger majority of lines. In the results, "Calls executed" show a low 21% of calls made out
of the total 95, meaning that even with 8 functions called in our tests, we're missing 79%
of functions or different game states that were not tested, or shown to be working without our tests.

To increase coverage on all tests, we can explore all values of branches, such as positive and
negative values or create values that would cover the less-explored branches in our if/else statements.
Normal logic flow will go with "program working," but we don't normally test for values to 
indefinitely break the game.

One card (village) I tested/changed allowed for a card to be drawn to the opposing player instead
of the current player. This goes beyond the original rules within the card to test the statements
of the other player. This is normally something that can be overlooked.

card Adventurer has a lower amount of testing coverage, this is resulted by inadequate testing
Better coverage can be gained in main by testing certain values of cards are gained, and testing
which cards are drawn, and then discared to check proper treasures are drawn.

-----------

*/
	
