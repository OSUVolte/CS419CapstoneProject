/******************************************************************************
* ASSIGNMENT 4 - randomhistory.c
* AUTHOR: Nickolas A. Williams
* CLASS: CS362
* DATE: 04/24/2016
* NOTES: random tester development discussion for Assignment 4
******************************************************************************/

/******************************************************************************
* dominion.c COVERAGE FOR randomtestadventurer.c - playAdventurer()
* Lines executed:22.76% of 558
* Branches executed:19.76% of 415
* Taken at least once:18.31% of 415
* Calls executed:9.57% of 94
*
* randomtestadventurer.c COVERAGE
* Lines executed:95.62% of 137
* Branches executed:100.00% of 110
* Taken at least once:87.27% of 110
* Calls executed:93.10% of 29
******************************************************************************/

/******************************************************************************
* dominion.c COVERAGE FOR randomtestcard.c - playSmithy()
* Lines executed:25.63% of 558
* Branches executed:21.69% of 415
* Taken at least once:19.52% of 415
* Calls executed:11.70% of 94
* Creating 'dominion.c.gcov
* 
* randomtestcard.c COVERAGE
* Lines executed:93.81% of 97
* Branches executed:100.00% of 60
* Taken at least once:70.00% of 60
* Calls executed:93.10% of 29
******************************************************************************/

/******************************************************************************
* DISCUSSION
* Most importantly:
* The weird bugs that random testing uncovered was nothing short of spooky.
* Just looking at the code for playAdventurer() and playSmithy(), it should
* not be possible to manipulate other players' cards at all. Yet somehow,
* given a large enough number of tests, I found that other players' decks
* were being manipulated. Getting to this point took a lot of work.
* 
* On to the normal preliminaries:
* The random testing for randomtestadventurer managed to execute 22.76% 
* of the dominion.c code, and the randomtestcard managed to execute 25.63%.
* This coverage was somewhat greater than I expected, given that the only
* other function of the code that playAdventurer() and playSmithy()
* reference is drawCard(). More surprising is that playSmithy() while simpler,
* references more other parts of dominion.c than playAdventurer().
* 
* Conducting this testing I noticed several bugs in the code that were not
* a part of my refactoring. First, playAdventurer() does not discard the
* adventurer card, which should be incorrect. This caused every test for
* discard pile increases to fail, and led to a restructuring of my tests.
* Second, I found that playSmithy() does not shuffle the discard into the
* deck if the deck has fewer than 3 cards, which I also read as incorrect.
* 
* Because certain almost all the tests were destined to fail, either because
* of my refactoring (playSmithy() draws the wrong number of cards) or because
* of bugs in the game already (playAdventurer() not discarding the adventurer),
* I had to rework how test failures were reported to get at the interesting
* bugs. Unlike the unit tests, where I could announce particular failures
* easily, with the random testing it became important to break individual
* failures into pieces. That is why my testing requirements headers are so
* much more granular, so that I can reference the failures and see the more
* interesting bugs. Specifically, the manipulation of other players' cards
* became apparent after I broke everything into individual failure cases.
* 
* One thing that I would do to make this more practical (and is definitely
* a lot of work) is implementing a system to store all the failed
* game TestStates, so another more detailed analysis of what particular
* interactions between all the cards caused the more esoteric failures.
******************************************************************************/