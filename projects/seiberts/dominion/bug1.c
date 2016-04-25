//Shawn Seibert
//Bug1.c 
//This is used for describing any bugs found in unit tests

//Unit Test 1
updateCoins()
After running my tests on updateCoins(), I was unable to locate or find any bugs.
This does not imply that there are not bugs, but the test that were ran may have
overlooked them.

//Unit Test 2
gainCard()
After running my tests on gainCard(), I was unable to locate or find any bugs.
This does not imply that there are not bugs, but the test that were ran may have
overlooked them.

//Unit Test 3
discardCard()
After running my tests on discardCard(), I was unable to locate or find any bugs.
This does not imply that there are not bugs, but the test that were ran may have
overlooked them.

//Unit Test 4
playCard()
After running my tests on playCard(), I was unable to locate or find any bugs.
This does not imply that there are not bugs, but the test that were ran may have
overlooked them.

//Adventure Card Test 1
After running the test, I detected one bug that the adventure card had. When the 
program attempted to remove the top card from the deck, the top card was not removed.
The test I ran shows the top card being equal to 5, and the card removed produces a value of 
-1 and not 4, thus causing the bug.

//Smithy Card Test 2
After running my tests on the smithy card, I found a bug that causes the user to draw
4 cards instead of three. By placing a counter into the for loop and added each increment 
together. With the increment being not equal to 3, caused the test to fail.

//Council Card Test 3
After running my tests on the council card, The first test found a bug that causes the user to draw
5 cards instead of 4. By placing a counter into the for loop and added each increment 
together. With the increment being not equal to 4, caused the test to fail. The next test detected
the number of buys does not increase by one, thus causing the test to fail. 

//Minion Card Test 4
The first tested for an increase in a number of actions by one. The test failed due to the number of actions
not increasing by one. The other bug that was found deals with the number of cards added to both the current player
and the other players. All players appear to draw 5 cards instead of 4.