/****************************************************
 * Alisha Crawley-Davis
 * CS 362 Assn 4
 * 5/8/2016
 * randomhistory.c
 * Write up of development of random testers,
 * including improvements in coverage and effort
 * to check the correctness of your specification
 *
 * **************************************************/

/*
 * I decided to do random testing of the smithy card,
 * along with the adventurer card that was assigned.
 * I had run unit tests on both of these cards so I
 * was able to compare coverage and results for these
 * cards.
 *
 */

/* Smithy Card
 *
 * For the unit testing, I just arbitrarily chose
 * an original game state (number of players,
 * which cards were in the players hands, discard
 * piles, etc.)
 *
 * For the random testing, I had the program randomly
 * choose things like number of players, which cards
 * started in each players hands, decks, and discard
 * piles, which player was the current player, etc.
 * I made sure that the Smithy card was in the current
 * player's hand and tested the function from there.
 *
 * For the Smithy function, the random tester did not
 * find anything that the unit tests did not find
 * themselves.
 *
 * Please note that I only had the random tester run
 * 20 times in order to save space in randomtestcard.out.
 *
 * However, I also ran it with thousands of iterations
 * and did not find anything in addition to what could
 * already be found in fewer test cases.
 *
 * For the unit testing, I had 100% statement and 
 * 100% branch coverage of the Smithy function.
 *
 * For the random testing, I also had 100% statement
 * and 100% branch coverage of the Smithy function.
 *
 * Using line coverage, my 8 unit tests ended up covering
 * 44.09% of dominion.c.
 *
 * When I added the random test of the Smithy card,
 * the percentage increased slightly to 44.44%
 *
 * The low number is not surprising since I was
 * only testing a few parts of the program.
 *
 */

/* Adventurer Card
 * 
 * Like the Smithy card, for the unit testing, I just 
 * arbitrarily chose an original game state (number of 
 * players, which cards were in the players hands, discard
 * piles, etc.)
 *
 * Like the Smithy card, for the random testing, I had
 * the program randomly choose these things. I made sure
 * the Adventurer card was in the player's hand and tested
 * the function from there.
 *
 * Like the Smithy card, I only had the random tester run
 * 20 times in order to save space in randomtestadventurer.out.
 *
 * However, I also ran it with thousands of iterations and did
 * not find anything in addition to what could already be found
 * in fewer test cases.
 *
 * It was much more difficult to write and test the random tester
 * for the Adventurer card than it was for the Smithy card.
 *
 * Lots of things did not work as expected and it was difficult
 * to tell if it was because of bugs in my random tester or if
 * it was bugs in the program or both. I originally wished that
 * we had a clean version of dominion.c in order to use to test
 * our unit and random testers. But then I realized that in the
 * real world, the programs we are testing will not be clean!
 * It was an interesting challenge!
 *
 * For the unit testing, I had 93% branch coverage of the Adventurer
 * card function - I had forgotten to test the case where the deck needed
 * to be shuffled. This was not a problem for the random tester.
 * Even though I did not specifically think about it, it randomly
 * chose many cases where the deck would need to be shuffled. So for the
 * random tester, I improved both statement and branch coverage to 100%.
 *
 * Using line coverage, my 8 unit tests ended up covering
 * 44.09% of dominion.c.
 *
 * When I added the random tester of the Adventurer card,
 * the percentage increased slightly to 44.44%
 *
 * The low number is not surprising since I was only testing a few
 * parts of the program.
 *
 * Overall, this assignment led to a few interesting insights.
 * The random tester did not increase coverage of the Smithy function
 * and did not provide extra insights into bugs.
 *
 * However, the random tester did increase coverage of the Adventurer
 * function and led to many more insights/possible bugs being uncovered.
 *
 * I feel like there are even more bugs to be found (especially in the
 * Adventurer function), which helps explain that 100% coverage is
 * not the only thing needed for a good test suite.
 *
 * I also found that random testing can help find more insights.
 *
 * Finally, the assignment helped me realize the challenge of debugging
 * unit tests and random testers while also debugging the program that
 * the tests are running on!
 *
 */ 
