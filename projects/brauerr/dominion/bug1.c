//bug1.c describing bugs found in smithy and adventurer cards

//unittest2.c:  isGameOver()
/*
  //does not check all potential stacks of cards for zero state - misses
  //treasure map during test
  //shows importance of initializing state to get the boundary conditions of the
  //application, depending on design
*/


//cardtest.c:  smithy
/*
  4 instead of 2?  discard not working?
*/

//cardtest2.c:  adventurer
/*
originally - had a unit test that checked for whether the deck and discard
only had a single treasure card - or no treasure cards
however this implementation caused the code to hang as 
the while(drawntreasure<2) is an infinite loop if you cannot draw two treasures

also the adventurer card stays in hand - does not get added to played pile
/*