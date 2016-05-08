/*Implications:
For the random test implementation, I reused the test cases from Assignment 3 card tests while adding additional tests to make a more thorough test suite and randomizing test parameters number of players( 2 – 4 ), current player (turn), which cards are in players’ hand, deck and discard piles. The card tests from Assignment 3 were fixed case, with 2 players and some hand, deck, discard pile combo and playing a particular card. Comparing actual and expected results can identify broken business rules or bugs in a fixed case test. However with the randomized test, we have 1000 tests of different inputs/game parameters, and the objective is to find the same bugs (and possibly new ones not identified during fixed case testing) so in the test results for Assignment 4 I paid close attention to whether the randomized tests still reproduced the correct failures on different inputs. One of the extra work of randomizing parameters is that you have to account for cases like the card for testing not being in the hand, or some necessary cards for playing a certain card are not in your deck causing the need to reshuffle (like for adventurer.) When the computer picks random cards for your piles it does not necessarily result in a test case that can reproduce bugs for a certain card whereas in a fixed case, you’re guaranteed to have test parameters that work for the test since you customized them yourself for testing the specific card.

Bugs:
For all the 1000 Adventurer tests with random parameters, a couple tests failed consistently which were the same ones that failed in Assignment 3. Actual handCount is not more than that of previous game state. This is due to the bug introduced in refactored Adventurer which causes player to draw cards until 1 additional treasure card is drawn instead of 2 resulting in actual post state hand count to be one less than expected.  Also Adventurer is still in the hand after being played, because it is not being discarded as it should.
For all the 1000 Village tests with random parameters, the number of actions test failed consistently like in Assignment 3. This is where the actual number of actions is 1 more than expected due to the bug introduced in refactored Village which gives players 3 additional actions instead of 2. Additionally the discard test failed too as well as the test whether village card remains in hand after playing which was not caught in Assignment 3. 
For both tests, game state was not changed (number players, supply count for each card, same embargo token amount for each card, same outposed played, same outpost turn, same whose turn, same phase, same number actions, same buys) and other player’s game state did not change (same deck count, hand count, discard count, same cards in hand, same cards in deck, same cards in discard) which was as expected.

Coverage:
Coverage was increased significantly for individual random tests however coverage of dominion.c decreased as can be seen below:

File 'dominion.c'
Lines executed:22.82% of 561
Branches executed:20.14% of 417
Taken at least once:18.47% of 417
Calls executed:10.42% of 96
For coverage of dominion.c, line execution was down from 33.69 to 22.82%, branch execution was down from 36.45 to 20.14%, taken at least once was down from 18.47 to 26.38%, and calls executed was down from 20.83 to 10.42%. This makes sense as this time there were only two functions being tested and both of these functions only call two functions (draw and discard card.) This makes it easier to find bugs because testing is shallow but as a result it doesn’t reach lots of other functions so coverage is lower.

File 'randomtestcard.c'
Lines executed:84.09% of 88
Branches executed:100.00% of 60
Taken at least once:76.67% of 60
Calls executed:100.00% of 18
For coverage of randomtestcard.c compared to cardtest3.c, there was some solid improvement. Lines executed went up slightly (81.90% - 84.09%), taken at least once went up significantly (57.50% - 76.67%) and calls executed is now 100% from 69.70%. Note that this is for setting “noisy_test” to 0 since turning on the printf’s results in more failure statements being skipped and makes coverage worse due to my extensive use of if’s in past two assignments. Another improvement was getting rid of tracking passes, eliminating non-essential else’s in the process. In this case including more tests and looping through large amounts of different, randomized input, I was able to find more bugs and more hard to find boundary cases.

File 'randomtestadventurer.c'
Lines executed:86.96% of 92
Branches executed:100.00% of 72 
Taken at least once:80.56% of 72
Calls executed:100.00% of 18
For coverage of randomtestadventurer.c compared to cardtest2.c, there was some solid improvement. Lines executed up went up slightly (84.16% - 86.92%), taken at least once went up significantly (57.41% - 80.56%) and calls executed is now 100% from 70%. Note that this is for setting “noisy_test” to 0 since turning on the printf’s results in more failure statements being skipped and makes coverage worse due to my extensive use of if’s in past two assignments. Another improvement was getting rid of tracking passes, eliminating non-essential else’s in the process. In this case including more tests and looping through large amounts of different, randomized input, I was able to verify the conclusions drawn from Assignment 3 were correct by testing on a bigger range of cases (such as cases where discard pile had to be shuffled into deck to produce enough treasure cards in hand.)*/












