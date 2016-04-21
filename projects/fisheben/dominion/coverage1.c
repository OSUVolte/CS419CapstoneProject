/***************************************************************************************************************************************
* Description of the coverage achieved in unit tests of dominion code
*
* Note: Every funtion is tested with 2 players.  Each function is tested for no unexpected changes in 
* the victory card deck for the active player, no unexpected changes in the deck for the active player, no 
* unexpected state changes to the unactive player's deck, discardDeck, and hand.  The notes below discuss the
* additional tests that were conducted.
* 
* File 'unittest1.c'
* Lines executed:65.44% of 136
* Branches executed:83.67% of 98
* Taken at least once:46.94% of 98
* Calls executed:39.53% of 43
* Creating 'unittest1.c.gcov'
* Interpretation of unittest1.c.gcov shows lines 410 to 498 print statements never called
* Interpretation of dominion.c.gcov shows good coverage of function
function updateCoins called 1140 returned 100% blocks executed 100%
     1140: 1168:int updateCoins(int player, struct gameState *state, int bonus)
        -: 1169:{
        -: 1170:  int i;
        -: 1171:	
        -: 1172:  //reset coin count
     1140: 1173:  state->coins = 0;
        -: 1174:
        -: 1175:  //add coins for each Treasure card in player's hand
    71916: 1176:  for (i = 0; i < state->handCount[player]; i++)
branch  0 taken 98%
branch  1 taken 2% (fallthrough)
        -: 1177:    {
    70776: 1178:      if (state->hand[player][i] == copper)
branch  0 taken 4% (fallthrough)
branch  1 taken 96%
        -: 1179:	{
     2506: 1180:	  state->coins += 1;
        -: 1181:	}
    68270: 1182:      else if (state->hand[player][i] == silver)
branch  0 taken 1% (fallthrough)
branch  1 taken 99%
        -: 1183:	{
      132: 1184:	  state->coins += 2;
        -: 1185:	}
    68138: 1186:      else if (state->hand[player][i] == gold)
branch  0 taken 97% (fallthrough)
branch  1 taken 3%
        -: 1187:	{
    66132: 1188:	  state->coins += 3;
        -: 1189:	}	
        -: 1190:    }	
        -: 1191:
        -: 1192:  //add bonus
     1140: 1193:  state->coins += bonus;
        -: 1194:
     1140: 1195:  return 0;
        -: 1196:}
        -: 1197:
* Discussion: unittest1.c tests the updateCoins function.  The statement coverage of the test is 65.44%
* This low coverage reflects the fact that no bugs were found and due to this the print function (which is fairly large) was
* not executed.  The branch coverage is better at 83.67%, this more representative of the coverage as the print function
* has no branches.  Boundary cases tested in unittest1 are testing hands with a range of bonus coins from 0 to 10. It also tests the case 
* with no treasure cards in the players hand, another case where the player has no cards at all in hand or deck or discard deck.
* In both these cases the coins in the post call should equal the bonus coins.  Lastly the code tests 3 different max hands of gold, 
* silver and copper, to make sure the coins are summed properly.
* 
* File 'unittest2.c'
* Lines executed:66.90% of 142
* Branches executed:84.62% of 104
* Taken at least once:45.19% of 104
* Calls executed:36.59% of 41
* Creating 'unittest2.c.gcov'
* Interpretation of unittest2.c.gcov shows lines 449 to 538 print statements never called. 
* Interpretation of dominion.c.gcov shows good coverage of function 
function drawCard called 5172 returned 100% blocks executed 100%
     5172:  528:int drawCard(int player, struct gameState *state)
        -:  529:{	int count;
        -:  530:  int deckCounter;
     5172:  531:  if (state->deckCount[player] <= 0){//Deck is empty
branch  0 taken 1% (fallthrough)
branch  1 taken 99%
        -:  532:    
        -:  533:    //Step 1 Shuffle the discard pile back into a deck
        -:  534:    int i;
        -:  535:    //Move discard to deck
      348:  536:    for (i = 0; i < state->discardCount[player];i++){
branch  0 taken 93%
branch  1 taken 7% (fallthrough)
      324:  537:      state->deck[player][i] = state->discard[player][i];
      324:  538:      state->discard[player][i] = -1;
        -:  539:    }
        -:  540:
       24:  541:    state->deckCount[player] = state->discardCount[player];
       24:  542:    state->discardCount[player] = 0;//Reset discard
        -:  543:
        -:  544:    //Shufffle the deck
       24:  545:    shuffle(player, state);//Shuffle the deck up and make it so that we can draw
call    0 returned 100%
        -:  546:   
        -:  547:    if (DEBUG){//Debug statements
        -:  548:      printf("Deck count now: %d\n", state->deckCount[player]);
        -:  549:    }
        -:  550:    
       24:  551:    state->discardCount[player] = 0;
        -:  552:
        -:  553:    //Step 2 Draw Card
       24:  554:    count = state->handCount[player];//Get current player's hand count
        -:  555:    
        -:  556:    if (DEBUG){//Debug statements
        -:  557:      printf("Current hand count: %d\n", count);
        -:  558:    }
        -:  559:    
       24:  560:    deckCounter = state->deckCount[player];//Create a holder for the deck count
        -:  561:
       24:  562:    if (deckCounter == 0)
branch  0 taken 50% (fallthrough)
branch  1 taken 50%
       12:  563:      return -1;
        -:  564:
       12:  565:    state->hand[player][count] = state->deck[player][deckCounter - 1];//Add card to hand
       12:  566:    state->deckCount[player]--;
       12:  567:    state->handCount[player]++;//Increment hand count
        -:  568:  }
        -:  569:
        -:  570:  else{
     5148:  571:    int count = state->handCount[player];//Get current hand count for player
        -:  572:    int deckCounter;
        -:  573:    if (DEBUG){//Debug statements
        -:  574:      printf("Current hand count: %d\n", count);
        -:  575:    }
        -:  576:
     5148:  577:    deckCounter = state->deckCount[player];//Create holder for the deck count
     5148:  578:    state->hand[player][count] = state->deck[player][deckCounter - 1];//Add card to the hand
     5148:  579:    state->deckCount[player]--;
     5148:  580:    state->handCount[player]++;//Increment hand count
        -:  581:  }
        -:  582:
     5160:  583:  return 0;
        -:  584:}
* Discussion: unittest2.c tests the drawCard function.  The statement coverage of the test is 66.90%
* This low coverage reflects the fact that no bugs were found and due to this the print function (which is fairly large) was
* not executed.  The branch coverage is better at 84.62%, this more representative of the coverage as the print function
* has no branches.  
* Boundary cases tested in unittest2 are drawing a card from an empty deck and empty discard deck.  This ensures 
* that no additional cards are drawn.  Drawing a card from a empty deck but and a non empty discard deck.  This tests that the cards in 
* the discard deck are properly shuffled back into the deck before a card is drawn.  Lastly the code tests for a game state with cards in deck
* and cards in discard deck, and looks for any unexpected game states pre and post call.
*
* File 'unittest3.c'
* Lines executed:70.18% of 114
* Branches executed:75.56% of 90
* Taken at least once:47.78% of 90
* Calls executed:57.50% of 40
* Creating 'unittest3.c.gcov'
* Interpretation of unittest3.c.gcov shows lines 449 to 449 shows many print statements never called. 
* Interpretation of dominion.c.gcov shows one line did not execute, #####: 1116: state->handCount[currentPlayer]--;
function discardCard called 2220 returned 100% blocks executed 89%
     2220: 1093:int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)
        -: 1094:{
        -: 1095:	
        -: 1096:  //if card is not trashed, added to Played pile 
     2220: 1097:  if (trashFlag < 1)
branch  0 taken 46% (fallthrough)
branch  1 taken 54%
        -: 1098:    {
        -: 1099:      //add card to played pile
     1020: 1100:      state->playedCards[state->playedCardCount] = state->hand[currentPlayer][handPos]; 
     1020: 1101:      state->playedCardCount++;
        -: 1102:    }
        -: 1103:	
        -: 1104:  //set played card to -1
     2220: 1105:  state->hand[currentPlayer][handPos] = -1;
        -: 1106:	
        -: 1107:  //remove card from player's hand
     2220: 1108:  if ( handPos == (state->handCount[currentPlayer] - 1) ) 	//last card in hand array is played
branch  0 taken 11% (fallthrough)
branch  1 taken 89%
        -: 1109:    {
        -: 1110:      //reduce number of cards in hand
      240: 1111:      state->handCount[currentPlayer]--;
        -: 1112:    }
     1980: 1113:  else if ( state->handCount[currentPlayer] == 1 ) //only one card in hand
branch  0 taken 0% (fallthrough)
branch  1 taken 100%
        -: 1114:    {
        -: 1115:      //reduce number of cards in hand
    #####: 1116:      state->handCount[currentPlayer]--;
        -: 1117:    }
        -: 1118:  else 	
        -: 1119:    {
        -: 1120:      //replace discarded card with last card in hand
     1980: 1121:      state->hand[currentPlayer][handPos] = state->hand[currentPlayer][ (state->handCount[currentPlayer] - 1)];
        -: 1122:      //set last card to -1
     1980: 1123:      state->hand[currentPlayer][state->handCount[currentPlayer] - 1] = -1;
        -: 1124:      //reduce number of cards in hand
     1980: 1125:      state->handCount[currentPlayer]--;
        -: 1126:    }
        -: 1127:	
     2220: 1128:  return 0;
        -: 1129:}
        -: 1130:  
* not executed, this is because the successful test bypasses the other branches.
* Discussion: unittest3.c tests the discardCard function.  The statement coverage of the test is 70.18%
* This low coverage reflects the fact that only 1 bug was found.  The branch coverage is better at 75.56%, and it's value
* reflects that only one bug was found, some branches and statements are triggered from a finding bugs that are not executed.  Boundary cases tested
* in this unit test; different hand sizes from 1 to 10, different values for the trash flag, and different positions of the card to
* be discarded in the hand, from the 1st position to the last position in the hand.  The code then tests for no unexpected game states, correct hand
* count, and that the correct card was discarded.  The bug that was found was from the discardCount not being incremented after the call to 
* discardCard to reflect a card was discarded.
* 
* File 'unittest4.c'
* Lines executed:70.45% of 132
* Branches executed:100.00% of 70
* Taken at least once:75.71% of 70
* Calls executed:35.14% of 37
* Creating 'unittest4.c.gcov'
* Interpretation of unittest4.c.gcov shows lines 292 to 398 shows many print statements never called. 
* Interpretation of dominion.c.gcov shows good coverage of function.
function getCost called 186 returned 100% blocks executed 100%
      186:  586:int getCost(int cardNumber)
        -:  587:{
      186:  588:  switch( cardNumber ) 
branch  0 taken 3%
branch  1 taken 3%
branch  2 taken 3%
branch  3 taken 3%
branch  4 taken 3%
branch  5 taken 3%
branch  6 taken 3%
branch  7 taken 3%
branch  8 taken 3%
branch  9 taken 3%
branch 10 taken 3%
branch 11 taken 3%
branch 12 taken 3%
branch 13 taken 10%
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
branch 27 taken 6%
        -:  589:    {
        -:  590:    case curse:
        6:  591:      return 0;
        -:  592:    case estate:
        6:  593:      return 2;
        -:  594:    case duchy:
        6:  595:      return 5;
        -:  596:    case province:
        6:  597:      return 8;
        -:  598:    case copper:
        6:  599:      return 0;
        -:  600:    case silver:
        6:  601:      return 3;
        -:  602:    case gold:
        6:  603:      return 6;
        -:  604:    case adventurer:
        6:  605:      return 6;
        -:  606:    case council_room:
        6:  607:      return 5;
        -:  608:    case feast:
        6:  609:      return 4;
        -:  610:    case gardens:
        6:  611:      return 4;
        -:  612:    case mine:
        6:  613:      return 5;
        -:  614:    case remodel:
        6:  615:      return 4;
        -:  616:    case smithy:
       18:  617:      return 4;
        -:  618:    case village:
        6:  619:      return 3;
        -:  620:    case baron:
        6:  621:      return 4;
        -:  622:    case great_hall:
        6:  623:      return 3;
        -:  624:    case minion:
        6:  625:      return 5;
        -:  626:    case steward:
        6:  627:      return 3;
        -:  628:    case tribute:
        6:  629:      return 5;
        -:  630:    case ambassador:
        6:  631:      return 3;
        -:  632:    case cutpurse:
        6:  633:      return 4;
        -:  634:    case embargo: 
        6:  635:      return 2;
        -:  636:    case outpost:
        6:  637:      return 5;
        -:  638:    case salvager:
        6:  639:      return 4;
        -:  640:    case sea_hag:
        6:  641:      return 4;
        -:  642:    case treasure_map:
        6:  643:      return 4;
        -:  644:    }
        -:  645:	
       12:  646:  return -1;
        -:  647:} 
* Discussion: unittest4.c tests the getCost function.  The statement coverage of the test is 70.45%
* This low coverage reflects the fact that no bugs were found and so the cases and statements in which errrors are found are not executed.  
* The branch coverage is perfect at 100.00%, this more representative of the coverage as the print function
* has no branches but many statements.  Boundary cases tested in unittest4 are getting the cost of all the possible cards and then comparing the values 
* returned with a local copy of the correct values.  Unfortunately this will not test any new cards added at a later time.  It would be better if the 
* card values were stored in a static constant array so that any changes could be tested in the future.
* 
* File 'cardtest1.c'
* Lines executed:56.19% of 105
* Branches executed:91.18% of 68
* Taken at least once:51.47% of 68
* Calls executed:27.50% of 40
* Creating 'cardtest1.c.gcov'
* Interpretation of cardtest1.c.gcov shows lines 275 to 305 print statements never called, also with 315 to 384 unexecuted print statements
* Interpretation of dominion.c.gcov shows good coverage of function.
function mySmithy called 540 returned 100% blocks executed 100%
      540: 1318:int mySmithy(struct gameState *state, int currentPlayer, int handPos){
        -: 1319:	//+3 Cards
        -: 1320:	int i;
     2160: 1321:	for (i = 0; i < 3; i++)
branch  0 taken 75%
branch  1 taken 25% (fallthrough)
        -: 1322:	{
     1620: 1323:		drawCard(currentPlayer, state);
call    0 returned 100%
        -: 1324:	}
        -: 1325:		
        -: 1326:	//discard card from hand
        -: 1327:	//ADDED LOGIC ERROR SET TRASH FLAG TO 1
      540: 1328:	discardCard(handPos, currentPlayer, state, 1);
call    0 returned 100%
      540: 1329:	return 0;
        -: 1330:}
        -: 1331:
* Discussion: cardtest1.c tests the smithy card.  The statement coverage of the test is a very low 56.19% coverage.
* This low coverage reflects the fact that no bugs were found and so the cases and statements in which errrors are found are not executed.  
* The branch coverage is very good at 91.18%, this more representative of the coverage as most branches are executed but few error functions 
* are called.  Boundary cases tested in this card test, different hand sizes from 1 to 10, and different positions of the card to be
* discarded in the hand, from the 1st position to the last position in the hand.  The unit test then looks for the correct number of cards and
* that the smithy card was discarded properly after it was played.
*
* File 'cardtest2.c'
* Lines executed:82.61% of 161
* Branches executed:73.58% of 106
* Taken at least once:49.06% of 106
* Calls executed:73.08% of 52
* Creating 'cardtest2.c.gcov'
* Interpretation of cardtest2.c.gcov shows lines 541 to 591 print statements never called.  Lines 444-460 show many branches that were 
* not executed, this is because the successful test bypasses the other branches.
* Interpretation of dominion.c.gcov shows 3 lines fail to execute.
#####: 1210:		shuffle(currentPlayer, state);
#####: 1225:		state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1];
#####: 1226:		z=z-1;

function myAdventurer called 48 returned 100% blocks executed 86%
       48: 1201:int myAdventurer(struct gameState *state, int currentPlayer ){
        -: 1202:      
       48: 1203:  int z = 0;// this is the counter for the temp hand
        -: 1204:  int temphand[MAX_HAND];// moved above the if statement
       48: 1205:  int drawntreasure=0;
       48: 1206:  int cardDrawn = 0;
        -: 1207:
      192: 1208:	while(drawntreasure < 2){
branch  0 taken 67%
branch  1 taken 33% (fallthrough)
       96: 1209:		if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
branch  0 taken 0% (fallthrough)
branch  1 taken 100%
    #####: 1210:		  shuffle(currentPlayer, state);
call    0 never executed
        -: 1211:		}
       96: 1212:		drawCard(currentPlayer, state);
call    0 returned 100%
       96: 1213:		cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
        -: 1214:		
        -: 1215:		//ADDED A LOGIC BUG HERE WHERE CARD DRAWN IS ASSIGNED TO GOLD
       96: 1216:		if (cardDrawn == copper || cardDrawn == silver || (cardDrawn = gold))
branch  0 taken 67% (fallthrough)
branch  1 taken 33%
branch  2 taken 75% (fallthrough)
branch  3 taken 25%
       96: 1217:		  drawntreasure++;
        -: 1218:		else{
        -: 1219:		  temphand[z]=cardDrawn;
        -: 1220:		  state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
        -: 1221:		  z++;
        -: 1222:		}
        -: 1223:    }
       96: 1224:    while(z-1>=0){
branch  0 taken 0%
branch  1 taken 100% (fallthrough)
    #####: 1225:		state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
    #####: 1226:		z=z-1;
        -: 1227:    }
       48: 1228:      return 0;
        -: 1229:}
        -: 1230:
* Discussion: cardtest2.c tests the adventurer card.  The statement coverage of the test is 82.61% coverage reflecting lots of bugs found.
* This higher coverage reflects the fact that bugs were found and so the cases and statements in which errrors are found are executed.  
* The branch coverage is 73.58%, this is reflective of most of the unittests that have been analyzed in this discussion and seems to be the
* normal average.  Boundary cases tested in this card test, all treasure decks are tested using all gold deck, all silver deck and a all copper
* deck.  This tests that no cards are discarded and the correct hand count is found (should've also tested correct cards are added to hand but
* this wasn't done here).  The unit test then tests that the adventurer card is discard properly, this test fails and influences some of the 
* game state tests.  The next test is to see if the a deck with two treasure cards at the start of the deck will execute properly, ie all cards
* should be added to the discarded deck.  This test also fails, due to a bug I introduced into the adventurer card.  The final test is to test
* a deck with no treasure cards, this test again fails due to the bug that was introduced in the the adventurer card.  I noticed that the adventurer
* card implementation will enter an infinite loop if the deck has no treasure cards, this needs to be addressed.
* 
* File 'cardtest3.c'
* Lines executed:54.87% of 113
* Branches executed:82.50% of 80
* Taken at least once:45.00% of 80
* Calls executed:23.81% of 42
* Creating 'cardtest3.c.gcov'
* Interpretation of cardtest3.c.gcov shows lines 311 to 419 shows many print statements never called.
* Interpretation of dominion.c.gcov shows good coverage of function.
       -:  762:    case village:
        -:  763:      //+1 Card
      180:  764:      drawCard(currentPlayer, state);
call    0 returned 100%
        -:  765:			
        -:  766:      //+2 Actions
      180:  767:      state->numActions = state->numActions + 2;
        -:  768:			
        -:  769:      //discard played card from hand
      180:  770:      discardCard(handPos, currentPlayer, state, 0);
call    0 returned 100%
      180:  771:      return 0;   
* Discussion: cardtest3.c tests the village card.   The statement coverage of the test is 54.87%
* This low coverage reflects the fact that no bugs were found and so the cases and statements in which errrors are found are not executed. 
* The branch coverage is better at 82.50%, this more representative of the coverage because when bugs are detected function calls execute
* with little branching in the functions.  Boundary cases tested in this card test; different hand sizes from 1 to 10, and different positions of the card to be
* discarded in the hand, from the 1st position to the last position in the hand.  The unit test then looks for the correct number of cards and
* that the village card was discarded properly after it was played, and also if the player has the correct number of actions. 
* 
* File 'cardtest4.c'
* Lines executed:54.31% of 116
* Branches executed:81.40% of 86
* Taken at least once:44.19% of 86
* Calls executed:26.67% of 45
* Creating 'cardtest4.c.gcov'
* Interpretation of unittest4.c.gcov shows lines 330 to 447 shows many print statements never called. 
* Interpretation of dominion.c.gcov shows good coverage of function.
-:  824:    case great_hall:
        -:  825:      //+1 Card
      180:  826:      drawCard(currentPlayer, state);
call    0 returned 100%
        -:  827:			
        -:  828:      //+1 Actions
      180:  829:      state->numActions++;
        -:  830:			
        -:  831:      //discard card from hand
      180:  832:      discardCard(handPos, currentPlayer, state, 0);
call    0 returned 100%
      180:  833:      return 0;
* Discussion: cardtest4.c tests the great hall card.   The statement coverage of the test is 54.31%
* This low coverage reflects the fact that no bugs were found and so the cases and statements in which errrors are found are not executed. 
* The branch coverage is better at 81.40%, this more representative of the coverage because when bugs are detected some function calls execute
* with little branching in the functions.  Boundary cases tested in this card test, different hand sizes from 1 to 10, and different positions of the card to be
* discarded in the hand, from the 1st position to the last position in the hand.  The unit test then looks for the correct number of cards and
* that the great hall card was discarded properly after it was played, and also if the player has the correct victory points after playing the victory card, which
* should be 1 less than the pre call.
* 
* File 'dominion.c'
* Lines executed:35.21% of 568
* Branches executed:37.65% of 417
* Taken at least once:29.98% of 417
* Calls executed:18.75% of 96
* Creating 'dominion.c.gcov'
* Discussion: dominion.c statement coverage of the test is 35.21%.  This low coverage reflects the fact that few of the function in dominion were tested.
* and also some of the functions that were tested were did not have very good coverage, eg;  the card effect function.  The branch coverage for dominion.c
* is 37.65% and is also low.  The low branch coverage is due to the same reason the statement coverage is low, not very much of the code was tested.
*
*