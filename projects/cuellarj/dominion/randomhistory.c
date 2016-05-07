/*
Joseph Cuellar 
CS 362 - Assignment 4

I had a lot of problems with the Adveturer Card, I had to go into dominion.c and temporarily fix the bug I created in
past assignments. I will reestablish the bug after this week. The rest is below:

Both cards were tested individually, which meant that the rest of the game had to be created randomly. 

Adventurer:

- 2 Cards needed to be available for this to work for each play
- Everything was randomly initialized. The main objective was to make sure that the decks and games states were OK at the end of it
- The hardest part of testing this card was getting enough instances where the empty decks needed to be shuffled

RESULTS:

File 'dominion.c'
Lines executed:6.80% of 559
Branches executed:4.80% of 417
Taken at least once:4.08% of 417
Calls executed:3.19% of 94
Creating 'dominion.c.gcov'

function callAdventurerCard called 1000 returned 100% blocks executed 100%
     1000:  648:int callAdventurerCard(struct gameState *state, int currentPlayer){
        -:  649:    int cardDrawn;
     1000:  650:    int drawntreasure = 0;
     1000:  651:    int z = 0;
        -:  652:    int temphand[MAX_HAND];
        -:  653:
    19882:  654:    while(drawntreasure<2){
branch  0 taken 95%
branch  1 taken 5% (fallthrough)
    17882:  655:        if (state->deckCount[currentPlayer] < 1){//if the deck is empty we need to shuffle discard and add to deck
branch  0 taken 2% (fallthrough)
branch  1 taken 98%
      360:  656:          shuffle(currentPlayer, state);
call    0 returned 100%
        -:  657:        }
    17882:  658:        drawCard(currentPlayer, state);
call    0 returned 100%
    17882:  659:        cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
    17882:  660:        if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
branch  0 taken 96% (fallthrough)
branch  1 taken 4%
branch  2 taken 96% (fallthrough)
branch  3 taken 4%
branch  4 taken 4% (fallthrough)
branch  5 taken 96%
     2000:  661:          drawntreasure++;
        -:  662:        else{
    15882:  663:          temphand[z]=cardDrawn;
    15882:  664:          state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
    15882:  665:          z++;
        -:  666:        }
        -:  667:    }
        -:  668:
    17882:  669:    while(z-1>=0){
branch  0 taken 94%
branch  1 taken 6% (fallthrough)
    15882:  670:        state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
    15882:  671:        z=z-1;
        -:  672:    }
        -:  673:
     1000:  674:    return 0;
        -:  675:  }
        -:  676:
        -:  677:

		
		
		
		
Village:

- Village is already a pretty simple card, I don't think there would be a big differrence in having many tests or few tests. 
- Either the function just works or it doesn't. There aren't many branches or prumutations for things to change compared to adventurer.


RESULTS:
File 'dominion.c'
Lines executed:23.26% of 559
Branches executed:18.23% of 417
Taken at least once:16.07% of 417
Calls executed:12.77% of 94
Creating 'dominion.c.gcov'

function callVillageCard called 1500 returned 100% blocks executed 100%
     1500:  691:int callVillageCard(int currentPlayer, struct gameState *state, int handPos){
        -:  692:     
        -:  693:     
        -:  694:     
        -:  695:      //+2 Actions
     1500:  696:      state->numActions = state->numActions + 2;
        -:  697:      
        -:  698:      //discard played card from hand
     1500:  699:      discardCard(handPos, currentPlayer, state, 0);
call    0 returned 100%
     1500:  700:      return 0;
        -:  701:}
        -:  702:
*/