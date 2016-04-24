********************************************************
** Author: Kayla Vondy
** Filename: randomstring.c
** Description: this file describes the development of 
** 	my random tester and how it finds the error message
** 	in the testme() function.
********************************************************

***** inputChar() *****
For this function I knew I needed to pull a random selection of the 
characters that would trigger the testme() function to increment the
state variable. The state needed to be equal to 9 in order for the error
message to appear. 
My first approach was to randomly select a number whose ASCII equivalent 
would be the characters needed. However, this range was enormous! In order
to optimize the function for time efficiency, I created a global ARRAYSET 
array variable which included the list of symbols needed. Instead of looping
through 89 possibilities, I reduced it to 9 possibilities. 
Testing proved that this improved my time from about a minute to almost
instantaneous for this function.

***** inputString() *****
This function proved to be more challenging. I knew I needed to fill a 
char array with random lowercase letters and return a string address in 
memory. In order to do this more readily (and without using malloc in the 
function since every time you malloc you need to free memory) I made the
char array a global variable.
The ASCII equivalent for the lowercase alphabet is 97-122. However the key
to accessing the error message is "reset" which only needs to use the letters
from e to t. This reduces the average time from 26^5 to 16^5.


I chose to make my algorithm tests as efficient as possible since there was
little to no requirements for this other than to write functions that would 
cause the error message to appear.