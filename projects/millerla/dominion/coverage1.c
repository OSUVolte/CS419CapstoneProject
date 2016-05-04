Name: Lauren Miller
Class: CS362
Assighnment: Assignment 3
Date: 4/23/2016

I used gcov the measure coverage for dominion.c after running my function and card tests. The output is included in unittestresults.out.

Given that my tests were for only designed to test some of the Dominion functions and, for the card tests, certain parts of playCard, I wasn't expecting complete coverage of dominion.c. In fact, my tests executed only 37% of the lines and 44% of branches were covered by my tests, although only 27% of these branches were taken. By itself, these numbers aren't particularly helpful, as it covered parts of dominion unrelated to my tests. While any imperfect testing of areas that I was interested in would obviously reduce these numbers, calling functions besides the ones I was testing, such as initializeGame, for my tests, would raise these numbers a certain amount. In short, these numbers aren't useful. However, seeing numbers in this range did at least confirm that I was using gcov correctly.

My coverage for the specific programs I tested was much better, although still not complete. I tested drawCard(), discardCard(), fullDeckCount(), and buyCard().

drawCard had 77% of lines executed, 100% of branches covered, and 67% of these branches taken at least once. My coverage for this fuction was the worst of all those I tested. I tested drawing from an empty deck after drawing all cards into the hand to confirm that no cards were added to the hand, but didn't test what would happen when there were cards in the discard pile that could be used. I also missed a branch dependant on deckCounter being above 0 when the deck was empty, indicating that deckCount was never not 0 when the deck was empty. This condition would be difficult to create and might not be generated during normal play, but I did miss it and the statements dependent on it. 

discardCard had 92% of lines executed, 100% of branches covered, and 83% of these branches taken at least once. I missed one condition, which was handCount being 1 for the currentPlayer. This seems to indicate a redundant if statement, as this situation should always be caught by a previous if statement that does the same as this missed one would have. 

fullDeckCount had 100% of lines executed, 100% of branches covered, and 93% of these branches taken at least once. Although this would seem to be very good, I did miss one crucial condition in my tests. I never tested fullDeckCount with cards in the discard deck, a significant oversight despite the numbers for lines executed, branches covered, and branches taken, which only result in part because of how some dependent code was put on the same line as its condition.

buyCard had 92% of lines executed, 100% of branches covered, and 83% of these branches taken at least once. I missed the condition where the number of buys was less than 0, and in fact my test made it so that the number of buys was always above it, not realizing that this was a condition I needed to test. All other branches were taken and lines executed.

The four card tests were for the Sea Hag, Smithy, Adventurer, and Village. The first three of these were ones that I had refactored and to which I had intentionally introduced errors for Assignment 2.

The Sea Hag case called sea_hag_card, which had covered 100% of lines and 100% of branches, and had 100% of these taken at least once, so nothing was missed as reported by gcov. Likewise, the Smithy case called smithy_card, which had covered 100% of lines and 100% of branches, and had 100% of these taken at least once, as with sea_hag_card.

The Adventurer card had less coverage. The Adventurer case called adventurer_card, which covered only 81% of lines and 100% of branches, but had 66% of these taken at least once. I missed the condition of calling adventurer_card when there were no cards left in the deck and it's dependent statement. This was a call to another function, shuffle, so in a sense little was missed. I wasn't interesting in testing the shuffle function, but it's use was part of adventurer_card. There was also a branch that depended on the variable z, which is set to 0 at the start of the function and never changed after. Given that z is 0 there is no way to change the value of z, it is impossible to test a condition and dependent statements that depend on z being greater than 0.

Village was the 4th card I tested, and the only one which had not been refactored previously. It had, as reported by gcov, very good coverage. It had zero branches. All statements were executed and all calls were returned.

Overall, my tests covered most branches but didn't necessarily take all of them. The tests executed all lines not dependent on these missed conditions, some of which were actually impossible to take. In retrospect, I should have made specfic note of all branches that could arise before creating the test and confirmed that all would be called by the unit tests in a more systematic way that I used. 
