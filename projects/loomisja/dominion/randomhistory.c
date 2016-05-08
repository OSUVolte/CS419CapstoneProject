Jason Loomis
5/8/2016
Assignment 4: Random Testing
Filename: randomhistory.c


=== Development of Random Testers ===

*** General Operation ***
For this assignment, random testers were developed for the Adventurer card effect (randomtestadventurer.c) and for the Smithy (randomtestcard.c). The operation of these testers has the following pattern: 1) generate a randomized game state, 2) copy that game state and execute the desired card effect on the copy, 3) use oracles to compare the before and after game states and verify the correctness of the card effect according to the card rules. This pattern is executed repeatedly by a loop, with a new randomized game state generated for each iteration.

*** Generating a Randomized Game State ***
The randomized game state is the primary input for the card effect, and forms the basis for all of the test scenarios that the random testers will test. It is really the heart of the random testing effort.

The simplest means of generating a "random" game state would have been to simply fill the gameState struct with random bytes. However, as we saw in the lectures in week 3, this is not an ideal approach, because most game states generated in this fashion will not be valid (e.g. the number of players may be negative, or the cards in each player's deck may not have valid indices into the CARD enumeration) and will likely not be internally consistent (e.g. the index of the current player may exceed the number of players for the game). Further, since the functions being tested are not user interface or external API functions (i.e. they are within the trust boundary of the program itself), the code being tested is not expected to be able to handle arbitrary input--rather, it is expected to handle input, a game state, that has been arrived at based on the rules of game play.

Knowing this, for this assignment, I chose to generate randomized game states that would generally be feasible as snapshots of some arbitrary Dominion game. This means that the random game state that is generated must be internally consistent, and should generally be within the bounds of the game rules. To that end, I created a function, randomizeGameState(), to perform this task. This function starts by choosing a random number of players for the game (2-4 players) and a random seed for the game's internal random number generators, then initializes a new game using the built-in initializeGame() function. This newly-initialized game ensures a reasonable initial game state. From that initial state, my randomization function randomizes the state of all the "global" game state variables: the (valid) supply card piles (supplyCount, which includes kingdom cards, treasure cards, curse cards, victory cards), the embargo tokens (if embargo is one of the kingdom cards), the current player (whoseTurn), and the decks, hands, and discards of all of the players. Additionally, it randomizes the state of the "current player" variables, the outpost (outpostPlayed, outpostTurn), the player's numActions, coins, numBuys, and the played cards. The phase is left alone (initialized to 0) as this game state is intended to represent a player during the "action" phase of his turn, when he is playing various cards. Finally, for the current player (whoseTurn), the randomizeGameState() function inserts the desired card at a random position in the player's hand, with the intention that this will be the card played.

The gameState variables are initialized with the following ranges:
* numPlayers: 2 <= numPlayers <= MAX_PLAYERS
supplyCount: all kingdom, treasure, victory, curse cards between 0 and game initial counts
* embargo: if embargo is in the kingdom, embargo tokens may be may be applied to any kingdom supply piles; the number of tokens applied is up to (10 - # embargoes remaining in supply)
* outpostPlayed: if outpost is in the kingdom, with a 1/32 chance, outpostPlayed flag is set to up to (10 - # outposts remaining in supply)
* outpostTurn: if the outpostPlayed flag is non-zero, outpostTurn is set to a value between 0 and 2.
* whoseTurn: a player between 0 and (numPlayers - 1) is selected
numActions: random value between 0 and 10 (arbitrary)
* coins: random value between 0 and 20 (arbitrary)
* numBuys: random value between 0 and 10 (arbitrary)
* cards counts: a cardcount is selected, between 0 and MAX_HAND, this value is then randomly divided among the deck, hand, and discard for each player; for the current player (whoseTurn), the distribution includes the played cards as well.
* cards: for the count of cards specified, the deck, hand, and discard are chosen randomly from among the kingdom, treasure victory, and curse cards; for the current player (whoseTurn), the playedCards are chosen as well.
* cardToPlay + handpos: for the current player (whoseTurn), the player's hand is specified to have at least 1 card and that card is specified to be cardToPlay and is set at any valid handpos for that player's hand.

The result is a gameState that could have been arrived at over the course of some arbitrary game, with the exception that the cards in play (in players' hands, decks, discards, and in the supply) may be more than might actually occur in a real game. Further, no attempt is made to ensure the consistency of the number of coins, buys, actions, or cards in hand with respect to the cards played--this would effectively mean implementing all of the card effects and other functions to guarantee this consistency. I opted to forgo this consistency in the interest of time.

*** Seeds and Reproducibility ***
As I implemented my randomization function, it makes heavy use of the pseudo-random number generator rand() for its operation. rand() generates a sequence of pseudo-random numbers, based on an initial starting seed--given the same seed, the same sequence of numbers will be generated. To that end, in my random test functions, an initial seed is provided that defines the sequence of random numbers that will be used to generate the game state. Supplying the same seed will regenerate the same game state. Providing this functionality means that if the seed is known, the exact conditions that resulted in an error can be reproduced. For the purpose of the random tester program, the initial seed is set based on the system clock time and so, ensures a sufficiently randomized set of tests will be run. However, included with the test results are the seeds that generated each game state so that any state can be re-generated if desired (e.g. for debugging).

*** Oracles ***
Random input, no matter what quality, is only half of the story. The other half is the oracle, the determination of whether the code under test has produced a correct or an incorrect result from the supplied input. If the randomized game state is the heart of the testing effort, the oracle is the brain.

For this assignment, I drew from the code that I developed for assignment 3 to devise my oracles. In assignment 3, I defined unit tests to exercise various card effects and game functions. Each of these tests ran a suite of general and specific (i.e. particular to the state of the player's hand/deck/discard) validation tests on the output produced, based on the particular card rules. I made use of many of these tests to define my oracles for this assignment. I also added deeper error checking in the oracle functions to prevent erroneous behaviour from aborting the test--specifically, I found that I needed to add a check of the card type values in the deck/hand/discard/played piles to ensure that invalid (i.e. non-CARD enumeration values) would not cause my oracle functions to experience buffer overflows.

The Adventurer has the following card rule: Reveal cards from your deck until you reveal 2 treasure cards. Put those Treasure cards in your hand and discard the other revealed cards.

Based on this rule, the following oracles were defined:
1) Check that the played card count has increased by exactly 1
2) Check that exactly 1 Adventurer has been added to the played cards
3) Check that number of cards in player's hand/played has increased by no more than 2
4) Check that the cards in player's hand have: decreased by 1 Adventurer and increased by up to 2 treasure cards
5) Check that number of cards in player's deck/discard decreased by no more than 2
6) Check that number of cards in player's hand/played increased by exactly the number that the deck/discard decreased
7) Check that the cards in player's hand/played increased by exactly the cards that the deck/discard decreased by
8) Check that the state of other players didn't change
9) Check that the state of the supply cards (kingdom, treasure, victory, curse) are unchanged.
10) Check other gameState fields (numPlayers, whoseTurn, etc.)

Each of these oracles must pass, given any random game state, in order for the Adventurer card effect to be considered correct.

Similarly, for the Smithy, the card rule is: +3 cards. The following oracles were defined:
1) Check that the played card count has increased by exactly 1
2) Check that exactly 1 Smithy has been added to the played cards
3) Check that number of cards in player's hand/played has increased by exactly 3*
4) Check that number of cards in player's deck/discard decreased by exactly 3*
5) Check that number of cards in player's hand/played increased by exactly the number that the deck/discard decreased
6) Check that the cards in player's hand/played increased by exactly the cards that the deck/discard decreased by
7) Check that the state of other players didn't change
8) Check that the state of the supply cards (kingdom, treasure, victory, curse) are unchanged.
9) Check other gameState fields (numPlayers, whoseTurn, etc.)

*unless the the deck/discard contained fewer than 3 cards, in which case the number changes by the number of cards in the deck/discard

Similarly, each of these oracles must pass, given any randomized game state, in order for the Smithy card effect to be considered correct.


=== Coverage ===

The random testing functions were executed each separately, 10000 times (i.e. 10000 randomized inputs), and were also both executed cumulatively (also 10000 times each) on the dominion code to arrive at the coverage results below. See 'randomtestadventurer.out' (generated with 'make randomtestadventurer.out' command) and 'randomtestcard.out' (generated with 'make randomtestcard.out' command) and 'randomtests.txt' (generated manually by running each random test program and collecting the coverage results).

*** OVERALL (cumulative coverage achieved by all random tests) ***
File 'dominion.c'
Lines executed:28.62% of 566
Branches executed:28.27% of 421
Taken at least once:21.38% of 421
Calls executed:16.33% of 98

Overall, running both random tests on the dominion code, about 28.6% line coverage and 28.2% branch coverage are achieved. This low overall coverage result is expected since these are very specific, targeted tests that are only executing very specific functions of the code. Obviously, better coverage would be achieved of the dominion.c source if more of the cards and other game functions were exercised.


*** randomtestadventurer.out (results for cardEffect for adventurer) ***
File 'dominion.c'
Lines executed:27.39% of 566
Branches executed:27.79% of 421
Taken at least once:20.43% of 421
Calls executed:13.27% of 98

The coverage achieved by running randomtestadventurer is very similar to that achieved overall, in this case over 27% of lines and branches executed. Again, this low overall coverage is expected since this is a specific test, targeted at a specific function.

Inspecting the gcov output for the coverage of the cardEffectAdventurer function, we can see that random testing exercised almost every block (95%), save for line 671 (which provides error handling for a very specific buffer overflow scenario). Under the unit testing performed for assignment 3, 100% block coverage was achieved for cardEffectAdventurer; however, the expanded range of conditions checked by the random testing necessitated modification of the cardEffectAdventurer code to prevent a possible buffer overflow and accompanying segmentation fault that would abort testing.

function cardEffectAdventurer called 10000 returned 100% blocks executed 95%
    10000:  650:int cardEffectAdventurer(int player, int handPos, struct gameState *state)
        -:  651:{
    10000:  652:	int drawntreasure = 0;
        -:  653:	int cardDrawn;
    10000:  654:	int z = 0;
        -:  655:	int temphand[MAX_HAND];// moved above the if statement
   309552:  656:	while (drawntreasure <= 2) {
branch  0 taken 97%
branch  1 taken 3% (fallthrough)
   289552:  657:		if (state->deckCount[player] < 1) {//if the deck is empty we need to shuffle discard and add to deck
branch  0 taken 19% (fallthrough)
branch  1 taken 81%
    54487:  658:			shuffle(player, state);
call    0 returned 100%
        -:  659:		}
   289552:  660:		drawCard(player, state);
call    0 returned 100%
   289552:  661:		cardDrawn = state->hand[player][state->handCount[player] - 1];//top card of hand is most recently drawn card.
   289552:  662:		if (cardDrawn == copper || cardDrawn == copper || cardDrawn == gold)
branch  0 taken 95% (fallthrough)
branch  1 taken 5%
branch  2 taken 100% (fallthrough)
branch  3 taken 0%
branch  4 taken 6% (fallthrough)
branch  5 taken 94%
    30000:  663:			drawntreasure++;
        -:  664:		else {
   259552:  665:			if (z < MAX_HAND) // bounds check to avoid segfault
branch  0 taken 100% (fallthrough)
branch  1 taken 0%
        -:  666:			{
   259552:  667:				temphand[z] = cardDrawn;
   259552:  668:				state->handCount[player]--; //this should just remove the top card (the most recently drawn one).
   259552:  669:				z++;
        -:  670:			}
    #####:  671:			else break;
        -:  672:		}
        -:  673:	}
   279552:  674:	while (z - 1 >= 0) {
branch  0 taken 96%
branch  1 taken 4% (fallthrough)
        -:  675:		// bounds check to avoid segfault
   259552:  676:		if(z <= MAX_HAND) state->discard[player][state->discardCount[player]++] = temphand[z - 1]; // discard all cards in play that have been drawn
branch  0 taken 100% (fallthrough)
branch  1 taken 0%
   259552:  677:		z = z - 1;
        -:  678:	}
        -:  679:	//discard card from hand
    10000:  680:	discardCard(handPos, player, state, 0);
call    0 returned 100%
    10000:  681:	return 0;
        -:  682:}


*** randomtestcard.out (results for cardEffect for smithy) ***
File 'dominion.c'
Lines executed:24.91% of 566
Branches executed:24.47% of 421
Taken at least once:17.81% of 421
Calls executed:12.24% of 98

The coverage achieved by running randomtestcard is a bit lower than that achieved overall, in this case nearly 25% of lines and branches executed. Again, this low overall coverage is expected since this is a specific test, targeted at a specific function.

Inspecting the gcov output for the coverage of the cardEffectSmithyfunction, we can see that random testing exercised every block. It is a very small, simple function, so this coverage was not overly difficult to achieve.

function cardEffectSmithy called 10000 returned 100% blocks executed 100%
    10000:  843:int cardEffectSmithy(int player, int handPos, struct gameState *state)
        -:  844:{
        -:  845:	int i;
        -:  846:
        -:  847:	//+3 Cards
    50000:  848:	for (i = 0; i <= 3; i++)
branch  0 taken 80%
branch  1 taken 20% (fallthrough)
        -:  849:	{
    40000:  850:		drawCard(player, state);
call    0 returned 100%
        -:  851:	}
        -:  852:
        -:  853:	//discard card from hand
    10000:  854:	discardCard(handPos, player, state, 0);
call    0 returned 100%
    10000:  855:	return 0;
        -:  856:}


*** Comparison to Unit Testing ***
The random testing performed for this assignment achieved comparable coverage to that achieved for the Adventurer and Smithy card effect unit tests performed for assignment 3. That said, there was little room for improvement from the unit tests in assignment 3, both of which achieved 100% coverage of their respective card effect functions.

The random testing generally revealed the same bugs that were found by the unit tests:

For Adventurer:
The testing found several bugs, including the one I purposefully added for Assignment 2 (ignoring silver treasure cards), and another that would occur when the drawCard() function would return an error which was not being checked by the adventurer function code. Additionally, the random testing revealed a bug wherein the game state values would be overwritten due to a buffer overflow (this one is related to the bug occurring when the return value of drawCard is ignored).

For Smithy:
The random testing revealed a bug that I had planted in this code in Assignment 2 (the for loop termination condition).

Random testing proved somewhat simpler to implement than the unit tests--where the unit tests required many lines of specific code to carefully set up particular game states for verification, the randomization function that I created for this testing was able to generate many scenarios to test automatically, and achieve comparable coverage and reveal the same bugs without the careful planning required by the unit tests.
