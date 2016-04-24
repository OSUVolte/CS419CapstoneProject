/* -----------------------------------------------------------------------
 * Name: Alex Marsh
 * CS362
 * unittest1.c
 * This tests the function scoreFor() function in dominion.c
 * Include the following lines in your makefile:
 *
 * unittest1: unittest1.c dominion.o rngs.o
 *      gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */


#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
//to include printfs set to 1
#define NOISY_TEST 0


int main(){
    int seed = 1000;
    int numPlayer = 2;
    int p, r, score;
    int errors;
    int numOfCards, handIndex;
    int expected, vType;
    int discardIndex, deckIndex;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    //this will hold some of the victory cards. The numbers are taken from 
    //the enumeration in dominion.h
    //curse and gardens are not included since they are special cases
    //1=estate, 2=duchy, 3=province, 16= greathall
    int victoryCardsArr[4] = {1, 2, 3, 16}; 
    char cardName[4][20] = {"estate", "duchy", "province", "great hall"}; 
    struct gameState G;
    
    int maxHandCount = 8;
    printf("----------------- Testing scoreFor() ----------------\n");
    printf("\n");
    
//    printf("Test players hand\n");
    
    //loop through the victory cards in the victoryCardsArr
    //specifically estate, duchy, province, great hall
    for(vType=0; vType < 4; vType++){
        //loop over the players
        for (p = 0; p <numPlayer; p++){
            //with two players there are 8 of each card
            for(numOfCards = 0; numOfCards <= 8; numOfCards++){
 //               printf("Test player %d Hand with %d %s victory card(s).\n", p, numOfCards, cardName[vType]);

                memset(&G, 23, sizeof(struct gameState)); // clear the game state  

                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

                G.handCount[p] = numOfCards;        //set the number of cards on hand
                //G.discardCount[p] = numOfCards;     //set the number of card in discard
                //G.deckCount[p] = numOfCards;             //set the number of card in the deck
                
                //set all the cards in players hand to the appropriate card
                int cardNum;
                for(cardNum = 0; cardNum <= maxHandCount; cardNum++){
                    G.hand[p][cardNum] = victoryCardsArr[vType]; 
                    //G.discard[p][cardNum] = estate;     
                    //G.deck[p][cardNum] = estate;    
                }

                int handCount = G.handCount[p];  //get current num of cards in hand
 #if (NOISY_TEST == 1)
                printf("HandCount is %d\n", handCount);
                
                //print players hand for error checking. 
                printf("Player %d's hand:\n", p);
                if(handCount > 0) printf("#  Card\n");
                for(handIndex = 0; handIndex < handCount; handIndex++) {
                    int card = G.hand[p][handIndex];
                    char name[MAX_STRING_LENGTH];
                    cardNumToName(card, name);
                    printf("%-2d %-13s\n", handIndex, name);
                }
                printf("\n");
 #endif               
                
                score = scoreFor(p, &G);   //call scoreFor
                //find the expected score accourding to the card
                if(vType == 0)
                    {expected = numOfCards * 1;}    //estate
                if(vType == 1)
                    {expected = numOfCards * 3;}    //duchy
                if(vType == 2)
                    {expected = numOfCards * 6;}    //province
                if(vType == 3)
                    {expected = numOfCards * 1;}   //great hall
                 

                if(score != expected){//check if score is correct
                    printf("****FAIL Hand score = %d, expected = %d\n", score, expected);
                    errors++;
                }  
#if (NOISY_TEST == 1)
                else{
                    printf("PASS Hand score = %d, expected = %d\n", score, expected);}
#endif                
            }
        }
        
    }
    
    
//    printf("Testing Discard Deck\n");
    
    //loop through the victory cards in the victoryCardsArr
    //specifically estate, duchy, province, great hall
    for(vType = 0; vType < 4; vType++){
        //loop over the players
        for (p = 0; p < numPlayer; p++){
            //with two players there are 8 of each card
            for(numOfCards = 0; numOfCards <= 8; numOfCards++){
  //              printf("Test player %d Discard with %d %s victory card(s).\n", p, numOfCards, cardName[vType]);

                memset(&G, 23, sizeof(struct gameState)); // clear the game state  

                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

                //G.handCount[p] = numOfCards;        //set the number of cards on hand
                G.discardCount[p] = numOfCards;     //set the number of card in discard
                //G.deckCount[p] = numOfCards;             //set the number of card in the deck
                
                //set all the cards in players hand to the appropriate card
                //fill deck and hand with copper so there are no random victory
                //cards inserted. 
                int cardNum;
                for(cardNum = 0; cardNum <= maxHandCount; cardNum++){
                    G.hand[p][cardNum] = copper; 
                    G.discard[p][cardNum] = victoryCardsArr[vType];     
                    G.deck[p][cardNum] = copper;    
                }

                int discardCount = G.discardCount[p];  //get current num of cards in hand
#if (NOISY_TEST == 1)
                printf("DiscardCount is %d\n", discardCount);
                
                //print players discard for error checking. 
                printf("Player %d's discard hand:\n", p);
                if(discardCount > 0) printf("#  Card\n");
                for(discardIndex = 0; discardIndex < discardCount; discardIndex++) {
                    int card = G.discard[p][discardIndex];
                    char name[MAX_STRING_LENGTH];
                    cardNumToName(card, name);
                    printf("%-2d %-13s\n", discardIndex, name);
                }
                printf("\n");
#endif                    
                
                score = scoreFor(p, &G);   //call scoreFor
                //find the expected score accourding to the card
                if(vType == 0)
                    {expected = numOfCards * 1;}    //estate
                if(vType == 1)
                    {expected = numOfCards * 3;}    //duchy
                if(vType == 2)
                    {expected = numOfCards * 6;}    //province
                if(vType == 3)
                    {expected = numOfCards * 1;}   //great hall
                 

                if(score != expected){//check if score is correct
                    printf("****FAIL Discard score = %d, expected = %d\n", score, expected); 
                    errors++;
                }  
#if (NOISY_TEST == 1)   
                else{
                    printf("PASS Discard score = %d, expected = %d\n", score, expected);}
#endif
            }
        }
        
    }
    
    
//     printf("Testing Deck\n");
    
    //loop through the victory cards in the victoryCardsArr
    //specifically estate, duchy, province, great hall
    for(vType = 0; vType < 4; vType++){
        //loop over the players
        for (p = 0; p < numPlayer; p++){
            //with two players there are 8 of each card
            for(numOfCards = 0; numOfCards <= 8; numOfCards++){
//                printf("Test player %d Deck with %d %s victory card(s).\n", p, numOfCards, cardName[vType]);

                memset(&G, 23, sizeof(struct gameState)); // clear the game state  

                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

                //G.handCount[p] = numOfCards;        //set the number of cards on hand
                //G.discardCount[p] = numOfCards;     //set the number of card in discard
                G.deckCount[p] = numOfCards;             //set the number of card in the deck
                
                //set all the cards in players hand to the appropriate card
                //fill discard and hand with copper so there are no random victory
                //cards inserted. 
                int cardNum;
                for(cardNum = 0; cardNum <= maxHandCount; cardNum++){
                    G.hand[p][cardNum] = copper; 
                    G.discard[p][cardNum] = copper;    
                    G.deck[p][cardNum] = victoryCardsArr[vType];    
                }

                int deckCount = G.deckCount[p];  //get current num of cards in hand
 #if (NOISY_TEST == 1)
                printf("DeckCount is %d\n", deckCount);
                
                //print players deck for error checking. 
                printf("Player %d's deck:\n", p);
                if(deckCount > 0) printf("#  Card\n");
                for(deckIndex = 0; deckIndex < deckCount; deckIndex++) {
                    int card = G.deck[p][deckIndex];
                    char name[MAX_STRING_LENGTH];
                    cardNumToName(card, name);
                    printf("%-2d %-13s\n", deckIndex, name);
                }
                printf("\n");
 #endif                   
                
                score = scoreFor(p, &G);   //call scoreFor
                //find the expected score accourding to the card
                if(vType == 0)
                    {expected = numOfCards * 1;}    //estate
                if(vType == 1)
                    {expected = numOfCards * 3;}    //duchy
                if(vType == 2)
                    {expected = numOfCards * 6;}    //province
                if(vType == 3)
                    {expected = numOfCards * 1;}   //great hall
                 

                if(score != expected){//check if score is correct
                    printf("****FAIL Deck score = %d, expected = %d\n", score, expected); 
                    errors++;
                }  
#if (NOISY_TEST == 1) 
                else{
                    printf("PASS Deck score = %d, expected = %d\n", score, expected);}
#endif
            }
        }
        
    }
    
 //   printf("Testing for curse victory card\n");
    for (p = 0; p < numPlayer; p++){
      
      for(numOfCards = 0; numOfCards <= 8; numOfCards++){
        memset(&G, 23, sizeof(struct gameState)); // clear the game state  
        r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
         
        G.handCount[p] = numOfCards;        //set the number of cards on hand
        G.discardCount[p] = numOfCards;     //set the number of card in discard
        G.deckCount[p] = numOfCards;             //set the number of card in the deck

        //set all the cards in players hand to the appropriate card
        int cardNum;
        for(cardNum = 0; cardNum <= maxHandCount; cardNum++){
            G.hand[p][cardNum] = curse; 
            G.discard[p][cardNum] = copper;     
            G.deck[p][cardNum] = copper;    
        }
  //      printf("Test player %d Deck with %d curse card(s).\n", p, numOfCards);   
        int handCount = G.handCount[p];  //get current num of cards in hand
#if (NOISY_TEST == 1)
        printf("HandCount is %d\n", handCount);

        //print players hand for error checking. 
        printf("Player %d's hand:\n", p);
        if(handCount > 0) printf("#  Card\n");
        for(handIndex = 0; handIndex < handCount; handIndex++) {
            int card = G.hand[p][handIndex];
            char name[MAX_STRING_LENGTH];
            cardNumToName(card, name);
            printf("%-2d %-13s\n", handIndex, name);
        }
        printf("\n");
#endif

        score = scoreFor(p, &G);   //call scoreFor
        //find the expected score accourding to the card
        expected = -(1 * numOfCards);


        if(score != expected){//check if score is correct
            printf("****FAIL Hand score = %d, expected = %d\n", score, expected);
            errors++;
        }  
#if (NOISY_TEST == 1) 
          else{
            printf("PASS Hand score = %d, expected = %d\n", score, expected);}
#endif          
          
 //       printf("Test player %d Discard with %d curse card(s).\n", p, numOfCards);   
        
        for(cardNum = 0; cardNum <= maxHandCount; cardNum++){
            G.hand[p][cardNum] = copper; 
            G.discard[p][cardNum] = curse;     
            G.deck[p][cardNum] = copper;    
        }
        int discardCount = G.discardCount[p];  //get current num of cards in hand
 #if (NOISY_TEST == 1)
          printf("DiscardCount is %d\n", discardCount);

        //print players discard for error checking. 
        printf("Player %d's discard hand:\n", p);
        if(discardCount > 0) printf("#  Card\n");
        for(discardIndex = 0; discardIndex < discardCount; discardIndex++) {
            int card = G.discard[p][discardIndex];
            char name[MAX_STRING_LENGTH];
            cardNumToName(card, name);
            printf("%-2d %-13s\n", discardIndex, name);
        }
        printf("\n");  
#endif          
        score = scoreFor(p, &G);   //call scoreFor
        //find the expected score accourding to the card
        expected = -(1 * numOfCards);


        if(score != expected){//check if score is correct
            printf("****FAIL Discard score = %d, expected = %d\n", score, expected);
            errors++;
        }  
#if (NOISY_TEST == 1)   
          else{
            printf("PASS Discard score = %d, expected = %d\n", score, expected);}
          
        printf("Test player %d Deck with %d curse card(s).\n", p, numOfCards);   
#endif      
        for(cardNum = 0; cardNum <= maxHandCount; cardNum++){
            G.hand[p][cardNum] = copper; 
            G.discard[p][cardNum] = copper;     
            G.deck[p][cardNum] = curse;    
        }
        
        int deckCount = G.deckCount[p];  //get current num of cards in hand
 #if (NOISY_TEST == 1)
        printf("DeckCount is %d\n", deckCount);

        //print players deck for error checking. 
        printf("Player %d's deck:\n", p);
        if(deckCount > 0) printf("#  Card\n");
        for(deckIndex = 0; deckIndex < deckCount; deckIndex++) {
            int card = G.deck[p][deckIndex];
            char name[MAX_STRING_LENGTH];
            cardNumToName(card, name);
            printf("%-2d %-13s\n", deckIndex, name);
        }
        printf("\n");  
 #endif
          score = scoreFor(p, &G);   //call scoreFor
        //find the expected score accourding to the card
        expected = -(1 * numOfCards);


        if(score != expected){//check if score is correct
            printf("****FAIL Deck score = %d, expected = %d\n", score, expected);
            errors++;
        }  
#if (NOISY_TEST == 1)
          else{
            printf("PASS Deck score = %d, expected = %d\n", score, expected);}  
#endif
      }
        
    }
    
//   printf("Testing for gardens victory card\n");
    for (p = 0; p < numPlayer; p++){
      for(numOfCards = 0; numOfCards <= 8; numOfCards++){ 
      memset(&G, 23, sizeof(struct gameState)); // clear the game state  
        r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
        G.handCount[p] = numOfCards;        //set the number of cards on hand
        G.discardCount[p] = numOfCards;     //set the number of card in discard
        G.deckCount[p]=numOfCards;  
        //set all the cards in players hand to the appropriate card
        int cardNum;
        for(cardNum = 0; cardNum <= maxHandCount; cardNum++){
            G.hand[p][cardNum] = gardens; 
            G.discard[p][cardNum] = copper;     
            G.deck[p][cardNum] = copper;    
        }
 //       printf("Test player %d Deck with %d gardens card(s).\n", p, numOfCards);   
        int handCount = G.handCount[p];  //get current num of cards in hand
#if (NOISY_TEST == 1)
        printf("HandCount is %d\n", handCount);

        //print players hand for error checking. 
        printf("Player %d's hand:\n", p);
        if(handCount > 0) printf("#  Card\n");
        for(handIndex = 0; handIndex < handCount; handIndex++) {
            int card = G.hand[p][handIndex];
            char name[MAX_STRING_LENGTH];
            cardNumToName(card, name);
            printf("%-2d %-13s\n", handIndex, name);
        }
        printf("\n");
#endif

        score = scoreFor(p, &G);   //call scoreFor
        //gardens victory card is worth 1 estate for every 10 cards
        // the score is then added on, but since we don't have an 
        // additional score now, the division is enough  
        expected = (fullDeckCount(p, 0, &G)/10); 
        if(score != expected){//check if score is correct
            printf("****FAIL Deck score = %d, expected = %d\n", score, expected); 
            errors++;
        }  
#if (NOISY_TEST == 1)    
          else{
            printf("PASS Deck score = %d, expected = %d\n", score, expected);}  
          
        printf("Test player %d Discard with %d gardens card(s).\n", p, numOfCards);   
#endif        
        for(cardNum = 0; cardNum <= maxHandCount; cardNum++){
            G.hand[p][cardNum] = copper; 
            G.discard[p][cardNum] = gardens;     
            G.deck[p][cardNum] = copper;    
        }
        int discardCount = G.discardCount[p];  //get current num of cards in hand
 #if (NOISY_TEST == 1)
          printf("DiscardCount is %d\n", discardCount);

        //print players discard for error checking. 
        printf("Player %d's discard hand:\n", p);
        if(discardCount > 0) printf("#  Card\n");
        for(discardIndex = 0; discardIndex < discardCount; discardIndex++) {
            int card = G.discard[p][discardIndex];
            char name[MAX_STRING_LENGTH];
            cardNumToName(card, name);
            printf("%-2d %-13s\n", discardIndex, name);
        }
        printf("\n");  
#endif          
        score = scoreFor(p, &G);   //call scoreFor
        //find the expected score accourding to the card
        expected = (fullDeckCount(p, 0, &G)/10); 

        if(score != expected){//check if score is correct
            printf("****FAIL Discard score = %d, expected = %d\n", score, expected); 
            errors++;
        }  
#if (NOISY_TEST == 1)  
          else{
            printf("PASS Discard score = %d, expected = %d\n", score, expected);}
          
        printf("Test player %d Deck with %d gardens card(s).\n", p, numOfCards);   
#endif        
        for(cardNum = 0; cardNum <= maxHandCount; cardNum++){
            G.hand[p][cardNum] = copper; 
            G.discard[p][cardNum] = copper;     
            G.deck[p][cardNum] = gardens;    
        }
        
        int deckCount = G.deckCount[p];  //get current num of cards in hand
 #if (NOISY_TEST == 1)
        printf("DeckCount is %d\n", deckCount);

        //print players deck for error checking. 
        printf("Player %d's deck:\n", p);
        if(deckCount > 0) printf("#  Card\n");
        for(deckIndex = 0; deckIndex < deckCount; deckIndex++) {
            int card = G.deck[p][deckIndex];
            char name[MAX_STRING_LENGTH];
            cardNumToName(card, name);
            printf("%-2d %-13s\n", deckIndex, name);
        }
        printf("\n");  
 #endif
          score = scoreFor(p, &G);   //call scoreFor
        //find the expected score accourding to the card
        expected = (fullDeckCount(p, 0, &G)/10); 

        if(score != expected){//check if score is correct
            printf("****FAIL Deck score = %d, expected = %d\n", score, expected); 
            errors++;
        }  
#if (NOISY_TEST == 1) 
          else{
            printf("PASS Deck score = %d, expected = %d\n", score, expected);}  
#endif          
      }
    }
    
    if(errors == 0){
     printf("ALL TESTS PASS for whoseTurn().\n");   
    }
    else{
     printf("FAIL: There are %d errors in scoreFor().\n", errors);   
    }
    
    return 0;
}





void cardNumToName(int card, char *name){
  switch(card){
  case curse: strcpy(name,"Curse");
    break;
  case estate: strcpy(name,"Estate");
    break;
  case duchy: strcpy(name,"Duchy");
    break;
  case province: strcpy(name,"Province");
    break;
  case copper: strcpy(name,"Copper");
    break;
  case silver: strcpy(name,"Silver");
    break;
  case gold: strcpy(name,"Gold");
    break;
  case adventurer: strcpy(name,"Adventurer");
    break;
  case council_room: strcpy(name,"Council Room");
    break;
  case feast: strcpy(name,"Feast");
    break;
  case gardens: strcpy(name,"Gardens");
    break;
  case mine: strcpy(name,"Mine");
    break;
  case remodel: strcpy(name,"Remodel");
    break;
  case smithy: strcpy(name,"Smithy");
    break;
  case village: strcpy(name,"Village");
    break;
  case baron: strcpy(name,"Baron");
    break;
  case great_hall: strcpy(name,"Great Hall");
    break;
  case minion: strcpy(name,"Minion");
    break;
  case steward: strcpy(name,"Steward");
    break;
  case tribute: strcpy(name,"Tribute");
    break;
  case ambassador: strcpy(name,"Ambassador");
    break;
  case cutpurse: strcpy(name,"Cutpurse");
    break;
  case embargo: strcpy(name,"Embargo");
    break;
  case outpost: strcpy(name,"Outpost");
    break;
  case salvager: strcpy(name,"Salvager");
    break;
  case sea_hag: strcpy(name,"Sea Hag");
    break;
  case treasure_map: strcpy(name,"Treasure Map");
    break;

  default: strcpy(name,"?");
  }

}