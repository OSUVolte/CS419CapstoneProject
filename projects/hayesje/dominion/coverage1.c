/*                               UNIT TEST COVERAGE

Summary;
    1. updateCoins called 80 returned 100% blocks executed 100%
       I was able to achieve decent statement and branch coverage by judiciously
       selecting various copper, silver, and gold combinations. The maximum
       percentage for any branch was 80%, while the minimum was 20%.

    2. gainCard called 351 returned 100% blocks executed 100%
       I was able to achieve decent statement and branch coverage, however I had to add
       a small number of additional test cases so that one branch (a check to determine if
       a supply stack is empty) would execute and return -1.

    3. discardCard called 48 returned 100% blocks executed 89%
       No matter how hard I tried, I could not get full block coverage. Looking into this
       further, it is believe the code is dead code using valid input ranges.  Given the
       code below, the only time the "else if" is true is when handCount = 1.  However, the
       only valid handPos when handCount=1 is handPos=0.  This combination will always cause
       the "if" statement to execute and prevents the "else if" block from ever executing.


            if ( handPos == (state->handCount[currentPlayer] - 1) )//last card in hand array is played
                    // Do this
            }
            else if ( state->handCount[currentPlayer] == 1 ) //only one card in hand
            {
                    // Never occurs for expected handCount/handPos combinations.
            }
            else
            {
                   //  Do that
            }

    4. isGameOver called 3655 returned 100% blocks executed 100%
       I was able to achieve decent statement coverage, however I only got 4% coverage
       on one of the branches with 3655 calls to isGameOver. Although that one branch
       percentage is small, the block was still executed several hundred times.

    5. playSmithy called 24 returned 100% blocks executed 100%
       It is believe that good statement and branch coverage was achieved.

    6. playAdventurer called 64 returned 100% blocks executed 100%
       The minimum percentage of branch coverage was 13%, therefore
       the each statement was executed a minimum of 8 times.

    7. playSalvager called 80 returned 100% blocks executed 100%
       The minimum percentage of branch coverage was 20%, therefore
       the each statement was executed a minimum of 16 times.

    8. playVillage called 400 returned 100% blocks executed 100%
       Good statement coverage ... no branches in playVillage.


    Return values:  Return values were only tested on functions that could potential return
                    different values.  These functions included isGameOver and gainCard.





                                   GCOV RESULTS
The results for each unit test below was obtained with a "clean" directory so that
all results within the dominion.c.gcov file represented the results from a single unit test.
**************************************************************************************
                             unittest1.c  updateCoints
Lines executed:1.82% of 605
Branches executed:1.92% of 417
Taken at least once:1.92% of 417
Calls executed:0.00% of 127
---------------------------------------------------------------------------------------
function updateCoins called 80 returned 100% blocks executed 100%
       80:  792:int updateCoins(int player, struct gameState *state, int bonus)
        -:  793:{
        -:  794:  int i;
        -:  795:
        -:  796:  //reset coin count
       80:  797:  state->coins = 0;
        -:  798:
        -:  799:  //add coins for each Treasure card in player's hand
      192:  800:  for (i = 0; i < state->handCount[player]; i++)
branch  0 taken 58%
branch  1 taken 42% (fallthrough)
        -:  801:    {
      112:  802:      if (state->hand[player][i] == copper)
branch  0 taken 21% (fallthrough)
branch  1 taken 79%
        -:  803:	{
       24:  804:	  state->coins += 1;
        -:  805:	}
       88:  806:      else if (state->hand[player][i] == silver)
branch  0 taken 27% (fallthrough)
branch  1 taken 73%
        -:  807:	{
       24:  808:	  state->coins += 2;
        -:  809:	}
       64:  810:      else if (state->hand[player][i] == gold)
branch  0 taken 38% (fallthrough)
branch  1 taken 63%
        -:  811:	{
       24:  812:	  state->coins += 3;
        -:  813:	}
        -:  814:    }
        -:  815:
        -:  816:  //add bonus
       80:  817:  state->coins += bonus;
        -:  818:
       80:  819:  return 0;
        -:  820:}
**************************************************************************************
                             unittest2.c  gainCard
Lines executed:2.48% of 605
Branches executed:1.44% of 417
Taken at least once:1.44% of 417
Calls executed:0.79% of 127
---------------------------------------------------------------------------------------
function gainCard called 351 returned 100% blocks executed 100%
      351:  755:int gainCard(int supplyPos, struct gameState *state, int toFlag, int player)
        -:  756:{
        -:  757:  //Note: supplyPos is enum of choosen card
        -:  758:
        -:  759:  //check if supply pile is empty (0) or card is not used in game (-1)
      351:  760:  if ( supplyCount(supplyPos, state) < 1 )
call    0 returned 100%
branch  1 taken 8% (fallthrough)
branch  2 taken 92%
        -:  761:    {
       27:  762:      return -1;
        -:  763:    }
        -:  764:
        -:  765:  //added card for [whoseTurn] current player:
        -:  766:  // toFlag = 0 : add to discard
        -:  767:  // toFlag = 1 : add to deck
        -:  768:  // toFlag = 2 : add to hand
        -:  769:
      324:  770:  if (toFlag == 1)
branch  0 taken 33% (fallthrough)
branch  1 taken 67%
        -:  771:    {
      108:  772:      state->deck[ player ][ state->deckCount[player] ] = supplyPos;
      108:  773:      state->deckCount[player]++;
        -:  774:    }
      216:  775:  else if (toFlag == 2)
branch  0 taken 50% (fallthrough)
branch  1 taken 50%
        -:  776:    {
      108:  777:      state->hand[ player ][ state->handCount[player] ] = supplyPos;
      108:  778:      state->handCount[player]++;
        -:  779:    }
        -:  780:  else
        -:  781:    {
      108:  782:      state->discard[player][ state->discardCount[player] ] = supplyPos;
      108:  783:      state->discardCount[player]++;
        -:  784:    }
        -:  785:
        -:  786:  //decrease number in supply pile
      324:  787:  state->supplyCount[supplyPos]--;
        -:  788:
      324:  789:  return 0;
        -:  790:}
**************************************************************************************
                             unittest3.c  discardCard
Lines executed:1.98% of 605
Branches executed:1.44% of 417
Taken at least once:1.20% of 417
Calls executed:0.00% of 127
---------------------------------------------------------------------------------------
function discardCard called 48 returned 100% blocks executed 89%
       48:  717:int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)
        -:  718:{
        -:  719:
        -:  720:  //if card is not trashed, added to Played pile
       48:  721:  if (trashFlag < 1)
branch  0 taken 50% (fallthrough)
branch  1 taken 50%
        -:  722:    {
        -:  723:      //add card to played pile
       24:  724:      state->playedCards[state->playedCardCount] = state->hand[currentPlayer][handPos];
       24:  725:      state->playedCardCount++;
        -:  726:    }
        -:  727:
        -:  728:  //set played card to -1
       48:  729:  state->hand[currentPlayer][handPos] = -1;
        -:  730:
        -:  731:  //remove card from player's hand
       48:  732:  if ( handPos == (state->handCount[currentPlayer] - 1) ) 	//last card in hand array is played
branch  0 taken 50% (fallthrough)
branch  1 taken 50%
        -:  733:    {
        -:  734:      //reduce number of cards in hand
       24:  735:      state->handCount[currentPlayer]--;
        -:  736:    }
       24:  737:  else if ( state->handCount[currentPlayer] == 1 ) //only one card in hand
branch  0 taken 0% (fallthrough)
branch  1 taken 100%
        -:  738:    {
        -:  739:      //reduce number of cards in hand
    #####:  740:      state->handCount[currentPlayer]--;
        -:  741:    }
        -:  742:  else
        -:  743:    {
        -:  744:      //replace discarded card with last card in hand
       24:  745:      state->hand[currentPlayer][handPos] = state->hand[currentPlayer][ (state->handCount[currentPlayer] - 1)];
        -:  746:      //set last card to -1
       24:  747:      state->hand[currentPlayer][state->handCount[currentPlayer] - 1] = -1;
        -:  748:      //reduce number of cards in hand
       24:  749:      state->handCount[currentPlayer]--;
        -:  750:    }
        -:  751:
       48:  752:  return 0;
        -:  753:}
**************************************************************************************
                             unittest4.c  isGameOver
Lines executed:1.65% of 605
Branches executed:1.92% of 417
Taken at least once:1.92% of 417
Calls executed:0.00% of 127
---------------------------------------------------------------------------------------
function isGameOver called 3655 returned 100% blocks executed 100%
     3655:  392:int isGameOver(struct gameState *state) {
        -:  393:  int i;
        -:  394:  int j;
        -:  395:
        -:  396:  //if stack of Province cards is empty, the game ends
     3655:  397:  if (state->supplyCount[province] == 0)
branch  0 taken 10% (fallthrough)
branch  1 taken 90%
        -:  398:    {
      378:  399:      return 1;
        -:  400:    }
        -:  401:
        -:  402:  //if three supply pile are at 0, the game ends
     3277:  403:  j = 0;
    85202:  404:  for (i = 0; i < 25; i++)
branch  0 taken 96%
branch  1 taken 4% (fallthrough)
        -:  405:    {
    81925:  406:      if (state->supplyCount[i] == 0)
branch  0 taken 10% (fallthrough)
branch  1 taken 90%
        -:  407:	{
     8424:  408:	  j++;
        -:  409:	}
        -:  410:    }
     3277:  411:  if ( j >= 3)
branch  0 taken 62% (fallthrough)
branch  1 taken 38%
        -:  412:    {
     2024:  413:      return 1;
        -:  414:    }
        -:  415:
     1253:  416:  return 0;
        -:  417:}
**************************************************************************************
                             cardtest1.c  Smithy
Lines executed:4.46% of 605
Branches executed:2.40% of 417
Taken at least once:1.44% of 417
Calls executed:2.36% of 127
---------------------------------------------------------------------------------------
function playSmithy called 24 returned 100% blocks executed 100%
       24:  853:int playSmithy(struct gameState *state, int handPos) {
        -:  854:    int i;
       24:  855:    int currentPlayer = whoseTurn(state);
call    0 returned 100%
        -:  856:    //+3 Cards
      120:  857:    for (i = 0; i <= 3; i++)
branch  0 taken 80%
branch  1 taken 20% (fallthrough)
        -:  858:       {
       96:  859:	 drawCard(currentPlayer, state);
call    0 returned 100%
        -:  860:       }
        -:  861:
        -:  862:    //discard card from hand
       24:  863:    discardCard(handPos, currentPlayer, state, 0);
call    0 returned 100%
       24:  864:    return 0;
        -:  865:}
**************************************************************************************
                             cardtest2.c  Adventurer
Lines executed:10.25% of 605
Branches executed:7.19% of 417
Taken at least once:6.71% of 417
Calls executed:4.72% of 127
---------------------------------------------------------------------------------------
function playAdventurer called 64 returned 100% blocks executed 100%
       64:  824:int playAdventurer(struct gameState *state) {
        -:  825:    int cardDrawn;
       64:  826:    int drawntreasure=0;
       64:  827:    int currentPlayer = whoseTurn(state);
call    0 returned 100%
        -:  828:    int temphand[MAX_HAND];
       64:  829:    int z = 0;
        -:  830:
      374:  831:    while(drawntreasure<2){
branch  0 taken 79%
branch  1 taken 21% (fallthrough)
      246:  832:	if (state->deckCount[currentPlayer] < 1){//if the deck is empty we need to shuffle discard and add to deck
branch  0 taken 13% (fallthrough)
branch  1 taken 87%
       32:  833:	  shuffle(currentPlayer, state);
call    0 returned 100%
        -:  834:	}
      246:  835:	drawCard(currentPlayer, state);
call    0 returned 100%
      246:  836:	cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
      246:  837:	if (cardDrawn == copper ||  cardDrawn == silver || cardDrawn == gold)
branch  0 taken 87% (fallthrough)
branch  1 taken 13%
branch  2 taken 70% (fallthrough)
branch  3 taken 30%
branch  4 taken 21% (fallthrough)
branch  5 taken 79%
      128:  838:	  drawntreasure++;
        -:  839:	else{
      118:  840:	  temphand[z]=cardDrawn;
      118:  841:	  state->handCount[currentPlayer]--;
      118:  842:	  z++;
        -:  843:	}
        -:  844:    }
      246:  845:    while(z-1>=0){
branch  0 taken 65%
branch  1 taken 35% (fallthrough)
      118:  846:        state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
      118:  847:	z=z-1;
        -:  848:    }
       64:  849:    return 0;
        -:  850:}
**************************************************************************************
                             cardtest3.c  Salvager
Lines executed:5.12% of 605
Branches executed:8.63% of 417
Taken at least once:2.64% of 417
Calls executed:4.72% of 127
---------------------------------------------------------------------------------------
function playSalvager called 80 returned 100% blocks executed 100%
       80: 1400:int playSalvager(struct gameState *state, int choice1, int handPos) {
       80: 1401:      int currentPlayer = whoseTurn(state);
call    0 returned 100%
        -: 1402:
        -: 1403:      //+1 buy
       80: 1404:      state->numBuys++;
        -: 1405:
       80: 1406:      if (choice1)
branch  0 taken 80% (fallthrough)
branch  1 taken 20%
        -: 1407:	{
        -: 1408:	  //gain coins equal to trashed card
       64: 1409:	  state->coins = state->coins + getCost( handCard(choice1, state) );
call    0 returned 100%
call    1 returned 100%
        -: 1410:	  //trash card
       64: 1411:	  discardCard(choice1, currentPlayer, state, 1);
call    0 returned 100%
        -: 1412:	}
        -: 1413:
        -: 1414:      //discard card
       80: 1415:      discardCard(handPos, currentPlayer, state, 0);
call    0 returned 100%
       80: 1416:      return 0;
        -: 1417:}
**************************************************************************************
                             cardtest4.c  Village
Lines executed:4.46% of 605
Branches executed:1.92% of 417
Taken at least once:0.96% of 417
Calls executed:2.36% of 127
---------------------------------------------------------------------------------------
function playVillage called 400 returned 100% blocks executed 100%
      400:  868:int playVillage(struct gameState *state, int handPos) {
        -:  869:    //+1 Card
      400:  870:    int currentPlayer = whoseTurn(state);
call    0 returned 100%
      400:  871:    drawCard(currentPlayer, state);
call    0 returned 100%
        -:  872:
        -:  873:    //+2 Actions
      400:  874:    state->numActions = state->numActions + 2;
        -:  875:
        -:  876:    //discard played card from hand
      400:  877:    discardCard(handPos, currentPlayer, state, 0);
call    0 returned 100%
      400:  878:    return 0;
        -:  879:}
*/
