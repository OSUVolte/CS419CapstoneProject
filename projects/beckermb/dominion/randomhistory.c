/* Ben Beckerman
 CS362
 Assignment 4
 1 May 2016

randomtestadventurer.c Testing:
Run using: make randomtestadventurer.out

The following factors are randomized for each run of the test:
* Size of the player's hand
* Content of the player's hand
* Size of the player's discard pile
* Content of the player's discard pile
* Size of the player's deck
* Content of the player's deck.

The content of the adventurer card is primarily concerned with drawing and discarding cards, so these seemed like the factors that would most likely result in errors and so should be randomized. The tests are run for 30,000 iterations. After some deliberations, I decided on this number as likely to hit every combination of hand/deck/discard sizes. Ideally, we would hit every permutation of those piles' composition, but that number is prohibitively large (approximately 1.8e+97).

Each of these tests were run on each iteration of the random testing:
* Check to make sure card is discarded.
* Check to make sure 1 coin is added to hand if only 1 in deck/discard.
* Check to make sure 2 coins are added to hand if 2 or more in deck/discard.
* Check to see if 1 or 2 coins are removed from deck/discard
* Check to make sure that the total number of cards belonging to player is unaffected
* Check to make global supply is unaffected.
* Check to make sure other player's cards are unaffected.

The random testing had 100% branch and statement coverage over adventurerCardEffect method. Two bugs were revealed by the testing. The first is that the adventurer card is not discarded after it is played. That bug can be revealed in the testing. The second bug revealed during random testing is the one I introduced during the random testing. That bug limited the size of the temporary array for cards to 7, so that a seg fault would occur if the player had to draw more than 7 cards to find 2 coins. I have since fixed that bug so that the tests can complete, but the bug was usually discovered in less than 10 iterations.


randomtestcard.c Testing --
Run using: make randomtestcard.out

The card selected to use random testing is on is the village. Similiar to the the adventurer, the tests are run for 30,000 iterations for the same reason.
The following factors are randomized for each run of the test:
* Size of the player's hand
* Content of the player's hand
* Size of the player's discard pile
* Content of the player's discard pile
* Size of the player's deck
* Content of the player's deck.
* Number of actions available to player

The village card is relatively simple. It adds two actions and draws a card. Because of this, the key factors to randomize are the player's deck/discard for drawing, and the number of actions for adding the card.

The following tests are run on each iteration
* Check to make sure card was drawn
* Check to make sure handsize is appropriate.
* Number of actions available to player after card played.
* Check to make global supply is unaffected.
* Check to make sure other player's cards are unaffected.

The random testing had 100% statement coverage on the villageCardEffect method. It has no branches. The testing revealed the bug introduced in a previous assignment where the actions that the card was supposed to deliver are not actually added to the player's hand.

*/
