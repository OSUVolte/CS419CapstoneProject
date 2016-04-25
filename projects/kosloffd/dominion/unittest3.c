#include "dominion.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



int main()
{
    const char* funcName = "buyCard()";
    struct gameState* game = newGame();
    int* cardsInPlay = kingdomCards(adventurer, baron, smithy, mine, remodel, feast, steward, village, salvager, treasure_map);

    if(initializeGame(2, cardsInPlay, time(NULL), game) == -1)
    {
        printf("Couldn't intialize game!\n");
        exit(0);
    }

    printf("**************Starting test on method: %s**************\n\n", funcName);
    // Initial Test to see if there are unexpected changes to the game
    game->coins = 6;
    game->phase = 1;
    struct gameState* initialState = malloc(sizeof(struct gameState));
    memcpy(initialState, game, sizeof(struct gameState));

    // Gain a card 'normally' (it goes into the discard pile)
    if( buyCard(adventurer, game) == -1)
        printf("Error -%s is not allowing a purchase when it should be!\n", funcName);

    /* Begin testing for unexpected changes in game state */
    int thisPlayer = whoseTurn(game);
    int otherPlayer = whoseTurn(game)^1;

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
    if( initialState->coins != game->coins + getCost(adventurer))
        printf("Error -%s (incorrectly) changed the \"coins\" variable!\n", funcName);
    if( initialState->numBuys != game->numBuys + 1)
        printf("Error -%s (incorrectly) changed the number of Buy phases available!\n", funcName);
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

    if(game->discardCount[thisPlayer] != initialState->discardCount[thisPlayer] + 1)
        printf("Error -%s (incorrectly) changed the count for this player's discard pile!\n", funcName);
    if(initialState->discardCount[otherPlayer] != game->discardCount[otherPlayer])
        printf("Error -%s changed the count of the other player's discard pile!\n", funcName);


    // Only check for the values up to the previous number in the discard pile
    for(i=0; i<initialState->discardCount[thisPlayer]; i++)
    {
        // There should be one more card in the discard than before, as the player has gained it
        if(initialState->discard[thisPlayer][i] != game->discard[thisPlayer][i] + 1)
            printf("Error -%s changed the contents of this player's discard!\n", funcName);
    }
    if( game->discard[thisPlayer][i] != adventurer)
        printf("Error -%s caused the purchased card not to be put on top of the discard!\n", funcName);

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

    free(initialState);
    initialState = NULL;
    /* End testing for unexpected changes in game state */

    // Since we just used the buy phase for this turn, we should get an error here
    if(buyCard(adventurer, game) != -1)
        printf("Error -%s allowed two buy phases in a row without a bonus buy phase!\n", funcName);

    game->numBuys++;
    game->coins = 0;
    if(buyCard(adventurer, game) != -1)
        printf("Error -%s allowed a purchase with no coins!\n", funcName);

    game->coins = 1;
    if(buyCard(adventurer, game) != -1)
        printf("Error -%s allowed a purchase with less coins than required!\n", funcName);

    game->coins = 6;
    game->supplyCount[adventurer] = 0;
    if(buyCard(adventurer, game) != -1)
        printf("Error -%s allowed a purchase when no cards remained to be bought!\n", funcName);


  printf("\n\n********** End of test reached for function %s. Any errors found are shown above.**********\n", funcName);
    return 0;
}
