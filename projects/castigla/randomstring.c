Ashley Castiglione
Random Test Quiz
randomstring.c 

I implemented inputChar() by just returning a random number using the ASCII characters 32-95. This would ensure
a number/character combination. 

I implemented inputString() by creating an array of lenth 6 and looping through to make strings of 5 characters,
plus the \0 needed at the end of the string.

The key word of this program was to hit the word 'reset' at some point in the program. Due to the ASCII characters
being chosen randomly, this could take a long time. By hard coding reset into the program, I was able to hit the
error, so see that it was possible. 