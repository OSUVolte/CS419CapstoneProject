Author: Jonathan Hardman
File Name: coverage1.c

I primarily focused my coverage on all valid inputs of the various functions and 
cards that I was testing, looking for any true negatives, and for any unexpected
changes in game state variables. With that said the overall coverage percentage 
isn't very useful in that these are unit tests, they aren't designed to cover a lot
of the source code. I'll instead be evaluating the .gcov files and will be critiquing my 
input coverage and things I need to improve on with my tests.

Also note that I turned off all of the assertions for card tests for compiling purposes.
If you want the turn them on, then set AssertON = 1 at the top of each card test.

unittest1:	Function tested: initializeGame
			Thoughts: Looking through initializeGame function it appears that the only lines which 
					  I never hit were error return branches, which means I could use more testing in
					  boundry input values.
								  
unittest2-4:Functions tested: numHandCards, whoseTurn, getCost
			Thoughts: I'll be honest in that I chose these functions in order to be quick in finishing the assignment. 
					  I only had time for one weekend to work on these, so with that said there is a lot I could do better.
					  While the tests did technically cover all possible fetched values that it would expect in a normal game
					  of dominion, I could have been more creative and tested for abnormal games of dominion where gameState
					  values could be all over the place.
								  
cardtest1:	Card tested: Village
			Thoughts: With this test I wanted to make sure all of the card requirements were being met and nothing else was 
					  changing in the background without me noticing. The test covered every line of the village card effect, 
					  though I could do more environment testing for example, what is the maximum amount of actions, is there a limit?
					  It's something to test later.
					  
cardtest2:	Card tested: Council Room
			Thoughts: Like with village, I wanted to make sure all of the card requirements were being met and nothing else was 
					  changing in the background without me noticing. Got full coverage on tested card effect, and got a few bugs
					  which are mentioned in bug1.c. Otherwise I could do more environment test like for example what if the player
					  has reached MAX_HAND amount already?
					  
cardtest3:	Card tested: Adventurer
			Thoughts: This one was tricky because the effect is a bit unconventional. In order to test this code I needed to control
					  the what treasure cards were in the deck and hand of the player. So what I did was make a couple copies of 
					  initializeGame and changed each one so it would give each player silver and gold cards to start with rather 
					  than copper. This allowed me to test if the card effect was seeing and not altering the teasure cards in any way.
					  The risk with this however is that on some tests you will not get full coverage of the card efftect as a few branches 
					  will be missed like when it picks up a non-treasure card. THe are bugs with the card which are outlined in bug1.c. 
					  One thing I could do in order to prevent these holes in coverage is change the custom initializeGame functions so
					  that the card balances force you to pick up a non-treasure card at some point. And I'm sure there are several other
					  tests needed since there are so many conditions which could make using this card wonky.
					  
cardtest4:	Card tested: Smithy
			Thoughts: This test was fairly simple since the cards effect is simple. Nevertheless I still made sure all of the card 
					  requirements were being met and nothing else was changing in the background. It appears that I got full coverage
					  on tested card effect, and got a few bugs and caught a bug which is mentioned in bug1.c. Other than that I'm sure
					  there are tons of other more vigorous tests that would be way more complicated that I could have done with more time.
					  