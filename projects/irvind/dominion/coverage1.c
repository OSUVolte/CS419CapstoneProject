/*---------------------------------------
* Brett Irvin
* 4/20/16
* CS362_400 Software Engineering II
* Assignment 3--coverage1.c
* Describes the coverage results from 
* Assignment 3.
*---------------------------------------*/
Looking at the gcov results for my test suite, I ended up with the following coverage for dominion.c:

Unittest1, updateCoins():
   For this first unit test, I ended up with full 100% coverage.  All of the lines and branches were executed,
and every path was taken at least once.  This unit test tries many combinations of gold, silver, and copper 
treasure cards.  It's easy to overstate the effectiveness of this particular unit test; though it's at 100% coverage,
it's a fairly easy function to test, as there are only so many Treasure cards and variations to test.  As my other tests
will show, I still have plenty of room for improvement as a tester.

Unittest2, shuffle():
   The second unit test focused on the shuffle function, and once again, the 100% coverage I ended up with is deceiving.  Of 
all the tests I designed for Assignment 3, I was most unsure about this particular unit test.  I may have 100% on this test, but
to me it still needs additional testing.  Since the shuffle function is fairly critical to the rest of the game, this function needs
to be tested exhaustively.  To me, this unit test shows that you can't always rely on a 100% gcov coverage rate as an indicator
of quality testing.

Unittest3, isGameOver():
   This third unit test focused on isGameOver, and it also had 100% coverage--all lines and branches were taken at least once.  I feel 
fairly confident about this test, not because I'm an experienced tester, but because it was one of the easier tests to implement.  This 
function may still fail at some point, but it will be very obvious if you ever get an unexpected game over.  This one could use more testing,
but could probably take a back seat to more game-critical functions.

Unittest4, numHandCards():
   The fourth unit test addressed the numHandCards function, and ended up with complete coverage.  With 2 lines and no branches, numHandCards
is a fairly simple function to test, so like unit test #3 above, other, more important functions like scoreFor and getWinners would benefit more
from testing time, even if it happens at the expense of numHandCards. 

  
cardtest1, smithy:
   Taken against the rest of the cards available in Dominion, smithy is probably one of the easiest cards to test, simply because it's so simple.  We
were given the requirements for the smithy card, which ended up acting as a useful template for testing the other cards for Assignment 3.  I feel fairly
confident that the smithy card was tested sufficiently.  It returned a 100% coverage rate--but then again, there's plenty of room for further testing aside
from the simple tests I ran in cardtest1.

cardtest2, adventurer:
	Compared to smithy, adventurer was a good bit more difficult to test.  I ended up with 60% of lines executed, 66% of branches executed, and 41% of
of paths taken at least once.  The adventurer card clearly needs additional testing.  It's not nearly as cut-and-dried of a card as smithy, especially since 
the card provides the player with several choices.  There is plenty of room for improvement on cardtest2, even if it's just building on the existing tests I made
for this assignment.

cardtest3, village:
   The village card was fairly straightfoward to test, since it's a relatively simple card.  Gcov reported 100% coverage on this card, and since the card is so 
simple, the tests ended up being kind of trivial as well.  If I were testing this in a real world environment, with deadlines and managers in the background, it
would probably be wise to devote additional testing time to more complex cards like adventurer, even if it ends up being at the expense of testing village.

cardtest4, steward:
   Unlike the other 3 cards I tested, the steward card has not been broken into an individual function.  It's hard to really know how much of steward was tested, since
it's still a part of the larger dominion.c file.  Ideally, I guess a better approach would be to break something like steward out into its own separate function, then run
gcov on that function.  That will give you a more accurate idea of what you're actually testing and how effective it is.  However, I'm not sure how realistic that is; even
with a program as small as Dominion, it would be pretty time intensive to go back and break all of the cards out into separate functions.  I really don't know what the best 
solution in this scenario is.  A card like steward is pretty complex, so testing it is necessary, but at the same time, I don't think the real world would allow you to 
essentially rebuild an almost completed game like we have here.  It seems like gcov is useful in a lot of situations, but there needs to be some kind of alternate approach
in this scenario.  Since I'm new to testing, I have no idea what the conventional approach is when this kind of problem arises.   

--------

   Overall, the coverage rates I ended up with are somewhat misleading.  Several of my unit and card tests ended up with 100% coverage, but that is
deceiving.  There are plenty of larger, more specialized functions that probably should be tested instead of some of the ones I have chosen for 
this assignment.  Functions like playCard are essential to the Dominion game itself; if something like playCard is broken, then it renders the rest
of the game unplayable.  
   With that being said, the coverage rate of dominion.c is at 36% of lines covered, 32% of branches executed, 24% of paths taken at least once, and 27%
of calls executed.  To me, that's a much more accurate picture of my testing suite's effectiveness.  It's easy to look at a few individual test results or 
and get overly excited about seeing 100% coverage.  The better indicator of success is the coverage rate on a file like dominion.c.  At 36% coverage, it's
clear that there is a lot of room for improvement with my future tests.

File 'dominion.c'
Lines executed:36.11% of 565
Branches executed:32.22% of 419
Taken at least once:24.11% of 419
Calls executed:27.66% of 94
Creating 'dominion.c.gcov'