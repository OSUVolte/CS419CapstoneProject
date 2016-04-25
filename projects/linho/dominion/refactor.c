//
//  refactor.c
//  CS 362
//  HW 2
//  Created by Hong Lin
//  Student ID: 932-050-646
//

First of all, I modified smithy, village, adventurer, council_room and mine into individual function and they will be called in switch.

smithy:
    The variable i is not declared in the function, and in for loop i is decreasing instead of increasing.

village:
    The currentPlayer is not specified using whoseTurn funcion. And hand posision is not passing when calling discardCard.

adventurer:
    It will discard the card while drawn treasure cards are equal or more than 2 instead of less 2.

council room:
    It will not +1 buy anymore. And in for loop it will draw a card when i is current player instead of is not current player.