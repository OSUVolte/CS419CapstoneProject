#include "dominion.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



int main()
{
    const char* funcName = "cardEffect() of remodel";
    struct gameState* game = newGame();
    int* cardsInPlay = kingdomCards(adventurer, baron, smithy, mine, remodel, feast, steward, village, salvager, treasure_map);

    if(initializeGame(2, cardsInPlay, time(NULL), game) == -1)
    {
        printf("Couldn't intialize game!\n");
        exit(0);
    }

    int thisPlayer = whoseTurn(game);
    int otherPlayer = whoseTurn(game)^1;

    // Put a remodel card in the player's hand, will test remodel with gardens to gain a gold
    game->hand[thisPlayer][game->handCount[thisPlayer]-1] = remodel;
    game->hand[thisPlayer][game->handCount[thisPlayer]-2] = gardens;

    printf("**************Starting test on method: %s**************\n\n", funcName);
    // Initial Test to see if there are unexpected changes to the game
    struct gameState* initialState = malloc(sizeof(struct gameState));
    memcpy(initialState, game, sizeof(struct gameState));

    if(cardEffect(remodel, game->handCount[thisPlayer]-2, gold, 0, game, game->handCount[thisPlayer]-1, 0) == -1)
        printf("Error -%s returned an error code when it shouldn't! \n", funcName);

    /* Begin testing for unexpected changes in game state */

    if( initialState->numPlayers != game->numPlayers )
        printf("Error -%s changed the number of players!\n", funcName);

    int i;        // There are 26 possible cards, make sure the same are still in play
    for(i=0; i<=26; i++)
    {
        if( initialState->supplyCount[i] != game->supplyCount[i] )
        {
            if(i != gold)
                printf("Error -%s changed the number of kingdom cards!\n", funcName);
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


    if( game->handCount[thisPlayer] != initialState->handCount[thisPlayer] - 2 )
    {
        if( game->handCount[thisPlayer] == initialState->handCount[thisPlayer])
            printf("Error -%s did NOT change the number of cards in this player's hand!\n", funcName);
        else
            printf("Error -%s (incorrectly) changed the number of cards in this player's hand!\n", funcName);
    }
    if( initialState->handCount[otherPlayer] != game->handCount[otherPlayer])
        printf("Error -%s changed the number of cards in the other player's hand!\n", funcName);

    for(i=0; i< initialState->handCount[thisPlayer] -2; i++)
    {
        if( initialState->hand[thisPlayer][i] != game->hand[thisPlayer][i])
            printf("Error -%s changed the cards in this player's hand!\n(If turn isn't changed)\n", funcName);
    }
    for(i=0; i<game->handCount[otherPlayer]; i++)
    {
        if( initialState->hand[otherPlayer][i] != game->hand[otherPlayer][i])
            printf("Error -%s changed the cards in the other player's hand!\n(If turn isn't changed)\n", funcName);
    }

    if(game->deckCount[thisPlayer] != initialState->deckCount[thisPlayer] )
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

    if(game->discardCount[thisPlayer] != initialState->discardCount[thisPlayer] + 1)
    {
        if(game->discardCount[thisPlayer] == initialState->discardCount[thisPlayer] )
            printf("Error -%s did NOT change the count for this player's discard pile!\n", funcName);
        else
            printf("Error -%s incorrectly changed the count for this player's discard pile!\n", funcName);
    }

    if(initialState->discardCount[otherPlayer] != game->discardCount[otherPlayer])
        printf("Error -%s changed the count of the other player's discard pile!\n", funcName);

    for(i=0; i<game->discardCount[thisPlayer]-1; i++)
    {
        if( initialState->discard[thisPlayer][i] != game->discard[thisPlayer][i] )
            printf("Error -%s changed the contents of this player's discard!\n", funcName);
    }
    if(game->discard[thisPlayer][game->discardCount[thisPlayer]-1] != gold)
        printf("Error -%s did not put the gained card in the player's discard!\n", funcName);

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

    // Revert to original state
    memcpy(game, initialState, sizeof(struct gameState));

    if(cardEffect(remodel, game->handCount[thisPlayer]-2, province, 0, game, game->handCount[thisPlayer]-1, 0) != -1)
        printf("Error -%s did not return an error when trying to trade in for a card that cost too much!\n", funcName);

    free(initialState);
    free(game);
    printf("\n\n********** End of test reached for function %s. Any errors found are shown above.**********\n", funcName);
    return 0;
}
