/* -----------------------------------------------------------------------
 * Martha Gebremariam
 * CS362_SP2016
 *writeup for Quiz3
 * -----------------------------------------------------------------------
 */
 
/*
inputChar() randomly selects a caracter from " ax{}[]()" by fist creating a char array c and setting it equal to " ax{}[]()". Then it generates a random number between 0 and 8 using rand() function. It then returns c[random];

inputString() randomly rearranges the characters in "reset" by fist creating a char arracy c and setting it equal to "reset". Then it declares a 6 element char array str. It then goes into a for loop and generates a random numbers between 0 and 4. it then fills up elements with c[random]. It then returns str after appending '\o' at the end;

testme() indefinitely runs a while loop until consecutive calls to inputChar() result in the following in the exact order ({ ax})] And it subsequently receives "reset" in the correct order from inputString 

At that point, it will pring an error message and exit the program.

 */