#include "cardtest1.c"
#include "cardtest2.c"
#include "cardtest3.c"
#include "cardtest4.c"
#include "unittest1.c"
#include "unittest2.c"
#include "unittest3.c"
#include "unittest4.c"

int main() {

	// Test unit functions
	testUpdateCoins();
	testFullDeckCount();
	testEndTurn();
	testIsGameOver();

	// Test all the cards
	testSmithy();
	testEmbargo();
	testRemodel();
	testAdventurer();
	return 0;
}