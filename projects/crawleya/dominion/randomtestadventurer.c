/* -----------------------------------------------------------------------
 * Alisha Crawley-Davis
 * CS 362 Assn 3
 * 5/8/2016
 * randomtestadventurer.c
 * Test of Adventurer card in cardEffect() in  dominion.c
 * Based on template provided in class
 *
 * Include the following lines in makefile:
 *
 * randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
 *     gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

/*****************************************************************************
 * Description: This function updates the testsCompleted and testsPassed 
 *              variables as appropriate
 * Input:       int i; Boolean 1 = pass, 0 = fail
 *              *tp testsPassed increments when test passes
 *              *tc testsCompleted increments each time the function
 *               is called
 **************************************************************************/
void theResult(int i, int *tp, int *tc)
{
    *tc = *tc + 1;
    if (i == 1) //test passed
    {
        *tp = *tp + 1;
//        printf("PASS: ");
    }
/*    else if (i == 0) //test failed
        printf("FAIL: ");
    else            //bad input to function
        printf("BAD TEST");
*/
}

int main() {

    //Index variables
    int r, i, j, m, n;

    //Set up random number generator
    srand(time(NULL));
    int seed = rand();

    //Set up the game
    //
    //Choose 10 arbitrary kingdom cards
    int k[10] = {smithy, adventurer, salvager, embargo, ambassador, steward,
                  village, remodel, mine, feast};

    //Treasure cards
    int treasure[3] = {copper, silver, gold};

    //Overall Test Stats
    int overallTestsPassed = 0;
    int overallTestsCompleted = 0;

    //Go through n iterations of random tests
    //Note I ran this with many more iterations
    //but got the same information I got
    //with only 20 iterations. I am turning
    //this in with 20 in the interest
    //of saving space in the .out file
    for (n = 0; n < 20; n++)
    {
        printf("Random Iteration #%d:\n", n + 1);

        //Randomly choose number of players from 2 to 4
        int numPlayer;
        numPlayer = (rand() % 3) + 2;
    
        struct gameState G;
        struct gameState origG;
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
        assert (r == 0); //Make sure game is initialized correctly

        int handpos = 0;
        int choice1 = 0;
        int choice2 = 0;
        int choice3 = 0;
        int bonus = 0;
        int numOriginalTreasuresInHand = 0;
        int numTreasuresInDeck = 0;
        int numTreasuresInDiscard = 0;
        int numNewTreasures = 0;
        int adventurerInHand = 0;
        int correctNumCardsInHand = 1;
        int correctNumAdventurersInHand = 1;
        int correctNumTreasuresInHand = 1;
        int correctNumCardsInDeck = 1;
        int correctNumCardsInDiscard = 1;
        int otherPlayersCardsSame = 1;
        int kingdomCardsSame = 1;
        int treasureCardsSame = 1;
        int victoryCardsSame = 1;

        //Randomly choose how many cards are in each player's hand, deck, and discard (between 3 and 10)
        for (i = 0; i < numPlayer; i++)
        {
            G.handCount[i] = (rand() % 8) + 3;
            G.deckCount[i] = (rand() % 8) + 3;
            G.discardCount[i] = (rand() % 8) + 3;
        }

        //Randomly fill each player's hand, discard
        for (i = 0; i < numPlayer; i++)
        {
            for (j = 0; j < G.handCount[i]; j++)
            {
                //Fill player's hands
    
                //Randomly decide if the card is a kingdom, treasure, or curse card
                m = rand() % 3;
                if (m == 0) //treasure card (arbitrary decision that 0 means treasure card)
                    G.hand[i][j] = treasure[rand() % 3];
                else if (m == 1)//kingdom card
                    G.hand[i][j] = k[rand() % 9];
                else
                    G.hand[i][j] = curse;
     
                //Fill player's decks
    
                //Randomly decide if the card is a kingdom, treasure, or curse card
                m = rand() % 3;
                if (m == 0) //treasure card (arbitrary decision that 0 means treasure card)
                    G.deck[i][j] = treasure[rand() % 3];
                else if (m == 1)//kingdom card
                    G.deck[i][j] = k[rand() % 9];
                else
                    G.deck[i][j] = curse;
    
                //Fill player's discard piles
    
                //Randomly decide if the card is a kingdom, treasure, or curse card
                m = rand() % 3;
                if (m == 0) //treasure card (arbitrary decision that 0 means treasure card)
                    G.discard[i][j] = treasure[rand() % 3];
                else if (m == 1)//kingdom card
                    G.discard[i][j] = k[rand() % 9];
                else
                    G.discard[i][j] = curse;
            }
        }
       
        //Randomly choose a current player
        int currentPlayer;
        G.whoseTurn = rand() % numPlayer;
        currentPlayer = G.whoseTurn;
    
	//Put an Adventurer card in current player's hand
        G.hand[currentPlayer][0] = adventurer;
    //    printf("Current player is %d\n",G.whoseTurn);
    
        //Count number of Adventurers in current player's hand
        int numAdventurer = 0;
        for (i = 0; i < G.handCount[currentPlayer]; i++)
            if (G.hand[currentPlayer][i] == adventurer)
                numAdventurer++;
        printf("----------TESTING adventurer CARD----------:\n");


        printf("Player's original hand(4, 5, 6 are treasure 7 is adventurer): ");
        for (i = 0; i < G.handCount[currentPlayer]; i++)
            printf("%d ",G.hand[currentPlayer][i]);
        printf("\n");

        //Count number of Treasure Cards in current player's hand, deck, and discard
        for (i = 0; i < G.handCount[currentPlayer]; i++)
            for (j = 0; j < 3; j++)
            {
                if (G.hand[currentPlayer][i] == treasure[j])
                    numOriginalTreasuresInHand++;
                if (G.deck[currentPlayer][i] == treasure[j])
                    numTreasuresInDeck++;
                if (G.discard[currentPlayer][i] == treasure[j])
                    numTreasuresInDiscard++;
            }
//        printf("Number of original treasures in hand is %d\n",numOriginalTreasuresInHand);
//        printf("# treasures in deck is %d\n",numTreasuresInDeck);
//        printf("# treasures in discard is %d\n",numTreasuresInDiscard);

        //Test Adventurer Card
    
        int testsPassed = 0;
        int testsCompleted = 0; 
   
        //Make copy of current game state to compare to game state after card is played 
        memcpy(&origG, &G, sizeof(struct gameState));

        //Play Adventurer Card
        cardEffect(adventurer, choice1, choice2, choice3, &G, handpos, &bonus);
 
        printf("Player's hand after card effect(4, 5, 6 are treasure, 7 is adventurer): ");
        for (i = 0; i < G.handCount[currentPlayer]; i++)
            printf("%d ",G.hand[currentPlayer][i]);
        printf("\n");

        //Check to make sure correct number of cards in player's hand - should be 1 more
        //because two treasure cards are added and one Adventurer card is removed
        //Note that this only works if player has enough treasure cards in their deck/discard
        if (numTreasuresInDeck + numTreasuresInDiscard >= 2)
        {
            if (G.handCount[currentPlayer] == origG.handCount[currentPlayer] + 1)
                theResult(1, &testsPassed, &testsCompleted);
            else
            {
                theResult(0, &testsPassed, &testsCompleted);
                correctNumCardsInHand = 0;
            }
        }
        
        //Check to make sure there are two more treasure cards in player's hand
        //Note that this only works if the player has enough treasure cards in their deck/discard
        if (numTreasuresInDeck + numTreasuresInDiscard >= 2)
        {
            for (i = 0; i < G.handCount[currentPlayer]; i++)
                for (j = 0; j < 3; j++)
                    if (G.hand[currentPlayer][i] == treasure[j])
                        numNewTreasures++;
            if (numNewTreasures == numOriginalTreasuresInHand + 2)
                theResult(1, &testsPassed, &testsCompleted);
            else
            {
                theResult(0, &testsPassed, &testsCompleted);
                correctNumTreasuresInHand = 0;
            }
//            printf("Number of treasure cards in hand:\tExpected %d, got %d\n", numOriginalTreasuresInHand + 2, numNewTreasures);
        }
        else
            printf("Not testing number of treasure cards in hand\n");
    
        //Check to make sure there is one less Adventurer in the hand
        for (i = 0; i < G.handCount[currentPlayer]; i++)
            if (G.hand[currentPlayer][i] == adventurer)
                adventurerInHand++;
        if (adventurerInHand == numAdventurer - 1)
            theResult(1, &testsPassed, &testsCompleted);
        else
        {
            theResult(0, &testsPassed, &testsCompleted);
            correctNumAdventurersInHand = 0;
        }
//        printf("Adventurer in hand:\tExpected %d, got %d\n", numAdventurer - 1, adventurerInHand);
        
        //Check to make sure other players have the same number of cards in their hands, decks, and discard piles
        for (i = 0; i < numPlayer; i++)
        {
            if (i != currentPlayer)
            {
                if (G.handCount[i] == origG.handCount[i])
                    theResult(1, &testsPassed, &testsCompleted);
                else
                {
                    theResult(0, &testsPassed, &testsCompleted);
                    otherPlayersCardsSame = 0;
                }
//                printf("Player %d, expected %d cards in hand, got %d\n",i, origG.handCount[i], G.handCount[i]);
            }
        }
    
       //Make sure kingdom cards have not changed
        if (origG.supplyCount[smithy] == G.supplyCount[smithy])
            theResult(1, &testsPassed, &testsCompleted);
        else
        {
            theResult(0, &testsPassed, &testsCompleted);
            kingdomCardsSame = 0;
        }
    //    printf("Number of smithy cards should not change.\n");
    
        if (origG.supplyCount[adventurer] == G.supplyCount[adventurer])
            theResult(1, &testsPassed, &testsCompleted);
        else
        {
            theResult(0, &testsPassed, &testsCompleted);
            kingdomCardsSame = 0;
        }
    //    printf("Number of adventurer cards should not change.\n");
    
        if (origG.supplyCount[salvager] == G.supplyCount[salvager])
            theResult(1, &testsPassed, &testsCompleted);
        else
        {
            theResult(0, &testsPassed, &testsCompleted);
            kingdomCardsSame = 0;
        }
    //    printf("Number of salvager cards should not change.\n");
    
        if (origG.supplyCount[embargo] == G.supplyCount[embargo])
            theResult(1, &testsPassed, &testsCompleted);
        else
        {
            theResult(0, &testsPassed, &testsCompleted);
            kingdomCardsSame = 0;
        }
    //    printf("Number of embargo cards should not change.\n");
    
        if (origG.supplyCount[ambassador] == G.supplyCount[ambassador])
            theResult(1, &testsPassed, &testsCompleted);
        else
        {
            theResult(0, &testsPassed, &testsCompleted);
            kingdomCardsSame = 0;
        }
    //    printf("Number of ambassador cards should not change.\n");
    
        if (origG.supplyCount[steward] == G.supplyCount[steward])
            theResult(1, &testsPassed, &testsCompleted);
        else
        {
            theResult(0, &testsPassed, &testsCompleted);
            kingdomCardsSame = 0;
        }
    //    printf("Number of steward cards should not change.\n");
    
        if (origG.supplyCount[village] == G.supplyCount[village])
            theResult(1, &testsPassed, &testsCompleted);
        else
        {
            theResult(0, &testsPassed, &testsCompleted);
            kingdomCardsSame = 0;
        }
    //    printf("Number of village cards should not change.\n");
    
        if (origG.supplyCount[remodel] == G.supplyCount[remodel])
            theResult(1, &testsPassed, &testsCompleted);
        else
        {
            theResult(0, &testsPassed, &testsCompleted);
            kingdomCardsSame = 0;
        }
    //    printf("Number of remodel cards should not change.\n");
    
        if (origG.supplyCount[mine] == G.supplyCount[mine])
            theResult(1, &testsPassed, &testsCompleted);
        else
        {
            theResult(0, &testsPassed, &testsCompleted);
            kingdomCardsSame = 0;
        }
    //    printf("Number of mine cards should not change.\n");
    
        if (origG.supplyCount[feast] == G.supplyCount[feast])
            theResult(1, &testsPassed, &testsCompleted);
        else
        {
            theResult(0, &testsPassed, &testsCompleted);
            kingdomCardsSame = 0;
        }
    //    printf("Number of feast cards should not change.\n");
    
        //Number of victory cards should not change
        if (origG.supplyCount[estate] == G.supplyCount[estate])
            theResult(1, &testsPassed, &testsCompleted);
        else
        {
            theResult(0, &testsPassed, &testsCompleted);
            victoryCardsSame = 0;
        }
    //    printf("Number of estate cards should not change.\n");
    
        if (origG.supplyCount[province] == G.supplyCount[province])
            theResult(1, &testsPassed, &testsCompleted);
        else
        { 
            theResult(0, &testsPassed, &testsCompleted);
            victoryCardsSame = 0;
        }
    //    printf("Number of province cards should not change.\n");
    
        if (origG.supplyCount[duchy] == G.supplyCount[duchy])
            theResult(1, &testsPassed, &testsCompleted);
        else
        {
            theResult(0, &testsPassed, &testsCompleted);
            victoryCardsSame = 0;
        }
    //    printf("Number of duchy cards should not change.\n");
    
        //Number of treasure cards should not change
        if (origG.supplyCount[copper] == G.supplyCount[copper])
            theResult(1, &testsPassed, &testsCompleted);
        else
        {
            theResult(0, &testsPassed, &testsCompleted);
            treasureCardsSame = 0;
        }
    //    printf("Number of coppers should not change.\n");
        
        if (origG.supplyCount[silver] == G.supplyCount[silver])
            theResult(1, &testsPassed, &testsCompleted);
        else
        {
            theResult(0, &testsPassed, &testsCompleted);
            treasureCardsSame = 0;
        }
    //    printf("Number of silvers should not change.\n");
    
        if (origG.supplyCount[gold] == G.supplyCount[gold])
            theResult(1, &testsPassed, &testsCompleted);
        else
        {
            theResult(0, &testsPassed, &testsCompleted);
            treasureCardsSame = 0;
        }
    //    printf("Number of golds should not change.\n");
    
        printf("Number of players was %d\n", numPlayer);
        if (testsPassed == testsCompleted)
            printf("All tests passed!\n");
        else
        {
            printf("%d passed out of %d tests.\n", testsPassed, testsCompleted);
            if (correctNumCardsInHand == 0)
                printf("Incorrect number of cards in current player's hand, expected %d got %d\n",origG.handCount[currentPlayer] + 1, G.handCount[currentPlayer]);
            if (correctNumAdventurersInHand == 0)
                printf("Incorrect number of Adventurers in current player's hand, expected %d, got %d\n", numAdventurer - 1, adventurerInHand);
            if (correctNumTreasuresInHand == 0)
                printf("Incorrect number of Treasures in current player's hand:\tExpected %d, got %d\n", numOriginalTreasuresInHand + 2, numNewTreasures);
 
            if (correctNumCardsInDeck == 0)
                printf("Incorrect number of cards in current player's deck, expected %d, got %d\n",origG.deckCount[currentPlayer] - 3, G.deckCount[currentPlayer]);
            if (correctNumCardsInDiscard == 0)
                printf("Incorrect number of cards in current player's discard, expected %d, got %d\n",origG.discardCount[currentPlayer] + 1, G.discardCount[currentPlayer]);
            if (otherPlayersCardsSame == 0)
                printf("Other player(s) have incorrect numbers of cards\n");
            if (kingdomCardsSame == 0)
                printf("Kingdom Card supply piles incorrect\n");
            if (treasureCardsSame == 0)
                printf("Treasure Card supply piles incorrect\n");
            if (victoryCardsSame == 0)
                printf("Victory Card Supply piles incorrect\n");
        }
        printf("----------FINISHED TESTING adventurer CARD----------\n\n");
        overallTestsPassed += testsPassed;
        overallTestsCompleted+= testsCompleted;
    }    
    printf("Overall tests Passed: %d\n", overallTestsPassed);
    printf("Overall tests Completed: %d\n", overallTestsCompleted);
 
    return 0;
}
