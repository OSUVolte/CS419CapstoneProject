/******************************************************************************
* QUIZ 2 - randomstring.c
* AUTHOR: Nickolas A. Williams
* CLASS: CS362
* DATE: 04/24/2016
* NOTES: documentation for development of testme.c
******************************************************************************/

/******************************************************************************
* char inputChar()
* Returns a char from the ASCII table ranging from 32 (space) to 126 
* (tilde, ~). This range was chosen because it represents all the valid
* "output" characters, (not carriage return, &c.).
*
* char* inputString()
* Returns a string, length six, containing five lower-case letters (ASCII 97
* to 122), followed by a null terminator. This range was chosen because the
* string must contain "reset\0" in order to fail, all of which are just lower-case
* case letters.
*
* My original implementation (foolishly) used inputChar() to 
* generate the string, however, in retrospect it would have taken forever 
* to find the error, so I limited the generation to lower-case characters,
* since only lower-case characters could possibly generate an error.
*
* I ran the tester a couple times and found that the "error" is found in
* iteration 16,767,827 the first time, and 14,001,019 the second. State 9
* is reached very quickly, but getting "reset" to appear takes a long time.
******************************************************************************/