For this assignment we wrote random testers for 2 cards.  Namely, the Adventurer
card and another card of our choosing.  I chose to randomly test Smithy as my
second card.


Random Setup:
Both of my random testing programs have the same basic setup.  The main difference
is the tests that they are running.  Both functions use the rand() function seeded
with the time because I didn't feel that the provided rngs.c gave random enough
values.  Next, I initialize a game and set card zero in player 0's hand equal to
the card that I am testing (Adventurer or Smithy).  The remaining cards in the hand
are random from the initial game setup in the initializeGame() function.  Then,
I get a random number up to 5 for the size of the deck.  I then loop though the
deck and fill it with random, non-treasure cards.  Next, I pick another random
number up to 4 for the number of treasure cards.  In a for loop, I over-write
random spots in the deck with a random treasure card.  Finally, I go through the
steps above with the discard pile so that it is also filled with up to 5 random
cards including up to 4 random treasure cards.  Since the deck and discard will
have varying amounts of cards in them and also varying amounts of treasure cards,
it is possible that they will contain zero cards or zero treasure cards.  This
affects my tests so I keep track of whether or not it is possible to draw 2
treasure cards (for Adventurer) or whether or not it is possible to draw 3 cards
(for Smithy).  Then, I print out the contents of the deck and discard pile so
that they can be used in the debugging process to understand more about the game
state on that particular run.  Lastly, I copy my game state to a test game state
and play my card (either Adventurer or Smithy depending on the card I'm testing).


Testing Adventurer:
My first test tests that the player received 2 treasure cards.  In order to 
minimize false failures for this test, I kept track of the sum of the treasure 
cards in the deck and discard pile when the card was played because if the random 
game setup caused the sum of the treasure cards in these piles to be less than 2, 
I didn't want the test to say that it failed since it was not possible to draw 2 
treasure cards.  Therefore, this test should only fail if it was possible to draw 
2 treasure cards and the player drew more or less than 2 treasure cards.

My second test tests that the player received 2 coins.  This is an inexact test
because it is really testing that the player’s coin value increased by at least 2.
This is inexact because this can happen if the player draws 2 copper treasure 
cards, but it can also happen if the player drew one silver or one gold treasure
card.  If the player only drew one silver or one gold, the value of the coins in
their hand would increase by at least 2, even though they only drew 1 treasure card.
In that way, this test isn’t very reliable.  It can tell if the player drew too 
few treasure cards, but not if the player drew enough treasure cards, or too many
treasure cards.  This is a limitation of the random setup and not knowing exactly
what the player has available to draw.

My next few tests check to make sure that the game state does not change for the
other player and that the victory, kingdom, and treasure card piles remain
unchanged.

My final test checks that Adventurer is the last card in the discard pile since
this is the last thing that is supposed to be done as part of playing Adventurer.


Testing Smithy:
My first test tests that the player drew 3 cards.  In order to minimize false
failures for this test, I kept track of the size of the deck and discard pile
when the card was played because if the random game setup caused the sum of these
piles to be less than 3, I didn't want the test to say that it failed since it was
not possible to draw 3 cards.  Therefore, this test should only fail if it was
possible to draw 3 cards and the player drew more or less than 3 cards.

My second test tests that the player received zero coins because while they might
draw a treasure card, updating the coins in the player's hand is not something that
is done in the cardEffect() function, it is done later in the playCard() function.
Since Smithy does not explicitly add coins as part of it's action, the player
should not receive any coins at this point.

My next few tests check to make sure that the game state does not change for the
other player and that the victory, kingdom, and treasure card piles remain
unchanged.

My final test checks that Smithy is the last card in the discard pile since
this is the last thing that is supposed to be done as part of playing Smithy.


Testing Runs:
For both cards, I performed the setup tests described above 1000 times.  I chose
this number because it seemed big enough to catch bugs in these small functions, 
but also small enough that a human had hope to digest the information provided
from the test output.  I also only printed information about the tests that failed
in each run to minimize extra information that might not help.


Differences with Unit Testing:
I don't test for quite as many things with my random testing of both the Smithy
and Adventurer cards because with the random game setup, I don't know as much
about each game.  In my unit tests, I was able to control exactly what was in
the player's hand, deck, and discard pile before the card was played so I knew
exactly what would be in their hand, deck and discard pile after the card was
played.


Bugs:
My random testing and unit testing revealed the same bugs in the cards.  Since I
didn't have control over the cards that the player had available to draw for Smithy
and Adventurer, the bugs didn't always show up with each run of the tests, but
since the tests are run many times with the random tester, they eventually all
showed up.

    Smithy Bugs:
    - The current player draws 1 extra card.
    - The discard pile is empty and does not contain the Smithy card that was
      played.
                  
    Adventurer Bugs:
    - The number of coins that the player has does not get updated after the player
      draws the treasure cards.
    - Discard pile is empty after Adventurer is played (Adventurer and non-treasure
      drawn cards are not discarded).


Coverage:
For Smithy, my coverage with both the unit tests and the random testing was 100% for 
both lines and branches executed, and for the “taken at least once” criteria.  For
Adventurer, my coverage with unit testing was: 88.89% lines executed, 100% branches 
executed, and 83.33% taken at least once.  With random testing on Adventurer, I was 
able to improve all of these to 100%.  I think this illustrates how hard it is to get
100% coverage with unit tests alone and that random testing can help you get the rest
of the way to 100% coverage.  However, my random testing also illustrates some of the
challenges with random testing in that you don’t control the input so it is harder, if
not impossible to run certain tests that require knowing the setup to know the expected
outcome.