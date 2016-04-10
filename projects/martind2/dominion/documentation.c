#include <iostream.h>

int main(int argc, char* argv[]) {
    /* Documentation.c
        Cards:
        SMITHY - Draw three cards. Uses a for loop to draw more cards from the deck.
        ADVENTURER - While drawntreasure is less than two, shuffle the deck if needed,
            then draw a card. If the card is a copper, silver or gold,
            increment drawntreasurer, otherwise add the card to the temphand and
            decrease the player's handcount.
            When the player has drawn two treasures, discard all cards from the temphand


        Other functions:
        discardCard(handPos, currentPlayer, state, 0) - If the card has no trash flag,
            add the card to the player's discard pile. Set the played card in the player's
            hand to -1 using the currentPlayer and handPos params.
            Remove the card from the players hand: if the card is the last card in hand
            array, simply reduce the hand count; if its the only card in the player's hand,
            reduce the player's hand count; otherwise, replace the discarded card with the
            last card in the player's hand array. Set the last card to -1, reduce the
            player's hand by one.
        updateCoints(player, state, bonus) - Reset the coin count to zero. Iterate through
            the player's hand. If a card in the players hand is a copper, add one to the 
            count; if silver, add two; if gold, add three. Add the the bonus param.



    */

    printf("Documentation is in the comments of this file.\n");

    return 0;
} 
