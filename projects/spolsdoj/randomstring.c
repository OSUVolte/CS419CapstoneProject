randomstring.c

By: James Spolsdoff

char inputChar()
This was a basic random generator function that used a range of ascii char to generate a variable for the main
testing while loop. It reached state = 9 rather quickly.

char inputString()
At first I wrote a function that utilized a long string and both upper and lowercase characters. When I ran this
on flip it took far too long and did not reach the error condition. I first paired down the string to a six element
array. After running that the test was still too long. I then only included lowercase char in the array and was able
to have the program throw an wrror after iteration 5297423. 
