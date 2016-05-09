/***************randomtestadventurer.c: Adventurer Card *************/
The test found the bug for deck count, discard pile and played card count.
More testing conditions are added for the random test than unit test for 
this card. Other players state is also checked. Two bugs were found as followed:

FAILED: Played Card Count.
EXPECTED: 1 , ACTUAL 0

FAILED: Discard pile and Deck count.
Discard Pile before: 0 and after 3
Deck Count before: 5 and after 1

Coverage: Coverage is same as unit test
Below is coverage for adventurerEffect
Lines executed:100.00% of 18
Branches executed:100.00% of 12
Taken at least once:91.67% of 12
Calls executed:100.00% of 3

Below is coverage for adventurerEffect tester from dominion.c.gcov

function adventurerEffect called 35010 returned 100% blocks executed 100%
    35010:  661:int adventurerEffect(struct gameState *state, int handPos){
    35010:  662:  int drawntreasure = 0;
    35010:  663:  int z = 0;
        -:  664:  int temphand[MAX_HAND];
        -:  665:  int cardDrawn;
    35010:  666:  int currentPlayer = whoseTurn(state);
call    0 returned 100%
  4501860:  667:  while(drawntreasure<2){
branch  0 taken 99%
branch  1 taken 1% (fallthrough)
  4431840:  668:    if (state->deckCount[currentPlayer] <= 1){//if the deck is empty we need to shuffle discard and add to deck
branch  0 taken 1% (fallthrough)
branch  1 taken 99%
       11:  669:      shuffle(currentPlayer, state);
call    0 returned 100%
        -:  670:    }
  4431840:  671:    drawCard(currentPlayer, state);
call    0 returned 100%
  4431840:  672:    cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
  4431840:  673:    if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
branch  0 taken 98% (fallthrough)
branch  1 taken 2%
branch  2 taken 99% (fallthrough)
branch  3 taken 1%
branch  4 taken 0% (fallthrough)
branch  5 taken 100%
    70020:  674:      drawntreasure++;
        -:  675:    else{
  4361820:  676:      temphand[z]=cardDrawn;
  4361820:  677:      state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
  4361820:  678:      z++;
        -:  679:    }
        -:  680:  }
  4466850:  681:  while(z>=0){
branch  0 taken 99%
branch  1 taken 1% (fallthrough)
  4396830:  682:    state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
  4396830:  683:    z=z-1;
        -:  684:  }
    35010:  685:  return 0;
        -:  686:}


/**********randomtestcard.c : great_hall*****************/

All the test are passed for great_hall. assert statement were used 
All the assert statement passed. Below is coverage for great_hall tester from dominion.c.gcov

case great_hall:
        -:  912:      //+1 Card
     4000:  913:      drawCard(currentPlayer, state);
call    0 returned 100%
        -:  914:
        -:  915:      //+1 Actions
     4000:  916:      state->numActions++;
        -:  917:
        -:  918:      //discard card from hand
     4000:  919:      discardCard(handPos, currentPlayer, state, 0);
call    0 returned 100%
     4000:  920:      return 0;
