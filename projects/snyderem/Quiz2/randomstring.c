/*
** Filename: randomstring.c
** Emily Snyder
** Spring 2016
** CS 362-400


The desired outcome for the random tester in testme.c is to print the error message 
that is present in the testme() function. By examing that function it is clear 
that for this to happen the function must pass through all of the different states
and in order to hit each a specific character must be found. There states are
from '0' to '9' and after reaching the 9th state the function looks for the
string a specific string. This string for the final case is 6 characters long 
consisting of 5 letters and the null terminator. 

The required characters and string are as follows:
Characters - '[', '(', '{', ' ', 'a', 'x', '}', ')', ']'
String - "reset"

Removing the duplicate letters from the string and adding them to the list
of necessary characters gives the following list:
'[', '(', '{', ' ', 'a', 'x', '}', ')', ']', 'r', 'e', 's', 't'

Based on this information, the inputChar() function randomly selects one of the
13 characters that is required in testme() and the inputString() function
creates a string that is made up of 5 random characters chosen by
inputChar(). 

Using this method there is a 1/13 or 7.69% chance of getting each of the 
characters for the first 9 cases and (1/13)^5 0.000269% chance of getting the 
desired word "reset". 

Running the program 10 times it was possible to print the error message after
an average of 307,446 time.

Iterations:
	60520
	124003
	381845
	18966
	583179
	387381
	9752
	92384
	356260
	1060170
Average: 307446


Running gcov on the file, it shows that there is 97.44% line coverage and 100%
branch coverage.

File 'testme.c'
Lines executed:97.44% of 39
Branches executed:100.00% of 52
Taken at least once:96.15% of 52
Calls executed:100.00% of 10
Creating 'testme.c.gcov'


Looking at the testme.c.gcov it shows that in the testme() function, there is
100% block coverage demonstrating that the random tester covers all of the blocks
in the function that it is testing. 

Results from gcov:

function testme called 1 returned 0% blocks executed 100%
        1:   38:void testme()
        -:   39:{
        1:   40:  int tcCount = 0;
        -:   41:  char *s;
        -:   42:  char c;
        1:   43:  int state = 0;
        -:   44:  while (1)
        -:   45:  {
   398895:   46:    tcCount++;
   398895:   47:    c = inputChar();
call    0 returned 100%
   398895:   48:    s = inputString();
call    0 returned 100%
   398895:   49:    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);
call    0 returned 100%
        -:   50:
   398895:   51:    if (c == '[' && state == 0) state = 1;
branch  0 taken 8% (fallthrough)
branch  1 taken 92%
branch  2 taken 1% (fallthrough)
branch  3 taken 99%
   398895:   52:    if (c == '(' && state == 1) state = 2;
branch  0 taken 8% (fallthrough)
branch  1 taken 92%
branch  2 taken 1% (fallthrough)
branch  3 taken 99%
   398895:   53:    if (c == '{' && state == 2) state = 3;
branch  0 taken 8% (fallthrough)
branch  1 taken 92%
branch  2 taken 1% (fallthrough)
branch  3 taken 99%
   398895:   54:    if (c == ' '&& state == 3) state = 4;
branch  0 taken 8% (fallthrough)
branch  1 taken 92%
branch  2 taken 1% (fallthrough)
branch  3 taken 99%
   398895:   55:    if (c == 'a' && state == 4) state = 5;
branch  0 taken 8% (fallthrough)
branch  1 taken 92%
branch  2 taken 1% (fallthrough)
branch  3 taken 99%
   398895:   56:    if (c == 'x' && state == 5) state = 6;
branch  0 taken 8% (fallthrough)
branch  1 taken 92%
branch  2 taken 1% (fallthrough)
branch  3 taken 99%
   398895:   57:    if (c == '}' && state == 6) state = 7;
branch  0 taken 8% (fallthrough)
branch  1 taken 92%
branch  2 taken 1% (fallthrough)
branch  3 taken 99%
   398895:   58:    if (c == ')' && state == 7) state = 8;
branch  0 taken 8% (fallthrough)
branch  1 taken 92%
branch  2 taken 1% (fallthrough)
branch  3 taken 99%
   398895:   59:    if (c == ']' && state == 8) state = 9;
branch  0 taken 8% (fallthrough)
branch  1 taken 92%
branch  2 taken 1% (fallthrough)
branch  3 taken 99%
   398895:   60:    if (s[0] == 'r' && s[1] == 'e'
branch  0 taken 8% (fallthrough)
branch  1 taken 92%
branch  2 taken 8% (fallthrough)
branch  3 taken 92%
     2319:   61:       && s[2] == 's' && s[3] == 'e'
branch  0 taken 7% (fallthrough)
branch  1 taken 93%
branch  2 taken 7% (fallthrough)
branch  3 taken 93%
       11:   62:       && s[4] == 't' && s[5] == '\0'
branch  0 taken 9% (fallthrough)
branch  1 taken 91%
branch  2 taken 100% (fallthrough)
branch  3 taken 0%
        1:   63:       && state == 9)
branch  0 taken 100% (fallthrough)
branch  1 taken 0%
        -:   64:    {
        1:   65:      printf("error ");
call    0 returned 100%
        1:   66:      exit(200);
call    0 returned 0%
        -:   67:    }
   398894:   68:  }
        -:   69:}

*/
