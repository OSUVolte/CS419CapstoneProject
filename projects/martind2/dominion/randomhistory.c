/* randomhistory.c - a writeup report of randomtestcard.c and
randomtestadventuer.c

By Dave Martinez, martind2@oregonstate.edu

For this assignment, I wrote two random testers that focused on the 
playAdventuer() function and the playVillage() function. In my 
previous assignment, I had noted that I had achieved near 100% coverage
for the functions under consideration. Likewise, for this assignment,
I again acheived 100% coverage for these two cards.

Overall, dominion.c saw a major reduction in coverage. In my previous
unit test assignment, I achieved 35% coverage across the entire file. 
However, with random testing, I was not utilizing the same function 
helpers that executed more lines of code. Thus, my coverage ended up
at 8% for dominion.c.

I began developing my random testers with code from the lectures titled
"Random Testing 1" and "Random Testing 2". Specifically, I utilized code
that generated random bytes and filled the gameState struct with
random bits of data. From there, I attempted to run the file and find
cause segmentation faults. 

The segmentation faults gave me quick clues as to what preconditions 
needed to exist or the playVillage and playAdventurer functions. Using
the errors, trace statements and the source code, I was able to find 
what other functions were being called and what prerequisites those
additional functions required. 

Finally, I utilized tests I had through through during the previous
assignment to quickly get an understanding if each random test
was causing unexpected behavior. I tallied these results up and output
them at the end of each .out file.

To increase or decrease the number of testing cycles, change the 
'TEST_AMT' constant defined near the start of each file. To make and
execute both files, use:

	make clean
	make randomtests

*/