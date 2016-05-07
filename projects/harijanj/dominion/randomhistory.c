/*  Development of the random testers.
	By Jonathan Harijanto

1) Random Test Card -> Smithy
I wrote a random test code for "smithy" card.
The way it works basically it generates random number of player
from 1 - 4, and select one of them to be the "current" player
a.k.a main player. It initializes the deck size, hand size and 
discard size randomly. Then it assigns card to both deck and hand
after we know the size for the deck and hand. Before the test starts,
it memorizes the size of hand and deck so that we can use as comparison
after "Smithy" calls. After that, "smithy" card is called, and the 
comparison between the previous hand & deck size with the current
hand & deck size. There are several if-else conditions that will 
print whether "smithy" works perfectly or not. This whole test is
randomly automated, what's done manually probably when it has to
manually compare the previous hand&deck size with current hand&deck size.
The test shows that "smithy" doesnt work, because it gives the 'main' player
4 cards instead of 3 cards. However, the rest of effect works because other players
don't receive any cards at all, and the deck of main player decreased.
I checked "smithyCard" at dominion C, and realized that the "for-loop" loops until 
less than 5 instead of 4. Thus, I'm sure the bug that it gives player 4 cards because
of that. The testing coverage shows a really good result, it gives 100% for lines &
branches. I think this random test able to "hit" every statement for smithy.

2) Random Test Adventurer
I wrote a random test code for "adventurer" card.
The way it works basically it generates random number of player
from 1 - 4, and select one of them to be the "current" player
a.k.a main player. It initializes the deck size, hand size and 
discard size randomly. Then it sets to be the "main" player's turn
and assigns card to both player's deck, hand and discard. 
Before the test starts, it copies the size of hand and deck so that we 
can use as comparison after "Adventurer" calls. Furthermore, it also
counts the number of treasure card avaiable at hand & deck and memorizes
it to a variables. After that, "adventurer" is called, and it does a comparison.
It will count the number of treasure card avaiable at hand and deck.
There are several if-else conditions that will print whether "adventurer" works 
perfectly or not. This whole test is randomly automated, what's done 
manually probably when it has to manually count the previous hand&deck treasure card
with current hand&deck treasure card.
The test shows that "adventurer" doesn't work because it gives the "main" player more
than two treasure cards to hand. Unfortunately with this simple random test, it is
quite hard to determine where is the exact location of the bug. AdventurerCard has a more
complex function than smithyCard.
However, the testing coverage shows a really good result as well, it gives 100% for lines 
& branches. I think this random test able to "hit" every statement for adventurer.

--------------------------------------------------------
[harijanj@flip2 dominion]$ gcov -b randomtestadventurer
File 'randomtestadventurer.c'
Lines executed:100.00% of 49
Branches executed:100.00% of 48
Taken at least once:100.00% of 48
Calls executed:100.00% of 18
Creating 'randomtestadventurer.c.gcov'

[harijanj@flip2 dominion]$ gcov -b randomtestcard
File 'randomtestcard.c'
Lines executed:100.00% of 48
Branches executed:100.00% of 22
Taken at least once:86.36% of 22
Calls executed:100.00% of 27
Creating 'randomtestcard.c.gcov'
--------------------------------------------------------

*/