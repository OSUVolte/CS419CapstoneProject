/********************************
Author: Luke Brewbaker
Date:  4/20/16
Modified: 4/20/16
File: randomstring.c

Overview:
Description for testme.c


*******************************/
/*

For the random tester we had to write two functions. char inputChar() and char *inputString().  char inputChar() is a function that will return a char to test against the string 'reset\0' in the main function.  Since this is a random test, I decided to use rand() and use the ASCII char values as the parameters.  The function is a simple return value:  

return (rand() % 95) +32;

The list of ASCII characters can be found here: http://www.ascii-code.com/  and I only use the ones pertaining to the English alphabet, characters 32 to 127.  However, if you wanted to make the test more thorough you can test every ASCII char, 0-255, but that is not necessary for the scope of this funciton and would only increase testing time.


char *inputString() was a little more complicated to figure out. We need to check each character of the array against one another.  Fortunately, in C, strings are also arrays.  I created a char testString[6] to be the same size as "reset\0" that we can fill with random characters.  To do this, I use a for loop to cycle through each position and fill with a random char, and then check against the string:

for(int x = 0; x < 5; x++){
	temp = rand() % 5;
	testString[x] = alpha[temp];
} 

testString[5] = '\0';
return testString;

This will return the test string after filled with random characters to main in order to check if it matches.
    

Now the program will run, and when all the conditions are met: s[0] == 'r' && s[1] == 'e' && s[2] == 's' && s[3] == 'e' && s[4] == 't' && s[5] == '\0' && state == 9).  It will print the error message.  Time varies since it is random. Anywhere from 50 to 50,000 iterations is my experience.


*/