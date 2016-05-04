William George
CS 362
Quiz Random Testing 2

For the first function inputChar(), I made an array with characters used in the testme function. 
Then I used the rand function to pick a character from the array of characters to return.

For the second functon inputString(), I once again made an array. This time I used random words including the word "reset".
The word "reset" is used by the testme function to return an error and exit the program loop. 
By doing it this way we can move through each of the characters in the char array then finish the loop by moving randomly through 
the string array. This will allow the program to test each of the char positions on the inputChar() array. 