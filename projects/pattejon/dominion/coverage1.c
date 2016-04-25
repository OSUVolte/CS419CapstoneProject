/* ---------------------------------------------------------------------
* Jon Patterson
* Assignment 3
* coverage1.c
* Discussion of test coverage
*----------------------------------------------------------------------*/

unittest1.c
	This test has 100% code coverage, and traverses 100% of 26 branches.
	For boundary coverage we attempt to test cases where all of the cards
	in hand are of one type, and ensuring that the proper number of coins
	is calculated. I then wrote a random tester to test random hands 
	containing various treasure cards.

unittest2.c
	For this test I found bugs that caused the code to segfault, for the 
	purposes of generating code coverage results I had to comment some
	of those branches out, with the knowledge that I had found a bug that
	theoretically would be fixed.
	For the remaining lines, 100% code coverage was obtained. 100% of 6 
	branches were traversed. The code attempted to handle cases were all
	the cards in the deck were drawn, drawing from an empty deck,
	discarding a card and drawing again.

unittest3.c
	This test obtained 96% code coverage. 100% of 12 branches were
	traversed. Discarding multiple cards in the hand was testied, as well
	as attempting to discard from an empty hand, which succeeded, 
	identifying a bug that exists in the implementation of the program.

unittest4.c
	For this test 100% code coverage was obtained. 100% of 30 branches
	were traversed as well. This test attempted to identify any bug
	in the isGameOver() method and was unable to find any problems.

cardtest1.c
	This test attempted to test the smithy card implementation that I
	deliberately introduced a bug into. 97% code coverage was obtained.
	100% of 14 branches were traversed. I attempted to perform a single 
	call of the program, since it doesn't take any other inputs other
	than the game state. My test identified the bugs that I had
	introduced into the method.

cardtest2.c
	This test was for the second mandatory card for the assignment,
	adventurer. I wrote the test to draw from the deck at the
	initialization of the game. 97% code coverage was obtained. 100%
	of 28 branches were traversed. I noted in bug1.c that there was
	an case where the code would fail to find two treasure cards in
	the deck, and due to how the re-shuffle implementation was 
	written, this could cause the program to loop indefinitely.

cardtest3.c
	For this test 97% code coverage was obtained. 100% of 18 branches
	were traversed. This test found similar bugs to the case described
	in the smithy function, as I had altered it in a similar way. The
	bug that I introduced was caught by the test.

cardtest4.c
	The last test written was testing another method that I deliberately
	broke. 97% code coverage was obtained. 100% of 12 branches were
	traversed. The bug introduced here was not obvious to me, even 
	though I was the one that introduced it. After reviewing the output
	I was able to verify that the bug displayed was due to the change that
	I had made.
