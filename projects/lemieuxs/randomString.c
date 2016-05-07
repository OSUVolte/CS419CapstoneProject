/*

inputChar() returns a random ASCII character, which eventually
causes state to increase to 9.
In order to generate the word "reset", inputString() generates
a random string of 5 lowercase letters, followed by a \0.
This random combination eventually generates the word "reset", which
breaks the loop. For me, it took 1978817 iterations to break the loop
for the first time.

*/