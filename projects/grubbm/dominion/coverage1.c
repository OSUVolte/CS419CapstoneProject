/***************************************
Max Grubb Unit Test Results Assignment3 
****************************************/

The summary of results can be seen in unittestresult.out.  The results varied due to the fact that only 
small portions of the overall code were tested.  


Function 'updateCoins'  
Function 'updateCoins'
Lines executed:81.82% of 11
Branches executed:100.00% of 8
Taken at least once:75.00% of 8
No calls

While most of my code did not interact with this functinon directly, 7 of my 8 tests called initiliazeGame() 
which calls this function in turn.  Because the coins are updated at the start of the game, this function 
has very high testing numbers. Also, there were some calls to this function in my cardEffect tests. Not all 
lines were executed because my testing did not deal with bonus at all, and not all if-then statements were
addressed. To get these numbers higher, I would look to test bonus numbers and ensure all if then statements are
addressed. 

Function 'cardEffect'
Lines executed:3.81% of 236
Branches executed:11.56% of 199
Taken at least once:1.01% of 199
Calls executed:1.56% of 64

While there were four tests on four cards that called this function, cardEffect() is one of the 
largest functions in terms of lines, so most of the function was not addressed. Also, a call to gardens
or smithy cards do not have large effects or really call other functions, hence the lower numbers. I would
test all cards to ensure higher numbers and test coverage. 

Function 'drawCard'
Lines executed:36.36% of 22
Branches executed:33.33% of 6
Taken at least once:16.67% of 6
Calls executed:0.00% of 1

This function was mainly called as a result of calling cardEffect. Also, the tests I ran that interacted with 
this function were simple in nature, so not all of the loops and if-then statements could be triggered. 
A fuller testing of the game and different game states would ensure higher numbers and coverage.

Function 'whoseTurn'
Lines executed:100.00% of 2
No branches
No calls

This is a simple test with minimal code.  It was called twice during its unit test and was successful twice. 

Function 'shuffle'
Lines executed:93.75% of 16
Branches executed:100.00% of 8
Taken at least once:87.50% of 8
Calls executed:100.00% of 2

This was generally called within a game initialization and it has high coverage as a result of this because
7 of 8 tests had a game initialization. The numbers would be higher if a more robust gameplay test was 
created to test all lines within this function 

Function 'initializeGame'
Lines executed:83.87% of 62
Branches executed:95.65% of 46
Taken at least once:78.26% of 46
Calls executed:100.00% of 5

This function was called in a majority of cases, but not all possibilities were addressed, hence high numbers but 
not full 100% numbers.  Again, a fuller and more robust test that simulates a more complete game, and likely
games would raise these numbers.