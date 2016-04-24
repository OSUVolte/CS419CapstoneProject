Runa Trinh
CS 362
I created unit tests for the fullDeckCount(), isGameOver(),
discardCard(), and upDateCoins(). There was full coverage
for the updateCoins(), isGameOver(), and fullDeckCount().
The discardCard() had 93% coverage, but all the branches 
were executed. It mostly indicates that the cases that the 
functions were expecting will at least occur, but it does not
indicate whether the function can handle unexpected input or 
arugments passed to it. I put as much in the unit tests that
I could to check that other game variables/state that needed to
stay unchanged were not changed.

I also created unit tests for the four Dominions cards:
smithy, cutPurse, village and adventurer. There was full
coverage for the village card and smithy card. The coverage
for adventurer was 95%, but with full coverage of the branches.
The coverage for cutPurse was 85% with about the same for the 
branch coverage. The missing 15% was probably because I did not
know how to validate how to make the other player show their
hand when they did not a copper. I decided it was more important
cover the functions of the card. For the most part, these 
test cases will cover what the functions expect, but not for 
cases if the cards were called with the wrong input passed to it. 

Unfortunately even with just these tests, the coverage of the entire
dominion program is only at about 28% for both line and branch coverage.
In order to gain more coverage of the program, most of the card tests 
should be covered and more of the bigger, more often used functions
like playCard and buyCard should be covered.
