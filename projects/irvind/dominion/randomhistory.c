/*---------------------------------------
* Brett Irvin
* 4/24/16
* CS362_400 Software Engineering II
* Assignment 4--randomhistory.c
* Describes the development of random
* testers for Assignment 4
*---------------------------------------*/

randomcardtester.c (chose the Smithy card):

----Development----
	For Assignment 4, I decided to build off of my card tests from Assignment 3.  One of the most difficult things initially
was making sure that the game state was truly random.  There's a lot of variables that go into constructing a game state, and I read
through the dominion header file (dominion.h) several times to be sure I was accounting for all of the variables.  I finally ended up
looping through each of the game state variables individually and printing the results to the screen before I was satisfied that the
random test was really going to be random.  After sorting all of that out, I went through the variables once again after they were 
passed into the game state, to make sure they hadn't changed or been reassigned.  While I had the variables printing to the screen,
I made sure that none of them were going outside of the acceptable ranges.
	Once the randomization and game states were set up properly, a lot of the actual tests built on what I had from Assignment 3.
When I ran the tester it was clear very quickly that I needed to cut down on the amount of information I was displaying to the user.  
I changed the earlier code from displaying both 'Success' and 'Failure' messages to displaying only failures.  That made the information
much easier to read and understand. The tester I ended up with loops for a set number of tests, creating a new/randomized game state for 
each run.  Each random game state is then tested for correctness, with tests occurring for the players' discard, deck, and hand count, as
well as the card's effect on the victory and kingdom cards.
	One thing I struggled with on both random testers was figuring out how many tests to run.  I wanted my tests to be effective, but
I was also worried that the testers would take too long to execute, which might be interpreted as malfunctioning code.  I tried to split the
difference: while 10,000 tests would take forever to execute, only running 5 tests would be trivial, and wouldn't be effective.  I finally
settled on running 50 tests, which seemed like a fair compromise.  If, during testing/grading, you end up staring at a blank screen, the
testers are still running, even though they don't seem to be.
 
/*---------------------------------------------------------*/

randomcardtestadventurer.c:

----Development----
	I remembered the Adventurer card from Assignment 3; it was probably the most difficult card to test properly.  Like before, part
of the difficulty in designing a random tester was in making sure that the game state was truly randomized.  Compared to the Smithy 
card (which I did first), the Adventurer card has quite a bit more going on.  The Smithy card basically just adds three cards to a user's 
deck; the Adventurerer card has a lot more to evaluate and test.  The basic tests were fairly easy to implement, since they were basically
checking the hand count, deck count, discard count, and game state for errors. 
	The random tester for the Adventurer card is similar to the tester for the Smithy card: it loops for a pre-defined number of tests, and
during each iteration it creates a randomized game state for each run.  Each random game state is then tested for correctness.  There are tests
in place for the players' discard, deck, and hand counts, as well as for the presence of Treasure cards.
	I initially implemented a basic error counter that would display how many times a bug had occurred; I figured this might be a good
way to determine whether an error condition was a one-time fluke, or was a legitimate error.  Anything that I saw repeated, I felt fairly
sure could be labeled as an error.  It would also help me look for patterns.  I had this designed, then realized I could just look back through
the test results and achieve the same effect.

/*---------------------------------------------------------*/  
  
 ----Coverage---- 
	When evaluating the coverage of my random testers, I went back and compared the coverage rates to what I had received from the unit tests
in Assignment 3.  Compared to the earlier assignment, my random test coverage rates actually decreased slightly.  I expected this, both because my
random testers targeted specific bugs in the game state, and also because Assignment 3 had so many more tests.
	It's clear that there's much more that could be done with these random testers.  My impression from these results is that both random and unit
testing have their own advantages and disadvantages.  Neither approach is perfect, but both are useful depending on the context and test requirements.
If I were working in a production environment, it would be critical to perform both styles of testing.  As my results below indicate, even when you use
both types of testing, it's still very easy to overlook certain aspects or parts of your code.  In my case, I know that my random testers are limited by 
only testing the variables of the game state.  My tests are somewhat basic, and they assume a lot of things are working correctly.  There could very well
be a bug in the some of the more complex functions like shuffle and gainCard, and my current tests would miss them entirely.  Ideally, this is where overlap
between random testing and unit testing would be beneficial, as you're seldom going to end up with a decent test suite if only one style of testing is used.


--Assignment 3's results:
For all unit tests:
File 'dominion.c'
Lines executed:36.11% of 565
Branches executed:32.22% of 419
Taken at least once:24.11% of 419
Calls executed:27.66% of 94
Creating 'dominion.c.gcov'


--Assignment 4's results:
For randomtestcard.c:								For randomtestadventurer.c:
File 'dominion.c'									File 'dominion.c'
Lines executed:26.20% of 561						Lines executed:23.35% of 561
Branches executed:27.85% of 413						Branches executed:26.39% of 413
Taken at least once:17.43% of 413					Taken at least once:15.74% of 413
Calls executed:17.02% of 94							Calls executed:15.96% of 94

