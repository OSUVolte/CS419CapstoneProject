/**************************************************************************
* Erin Donnelly
* CS362 Software Engineering II
* Assignment 3
* Filename: bug1.c
* Description: Describes bugs found from unittests
*
* 1 - discardCard() allows you to discard a card even when the handCount
* is 0. This results in a negative handCount, which is impossible.
**************************************************************************/