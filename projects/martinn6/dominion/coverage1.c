Coverage tests:

Summary: I primarily focused on function coverage since that is what the assignement was about. As I progressed
through the assignement, I was noticing some patterns:

1) 100% complete coverage of a function did not mean that I was testing all the scenarios. I felt better about 
utizling boundary tests over coverage completion. Even with 100% coverage, I noticed I was missing some logical
patterns.

2) As I progressed through the cardtests, I felt like I was building a test suite. Each test I did helped to test
the other cards as well. It was a pretty neat experience when it clicked that I was building a test suite.

Regarding the coverage, eventhough I tested a lot of the 'cardEffect' code, I only tested 12.29% of the whole function. 
That was shocking to me. Since this is the last day and I arm running out of time, I did try and choose code that
did not have a lot of lines to diagnose. If I would have tested functions with more lines, I would have increased 
the percentage. However, in the end, I still should test each of the case statements of the function to make sure
they are running correctly.

final coverage test by branch:

Lines executed:40.51% of 548 
Branches executed:43.88% of 417
Taken at least once:35.25% of 417
Calls executed:18.89% of 90

This really surprised me because I spent a lot of time on this: 12-15 hours and I only have ~40% of lines and branches covered. This means
it would take me around a whole week (~40 hours +/-) to cover the whole program depending on the size of each function and how many there
are.

final coverage test by function:

All functions that I tested have 100% coverage except for cardEffect. Mostly this is due to the fact that cardEffect is really 20-30 functions
in one. I would split the cardEffect funtions into mulitple functions. This way you could see exactly what still needs to be tested.

A lot of other functions were tested due to the functions of initalizing the game. However, there are still some functions that have not been
tested at all. 

Function 'updateCoins'
Lines executed:100.00% of 11

Function 'gainCard'
Lines executed:100.00% of 13

Function 'discardCard'
Lines executed:92.31% of 13

Function 'cardEffect'
Lines executed:12.29% of 236

Function 'getCost'
Lines executed:100.00% of 30

Function 'drawCard'
Lines executed:36.36% of 22

Function 'getWinners'
Lines executed:100.00% of 24

Function 'scoreFor'
Lines executed:50.00% of 24

Function 'isGameOver'
Lines executed:0.00% of 10

Function 'endTurn'
Lines executed:0.00% of 20

Function 'whoseTurn'
Lines executed:100.00% of 2

Function 'fullDeckCount'
Lines executed:0.00% of 9

Function 'supplyCount'
Lines executed:100.00% of 2

Function 'handCard'
Lines executed:0.00% of 3

Function 'numHandCards'
Lines executed:0.00% of 2

Function 'buyCard'
Lines executed:0.00% of 13

Function 'playCard'
Lines executed:0.00% of 14

Function 'shuffle'
Lines executed:93.75% of 16

Function 'initializeGame'
Lines executed:95.16% of 62

Function 'kingdomCards'
Lines executed:0.00% of 13

Function 'newGame'
Lines executed:0.00% of 3

Function 'compare'
Lines executed:83.33% of 6
