#ifndef _DOMINION_UNIT_TESTS
#define _DOMINION_UNIT_TESTS

int addTreasureCard(int player, struct gameState *state, int tCard);
int clearHand(int player, struct gameState *state);
void testUpdateCoins();
void testGetCost();
void testPlayCard();
void testBuyCard();
void testSmithyCard();
void testAdventurerCard();
void testCouncilRoomCard();
void testVillageCard();

#endif