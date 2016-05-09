Random History and Analysis
William George

Test Card for randomtestcard.out : minion
Total Tests Run: 47500795
Failed Tests: 2846630
Coverage randomtestcard.c: 94.34% of 53 Lines
Coverage dominion.c: 26.70% of 573

Analysis:
When looking over the coverage for the randomtestcard and with the minion card in dominion.c the random function calls almost every line. In the randomtestcard.c file the only line that did not run were those in the tests that did not fail. Specifically the one with the increase in the actions and the the line with the improper change in coins.

When looking over the cardEffect function in the dominion.c file it looks as if all the branches are covered in minion when I run the randomtestcard.c program. 

Test Card for randomtestadventurer.out : adventurer
Total Tests Run: 48801696
Failed Tests: 0
Coverage randomtestadventuere.c: 92.86% of 42 Lines
Coverage dominion.c: 21.12% of 573

Analysis:
My randomtestadventurer program had 92.86% coverage only because the test never failed as such the line within the failure statement did not run. In dominion.c I noticed the shuffle function in the adveruter case did not run meaning the deckCount variable never reached zero, adding a binary function or method that makes the state->deckCount equal some value that can be zero may be appropriate to increase the overall coverage.

After some careful thought I added a couple lines to vary the size of the deck. After doing so I got 100% coverage and the following results.

Total Tests Run: 23710819
Failed Tests: 160797
Coverage randomtestadventuere.c: 100.00% of 42 Lines
Coverage dominion.c: 23.04% of 573

As you can see the coverage was way better and it uncovered a bug with the shuffle function that somehow throws off the number of coins the player has. How this bug has occured I'm not quite sure of yet, but it has been localized to the shuffle function. As far as coverage of dominion.c is concerned the coverage increased because we are now calling the shuffle function. Overall the increase in coverage and the update in the specs for the test lead to a more robust random test that gave us a lot more information than the original iteration. 



