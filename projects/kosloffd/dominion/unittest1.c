#include "dominion.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



int main()
{
    const char* funcName = "gainCard()";
    struct gameState* game = newGame();
    int* cardsInPlay = kingdomCards(adventurer, baron, smithy, mine, remodel, feast, steward, village, salvager, treasure_map);

    if(initializeGame(2, cardsInPlay, time(NULL), game) == -1)
    {
        printf("Couldn't intialize game!\n");
        exit(0);
    }

    printf("**************Starting test on method: %s**************\n\n", funcName);
    // Initial Test to see if there are unexpected changes to the game
    struct gameState* initialState = malloc(sizeof(struct gameState));
    memcpy(initialState, game, sizeof(struct gameState));

    // Gain a card 'normally' (it goes into the discard pile)
    if( gainCard(adventurer, game, 0, whoseTurn(game)) == -1)
        printf("Error -%s shows card is not in game when it should be!\n", funcName);

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

    if(game->discardCount[thisPlayer] != initialState->discardCount[thisPlayer] + 1)
        printf("Error -%s changed the count for this player's discard pile!\n", funcName);
    if(initialState->discardCount[otherPlayer] != game->discardCount[otherPlayer])
        printf("Error -%s changed the count of the other player's discard pile!\n", funcName);


    // Only check for the values up to the previous number in the discard pile
    for(i=0; i<initialState->discardCount[thisPlayer]; i++)
    {
        // There should be one more card in the discard than before, as the player has gained it
        if(initialState->discard[thisPlayer][i] != game->discard[thisPlayer][i] + 1)
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

    free(initialState);
    initialState = NULL;
    /* End testing for unexpected changes in game state */

    // Check other flags. First going on top of deck

    // Store the old values to check against
    int oldDeckCount = game->deckCount[thisPlayer];
    int oldNumberInPlay = game->supplyCount[adventurer];

    gainCard(adventurer, game, 1, thisPlayer);

    int newDeckCount = game->deckCount[thisPlayer];
    int newNumberInPlay = game->supplyCount[adventurer];
    if(newNumberInPlay != oldNumberInPlay-1)
        printf("Error -%s did not decrease the supply of cards in the stack!\n", funcName);
    if(newDeckCount != oldDeckCount+1)
        printf("Error -%s with Flag 1 did not increment the deck count!\n", funcName);
    if(game->deck[thisPlayer][newDeckCount-1] != adventurer)
        printf("Error -%s with Flag 1 did not put the card on top of the deck!\n", funcName);


    // Now check going into the player's hand
    int oldHandCount = game->handCount[thisPlayer];
    int adventurerCountBefore=0;
    for(i=0; i<oldHandCount; i++)
    {
        if(game->hand[thisPlayer][i] == adventurer)
            adventurerCountBefore++;
    }

    gainCard(adventurer, game, 2, thisPlayer);

    int newHandCount = game->handCount[thisPlayer];
    if(newHandCount != oldHandCount+1)
        printf("Error -%s with Flag 2 didn't increment the count of cards in hand!\n", funcName);
    int adventurerCountAfter=0;
    for(i=0; i<newHandCount; i++)
    {
        if(game->hand[thisPlayer][i] == adventurer)
            adventurerCountAfter++;
    }
    if(adventurerCountAfter != adventurerCountBefore + 1)
        printf("Error -%s with Flag 2 didn't put the gained card into the hand!\n", funcName);

  // Finally test the boundary condition when the pile is empty
    game->supplyCount[adventurer] = 0;
    if( gainCard(adventurer, game, 0, thisPlayer) != -1)
        printf("Error -%s did not recognize an empty pile!\n", funcName);

    free(game);
    printf("\n\n********** End of test reached for function %s. Any errors found are shown above.**********\n", funcName);
    return 0;
}
