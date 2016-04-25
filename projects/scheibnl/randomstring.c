/*

I've implemented inputChar() and inputString() in such a way that they will, eventually, cause
testme() to print its error message.

First, inputChar() will produce a random character in the ASCII value range of 32 to 125 or Space to }. 
This covers all of the values needed to move through states 1 to 9. And this takes very little time, in practice,
to accomplish.

inputString() produces a random string of 5 lower-case characters (a-z). This takes a bit more time to move 
testme() through the last state, as the likelihood of this producing a random string with the value of "reset" is
26^5. However, it is possible to produce the error message with this implementation. Likely, it will just take a little
while to run.

*/