William Maillard
CS 372
Assignment 4
5/5/2016

For assignment 4, two random testers were created: randomtestadventurer.c and randomtestcard.c which test the Adventurer and the Smithy card respectively.  To compile and run these tests, type "make randomtests".  You can also run these files individually by typing "make randomtestadventurer" or "make randomtestcard".

***randomtestadventurer.c information and discussion:

This programs defaults to 100,000 tests, which each:
1. Initialize a game 
2. Fill a player's hand, discard pile, and deck with random cards 
3. Call the playAdventurer function.
4. Compares the results of playAdventurer to the expected results
	
After this has been done 100,000 times, the program prints (if used with the makefile, writes to the file randomtestadventurer.out) the following:
1. One example of inputs that failed and their resulting outputs
2. The number of tests, failed tests, and percentage of passed tests

The development of this test was pretty straightforward and resulted in an increase of overall code coverage, and specific coverage
of the playAdventurer function.  Here is the coverage information of the playAdventurer function after the unit tests but before the random test:

Function 'playAdventurer'
Lines executed:72.22% of 18
Branches executed:100.00% of 12
Taken at least once:83.33% of 12
Calls executed:100.00% of 3

And here is the coverage of the playAdventurer function after the unit tests and after the random test:

Function 'playAdventurer'
Lines executed:100.00% of 18
Branches executed:100.00% of 12
Taken at least once:100.00% of 12
Calls executed:100.00% of 3

As you can see, the random test increased the number of lines executed and branches executed at least once to 100%, which is great coverage for this function. The only difficulty that was faced when developing this random test was that the playAdventurer function failed with every input.  This was at first a little worrisome, but it turns out to make perfect sense because the current playAdventurer card does not discard the Adventurer card after it is played, like the other card functions, and therefore the handsize will always be incorrect after this function is called.  The details of the randomtestadventurer function can be seen in the randomtestadventurer.out file.
	
***randomtestcard.c information and discussion:

This programs defaults to 10 tests, which each:
1. Initialize a game 
2. Fill a player's hand, discard pile, and deck with random cards 
3. Put an Smithy card randomly into the player's hand
4. Call the playSmithy function using the Smithy card that was added to player's hand
5. Compares the results of calling playSmithy to the expected results
	
After this has been done 10 times, the program prints (if used with the makefile, writes to the file randomtestscard.out) the following:
1. One example of inputs that failed and their resulting outputs
2. The number of tests, failed tests, and percentage of passed tests

The development of this test was very similiar to playAdventurer random test except for a couple of key differences:
	
1. The function playSmithy takes as an argument, the position of the Smithy card in the player's hand, so a Smithy card had to be added to the player's hand and its position was paseed to playSmithy.
2.  The bug in the playSmithy function initiates an iterator to an arbitrary value and then increases that value until it is more than 3.  This bug causes the playSmithy function to run for a significant amount of time if the iterator is initiated to a very negative number.  Because of this, the number of times that the test is run is set to default at 10.  This can be overridden with commandline arguments(see the randomtestcard.c file for more information).


This random test of the Smithy card	resulted in an increase of overall code coverage, and specific coverage
of the playSmithy function.  Here is the coverage information of the playSmithy function after the unit tests but before the random test:

Function 'playSmithy'
Lines executed:83.33% of 6
Branches executed:100.00% of 2
Taken at least once:50.00% of 2
Calls executed:66.67% of 3

And here is the coverage of the playAdventurer function after the unit tests and after the random test:

Function 'playSmithy'
Lines executed:100.00% of 6
Branches executed:100.00% of 2
Taken at least once:100.00% of 2
Calls executed:100.00% of 3

As you can see, the random test increased the number of lines executed, branches executed at least once, and the calls executed to 100%, which is great coverage for this function.  This increase can be attributed to the fact that the random test was able to executed enough times to get into the for() loop that contains an arbitrarily inititated iterator.
	
The biggest difficulty that was faced when developing this random test was that the playSmithy took a very long time to run if it found the abitrarily assigned iterator bug.  This limited the number of tests that could be run in a reasonable amount and time.  Even though few tests were run, all of them failed, so valuable information was still gathered. The details of the randomtestcard function can be seen in the randomtestcard.out file.
	
***Overall coverage
	
The overall coverage of the dominion code, as expected, increased a little bit after these random tests were performed.  Here are the coverage results after the unit tests:

File 'dominion.c'
Lines executed:38.16% of 566
Branches executed:39.62% of 419
Taken at least once:35.08% of 419
Calls executed:23.00% of 100

And here are the coverage results after the unit tests and the random tests.

File 'dominion.c'
Lines executed:39.22% of 566
Branches executed:39.62% of 419
Taken at least once:35.80% of 419
Calls executed:24.00% of 100
Creating 'dominion.c.gcov'
	
They was a small amount of increased coverage, which can be expected when working with just two cards.