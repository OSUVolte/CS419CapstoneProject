// Heidi Binder-Vitti
// CS362
// Random Testing Quiz 2

In the inputChar function, I created an array with the characters that do something in the 
testme function.  Then I used rand() to pick a random character from the array to return.

For the inputString function, I created an array with random words, including the word
"reset", which is needed to call the error message.  I used rand() to pick a random word
from the array to return from that function.

This will get to the error message by advancing to state 9 by going through the characters
returned randomly from inputChar.  Once at state 9, the program will keep running until 
'reset' is randomly returned from inputString.  At that point the error messag will print
and the program will quit.