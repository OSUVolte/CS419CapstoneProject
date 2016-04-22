/************************************************************
** Class:  CS 362 - Software Engineering II - 400
** Author:  Chris McLaughlin
** File:  randomstring.c
** Date:  4/8/16
** Due Date: 4/10/16
**
** Description:  Documentation for the development or my vers.
** of a random tester for the function testme() from testme.c
** that finds the error message at the end.
*************************************************************/

/************************************************************
** Basic Understanding of How to Reach the Error:
**
** In order to reach the error in testme.c.  The testme() 
** function uses a while loop to repeat calls to inputChar()
** and inputString().  As inputChar() produces characters which
** match conditional requirements in the order of...
** Start...[, (, {, Space, a, x, }, ), ]...Finish
** The test state is advanced incrementally from 0 up to 9.
** Once state 9 has been reached, the test checks to see if
** inputString() produces the string "reset"
** If this condition is met...the error is produced. 
*************************************************************/

/************************************************************
** Implementation of inputChar() to reach req. error state:
** 
** Seeing as the test state is advanced incrementally.  It
** made sense that producing random characters over the ASCII 
** range from Space to Del [32 to 127] would appropriately
** advance the test state in a reasonable amount of time.
** Going into more detail, there is a 1/95 (1.05%) chance 
** with each call to inputChar() that the character will 
** advance the state if state advancement is available.  This
** means it should take approximately 855 calls to inputChar
** on average...to reach test state 9.
*************************************************************/

/************************************************************
** Implementation of inputString() to reach req. error state:
**
** Once the test state reaches level 9.  The calls to
** inputString() become more important in determining whether
** the error is produced.  Producing the string "reset"
** randomly without modifying the character pool that creates
** the input string would result in an unfeasible test time 
** to produce the error.  This is due to the fact that char 
** order plays a factor.  If an unmodified character pool is
** used to generate the input string there would be a 
** (1/95)*(1/95)*(1/95)*(1/95)*(1/95) * 100% chance of 
** producing the required string.  In order to make calls to
** inputString() more likely to produce an error; the char
** pool in which I used to generate the random inputString
** was "testertesterABC."  By primarily containing r's, e's
** s's, and t's.  The probability "reset" will be produced 
** will be substantially higher, while still maintaining the
** nature of a random tester.
**
** After 10 runs...There was an average of 2753.3 iterations to 
** reach the error. 
*************************************************************/