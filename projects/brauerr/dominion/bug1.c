//bug1.c describing bugs found in smithy and adventurer cards

//unittset1.c:  buyCard()
/*
  //does not decrement buys after successful purchase of silver
*/

//unittest2.c:  isGameOver()
/*
  //does not check all potential stacks of cards for zero state - misses
  //treasure map during test
  //shows importance of initializing state to get the boundary conditions of the
  //application, depending on design
*/

//unittest3.c:  scoreFor()
/*
  //failed for both players
  //either a bug in the gainCard method or a bug in the
  //fullDeckCount method for gardens
*/

//unittest4.c: shuffle()
/*
  //doesn't handle discard pile not being empty
*/

//cardtest1.c:  smithy
/*
  no bugs found
*/

//cardtest2.c:  adventurer
/*
originally - had a unit test that checked for whether the deck and discard
only had a single treasure card - or no treasure cards
however this implementation caused the code to hang as 
the while(drawntreasure<2) is an infinite loop if you cannot draw two treasures

also the adventurer card stays in hand - does not get added to played pile
and treasure cards not properly added - only one is counting towards update coins
/*

//cardtest3.c: village
/*
  no bugs found
*/

//cardtest4.c: council_room
/*
  no bugs found
*/