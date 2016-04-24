/******************************************************************************
** coverage1.c 
** Emily Snyder
** Spring 2016
** CS 362-400
** Discusses coverage provided by test suite.
*******************************************************************************

unittest1.c - getCost()

	getCost() should return the correct cost in coins for the card that is
	passed as a parameter. The tests compare the cost returned by the function
	to the costs given at http://wiki.dominionstrategy.com/.

  All tests pass successfully, no bugs found.	
 
  GCOV
		Function 'getCost'
		Lines executed:100.00% of 30
		Branches executed:100.00% of 28
		Taken at least once:100.00% of 28

  Since all the costs returned for all cards are tested, these tests provide
  100% coverage of the function.

unittest2.c - shuffle()

  shuffle() should only reorder the cards in the deck. 
		-	It should not affect the number of cards in any of the card piles for any 
			of the players. 
		-	It should return a value of -1 if the deck is empty when the function is 
			called. 
		- It should not change the cards that are in the deck when it shuffles.

  All tests pass successfully, no bugs found.
 
  GCOV
		Function 'shuffle'
		Lines executed:100.00% of 16
		Branches executed:100.00% of 8
		Taken at least once:100.00% of 8
		Calls executed:100.00% of 2

  The unit tests cover 100% of the shuffle() function.

unittest3.c - discardCard()

  discardCard():
    - If a card is played not trashed, the card should be added to the discard
      pile and the played card count should increase.
    - If a card is trashed, the card should not be added to the discard pile
      and the played card count should increase.
    - No other players' counts should change

	Bugs found and discussed in bug1.c

	GCOV
		Function 'discardCard'
		Lines executed:100.00% of 13
		Branches executed:100.00% of 6
		Taken at least once:100.00% of 6
		No calls
  
  The unit tests cover 100% of the discardCard() function.

unittest4.c - gameOver()

  gameOver():
		- The Province Supply pile is empty.
    - Any three Supply piles are empty. This includes all the Supply piles, not 
      just the 10 Kingdom card piles that are selected for each game. So, for 
      instance, if the Estate pile, the Curse pile, and one of the Kingdom card 
      piles is empty, the game ends.
   ** information from http://boardgamegeek.com/wiki/page/Dominion_FAQ **

  Bugs found and discussed in bug1.c

	GCOV
		Function 'isGameOver'
		Lines executed:100.00% of 10
		Branches executed:100.00% of 8
		Taken at least once:100.00% of 8
		No calls

  The unit tests cover 100% of the discardCard() function.

cardtest1.c - Smithy card
 
	From http://wiki.dominionstrategy.com/index.php/Smithy
		+3 Cards

	-	Current player's hand should add three cards, discard the smithy card,
    and remove 3 cards from their deck.
	- Played cards count should increase.
	- No other players' piles should change.

	GCOV
		Function 'smithyEffect'
		Lines executed:100.00% of 5
		Branches executed:100.00% of 2
		Taken at least once:100.00% of 2
		Calls executed:100.00% of 2
	
	The unit tests cover 100% of the smithyEffect() function.

cardtest2.c - Adventurer card

	http://wiki.dominionstrategy.com/index.php/Adventurer
	Reveal cards from your deck until you reveal 2 Treasure cards. 
	Put those Treasure cards into your hand and discard the other revealed cards.

	Current player:
		- Number of cards in deck will be decreased by the number of cards drawn
      before finding 2 treasure cards.	
		- Hand will be increased by up to 2, depending on how many treasure cards
			are found.
		- Discard pile will be increased by 1 for the adventurer card, plus 1 for
			each of the non-treasure cards drawn.
		- Cards played count will increase by one.
	Other players:
		- No changes should be made.

	GCOV
		Function 'adventurerEffect'
		Lines executed:100.00% of 16
		Branches executed:100.00% of 10
		Taken at least once:90.00% of 10
		Calls executed:100.00% of 2

cardtest3.c - Great Hall card

	http://wiki.dominionstrategy.com/index.php/Great_Hall
	When you play it, you draw a card and may play another Action.

	Current player:
		- Hand will be increased by 1, Great Hall card will be discarded, for net
			change of 0.
		- Discard will increase by 1.
		- Cards played count will increase by one.
		- Number of actions is increased by 1.
	Other players:
		- No changes should be made.

	GCOV: 100% coverage for the great_hall case

						-:  829:    case great_hall:
						-:  830:      //+1 Card
						1:  831:      drawCard(currentPlayer, state);
		call    0 returned 100%
						-:  832:      
						-:  833:      //+1 Actions
						1:  834:      state->numActions++;
						-:  835:      
						-:  836:      //discard card from hand
						1:  837:      discardCard(handPos, currentPlayer, state, 0);
		call    0 returned 100%
						1:  838:      return 0;

cardtest4.c - Council Room card

	http://wiki.dominionstrategy.com/index.php/Council_Room
	+4 Cards
	+1 Buy
	Each other player draws a card.

	Current player:
		- Hand will be increased by 4, Great Hall card will be discarded, for net
			change of 3.
		- Discard will increase by 1.
		- Cards played count will increase by one.
		- Number of buys is increased by 1.
	Other players:
		- Hand increased by 1.
		- Deck decreased by 1.

	GCOV: 100% coverage for the council_room case

						-:  670:    case council_room:
						-:  671:      //+4 Cards
						5:  672:      for (i = 0; i < 4; i++)
		branch  0 taken 80%
		branch  1 taken 20% (fallthrough)
						-:  673:      {
						4:  674:        drawCard(currentPlayer, state);
		call    0 returned 100%
						-:  675:      }
						-:  676:      
						-:  677:      //+1 Buy
						1:  678:      state->numBuys++;
						-:  679:      
						-:  680:      //Each other player draws a card
						5:  681:      for (i = 0; i < state->numPlayers; i++)
		branch  0 taken 80%
		branch  1 taken 20% (fallthrough)
						-:  682:      {
						4:  683:        if ( i != currentPlayer )
		branch  0 taken 75% (fallthrough)
		branch  1 taken 25%
						-:  684:          {
						3:  685:            drawCard(i, state);
		call    0 returned 100%
						-:  686:          }
						-:  687:      }
						-:  688:      
						-:  689:      //put played card in played card pile
						1:  690:      discardCard(handPos, currentPlayer, state, 0);
		call    0 returned 100%
						-:  691:      
						1:  692:      return 0;


--------------------------- CARD EFFECT COVERAGE ------------------------------
	Function 'cardEffect'
 		Lines executed:11.49% of 148
 		Branches executed:24.37% of 119
 		Taken at least once:7.56% of 119
 		Calls executed:12.50% of 48

