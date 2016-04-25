Stramel CS362 Assignment 3 Coverage Results
--------------------------------------------

OVERALL: dominion.c

    Through the 8 sets of unit tests that I created for dominion.c functions,
    I was able to exercise about 1/3 of the total code (lines and branches).

	File 'dominion.c'
	Lines executed:35.11% of 564
	Branches executed:37.89% of 417
	Taken at least once:35.01% of 417
	Calls executed:21.88% of 96
	Creating 'dominion.c.gcov'

    To get increased coverage I'd need to add unit tests for all of the other
    cards in the game - I only test 4 cards (smithy, adventurer, village, and
    council room).  These other cards (the cardEffect() function specifically)
    comprise the vast majority of uncovered code.  Additionally, I'd need to
    start working my way through the remaining functions that define the
    execution of the game itself.

    As noted above, dominion.c has 564 executable lines and 417 executable
    branches.  The following table shows by function the number of lines
    and branches REMAINING to be covered.  They are ordered from most to
    least remaining work to be done.

	function              lines       branches
	--------------------  ----------  ----------
	cardEffect            210         179
	getCost               30          28
	getWinners            24          22
	endTurn               20          6
	playCard              14          10
	buyCard               13          6
	gainCard              13          6
	kingdomCards          13          0
	initializeGame        10          2
	great_hallCardEffect  5           0
	handCard              3           0
	newGame               3           0
	numHandCards          2           0
	supplyCount           2           0
	whoseTurn             2           0
	compare               1           0
	discardCard           1           0
	--------------------  ----------  ----------
	total                 366         259

UNIT TEST #1: isGameOver()

	Through a total of seven (7) blocks of testing I was able to achieve 100%
	line and branch execution (including taking each branch) for the
	isGameOver() function.  In addition to hitting each line/branch I tested
	for a variety of combinations of cards including those at the boundaries
	of the card ENUM.  Though not allowed for this assignment, this function
	seemed an excellent candidate for random testing.

	Function 'isGameOver'
	Lines executed:100.00% of 10
	Branches executed:100.00% of 8
	Taken at least once:100.00% of 8
	No calls

UNIT TEST #2: scoreFor()

	Through a total of five (5) blocks of testing I was able to achieve 100%
	line and branch execution (including taking each branch) for the
	scoreFor() function.  I also ensured the all opportunies to make
	calls to other functions from within scoreFor() were exercised.

	Function 'scoreFor'
	Lines executed:100.00% of 24
	Branches executed:100.00% of 42
	Taken at least once:100.00% of 42
	Calls executed:100.00% of 3

UNIT TEST #3: fullDeckCount()

	Through a total of three (3) blocks of testing I was able to achieve 100%
	line and branch execution (including taking each branch) for the
	fullDeckCount() function.  Additionally I checked a variety of
	hand/deck/discard combinations including none.  I checked every card as
	well as boundaries of the card ENUM (cards that don't exist).

	Function 'fullDeckCount'
	Lines executed:100.00% of 9
	Branches executed:100.00% of 12
	Taken at least once:100.00% of 12
	No calls

UNIT TEST #4: updateCoins()

	Through a total of ten (10) blocks of testing I was able to achieve 100%
	line and branch execution (including taking each branch) for the
	updateCoins() function.  Additionally I checked a variety of
	coin + bonus combinations including none.  I checked to ensure that card
	weren't added from the wrong piles (deck/discard).  I checked every card
	as well as boundaries of the card ENUM (cards that don't exist).

	Function 'updateCoins'
	Lines executed:100.00% of 11
	Branches executed:100.00% of 8
	Taken at least once:100.00% of 8
	No calls

CARD TEST #1: SMITHY

	Through a total of six (6) blocks of testing I was able to achieve 100%
	line and branch execution (including taking each branch) for the
	smithyCardEffect() function.  I also ensured the all opportunies to make
	calls to other functions from within smithyCardEffect() were exercised.
    I tested all requirements that were deemed sufficient for full credit
    on the Canvas module about "testing for business rules" - including
    not just understanding the effect on the current player but testing
    for unexpected outcomes on other players and card piles.

	Function 'smithyCardEffect'
	Lines executed:100.00% of 5
	Branches executed:100.00% of 2
	Taken at least once:100.00% of 2
	Calls executed:100.00% of 2

CARD TEST #2: ADVENTURER

	Through a total of seven (7) blocks of testing I was able to achieve 100%
	line and branch execution for the adventurerCardEffect() function.  I
	also ensured the all opportunies to make calls to other functions from
	within adventurerCardEffect() were exercised.  I originally only had less
	coverage and I went back to manually create a case where there were no
	card in deck (moved to discard) to force a shuffle to increase coverage.

	This is the only test block where I didn't reach 100% of branches taken,
	however I did achieve 10 our of 12 branches taken.  However, I have
	exercised all of the logic.  The two missing branches are two of the coins
	in the following if statement.  But I absolutely did get into the code
	for one of the coins so in affect all of the code has been exercise.

	if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
	  drawntreasure++;

	Function 'adventurerCardEffect'
	Lines executed:100.00% of 18
	Branches executed:100.00% of 12
	Taken at least once:83.33% of 12
	Calls executed:100.00% of 3

CARD TEST #3: COUNCIL ROOM

	Through a total of seven (7) blocks of testing I was able to achieve 100%
	line and branch execution for the council_roomCardEffect() function.  I
	also ensured the all opportunies to make calls to other functions from
	within council_roomCardEffect() were exercised.
    I tested all requirements that were deemed sufficient for full credit
    on the Canvas module about "testing for business rules" - including
    not just understanding the effect on the current player but testing
    for unexpected outcomes on other players and card piles.

	Function 'council_roomCardEffect'
	Lines executed:100.00% of 9
	Branches executed:100.00% of 6
	Taken at least once:100.00% of 6
	Calls executed:100.00% of 3

CARD TEST #4: VILLAGE

	Through a total of seven (7) blocks of testing I was able to achieve 100%
	line and branch execution for the villageCardEffect() function.  I
	also ensured the all opportunies to make calls to other functions from
	within villageCardEffect() were exercised.
    I tested all requirements that were deemed sufficient for full credit
    on the Canvas module about "testing for business rules" - including
    not just understanding the effect on the current player but testing
    for unexpected outcomes on other players and card piles.

	Function 'villageCardEffect'
	Lines executed:100.00% of 5
	No branches
	Calls executed:100.00% of 2
