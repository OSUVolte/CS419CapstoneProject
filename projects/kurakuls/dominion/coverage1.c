UNIT TEST 1:

Testing supplyCount and Initializing Game.
Test complete.

File 'dominion.c'
Lines executed:17.47% of 561

I didn't find any bugs, but it is discouraging that only 17% coverage. Especially when you consider
that a lot of that was the game initialization. 


UNIT TEST 2:

Testing shuffle.
Test complete.

File 'dominion.c'
Lines executed:17.65% of 561

Another disappointing result with only 17% of the code being covered. Again a huge amount of that was intialization
However, inside of the shuffle function, I did manage to get a lot of branching so I could test all the 
aspects of it. I'm happy about that and really that seems realistic considering that it's only one function.


UNIT TEST 3:

Testing WhoseTurn.
Test complete.

File 'dominion.c'
Lines executed:18.00% of 561

A little better at 18%, but nothing to really celebrate. This was a rather simple function just trying to get
whose turn to tell me which player was going. 
I will admit, this was probably a low hanging fruit function to test, but it is used in several spots that are highly
important, so it's good to make sure it works.


UNIT TEST 4:

Testing numHandCards.
Test complete.

File 'dominion.c'
Lines executed:18.36% of 561

Another low hanging fruit, but at this point I was also really tired, so I didn't worry all that much.
Number of cards in a players hand does have a lot of influence so it's good to know that it works. There aren't
any branches here since it's a simple get function though.



CARD TEST 1:
Testing great_hall.
Test complete.

File 'dominion.c'
Lines executed:22.82% of 561

Great Hall is supposed to let you draw a card and discard it, so your hand count doesn't change and it allows you 
to add another action. 

My coverage was pretty decent considering this ran for four players and they all got what they needed.

It did branch into draw and discard and both of those were coverege very well.



CARD TEST 2:
Testing Gardens.
Test complete.

File 'dominion.c'
Lines executed:23.35% of 561

Low Hanging Fruit. I was just returning a -1 so it wasn't a tough test, but it did do it and now I know.






CARD TEST 3:

Testing Smithy.
Smithy Changes the handCount by more than 2.
Smithy Changes the handCount by more than 2.
Smithy Changes the handCount by more than 2.
Smithy Changes the handCount by more than 2.
Test complete.

File 'dominion.c'
Lines executed:30.48% of 561

This coverage was along the lines of what I would hope for a single factor. But I did program it to find a bug
that I had introduced. Originally, if you called Smithy, it would change the handcount by 2, but the bug I introduced
changes it by 3. The coverage was actually decent and it branched into the appropriate functions decently.


CARD TEST 4:
Testing Adventurer.
Adventurer adds less than two coins.
Adventurer adds less than two coins.
Adventurer adds less than two coins.
Adventurer adds less than two coins.
Test complete.

File 'dominion.c'
Lines executed:32.26% of 561

Best coverage out of the whole group. I felt strong about the branching that this used. I do wish that I had gone more 
in depth about coin counts instead of just declaring that it wasn't working. For example, I would show the
totals of the coin and it would help the user see how the bug was a simple error.

