Shawn Seibert
April 21, 2016
randomstring.c
Quiz 2 Random Tester


In order to display the error message, “error ”, when a certain condition is met, I created two random testers for
inputChar() and inputString(). Starting with inputChar(), I created a character array that included various 
alphabetic characters and various brackets. A single character would be randomly returned from that array. The character
would then be checked to see if it matches one of the desired conditional statements. This continues until all the 
characters are/are not found. 
 
The other function, inputString(), creates a random 5 letter character string which is then returned back to the
main function.  If the word “reset” is not found, then the inputString() will be called again and a new random 5 letter
word would be created and tested. Once the word “reset” is found, then the “error” message is displayed and the program stops.
	
Based on running this random testing multiple times, I was able to display the error message as low ~250,000 iterations and up 
to ~7,230,000 iterations. If done differently, I would have included all the characters of the ASCII table for the inputChar() 
function. This would have expanded the search for any additional errors but would have most likely increased the duration and 
iterations of the random test.
