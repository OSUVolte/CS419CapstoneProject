/*
Submit a file called documentation.c (.c file because github
thinks you are using github for file storage if you use many .txt files)
that contains documentation of smithy, adventurer cards. Documentation should contain
your understanding of smithy and adventurer cards (code). It should also contain documentation
of your understanding of discardCard() and updateCoins() method.  Keep your documentation short,
though there is no upper limit. Documentation.c file should contain at least 100 words.


    case smithy:
      //+3 Cards
      for (i = 0; i < 3; i++)
	{
	  drawCard(currentPlayer, state);
	}

      //discard card from hand
      discardCard(handPos, currentPlayer, state, 0);
      return 0;

Smithy will add three cards to the users hand (using the draw card function).
It will implement this using a for loop.

After the for loop has completed, no matter what the smithy case will discard the entire hand by calling discardCard
(sending handPos, CurrentPlayer, State of game, and the "zero" flag, which it will go into the played pile instead
of the trashed pile (using an "if statement)).



*** Adventurer Card ***

Puts the cards in the discard pile from your hand until 2 treasure cards are had.

The adventure card will loop until the drawn treasure count reaches two.

It starts by checking to see if there are any cards in the hand.
If there are none it will shuffle cards in the deck.
It will then set a the card drawn to the "cardDrawn" (an enumerated integer).
It will see if the card drawn is copper, silver, or gold.
If it is a treasure card it will increment the treasure card count.
Otherwise, it will add the card to a temporary array holding cards that will be discarded.
After it hits 2 treasure counts it will discard every card from the temp hand.


*** discardCard()  ***
This will first find out if trashflag has been called.
If trash flag is called it will add the card to the "played Cards" portion.
Then, if it hasn't been set to -1 already, it will set the card to -1.
It will then call a series of if that will all reduce the number of cards in the hand of the current player.
If the discarded card is not the last card in the hand it will swap those cards in order to discard the correct card.


** updateCoins() **

Update coins sets coins to 0 and then runs a for loop through the entire hand of the player.
This shows how many coins the player has in their hand.
After it runs through the entire hand of the player it will add the bonus to the coins and the function will return.

*/




