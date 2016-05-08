Alex Samuel
Assignment 4
randomhistory.c

	The first step I took in creating my randomtesters for adventurer and smithy cards was to review the coverage data 
I obtained in my previous adventurer card tests. I then attempted to identify gaps in code coverage and address those in my random tests.

-------------------------------------------------------------------------------
Original Card Unit Tests Data
Function 'adventurerCard'
Lines executed:93.33% of 15
Branches executed:100.00% of 12
Taken at least once:75.00% of 12
Calls executed:50.00% of 2

function adventurerCard called 1 returned 100% blocks executed 93%
        1: 1292:int adventurerCard(int drawntreasure, struct gameState *state, int z, int currentPlayer) {
        -: 1293:    int temphand[MAX_HAND];
        6: 1294:    while(drawntreasure<3){
branch  0 taken 80%
branch  1 taken 20% (fallthrough)
        4: 1295:        if (state->deckCount[currentPlayer] <1){
branch  0 taken 0% (fallthrough)
branch  1 taken 100%
    #####: 1296:          shuffle(currentPlayer, state);
call    0 never executed
        -: 1297:        }
        4: 1298:        drawCard(currentPlayer, state);
call    0 returned 100%
        4: 1299:        int cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];
        4: 1300:        if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
branch  0 taken 25% (fallthrough)
branch  1 taken 75%
branch  2 taken 100% (fallthrough)
branch  3 taken 0%
branch  4 taken 0% (fallthrough)
branch  5 taken 100%
        3: 1301:          drawntreasure++;
        -: 1302:        else{
        1: 1303:          temphand[z]=cardDrawn;
        1: 1304:          state->handCount[currentPlayer]--;
        1: 1305:          z++;
        -: 1306:        }
        -: 1307:      }
        3: 1308:    while(z-1>=0){
branch  0 taken 50%
branch  1 taken 50% (fallthrough)
        1: 1309:	state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1];
        1: 1310:	z=z-1;
        -: 1311:    }
        -: 1312:
        1: 1313:    return 0;
        -: 1314:}

Random Tests Data
Function 'adventurerCard'
Lines executed:100.00% of 15
Branches executed:100.00% of 12
Taken at least once:83.33% of 12
Calls executed:100.00% of 2

function adventurerCard called 1000000 returned 100% blocks executed 100%
  1000000: 1292:int adventurerCard(int drawntreasure, struct gameState *state, int z, int currentPlayer) {
        -: 1293:    int temphand[MAX_HAND];
  5576923: 1294:    while(drawntreasure<3){
branch  0 taken 78%
branch  1 taken 22% (fallthrough)
  3576923: 1295:        if (state->deckCount[currentPlayer] <1){
branch  0 taken 56% (fallthrough)
branch  1 taken 44%
  2000000: 1296:          shuffle(currentPlayer, state);
call    0 returned 100%
        -: 1297:        }
  3576923: 1298:        drawCard(currentPlayer, state);
call    0 returned 100%
  3576923: 1299:        int cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];
  3576923: 1300:        if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
branch  0 taken 16% (fallthrough)
branch  1 taken 84%
branch  2 taken 100% (fallthrough)
branch  3 taken 0%
branch  4 taken 0% (fallthrough)
branch  5 taken 100%
  3000000: 1301:          drawntreasure++;
        -: 1302:        else{
   576923: 1303:          temphand[z]=cardDrawn;
   576923: 1304:          state->handCount[currentPlayer]--;
   576923: 1305:          z++;
        -: 1306:        }
        -: 1307:      }
  2576923: 1308:    while(z-1>=0){
branch  0 taken 37%
branch  1 taken 63% (fallthrough)
   576923: 1309:	state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1];
   576923: 1310:	z=z-1;
        -: 1311:    }
        -: 1312:
  1000000: 1313:    return 0;
-------------------------------------------------------------------------------

	For my adventurerCard() function, my coverage increased slightly. I was able to obtain 100% coverage of lines and function calls
executed and I was able to increase my coverage of branches executed at least once. My random tests on this card uncovered the same 
bugs that my original tests. Specifically, one bug that is present in this card was introduced in assignment 2. The bug is that the 
player will keep drawing cards until 3 treasure cards are drawn rather than 2. Another bug that was indicated from my tests was that 
a non-treasure card can be drawn by the player and enter the player's hand rather than only treasure cards. Finally, my tests also 
indicate that playing the adventurer card can affect the deck of other players.

-------------------------------------------------------------------------------
Original Card Unit Tests Data
Function 'smithyCard'
Lines executed:100.00% of 5
Branches executed:100.00% of 2
Taken at least once:100.00% of 2
Calls executed:100.00% of 2


function smithyCard called 1 returned 100% blocks executed 100%
        1: 1282:int smithyCard(int handPos, int currentPlayer, struct gameState *state) {
        -: 1283:    int i;
        5: 1284:    for (i = 0; i < 4; i++) {
branch  0 taken 80%
branch  1 taken 20% (fallthrough)
        4: 1285:	  drawCard(currentPlayer, state);
call    0 returned 100%
        -: 1286:	}
        -: 1287:
        1: 1288:    discardCard(handPos, currentPlayer, state, 0);
call    0 returned 100%
        1: 1289:    return 0;
        -: 1290:}
        -: 1291:

Random Tests Data
Function 'smithyCard'
Lines executed:100.00% of 5
Branches executed:100.00% of 2
Taken at least once:100.00% of 2
Calls executed:100.00% of 2

function smithyCard called 1000000 returned 100% blocks executed 100%
  1000000: 1282:int smithyCard(int handPos, int currentPlayer, struct gameState *state) {
        -: 1283:    int i;
  5000000: 1284:    for (i = 0; i < 4; i++) {
branch  0 taken 80%
branch  1 taken 20% (fallthrough)
  4000000: 1285:	  drawCard(currentPlayer, state);
call    0 returned 100%
        -: 1286:	}
        -: 1287:
  1000000: 1288:    discardCard(handPos, currentPlayer, state, 0);
call    0 returned 100%
  1000000: 1289:    return 0;
        -: 1290:}
        -: 1291:
-------------------------------------------------------------------------------

	For my smithyCard() function, my coverage remained the same at 100% but I was able to dramatically 
increase the number of line counts for each line within the function. My random tests uncovered a bug where 
the player is able to draw 4 cards rather than 3 when this card is played.