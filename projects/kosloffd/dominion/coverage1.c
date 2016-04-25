My results from gcov after running all eight tests were:

44% Line coverage
52% branch coverage

This is actually kind of surprising to me that with eight unit tests I could cover nearly half of the lines of the program code.  I didn't find my tests to be too faulty, but I did miss a few parts of the code.

When checking the line coverage, I see that I only missed two lines in the eight functions that I tested.  In discardCard(), I missed executing the test for when there was only one card in the players hand.  Also in testing the remodel card, there was a bug for a value combination which I didn't think to test for and it resulted in a -1 return value, which I never reached.   I found the lines in scoreFor() were surprisingly executed from 40 - 250 times, and in contrast the playSmithy() function was only called once, though all lines were executed.  Overall, I think that the line coverage of the functions, though pretty low in number, were pretty good, as I did manage to reach all but two lines in those functions.

When checking the branch analysis, I had 100% branch coverage for gainCard() with a split of around 20% / 80-% for most branches. 

For discardCard(), I executed 89%, missing the branch noted above where there was one card in the player's hand. Again the branch coverage for the was 20/80 for setting the trash flag and 36 / 64 for the last card in the hand being the one discarded.

For the function buyCard(), my coverage was 100% with most branches having a split of about 30 / 70%.

For scoreFor(), my branch execution was 88%.  There were many single digit percentages when checking the deck and discard for victory cards, but I don't think matters as long as each one is checked because the entire deck isn't going to be victory cards.  I missed all of the checks for victory cards in the deck other than estate cards.  This can be improved in next update of the test suite.

playSmithy() is a very simple function, so all branches were covered adequately.

For playAdventurer(), I executed 100% of branches, although I never had the test draw a silver, just copper and gold.

When testing cardEffect() with council_room I executed all the branches and the average was about 40 / 60% for the branch execution.

When testing cardEffect() with remodel I missed one of the branches where I found a bug and didn't think to test a specific value in order to find it.  All other branch executions were what I would expect.