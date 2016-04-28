/*
Aaron Sealy
Quiz 2
CS 362
Spring 2016

dominion.c coverage is Lines executed:29.08% of 564

The report is below and can also be seen in unittestresults.out.
The adventurer card kept crashing and disrupting my results and output when tested , so its tests do not seem to be included
in the report, since all my output reports are either before or after that card was tested and crashed.

Testing numHandCards() function:
TEST: hand count = 5. Expected result = 5.
Test passed!
unittest2.c:
Testing handCard() function:
TEST: actual hand card= 4. Expected result = 4.
Test passed!
unittest3.c:
Testing whoseTurn() function:
TEST: whose turn = 0. Expected result = 0.
Test passed!
unittest4.c:
Testing getCost() function:
Success: All valid inputs passed!
Success: All invalid inputs returned -1 as expected
cardtest1.c:
Testing Smithy card:
TEST 1: hand count = 6. Expected result = 8.
TEST 1 FAILED!
TEST 2: played count = 1. Expected result = 1.
TEST 3: deck = 3. Expected result = 2.
TEST 3 FAILED!
TEST 1: hand count = 6. Expected result = 8.
TEST 1 FAILED!
TEST 2: played count = 1. Expected result = 1.
TEST 3: deck = 3. Expected result = 2.
TEST 3 FAILED!
TEST 1: hand count = 6. Expected result = 8.
TEST 1 FAILED!
TEST 2: played count = 1. Expected result = 1.
TEST 3: deck = 3. Expected result = 2.
TEST 3 FAILED!
TEST 1: hand count = 6. Expected result = 8.
TEST 1 FAILED!
TEST 2: played count = 1. Expected result = 1.
TEST 3: deck = 3. Expected result = 2.
TEST 3 FAILED!
TEST 1: hand count = 6. Expected result = 8.
TEST 1 FAILED!
TEST 2: played count = 1. Expected result = 1.
TEST 3: deck = 3. Expected result = 2.
TEST 3 FAILED!
TEST 1: hand count = 6. Expected result = 8.
TEST 1 FAILED!
TEST 2: played count = 1. Expected result = 1.
TEST 3: deck = 3. Expected result = 2.
TEST 3 FAILED!
TEST 1: hand count = 6. Expected result = 8.
TEST 1 FAILED!
TEST 2: played count = 1. Expected result = 1.
TEST 3: deck = 3. Expected result = 2.
TEST 3 FAILED!
TEST 1: hand count = 6. Expected result = 8.
TEST 1 FAILED!
TEST 2: played count = 1. Expected result = 1.
TEST 3: deck = 3. Expected result = 2.
TEST 3 FAILED!
TEST 1: hand count = 6. Expected result = 8.
TEST 1 FAILED!
TEST 2: played count = 1. Expected result = 1.
TEST 3: deck = 3. Expected result = 2.
TEST 3 FAILED!
TEST 1: hand count = 6. Expected result = 8.
TEST 1 FAILED!
TEST 2: played count = 1. Expected result = 1.
TEST 3: deck = 3. Expected result = 2.
TEST 3 FAILED!
cardtest2.c:
Testing Great Hall card:
TEST 1: hand count = 5. Expected result = 6.
TEST 1 FAILED!
TEST 2: played count = 1. Expected result = 1.
TEST 3: deck count= 4. Expected result = 4.
TEST 4: number actions = 1. Expected result = 2.
TEST 4 FAILED!
TEST 1: hand count = 5. Expected result = 6.
TEST 1 FAILED!
TEST 2: played count = 1. Expected result = 1.
TEST 3: deck count= 4. Expected result = 4.
TEST 4: number actions = 1. Expected result = 2.
TEST 4 FAILED!
TEST 1: hand count = 5. Expected result = 6.
TEST 1 FAILED!
TEST 2: played count = 1. Expected result = 1.
TEST 3: deck count= 4. Expected result = 4.
TEST 4: number actions = 1. Expected result = 2.
TEST 4 FAILED!
TEST 1: hand count = 5. Expected result = 6.
TEST 1 FAILED!
TEST 2: played count = 1. Expected result = 1.
TEST 3: deck count= 4. Expected result = 4.
TEST 4: number actions = 1. Expected result = 2.
TEST 4 FAILED!
TEST 1: hand count = 5. Expected result = 6.
TEST 1 FAILED!
TEST 2: played count = 1. Expected result = 1.
TEST 3: deck count= 4. Expected result = 4.
TEST 4: number actions = 1. Expected result = 2.
TEST 4 FAILED!
TEST 1: hand count = 5. Expected result = 6.
TEST 1 FAILED!
TEST 2: played count = 1. Expected result = 1.
TEST 3: deck count= 4. Expected result = 4.
TEST 4: number actions = 1. Expected result = 2.
TEST 4 FAILED!
TEST 1: hand count = 5. Expected result = 6.
TEST 1 FAILED!
TEST 2: played count = 1. Expected result = 1.
TEST 3: deck count= 4. Expected result = 4.
TEST 4: number actions = 1. Expected result = 2.
TEST 4 FAILED!
TEST 1: hand count = 5. Expected result = 6.
TEST 1 FAILED!
TEST 2: played count = 1. Expected result = 1.
TEST 3: deck count= 4. Expected result = 4.
TEST 4: number actions = 1. Expected result = 2.
TEST 4 FAILED!
TEST 1: hand count = 5. Expected result = 6.
TEST 1 FAILED!
TEST 2: played count = 1. Expected result = 1.
TEST 3: deck count= 4. Expected result = 4.
TEST 4: number actions = 1. Expected result = 2.
TEST 4 FAILED!
TEST 1: hand count = 5. Expected result = 6.
TEST 1 FAILED!
TEST 2: played count = 1. Expected result = 1.
TEST 3: deck count= 4. Expected result = 4.
TEST 4: number actions = 1. Expected result = 2.
TEST 4 FAILED!
cardtest4.c:
Testing Village card:
TEST 1: hand count = 5. Expected result = 6.
TEST 1 FAILED!
TEST 2: played count = 1. Expected result = 1.
TEST 3: deck count= 4. Expected result = 4.
TEST 4: number actions = 3. Expected result = 3.
TEST 1: hand count = 5. Expected result = 6.
TEST 1 FAILED!
TEST 2: played count = 1. Expected result = 1.
TEST 3: deck count= 4. Expected result = 4.
TEST 4: number actions = 3. Expected result = 3.
TEST 1: hand count = 5. Expected result = 6.
TEST 1 FAILED!
TEST 2: played count = 1. Expected result = 1.
TEST 3: deck count= 4. Expected result = 4.
TEST 4: number actions = 3. Expected result = 3.
TEST 1: hand count = 5. Expected result = 6.
TEST 1 FAILED!
TEST 2: played count = 1. Expected result = 1.
TEST 3: deck count= 4. Expected result = 4.
TEST 4: number actions = 3. Expected result = 3.
TEST 1: hand count = 5. Expected result = 6.
TEST 1 FAILED!
TEST 2: played count = 1. Expected result = 1.
TEST 3: deck count= 4. Expected result = 4.
TEST 4: number actions = 3. Expected result = 3.
TEST 1: hand count = 5. Expected result = 6.
TEST 1 FAILED!
TEST 2: played count = 1. Expected result = 1.
TEST 3: deck count= 4. Expected result = 4.
TEST 4: number actions = 3. Expected result = 3.
TEST 1: hand count = 5. Expected result = 6.
TEST 1 FAILED!
TEST 2: played count = 1. Expected result = 1.
TEST 3: deck count= 4. Expected result = 4.
TEST 4: number actions = 3. Expected result = 3.
TEST 1: hand count = 5. Expected result = 6.
TEST 1 FAILED!
TEST 2: played count = 1. Expected result = 1.
TEST 3: deck count= 4. Expected result = 4.
TEST 4: number actions = 3. Expected result = 3.
TEST 1: hand count = 5. Expected result = 6.
TEST 1 FAILED!
TEST 2: played count = 1. Expected result = 1.
TEST 3: deck count= 4. Expected result = 4.
TEST 4: number actions = 3. Expected result = 3.
TEST 1: hand count = 5. Expected result = 6.
TEST 1 FAILED!
TEST 2: played count = 1. Expected result = 1.
TEST 3: deck count= 4. Expected result = 4.
TEST 4: number actions = 3. Expected result = 3.
File 'dominion.c'
Lines executed:29.08% of 564
Creating 'dominion.c.gcov'

        -:    0:Source:dominion.c
        -:    0:Graph:dominion.gcno
        -:    0:Data:dominion.gcda
        -:    0:Runs:7
        -:    0:Programs:7
        -:    1:#include "dominion.h"
        -:    2:#include "dominion_helpers.h"
        -:    3:#include "rngs.h"
        -:    4:#include <stdio.h>
        -:    5:#include <math.h>
        -:    6:#include <stdlib.h>
        -:    7:
      990:    8:int compare(const void* a, const void* b) {
      990:    9:  if (*(int*)a > *(int*)b)
    #####:   10:    return 1;
      990:   11:  if (*(int*)a < *(int*)b)
      264:   12:    return -1;
      726:   13:  return 0;
        -:   14:}
        -:   15:
    #####:   16:struct gameState* newGame() {
    #####:   17:  struct gameState* g = malloc(sizeof(struct gameState));
    #####:   18:  return g;
        -:   19:}
        -:   20:
    #####:   21:int* kingdomCards(int k1, int k2, int k3, int k4, int k5, int k6, int k7,
        -:   22:		  int k8, int k9, int k10) {
    #####:   23:  int* k = malloc(10 * sizeof(int));
    #####:   24:  k[0] = k1;
    #####:   25:  k[1] = k2;
    #####:   26:  k[2] = k3;
    #####:   27:  k[3] = k4;
    #####:   28:  k[4] = k5;
    #####:   29:  k[5] = k6;
    #####:   30:  k[6] = k7;
    #####:   31:  k[7] = k8;
    #####:   32:  k[8] = k9;
    #####:   33:  k[9] = k10;
    #####:   34:  return k;
        -:   35:}
        -:   36:
       33:   37:int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed,
        -:   38:		   struct gameState *state) {
        -:   39:
        -:   40:  int i;
        -:   41:  int j;
        -:   42:  int it;
        -:   43:  //set up random number generator
       33:   44:  SelectStream(1);
       33:   45:  PutSeed((long)randomSeed);
        -:   46:
        -:   47:  //check number of players
       33:   48:  if (numPlayers > MAX_PLAYERS || numPlayers < 2)
        -:   49:    {
    #####:   50:      return -1;
        -:   51:    }
        -:   52:
        -:   53:  //set number of players
       33:   54:  state->numPlayers = numPlayers;
        -:   55:
        -:   56:  //check selected kingdom cards are different
      363:   57:  for (i = 0; i < 10; i++)
        -:   58:    {
     3630:   59:      for (j = 0; j < 10; j++)
        -:   60:        {
     3300:   61:	  if (j != i && kingdomCards[j] == kingdomCards[i])
        -:   62:	    {
    #####:   63:	      return -1;
        -:   64:	    }
        -:   65:        }
        -:   66:    }
        -:   67:
        -:   68:
        -:   69:  //initialize supply
        -:   70:  ///////////////////////////////
        -:   71:
        -:   72:  //set number of Curse cards
       33:   73:  if (numPlayers == 2)
        -:   74:    {
       33:   75:      state->supplyCount[curse] = 10;
        -:   76:    }
    #####:   77:  else if (numPlayers == 3)
        -:   78:    {
    #####:   79:      state->supplyCount[curse] = 20;
        -:   80:    }
        -:   81:  else
        -:   82:    {
    #####:   83:      state->supplyCount[curse] = 30;
        -:   84:    }
        -:   85:
        -:   86:  //set number of Victory cards
       33:   87:  if (numPlayers == 2)
        -:   88:    {
       33:   89:      state->supplyCount[estate] = 8;
       33:   90:      state->supplyCount[duchy] = 8;
       33:   91:      state->supplyCount[province] = 8;
        -:   92:    }
        -:   93:  else
        -:   94:    {
    #####:   95:      state->supplyCount[estate] = 12;
    #####:   96:      state->supplyCount[duchy] = 12;
    #####:   97:      state->supplyCount[province] = 12;
        -:   98:    }
        -:   99:
        -:  100:  //set number of Treasure cards
       33:  101:  state->supplyCount[copper] = 60 - (7 * numPlayers);
       33:  102:  state->supplyCount[silver] = 40;
       33:  103:  state->supplyCount[gold] = 30;
        -:  104:
        -:  105:  //set number of Kingdom cards
      693:  106:  for (i = adventurer; i <= treasure_map; i++)       	//loop all cards
        -:  107:    {
     5445:  108:      for (j = 0; j < 10; j++)           		//loop chosen cards
        -:  109:	{
     5115:  110:	  if (kingdomCards[j] == i)
        -:  111:	    {
        -:  112:	      //check if card is a 'Victory' Kingdom card
      330:  113:	      if (kingdomCards[j] == great_hall || kingdomCards[j] == gardens)
        -:  114:		{
      132:  115:		  if (numPlayers == 2){
       66:  116:		    state->supplyCount[i] = 8;
        -:  117:		  }
    #####:  118:		  else{ state->supplyCount[i] = 12; }
        -:  119:		}
        -:  120:	      else
        -:  121:		{
      264:  122:		  state->supplyCount[i] = 10;
        -:  123:		}
      330:  124:	      break;
        -:  125:	    }
        -:  126:	  else    //card is not in the set choosen for the game
        -:  127:	    {
     4785:  128:	      state->supplyCount[i] = -1;
        -:  129:	    }
        -:  130:	}
        -:  131:
        -:  132:    }
        -:  133:
        -:  134:  ////////////////////////
        -:  135:  //supply intilization complete
        -:  136:
        -:  137:  //set player decks
       99:  138:  for (i = 0; i < numPlayers; i++)
        -:  139:    {
       66:  140:      state->deckCount[i] = 0;
      264:  141:      for (j = 0; j < 3; j++)
        -:  142:	{
      198:  143:	  state->deck[i][j] = estate;
      198:  144:	  state->deckCount[i]++;
        -:  145:	}
      528:  146:      for (j = 3; j < 10; j++)
        -:  147:	{
      462:  148:	  state->deck[i][j] = copper;
      462:  149:	  state->deckCount[i]++;
        -:  150:	}
        -:  151:    }
        -:  152:
        -:  153:  //shuffle player decks
       99:  154:  for (i = 0; i < numPlayers; i++)
        -:  155:    {
       66:  156:      if ( shuffle(i, state) < 0 )
        -:  157:	{
    #####:  158:	  return -1;
        -:  159:	}
        -:  160:    }
        -:  161:
        -:  162:  //draw player hands
       99:  163:  for (i = 0; i < numPlayers; i++)
        -:  164:    {
        -:  165:      //initialize hand size to zero
       66:  166:      state->handCount[i] = 0;
       66:  167:      state->discardCount[i] = 0;
        -:  168:      //draw 5 cards
        -:  169:      // for (j = 0; j < 5; j++)
        -:  170:      //	{
        -:  171:      //	  drawCard(i, state);
        -:  172:      //	}
        -:  173:    }
        -:  174:
        -:  175:  //set embargo tokens to 0 for all supply piles
      924:  176:  for (i = 0; i <= treasure_map; i++)
        -:  177:    {
      891:  178:      state->embargoTokens[i] = 0;
        -:  179:    }
        -:  180:
        -:  181:  //initialize first player's turn
       33:  182:  state->outpostPlayed = 0;
       33:  183:  state->phase = 0;
       33:  184:  state->numActions = 1;
       33:  185:  state->numBuys = 1;
       33:  186:  state->playedCardCount = 0;
       33:  187:  state->whoseTurn = 0;
       33:  188:  state->handCount[state->whoseTurn] = 0;
        -:  189:  //int it; move to top
        -:  190:
        -:  191:  //Moved draw cards to here, only drawing at the start of a turn
      198:  192:  for (it = 0; it < 5; it++){
      165:  193:    drawCard(state->whoseTurn, state);
        -:  194:  }
        -:  195:
       33:  196:  updateCoins(state->whoseTurn, state, 0);
        -:  197:
       33:  198:  return 0;
        -:  199:}
        -:  200:
       66:  201:int shuffle(int player, struct gameState *state) {
        -:  202:
        -:  203:
        -:  204:  int newDeck[MAX_DECK];
       66:  205:  int newDeckPos = 0;
        -:  206:  int card;
        -:  207:  int i;
        -:  208:
       66:  209:  if (state->deckCount[player] < 1)
    #####:  210:    return -1;
       66:  211:  qsort ((void*)(state->deck[player]), state->deckCount[player], sizeof(int), compare);
        -:  212:  /* SORT CARDS IN DECK TO ENSURE DETERMINISM! */
        -:  213:
      792:  214:  while (state->deckCount[player] > 0) {
      660:  215:    card = floor(Random() * state->deckCount[player]);
      660:  216:    newDeck[newDeckPos] = state->deck[player][card];
      660:  217:    newDeckPos++;
     2310:  218:    for (i = card; i < state->deckCount[player]-1; i++) {
     1650:  219:      state->deck[player][i] = state->deck[player][i+1];
        -:  220:    }
      660:  221:    state->deckCount[player]--;
        -:  222:  }
      726:  223:  for (i = 0; i < newDeckPos; i++) {
      660:  224:    state->deck[player][i] = newDeck[i];
      660:  225:    state->deckCount[player]++;
        -:  226:  }
        -:  227:
       66:  228:  return 0;
        -:  229:}
        -:  230:
    #####:  231:int playCard(int handPos, int choice1, int choice2, int choice3, struct gameState *state)
        -:  232:{
        -:  233:  int card;
    #####:  234:  int coin_bonus = 0; 		//tracks coins gain from actions
        -:  235:
        -:  236:  //check if it is the right phase
    #####:  237:  if (state->phase != 0)
        -:  238:    {
    #####:  239:      return -1;
        -:  240:    }
        -:  241:
        -:  242:  //check if player has enough actions
    #####:  243:  if ( state->numActions < 1 )
        -:  244:    {
    #####:  245:      return -1;
        -:  246:    }
        -:  247:
        -:  248:  //get card played
    #####:  249:  card = handCard(handPos, state);
        -:  250:
        -:  251:  //check if selected card is an action
    #####:  252:  if ( card < adventurer || card > treasure_map )
        -:  253:    {
    #####:  254:      return -1;
        -:  255:    }
        -:  256:
        -:  257:  //play card
    #####:  258:  if ( cardEffect(card, choice1, choice2, choice3, state, handPos, &coin_bonus) < 0 )
        -:  259:    {
    #####:  260:      return -1;
        -:  261:    }
        -:  262:
        -:  263:  //reduce number of actions
    #####:  264:  state->numActions--;
        -:  265:
        -:  266:  //update coins (Treasure cards may be added with card draws)
    #####:  267:  updateCoins(state->whoseTurn, state, coin_bonus);
        -:  268:
    #####:  269:  return 0;
        -:  270:}
        -:  271:
    #####:  272:int buyCard(int supplyPos, struct gameState *state) {
        -:  273:  int who;
        -:  274:  if (DEBUG){
        -:  275:    printf("Entering buyCard...\n");
        -:  276:  }
        -:  277:
        -:  278:  // I don't know what to do about the phase thing.
        -:  279:
    #####:  280:  who = state->whoseTurn;
        -:  281:
    #####:  282:  if (state->numBuys < 1){
        -:  283:    if (DEBUG)
        -:  284:      printf("You do not have any buys left\n");
    #####:  285:    return -1;
    #####:  286:  } else if (supplyCount(supplyPos, state) <1){
        -:  287:    if (DEBUG)
        -:  288:      printf("There are not any of that type of card left\n");
    #####:  289:    return -1;
    #####:  290:  } else if (state->coins < getCost(supplyPos)){
        -:  291:    if (DEBUG)
        -:  292:      printf("You do not have enough money to buy that. You have %d coins.\n", state->coins);
    #####:  293:    return -1;
        -:  294:  } else {
    #####:  295:    state->phase=1;
        -:  296:    //state->supplyCount[supplyPos]--;
    #####:  297:    gainCard(supplyPos, state, 0, who); //card goes in discard, this might be wrong.. (2 means goes into hand, 0 goes into discard)
        -:  298:
    #####:  299:    state->coins = (state->coins) - (getCost(supplyPos));
    #####:  300:    state->numBuys--;
        -:  301:    if (DEBUG)
        -:  302:      printf("You bought card number %d for %d coins. You now have %d buys and %d coins.\n", supplyPos, getCost(supplyPos), state->numBuys, state->coins);
        -:  303:  }
        -:  304:
        -:  305:  //state->discard[who][state->discardCount[who]] = supplyPos;
        -:  306:  //state->discardCount[who]++;
        -:  307:
    #####:  308:  return 0;
        -:  309:}
        -:  310:
        1:  311:int numHandCards(struct gameState *state) {
        1:  312:  return state->handCount[ whoseTurn(state) ];
        -:  313:}
        -:  314:
        1:  315:int handCard(int handPos, struct gameState *state) {
        1:  316:  int currentPlayer = whoseTurn(state);
        1:  317:  return state->hand[currentPlayer][handPos];
        -:  318:}
        -:  319:
    #####:  320:int supplyCount(int card, struct gameState *state) {
    #####:  321:  return state->supplyCount[card];
        -:  322:}
        -:  323:
    #####:  324:int fullDeckCount(int player, int card, struct gameState *state) {
        -:  325:  int i;
    #####:  326:  int count = 0;
        -:  327:
    #####:  328:  for (i = 0; i < state->deckCount[player]; i++)
        -:  329:    {
    #####:  330:      if (state->deck[player][i] == card) count++;
        -:  331:    }
        -:  332:
    #####:  333:  for (i = 0; i < state->handCount[player]; i++)
        -:  334:    {
    #####:  335:      if (state->hand[player][i] == card) count++;
        -:  336:    }
        -:  337:
    #####:  338:  for (i = 0; i < state->discardCount[player]; i++)
        -:  339:    {
    #####:  340:      if (state->discard[player][i] == card) count++;
        -:  341:    }
        -:  342:
    #####:  343:  return count;
        -:  344:}
        -:  345:
       33:  346:int whoseTurn(struct gameState *state) {
       33:  347:  return state->whoseTurn;
        -:  348:}
        -:  349:
    #####:  350:int endTurn(struct gameState *state) {
        -:  351:  int k;
        -:  352:  int i;
    #####:  353:  int currentPlayer = whoseTurn(state);
        -:  354:
        -:  355:  //Discard hand
    #####:  356:  for (i = 0; i < state->handCount[currentPlayer]; i++){
    #####:  357:    state->discard[currentPlayer][state->discardCount[currentPlayer]++] = state->hand[currentPlayer][i];//Discard
    #####:  358:    state->hand[currentPlayer][i] = -1;//Set card to -1
        -:  359:  }
    #####:  360:  state->handCount[currentPlayer] = 0;//Reset hand count
        -:  361:
        -:  362:  //Code for determining the player
    #####:  363:  if (currentPlayer < (state->numPlayers - 1)){
    #####:  364:    state->whoseTurn = currentPlayer + 1;//Still safe to increment
        -:  365:  }
        -:  366:  else{
    #####:  367:    state->whoseTurn = 0;//Max player has been reached, loop back around to player 1
        -:  368:  }
        -:  369:
    #####:  370:  state->outpostPlayed = 0;
    #####:  371:  state->phase = 0;
    #####:  372:  state->numActions = 1;
    #####:  373:  state->coins = 0;
    #####:  374:  state->numBuys = 1;
    #####:  375:  state->playedCardCount = 0;
    #####:  376:  state->handCount[state->whoseTurn] = 0;
        -:  377:
        -:  378:  //int k; move to top
        -:  379:  //Next player draws hand
    #####:  380:  for (k = 0; k < 5; k++){
    #####:  381:    drawCard(state->whoseTurn, state);//Draw a card
        -:  382:  }
        -:  383:
        -:  384:  //Update money
    #####:  385:  updateCoins(state->whoseTurn, state , 0);
        -:  386:
    #####:  387:  return 0;
        -:  388:}
        -:  389:
    #####:  390:int isGameOver(struct gameState *state) {
        -:  391:  int i;
        -:  392:  int j;
        -:  393:
        -:  394:  //if stack of Province cards is empty, the game ends
    #####:  395:  if (state->supplyCount[province] == 0)
        -:  396:    {
    #####:  397:      return 1;
        -:  398:    }
        -:  399:
        -:  400:  //if three supply pile are at 0, the game ends
    #####:  401:  j = 0;
    #####:  402:  for (i = 0; i < 25; i++)
        -:  403:    {
    #####:  404:      if (state->supplyCount[i] == 0)
        -:  405:	{
    #####:  406:	  j++;
        -:  407:	}
        -:  408:    }
    #####:  409:  if ( j >= 3)
        -:  410:    {
    #####:  411:      return 1;
        -:  412:    }
        -:  413:
    #####:  414:  return 0;
        -:  415:}
        -:  416:
    #####:  417:int scoreFor (int player, struct gameState *state) {
        -:  418:
        -:  419:  int i;
    #####:  420:  int score = 0;
        -:  421:  //score from hand
    #####:  422:  for (i = 0; i < state->handCount[player]; i++)
        -:  423:    {
    #####:  424:      if (state->hand[player][i] == curse) { score = score - 1; };
    #####:  425:      if (state->hand[player][i] == estate) { score = score + 1; };
    #####:  426:      if (state->hand[player][i] == duchy) { score = score + 3; };
    #####:  427:      if (state->hand[player][i] == province) { score = score + 6; };
    #####:  428:      if (state->hand[player][i] == great_hall) { score = score + 1; };
    #####:  429:      if (state->hand[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
        -:  430:    }
        -:  431:
        -:  432:  //score from discard
    #####:  433:  for (i = 0; i < state->discardCount[player]; i++)
        -:  434:    {
    #####:  435:      if (state->discard[player][i] == curse) { score = score - 1; };
    #####:  436:      if (state->discard[player][i] == estate) { score = score + 1; };
    #####:  437:      if (state->discard[player][i] == duchy) { score = score + 3; };
    #####:  438:      if (state->discard[player][i] == province) { score = score + 6; };
    #####:  439:      if (state->discard[player][i] == great_hall) { score = score + 1; };
    #####:  440:      if (state->discard[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
        -:  441:    }
        -:  442:
        -:  443:  //score from deck
    #####:  444:  for (i = 0; i < state->discardCount[player]; i++)
        -:  445:    {
    #####:  446:      if (state->deck[player][i] == curse) { score = score - 1; };
    #####:  447:      if (state->deck[player][i] == estate) { score = score + 1; };
    #####:  448:      if (state->deck[player][i] == duchy) { score = score + 3; };
    #####:  449:      if (state->deck[player][i] == province) { score = score + 6; };
    #####:  450:      if (state->deck[player][i] == great_hall) { score = score + 1; };
    #####:  451:      if (state->deck[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
        -:  452:    }
        -:  453:
    #####:  454:  return score;
        -:  455:}
        -:  456:
    #####:  457:int getWinners(int players[MAX_PLAYERS], struct gameState *state) {
        -:  458:  int i;
        -:  459:  int j;
        -:  460:  int highScore;
        -:  461:  int currentPlayer;
        -:  462:
        -:  463:  //get score for each player
    #####:  464:  for (i = 0; i < MAX_PLAYERS; i++)
        -:  465:    {
        -:  466:      //set unused player scores to -9999
    #####:  467:      if (i >= state->numPlayers)
        -:  468:	{
    #####:  469:	  players[i] = -9999;
        -:  470:	}
        -:  471:      else
        -:  472:	{
    #####:  473:	  players[i] = scoreFor (i, state);
        -:  474:	}
        -:  475:    }
        -:  476:
        -:  477:  //find highest score
    #####:  478:  j = 0;
    #####:  479:  for (i = 0; i < MAX_PLAYERS; i++)
        -:  480:    {
    #####:  481:      if (players[i] > players[j])
        -:  482:	{
    #####:  483:	  j = i;
        -:  484:	}
        -:  485:    }
    #####:  486:  highScore = players[j];
        -:  487:
        -:  488:  //add 1 to players who had less turns
    #####:  489:  currentPlayer = whoseTurn(state);
    #####:  490:  for (i = 0; i < MAX_PLAYERS; i++)
        -:  491:    {
    #####:  492:      if ( players[i] == highScore && i > currentPlayer )
        -:  493:	{
    #####:  494:	  players[i]++;
        -:  495:	}
        -:  496:    }
        -:  497:
        -:  498:  //find new highest score
    #####:  499:  j = 0;
    #####:  500:  for (i = 0; i < MAX_PLAYERS; i++)
        -:  501:    {
    #####:  502:      if ( players[i] > players[j] )
        -:  503:	{
    #####:  504:	  j = i;
        -:  505:	}
        -:  506:    }
    #####:  507:  highScore = players[j];
        -:  508:
        -:  509:  //set winners in array to 1 and rest to 0
    #####:  510:  for (i = 0; i < MAX_PLAYERS; i++)
        -:  511:    {
    #####:  512:      if ( players[i] == highScore )
        -:  513:	{
    #####:  514:	  players[i] = 1;
        -:  515:	}
        -:  516:      else
        -:  517:	{
    #####:  518:	  players[i] = 0;
        -:  519:	}
        -:  520:    }
        -:  521:
    #####:  522:  return 0;
        -:  523:}
        -:  524:
      280:  525:int drawCard(int player, struct gameState *state)
        -:  526:{	int count;
        -:  527:  int deckCounter;
      280:  528:  if (state->deckCount[player] <= 0){//Deck is empty
        -:  529:
        -:  530:    //Step 1 Shuffle the discard pile back into a deck
        -:  531:    int i;
        -:  532:    //Move discard to deck
    #####:  533:    for (i = 0; i < state->discardCount[player];i++){
    #####:  534:      state->deck[player][i] = state->discard[player][i];
    #####:  535:      state->discard[player][i] = -1;
        -:  536:    }
        -:  537:
    #####:  538:    state->deckCount[player] = state->discardCount[player];
    #####:  539:    state->discardCount[player] = 0;//Reset discard
        -:  540:
        -:  541:    //Shufffle the deck
    #####:  542:    shuffle(player, state);//Shuffle the deck up and make it so that we can draw
        -:  543:
        -:  544:    if (DEBUG){//Debug statements
        -:  545:      printf("Deck count now: %d\n", state->deckCount[player]);
        -:  546:    }
        -:  547:
    #####:  548:    state->discardCount[player] = 0;
        -:  549:
        -:  550:    //Step 2 Draw Card
    #####:  551:    count = state->handCount[player];//Get current player's hand count
        -:  552:
        -:  553:    if (DEBUG){//Debug statements
        -:  554:      printf("Current hand count: %d\n", count);
        -:  555:    }
        -:  556:
    #####:  557:    deckCounter = state->deckCount[player];//Create a holder for the deck count
        -:  558:
    #####:  559:    if (deckCounter == 0)
    #####:  560:      return -1;
        -:  561:
    #####:  562:    state->hand[player][count] = state->deck[player][deckCounter - 1];//Add card to hand
    #####:  563:    state->deckCount[player]--;
    #####:  564:    state->handCount[player]++;//Increment hand count
        -:  565:  }
        -:  566:
        -:  567:  else{
      280:  568:    int count = state->handCount[player];//Get current hand count for player
        -:  569:    int deckCounter;
        -:  570:    if (DEBUG){//Debug statements
        -:  571:      printf("Current hand count: %d\n", count);
        -:  572:    }
        -:  573:
      280:  574:    deckCounter = state->deckCount[player];//Create holder for the deck count
      280:  575:    state->hand[player][count] = state->deck[player][deckCounter - 1];//Add card to the hand
      280:  576:    state->deckCount[player]--;
      280:  577:    state->handCount[player]++;//Increment hand count
        -:  578:  }
        -:  579:
      280:  580:  return 0;
        -:  581:}
        -:  582:
       29:  583:int getCost(int cardNumber)
        -:  584:{
       29:  585:  switch( cardNumber )
        -:  586:    {
        -:  587:    case curse:
        1:  588:      return 0;
        -:  589:    case estate:
        1:  590:      return 2;
        -:  591:    case duchy:
        1:  592:      return 5;
        -:  593:    case province:
        1:  594:      return 8;
        -:  595:    case copper:
        1:  596:      return 0;
        -:  597:
        -:  598:    case silver:
        1:  599:      return 3;
        -:  600:    case gold:
        1:  601:      return 6;
        -:  602:    case adventurer:
        1:  603:      return 6;
        -:  604:    case council_room:
        1:  605:      return 5;
        -:  606:    case feast:
        1:  607:      return 4;
        -:  608:    case gardens:
        1:  609:      return 4;
        -:  610:
        -:  611:    case mine:
        1:  612:      return 5;
        -:  613:    case remodel:
        1:  614:      return 4;
        -:  615:    case smithy:
        1:  616:      return 4;
        -:  617:    case village:
        1:  618:      return 3;
        -:  619:    case baron:
        1:  620:      return 4;
        -:  621:    case great_hall:
        1:  622:      return 3;
        -:  623:
        -:  624:    case minion:
        1:  625:      return 5;
        -:  626:    case steward:
        1:  627:      return 3;
        -:  628:    case tribute:
        1:  629:      return 5;
        -:  630:    case ambassador:
        1:  631:      return 3;
        -:  632:    case cutpurse:
        1:  633:      return 4;
        -:  634:    case embargo:
        1:  635:      return 2;
        -:  636:
        -:  637:    case outpost:
        1:  638:      return 5;
        -:  639:    case salvager:
        1:  640:      return 4;
        -:  641:    case sea_hag:
        1:  642:      return 4;
        -:  643:    case treasure_map:
        1:  644:      return 4;
        -:  645:    }
        -:  646:
        2:  647:  return -1;
        -:  648:}
        -:  649:
       10:  650:int smithyCard(int currentPlayer, struct gameState *state, int handPos){
        -:  651:    int i;
        -:  652:
        -:  653:    //+3 Cards
       30:  654:    for (i = 1; i < 3; i++)
        -:  655:	{
       20:  656:        drawCard(currentPlayer, state);
        -:  657:	}
        -:  658:
        -:  659:    //discard card from hand
       10:  660:    discardCard(handPos, currentPlayer, state, 0);
       10:  661:    return 0;
        -:  662:}
        -:  663:
    #####:  664:int adventurerCard(int currentPlayer, struct gameState *state){
    #####:  665:    int drawntreasure = 0;
        -:  666:    int temphand[MAX_HAND];
        -:  667:    int cardDrawn;
    #####:  668:    int z = 0;
        -:  669:
    #####:  670:    while(drawntreasure<2){
    #####:  671:        if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
    #####:  672:            shuffle(currentPlayer, state);
        -:  673:        }
    #####:  674:        drawCard(currentPlayer, state);
    #####:  675:        cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
    #####:  676:        if (cardDrawn == copper || cardDrawn == silver)
    #####:  677:            drawntreasure++;
        -:  678:        else{
    #####:  679:            temphand[z]=cardDrawn;
    #####:  680:            state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
    #####:  681:            z++;
        -:  682:        }
        -:  683:    }
        -:  684:
    #####:  685:    while(z-1>=0){
    #####:  686:        state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
    #####:  687:        z=z-1;
        -:  688:    }
        -:  689:
    #####:  690:    return 0;
        -:  691:}
        -:  692:
       10:  693:int greatHallCard(int currentPlayer, struct gameState *state, int handPos){
        -:  694:    //+1 Card
       10:  695:    drawCard(currentPlayer, state);
        -:  696:
        -:  697:    //Update Actions
       10:  698:    state->numActions++;
       10:  699:    state->numActions--;
        -:  700:
        -:  701:    //discard card from hand
       10:  702:    discardCard(handPos, currentPlayer, state, 0);
       10:  703:    return 0;
        -:  704:}
        -:  705:
    #####:  706:int remodelCard(int currentPlayer, struct gameState *state, int handPos, int choice1, int choice2){
        -:  707:      int i;
    #####:  708:      int j = state->hand[currentPlayer][choice1];  //store card we will trash
        -:  709:
    #####:  710:      if ( (getCost(state->hand[currentPlayer][choice1]) + 4) > getCost(choice2) ){
    #####:  711:        return -1;
        -:  712:	  }
        -:  713:
    #####:  714:      gainCard(choice2, state, 0, currentPlayer);
        -:  715:
        -:  716:      //discard card from hand
    #####:  717:      discardCard(handPos, currentPlayer, state, 0);
        -:  718:
        -:  719:      //discard trashed card
    #####:  720:      for (i = 0; i < state->handCount[currentPlayer]; i++){
    #####:  721:          if (state->hand[currentPlayer][i] == j){
    #####:  722:            discardCard(i, currentPlayer, state, 0);
    #####:  723:            break;
        -:  724:          }
        -:  725:	  }
    #####:  726:      return 0;
        -:  727:}
        -:  728:
    #####:  729:int SeaHagCard(int currentPlayer, struct gameState *state){
        -:  730:      int i;
    #####:  731:      for (i = 0; i < state->numPlayers; i++){
    #####:  732:        if (i = currentPlayer){
    #####:  733:            state->discard[i][state->discardCount[i]] = state->deck[i][state->deckCount[i]--];			    state->deckCount[i]--;
    #####:  734:            state->discardCount[i]++;
    #####:  735:            state->deck[i][state->deckCount[i]--] = curse;//Top card now a curse
        -:  736:        }
        -:  737:      }
    #####:  738:      return 0;
        -:  739:}
        -:  740:
       30:  741:int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
        -:  742:{
        -:  743:  int i;
        -:  744:  int j;
        -:  745:  int k;
        -:  746:  int x;
        -:  747:  int index;
        -:  748:  int temphand[MAX_HAND];
       30:  749:  int currentPlayer = whoseTurn(state);
       30:  750:  int nextPlayer = currentPlayer + 1;
       30:  751:  int tributeRevealedCards[2] = {-1, -1};
       30:  752:  if (nextPlayer > (state->numPlayers - 1)){
       15:  753:    nextPlayer = 0;
        -:  754:  }
        -:  755:
        -:  756:  //uses switch to select card and perform actions
       30:  757:  switch( card )
        -:  758:    {
        -:  759:    case adventurer:
    #####:  760:    adventurerCard(currentPlayer, state);
    #####:  761:    break;
        -:  762:
        -:  763:    case council_room:
        -:  764:      //+4 Cards
    #####:  765:      for (i = 0; i < 4; i++)
        -:  766:	{
    #####:  767:	  drawCard(currentPlayer, state);
        -:  768:	}
        -:  769:
        -:  770:      //+1 Buy
    #####:  771:      state->numBuys++;
        -:  772:
        -:  773:      //Each other player draws a card
    #####:  774:      for (i = 0; i < state->numPlayers; i++)
        -:  775:	{
    #####:  776:	  if ( i != currentPlayer )
        -:  777:	    {
    #####:  778:	      drawCard(i, state);
        -:  779:	    }
        -:  780:	}
        -:  781:
        -:  782:      //put played card in played card pile
    #####:  783:      discardCard(handPos, currentPlayer, state, 0);
        -:  784:
    #####:  785:      return 0;
        -:  786:
        -:  787:    case feast:
        -:  788:      //gain card with cost up to 5
        -:  789:      //Backup hand
    #####:  790:      for (i = 0; i <= state->handCount[currentPlayer]; i++){
    #####:  791:	temphand[i] = state->hand[currentPlayer][i];//Backup card
    #####:  792:	state->hand[currentPlayer][i] = -1;//Set to nothing
        -:  793:      }
        -:  794:      //Backup hand
        -:  795:
        -:  796:      //Update Coins for Buy
    #####:  797:      updateCoins(currentPlayer, state, 5);
    #####:  798:      x = 1;//Condition to loop on
    #####:  799:      while( x == 1) {//Buy one card
    #####:  800:	if (supplyCount(choice1, state) <= 0){
        -:  801:	  if (DEBUG)
        -:  802:	    printf("None of that card left, sorry!\n");
        -:  803:
        -:  804:	  if (DEBUG){
        -:  805:	    printf("Cards Left: %d\n", supplyCount(choice1, state));
        -:  806:	  }
        -:  807:	}
    #####:  808:	else if (state->coins < getCost(choice1)){
    #####:  809:	  printf("That card is too expensive!\n");
        -:  810:
        -:  811:	  if (DEBUG){
        -:  812:	    printf("Coins: %d < %d\n", state->coins, getCost(choice1));
        -:  813:	  }
        -:  814:	}
        -:  815:	else{
        -:  816:
        -:  817:	  if (DEBUG){
        -:  818:	    printf("Deck Count: %d\n", state->handCount[currentPlayer] + state->deckCount[currentPlayer] + state->discardCount[currentPlayer]);
        -:  819:	  }
        -:  820:
    #####:  821:	  gainCard(choice1, state, 0, currentPlayer);//Gain the card
    #####:  822:	  x = 0;//No more buying cards
        -:  823:
        -:  824:	  if (DEBUG){
        -:  825:	    printf("Deck Count: %d\n", state->handCount[currentPlayer] + state->deckCount[currentPlayer] + state->discardCount[currentPlayer]);
        -:  826:	  }
        -:  827:
        -:  828:	}
        -:  829:      }
        -:  830:
        -:  831:      //Reset Hand
    #####:  832:      for (i = 0; i <= state->handCount[currentPlayer]; i++){
    #####:  833:	state->hand[currentPlayer][i] = temphand[i];
    #####:  834:	temphand[i] = -1;
        -:  835:      }
        -:  836:      //Reset Hand
        -:  837:
    #####:  838:      return 0;
        -:  839:
        -:  840:    case gardens:
    #####:  841:      return -1;
        -:  842:
        -:  843:    case mine:
    #####:  844:      j = state->hand[currentPlayer][choice1];  //store card we will trash
        -:  845:
    #####:  846:      if (state->hand[currentPlayer][choice1] < copper || state->hand[currentPlayer][choice1] > gold)
        -:  847:	{
    #####:  848:	  return -1;
        -:  849:	}
        -:  850:
    #####:  851:      if (choice2 > treasure_map || choice2 < curse)
        -:  852:	{
    #####:  853:	  return -1;
        -:  854:	}
        -:  855:
    #####:  856:      if ( (getCost(state->hand[currentPlayer][choice1]) + 3) > getCost(choice2) )
        -:  857:	{
    #####:  858:	  return -1;
        -:  859:	}
        -:  860:
    #####:  861:      gainCard(choice2, state, 2, currentPlayer);
        -:  862:
        -:  863:      //discard card from hand
    #####:  864:      discardCard(handPos, currentPlayer, state, 0);
        -:  865:
        -:  866:      //discard trashed card
    #####:  867:      for (i = 0; i < state->handCount[currentPlayer]; i++)
        -:  868:	{
    #####:  869:	  if (state->hand[currentPlayer][i] == j)
        -:  870:	    {
    #####:  871:	      discardCard(i, currentPlayer, state, 0);
    #####:  872:	      break;
        -:  873:	    }
        -:  874:	}
        -:  875:
    #####:  876:      return 0;
        -:  877:
        -:  878:    case remodel:
    #####:  879:    remodelCard(currentPlayer, state, handPos, choice1, choice2);
    #####:  880:    break;
        -:  881:
        -:  882:    case smithy:
        -:  883:    // Call  smithy function
       10:  884:    smithyCard(currentPlayer, state, handPos);
       10:  885:    break;
        -:  886:
        -:  887:    case village:
        -:  888:      //+1 Card
       10:  889:      drawCard(currentPlayer, state);
        -:  890:
        -:  891:      //+2 Actions
       10:  892:      state->numActions = state->numActions + 2;
        -:  893:
        -:  894:      //discard played card from hand
       10:  895:      discardCard(handPos, currentPlayer, state, 0);
       10:  896:      return 0;
        -:  897:
        -:  898:    case baron:
    #####:  899:      state->numBuys++;//Increase buys by 1!
    #####:  900:      if (choice1 > 0){//Boolean true or going to discard an estate
    #####:  901:	int p = 0;//Iterator for hand!
    #####:  902:	int card_not_discarded = 1;//Flag for discard set!
    #####:  903:	while(card_not_discarded){
    #####:  904:	  if (state->hand[currentPlayer][p] == estate){//Found an estate card!
    #####:  905:	    state->coins += 4;//Add 4 coins to the amount of coins
    #####:  906:	    state->discard[currentPlayer][state->discardCount[currentPlayer]] = state->hand[currentPlayer][p];
    #####:  907:	    state->discardCount[currentPlayer]++;
    #####:  908:	    for (;p < state->handCount[currentPlayer]; p++){
    #####:  909:	      state->hand[currentPlayer][p] = state->hand[currentPlayer][p+1];
        -:  910:	    }
    #####:  911:	    state->hand[currentPlayer][state->handCount[currentPlayer]] = -1;
    #####:  912:	    state->handCount[currentPlayer]--;
    #####:  913:	    card_not_discarded = 0;//Exit the loop
        -:  914:	  }
    #####:  915:	  else if (p > state->handCount[currentPlayer]){
        -:  916:	    if(DEBUG) {
        -:  917:	      printf("No estate cards in your hand, invalid choice\n");
        -:  918:	      printf("Must gain an estate if there are any\n");
        -:  919:	    }
    #####:  920:	    if (supplyCount(estate, state) > 0){
    #####:  921:	      gainCard(estate, state, 0, currentPlayer);
    #####:  922:	      state->supplyCount[estate]--;//Decrement estates
    #####:  923:	      if (supplyCount(estate, state) == 0){
    #####:  924:		isGameOver(state);
        -:  925:	      }
        -:  926:	    }
    #####:  927:	    card_not_discarded = 0;//Exit the loop
        -:  928:	  }
        -:  929:
        -:  930:	  else{
    #####:  931:	    p++;//Next card
        -:  932:	  }
        -:  933:	}
        -:  934:      }
        -:  935:
        -:  936:      else{
    #####:  937:	if (supplyCount(estate, state) > 0){
    #####:  938:	  gainCard(estate, state, 0, currentPlayer);//Gain an estate
    #####:  939:	  state->supplyCount[estate]--;//Decrement Estates
    #####:  940:	  if (supplyCount(estate, state) == 0){
    #####:  941:	    isGameOver(state);
        -:  942:	  }
        -:  943:	}
        -:  944:      }
        -:  945:
        -:  946:
    #####:  947:      return 0;
        -:  948:
        -:  949:    case great_hall:
       10:  950:    greatHallCard(currentPlayer, state, handPos);
       10:  951:    break;
        -:  952:
        -:  953:    case minion:
        -:  954:      //+1 action
    #####:  955:      state->numActions++;
        -:  956:
        -:  957:      //discard card from hand
    #####:  958:      discardCard(handPos, currentPlayer, state, 0);
        -:  959:
    #####:  960:      if (choice1)		//+2 coins
        -:  961:	{
    #####:  962:	  state->coins = state->coins + 2;
        -:  963:	}
        -:  964:
    #####:  965:      else if (choice2)		//discard hand, redraw 4, other players with 5+ cards discard hand and draw 4
        -:  966:	{
        -:  967:	  //discard hand
    #####:  968:	  while(numHandCards(state) > 0)
        -:  969:	    {
    #####:  970:	      discardCard(handPos, currentPlayer, state, 0);
        -:  971:	    }
        -:  972:
        -:  973:	  //draw 4
    #####:  974:	  for (i = 0; i < 4; i++)
        -:  975:	    {
    #####:  976:	      drawCard(currentPlayer, state);
        -:  977:	    }
        -:  978:
        -:  979:	  //other players discard hand and redraw if hand size > 4
    #####:  980:	  for (i = 0; i < state->numPlayers; i++)
        -:  981:	    {
    #####:  982:	      if (i != currentPlayer)
        -:  983:		{
    #####:  984:		  if ( state->handCount[i] > 4 )
        -:  985:		    {
        -:  986:		      //discard hand
    #####:  987:		      while( state->handCount[i] > 0 )
        -:  988:			{
    #####:  989:			  discardCard(handPos, i, state, 0);
        -:  990:			}
        -:  991:
        -:  992:		      //draw 4
    #####:  993:		      for (j = 0; j < 4; j++)
        -:  994:			{
    #####:  995:			  drawCard(i, state);
        -:  996:			}
        -:  997:		    }
        -:  998:		}
        -:  999:	    }
        -: 1000:
        -: 1001:	}
    #####: 1002:      return 0;
        -: 1003:
        -: 1004:    case steward:
    #####: 1005:      if (choice1 == 1)
        -: 1006:	{
        -: 1007:	  //+2 cards
    #####: 1008:	  drawCard(currentPlayer, state);
    #####: 1009:	  drawCard(currentPlayer, state);
        -: 1010:	}
    #####: 1011:      else if (choice1 == 2)
        -: 1012:	{
        -: 1013:	  //+2 coins
    #####: 1014:	  state->coins = state->coins + 2;
        -: 1015:	}
        -: 1016:      else
        -: 1017:	{
        -: 1018:	  //trash 2 cards in hand
    #####: 1019:	  discardCard(choice2, currentPlayer, state, 1);
    #####: 1020:	  discardCard(choice3, currentPlayer, state, 1);
        -: 1021:	}
        -: 1022:
        -: 1023:      //discard card from hand
    #####: 1024:      discardCard(handPos, currentPlayer, state, 0);
    #####: 1025:      return 0;
        -: 1026:
        -: 1027:    case tribute:
    #####: 1028:      if ((state->discardCount[nextPlayer] + state->deckCount[nextPlayer]) <= 1){
    #####: 1029:	if (state->deckCount[nextPlayer] > 0){
    #####: 1030:	  tributeRevealedCards[0] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
    #####: 1031:	  state->deckCount[nextPlayer]--;
        -: 1032:	}
    #####: 1033:	else if (state->discardCount[nextPlayer] > 0){
    #####: 1034:	  tributeRevealedCards[0] = state->discard[nextPlayer][state->discardCount[nextPlayer]-1];
    #####: 1035:	  state->discardCount[nextPlayer]--;
        -: 1036:	}
        -: 1037:	else{
        -: 1038:	  //No Card to Reveal
        -: 1039:	  if (DEBUG){
        -: 1040:	    printf("No cards to reveal\n");
        -: 1041:	  }
        -: 1042:	}
        -: 1043:      }
        -: 1044:
        -: 1045:      else{
    #####: 1046:	if (state->deckCount[nextPlayer] == 0){
    #####: 1047:	  for (i = 0; i < state->discardCount[nextPlayer]; i++){
    #####: 1048:	    state->deck[nextPlayer][i] = state->discard[nextPlayer][i];//Move to deck
    #####: 1049:	    state->deckCount[nextPlayer]++;
    #####: 1050:	    state->discard[nextPlayer][i] = -1;
    #####: 1051:	    state->discardCount[nextPlayer]--;
        -: 1052:	  }
        -: 1053:
    #####: 1054:	  shuffle(nextPlayer,state);//Shuffle the deck
        -: 1055:	}
    #####: 1056:	tributeRevealedCards[0] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
    #####: 1057:	state->deck[nextPlayer][state->deckCount[nextPlayer]--] = -1;
    #####: 1058:	state->deckCount[nextPlayer]--;
    #####: 1059:	tributeRevealedCards[1] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
    #####: 1060:	state->deck[nextPlayer][state->deckCount[nextPlayer]--] = -1;
    #####: 1061:	state->deckCount[nextPlayer]--;
        -: 1062:      }
        -: 1063:
    #####: 1064:      if (tributeRevealedCards[0] == tributeRevealedCards[1]){//If we have a duplicate card, just drop one
    #####: 1065:	state->playedCards[state->playedCardCount] = tributeRevealedCards[1];
    #####: 1066:	state->playedCardCount++;
    #####: 1067:	tributeRevealedCards[1] = -1;
        -: 1068:      }
        -: 1069:
    #####: 1070:      for (i = 0; i <= 2; i ++){
    #####: 1071:	if (tributeRevealedCards[i] == copper || tributeRevealedCards[i] == silver || tributeRevealedCards[i] == gold){//Treasure cards
    #####: 1072:	  state->coins += 2;
        -: 1073:	}
        -: 1074:
    #####: 1075:	else if (tributeRevealedCards[i] == estate || tributeRevealedCards[i] == duchy || tributeRevealedCards[i] == province || tributeRevealedCards[i] == gardens || tributeRevealedCards[i] == great_hall){//Victory Card Found
    #####: 1076:	  drawCard(currentPlayer, state);
    #####: 1077:	  drawCard(currentPlayer, state);
        -: 1078:	}
        -: 1079:	else{//Action Card
    #####: 1080:	  state->numActions = state->numActions + 2;
        -: 1081:	}
        -: 1082:      }
        -: 1083:
    #####: 1084:      return 0;
        -: 1085:
        -: 1086:    case ambassador:
    #####: 1087:      j = 0;		//used to check if player has enough cards to discard
        -: 1088:
    #####: 1089:      if (choice2 > 2 || choice2 < 0)
        -: 1090:	{
    #####: 1091:	  return -1;
        -: 1092:	}
        -: 1093:
    #####: 1094:      if (choice1 == handPos)
        -: 1095:	{
    #####: 1096:	  return -1;
        -: 1097:	}
        -: 1098:
    #####: 1099:      for (i = 0; i < state->handCount[currentPlayer]; i++)
        -: 1100:	{
    #####: 1101:	  if (i != handPos && i == state->hand[currentPlayer][choice1] && i != choice1)
        -: 1102:	    {
    #####: 1103:	      j++;
        -: 1104:	    }
        -: 1105:	}
    #####: 1106:      if (j < choice2)
        -: 1107:	{
    #####: 1108:	  return -1;
        -: 1109:	}
        -: 1110:
        -: 1111:      if (DEBUG)
        -: 1112:	printf("Player %d reveals card number: %d\n", currentPlayer, state->hand[currentPlayer][choice1]);
        -: 1113:
        -: 1114:      //increase supply count for choosen card by amount being discarded
    #####: 1115:      state->supplyCount[state->hand[currentPlayer][choice1]] += choice2;
        -: 1116:
        -: 1117:      //each other player gains a copy of revealed card
    #####: 1118:      for (i = 0; i < state->numPlayers; i++)
        -: 1119:	{
    #####: 1120:	  if (i != currentPlayer)
        -: 1121:	    {
    #####: 1122:	      gainCard(state->hand[currentPlayer][choice1], state, 0, i);
        -: 1123:	    }
        -: 1124:	}
        -: 1125:
        -: 1126:      //discard played card from hand
    #####: 1127:      discardCard(handPos, currentPlayer, state, 0);
        -: 1128:
        -: 1129:      //trash copies of cards returned to supply
    #####: 1130:      for (j = 0; j < choice2; j++)
        -: 1131:	{
    #####: 1132:	  for (i = 0; i < state->handCount[currentPlayer]; i++)
        -: 1133:	    {
    #####: 1134:	      if (state->hand[currentPlayer][i] == state->hand[currentPlayer][choice1])
        -: 1135:		{
    #####: 1136:		  discardCard(i, currentPlayer, state, 1);
    #####: 1137:		  break;
        -: 1138:		}
        -: 1139:	    }
        -: 1140:	}
        -: 1141:
    #####: 1142:      return 0;
        -: 1143:
        -: 1144:    case cutpurse:
        -: 1145:
    #####: 1146:      updateCoins(currentPlayer, state, 2);
    #####: 1147:      for (i = 0; i < state->numPlayers; i++)
        -: 1148:	{
    #####: 1149:	  if (i != currentPlayer)
        -: 1150:	    {
    #####: 1151:	      for (j = 0; j < state->handCount[i]; j++)
        -: 1152:		{
    #####: 1153:		  if (state->hand[i][j] == copper)
        -: 1154:		    {
    #####: 1155:		      discardCard(j, i, state, 0);
    #####: 1156:		      break;
        -: 1157:		    }
    #####: 1158:		  if (j == state->handCount[i])
        -: 1159:		    {
    #####: 1160:		      for (k = 0; k < state->handCount[i]; k++)
        -: 1161:			{
        -: 1162:			  if (DEBUG)
        -: 1163:			    printf("Player %d reveals card number %d\n", i, state->hand[i][k]);
        -: 1164:			}
    #####: 1165:		      break;
        -: 1166:		    }
        -: 1167:		}
        -: 1168:
        -: 1169:	    }
        -: 1170:
        -: 1171:	}
        -: 1172:
        -: 1173:      //discard played card from hand
    #####: 1174:      discardCard(handPos, currentPlayer, state, 0);
        -: 1175:
    #####: 1176:      return 0;
        -: 1177:
        -: 1178:
        -: 1179:    case embargo:
        -: 1180:      //+2 Coins
    #####: 1181:      state->coins = state->coins + 2;
        -: 1182:
        -: 1183:      //see if selected pile is in play
    #####: 1184:      if ( state->supplyCount[choice1] == -1 )
        -: 1185:	{
    #####: 1186:	  return -1;
        -: 1187:	}
        -: 1188:
        -: 1189:      //add embargo token to selected supply pile
    #####: 1190:      state->embargoTokens[choice1]++;
        -: 1191:
        -: 1192:      //trash card
    #####: 1193:      discardCard(handPos, currentPlayer, state, 1);
    #####: 1194:      return 0;
        -: 1195:
        -: 1196:    case outpost:
        -: 1197:      //set outpost flag
    #####: 1198:      state->outpostPlayed++;
        -: 1199:
        -: 1200:      //discard card
    #####: 1201:      discardCard(handPos, currentPlayer, state, 0);
    #####: 1202:      return 0;
        -: 1203:
        -: 1204:    case salvager:
        -: 1205:      //+1 buy
    #####: 1206:      state->numBuys++;
        -: 1207:
    #####: 1208:      if (choice1)
        -: 1209:	{
        -: 1210:	  //gain coins equal to trashed card
    #####: 1211:	  state->coins = state->coins + getCost( handCard(choice1, state) );
        -: 1212:	  //trash card
    #####: 1213:	  discardCard(choice1, currentPlayer, state, 1);
        -: 1214:	}
        -: 1215:
        -: 1216:      //discard card
    #####: 1217:      discardCard(handPos, currentPlayer, state, 0);
    #####: 1218:      return 0;
        -: 1219:
        -: 1220:    case sea_hag:
    #####: 1221:    SeaHagCard(currentPlayer, state);
    #####: 1222:    break;
        -: 1223:
        -: 1224:    case treasure_map:
        -: 1225:      //search hand for another treasure_map
    #####: 1226:      index = -1;
    #####: 1227:      for (i = 0; i < state->handCount[currentPlayer]; i++)
        -: 1228:	{
    #####: 1229:	  if (state->hand[currentPlayer][i] == treasure_map && i != handPos)
        -: 1230:	    {
    #####: 1231:	      index = i;
    #####: 1232:	      break;
        -: 1233:	    }
        -: 1234:	}
    #####: 1235:      if (index > -1)
        -: 1236:	{
        -: 1237:	  //trash both treasure cards
    #####: 1238:	  discardCard(handPos, currentPlayer, state, 1);
    #####: 1239:	  discardCard(index, currentPlayer, state, 1);
        -: 1240:
        -: 1241:	  //gain 4 Gold cards
    #####: 1242:	  for (i = 0; i < 4; i++)
        -: 1243:	    {
    #####: 1244:	      gainCard(gold, state, 1, currentPlayer);
        -: 1245:	    }
        -: 1246:
        -: 1247:	  //return success
    #####: 1248:	  return 1;
        -: 1249:	}
        -: 1250:
        -: 1251:      //no second treasure_map found in hand
    #####: 1252:      return -1;
        -: 1253:    }
        -: 1254:
       20: 1255:  return -1;
        -: 1256:}
        -: 1257:
       30: 1258:int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)
        -: 1259:{
        -: 1260:
        -: 1261:  //if card is not trashed, added to Played pile
       30: 1262:  if (trashFlag < 1)
        -: 1263:    {
        -: 1264:      //add card to played pile
       30: 1265:      state->playedCards[state->playedCardCount] = state->hand[currentPlayer][handPos];
       30: 1266:      state->playedCardCount++;
        -: 1267:    }
        -: 1268:
        -: 1269:  //set played card to -1
       30: 1270:  state->hand[currentPlayer][handPos] = -1;
        -: 1271:
        -: 1272:  //remove card from player's hand
       30: 1273:  if ( handPos == (state->handCount[currentPlayer] - 1) ) 	//last card in hand array is played
        -: 1274:    {
        -: 1275:      //reduce number of cards in hand
    #####: 1276:      state->handCount[currentPlayer]--;
        -: 1277:    }
       30: 1278:  else if ( state->handCount[currentPlayer] == 1 ) //only one card in hand
        -: 1279:    {
        -: 1280:      //reduce number of cards in hand
    #####: 1281:      state->handCount[currentPlayer]--;
        -: 1282:    }
        -: 1283:  else
        -: 1284:    {
        -: 1285:      //replace discarded card with last card in hand
       30: 1286:      state->hand[currentPlayer][handPos] = state->hand[currentPlayer][ (state->handCount[currentPlayer] - 1)];
        -: 1287:      //set last card to -1
       30: 1288:      state->hand[currentPlayer][state->handCount[currentPlayer] - 1] = -1;
        -: 1289:      //reduce number of cards in hand
       30: 1290:      state->handCount[currentPlayer]--;
        -: 1291:    }
        -: 1292:
       30: 1293:  return 0;
        -: 1294:}
        -: 1295:
    #####: 1296:int gainCard(int supplyPos, struct gameState *state, int toFlag, int player)
        -: 1297:{
        -: 1298:  //Note: supplyPos is enum of choosen card
        -: 1299:
        -: 1300:  //check if supply pile is empty (0) or card is not used in game (-1)
    #####: 1301:  if ( supplyCount(supplyPos, state) < 1 )
        -: 1302:    {
    #####: 1303:      return -1;
        -: 1304:    }
        -: 1305:
        -: 1306:  //added card for [whoseTurn] current player:
        -: 1307:  // toFlag = 0 : add to discard
        -: 1308:  // toFlag = 1 : add to deck
        -: 1309:  // toFlag = 2 : add to hand
        -: 1310:
    #####: 1311:  if (toFlag == 1)
        -: 1312:    {
    #####: 1313:      state->deck[ player ][ state->deckCount[player] ] = supplyPos;
    #####: 1314:      state->deckCount[player]++;
        -: 1315:    }
    #####: 1316:  else if (toFlag == 2)
        -: 1317:    {
    #####: 1318:      state->hand[ player ][ state->handCount[player] ] = supplyPos;
    #####: 1319:      state->handCount[player]++;
        -: 1320:    }
        -: 1321:  else
        -: 1322:    {
    #####: 1323:      state->discard[player][ state->discardCount[player] ] = supplyPos;
    #####: 1324:      state->discardCount[player]++;
        -: 1325:    }
        -: 1326:
        -: 1327:  //decrease number in supply pile
    #####: 1328:  state->supplyCount[supplyPos]--;
        -: 1329:
    #####: 1330:  return 0;
        -: 1331:}
        -: 1332:
       33: 1333:int updateCoins(int player, struct gameState *state, int bonus)
        -: 1334:{
        -: 1335:  int i;
        -: 1336:
        -: 1337:  //reset coin count
       33: 1338:  state->coins = 0;
        -: 1339:
        -: 1340:  //add coins for each Treasure card in player's hand
      198: 1341:  for (i = 0; i < state->handCount[player]; i++)
        -: 1342:    {
      165: 1343:      if (state->hand[player][i] == copper)
        -: 1344:	{
      132: 1345:	  state->coins += 1;
        -: 1346:	}
       33: 1347:      else if (state->hand[player][i] == silver)
        -: 1348:	{
    #####: 1349:	  state->coins += 2;
        -: 1350:	}
       33: 1351:      else if (state->hand[player][i] == gold)
        -: 1352:	{
    #####: 1353:	  state->coins += 3;
        -: 1354:	}
        -: 1355:    }
        -: 1356:
        -: 1357:  //add bonus
       33: 1358:  state->coins += bonus;
        -: 1359:
       33: 1360:  return 0;
        -: 1361:}
        -: 1362:
        -: 1363:
        -: 1364://end of dominion.c
        -: 1365:





*/
