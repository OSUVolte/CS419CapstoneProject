#ifndef _TESTHELPERS_H
#define _TESTHELPERS_H

/*******************************************************************************
** Program Filename: testhelpers.h
** Author: Jason Loomis
** Date: 5/8/16
** Description: CS 362, Assignment 4
**		Header for helper library for testing Dominion game.
**		Contains functions to assess game/player state, card counts, etc.
*******************************************************************************/

#include "dominion.h"

/* 
 * configure the level of verbosity of the output:
 * 0 = no output
 * 1 = summary output
 * 2 = all test results
 */
#define OUTPUTLEVEL 2

#define FALSE 0
#define TRUE 1

/* stringify preprocessor variables, from: http://stackoverflow.com/questions/2653214/stringification-of-a-macro-value */
#define xstr(a) str(a)
#define str(a) #a

/* random seed to use for test game initialization */
#define SEED 500

/* player initial hand size */
#define HANDCOUNT 5

/* A standard set of kingdom cards, the first 10 defined in cardEffect() */
extern int Kingdom[];

/*******************************************************************************
** Function: rand32
** Description: bitwise combine multiple 16-bit random values into a single
**		positive 32-bit random integer
** Parameters: None
** Pre-Conditions:
**		srand() has been called to initialize the random number generator
** Post-Conditions: returns a random positive 32-bit integer value
*******************************************************************************/
int rand32();

/*******************************************************************************
** Function: randU32
** Description: bitwise combine multiple 16-bit random values into a single
**		32-bit random unsigned integer
** Parameters: None
** Pre-Conditions:
**		srand() has been called to initialize the random number generator
** Post-Conditions: returns a random 32-bit unsigned integer value
*******************************************************************************/
unsigned int randU32();

/*******************************************************************************
** Function: chooseRandomCard
** Description: choose a card randomly from among the kingdom cards, treasure,
**		victory, or curse
** Parameters:
**		kingdom: pointer to array of kingdom cards
** Pre-Conditions:
**		srand() has been called to initialize the random number generator;
**		kingdom points to an array of 10 integers, all of which are valid
**			card types from the CARD enumeration
** Post-Conditions: the chosen random card type is returned
*******************************************************************************/
int chooseRandomCard(int* kingdom);

/*******************************************************************************
** Function: initCounts
** Description: initialize a card counts array
** Parameters:
**		counts: pointer to a card counts array
** Pre-Conditions: counts points to a valid array of (treasure_map + 1) ints
** Post-Conditions: counts[] is initialized to all zeroes.
*******************************************************************************/
void initCounts(int* counts);

/*******************************************************************************
** Function: copyGameState
** Description: copy a gameState struct.
** Parameters:
**		dest: pointer to a gameState struct to copy TO
**		src: pointer to a gameState struct to copy FROM
** Pre-Conditions: None
** Post-Conditions: src gameState is copied to dest gameState
*******************************************************************************/
void copyGameState(struct gameState* dest, struct gameState* src);

/*******************************************************************************
** Function: gameStateChanged
** Description: perform a byte for byte comparison of two gameStates
** Parameters:
**		a: pointer to a gameState struct
**		b: pointer to a gameState struct
** Pre-Conditions: pointers point to valid gameState structs
** Post-Conditions: returns FALSE if bytes are equal, otherwise TRUE
*******************************************************************************/
int gameStateChanged(struct gameState* a, struct gameState* b);

/*******************************************************************************
** Function: isValidCardType
** Description: check if a card type value is a value from the CARD enumeration.
** Parameters:
**		card: a card type value
** Pre-Conditions: None
** Post-Conditions: returns TRUE if the value is within the CARD enumeration,
**		otherwise FALSE
*******************************************************************************/
int isValidCardType(int card);

/*******************************************************************************
** Function: deltaPlayerHandCount
** Description: determine change (after - before) in cards in player's hand
** Parameters:
**		before: pointer to a previous gameState struct
**		after: pointer to a subsequent gameState struct
**		player: index of the player to check
** Pre-Conditions: before and after are valid pointers to gameState structs,
**		0 <= player < MAX_PLAYERS
** Post-Conditions: returns the difference between the player's handCount
**		in the after-state vs. the before-state
*******************************************************************************/
int deltaPlayerHandCount(struct gameState* before, struct gameState* after, int player);

/*******************************************************************************
** Function: deltaPlayerDeckCount
** Description: determine change (after - before) in cards in player's deck
** Parameters:
**		before: pointer to a previous gameState struct
**		after: pointer to a subsequent gameState struct
**		player: index of the player to check
** Pre-Conditions: before and after are valid pointers to gameState structs,
**		0 <= player < MAX_PLAYERS
** Post-Conditions: returns the difference between the player's deckCount
**		in the after-state vs. the before-state
*******************************************************************************/
int deltaPlayerDeckCount(struct gameState* before, struct gameState* after, int player);

/*******************************************************************************
** Function: deltaPlayeriscardCount
** Description: determine change (after - before) in cards in player's discard
** Parameters:
**		before: pointer to a previous gameState struct
**		after: pointer to a subsequent gameState struct
**		player: index of the player to check
** Pre-Conditions: before and after are valid pointers to gameState structs,
**		0 <= player < MAX_PLAYERS
** Post-Conditions: returns the difference between the player's discardCount
**		in the after-state vs. the before-state
*******************************************************************************/
int deltaPlayerDiscardCount(struct gameState* before, struct gameState* after, int player);

/*******************************************************************************
** Function: deltaPlayerCardCount
** Description: determine change (after - before) in cards in player's
**		hand + deck + discard pile, this is the number of cards  the player
**		has acquired (or lost) from outside his deck.
** Parameters:
**		before: pointer to a previous gameState struct
**		after: pointer to a subsequent gameState struct
**		player: index of the player to check
** Pre-Conditions: before and after are valid pointers to gameState structs,
**		0 <= player < MAX_PLAYERS
** Post-Conditions: returns the difference between the player's
**		handCount + deckCount + discardCount in the after-state vs.
**		the before-state
*******************************************************************************/
int deltaPlayerCardCount(struct gameState* before, struct gameState* after, int player);

/*******************************************************************************
** Function: playerCardStateChanged
** Description: determine whether a player's state has changed by examining
**		the player's card piles.
** Parameters:
**		before: pointer to a previous gameState struct
**		after: pointer to a subsequent gameState struct
**		player: index of the player to check
** Pre-Conditions: before and after are valid pointers to gameState structs,
**		0 <= player < MAX_PLAYERS
** Post-Conditions: returns TRUE if the state has changed, otherwise FALSE
** NOTE: trashed cards "disappear" from the game, so there is not trash pile
**		to be checked.
*******************************************************************************/
int playerCardStateChanged(struct gameState* before, struct gameState* after, int player);

/*******************************************************************************
** Function: deltaPlayedCardCount
** Description: determine change (after - before) played cards
** Parameters:
**		before: pointer to a previous gameState struct
**		after: pointer to a subsequent gameState struct
** Pre-Conditions: before and after are valid pointers to gameState structs
** Post-Conditions: returns the difference between the playedCardCount
**		in the after-state vs. the before-state
*******************************************************************************/
int deltaPlayedCardCount(struct gameState* before, struct gameState* after);

/*******************************************************************************
** Function: deltaSupplyCount
** Description: determine change (after - before) the supply card piles.
** Parameters:
**		before: pointer to a previous gameState struct
**		after: pointer to a subsequent gameState struct
** Pre-Conditions: before and after are valid pointers to gameState structs,
**		card is a valid type from the CARD enumeration
** Post-Conditions: returns the difference between supply card pile
**		in the after-state vs. the before-state
*******************************************************************************/
int deltaSupplyCount(struct gameState* before, struct gameState* after, int card);

/*******************************************************************************
** Function: curseCardStateChanged
** Description: determine whether the treasure card supply has changed.
** Parameters:
**		before: pointer to a previous gameState struct
**		after: pointer to a subsequent gameState struct
** Pre-Conditions: before and after are valid pointers to gameState structs
** Post-Conditions: returns TRUE if the state has changed, otherwise FALSE
*******************************************************************************/
int curseCardStateChanged(struct gameState* before, struct gameState* after);

/*******************************************************************************
** Function: victoryCardStateChanged
** Description: determine whether the treasure card supply has changed.
** Parameters:
**		before: pointer to a previous gameState struct
**		after: pointer to a subsequent gameState struct
** Pre-Conditions: before and after are valid pointers to gameState structs
** Post-Conditions: returns TRUE if the state has changed, otherwise FALSE
*******************************************************************************/
int victoryCardStateChanged(struct gameState* before, struct gameState* after);

/*******************************************************************************
** Function: treasureCardStateChanged
** Description: determine whether the treasure card supply has changed.
** Parameters:
**		before: pointer to a previous gameState struct
**		after: pointer to a subsequent gameState struct
** Pre-Conditions: before and after are valid pointers to gameState structs
** Post-Conditions: returns TRUE if the state has changed, otherwise FALSE
*******************************************************************************/
int treasureCardStateChanged(struct gameState* before, struct gameState* after);

/*******************************************************************************
** Function: kingdomCardStateChanged
** Description: determine whether the kingdom cards supply has changed.
** Parameters:
**		before: pointer to a previous gameState struct
**		after: pointer to a subsequent gameState struct
**		kingdom: pointer to array of kingdom cards
** Pre-Conditions: before and after are valid pointers to gameState structs,
**		kingdom points to an array of 10 integers, all of which are valid
**		card types from the CARD enumeration
** Post-Conditions: returns TRUE if the state has changed, otherwise FALSE
*******************************************************************************/
int kingdomCardStateChanged(struct gameState* before, struct gameState* after, int* kingdom);

/*******************************************************************************
** Function: supplyCardStateChanged
** Description: determine whether the supply cards (Kingdom cards, curse cards,
**		treasure cards, victory cards) have changed.
** Parameters:
**		before: pointer to a previous gameState struct
**		after: pointer to a subsequent gameState struct
**		kingdom: pointer to array of kingdom cards
** Pre-Conditions: before and after are valid pointers to gameState structs,
**		kingdom points to an array of 10 integers, all of which are valid
**		card types from the CARD enumeration
** Post-Conditions: returns TRUE if the state has changed, otherwise FALSE
*******************************************************************************/
int supplyCardStateChanged(struct gameState* before, struct gameState* after, int* kingdom);

/*******************************************************************************
** Function: playerCardsOfTypeInHand
** Description: count the number of cards of 'card' type in the player's hand
** Parameters:
**		state: pointer to a gameState struct
**		player: index of the player to check
** Pre-Conditions: state is a valid pointer to a gameState struct,
**		0 <= player < MAX_PLAYERS
**		card is a valid type from the CARD enumeration
** Post-Conditions: number of cards of the specified type in the player's hand
*******************************************************************************/
int playerCardsOfTypeInHand(struct gameState* state, int player, int card);

/*******************************************************************************
** Function: playerCardsOfTypeInDeck
** Description: count the number of cards of 'card' type in the player's deck
** Parameters:
**		state: pointer to a gameState struct
**		player: index of the player to check
** Pre-Conditions: state is a valid pointer to a gameState struct,
**		0 <= player < MAX_PLAYERS
**		card is a valid type from the CARD enumeration
** Post-Conditions: number of cards of the specified type in the player's deck
*******************************************************************************/
int playerCardsOfTypeInDeck(struct gameState* state, int player, int card);

/*******************************************************************************
** Function: playerCardsOfTypeInDiscard
** Description: count the number of cards of 'card' type in the player's discard
** Parameters:
**		state: pointer to a gameState struct
**		player: index of the player to check
** Pre-Conditions: state is a valid pointer to a gameState struct,
**		0 <= player < MAX_PLAYERS
**		card is a valid type from the CARD enumeration
** Post-Conditions: number of cards of the specified type in the player's discard
*******************************************************************************/
int playerCardsOfTypeInDiscard(struct gameState* state, int player, int card);

/*******************************************************************************
** Function: playedCardsOfType
** Description: count the number of cards of 'card' type in the played cards
** Parameters:
**		state: pointer to a gameState struct
** Pre-Conditions: state is a valid pointer to a gameState struct,
**		card is a valid type from the CARD enumeration
** Post-Conditions: number of cards of the specified type in played cards
*******************************************************************************/
int playedCardsOfType(struct gameState* state, int card);

/*******************************************************************************
** Function: playedCardsStateChanged
** Description: determine whether the played cards have changed.
** Parameters:
**		before: pointer to a previous gameState struct
**		after: pointer to a subsequent gameState struct
** Pre-Conditions: before and after are valid pointers to gameState structs
** Post-Conditions: returns TRUE if the state has changed, otherwise FALSE
*******************************************************************************/
int playedCardsStateChanged(struct gameState* before, struct gameState* after);

/*******************************************************************************
** Function: deltaPlayedCardTypes
** Description: calculate change in the number of each played card type
** Parameters:
**		before: pointer to a previous gameState struct
**		after: pointer to a subsequent gameState struct
**		cardcounts: pointer to array to hold counts for each card type
** Pre-Conditions: before and after are valid pointers to a gameState structs,
**		cardcounts is a valid array of length at least (treasure_map + 1)
** Post-Conditions: each card type entry in cardcounts contains the difference
**		between the number of cards of that type that have been played in the
**		after-state vs. the before-state
*******************************************************************************/
void deltaPlayedCardTypes(struct gameState* before, struct  gameState* after, int* cardcounts);

/*******************************************************************************
** Function: countPlayedCardTypes
** Description: count the number of cards of each type of card that have been played
** Parameters:
**		state: pointer to a gameState struct
**		cardcounts: pointer to array of to hold counts for each card type
** Pre-Conditions: state is a valid pointer to a gameState struct,
**		cardcounts is a valid array of length at least (treasure_map + 1)
**		cardcounts should be initialized PRIOR to calling this function
** Post-Conditions: each card type entry in cardcounts is incremented by the
**		number of cards in the played cards
*******************************************************************************/
void countPlayedCardTypes(struct gameState* state, int* cardcounts);

/*******************************************************************************
** Function: countPlayerCardTypesInHand
** Description: count the number of cards of each type of card in player's hand
** Parameters:
**		state: pointer to a gameState struct
**		player: index of the player to check
**		cardcounts: pointer to array of to hold counts for each card type
** Pre-Conditions: state is a valid pointer to a gameState struct,
**		0 <= player < MAX_PLAYERS
**		cardcounts is a valid array of length at least (treasure_map + 1)
**		cardcounts should be initialized PRIOR to calling this function
** Post-Conditions: each card type entry in cardcounts is incremented by the
**		number of cards in the player's hand
*******************************************************************************/
void countPlayerCardTypesInHand(struct gameState* state, int player, int* cardcounts);

/*******************************************************************************
** Function: countPlayerCardTypesInDeck
** Description: count the number of cards of each type of card in player's deck
** Parameters:
**		state: pointer to a gameState struct
**		player: index of the player to check
**		cardcounts: pointer to array of to hold counts for each card type
** Pre-Conditions: state is a valid pointer to a gameState struct,
**		0 <= player < MAX_PLAYERS
**		cardcounts is a valid array of length at least (treasure_map + 1)
**		cardcounts should be initialized PRIOR to calling this function
** Post-Conditions: each card type entry in cardcounts is incremented by the
**		number of cards in the player's deck
*******************************************************************************/
void countPlayerCardTypesInDeck(struct gameState* state, int player, int* cardcounts);

/*******************************************************************************
** Function: countPlayerCardTypesInDiscard
** Description: count the number of cards of each type of card in player's discard
** Parameters:
**		state: pointer to a gameState struct
**		player: index of the player to check
**		cardcounts: pointer to array of to hold counts for each card type
** Pre-Conditions: state is a valid pointer to a gameState struct,
**		0 <= player < MAX_PLAYERS
**		cardcounts is a valid array of length at least (treasure_map + 1)
**		cardcounts should be initialized PRIOR to calling this function
** Post-Conditions: each card type entry in cardcounts is incremented by the
**		number of cards in the player's discard
*******************************************************************************/
void countPlayerCardTypesInDiscard(struct gameState* state, int player, int* cardcounts);

/*******************************************************************************
** Function: countPlayerCardTypes
** Description: count the number of cards of each type of card in player's
**		hand + deck + discard
** Parameters:
**		state: pointer to a gameState struct
**		player: index of the player to check
**		cardcounts: pointer to array of to hold counts for each card type
** Pre-Conditions: state is a valid pointer to a gameState struct,
**		0 <= player < MAX_PLAYERS
**		cardcounts is a valid array of length at least (treasure_map + 1)
**		cardcounts should be initialized PRIOR to calling this function
** Post-Conditions: each card type entry in cardcounts is incremented by the
**		number of cards in the player's hand + deck + discard
*******************************************************************************/
void countPlayerCardTypes(struct gameState* state, int player, int* cardcounts);

/*******************************************************************************
** Function: deltaPlayerCardTypesInHand
** Description: calculate change in the number of each card type in player's
**		hand
** Parameters:
**		before: pointer to a previous gameState struct
**		after: pointer to a subsequent gameState struct
**		player: index of the player to check
**		cardcounts: pointer to array to hold counts for each card type
** Pre-Conditions: before and after are valid pointers to a gameState structs,
**		0 <= player < MAX_PLAYERS
**		cardcounts is a valid array of length at least (treasure_map + 1)
** Post-Conditions: each card type entry in cardcounts contains the difference
**		between the number of cards of that type in the player's hand in the
**		after-state vs. the before-state
*******************************************************************************/
void deltaPlayerCardTypesInHand(struct gameState* before, struct  gameState* after, int player, int* cardcounts);

/*******************************************************************************
** Function: deltaPlayerCardTypesInDeck
** Description: calculate change in the number of each card type in player's
**		deck
** Parameters:
**		before: pointer to a previous gameState struct
**		after: pointer to a subsequent gameState struct
**		player: index of the player to check
**		cardcounts: pointer to array to hold counts for each card type
** Pre-Conditions: before and after are valid pointers to a gameState structs,
**		0 <= player < MAX_PLAYERS
**		cardcounts is a valid array of length at least (treasure_map + 1)
** Post-Conditions: each card type entry in cardcounts contains the difference
**		between the number of cards of that type in the player's deck in the
**		after-state vs. the before-state
*******************************************************************************/
void deltaPlayerCardTypesInDeck(struct gameState* before, struct  gameState* after, int player, int* cardcounts);

/*******************************************************************************
** Function: deltaPlayerCardTypesInDiscard
** Description: calculate change in the number of each card type in player's
**		discard
** Parameters:
**		before: pointer to a previous gameState struct
**		after: pointer to a subsequent gameState struct
**		player: index of the player to check
**		cardcounts: pointer to array to hold counts for each card type
** Pre-Conditions: before and after are valid pointers to a gameState structs,
**		0 <= player < MAX_PLAYERS
**		cardcounts is a valid array of length at least (treasure_map + 1)
** Post-Conditions: each card type entry in cardcounts contains the difference
**		between the number of cards of that type in the player's discard in the
**		after-state vs. the before-state
*******************************************************************************/
void deltaPlayerCardTypesInDiscard(struct gameState* before, struct  gameState* after, int player, int* cardcounts);

/*******************************************************************************
** Function: deltaPlayerCardTypes
** Description: calculate change in the number of each card type in player's
**		hand + deck + discard
** Parameters:
**		before: pointer to a previous gameState struct
**		after: pointer to a subsequent gameState struct
**		player: index of the player to check
**		cardcounts: pointer to array to hold counts for each card type
** Pre-Conditions: before and after are valid pointers to a gameState structs,
**		0 <= player < MAX_PLAYERS
**		cardcounts is a valid array of length at least (treasure_map + 1)
** Post-Conditions: each card type entry in cardcounts contains the difference
**		between the number of cards of that type in the player's
**		hand + deck + discard in the after-state vs. the before-state
*******************************************************************************/
void deltaPlayerCardTypes(struct gameState* before, struct  gameState* after, int player, int* cardcounts);

/*******************************************************************************
** Function: deltaSupplyCardTypes
** Description: calculate change in the number of each card type in the supply
** Parameters:
**		before: pointer to a previous gameState struct
**		after: pointer to a subsequent gameState struct
**		cardcounts: pointer to array to hold counts for each card type
** Pre-Conditions: before and after are valid pointers to a gameState structs,
**		cardcounts is a valid array of length at least (treasure_map + 1)
** Post-Conditions: each card type entry in cardcounts contains the difference
**		between the number of cards of that type in the supply in the
**		after-state vs. the before-state
*******************************************************************************/
void deltaSupplyCardTypes(struct gameState* before, struct  gameState* after, int* cardcounts);

/*******************************************************************************
** Function: checkSpecificPlayedCard
** Description: determine if exactly 1 of the specified card has been added to
**		the played cards.
** Parameters:
**		before: pointer to a previous gameState struct
**		after: pointer to a subsequent gameState struct
**		card: the type of card
** Pre-Conditions: before and after are valid pointers to a gameState structs,
**		card is a valid type from the CARD enumeration
** Post-Conditions: returns TRUE if exactly 1 of the specified card has been
**		added to the after-state when compared to the before-state
*******************************************************************************/
int checkSpecificPlayedCard(struct gameState* before, struct  gameState* after, int card);

/*******************************************************************************
** Function: updateTestResult
** Description: update test record keeping and print the test result to stdout.
** Parameters:
**		result: boolean result of the test, zero for failure, otherwise success
**		passes: pointer to record of number of tests passed
**		failures: pointer to record of number of tests failed
** Pre-Conditions: None
** Post-Conditions: if result is non-zero, passes is incremented and "passed"
**		message is printed to stdout; otherwise, failures is incremented and
**		"failed" message is printed to stdout.
*******************************************************************************/
void updateTestResult(int result, int* passes, int* failures);

/*******************************************************************************
** Function: printTestResult
** Description: print the test result (pass/fail) to stdout.
** Parameters:
**		result: boolean result of the test, zero for failure, otherwise success
** Pre-Conditions: None
** Post-Conditions: if result is non-zero, "passed" message printed to stdout;
**		otherwise, "failed" message is printed to stdout.
*******************************************************************************/
void printTestResult(int result);

/*******************************************************************************
** Function: printIndent
** Description: print the specified indentation.
** Parameters:
**		indent: the number of indentations to print
** Pre-Conditions: None
** Post-Conditions: the specified number of indentations are printed to stdout.
*******************************************************************************/
void printIndent(int indent);

/*******************************************************************************
** Function: randomizeGameState
** Description: initialize a randomized game state
** Parameters:
**		state: pointer to a gameState
**		kingdom: pointer to array of kingdom cards
**		cardToPlay: the specific card type to be played
**		handpos: the hand position at which cardToPlay is located for the
**			player specified by gameState.whoseTurn
** Pre-Conditions:
**		srand() has been called to initialize the random number generator;
**		state is a pointer to a valid gameState struct;
**		kingdom points to an array of 10 integers, all of which are valid
**			card types from the CARD enumeration
**		cardToPlay should be a valid card type from the CARD enumeration,
**			additionally, cardToPlay should be one of the kingdom card types
** Post-Conditions: initializes the gameState using the provided kingdom cards,
**		the parameters are randomized as follows:
**			numPlayers: 2 <= numPlayers <= MAX_PLAYERS
**			supplyCount: all kingdom, treasure, victory, curse cards between 0
**				and game initial counts
**			embargo: if embargo is in the kingdom, embargo tokens may be
**				may be applied to any kingdom supply piles; the number of
**				tokens applied is up to (10 - # embargoes remaining in supply)
**			outpostPlayed: if outpost is in the kingdom, with a 1/32 chance,
**				outpostPlayed flag is set to up to (10 - # outposts remaining
**				in supply)
**			outpostTurn: if the outpostPlayed flag is non-zero, outpostTurn
**				is set to a value between 0 and 2.
**			whoseTurn: a player between 0 and (numPlayers - 1) is selected
**			numActions: random value between 0 and 10 (arbitrary)
**			coins: random value between 0 and 20 (arbitrary)
**			numBuys: random value between 0 and 10 (arbitrary)
**			cards counts: a cardcount is selected, between 0 and MAX_HAND,
**				this value is then randomly divided among the deck, hand, and
**				discard for each player; for the current player (whoseTurn),
**				the distribution includes the played cards as well.
**			cards: for the count of cards specified, the deck, hand, and
**				discard are chosen randomly from among the kingdom, treasure
**				victory, and curse cards; for the current player (whoseTurn),
**				the playedCards are chosen as well.
**			cardToPlay + handpos: for the current player (whoseTurn), the
**				player's hand is specified to have at least 1 card and that
**				card is specified to be cardToPlay and is set at any valid
**				handpos for that player's hand.
*******************************************************************************/
void randomizeGameState(struct gameState* state, int* kingdom, int cardToPlay, int* handpos);

#endif