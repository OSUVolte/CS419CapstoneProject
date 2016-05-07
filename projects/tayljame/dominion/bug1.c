/***********
Author: James Taylor
Date: 4/24/16
Bug report from unit testing assignment 3



***********/

unittest1:
    No bugs to report.
        Game starts with 8 province cards by default.
        With province card = 1 game tested as not overflow_error
        With province card = 0  game tested as overflow_error

unittest2
    no bugs to report
        Initial supply counts for treasure cards all passed (46 copper, 40 Silver, 30 Gold)
        Initial supply of victory cards all passed (8 Province, 8 Duchy, 8 Estate)
        Initial supply of victory cards all passed
            tested starting counts for adventurer, smithy, mine. All reported 10 as expected.
        After changing 1 type of each card, treasure, victory and action cards to 1, tests all passed showing
            correctly updated supplyCount()
unittest3
unittest4

cardtest1:
    one bug found
        introduced bug of only adding 2 card instead of intended 3 was caught

        test for correctly updating Smithy card be put into played pile, passed.

cardtest2:
    no bugs to report when using default starting setup for Deck and Hand contents
        tests passed for updating treasure counts when adding two copper cards
        test also passed for correctly showing 1 discard of an Estate card into discard pil

cardtest3
	no bugs to report when using default starting setup and adding in great_hall card to hand for played
		test for action count increase passed
		test for player hand count passed
		test for played card pile updating with great_hall being sent to played pile, passed. 
		
cardtest4

