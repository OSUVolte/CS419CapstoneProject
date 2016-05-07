/*
 * RANDOMTESTADVENTURER.C
 *
 * This tester provides 100% block, statement, and branch coverage for the Adventurer card.
 *
 * The random tester was able to catch errors related to the net number of cards gained after the
 * Adventurer card was played. The random tester was generating random deck contents, and in many cases,
 * there were not enough treasure cards in these random decks for Adventurer to function properly. Some
 * random decks resulted in the failure of sub-tests related to the number of new treasure cards gained.
 * Since this technically is not a valid input (players should start with at least two treasure cards
 * according to the rules of the game), I adjusted the random tester to ensure that this invalid input could
 * not be randomly generated.
 *
 * Additionally the random tester was building random decks by selecting a random integer in the range
 * 0...MAX_DECK. Whenever zero was selected (boundary case), a fatal divide by zero error would cause the
 * program to halt. Since zero is an invalid input, I adjusted the random tester to ensure at least two cards
 * are put into the pile.
 *
 * The biggest bug that was found deals with array offset checking. When handCount or deckCount are at zero,
 * there is no logic in the program that ensures that they are not decremented past this amount. In many
 * random test cases, adventurer calls drawCard() until handCount becomes negative, and memory that is not
 * associated with the hand is accessed. This particular failure is evident in the final test of the
 * suite, which always returns results such as;
 *
 * >> Initial hand count was 7, new hand count is -1, expected 9...FAILED.
 *
 * This invalid hand count is due to the array index bug, which allows hand counts to be decremented
 * past zero. In cases where the hand count is decremented significantly past valid bounds, seg faults occur.
 * I temporarily disabled this test because the seg faults were so frequent.
 *
 * Another common and related bug can be seen in this test:
 *
 * >> Net difference in deck treasure card supply is 3, expected 2...-1 copper, -1 silver, -1 gold...FAILED.
 *
 * This is due to the bug introduced by an earlier assignment, which fails to recognize gold cards
 * as treasure cards when Adventurer is being played. This test shows that 3 treasure cards were drawn,
 * but only two were recognized as valid treasures. This bug is part of the combinatorial input array that
 * causes the array bounds index bug listed above.
 *
 * In rare cases, the unit tests which check to ensure that the other players' decks are untouched fail.
 * I could not determine the exact inputs which cause these failures.
 *
 * RANDOMTESTCARD.C
 *
 * This random tester is built for the Great Hall card.
 *
 * The random tester was able to uncover a bug in my test oracle logic. I wrongly assumed that when Great Hall
 * called discardCard(), the newly gained card would be in the last position of the deck. In fact, the newly
 * gained card will often replace the discarded Great Hall card. Many of my tests failed because I was applying
 * this erroneous logic. Although I missed this with a small number of manual tests, the random tester
 * made it easier to detect (more chances of occurring).
 *
 * The random tester also helped to uncovered a bug related to the random insertion of a Great Hall card
 * in the player's hand. This is not a game logic bug, but rather another test library bug. In about 10% of
 * cases, the Great Hall card would inserted in an invalid position in the player's hand. This would cause
 * the test which compared supply counts to fail - another false negative.
 *
 * A third test library bug was found due to failed supply count tests. I failed to take into account
 * that the new card gained when Great Hall was played might be another Great Hall card. This assumption
 * lead to some more false negatives when it came to tallying up the number of expected Great Hall cards
 * in the player's hand.
 *
 * Another test library bug was found related to testing if the newly gained card did in fact come from
 * the player's own deck. In this test, I was only checking to see if the new card came from the deck,
 * however, in cases where the random deck had no cards in it, the discard pile became the source of
 * new cards. I adjusted the test to check the discard pile in cases where the deck was empty to start.
 *
 * After look at the coverage for functions called by the card, I noticed certain branches were not being
 * taken. For example, the drawCard branch that deals with empty decks was not taken at all, because my
 * random decks were never empty. I adjusted this random deck code to ensure this branch was covered.
 */