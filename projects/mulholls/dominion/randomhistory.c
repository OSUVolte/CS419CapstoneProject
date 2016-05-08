Random History:

I started my development using the adventurercard. I had a general idea of how much
random I wanted to introduce to keep it effective. Essentially, I wanted to use
a technique similar to Assignment 3 where I created a random valid state to test
against, except this time the randomness would be the focus of the test. I decided
that I would improve my unitTestLib.c function setupRandomState to use the Random()
function from rngs.h and put more of the actual variables into a random but acceptable
state. In other words, I ensured there were a randomly picked number of players between
2 and 4, at least 7 copper, and 3 estates, in each player's hand/deck/discard, that only 
10 of the cards had some supplies in them, that for each estate/duchy/province there was
an allowed amount of cards in the supply, and then everything else was random but within
the allowed ranges of the game. I tried to balance the number of cards between players
up to the MAX_DECK/numPlayers but then I took a random number between 0 as the max cards
that player might have (i.e. in a 4 person game the state isn't generated to have more 
than 500 / 4 = 125 cards per player. I then made sure that the required 7 copper, especially
for the adventurer card, were spread out evenly through the hand, discard and deck. It was
possible there would be more copper, silver, and gold, but I wanted to make sure that at 
least the game minimum was distributed evenly.

This was the hardest part for the random testing. I then chose a random player to play
the adventurer card. I copied the state into a before state for comparisons, and then
ran the card and checked the state after the card against the before state for comparisons.
The first problem I ran into was that the adventurer card seg faulted because of the bug 
I introduced in our first assignment. I commented out that line of code in my dominion.c
and replaced it with a "working" line from the original. This would have been a bug I reported
for sure because the function was having memory issues.

Once the working line was in place I ran my test until it found 15 errors. I ended up finding
them pretty quickly. Based on a postcheck that I did, I found that the adventurer card was not
properly affecting the number of cards in the players hand. The player would end up with an 
extra card in their hand. This turned out to be because the adventurer card does not have a
point where it discards from the players hand. All 15 of the errors I was getting were for
this one error. I commented out that part of my tester and let the program run untouched for
about 5 minutes. At this point all my before and after checks were coming up clean. I
uncommented the successful test and upped the error count to 1000 as the limit and ran it
again. This time I checked my gcov file and found really good coverage of the cards functions.
The only line not being run a whole ton was the shuffle function. This still had 43 separete
runs in the adventurer card, but another 45 in the drawCard function. The drawCard function
itself was called 6681 times for the 1000 errors which seems about right considering the 
player should be drawing a random amount everytime to find 2 new treasures. I didn't have
to do much after this because to check for further bugs, I would have had to comment out
the known bug check and just let the test run until it found X amount of errors. This could
take 5 minutes, or 5 days. Or it could be indefinite if there's actually no errors.

I then moved onto the smithy card to test out. I approached it in a very similar way. I used
the same randomizer but set the checks for the smithy card's actions and checked the before
and after states. I found really quickly that the smithy wasn't doing much right. It doesn't
net the proper number of cards into the hand as it should, it doesn't discard the smithy
to the top of the discard pile, it changes then number of cards that exist in the deck from
before to after, and the total count of all the cards doesn't match. This tells me that
something is very wrong with the discard function. I checked the coverage, but the smithy 
card is pretty straightforward. The bug that I introduced has a lot of red herring code,
but essentially even with that code all the lines are run a good number of times and fairly
well balanced. The drawCard() function is called 507 times and in that the deck needed to be
shuffled an additional 6 times.  Every line in the drawCard() function is covered from the
test cases though. Every line has coverage in the shuffle calls as well. I didn't think I
needed to change much with the smithy card based on these tests and the initial coverage.

All in all the random test provided good coverage, and uncovered some readily apparent bugs
very quickly. Longer testing streaks that weren't masked by easily failed tests may turn up
more inconspicuous bugs as well.
