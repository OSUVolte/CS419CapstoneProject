#include "dominion.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



int main()
{
    const char* funcName = "discardCard()";
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
    int thisPlayer = whoseTurn(game);
    int otherPlayer = whoseTurn(game)^1;

    int lastCardInHand = game->hand[thisPlayer][game->handCount[thisPlayer]];
    // Discard the last card in the player's hand 'normally' (it goes into the discard pile)
    discardCard(game->handCount[thisPlayer]-1 , whoseTurn(game), game, 0);

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
    if( initialState->handCount[thisPlayer] != game->handCount[thisPlayer] + 1)
        printf("Error -%s changed the number of cards in this player's hand!\n", funcName);
        // Toggle the bit to check for the other player's hand
    if( initialState->handCount[otherPlayer] != game->handCount[otherPlayer])
        printf("Error -%s changed the number of cards in the other player's hand!\n", funcName);

    // Only check up to the fourth card in the hand since the last was discarded
    for(i=0; i< game->handCount[thisPlayer]; i++)
    {
        if( initialState->hand[thisPlayer][i] != game->hand[thisPlayer][i])
            printf("Error -%s changed the cards in this player's hand! (If turn isn't changed)\n", funcName);
    }
    for(i=0; i<initialState->handCount[otherPlayer]; i++)   //Check all the original cards in the other hand
    {
        if( initialState->hand[otherPlayer][i] != game->hand[otherPlayer][i])
            printf("Error -%s changed the cards in the other player's hand! (If turn isn't changed)\n", funcName);
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

    if(initialState->discardCount[thisPlayer] != game->discardCount[thisPlayer] +1 )
        printf("Error -%s (incorrectly) changed the count for this player's discard pile!\n", funcName);
    if(initialState->discardCount[otherPlayer] != game->discardCount[otherPlayer])
        printf("Error -%s changed the count of the other player's discard pile!\n", funcName);


    // Only check for the values up to the previous number in the discard pile
    for(i=0; i<initialState->discardCount[thisPlayer]; i++)
    {
        // There should be one more card in the discard than before, as the player has discarded it
        if(initialState->discard[thisPlayer][i] != game->discard[thisPlayer][i])
            printf("Error -%s (incorrectly) changed the contents of this player's discard!\n", funcName);
    }
    if(game->discard[thisPlayer][i] != lastCardInHand)
        printf("Error -%s did not place the discarded card on the top of the discard stack!\n", funcName);
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



    // Check the trash flag
    struct gameState* stateBeforeTrash = malloc(sizeof(struct gameState));
    memcpy(stateBeforeTrash, game, sizeof(struct gameState));

    // Check to make sure the card was removed from the hand and that it couldn't have been put anywhere else
    int lastCardIndex = game->handCount[thisPlayer]-1;
    discardCard(game->handCount[thisPlayer] - 1, thisPlayer, game, 1);
    if(stateBeforeTrash->deckCount[thisPlayer] != game->deckCount[thisPlayer])
        printf("Error -%s did not trash the card, the deckCount was changed!", funcName);
    if(stateBeforeTrash->discardCount[thisPlayer] != game->discardCount[thisPlayer])
        printf("Error -%s did not trash the card, the discardCount was changed!", funcName);
    if(game->hand[thisPlayer][lastCardIndex] != -1)
        printf("Error -%s did not change the value of the discarded card to -1\n", funcName);

    // Check that the number of cards was reduced
    if(stateBeforeTrash->handCount[thisPlayer] != game->handCount[thisPlayer] + 1)
        printf("Error -%s did not trash the card, the handCount was incorrectly changed!", funcName);

    free(stateBeforeTrash);


    // Test cases where the last card isn't the one discarded and there is only one card in the hand

    // Let there be three distinct cards in the hand
    game->hand[thisPlayer][0] = adventurer;
    game->hand[thisPlayer][1] = baron;
    game->hand[thisPlayer][2] = smithy;
    game->hand[thisPlayer][3] = -1;
    game->hand[thisPlayer][4] = -1;
    game->handCount[thisPlayer] = 3;

    struct gameState* stateBeforeDiscard = malloc(sizeof(struct gameState));
    int cardIndex = 1;      // Discard the middle card for the first loop
    while(game->handCount[thisPlayer] > 0)
    {
        memcpy(stateBeforeDiscard, game, sizeof(struct gameState));
        discardCard(cardIndex, thisPlayer, game, 0);

        // Check that the number of cards was reduced
        if(stateBeforeDiscard->handCount[thisPlayer] != game->handCount[thisPlayer] + 1)
            printf("Error -%s did not trash the card, the handCount was incorrectly changed!", funcName);

        // Check that the indexes were updated correctly
        for(i=0; i<game->handCount[thisPlayer]; i++)
        {
            if(game->hand[thisPlayer][i] != stateBeforeDiscard->hand[thisPlayer][i] &&
                game->hand[thisPlayer][i] != stateBeforeDiscard->hand[thisPlayer][stateBeforeDiscard->handCount[thisPlayer]-1])
            printf("Error -%s did not rearrange the hand correctly after discarding!\n", funcName);
        }
        cardIndex = 0;      // For the remaining loops, discard the first card
    }

    free(stateBeforeDiscard);
    free(game);

    printf("\n\n********** End of test reached for function %s. Any errors found are shown above.**********\n", funcName);
    return 0;
}
