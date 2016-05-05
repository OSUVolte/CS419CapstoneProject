The two cards which I implemented random testing 
for was the village card and the adventurer card.

The village card function gives the current player two 
additional actions and allows them to draw a card
and add to their hand. The input it takes is the 
current player, gamestate and the position of the
village card. The random test generated players from 
from 1 to MAX_PLAYERS(4). In addition, the deck, 
discard and hand count was randomnly generated 
from 0 to the MAX_DECK(500). I tried to account
for different various game states that the village
card function would get. I also kept track of the 
village card to make sure that it would get discarded
correctly as well and this was also had a randomnly
generated position in the hand. In addition, the
number of actions was also randomnly generated.

The oracle checks to make sure that the player
correctly gains 2 actions. It also checks the index
of where the village card was to make sure it is 
longer in the hand. With the addition of the the drawn 
card and the removal of the village card, the hand count 
shouldn't change. It checks that the deck count decremented
by one to account for the drawn card. It checks that the
discard deck incremented by one to account for the village card.
It also checks to make sure that the function returns 
with no error. 

I had it run 10000 times to check if there were any issues and
created an array that would keep check of any failed test cases 
for easy access to check. There was full coverage of the village
card. It also covered 14% of the dominion game which isn't too
bad for the random testing of one function. There were a few failed
test cases, but it was due to the fact that I didn't cover empty
decks in the oracle.

The adventurer card lets the current player draw from their deck
until they get two treasure cards and adds to their hand. The
input is the current player and game state. Similar to the village
card, I randomnly generated the player, deck, discard and hand count.
This time though, I actually populated the decks and discard pile since
it was necessary for the function to be able to stop when two treasure
cards were drawn. Two treasure cards were also randomnly generated
in either the deck or discard deck. The treasures were also randonly 
generated to account for all combinations of copper, silver and gold. 

For the oracle, it checked that the hand count increased by two to account
for the addition of the two treasure cards. It also checked the last
two cards in the hand to make sure they were treasure cards. 
The oracle also made sure that the check the function called without any
errors. In order to increase the efficiency of the random tester in the
future, I would probably want to put a way to check that the drawn
non-treasure cards were successfully discarded, but I wasn't sure
how to implement a way to check it. 

I also had this run 10000 times to check if there were any issues
and created an array to keep track of any failed test cases. There was 
full coverage of the adventurer card and all of its branches. It
also offered 11% coverage of the dominion game. 