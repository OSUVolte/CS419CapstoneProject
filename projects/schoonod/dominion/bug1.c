//
//  bug.c
//  xa3
//
//  Created by Dane Schoonover on 4/23/16.
//  Copyright © 2016 dane. All rights reserved.
/*
 UNIT TEST 1 - handCard()
 No bugs to report.


 UNIT TEST 2 - supplyCount()
 No bugs to report.


 UNIT TEST 3 - scoreFor()
 Bugs found.
 The scoreFor() function is not producing the correct score based on pre-populated hand, discard, and deck piles. There are two bugs causing the error.
 First, the 3rd for loop within scoreFor(), is incorrect and is counting thru discardCount rather than deckCount.
 Second, the fullDeckCount() function located within scoreFor() is not calculating the full deck count correctly. It is only counting deck cards that match enum card 0 (curse), whereas it should be counting every single card. Thus, each call to fullDeckCount() is resulting in 0 points scored due to an incorrect count and C's truncation during integer division.


 UNIT TEST 4
 No bugs to report.


 CARD TEST 1
 Bug found.
 The handCount is not decreasing during discardCard. When smithyCard() adds 3 cards, handCounts should only increase by 2, since during smithCard(), discardCard() is called which would reduce the handCount by 1. +3 - 1 = 2.


 CARD TEST 2
 Bugs found.
 This was a bug introduced in an earlier assignment. The bug erroneously allows for 3 additional treasures to be drawn rather than the allowed +2.


 CARD TEST 3
 Bug found.
 This was a bug introduced in an earlier assignment. The bug erroneously allows for 5 additional buys rather than the allowed +1.


 CARD TEST 4
 No bugs to report.
*/