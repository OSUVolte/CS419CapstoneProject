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
	Once the randomization and game states were set up properly, a lot of the actual tests were based on what I had from Assignment 3.
When I ran the tester it was clear very quickly that I needed to cut down on the amount of information I was displaying to the user.  
I changed the earlier code from displaying both 'Success' and 'Failure' messages to displaying only failures.  That made the information
much easier to read and understand. The tester I ended up with loops for a set number of tests, creating a new/randomized game state for 
each run.  While running, the tester tests each game state *****

----Coverage----


/*---------------------------------------------------------*/

randomcardtestadventurer.c:

----Development----
	I remembered the Adventurer card from Assignment 3; it was probably the most difficult card to test properly.  Therefore,
I wasn't crazy about having to make a random tester for Adventurer, but it was part of the assignment.  Again, part of the 
difficulty was in making sure that the game state was truly randomized.  Compared to the Smithy card (which I did first), however,
the Adventurer card has quite a bit more going on.  The Smithy card basically just adds three cards to a user's deck; the Adventurerer
card has a lot more to evaluate and test.  The basic tests were fairly easy to implement, since they were basically checking the hand count,
deck count, discard count, and game state for errors.  
	Checking the treasure cards, however, took some time to figure out.  
	I implement a basic error counter that would display how many times a bug had occurred; I figured this might be a good
way to determine whether an error condition was a one-time fluke, or was a legitimate error.  Anything that I saw repeated, I felt fairly
sure could be labeled as an error.  It would also help me look for patterns.  I had this designed, then realized I could just look back through
the test results and achieve the same effect.
  One pattern that showed up from time to time but not consistently was an error that the second card added to Player 1's 
  
  
 ----Coverage---- 