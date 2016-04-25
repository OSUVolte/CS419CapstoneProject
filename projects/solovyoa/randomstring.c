/* Andriy Solovyov
 * CS 362
 * April 24
 * randomstring.c
 * Quiz 2 Description:
	             Implement a random tester for the function testme() in testme.c that is capable of printing the error message.  
                     You should implement inputChar() and inputString() to produce random values. Write up the development of your 
                     random tester and how it finds the error message as randomstring.c. Submit testme.c and randomstring.c under 
                     your onid directory in class github. (under your onid directory and not under dominion directory).
*/

/* char inputChar()

	In this function, an array of required characters was created, and then a function sizeOf would randomly select a number
	between zero and the size of an array. That random selected number would be an index for a specific character/letter in 
	the array and would be returned.
*/

/* char *inputString()

	In this function, there wasn't just a single random letter index bun a string of letters to a size of 6. The last 
	letter was a null terminator. All the random generated letters are returned and compared in the testme function to
	generate an error message.
*/

/* I was struggling getting to the error message due to bad code logic. I was stuck in the infinite  loop when it reached 
   to state 4, then after debugging I was stuck in infinite loop when reached state 9. Finally, I figured out the problem of 
   of infinite loops and received the right error response. The number of iterations was ranging between from 90 to 2500 and
   all reached to state 9. 
*/