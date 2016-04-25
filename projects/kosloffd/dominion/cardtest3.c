#include "dominion.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



int main()
{
    const char* funcName = "cardEffect() on council_room";
    struct gameState* game = newGame();
    int* cardsInPlay = kingdomCards(adventurer, baron, smithy, mine, council_room, feast, steward, village, salvager, treasure_map);

    if(initializeGame(2, cardsInPlay, time(NULL), game) == -1)
    {
        printf("Couldn't intialize game!\n");
        exit(0);
    }

    int thisPlayer = whoseTurn(game);
    int otherPlayer = whoseTurn(game)^1;

    // Put a Smithy card in the player's hand
    game->hand[thisPlayer][game->handCount[thisPlayer]-1] = council_room;

    printf("**************Starting test on method: %s**************\n\n", funcName);
    // Initial Test to see if there are unexpected changes to the game
    struct gameState* initialState = malloc(sizeof(struct gameState));
    memcpy(initialState, game, sizeof(struct gameState));

    cardEffect(council_room, 0, 0, 0, game, game->handCount[thisPlayer]-1, 0);

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
    if( game->numBuys != initialState->numBuys + 1 )
    {
        if( game->numBuys == initialState->numBuys )
            printf("Error -%s did NOT change the number of Buy phases available!\n", funcName);
        else
            printf("Error -%s incorrectly changed the number of Buy phases available!\n", funcName);
    }

    if( game->handCount[thisPlayer] != initialState->handCount[thisPlayer] + 3 )    // Draw 4, put council_room in playedCards, so only 3 total gained
    {
        if( game->handCount[thisPlayer] == initialState->handCount[thisPlayer])
            printf("Error -%s did NOT change the number of cards in this player's hand!\n", funcName);
        else
            printf("Error -%s (incorrectly) changed the number of cards in this player's hand!\n", funcName);
    }

    if( game->handCount[otherPlayer] != initialState->handCount[otherPlayer] + 1 )
    {
        if( game->handCount[otherPlayer] == initialState->handCount[otherPlayer] )
            printf("Error -%s did NOT change the number of cards in the other player's hand!\n", funcName);
        else
            printf("Error -%s incorrectly changed the number of cards in the other player's hand!\n", funcName);
    }

    // Only check up to the position where council_room was
    for(i=0; i< initialState->handCount[thisPlayer] - 1; i++)
    {
        if( initialState->hand[thisPlayer][i] != game->hand[thisPlayer][i])
            printf("Error -%s changed the cards in this player's hand!\n(If turn isn't changed)\n", funcName);
    }
    for(i=0; i<initialState->handCount[otherPlayer]; i++)
    {
        if( initialState->hand[otherPlayer][i] != game->hand[otherPlayer][i])
            printf("Error -%s changed the cards in the other player's hand!\n(If turn isn't changed)\n", funcName);
    }

    if(game->deckCount[thisPlayer] != initialState->deckCount[thisPlayer] - 4 )
    {
        if(game->deckCount[thisPlayer] == initialState->deckCount[thisPlayer])
            printf("Error -%s did NOT change the deck count for this player!\n", funcName);
        else
            printf("Error -%s (incorrectly) changed the deck count for this player!\n", funcName);
    }

    if(game->deckCount[otherPlayer] != initialState->deckCount[otherPlayer] - 1 )
    {
        if(game->deckCount[otherPlayer] == initialState->deckCount[otherPlayer])
            printf("Error -%s did NOT change the deck count for the other player!\n", funcName);
        else
            printf("Error -%s (incorrectly) changed the deck count for the other player!\n", funcName);
    }

    // Only check up to the amount of cards in the new deck (after drawing)
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

    for(i=0; i<game->discardCount[thisPlayer]; i++)
    {
        if( initialState->discard[thisPlayer][i] != game->discard[thisPlayer][i] )
            printf("Error -%s changed the contents of this player's discard!\n", funcName);
    }
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

    for(i=0; i<initialState->playedCardCount; i++)
    {
        if(initialState->playedCards[i] != game->playedCards[i])
            printf("Error -%s changed the cards in the \"Played Cards\" stack!\n", funcName);
    }

    free(initialState);
    initialState = NULL;

    /* End testing for unexpected changes in game state */


    free(game);
    printf("\n\n********** End of test reached for function %s. Any errors found are shown above.**********\n", funcName);
    return 0;
}
