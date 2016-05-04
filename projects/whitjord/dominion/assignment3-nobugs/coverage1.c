/* coverage for unittest1-4 and cardtest1-4
 * NOTE: the coverage talked about here is for the tests run on 
 * unmodified dominion files, coverage may differ when tests are
 * run under whitjord/dominion/ because bugs where introduced to
 * the functions that the tests are running 
 *
 * unittest1
 *
 * Function 'updateCoins'
 * Lines executed:100.00% of 11
 * Branches executed:100.00% of 8
 * Taken at least once:100.00% of 8
 * No calls
 *
 *
 * unittest2 
 *
 * Function 'isGameOver'
 * Lines executed:100.00% of 10
 * Branches executed:100.00% of 8
 * Taken at least once:100.00% of 8
 * No calls
 * 
 * 
 * unittest3
 *
 * Function 'whoseTurn'
 * Lines executed:100.00% of 2
 * No branches
 * No calls
 *
 *
 * unittest4
 *
 * Function 'discardCard'
 * Lines executed:92.31% of 13
 * Branches executed:100.00% of 6
 * Taken at least once:83.33% of 6
 * No calls
 * 
 * I didn't get 100% coverage on this. I couldn't think of a valid situation
 * where `state->handCount[currentPlayer] == 1` would be true and 
 * `handPos == (state->handCount[currentPlayer] - 1` wouldn't be
 *
 *
       13: 1241:  if ( handPos == (state->handCount[currentPlayer] - 1) )       //last card in hand array is played
branch  0 taken 31% (fallthrough)
branch  1 taken 69%
        -: 1242:    {
        -: 1243:      //reduce number of cards in hand
        4: 1244:      state->handCount[currentPlayer]--;
        -: 1245:    }
        9: 1246:  else if ( state->handCount[currentPlayer] == 1 ) //only one card in hand
branch  0 taken 0% (fallthrough)
branch  1 taken 100%

 *
 *
 *
 *
 *
