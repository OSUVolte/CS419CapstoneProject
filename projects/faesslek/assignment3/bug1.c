/******************************************************************************
 * Author: Kelby Faessler
 * Class: CS362
 * Project: Assignment 3
 *****************************************************************************/

/*
Bug descriptions:

In order to write unit tests for the various functions that I picked, I had to 
first understand what the function was trying to do. The easiest way for me to
do this was to simply read  the code for the function. So, this was more 
white-box testing than black-box testing. But, if the function names were not
descriptive enough, or even if they were but the function was some internal
utility, then it was necessary to read the function. Otherwise I wouldn't 
have an idea of what the function should do, and therefore I wouldn't know how
to test it. Reading the code for the functions allowed me to pick up on some 
bugs and I wrote tests specifically for these bugs in my unit tests. 

One of these bugs was in the updateCoins() function. This function allowed you
to pass in a player number greater than the max number of players allowed in
the game. This is important because there are arrays of data that are sized
according to the max number of allowable players, and the player number being
passed into this function is used as an array index. So, since this function
doesn't check the player number before using it, if you passed in the wrong
value it would read/write memory outside the bounds of the array. Very bad!!

There are several arrays used by many functions in this implementation of 
dominion so I suspect this will be a problem in other functions as well.

Another bug I found was in the isGameOver(). This function loops over all the 
cards to see if there are at least 3 with a supply equal to or less than 0.
However, the maximum loop count is hard coded to 25, instead of some global
function like NUM_CARDS. When I looked at how the array that stores the supply
counts for each of the cards is sized, it's based on the enumerated value of
the treasure_map card, which is also equal to the total number of cards since
treasure_map is the last card in that enumeration. That value does not match 
the hard coded value in isGameOver(), therefore isGameOver() is not checking
whether the supply of the treasure_map card is 0. I confirmed this with my
unit test.

*/
