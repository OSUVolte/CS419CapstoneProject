#include "dominion.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



int main()
{
    const char* funcName = "playAdventurer()";
    struct gameState* game = newGame();
    int* cardsInPlay = kingdomCards(adventurer, baron, smithy, mine, remodel, feast, steward, village, salvager, treasure_map);

    if(initializeGame(2, cardsInPlay, time(NULL), game) == -1)
    {
        printf("Couldn't intialize game!\n");
        exit(0);
    }

    int thisPlayer = whoseTurn(game);
    int otherPlayer = whoseTurn(game)^1;

    // Put an adventurer card in the player's hand
    game->hand[thisPlayer][game->handCount[thisPlayer]] = adventurer;

    printf("**************Starting test on method: %s**************\n\n", funcName);
    // Initial Test to see if there are unexpected changes to the game
    struct gameState* initialState = malloc(sizeof(struct gameState));
    memcpy(initialState, game, sizeof(struct gameState));

    playAdventurer(thisPlayer, game);

    /* Begin testing for unexpected changes in game state */

    if( initialState->numPlayers != game->numPlayers )
        printf("Error -%s changed the number of players!\n", funcName);

    int i;        // There are 26 possible cards, make sure the same are still in play
    for(i=0; i<=26; i++)
    {
        if( initialState->supplyCount[i] != game->supplyCount[i] )
                printf("Error -%s changed the number of kingdom cards!\n", funcName);
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


    if( game->handCount[thisPlayer] != initialState->handCount[thisPlayer] + 1 )    // Draw 2, put adventurer in playedCards, so only 1 total gained
    {
        if( game->handCount[thisPlayer] == initialState->handCount[thisPlayer])
            printf("Error -%s did NOT change the number of cards in this player's hand!\n", funcName);
        else
            printf("Error -%s (incorrectly) changed the number of cards in this player's hand!\n", funcName);
    }
        // Toggle the bit to check for the other player's hand
    if( initialState->handCount[otherPlayer] != game->handCount[otherPlayer])
        printf("Error -%s changed the number of cards in the other player's hand!\n", funcName);

    for(i=0; i< initialState->handCount[thisPlayer] - 1; i++) // Only up to handCount -1 because of the adventurer that was played from position handCount
    {
        if( initialState->hand[thisPlayer][i] != game->hand[thisPlayer][i])
            printf("Error -%s changed the cards in this player's hand!\n(If turn isn't changed)\n", funcName);
    }
    for(i=0; i<game->handCount[otherPlayer]; i++)
    {
        if( initialState->hand[otherPlayer][i] != game->hand[otherPlayer][i])
            printf("Error -%s changed the cards in the other player's hand!\n(If turn isn't changed)\n", funcName);
    }

    // Complicated, but basically the sum of the discard and deck (in case a shuffle was necessary) should be two less after playing the card
    if(game->deckCount[thisPlayer] + game->discardCount[thisPlayer] != initialState->deckCount[thisPlayer] + initialState->discardCount[thisPlayer] - 2)
    {
        if(game->deckCount[thisPlayer] + game->discardCount[thisPlayer] == initialState->deckCount[thisPlayer] + initialState->discardCount[thisPlayer])
            printf("Error -%s did NOT change the total of the \"deck plus discard\" count for this player!\n", funcName);
        else
            printf("Error -%s (incorrectly) changed the total of the \"deck plus discard\" count for this player!\n", funcName);
    }

    if(initialState->deckCount[otherPlayer] != game->deckCount[otherPlayer])
        printf("Error -%s changed the deck count for the other player!\n", funcName);

    // Can't make these following tests simple like this for thisPlayer because of the shuffling, taking two treasures out, discarding
    for(i=0; i<game->deckCount[otherPlayer]; i++)
    {
        if(initialState->deck[otherPlayer][i] != game->deck[otherPlayer][i])
            printf("Error -%s changed the contents of the other player's deck!\n", funcName);
    }

    if(initialState->discardCount[otherPlayer] != game->discardCount[otherPlayer])
        printf("Error -%s changed the count of the other player's discard pile!\n", funcName);

    for(i=0; i<game->discardCount[otherPlayer]; i++)
    {
        if(initialState->discard[otherPlayer][i] != game->discard[otherPlayer][i])
            printf("Error -%s changed the contents of the other player's discard!\n", funcName);
    }

    if(initialState->playedCardCount != game->playedCardCount + 1)
    {
        if(initialState->playedCardCount == game->playedCardCount)
            printf("Error -%s did NOT change the count of played cards!\n", funcName);
        else
            printf("Error -%s incorrectly changed the count of played cards!\n", funcName);
    }

    for(i=0; i<game->playedCardCount; i++)
    {
        if(initialState->playedCards[i] != game->playedCards[i])
            printf("Error -%s changed the cards in the \"Played Cards\" stack!\n", funcName);
    }

    /* End testing for unexpected changes in game state */

    // Get back to the initial game state, last card in hand is adventurer
    memcpy(initialState, game, sizeof(struct gameState));

    // Some structured tests to see if the shuffling behavior works
    game->deck[thisPlayer][game->deckCount[thisPlayer]-1] = gold;
    game->deck[thisPlayer][game->deckCount[thisPlayer]-2] = gold;
    playAdventurer(thisPlayer, game);
    if(game->deckCount[thisPlayer] != initialState->deckCount[thisPlayer] - 2)
        printf("Error -%s did not correctly change the deck count when the top two cards were treasure!\n", funcName);
    if(game->hand[thisPlayer][game->handCount[thisPlayer]-1] != gold ||
       game->hand[thisPlayer][game->handCount[thisPlayer]-2] != gold)
       printf("Error -%s did not put the two drawn treasure cards at the end of the player's hand!\n", funcName);
    if(game->discardCount[thisPlayer] != initialState->discardCount[thisPlayer])
        printf("Error -%s changed the discard count when the treasures were found in the deck!\n", funcName);

    for(i=0; i<game->deckCount[thisPlayer]-1; i++)
        game->deck[thisPlayer][i] = estate;
    game->deck[thisPlayer][game->deckCount[thisPlayer]-1] = gold;                   // Only one treasure in deck
    game->discard[thisPlayer][game->discardCount[thisPlayer]] = gold;               // One in discard
    game->discardCount[thisPlayer]++;
    memcpy(initialState, game, sizeof(struct gameState));
    playAdventurer(thisPlayer, game);
    if(game->deckCount[thisPlayer] + game->discardCount[thisPlayer] != initialState->deckCount[thisPlayer] + initialState->discardCount[thisPlayer] - 2)
    {
       if(game->deckCount[thisPlayer] + game->discardCount[thisPlayer] == initialState->deckCount[thisPlayer] + initialState->discardCount[thisPlayer])
            printf("Error -%s did NOT change the total of the \"deck plus discard\" count for this player when testing one treasure in deck, one in discard!\n", funcName);
        else
            printf("Error -%s (incorrectly) changed the total of the \"deck plus discard\" count for this player when testing one treasure in deck, one in discard!\n", funcName);
    }

    for(i=0; i<game->deckCount[thisPlayer]; i++)
        game->deck[thisPlayer][i] = estate;                             // No treasure in deck
    for(i=0; i<5; i++)
    {
        game->discard[thisPlayer][game->discardCount[thisPlayer]] = gold;   // Five in discard
        game->discardCount[thisPlayer]++;
    }
    memcpy(initialState, game, sizeof(struct gameState));

    playAdventurer(thisPlayer, game);
    if(game->deckCount[thisPlayer] + game->discardCount[thisPlayer] != initialState->deckCount[thisPlayer] + initialState->discardCount[thisPlayer] - 2)
    {
       if(game->deckCount[thisPlayer] + game->discardCount[thisPlayer] == initialState->deckCount[thisPlayer] + initialState->discardCount[thisPlayer])
            printf("Error -%s did NOT change the total of the \"deck plus discard\" count for this player when testing treasures in discard!\n", funcName);
        else
            printf("Error -%s (incorrectly) changed the total of the \"deck plus discard\" count for this player when testing treasures in discard!\n", funcName);
    }

    free(initialState);
    free(game);
    printf("\n\n********** End of test reached for function %s. Any errors found are shown above.**********\n", funcName);
    return 0;
}
