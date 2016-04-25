Jason Loomis
4/24/2016
Assignment 3: Unit Testing
Filename: coverage1.c

=== Coverage achieved by unit tests of dominion.c ===

=== OVERALL (cumulative coverage achieved by all unit tests) ===

*** GCOV COVERAGE RESULTS for dominion.c ***
File 'dominion.c'
Lines executed:43.74% of 567
Branches executed:50.84% of 419
Taken at least once:44.15% of 419
Calls executed:25.51% of 98

Overall, the suite of unit tests effectively covered about 44% of the dominion codebase, and 51% of the branches. In the grand scheme, this means that a lot of work remains for creating more unit tests to fill in the coverage and exercise more of the lines of the code. It is interesting that these tests--without intending to cover the whole of dominion.c--do a fair job of exercising a significant portion of the branches in the code.

One of the significant portions of the code that this testing leaves uncovered is (somewhat obviously) the card effects that were not tested. Clearly, better coverage would be achieved by testing all of the card effects. That was not within the scope of this assignment, but would be necessary for properly complete testing of the software--specifically, cardEffect should be thoroughly tested, each of the cases of its large switch statement should be exercised.

Grepping the unittestresults.out file for the called functions, we find:
FUNCTION				CALLED	RETURNED	BLOCKS EXECUTED
fullDeckCount			33183	100%		100%
isGameOver				26586	100%		100%
drawCard				1500	100%		100%
scoreFor				1260	100%		100%
compare					1134	100%		83%
shuffle					504		100%		100%
whoseTurn				351		100%		100%
cardEffect				351		100%		6%
discardCard				351		100%		78%
cardEffectAdventurer	270		100%		100%
getCost					261		100%		100%
cardEffectCouncilRoom	27		100%		100%
cardEffectSmithy		27		100%		100%
initializeGame			24		100%		95%
updateCoins				24		100%		82%
newGame					0		0%			0%
kingdomCards			0		0%			0%
playCard				0		0%			0%
buyCard					0		0%			0%
numHandCards			0		0%			0%
handCard				0		0%			0%
supplyCount				0		0%			0%
endTurn					0		0%			0%
getWinners				0		0%			0%
cardEffectFeast			0		0%			0%
cardEffectMine			0		0%			0%
cardEffectRemodel		0		0%			0%
gainCard				0		0%			0%

Which indicates that these unit tests called just over half of the functions from dominion.c a number of times, and the other half ZERO times. So to improve the testing of this software, the functions that are completely uncovered should be tested (e.g. buyCard, numHandCards, supplyCount, endTurn, getWinners, gainCard).

Further, not all of the functions covered above were actually being tested--rather, they were indirectly called by the functions and card effects that were being assessed. It would be very useful to perform explicit unit testing on these "worker" functions to gain some confidence that they were not the source of any bugs which were trickling down to the higher-level functions.


=== Discussion of Helper Functions ===
For this testing assignment, I created a library of "helper" functions to encapsulate much of the repeated code that I used to check the gameState.

Taking this approach was a double-edged sword. Immediately, for this assignment, it meant more work for me--I needed to ensure that I had debugged and tested my helper functions. And bugs in the tests could cause erroneous results for my unit testing (e.g. a tested function executes properly, but the unit test has a bug that causes the test to indicate that it has failed)--and this happened, more than once. To avoid that situation to the extent possible, I tried to make the helper functions very short (a few lines) and lay out the code neatly so the purpose of the functions could be taken in at a single glance, and mistakes made more obvious.

That said, it was also a blessing--once my helper functions were debugged, they helped me prevent copy-paste errors copying blocks of code from one place to the other and reusing constructs from the tests I had written. They also shortened the number of lines of code needed for the tests.


=== unittest1.c (tests dominion.c fullDeckCount() function) ===

*** GCOV COVERAGE RESULTS for dominion.c ***
File 'dominion.c'
Lines executed:18.52% of 567
Branches executed:19.09% of 419
Taken at least once:16.95% of 419
Calls executed:7.14% of 98
For complete captured output, see unittest1.out
And for verbose testing output, see unittest1.verbose.txt

This single test covered only about 18.5% of the lines and 19% of the branches of the code in dominion.c. That number seems sparing, but is actually inflated with respect to the total code covered by the function--all of my unit tests use initializeGame() to populate the gameState structures they test, and initializeGame() calls many other functions (shuffle, drawCard, etc.). However, ALL of the lines and ALL of the branches within this (simple) function were covered by unittest1--and MANY calls were made (my unit test steps through many combinations of inputs). Additionally, my unit test verified that this function had no unintended effects on the gameState (the function should just be counting cards, not changing anything). Ultimately, this unit test covered the function very well, and since no bugs were found, we can feel good about the proper behavior of this function when it is used elsewhere in the code.

function fullDeckCount called 33084 returned 100% blocks executed 100%
	33084:	327:int fullDeckCount(int player, int card, struct gameState *state) {
		-:	328:	int i;
	33084:	329:	int count = 0;
		-:	330:
	79191:	331:	for (i = 0; i < state->deckCount[player]; i++)
branch	0 taken 58%
branch	1 taken 42% (fallthrough)
		-:	332:	{
	46107:	333:		if (state->deck[player][i] == card) count++;
branch	0 taken 4% (fallthrough)
branch	1 taken 96%
		-:	334:	}
		-:	335:
	79191:	336:	for (i = 0; i < state->handCount[player]; i++)
branch	0 taken 58%
branch	1 taken 42% (fallthrough)
		-:	337:	{
	46107:	338:		if (state->hand[player][i] == card) count++;
branch	0 taken 4% (fallthrough)
branch	1 taken 96%
		-:	339:	}
		-:	340:
	79191:	341:	for (i = 0; i < state->discardCount[player]; i++)
branch	0 taken 58%
branch	1 taken 42% (fallthrough)
		-:	342:	{
	46107:	343:		if (state->discard[player][i] == card) count++;
branch	0 taken 4% (fallthrough)
branch	1 taken 96%
		-:	344:	}
		-:	345:
	33084:	346:	return count;
		-:	347:}


=== unittest2.c (tests dominion.c getCost() function) ===

*** GCOV COVERAGE RESULTS for dominion.c ***
File 'dominion.c'
Lines executed:22.22% of 567
Branches executed:22.91% of 419
Taken at least once:20.76% of 419
Calls executed:7.14% of 98
For complete captured output, see unittest2.out
And for verbose testing output, see unittest2.verbose.txt

This single test covered only about 22% of the lines and 23% of the branches of the code in dominion.c. That number seems sparing, but is actually inflated with respect to the total code covered by the function--all of my unit tests use initializeGame() to populate the gameState structures they test, and initializeGame() calls many other functions (shuffle, drawCard, etc.). However, ALL of the lines and ALL of the branches within this (simple) function were covered by unittest2--this was a fairly straight-forward function to achieve this with, because internally, it is one long conditional switch statement. My unit tests were designed to exercise each of the branches. Additionally, my unit test verified that this function had no unintended effects on the gameState (the function should just be determining the cost of cards, not changing anything). Ultimately, this unit test covered the function very well, and since no bugs were found, we can feel good about the proper behavior of this function when it is used elsewhere in the code.

function getCost called 261 returned 100% blocks executed 100%
	  261:	587:int getCost(int cardNumber)
		-:	588:{
	  261:	589:	switch (cardNumber)
branch	0 taken 3%
branch	1 taken 3%
branch	2 taken 3%
branch	3 taken 3%
branch	4 taken 3%
branch	5 taken 3%
branch	6 taken 3%
branch	7 taken 3%
branch	8 taken 3%
branch	9 taken 3%
branch 10 taken 3%
branch 11 taken 3%
branch 12 taken 3%
branch 13 taken 3%
branch 14 taken 3%
branch 15 taken 3%
branch 16 taken 3%
branch 17 taken 3%
branch 18 taken 3%
branch 19 taken 3%
branch 20 taken 3%
branch 21 taken 3%
branch 22 taken 3%
branch 23 taken 3%
branch 24 taken 3%
branch 25 taken 3%
branch 26 taken 3%
branch 27 taken 7%
		-:	590:	{
		-:	591:	case curse:
		9:	592:		return 0;
		-:	593:	case estate:
		9:	594:		return 2;
		-:	595:	case duchy:
		9:	596:		return 5;
		-:	597:	case province:
		9:	598:		return 8;
		-:	599:	case copper:
		9:	600:		return 0;
		-:	601:	case silver:
		9:	602:		return 3;
		-:	603:	case gold:
		9:	604:		return 6;
		-:	605:	case adventurer:
		9:	606:		return 6;
		-:	607:	case council_room:
		9:	608:		return 5;
		-:	609:	case feast:
		9:	610:		return 4;
		-:	611:	case gardens:
		9:	612:		return 4;
		-:	613:	case mine:
		9:	614:		return 5;
		-:	615:	case remodel:
		9:	616:		return 4;
		-:	617:	case smithy:
		9:	618:		return 4;
		-:	619:	case village:
		9:	620:		return 3;
		-:	621:	case baron:
		9:	622:		return 4;
		-:	623:	case great_hall:
		9:	624:		return 3;
		-:	625:	case minion:
		9:	626:		return 5;
		-:	627:	case steward:
		9:	628:		return 3;
		-:	629:	case tribute:
		9:	630:		return 5;
		-:	631:	case ambassador:
		9:	632:		return 3;
		-:	633:	case cutpurse:
		9:	634:		return 4;
		-:	635:	case embargo:
		9:	636:		return 2;
		-:	637:	case outpost:
		9:	638:		return 5;
		-:	639:	case salvager:
		9:	640:		return 4;
		-:	641:	case sea_hag:
		9:	642:		return 4;
		-:	643:	case treasure_map:
		9:	644:		return 4;
		-:	645:	}
		-:	646:
	   18:	647:	return -1;
		-:	648:}
		-:	649:


=== unittest3.c (tests dominion.c scoreFor() function) ===

*** GCOV COVERAGE RESULTS for dominion.c ***
File 'dominion.c'
Lines executed:22.75% of 567
Branches executed:29.12% of 419
Taken at least once:26.73% of 419
Calls executed:10.20% of 98
For complete captured output, see unittest3.out
And for verbose testing output, see unittest3.verbose.txt

Again, this single test covered only about 23% of the lines and 30% of the branches of the code in dominion.c. That number seems sparing, but is actually inflated with respect to the total code covered by the function--all of my unit tests use initializeGame() to populate the gameState structures they test, and initializeGame() calls many other functions (shuffle, drawCard, etc.). However, ALL of the lines and ALL of the branches within this function were covered by unittest3--this was not terribly difficult to in unit testing because this function inspects the cards in a player's hand and as long as it sees all of the different cards in some fashion, it will be able to exercise all of its branches. Additionally, my unit test verified that this function had no unintended effects on the gameState (the function should just be counting cards and summing scores, not changing anything). Ultimately, this unit test covered the function very well, and revealed multiple bugs--all critical to fix for the sake of accurate scoring of the game!

function scoreFor called 1260 returned 100% blocks executed 100%
	 1260:	420:int scoreFor(int player, struct gameState *state) {
		-:	421:
		-:	422:	int i;
	 1260:	423:	int score = 0;
		-:	424:	//score from hand
	 2232:	425:	for (i = 0; i < state->handCount[player]; i++)
branch	0 taken 44%
branch	1 taken 56% (fallthrough)
		-:	426:	{
	  972:	427:		if (state->hand[player][i] == curse) { score = score - 1; };
branch	0 taken 4% (fallthrough)
branch	1 taken 96%
	  972:	428:		if (state->hand[player][i] == estate) { score = score + 1; };
branch	0 taken 4% (fallthrough)
branch	1 taken 96%
	  972:	429:		if (state->hand[player][i] == duchy) { score = score + 3; };
branch	0 taken 4% (fallthrough)
branch	1 taken 96%
	  972:	430:		if (state->hand[player][i] == province) { score = score + 6; };
branch	0 taken 4% (fallthrough)
branch	1 taken 96%
	  972:	431:		if (state->hand[player][i] == great_hall) { score = score + 1; };
branch	0 taken 4% (fallthrough)
branch	1 taken 96%
	  972:	432:		if (state->hand[player][i] == gardens) { score = score + (fullDeckCount(player, 0, state) / 10); };
branch	0 taken 4% (fallthrough)
branch	1 taken 96%
call	2 returned 100%
		-:	433:	}
		-:	434:
		-:	435:	//score from discard
	 2475:	436:	for (i = 0; i < state->discardCount[player]; i++)
branch	0 taken 49%
branch	1 taken 51% (fallthrough)
		-:	437:	{
	 1215:	438:		if (state->discard[player][i] == curse) { score = score - 1; };
branch	0 taken 4% (fallthrough)
branch	1 taken 96%
	 1215:	439:		if (state->discard[player][i] == estate) { score = score + 1; };
branch	0 taken 4% (fallthrough)
branch	1 taken 96%
	 1215:	440:		if (state->discard[player][i] == duchy) { score = score + 3; };
branch	0 taken 4% (fallthrough)
branch	1 taken 96%
	 1215:	441:		if (state->discard[player][i] == province) { score = score + 6; };
branch	0 taken 4% (fallthrough)
branch	1 taken 96%
	 1215:	442:		if (state->discard[player][i] == great_hall) { score = score + 1; };
branch	0 taken 4% (fallthrough)
branch	1 taken 96%
	 1215:	443:		if (state->discard[player][i] == gardens) { score = score + (fullDeckCount(player, 0, state) / 10); };
branch	0 taken 4% (fallthrough)
branch	1 taken 96%
call	2 returned 100%
		-:	444:	}
		-:	445:
		-:	446:	//score from deck
	 2475:	447:	for (i = 0; i < state->discardCount[player]; i++)
branch	0 taken 49%
branch	1 taken 51% (fallthrough)
		-:	448:	{
	 1215:	449:		if (state->deck[player][i] == curse) { score = score - 1; };
branch	0 taken 27% (fallthrough)
branch	1 taken 73%
	 1215:	450:		if (state->deck[player][i] == estate) { score = score + 1; };
branch	0 taken 15% (fallthrough)
branch	1 taken 85%
	 1215:	451:		if (state->deck[player][i] == duchy) { score = score + 3; };
branch	0 taken 1% (fallthrough)
branch	1 taken 99%
	 1215:	452:		if (state->deck[player][i] == province) { score = score + 6; };
branch	0 taken 1% (fallthrough)
branch	1 taken 99%
	 1215:	453:		if (state->deck[player][i] == great_hall) { score = score + 1; };
branch	0 taken 1% (fallthrough)
branch	1 taken 99%
	 1215:	454:		if (state->deck[player][i] == gardens) { score = score + (fullDeckCount(player, 0, state) / 10); };
branch	0 taken 1% (fallthrough)
branch	1 taken 99%
call	2 returned 100%
		-:	455:	}
		-:	456:
	 1260:	457:	return score;
		-:	458:}
		-:	459:


=== unittest4.c (tests dominion.c isGameOver() function) ===

*** GCOV COVERAGE RESULTS for dominion.c ***
File 'dominion.c'
Lines executed:18.69% of 567
Branches executed:18.14% of 419
Taken at least once:15.99% of 419
Calls executed:7.14% of 98
For complete captured output, see unittest4.out
And for verbose testing output, see unittest4.verbose.txt

This single test covered only about 19% of the lines and 18% of the branches of the code in dominion.c. That number seems sparing, but is actually inflated with respect to the total code covered by the function--all of my unit tests use initializeGame() to populate the gameState structures they test, and initializeGame() calls many other functions (shuffle, drawCard, etc.). However, ALL of the lines and ALL of the branches within this function were covered by unittest4. To achieve this coverage I chose a brute-force testing approach for this function, and tested a very large number carefully chosen combinations of inputs (specifically, empty card piles). In all, I think the amount of testing my unit test did was overkill, but it was effective and did reveal an important bug (for particular choices of kingdom cards). Additionally, my unit test verified that this function had no unintended effects on the gameState (the function should just be counting cards in the supply, not changing anything).

function isGameOver called 26586 returned 100% blocks executed 100%
	26586:	393:int isGameOver(struct gameState *state) {
		-:	394:	int i;
		-:	395:	int j;
		-:	396:
		-:	397:	//if stack of Province cards is empty, the game ends
	26586:	398:	if (state->supplyCount[province] == 0)
branch	0 taken 11% (fallthrough)
branch	1 taken 89%
		-:	399:	{
	 2943:	400:		return 1;
		-:	401:	}
		-:	402:
		-:	403:	//if three supply pile are at 0, the game ends
	23643:	404:	j = 0;
   614718:	405:	for (i = 0; i < 25; i++)
branch	0 taken 96%
branch	1 taken 4% (fallthrough)
		-:	406:	{
   591075:	407:		if (state->supplyCount[i] == 0)
branch	0 taken 11% (fallthrough)
branch	1 taken 89%
		-:	408:		{
	65016:	409:			j++;
		-:	410:		}
		-:	411:	}
	23643:	412:	if (j >= 3)
branch	0 taken 77% (fallthrough)
branch	1 taken 23%
		-:	413:	{
	18216:	414:		return 1;
		-:	415:	}
		-:	416:
	 5427:	417:	return 0;
		-:	418:}
		-:	419:


=== cardtest1.c (tests cardEffect for smithy) ===

*** GCOV COVERAGE RESULTS for dominion.c ***
File 'dominion.c'
Lines executed:21.87% of 567
Branches executed:23.63% of 419
Taken at least once:15.99% of 419
Calls executed:11.22% of 98
For complete captured output, see cardtest1.out
And for verbose testing output, see cardtest1.verbose.txt

The unit test for the smithy card effect achieved about 22% line and 24% branch coverage of the dominion.c code overall. Like the function unit tests above, this number is somewhat inflated with respect to the actual code covered by the card effect because the card tests use initializeGame() (which calls several other functions) to initialize the gameState that they will test. Looking at the smithy card effect code itself (it is encapsulated in a function) the function achieves 100% line and branch coverage. It is a very small, simple function, so this coverage was not overly difficult to achieve. This coverage helped reveal a bug that I had planted in this code in Assignment 2 (the for loop termination condition), so that was a good indication that my testing tested meaningful properties of the card effect. In addition to checking the direct effects of the card on the current player, the unit tests also verify that there are no unintended side-effects of this card on the other players (there should be none, this card affects the current player only). Ultimately, the testing found a bug in the code, but once that is fixed and the tests pass, we can feel confident about the performance of the smithy card effect within the overall code. 

function cardEffectSmithy called 27 returned 100% blocks executed 100%
	   27:	844:int cardEffectSmithy(int player, int handPos, struct gameState *state)
		-:	845:{
		-:	846:	int i;
		-:	847:
		-:	848:	//+3 Cards
	  135:	849:	for (i = 0; i <= 3; i++)
branch	0 taken 80%
branch	1 taken 20% (fallthrough)
		-:	850:	{
	  108:	851:		drawCard(player, state);
call	0 returned 100%
		-:	852:	}
		-:	853:
		-:	854:	//discard card from hand
	   27:	855:	discardCard(handPos, player, state, 0);
call	0 returned 100%
	   27:	856:	return 0;
		-:	857:}
		-:	858:


=== cardtest2.c (tests cardEffect for adventurer) ===

*** GCOV COVERAGE RESULTS for dominion.c ***
File 'dominion.c'
Lines executed:27.34% of 567
Branches executed:27.45% of 419
Taken at least once:20.05% of 419
Calls executed:13.27% of 98
For complete captured output, see cardtest2.out
And for verbose testing output, see cardtest2.verbose.txt

The unit test for the adventurer card effect achieved about 27% line and 27% branch coverage of the dominion.c code overall. Like the unit tests above, this number is somewhat inflated with respect to the actual code covered by the card effect because the card tests use initializeGame() (which calls several other functions) to initialize the gameState that they will test. Looking at the adventurer card effect code itself (it is encapsulated in a function) the function achieves 100% line and branch coverage. The adventurer is a function of sizeable complexity in the dominion codebase, so achieving 100% line and branch coverage was no small task. In my testing, there were a handful of "standard conditions" that I would test--verification of the card rules and that the card effect did not modify the state of any other players--and I ran those against numerous card deck configurations designed to exercise the different branches within the adventurer. The testing found several bugs, including the one I purposefully added for Assignment 2 (ignoring silver treasure cards), and another that would occur when the drawCard() function would return an error which was not being checked by the adventurer function code. The test coverage is good, and the tests did find meaningful problems with the adventurer card effect--I think that, as complicated as the adventurer is, once the bugs found are fixed, this testing will give confidence that the function is working properly.

function cardEffectAdventurer called 270 returned 100% blocks executed 100%
	  270:	650:int cardEffectAdventurer(int player, int handPos, struct gameState *state)
		-:	651:{
	  270:	652:	int drawntreasure = 0;
		-:	653:	int cardDrawn;
	  270:	654:	int z = 0;
		-:	655:	int temphand[MAX_HAND];// moved above the if statement
	  270:	656:	int shuffled = 0;
	 1647:	657:	while (drawntreasure <= 2) {
branch	0 taken 92%
branch	1 taken 8% (fallthrough)
	 1269:	658:		if (state->deckCount[player] < 1) {//if the deck is empty we need to shuffle discard and add to deck
branch	0 taken 30% (fallthrough)
branch	1 taken 70%
	  378:	659:			if (shuffled) break; // only allowed to shuffle once
branch	0 taken 43% (fallthrough)
branch	1 taken 57%
		-:	660:			else
		-:	661:			{
	  216:	662:				shuffle(player, state);
call	0 returned 100%
	  216:	663:				shuffled++;
		-:	664:			}
		-:	665:		}
	 1107:	666:		drawCard(player, state);
call	0 returned 100%
	 1107:	667:		cardDrawn = state->hand[player][state->handCount[player] - 1];//top card of hand is most recently drawn card.
	 1107:	668:		if (cardDrawn == copper || cardDrawn == copper || cardDrawn == gold)
branch	0 taken 78% (fallthrough)
branch	1 taken 22%
branch	2 taken 100% (fallthrough)
branch	3 taken 0%
branch	4 taken 28% (fallthrough)
branch	5 taken 72%
	  486:	669:			drawntreasure++;
		-:	670:		else {
	  621:	671:			temphand[z] = cardDrawn;
	  621:	672:			state->handCount[player]--; //this should just remove the top card (the most recently drawn one).
	  621:	673:			z++;
		-:	674:		}
		-:	675:	}
	 1161:	676:	while (z - 1 >= 0) {
branch	0 taken 70%
branch	1 taken 30% (fallthrough)
	  621:	677:		state->discard[player][state->discardCount[player]++] = temphand[z - 1]; // discard all cards in play that have been drawn
	  621:	678:		z = z - 1;
		-:	679:	}
		-:	680:	//discard card from hand
	  270:	681:	discardCard(handPos, player, state, 0);
call	0 returned 100%
	  270:	682:	return 0;
		-:	683:}


=== cardtest3.c (tests cardEffect for council_room) ===

*** GCOV COVERAGE RESULTS for dominion.c ***
File 'dominion.c'
Lines executed:22.57% of 567
Branches executed:24.58% of 419
Taken at least once:16.95% of 419
Calls executed:12.24% of 98
For complete captured output, see cardtest3.out
And for verbose testing output, see cardtest3.verbose.txt

The unit test for the council_room card effect achieved about 23% line and 25% branch coverage of the dominion.c code overall. Like the unit tests above, this number is somewhat inflated with respect to the actual code covered by the card effect because the card tests use initializeGame() (which calls several other functions) to initialize the gameState that they will test. Looking at the council_room card effect code itself (it is encapsulated in a function) the function achieves 100% line and branch coverage. The council_room is a function with some complexity (though simpler than the adventurer) in the dominion codebase, so achieving 100% line and branch coverage took some thought about the conditions to test. In my testing, there were a handful of "standard conditions" that I would test--verification of the card rules and that the card effect only modified the cards in the hands of the other players (and made no other modifications)--and I ran those against numerous card deck configurations designed to exercise the different branches within the council_room. The testing found the bug that I had placed in the function for Assignment 2 (no all other players would receive +1 card under certain conditions). The test coverage is good, and the tests did find a meaningful problem with the card effect. Ultimately, this testing will give confidence that the function is working properly when it can pass all the tests once its bugs are fixed.

 function cardEffectCouncilRoom called 27 returned 100% blocks executed 100%
	   27:	685:int cardEffectCouncilRoom(int player, int handPos, struct gameState *state)
		-:	686:{
		-:	687:	int i;
		-:	688:
		-:	689:	//+4 Cards
	  135:	690:	for (i = 0; i < 4; i++)
branch	0 taken 80%
branch	1 taken 20% (fallthrough)
		-:	691:	{
	  108:	692:		drawCard(player, state);
call	0 returned 100%
		-:	693:	}
		-:	694:
		-:	695:	//+1 Buy
	   27:	696:	state->numBuys++;
		-:	697:
		-:	698:	//Each other player draws a card
	  114:	699:	for (i = 0; i < state->numPlayers; i++)
branch	0 taken 76%
branch	1 taken 24% (fallthrough)
		-:	700:	{
	   87:	701:		if (i < player)
branch	0 taken 34% (fallthrough)
branch	1 taken 66%
		-:	702:		{
	   30:	703:			drawCard(i, state);
call	0 returned 100%
		-:	704:		}
		-:	705:	}
		-:	706:
		-:	707:	//put played card in played card pile
	   27:	708:	discardCard(handPos, player, state, 0);
call	0 returned 100%
		-:	709:
	   27:	710:	return 0;
		-:	711:}
		-:	712:
 
 
=== cardtest4.c (tests cardEffect for village) ===

*** GCOV COVERAGE RESULTS for dominion.c ***
File 'dominion.c'
Lines executed:21.52% of 567
Branches executed:23.15% of 419
Taken at least once:15.51% of 419
Calls executed:10.20% of 98
For complete captured output, see cardtest4.out
And for verbose testing output, see cardtest4.verbose.txt

The unit test for the village card effect achieved about 22% line and 23% branch coverage of the dominion.c code overall. Like the unit tests above, this number is somewhat inflated with respect to the actual code covered by the card effect because the card tests use initializeGame() (which calls several other functions) to initialize the gameState that they will test. Looking at the village card effect code itself the function achieves 100% line coverage (and has no branches). The village is a very simple function (like smithy), so achieving 100% coverage was not terribly difficult. In my testing, there were a handful of "standard conditions" that I would test--verification of the card rules (adding 1 card to the player's hand, incrementing the buy count) and that the card effect did not modify the state of any other players--and I ran those against card deck configurations and player and game configurations designed to exercise village card effect. Ultimately, this unit test covered the card effect very well, and since no bugs were found, we can feel good about the proper behavior of the village card effect when it is used elsewhere in the code.

		 -:	 903:	case village:
		-:	904:		//+1 Card
	   27:	905:		drawCard(currentPlayer, state);
call	0 returned 100%
		-:	906:
		-:	907:		//+2 Actions
	   27:	908:		state->numActions = state->numActions + 2;
		-:	909:
		-:	910:		//discard played card from hand
	   27:	911:		discardCard(handPos, currentPlayer, state, 0);
call	0 returned 100%
	   27:	912:		return 0;