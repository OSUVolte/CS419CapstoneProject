/*                                    BUG  REPORT

 Functions:
    1.  updateCoins:  No bugs found ... passed all 80 test cases.
    2.  gainCard:     No bugs found ... passed all 351 test cases.
    3:  discardCard:  No bugs found ... passed all 48 test cases.
    4:  isGameOver:
             Bug1
               Status:       Real
               Description: This function failed 576 out of 3655 test cases. Upon further
                            review it was determined that all failing test cases occurred
                            when testing sea_hag and treasure_map stacks.  The follow code
                            contains the bug.

                             for (i = 0; i < 25; i++)     // Bug in upper limit
                             {
                                if (state->supplyCount[i] == 0)
	                            {
	                                j++;
	                             }
                             }

                             sea_hag and treasure_map have enum values of 25 and 26 respectively,
                             therefore the code was never checking if these stacks were
                             empty.

 Cards:
    1.  Smithy:
            Bug1
               Status:       Real
               Description:  This was a self induced bug.  On the previous week I altered
                             the for loop as illustrated and forgot that I had done it.
                                     Original:  for (i = 0; i < 3; i++)
                                       My Bug:  for (i = 0; i <= 3; i++)
                             This caused all 24 test cases for Smithy to fail. Replacing
                             Smithy with the original code resulted in all test cases
                             passing.

    2.  Adventurer:
            Bug1
                    Status:  Not Real
               Description:  Using the original code for Adventurer,  26 out of 64 test cases
                             were failing.  Upon further investigation, it was determined that
                             all failing test cases occurred when a shuffle was performed.
                             This randomness caused a difference in the deck card sequences
                             used by the "oracle" and "Adventurer". Although both decks contained
                             the same cards, this difference in card sequence oftentimes resulted
                             in different end state deckCounts and discardCounts. Both "oracle" and
                             "adventurer" where performing correctly, even though their end
                             states were different due to the shuffle.

                             It should be noted that the following lines in the Adventurer Card is
                             "dead code" since a shuffle is only performed on a non-empty deck. The
                             drawCard call a few lines below the dead code does the actual shuffle.

                                  if (state->deckCount[currentPlayer] < 1){
	                                    shuffle(currentPlayer, state);    //DOES NOTHING!.. returns -1!
	                              }

    3.  Salvager:
             Bug1
                    Status:  Real
               Description:  Using the original code for Salvager,  28 out of 52 test cases
                             were failing.  Upon further investigation, it was determined that
                             that these failures were due to two bugs in the code. Bug1 is
                             the condition statement used to "trashing" a card from the hand.

                             bug code:  if (choice1)
                                        {
	                                       state->coins = state->coins + getCost( handCard(choice1, state) );
	                                       discardCard(choice1, currentPlayer, state, 1);
	                                    }
	                         choice1 is used as an index to the player's hand for determining what
	                         card is to be trashed.  Using it as a conditional statement means that
	                         one could never trash the card and index 0.

             Bug2
                    Status:  Real
               Description:  A more serious bug was found due to multiple discardCard function calls
                             using "static" indexes to represent the location of the trash card and
                             the played Salvager card.

                              bug code:  1. int playSalvager(struct gameState *state, int choice1, int handPos)
                                         2. discardCard(choice1, currentPlayer, state, 1);
                                         3. discardCard(handPos, currentPlayer, state, 0);

                             Line 1 defines the index locations of the trash and Salvager card which unchanged
                                    during the playSalvager function.
                             Line 2 removes the trash card at index choice1 and replaces it with the top
                                    card in the deck.  If the top card in the deck happen to be the Salvager
                                    card, then handPos is no longer valid.
                             Line 3 If the position of Salvager is not equal handPos, then a problem

    4.  Village:      No bugs found ... passed all 400 test cases.

 */

