Functions added during refactor:  Both dominion.c and dominion.h were changed to support refactor.
 
	    Card                       Function
     adventurer         playAdventurer(struct gameState *state)
     ambassador         playAmbassador(struct gameState *state, int choice1, int choice2, int handPos)
     baron              playBaron(struct gameState *state, int choice1, int choice2, int handPos)
     council_room       playCouncil_Room(struct gameState *state, int handPos)
     cutpurse           playCutpurse(struct gameState *state, int handPos)
     embargo            playEmbargo(struct gameState *state, int choice1, int handPos)
     feast              playFeast(struct gameState *state, int choice1)
     great_hall         playGreat_hall(struct gameState *state, int handPos)
     mine               playMine(struct gameState *state, int choice1, int choice2, int handPos)
     minion             playMinion(struct gameState *state, int choice1, int choice2, int handPos)
     outpost            playOutpost(struct gameState *state, int handPos)
     remodel            playRemodel(struct gameState *state, int choice1, int choice2, int handPos)
     salvager           playSalvager(struct gameState *state, int choice1, int handPos)
     sea_hag            playSea_hag(struct gameState *state)
     smithy             playSmithy(struct gameState *state, int handPos)
     steward            playSteward(struct gameState *state, int choice1, int choice2, int choice3, int handPos)
     treasure_map       playTreasure_map(struct gameState *state, int handPos)
     tribute            playTribure(struct gameState *state)
     village            playVillage(struct gameState *state, int handPos)

The five functions choosen for assignment 2

    1.  Adventurer
        Bugs introduced:
	    a.  Changed the test used for identifying treasure cards
	        original: if(cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
                     bug: if(cardDrawn == copper || cardDrawn == gold)
            b.  Changed the boundary condition used to test the number of treasure cards revealed.
                original: while(drawntreasure<2)
                     bug: while(drawntreasure<=2)
            c.  Changed the deck count threshold used to determine the need for a shuffle
                original: if(state->deckCount[currentPlayer] < 1)
                     bug: if(state->deckCount[currentPlayer] == 1)
            d.  Changed the remove card from hand statement when card drawn is not a treasure card
                original: state->handCount[currentPlayer]--
                     bug: orginal statement removed (missing).
            e.  Changed the boundary condition used for placing non-treasure revealed cards to the discard pile.
	        original: while(z-1>=0)
		     bug: while(z-1>0)

    2.  Smithy
        Bugs Introduced:
            a.  Changed the boundary condition used for drawing cards
	        original: for(i=0; i<3; i++)
	             bug: for(i=0; i<=3; i++)
            b.  Changed the "trashed" flag used during discard
                original: discardCard(handPos, currentPlayer, state, 0)
                     bug: discardCard(handPos, currentPlayer, state, 1)
                  				
    3.  Remodel
        Bugs Introduced:
            a.  Changed the store card that will be trashed
		original: j = state->hand[currentPlayer][choice1]
                     bug: j = state->hand[currentPlayer][choice2]

    4.  Mine
        Bugs Introduced:
            a.  Selected treasure card is not trashed
                original: discardCard(i, currentPlayer, state, 0)
                     bug: It is believe the original is a bug. The 0 should be a 1.

    5.  Village
	Bugs Introduced:
            a.  Changed number of additional actions awarded 
		original: state->numActions = state->numActions + 2;
		     bug: state->numActions = state->numActions + 1;
            b.  Changed position of card discarded from the hand  
		original: discardCard(handPos, currentPlayer, state, 0)
		     bug: discardCard(1, currentPlayer, state, 0)
						 
