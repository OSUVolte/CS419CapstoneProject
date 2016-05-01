#include "dominion.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



int main()
{
    const char* funcName = "scoreFor()";
    struct gameState* game = newGame();
    int* cardsInPlay = kingdomCards(adventurer, baron, smithy, mine, remodel, feast, steward, village, salvager, treasure_map);

    if(initializeGame(2, cardsInPlay, time(NULL), game) == -1)
    {
        printf("Couldn't intialize game!\n");
        exit(0);
    }

    int thisPlayer = whoseTurn(game);
    int otherPlayer = whoseTurn(game)^1;

    printf("**************Starting test on method: %s**************\n\n", funcName);
    // Initial Test to see if there are unexpected changes to the game
    struct gameState* initialState = malloc(sizeof(struct gameState));
    memcpy(initialState, game, sizeof(struct gameState));

    // Each player starts with three estate cards, so their score should be 3
    if( scoreFor(thisPlayer, game) != 3)
        printf("Error -%s shows this player's initial score is not 3!\n", funcName);

    /* Begin testing for unexpected changes in game state */
    if( initialState->numPlayers != game->numPlayers )
        printf("Error -%s changed the number of players!\n", funcName);

    int i;        // There are 26 possible cards, make sure the same are still in play
    for(i=0; i<=26; i++)
    {
        if( initialState->supplyCount[i] != game->supplyCount[i] )
        {
            if(i != adventurer)
                printf("Error -%s changed the number of other kingdom cards!\n", funcName);
        }
    }
    for(i=0; i<=26; i++)
    {
        if(initialState->embargoTokens[i] != game->embargoTokens[i])
            printf("Error -%s changed the Embargo Tokens in play!\n", funcName);
    }
    if( initialState->outpostPlayed != game->outpostPlayed)
        printf("Error -%s changed the \"Outpost Played\" status!\n", funcName);
    if( initialState->outpostTurn != game->outpostTurn)
        printf("Error -%s changed the \"Outpost Turn\" status!\n", funcName);
    if( initialState->whoseTurn != game->whoseTurn)
        printf("Error -%s changed the whose turn it is!\n", funcName);
    if( initialState->phase != game->phase)
        printf("Error -%s changed the game phase!\n", funcName);
    if( initialState->numActions != game->numActions)
        printf("Error -%s changed the number of actions for this turn!\n", funcName);
    if( initialState->coins != game->coins)
        printf("Error -%s changed the \"coins\" variable!\n", funcName);
    if( initialState->numBuys != game->numBuys)
        printf("Error -%s changed the number of Buy phases available!\n", funcName);
    if( initialState->handCount[thisPlayer] != game->handCount[thisPlayer])
        printf("Error -%s changed the number of cards in this player's hand!\n", funcName);
        // Toggle the bit to check for the other player's hand
    if( initialState->handCount[otherPlayer] != game->handCount[otherPlayer])
        printf("Error -%s changed the number of cards in the other player's hand!\n", funcName);

    for(i=0; i< game->handCount[thisPlayer]; i++)
    {
        if( initialState->hand[thisPlayer][i] != game->hand[thisPlayer][i])
            printf("Error -%s changed the cards in this player's hand!\n(If turn isn't changed)\n", funcName);
    }
    for(i=0; i<game->handCount[otherPlayer]; i++)
    {
        if( initialState->hand[otherPlayer][i] != game->hand[otherPlayer][i])
            printf("Error -%s changed the cards in the other player's hand!\n(If turn isn't changed)\n", funcName);
    }

    if(initialState->deckCount[thisPlayer] != game->deckCount[thisPlayer])
        printf("Error -%s changed the deck count for this player!\n", funcName);
    if(initialState->deckCount[otherPlayer] != game->deckCount[otherPlayer])
        printf("Error -%s changed the deck count for the other player!\n", funcName);


    for(i=0; i<game->deckCount[thisPlayer]; i++)
    {
        if(initialState->deck[thisPlayer][i] != game->deck[thisPlayer][i])
            printf("Error -%s changed the contents of this player's deck!\n", funcName);
    }
    for(i=0; i<game->deckCount[otherPlayer]; i++)
    {
        if(initialState->deck[otherPlayer][i] != game->deck[otherPlayer][i])
            printf("Error -%s changed the contents of the other player's deck!\n", funcName);
    }

    if(game->discardCount[thisPlayer] != initialState->discardCount[thisPlayer])
        printf("Error -%s changed the count for this player's discard pile!\n", funcName);
    if(initialState->discardCount[otherPlayer] != game->discardCount[otherPlayer])
        printf("Error -%s changed the count of the other player's discard pile!\n", funcName);


    for(i=0; i<initialState->discardCount[thisPlayer]; i++)
    {
        if(initialState->discard[thisPlayer][i] != game->discard[thisPlayer][i])
            printf("Error -%s changed the contents of this player's discard!\n", funcName);
    }
    for(i=0; i<game->discardCount[otherPlayer]; i++)
    {
        if(initialState->discard[otherPlayer][i] != game->discard[otherPlayer][i])
            printf("Error -%s changed the contents of the other player's discard!\n", funcName);
    }

    if(initialState->playedCardCount != game->playedCardCount)
        printf("Error -%s changed the count of played cards!\n", funcName);

    for(i=0; i<game->playedCardCount; i++)
    {
        if(initialState->playedCards[i] != game->playedCards[i])
            printf("Error -%s changed the cards in the \"Played Cards\" stack!\n", funcName);
    }

    /* End testing for unexpected changes in game state */

    // Testing for scores in the cards in hand.  Set all cards to copper and
    // record the score to compare against.
    for(i=0; i<5; i++)
        game->hand[thisPlayer][i] = copper;
    int previousScore = scoreFor(thisPlayer, game);
    game->hand[thisPlayer][0] = curse;
    if( scoreFor(thisPlayer, game) != previousScore - 1 )
        printf("Error -%s didn't properly subtract for a curse card in hand!\n", funcName);

    previousScore = scoreFor(thisPlayer, game);
    game->hand[thisPlayer][1] = estate;
    if( scoreFor(thisPlayer, game) != previousScore + 1 )
        printf("Error -%s didn't properly add for an estate card in hand!\n", funcName);

    previousScore = scoreFor(thisPlayer, game);
    game->hand[thisPlayer][2] = duchy;
    if( scoreFor(thisPlayer, game) != previousScore + 3 )
        printf("Error -%s didn't properly add for a duchy card in hand!\n", funcName);

    previousScore = scoreFor(thisPlayer, game);
    game->hand[thisPlayer][3] = province;
    if( scoreFor(thisPlayer, game) != previousScore + 6 )
        printf("Error -%s didn't properly add for a province card!\n", funcName);

    previousScore = scoreFor(thisPlayer, game);
    game->hand[thisPlayer][4] = great_hall;
    if( scoreFor(thisPlayer, game) != previousScore + 1 )
        printf("Error -%s didn't properly add for a duchy card in hand!\n", funcName);

    // Reset to score 0 for hand
    for(i=0; i<game->handCount[thisPlayer]; i++)
        game->hand[thisPlayer][i] = copper;
    previousScore = scoreFor(thisPlayer, game);

    //Should have 10 cards (none gained or trashed), so gardens should add 1
    game->hand[thisPlayer][0] = gardens;
    if( scoreFor(thisPlayer, game) != previousScore + 1 )
        printf("Error -%s didn't properly add 1 to score for a gardens card in hand!\n", funcName);

    // Trash a copper from the hand and gardens should add none
    previousScore = scoreFor(thisPlayer, game);
    game->hand[thisPlayer][game->handCount[thisPlayer]] = -1;
    game->handCount[thisPlayer]--;

    if( scoreFor(thisPlayer, game) != previousScore - 1)
        printf("Error -%s didn't properly add 0 to score for a gardens card in hand!\n", funcName);

    // Add it back for ease of testing (even 10 cards)
    game->hand[thisPlayer][game->handCount[thisPlayer]] = copper;
    game->handCount[thisPlayer]++;

    // Put all 10 adventurer cards in deck
    previousScore = scoreFor(thisPlayer, game);
    for(i=0; i < 10; i++)
    {
        game->deck[thisPlayer][game->deckCount[thisPlayer]] = adventurer;
        game->deckCount[thisPlayer]++;
    }
    //Should have 20 cards now, so gardens should add 2
    if( scoreFor(thisPlayer, game) != previousScore + 2 )
        printf("Error -%s didn't properly add 2 for a gardens card in hand!\n", funcName);

    // Reset to 10 cards again
    for(i=0; i < 10 ; i++)
    {
        game->deckCount[thisPlayer]--;
        game->deck[thisPlayer][game->deckCount[thisPlayer]] = -1;
    }


    /* Repeat all tests for cards in the discard */

    memcpy(initialState, game, sizeof(struct gameState));

    // Set up to only have 10 cards by removing one from the deck count and adding a gardens to the discard
    game->deck[thisPlayer][game->deckCount[thisPlayer]] = -1;
    game->deckCount[thisPlayer]--;

    // Reset to score 0 for hand
    for(i=0; i<game->handCount[thisPlayer]; i++)
        game->hand[thisPlayer][i] = copper;
    previousScore = scoreFor(thisPlayer, game);

    //Should have 10 cards so gardens should add 1
    game->discard[thisPlayer][0] = gardens;
    game->discardCount[thisPlayer]++;
    if( scoreFor(thisPlayer, game) != previousScore + 1 )
        printf("Error -%s didn't properly add 1 to score for a gardens card in discard!\n", funcName);

    // Trash a copper from the hand and gardens should add none
    previousScore = scoreFor(thisPlayer, game);
    game->hand[thisPlayer][game->handCount[thisPlayer]] = -1;
    game->handCount[thisPlayer]--;

    if( scoreFor(thisPlayer, game) != previousScore - 1)
        printf("Error -%s didn't properly add 0 to score for a gardens card in discard!\n", funcName);

    // Add it back for ease of testing (even 10 cards)
    game->hand[thisPlayer][game->handCount[thisPlayer]] = copper;
    game->handCount[thisPlayer]++;

    // Put all 10 adventurer cards in deck
    previousScore = scoreFor(thisPlayer, game);
    for(i=0; i < 10; i++)
    {
        game->deck[thisPlayer][game->deckCount[thisPlayer]] = adventurer;
        game->deckCount[thisPlayer]++;
    }

    //Should have 20 cards now, so gardens should add 2
    if( scoreFor(thisPlayer, game) != previousScore + 2 )
        printf("Error -%s didn't properly add 2 for a gardens card in discard!\n", funcName);

    // Done testing gardens, on to the simpler tests
    previousScore = scoreFor(thisPlayer, game);
    game->discard[thisPlayer][0] = curse;
    game->discardCount[thisPlayer]++;
    if( scoreFor(thisPlayer, game) != previousScore - 1 )
        printf("Error -%s didn't properly subtract for a curse card in discard!\n", funcName);

    previousScore = scoreFor(thisPlayer, game);
    game->discard[thisPlayer][1] = estate;
    game->discardCount[thisPlayer]++;
    if( scoreFor(thisPlayer, game) != previousScore + 1 )
        printf("Error -%s didn't properly add for an estate card in discard!\n", funcName);

    previousScore = scoreFor(thisPlayer, game);
    game->discard[thisPlayer][2] = duchy;
    game->discardCount[thisPlayer]++;
    if( scoreFor(thisPlayer, game) != previousScore + 3 )
        printf("Error -%s didn't properly add for a duchy card in discard!\n", funcName);

    previousScore = scoreFor(thisPlayer, game);
    game->discard[thisPlayer][3] = province;
    game->discardCount[thisPlayer]++;
    if( scoreFor(thisPlayer, game) != previousScore + 6 )
        printf("Error -%s didn't properly add for a province card in discard!\n", funcName);

    previousScore = scoreFor(thisPlayer, game);
    game->discard[thisPlayer][4] = great_hall;
    game->discardCount[thisPlayer]++;
    if( scoreFor(thisPlayer, game) != previousScore + 1 )
        printf("Error -%s didn't properly add for a great_hall card in discard!\n", funcName);

    // We added cards to the discard and removed from deck, so reset state to the initial state
    free(game);
    game = initialState;
    initialState = NULL;

    /* Repeat all tests for cards in the deck */

    game->deck[thisPlayer][game->deckCount[thisPlayer]] = copper; // So when we put a gardens in this position we don't remove an estate

    // Reset to score 0 for hand
    for(i=0; i<game->handCount[thisPlayer]; i++)
        game->hand[thisPlayer][i] = copper;
    previousScore = scoreFor(thisPlayer, game);

    //Should have 10 cards so gardens should add 1
    game->deck[thisPlayer][game->deckCount[thisPlayer]] = gardens;
    if( scoreFor(thisPlayer, game) != previousScore + 1 )
        printf("Error -%s didn't properly add 1 to score for a gardens card in deck!\n", funcName);

    // Trash a copper from the hand and gardens should add none
    previousScore = scoreFor(thisPlayer, game);
    game->hand[thisPlayer][game->handCount[thisPlayer]] = -1;
    game->handCount[thisPlayer]--;

    if( scoreFor(thisPlayer, game) != previousScore -1 )
        printf("Error -%s didn't properly add 0 to score for a gardens card in deck!\n", funcName);

    // Add it back for ease of testing (even 10 cards)
    game->hand[thisPlayer][game->handCount[thisPlayer]] = copper;
    game->handCount[thisPlayer]++;

    // Put all 10 adventurer cards in deck
    previousScore = scoreFor(thisPlayer, game);
    for(i=0; i < 10; i++)
    {
        game->deck[thisPlayer][game->deckCount[thisPlayer]] = adventurer;
        game->deckCount[thisPlayer]++;
    }

    //Should have 20 cards now, so gardens should add 2
    if( scoreFor(thisPlayer, game) != previousScore + 2 )
        printf("Error -%s didn't properly add 2 for a gardens card in deck!\n", funcName);

    // On to the other victory cards...
    previousScore = scoreFor(thisPlayer, game);
    game->deck[thisPlayer][game->deckCount[thisPlayer]] = curse;
    game->deckCount[thisPlayer]++;
    if( scoreFor(thisPlayer, game) != previousScore - 1 )
        printf("Error -%s didn't properly subtract for a curse card in deck!\n", funcName);

    previousScore = scoreFor(thisPlayer, game);
    game->deck[thisPlayer][game->deckCount[thisPlayer]] = estate;
    game->deckCount[thisPlayer]++;
    if( scoreFor(thisPlayer, game) != previousScore + 1 )
        printf("Error -%s didn't properly add for an estate card in deck!\n", funcName);

    previousScore = scoreFor(thisPlayer, game);
    game->deck[thisPlayer][game->deckCount[thisPlayer]] = duchy;
    game->deckCount[thisPlayer]++;
    if( scoreFor(thisPlayer, game) != previousScore + 3 )
        printf("Error -%s didn't properly add for a duchy card in deck!\n", funcName);

    previousScore = scoreFor(thisPlayer, game);
    game->deck[thisPlayer][game->deckCount[thisPlayer]] = province;
    game->deckCount[thisPlayer]++;
    if( scoreFor(thisPlayer, game) != previousScore + 6 )
        printf("Error -%s didn't properly add for a province card in deck!\n", funcName);

    previousScore = scoreFor(thisPlayer, game);
    game->deck[thisPlayer][game->deckCount[thisPlayer]] = great_hall;
    game->deckCount[thisPlayer]++;
    if( scoreFor(thisPlayer, game) != previousScore + 1 )
        printf("Error -%s didn't properly add for a great_hall card in deck!\n", funcName);






    free(initialState);
    free(game);
    printf("\n\n********** End of test reached for function %s. Any errors found are shown above.**********\n", funcName);
    return 0;
}
