// Jake McMillen; mcmiljac@oregonstate.edu
// CS 362 - Assignment 3
// 24 April 2016

For the cardtests, the tests for playSmithy, playVillage, and playCouncil_Room achieved 100% statement coverage. This can be seen by examining the dominion.c.gcov file. Every line of codes in these three functions has been run at least once. The coverage for playAdventurer was not as good, however, since a significant number of statements were not executed. This resulted since there are a variety of cards that can be drawn, with the treasure and nontreasure cards being handled differently. I plan to improve this test in the future by constructing a variety of deck arrangements so that the treasure cards are spaced out differently.

For the method tests, handCard, updateCoins had 100% statement coverage. GainCard had nearly full statement coverage, however, it did not encounter a case where it tried to gain a card where the supply had been fully depleted. The unit test should be altered to include such a case in the future. DiscardCard missed two possible braches, namely when the player has exactly one card in her hand before discard, and when the player discards the last card in the card array. Again, the unit test should be altered to include these cases in order to obtain better coverage.

The relevant portions of the dominion.c.gcov file are shown below for reference:


        5:  314:int handCard(int handPos, struct gameState *state) {
        5:  315:  int currentPlayer = whoseTurn(state);
        5:  316:  return state->hand[currentPlayer][handPos];
        -:  317:}


	   24: 1143:int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag){
        -: 1144:	
        -: 1145:  //if card is not trashed, added to Played pile 
       24: 1146:  if (trashFlag < 1)
        -: 1147:    {
        -: 1148:      //add card to played pile
       21: 1149:      state->playedCards[state->playedCardCount] = state->hand[currentPlayer][handPos]; 
       21: 1150:      state->playedCardCount++;
        -: 1151:    }
        -: 1152:	
        -: 1153:  //set played card to -1
       24: 1154:  state->hand[currentPlayer][handPos] = -1;
        -: 1155:	
        -: 1156:  //remove card from player's hand
       24: 1157:  if ( handPos == (state->handCount[currentPlayer] - 1) ) 	//last card in hand array is played
        -: 1158:    {
        -: 1159:      //reduce number of cards in hand
    #####: 1160:      state->handCount[currentPlayer]--;
        -: 1161:    }
       24: 1162:  else if ( state->handCount[currentPlayer] == 1 ) //only one card in hand
        -: 1163:    {
        -: 1164:      //reduce number of cards in hand
    #####: 1165:      state->handCount[currentPlayer]--;
        -: 1166:    }
        -: 1167:  else 	
        -: 1168:    {
        -: 1169:      //replace discarded card with last card in hand
       24: 1170:      state->hand[currentPlayer][handPos] = state->hand[currentPlayer][ (state->handCount[currentPlayer] - 1)];
        -: 1171:      //set last card to -1
       24: 1172:      state->hand[currentPlayer][state->handCount[currentPlayer] - 1] = -1;
        -: 1173:      //reduce number of cards in hand
       24: 1174:      state->handCount[currentPlayer]--;
        -: 1175:    }
        -: 1176:	
       24: 1177:  return 0;
        -: 1178:}
        -: 1179:

		
       30: 1180:int gainCard(int supplyPos, struct gameState *state, int toFlag, int player){
        -: 1181:  //Note: supplyPos is enum of choosen card
        -: 1182:	
        -: 1183:  //check if supply pile is empty (0) or card is not used in game (-1)
       30: 1184:  if ( supplyCount(supplyPos, state) < 1 )
        -: 1185:    {
    #####: 1186:      return -1;
        -: 1187:    }
        -: 1188:	
        -: 1189:  //added card for [whoseTurn] current player:
        -: 1190:  // toFlag = 0 : add to discard
        -: 1191:  // toFlag = 1 : add to deck
        -: 1192:  // toFlag = 2 : add to hand
        -: 1193:
       30: 1194:  if (toFlag == 1)
        -: 1195:    {
       10: 1196:      state->deck[ player ][ state->deckCount[player] ] = supplyPos;
       10: 1197:      state->deckCount[player]++;
        -: 1198:    }
       20: 1199:  else if (toFlag == 2)
        -: 1200:    {
       10: 1201:      state->hand[ player ][ state->handCount[player] ] = supplyPos;
       10: 1202:      state->handCount[player]++;
        -: 1203:    }
        -: 1204:  else
        -: 1205:    {
       10: 1206:      state->discard[player][ state->discardCount[player] ] = supplyPos;
       10: 1207:      state->discardCount[player]++;
        -: 1208:    }
        -: 1209:	
        -: 1210:  //decrease number in supply pile
       30: 1211:  state->supplyCount[supplyPos]--;
        -: 1212:	 
       30: 1213:  return 0;
        -: 1214:}
        -: 1215:

	   66: 1216:int updateCoins(int player, struct gameState *state, int bonus){
        -: 1217:  int i;
        -: 1218:	
        -: 1219:  //reset coin count
       32: 1220:  state->coins = 0;
        -: 1221:
        -: 1222:  //add coins for each Treasure card in player's hand
      207: 1223:  for (i = 0; i < state->handCount[player]; i++)
        -: 1224:    {
      175: 1225:      if (state->hand[player][i] == copper)
        -: 1226:	{
      133: 1227:	  state->coins += 1;
        -: 1228:	}
       42: 1229:      else if (state->hand[player][i] == silver)
        -: 1230:	{
        5: 1231:	  state->coins += 2;
        -: 1232:	}
       37: 1233:      else if (state->hand[player][i] == gold)
        -: 1234:	{
        5: 1235:	  state->coins += 3;
        -: 1236:	}	
        -: 1237:    }	
        -: 1238:
        -: 1239:  //add bonus
       32: 1240:  state->coins += bonus;
        -: 1241:
       32: 1242:  return 0;
        -: 1243:}

		
        1: 1245:int playAdventurer(struct gameState *state){
        1: 1246:	int drawnTreasure = 0;
        -: 1247:	int cardDrawn;
        1: 1248:	int currentPlayer = whoseTurn(state);
        -: 1249:	int tempHand[MAX_HAND];
        1: 1250:	int z = 0;		// this is the counter for the temp hand
        -: 1251:
        4: 1252:	while(drawnTreasure < 2){
        2: 1253:		if (state->deckCount[currentPlayer] <1){	//if the deck is empty we need to shuffle discard and add to deck
    #####: 1254:			shuffle(currentPlayer, state);
        -: 1255:		}
        2: 1256:		drawCard(currentPlayer, state);
        2: 1257:		cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
        -: 1258:		
        2: 1259:		if (cardDrawn == copper || cardDrawn == silver)
        2: 1260:			drawnTreasure++;
        -: 1261:		else {
    #####: 1262:			tempHand[z]=cardDrawn;
    #####: 1263:			state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
    #####: 1264:			z++;
        -: 1265:		}
        -: 1266:    }
        -: 1267:    
        2: 1268:	while(z-1 >= 0){
    #####: 1269:		state->discard[currentPlayer][state->discardCount[currentPlayer]++] = tempHand[z-1]; // discard all cards in play that have been drawn
    #####: 1270:		z--;
        -: 1271:	}
        1: 1272:    return 0;	
        -: 1273:}

		
        6: 1275:int playSmithy(struct gameState *state, int handPos){
        -: 1276:	//+3 Cards
        -: 1277:    int i;
        6: 1278:	int currentPlayer = whoseTurn(state);
       24: 1279:	for (i = 0; i < 3; i++){
       18: 1280:	  drawCard(currentPlayer, state);
        -: 1281:	}
        6: 1282:	state->numActions++;
        -: 1283:			
        -: 1284:    //discard card from hand
        6: 1285:    discardCard(handPos, currentPlayer, state, 0);
        6: 1286:    return 0;
        -: 1287:}

		
        6: 1289:int playVillage(struct gameState *state, int handPos){
        -: 1290:	//+1 Card
        6: 1291:	int currentPlayer = whoseTurn(state);
        6: 1292:    drawCard(currentPlayer, state);
        -: 1293:			
        -: 1294:    //+2 Actions
        -: 1295:    //state->numActions++;
        -: 1296:			
        -: 1297:    //discard played card from hand
        6: 1298:    discardCard(handPos, currentPlayer, state, 0);
        6: 1299:	return 0;
        -: 1300:}
 
 
        6: 1327:int playCouncil_Room(struct gameState *state, int handPos){
        -: 1328:	int i;
        6: 1329:	int currentPlayer = whoseTurn(state);
        -: 1330:	
        -: 1331:	//+4 Cards
       30: 1332:    for (i = 0; i < 4; i++){
       24: 1333:		drawCard(currentPlayer, state);
        -: 1334:	}
        -: 1335:			
        -: 1336:    //+1 Buy
        6: 1337:    state->numBuys++;
        -: 1338:		
        -: 1339:    //Each other player draws a card
       12: 1340:    for (i = 1; i < state->numPlayers; i++){
        6: 1341:		if (i != currentPlayer){
        6: 1342:			drawCard(i, state);
        -: 1343:	    }
        -: 1344:	}
        -: 1345:			
        -: 1346:    //put played card in played card pile
        6: 1347:    discardCard(handPos, currentPlayer, state, 0);
        6: 1348:	return 0;
        -: 1349:}
        -: 1350:
        -: 1351:
        -: 1352://end of dominion.c
        -: 1353:
