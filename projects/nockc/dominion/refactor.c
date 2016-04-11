I changed the function prototypes in dominion.h to the following:
int playAdventurer(struct gameState *state, int handPos);
int playSmithy(struct gameState *state, int handPos);
int playVillage(struct gameState *state, int handPos);
int playFeast(struct gameState *state, int choice1);
int playCouncil_Room(struct gameState *state, int handPos);

In dominion.c, I created the above functions with the refactored code from the cardEffect function. In the switch statement of the cardEffect function, I replaced the code with returned value of calling respective refactored function. 

There are bugs in all five of the functions. The first bug is in the playAdventurer on line 1234. The initial value of drawntreasure variable is supposed to be 0 but instead I made it 1. This will cause the function to stop looking for treasure cards after the first treasure card is revealed. Therefore the Adventurer function will not succeed in giving the player first two treasure cards revealed.

The second bug is in playVillage on line 1279. The village is supposed to enable the current player to gain an additional card as well as two additional actions. This bug gives the player three additional actions instead of two which is incorrect.

The third bug is in playSmithy on line 1262. Smithy is supposed to allow the current player to draw an additional three cards, but this bug allows the player to draw five additional cards. 

The fourth bug is in playCouncil_Room on line 1346. For the current player who is playing council room, they should gain four additional cards, a buy, and also the other player should be able to draw a card. This bug gives the current player an additional card (for a total of five cards) while the other player doesn’t get to draw any cards.

The fifth bug is in playFeast on line 1306. When its played, this card gets trashed while current player gains a card costing up to 5. This bug causes a card costing exactly 5 to be reclassified as “too expensive.” Therefore, the player will only be allowed to choose a card costing 4 or less which is incorrect for feast.

