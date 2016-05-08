/*                             RANDOM TEST COVERAGE


Summary: 
	1. playAdventurer was called 1000000 times and passed all random test cases. Initially
	   it was failing many tests (Segmentation fault: core dump).  These failures occurred
   	   when the total number of treasure cards between the deck and discard piles is less
	   than 2.  When this occurs, the playAdventurer function will attempt to draw cards 
	   until two 2 treasure cards are drawn ... causing the program to crash.  Although
	   this input scenario is rare,  it could happen and is mentioned in the official rules
	   of the game. Therefore, this should be reported to the game developer as a bug. In
	   order to continue with random testing, the input was adjusted so that at least 
	   2 treasure cards were available when the Adventurer card is played in order to 
	   prevent system crashes.
	   
	2. The random test on the Adventurer function covered 100% of the code blocks, with each     
	   line of code being executed at least 8% of 1000000 = 80000 times.  Comparing this  
	   with the card-test from Assignment3 illustrates a smaller percentage on branching
	   was achieved with random testing, largely because less effort was used in defining
	   the random input that would execute specific code blocks. However, overall raw coverage
	   was better with random testing(it found the problem when less than 2 treasure cards 
	   are available to be drawn).  
	   
	3. playSmithy was called 1000000 times and passed all random test cases. Similar to playAdventurer,
	   the playSmithy function initially failed many test due to the random input that was
	   generated.  In some cases, the random input would generate a hand with no cards, which
	   created a problem when the playSmithy function would try to play the Smithy card from
	   hand.  Of course, this was a problem with the Random tester, not the function being
	   tested.  Once the tester was corrected, all random tests passed.
	   
	4. The random test on the Smithy function covered 100% of the code blocks with a higher "better"
	   branching percentage than was achieved with the card-test from Assignment 3. 

	   
	NOTES:  
	
	       i) Details about what is checked by the Random Testers can be found as comments in the code,
	          particularly in the "oracle" function in randomtestadventure.c and randomtestcard.c
	   
	      ii) The combinational data structure used to check for correctness is described at the end
              of this file.		  
	   
                                   GCOV RESULTS
The results for each random test below was obtained with a "clean" directory so that
all results within the dominion.c.gcov file represented the results from a single random
test.
**************************************************************************************
                             Random Tester:  Adventurer
randomtestadventurer => Passed:1000000  Failed:0
File 'dominion.c'
Lines executed:10.41% of 605
Branches executed:7.19% of 417
Taken at least once:6.95% of 417
Calls executed:4.72% of 127
Creating 'dominion.c.gcov'
--------------------------------------------------------------------------------------
function playAdventurer called 1000000 returned 100% blocks executed 100%
  1000000:  824:int playAdventurer(struct gameState *state) {
        -:  825:    int cardDrawn;
  1000000:  826:    int drawntreasure=0;
  1000000:  827:    int currentPlayer = whoseTurn(state);
call    0 returned 100%
        -:  828:    int temphand[MAX_HAND];
  1000000:  829:    int z = 0;
  9921453:  830:    while(drawntreasure<2){
branch  0 taken 89%
branch  1 taken 11% (fallthrough)
  7921453:  831:	   if (state->deckCount[currentPlayer] < 1){//if the deck is empty we need to shuffle discard and add to deck
branch  0 taken 8% (fallthrough)
branch  1 taken 92%
   612386:  832:	      shuffle(currentPlayer, state);
call    0 returned 100%
        -:  833:	   }
  7921453:  834:	   drawCard(currentPlayer, state);
call    0 returned 100%
  7921453:  835:	   cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
  7921453:  836:	   if (cardDrawn == copper ||  cardDrawn == silver || cardDrawn == gold)
branch  0 taken 92% (fallthrough)
branch  1 taken 8%
branch  2 taken 91% (fallthrough)
branch  3 taken 9%
branch  4 taken 10% (fallthrough)
branch  5 taken 90%
  2000000:  837:	      drawntreasure++;
        -:  838:	   else{
  5921453:  839:	     temphand[z]=cardDrawn;
  5921453:  840:	     state->handCount[currentPlayer]--;
  5921453:  841:	     z++;
        -:  842:	   }
        -:  843:    }
  7921453:  844:    while(z-1>=0){
branch  0 taken 86%
branch  1 taken 14% (fallthrough)
  5921453:  845:        state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
  5921453:  846:	z=z-1;
        -:  847:    }
  1000000:  848:    return 0;
        -:  849:}
        -:  850:
**************************************************************************************		
                               Random Tester:  Smithy
randomtestcard => Passed:1000000  Failed:0
File 'dominion.c'
Lines executed:10.08% of 605
Branches executed:6.24% of 417
Taken at least once:5.04% of 417
Calls executed:4.72% of 127
Creating 'dominion.c.gcov'
------------------------------------------------------------------------------------
function playSmithy called 1000000 returned 100% blocks executed 100%
  1000000:  852:int playSmithy(struct gameState *state, int handPos) {
        -:  853:    int i;
  1000000:  854:    int currentPlayer = whoseTurn(state);
call    0 returned 100%
        -:  855:    //+3 Cards
  4000000:  856:    for (i = 0; i < 3; i++)
branch  0 taken 75%
branch  1 taken 25% (fallthrough)
        -:  857:       {
  3000000:  858:	 drawCard(currentPlayer, state);
call    0 returned 100%
        -:  859:       }
        -:  860:			
        -:  861:    //discard card from hand
  1000000:  862:    discardCard(handPos, currentPlayer, state, 0);
call    0 returned 100%
  1000000:  863:    return 0;
        -:  864:}	
**************************************************************************************
                        DATA STRUCTURE USED IN ORACLES

In order to remove complexity due to the randomness of how cards are positioned
within a hand due to shuffles, a combinational data structure is used to represent
each card pile. The data structure is a 27 element array where each index represents
the number of cards in the card pile of a given card type. This eliminates sensitivity
to card permuations such that a given pile of cards is uniquely identified by the
data structure regardless of how the cards are ordered in the pile.

Each card pile, i.e. pre-deck, pre-hand, pre-discard, post-deck, post-hand, and 
post-discard is represented by a combinational data structure.  Although, one
cannot predict the contents of the post-deck or the post-discard data structure 
due to the randomness of the shuffle and resulting sequence of cards being 
drawn, one can make predictions on the total cards contained by these structures
For example

  Given    pre-deck, pre-hand, pre-discard,  post_hand
   Test:  (post-deck + post-discard) = (pre-deck + pre-discard) - (post-hand - pre-hand)

  Description: The cards in the post-deck and post-discard piles will equal the cards
  in the pre-deck and pre-discard minus the cards that were drawn and placed in the hand

Using these basic relationships, oracles for testing the Adventurer and Smithy cards were
developed. Comments were included in the "oracle" functions that described what
each Oracle is attempting to check.











*/
