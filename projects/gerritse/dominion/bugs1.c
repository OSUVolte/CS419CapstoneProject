/*********************
Ellard Gerritsen
CS362 Assignment3

bugs1.c
***********************/

Quick Note:
In general, the function unit tests didn't catch any 
bugs but the card effect unit tests definitely did. This is likely
a combination of already introduced bugs plus the refactored cards that
were meant to be bug ridden. 


----------Unit Test 1----------

This test passed. No bugs were caught this time.


----------Unit Test 2----------

This test passed. No bugs. 


----------Unit Test 3----------

This test passed. No bugs.



----------Unit Test 4----------

This test passed. No bugs.


----------Card Test 1----------

This was the smithy card. This test failed. Total bugs caught ended up
being 2. The number of cards drawn was incorrect. I knew this would happen though
because this is the card I refactored into incorrectly drawning the number of cards 
when used. The other error was that the number of played cards came out to 2. This doesn't
make much sense since only the smithy card was played. Maybe something to look at in the future.

----------Card Test 2----------

This was the adventurer card. This test also failed with a total of 4 bugs. The first
bug was in the hand count after the card effect. 6 cards were expected but somehow 9 ended up
in the hand. The game is supposed to discard all cards drawn after the 2 treasure cards are drawn.
This was also a refactored card of mine. Another eror is that the deck count was at 0. The adventurer
card effect is supposed to shuffle the deck but it apparently didn't happen in this case. 
Another error was that the deck count of player 2 changed. Since this effect isn't supposed to change
another players gameState, I am not sure what happened here. The handCount also changed for player2 here
so thats another error.


----------Card Test 3----------

This was the council room card. 

This card passed my test. No bugs.



----------Card Test 4----------

This was the cutpurse card.

This card passed my test. No bugs. 




