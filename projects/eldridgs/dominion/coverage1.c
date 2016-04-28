/*
Susan Eldridge
Spring 2016
CS361
This is a place to talk about code coverage in unittest[1-4] and cardtest[1-4].
*/

It should be noted, I was doing my testing on the dominion.c that I did NOT introduce bugs to.

Overall, I think my code coverage looks pretty good.  My testing can be improved by using many more
different combinations of cards.  I know that this is needed to catch my smithy bug.

unittest1:
Here I was trying to test update coins.  According to gcov -f, I got 100% coverage for the updateCoins()
method.  Only 28.1% for the entire dominion.c file.  This is good.  100% coverage for the method I was
actually trying to test.  With such a low percentage for the entire dominion.c file, but 100% for updateCoins()
I feel that this test does a good job of only testing what I was trying to test.

unittest2:
28.28% of the overall dominion code. I was testing discard card() for which I was able to get 92.31%.
I was able to execute 100% of branches, but only 83.33% were taken at least once.  It appears that I
did not make sure the hand count was decreased when the card was removed when it was the last card in
the hand and barely tested it when there was one other card in the hand. Other than that, all
statements were covered at least 51 times.

       53: 1226:int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)
        -: 1227:{
        -: 1228:
        -: 1229:  //if card is not trashed, added to Played pile
       53: 1230:  if (trashFlag < 1)
        -: 1231:    {
        -: 1232:      //add card to played pile
       51: 1233:      state->playedCards[state->playedCardCount] = state->hand[currentPlayer][handPos];
       51: 1234:      state->playedCardCount++;
        -: 1235:    }
        -: 1236:
        -: 1237:  //set played card to -1
       53: 1238:  state->hand[currentPlayer][handPos] = -1;
        -: 1239:
        -: 1240:  //remove card from player's hand
       53: 1241:  if ( handPos == (state->handCount[currentPlayer] - 1) ) 	//last card in hand array is played
        -: 1242:    {
        -: 1243:      //reduce number of cards in hand
    #####: 1244:      state->handCount[currentPlayer]--;
        -: 1245:    }
       53: 1246:  else if ( state->handCount[currentPlayer] == 1 ) //only one card in hand
        -: 1247:    {
        -: 1248:      //reduce number of cards in hand
        2: 1249:      state->handCount[currentPlayer]--;
        -: 1250:    }
        -: 1251:  else
        -: 1252:    {
        -: 1253:      //replace discarded card with last card in hand
       51: 1254:      state->hand[currentPlayer][handPos] = state->hand[currentPlayer][ (state->handCount[currentPlayer] - 1)];
        -: 1255:      //set last card to -1
       51: 1256:      state->hand[currentPlayer][state->handCount[currentPlayer] - 1] = -1;
        -: 1257:      //reduce number of cards in hand
       51: 1258:      state->handCount[currentPlayer]--;
        -: 1259:    }


unittest3:
In unittest3 I was testing gainCard().  Here I executed 31.02% of the total dominion.c, but got 100% line
coverage for gainCard().  All the branches were executed and taken at least once.

unittest4:
Here, I was trying to test isGameOver().  I had just 32.85% of the total lines executing, but 100% of the
isGameOver() lines executed.  All of the branches executed and were taken at least once.

cardtest1:
Each statement was covered at least 18 times.
        -:  831:    case smithy:
        -:  832:      //+3 Cards
       72:  833:      for (i = 0; i < 3; i++)
        -:  834:	{
       54:  835:	  drawCard(currentPlayer, state);
        -:  836:	}
        -:  837:
        -:  838:      //discard card from hand
       18:  839:      discardCard(handPos, currentPlayer, state, 0);
       18:  840:      return 0;

cardtest2:
Here, I was testing the adventurer card.  I never tested the state when the cards would need to be shuffled.
Other than that, all lines were covered at least 4 times.
        -:  669:    case adventurer:
       20:  670:      while(drawntreasure<2){
       12:  671:	if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
    #####:  672:	  shuffle(currentPlayer, state);
        -:  673:	}
       12:  674:	drawCard(currentPlayer, state);
       12:  675:	cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
       12:  676:	if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
        8:  677:	  drawntreasure++;
        -:  678:	else{
        4:  679:	  temphand[z]=cardDrawn;
        4:  680:	  state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
        4:  681:	  z++;
        -:  682:	}
        -:  683:      }
       12:  684:      while(z-1>=0){
        4:  685:	state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
        4:  686:	z=z-1;
        -:  687:      }
        4:  688:      return 0;

cardtest3:
I was testing council_room.  All lines were covered at least 3 times.
        -:  690:    case council_room:
        -:  691:      //+4 Cards
       15:  692:      for (i = 0; i < 4; i++)
        -:  693:	{
       12:  694:	  drawCard(currentPlayer, state);
        -:  695:	}
        -:  696:
        -:  697:      //+1 Buy
        3:  698:      state->numBuys++;
        -:  699:
        -:  700:      //Each other player draws a card
        9:  701:      for (i = 0; i < state->numPlayers; i++)
        -:  702:	{
        6:  703:	  if ( i != currentPlayer )
        -:  704:	    {
        3:  705:	      drawCard(i, state);
        -:  706:	    }
        -:  707:	}
        -:  708:
        -:  709:      //put played card in played card pile
        3:  710:      discardCard(handPos, currentPlayer, state, 0);
        -:  711:
        3:  712:      return 0;

cardtest4:
sea_hag was being tested.  All lines were covered at least 16 times.
        -: 1182:    case sea_hag:
       48: 1183:      for (i = 0; i < state->numPlayers; i++){
       32: 1184:	if (i != currentPlayer){
       16: 1185:	  state->discard[i][state->discardCount[i]] = state->deck[i][state->deckCount[i]--];			    state->deckCount[i]--;
       16: 1186:	  state->discardCount[i]++;
       16: 1187:	  state->deck[i][state->deckCount[i]--] = curse;//Top card now a curse
        -: 1188:	}
        -: 1189:      }
       16: 1190:      return 0;
