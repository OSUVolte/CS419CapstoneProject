/*
CS 362, 4-8-16, Assignment 2, Aaron Sealy

Smithy:
    Change:     The initial value of i is set to 1 instead of zero, so 2 cards will be drawn instead of 3
    Old code:   for (i = 0; i < 3; i++)
                {
                    drawCard(currentPlayer, state);
                }
	New code:   for (i = 1; i < 3; i++)
                {
                    drawCard(currentPlayer, state);
                }

Adventurer:
    Change:     Now only copper and silver, but not gold, are recognized as treasure
    Old code:   if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
                    drawntreasure++;
    New code:   if (cardDrawn == copper || cardDrawn == silver)
                    drawntreasure++;

Great Hall:
    Change:     Instead of incrementing actions, it increments and then decrements actions (i.e. no change to action)
    Old code:   state->numActions++;
    New Code:   state->numActions++;
                state->numActions--;

Remodel:
    Change:     Instead of choosing a card worth 2 coins more than the trashed card, it can now be
                    worth 4 coins more.
    Old code:   if ( (getCost(state->hand[currentPlayer][choice1]) + 2) > getCost(choice2) )
                {
                  return -1;
                }
    New Code:  if ( (getCost(state->hand[currentPlayer][choice1]) + 4) > getCost(choice2) )
                {
                  return -1;
                }

Sea hag:
    Change:     The if clause is changed so that the curse hits the current player instead of the other players
    Old code:   if (i != currentPlayer)
    New Code:   if (i = currentPlayer)
*/
