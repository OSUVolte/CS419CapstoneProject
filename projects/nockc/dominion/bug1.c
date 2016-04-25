/*Results of testing Smithy:
10 tests passed (playedCardCount increasing by 1, smithy being added to played cards and not in the player’s post state hand, current player not affecting other’s game state ) and 4 tests failed
Bugs found from failed tests:
Actual handCount is 2 more than expected handCount after playing the smithy. This is due to the bug introduced in refactored Smithy which lets players draw 5 cards instead of 3. Bug found for both turns. Bug found for both turns.
Actual deckCount decreased by 5 rather than by 3 for both turns after playing the smithy. This is due to the same bug mentioned above. Bug found for both turns.
Results of testing Adventurer:
8 tests passed (deck count decreased after drawing cards, discardCount increased after discarding cards, 2 Treasure cards were added, current player not affecting other’s game state ) and 6 tests failed
Bugs found from failed tests:
Actual handCount is not more than that of previous game state. This is due to the bug introduced in refactored Adventurer which causes player to draw cards until 1 additional treasure card is drawn instead of 2. Bug found for both turns.
Actual treasure card count does not increase by 2 from previous game state to post game state after playing Adventurer. This is also due to same bug described above. Bug found for both turns.
Adventurer is still in the hand after being played, so it is not being discarded as it should. Bug found for both turns.
Results of testing Village:
14 tests passed (hand count being same in previous and post game state, deck count increasing by 1, village card being discarded, village card not remaining in hand, next card in deck put into the hand) and 2 tests failed
Bugs found from failed tests:
Actual number of actions is 1 more than expected. This is due to the bug introduced in refactored Village which gives players 3 additional actions instead of 2. Bug found for both turns. 
Results of testing Council Room:
6 tests passed (council room card discarded correctly, player’s number of buys increased by 1, council room found in discarded cards, current player not affecting other’s game state) and 8 tests failed
Bugs found from failed tests:
Actual handCount for current player is 1 more than expected. This is due to the bug introduced in refactored Council Room which gives current player an additional card draw instead of the other player which results in the current player having an extra card in their hand. Bug found for both turns.
Actual deckCount for current player is 1 less than expected. This is due to the same bug mentioned above. Bug found for both turns.
Actual handCount for other player is 1 less than expected. This is due to the same bug mentioned above. Bug found for both turns.
Actual deckCount for other play is 1 more than expected. 
s 3 additional actions instead of 2. This is due to the same bug mentioned above. Bug found for both turns.
Results of testing isGameOver:
50 tests passed (returns 1 if the supply of province becomes empty, returns 1 if the supply of three other cards becomes empty for all cards except for sea_hag or treasure_map being the empty piles, gamestate remaining unchanged throughout all tests) and 2 tests failed
Bugs found from failed tests:
Three empty pile test fails when one of the empty piles is either sea_hag (card 25) or treasure_map (card 26) because of a bug in line 402 of dominion.c, specifically: 
for (i = 0; i < 25; i++) which should be for (i = 0; i < 27; i++)
Results of testing buyCard:
All tests passed (not allowing user to buy a card when they have no buys, not allowing user to buy a card with 0 supply, allowing user to buy a available card when they have buys, gamestate remaining unchanged throughout all tests. No bugs found from failed tests.
Results of testing fullDeckCount
All tests passed ( count of cards in a player's hand, count of cards in a player's discard pile, count of cards in a player's deck, if sum of above accounts are correctly calculated). No bugs found from failed tests.
Results of testing updateCoins
All tests passed ( correctly sums up the coin values for treasure cards and bonus (1 for copper, 2 for silver, 3 for gold), correctly returns a 0 for a hand with no coins and no bonus, correctly returns bonus for a hand with no coins and a bonus). No bugs found from failed tests.
*/
