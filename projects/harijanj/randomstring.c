/*
CS 362 - Quiz 2
By Jonathan Harijanto

1. testme()
A given function that compare the character obtained from the inputChar() function
with the designated character: [, (, {,  ,a, x, }, ), and ]. If the character is a
match, then the value of state will change. After the value of state reach '9', this
function will then compare the string obtained from inputString() function with 
the designated string: "reset". The word "Error" will be printed after the value of state
reach '9' and inputString() return "reset".

2. inputChar()
Function that generates and returns random character from a defined char array.
randChar will get the value from a char array that has random generated index.
The way this function generates the index is by modulus-ing pseudo-random number with
the length of the char array.

3. inputString()
Function that generates and returns random five-characters string with null character
at the end of the string.
First it allocates pointer to char array that holds 6 characters (outputString).
With the help of loop, outputString stores random character one at a time for 5 times.
The way this function gets random char is exactly the same like inputChar function.

4. Problems
The first time I tried, this program had an infinite loop at state 3.
It never stops iterating eventhough it already reached 20 000 000 iterations.
My first thought that I had too many possibliities in the char array.
However, eventhough I shortened it, this program still had an infinite loop at state 3.
Finally I figured it out that at "if state == 3 ....." conditions, this program is testing for
null character.
Therefore, at inputChar function, I included a ' ' at the very end because I'm using the 
strlen char array as the part of my randomly generated index algorithm. 

5. Result
I ran the program (./testme) for 5 times.

The number of iteration based on 5 runs: 1177, 1463, 1018, 777, and 967. 

The test coverage result:

[harijanj@flip2 testme]$ gcov -b testme.c
File 'testme.c'
Lines executed:97.37% of 38
Branches executed:100.00% of 52
Taken at least once:98.08% of 52
Calls executed:100.00% of 10
Creating 'testme.c.gcov'

Meaning:
Almost all of the lines in the program were executed.
100% Branch coverage means 100% statement coverage, 
thus all the statements were at least once executed. 

*/