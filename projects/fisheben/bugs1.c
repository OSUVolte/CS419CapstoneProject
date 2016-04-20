/*********************************************************************************************
* Description of Bugs found from unit tests
*
* 
* File 'unittest3.c' found one bug, tested discardCard function 
* Bug 1: 
* Priority: High
* Reproduce: See unit test 3, error flag 1 (postCall.discardCount[p] != preCall.discardCount[p] + 1 && !errorFlag1)
* Description: Game state post call discardCount is not one more than the game state pre call to discardCardCount.
*
* File 'cardtest2.c' found 8 bugs, tested adventurer card
* Bug 2: 
* Priority: High
* Reproduce: See cardtest2 errorflag 1,(postCall.handCount[p] != (preCall.handCount[p] + 1)
* Description: Game state post call to adventurer has too many cards in players hand, handCount is off
* Test 3 failed, game state pre and post call are not equal. 
* Bug 3: 
* Priority: High
* Reproduce: See cardtest2 errorflag 3, memcmp(&preCall, &postCall, sizeof(struct gameState)) != 0 && !errorFlag3)
* Description: Game state post call is not equal to preCall, may be related to Bug 2
* Bug 4: 
* Priority: High
* Reproduce: See cardtest2 errorflag 4, (postCall.playedCardCount != (preCall.playedCardCount + 1) && !errorFlag4)
* Description: Player has not discarded the played card properly, playCardCount is off
* Bug 5: 
* Priority: High
* Reproduce: See cardtest2 errorflag 5, (postCall.hand[p][cardPosition] == adventurer) || (preCall.hand[p][cardPosition] != adventurer)) && !errorFlag5)
* Description: Adventurer card is still in players hand
* Bug 6: 
* Priority: High
* Reproduce: See cardtest2 errorflag 6, (postCall.deckCount[p] != (preCall.deckCount[p] - 10)
* Description: Deck count post call should be 0 but it is 8, deck was stack so treasure cards were at front of a 10 card deck
* Bug 7: 
* Priority: High
* Reproduce: See cardtest2 errorflag 7, (postCall.discardCount[p] != preCall.discardCount[p] + 8 && !errorFlag7)
* Description: Discard count is off may be related to Bug 2
* Bug 8: 
* Priority: High
* Reproduce: See cardtest2 errorflag 8, (memcmp(&preCall, &postCall, sizeof(struct gameState)) != 0 && ! errorFlag8)
* Description: Game state is not identical pre call and post call to adventurer may be related to Bug 2
* Bug 9: 
* Priority: High
* Reproduce: See cardtest2 errorflag 9, (postCall.handCount[p] != (preCall.handCount[p])) && !errorFlag9)
* Description: adventurer tested with no treasure cards, so hand counts should be the same pre and post calls.
