/*
 *
 * Bugs found in program:
 *
 *Cardtest1.c bugs found (SMITHY)
 * Card test 1 test Smithy Bug
 * Critical system error when under 4 cards are in hand. There is a while-loop in the smithy implementation
 * that will run forever. This is a show-stopper error.
 *
 *
 *Cardtest2.c bugs found (ADVENTURER)
 *
 * Adventurer card does *not* get discarded after hand has completed.
 * A random card (the last card) appears to be removed from hand after card has been played.
 * No cards are inserted into the hand of the person who played the adventurer card.
 * If no cards in hand the adventurer function will attempt to shuffle and cause an infinite loop.
 *
 *Cardtest3.c bugs found (SEA_HAG)
 *
 * Sea_hag had same error as adventurer card (card was not getting discarded). I fixed this to move forward.
 * Sea_hag is discarded from hand but never winds up in the discard pile.
 * Sea_hag top card is never changed. While a curse IS added to the card it is not the top card a person gets.
 *
 *Cardtest4.c bugs found (BARON)
 *
 * This was a bummer as I had tried to correctly implement this card last week.
 * Baron does not trigger a game over correctly when the last estate card is assigned and game ending condition is met
 * The testGameOVer is called but it doesn't do anything.
 *
 *
 * Unittest1.c bugs found (SHUFFLE)
 *
 * No bugs were found in shuffle test. Coverage appears good. No test show function effects other players.
 *
 *Unittest2.c bugs found (DISCARD CARD)
 *
 * Discard card incorrectly will remove a card from the game instead of putting it in the discard pile.
 * This bug is the equivalent to "trashing" all cards. Bug appears to come from "playedCards"
 * The card should go into discard pile as well as played card pile before it is removed from the hand.
 *
 *Unittest3.c bugs found (DRAW CARD)
 * No bugs were found in draw card. Coverage appears good.
 *
 * Unittest4.c bugs found (UPDATE COINS)
 *
 *  Update coins : Bug in buy card or update coins. When coins are passed with a bonus buy card and update coins
 *  do NOT do anything to them. Due to the obfuscated nature of the coding here I was not able to determine where
 *  the responsibility for diminishing coins was (likely buy-card).
 *
 *  No other bugs found.
 * */
