/*
-Coverage DATA can be found in unittestresults.out and dominion.c.gcov
-If this file is not present; execute 'make unittestresults.out'

**********Unit test 1**********
Coverage of test:
	Lines executed:87.50% of 32
	Branches executed:100.00% of 18
	Taken at least once:72.22% of 18
	Calls executed:66.67% of 12
	-This shows that there is good coverage of teh actual unit test, with the only lines being missed being print statements for errors that
	 were only ever found or not found, but not both.
	 
Coverage of function:

	function discardCard called 54 returned 100% blocks executed 89%
		   54: 1157:int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)
			-: 1158:{
			-: 1159:	
			-: 1160:  //if card is not trashed, added to Played pile 
		   54: 1161:  if (trashFlag < 1)
	branch  0 taken 100% (fallthrough)
	branch  1 taken 0%
			-: 1162:    {
			-: 1163:      //add card to played pile
		   54: 1164:      state->playedCards[state->playedCardCount] = state->hand[currentPlayer][handPos]; 
		   54: 1165:      state->playedCardCount++;
			-: 1166:    }
			-: 1167:	
			-: 1168:  //set played card to -1
		   54: 1169:  state->hand[currentPlayer][handPos] = -1;
			-: 1170:	
			-: 1171:  //remove card from player's hand
		   54: 1172:  if ( handPos == (state->handCount[currentPlayer] - 1) ) 	//last card in hand array is played
	branch  0 taken 19% (fallthrough)
	branch  1 taken 81%
			-: 1173:    {
			-: 1174:      //reduce number of cards in hand
		   10: 1175:      state->handCount[currentPlayer]--;
			-: 1176:    }
		   44: 1177:  else if ( state->handCount[currentPlayer] == 1 ) //only one card in hand
	branch  0 taken 0% (fallthrough)
	branch  1 taken 100%
			-: 1178:    {
			-: 1179:      //reduce number of cards in hand
		#####: 1180:      state->handCount[currentPlayer]--;
			-: 1181:    }
			-: 1182:  else 	
			-: 1183:    {
			-: 1184:      //replace discarded card with last card in hand
		   44: 1185:      state->hand[currentPlayer][handPos] = state->hand[currentPlayer][ (state->handCount[currentPlayer] - 1)];
			-: 1186:      //set last card to -1
		   44: 1187:      state->hand[currentPlayer][state->handCount[currentPlayer] - 1] = -1;
			-: 1188:      //reduce number of cards in hand
		   44: 1189:      state->handCount[currentPlayer]--;
			-: 1190:    }
			-: 1191:	
		   54: 1192:  return 0;
	-Coverage of the discardCard() function in dominion.c is also good. The branch that is missed will always be missed since if there is only one card in
	 a player's hand, then that card is also the last card in the hand and will be picked up by the previous if statement. The test cases also do not include
	 the presence of a trash flag.
	 
**********Unit test 2**********
Coverage of test:
	Lines executed:89.47% of 38
	Branches executed:75.00% of 16
	Taken at least once:37.50% of 16
	Calls executed:76.47% of 17
	-Again, the coverage is good and the only lines of code missed are print statements that did not execute because the test either alwasy passed or always failed.
	
Coverage of function:

	function getWinners called 4 returned 100% blocks executed 91%
			4:  457:int getWinners(int players[MAX_PLAYERS], struct gameState *state) {
			-:  458:  int i;	
			-:  459:  int j;
			-:  460:  int highScore;
			-:  461:  int currentPlayer;
			-:  462:
			-:  463:  //get score for each player
		   20:  464:  for (i = 0; i < MAX_PLAYERS; i++)
	branch  0 taken 80%
	branch  1 taken 20% (fallthrough)
			-:  465:    {
			-:  466:      //set unused player scores to -9999
		   16:  467:      if (i >= state->numPlayers)
	branch  0 taken 50% (fallthrough)
	branch  1 taken 50%
			-:  468:	{
			8:  469:	  players[i] = -9999;
			-:  470:	}
			-:  471:      else
			-:  472:	{
			8:  473:	  players[i] = scoreFor (i, state);
	call    0 returned 100%
			-:  474:	}
			-:  475:    }
			-:  476:
			-:  477:  //find highest score
			4:  478:  j = 0;
		   20:  479:  for (i = 0; i < MAX_PLAYERS; i++)
	branch  0 taken 80%
	branch  1 taken 20% (fallthrough)
			-:  480:    {
		   16:  481:      if (players[i] > players[j])
	branch  0 taken 0% (fallthrough)
	branch  1 taken 100%
			-:  482:	{
		#####:  483:	  j = i;
			-:  484:	}
			-:  485:    }
			4:  486:  highScore = players[j];
			-:  487:
			-:  488:  //add 1 to players who had less turns
			4:  489:  currentPlayer = whoseTurn(state);
	call    0 returned 100%
		   20:  490:  for (i = 0; i < MAX_PLAYERS; i++)
	branch  0 taken 80%
	branch  1 taken 20% (fallthrough)
			-:  491:    {
		   16:  492:      if ( players[i] == highScore && i > currentPlayer )
	branch  0 taken 25% (fallthrough)
	branch  1 taken 75%
	branch  2 taken 0% (fallthrough)
	branch  3 taken 100%
			-:  493:	{
		#####:  494:	  players[i]++;
			-:  495:	}
			-:  496:    }
			-:  497:
			-:  498:  //find new highest score
			4:  499:  j = 0;
		   20:  500:  for (i = 0; i < MAX_PLAYERS; i++)
	branch  0 taken 80%
	branch  1 taken 20% (fallthrough)
			-:  501:    {
		   16:  502:      if ( players[i] > players[j] )
	branch  0 taken 0% (fallthrough)
	branch  1 taken 100%
			-:  503:	{
		#####:  504:	  j = i;
			-:  505:	}
			-:  506:    }
			4:  507:  highScore = players[j];
			-:  508:
			-:  509:  //set winners in array to 1 and rest to 0
		   20:  510:  for (i = 0; i < MAX_PLAYERS; i++)
	branch  0 taken 80%
	branch  1 taken 20% (fallthrough)
			-:  511:    {
		   16:  512:      if ( players[i] == highScore )
	branch  0 taken 25% (fallthrough)
	branch  1 taken 75%
			-:  513:	{
			4:  514:	  players[i] = 1;
			-:  515:	}
			-:  516:      else
			-:  517:	{
		   12:  518:	  players[i] = 0;
			-:  519:	}
			-:  520:    }
			-:  521:
			4:  522:  return 0;
	-Coverage for the getWinners() function is not as good. The fact that some important lines are missed explains why the unit test is not working correctly.
	
**********Unit test 3**********
Coverage of test:
	Lines executed:90.70% of 43
	Branches executed:100.00% of 12
	Taken at least once:66.67% of 12
	Calls executed:80.95% of 21
	-Again, the coverage is good and the only lines of code missed are print statements that did not execute because the test either alwasy passed or always failed.
	
Coverage of function:
	function isGameOver called 4 returned 100% blocks executed 100%
			4:  390:int isGameOver(struct gameState *state) {
			-:  391:  int i;
			-:  392:  int j;
			-:  393:	
			-:  394:  //if stack of Province cards is empty, the game ends
			4:  395:  if (state->supplyCount[province] == 0)
	branch  0 taken 25% (fallthrough)
	branch  1 taken 75%
			-:  396:    {
			1:  397:      return 1;
			-:  398:    }
			-:  399:
			-:  400:  //if three supply pile are at 0, the game ends
			3:  401:  j = 0;
		   78:  402:  for (i = 0; i < 25; i++)
	branch  0 taken 96%
	branch  1 taken 4% (fallthrough)
			-:  403:    {
		   75:  404:      if (state->supplyCount[i] == 0)
	branch  0 taken 7% (fallthrough)
	branch  1 taken 93%
			-:  405:	{
			5:  406:	  j++;
			-:  407:	}
			-:  408:    }
			3:  409:  if ( j >= 3)
	branch  0 taken 33% (fallthrough)
	branch  1 taken 67%
			-:  410:    {
			1:  411:      return 1;
			-:  412:    }
			-:  413:
			2:  414:  return 0;
	-Coverage for the isGameOver() function is very good. All branches are taken at least once and all statements are executed at least once.

**********Unit test 4**********
Coverage of test:
	Lines executed:93.33% of 45
	Branches executed:100.00% of 10
	Taken at least once:70.00% of 10
	Calls executed:82.35% of 17
	-Again, the coverage is good and the only lines of code missed are print statements that did not execute because the test either alwasy passed or always failed.
	
Coverage of function:
	function fullDeckCount called 138 returned 100% blocks executed 100%
		  138:  324:int fullDeckCount(int player, int card, struct gameState *state) {
			-:  325:  int i;
		  138:  326:  int count = 0;
			-:  327:
		  230:  328:  for (i = 0; i < state->deckCount[player]; i++)
	branch  0 taken 40%
	branch  1 taken 60% (fallthrough)
			-:  329:    {
		   92:  330:      if (state->deck[player][i] == card) count++;
	branch  0 taken 100% (fallthrough)
	branch  1 taken 0%
			-:  331:    }
			-:  332:
		  230:  333:  for (i = 0; i < state->handCount[player]; i++)
	branch  0 taken 40%
	branch  1 taken 60% (fallthrough)
			-:  334:    {
		   92:  335:      if (state->hand[player][i] == card) count++;
	branch  0 taken 100% (fallthrough)
	branch  1 taken 0%
			-:  336:    }
			-:  337:
		  230:  338:  for (i = 0; i < state->discardCount[player]; i++)
	branch  0 taken 40%
	branch  1 taken 60% (fallthrough)
			-:  339:    {
		   92:  340:      if (state->discard[player][i] == card) count++;
	branch  0 taken 100% (fallthrough)
	branch  1 taken 0%
			-:  341:    }
			-:  342:
		  138:  343:  return count;
	-Coverage of the fullDeckCount() function is quite good, with all statements being covered.
	
**********Card test 1**********
Coverage of test:
	Lines executed:87.50% of 24
	Branches executed:50.00% of 16
	Taken at least once:31.25% of 16
	Calls executed:70.00% of 10
	-Again, the coverage is good and the only lines of code missed are print statements that did not execute because the test either alwasy passed or always failed.
	
Coverage of function:
	function adventurerCard called 2 returned 100% blocks executed 93%
			2: 1262:int adventurerCard(int currentPlayer, struct gameState *state)
			-: 1263:{
			-: 1264:	int temphand[MAX_HAND];// moved above the if statement
			2: 1265:	int drawntreasure=0;
			-: 1266:	int cardDrawn;
			2: 1267:	int z = 0;// this is the counter for the temp hand
			-: 1268:	
		   10: 1269:      while(drawntreasure<2){
	branch  0 taken 75%
	branch  1 taken 25% (fallthrough)
			6: 1270:	if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
	branch  0 taken 0% (fallthrough)
	branch  1 taken 100%
		#####: 1271:	  shuffle(currentPlayer, state);
	call    0 never executed
			-: 1272:	}
			6: 1273:	drawCard(currentPlayer, state);
	call    0 returned 100%
			6: 1274:	cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
			6: 1275:	if (cardDrawn == copper || cardDrawn == silver)
	branch  0 taken 33% (fallthrough)
	branch  1 taken 67%
	branch  2 taken 0% (fallthrough)
	branch  3 taken 100%
			4: 1276:	  drawntreasure++;
			-: 1277:	else{
			2: 1278:	  temphand[z]=cardDrawn;
			2: 1279:	  state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
			2: 1280:	  z++;
			-: 1281:	}
			-: 1282:      }
			6: 1283:      while(z-1>=0){
	branch  0 taken 50%
	branch  1 taken 50% (fallthrough)
			2: 1284:	state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
			2: 1285:	z=z-1;
			-: 1286:      }
			2: 1287:      return 0;
			
	-This unit test has good coverage of the adventurerCard() function. It shows that there were no situations where the deck needed to be shuffled, so this could
	 be included into future tests.
	 
**********Card test 2**********
Coverage of test:
	Lines executed:92.00% of 25
	Branches executed:100.00% of 12
	Taken at least once:83.33% of 12
	Calls executed:77.78% of 9
	-Again, the coverage is good and the only lines of code missed are print statements that did not execute because the test either alwasy passed or always failed.
	
Coverage of function:
	function smithyCard called 8 returned 100% blocks executed 71%
			8: 1290:int smithyCard(int currentPlayer, struct gameState *state, int handPos)
			-: 1291:{
			8: 1292:	int i = 0;
			-: 1293:      //+3 Cards
			8: 1294:      for (i = 0; i > 3; i++)
	branch  0 taken 0%
	branch  1 taken 100% (fallthrough)
			-: 1295:	{
		#####: 1296:	  drawCard(currentPlayer, state);
	call    0 never executed
			-: 1297:	}
			-: 1298:			
			-: 1299:      //discard card from hand
			8: 1300:      discardCard(handPos, currentPlayer, state, 0);
	call    0 returned 100%
			8: 1301:      return 0;
	-Coverage here is quite good. The drawCard part is never called, but this is due to the bug introduced in earlier weeks.
	
**********Card test 3**********
Coverage of test:
	Lines executed:89.29% of 28
	Branches executed:100.00% of 14
	Taken at least once:78.57% of 14
	Calls executed:72.73% of 11
	-Again, the coverage is good and the only lines of code missed are print statements that did not execute because the test either alwasy passed or always failed.
	
Coverage of function:
	function villageCard called 8 returned 100% blocks executed 100%
			8: 1304:int villageCard(int currentPlayer, struct gameState *state, int handPos) {
			-: 1305:	  //+1 Card
			8: 1306:      drawCard(currentPlayer, state);
	call    0 returned 100%
			-: 1307:			
			-: 1308:      //+2 Actions
			8: 1309:      state->numActions = state->numActions + 1;
			-: 1310:			
			-: 1311:      //discard played card from hand
			8: 1312:      discardCard(handPos, currentPlayer, state, 0);
	call    0 returned 100%
			8: 1313:      return 0;
	-This shows excellent coverage of the villageCard() function.
	
**********Card test 4**********
Coverage of test:
	Lines executed:93.55% of 31
	Branches executed:100.00% of 18
	Taken at least once:88.89% of 18
	Calls executed:81.82% of 11
	-Again, the coverage is good and the only lines of code missed are print statements that did not execute because the test either alwasy passed or always failed.

Coverage of function:
	function council_roomCard called 8 returned 100% blocks executed 100%
			8: 1316:int council_roomCard(int currentPlayer, struct gameState *state, int handPos) {
			-: 1317:  //+4 Cards
			-: 1318:  int i;
		   40: 1319:      for (i = 0; i < 4; i++)
	branch  0 taken 80%
	branch  1 taken 20% (fallthrough)
			-: 1320:	{
		   32: 1321:	  drawCard(currentPlayer, state);
	call    0 returned 100%
			-: 1322:	}
			-: 1323:			
			-: 1324:      //+1 Buy
			8: 1325:      state->numBuys++;
			-: 1326:			
			-: 1327:      //Each other player draws a card
		   16: 1328:      for (i = 1; i < state->numPlayers; i++)
	branch  0 taken 50%
	branch  1 taken 50% (fallthrough)
			-: 1329:	{
			8: 1330:	  if ( i != currentPlayer )
	branch  0 taken 50% (fallthrough)
	branch  1 taken 50%
			-: 1331:	    {
			4: 1332:	      drawCard(i, state);
	call    0 returned 100%
			-: 1333:	    }
			-: 1334:	}
			-: 1335:			
			-: 1336:      //put played card in played card pile
			8: 1337:      discardCard(handPos, currentPlayer, state, 0);
	call    0 returned 100%
			-: 1338:			
			8: 1339:      return 0;
	-This shows excellent coverage of the council_roomCard() function.

*/