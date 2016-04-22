/*******************************************************************************************
* Ben Fisher
* Quiz 2
* File randomstring.c
* 04/21/2016
*
* The random tester has 3 parts the Operation Profile, the Specification Oracle, and the Random Test Case Generator.
* 
* For the testme.c file the Operation Profile is the range of values in which the program operates, it defines the
* input space of values to be tested.  This was left for me to decide, and so I decided that the input space for calls to 
* the function inputChar would be ' ', 'a', 'x' '[', '{', '(', ']', '}', ')', and for the calls to the function 
* inputString the Operational Profile would be any combination of the characters 't', 'e', 's', 'e', 'r'.
* 
* The Specification Oracle judges the correctness of the test point, it defines pass
* fail of a test.  The specification oracle was provided to us in the function testme.  It returns an error when the 
* conditions are met where state = 9 and s = "reset".
*
* The Random Test Case Generator is responsible for generating random values to be tested in a test case.  The functions inputChar and
* inputString generate the random values.  Each call to inputChar returns a random char defined in the operational profile, and each
* call to inputString returns a string also defined in the operational profile.
*
* Code coverage: Examination of the testme.c.gcov file shows the program has 100% statement coverage and 92% block coverage.
* Line 37 is missed this line returns 0 if a char from the operation profile is not found in the switch statement in function inputChar, so I would
* not expect this line to execute.  Line 101 is also not executed (return 0 in main), but this line should never execute because 
* the exit function is called from the testme function.  In the testme function the branch coverage of lines 86, 87 88, and 89 is low.  The
* Lines are executed between 1 and 20 times, it would be better if these lines were executed  at a value in line with the other cases in the switch 
* statement (~200's).  It may be that the testme program needs to be run more times to get a better average or the random strings generated may need 
* to be modified to give a better random distribution.
 

        -:    0:Source:testme.c
        -:    0:Graph:testme.gcno
        -:    0:Data:testme.gcda
        -:    0:Runs:1
        -:    0:Programs:1
        -:    1:/***************************************************************************************
        -:    2:* Operational profile: in what range of values will the program operate, define the
        -:    3:* input space
        -:    4:* Specification oracle: Judges the correctness of the test point.  Defines pass
        -:    5:* fail of the test
        -:    6:* Random Test case generator: Responsible for generating the random tests
        -:    7:* **************************************************************************************/
        -:    8:
        -:    9:#include<stdio.h>
        -:   10:#include<string.h>
        -:   11:#include<stdlib.h>
        -:   12:#include<time.h>
        -:   13:
        -:   14:/*************************************
        -:   15: * Function will randomly return one
        -:   16: * of the characters from the switch
        -:   17: * statement
        -:   18: * Precondition: none
        -:   19: * Postcondition: char is returned
        -:   20: * ***********************************/
function inputChar called 242 returned 100% blocks executed 92%
      242:   21:char inputChar()
        -:   22:{
      242:   23:    int c = (rand() % 9) + 1;
call    0 returned 100%
        -:   24:	
      242:   25:	switch(c){
branch  0 taken 13%
branch  1 taken 10%
branch  2 taken 10%
branch  3 taken 12%
branch  4 taken 12%
branch  5 taken 8%
branch  6 taken 8%
branch  7 taken 13%
branch  8 taken 13%
branch  9 taken 0%
       31:   26:		case 1: return ' '; 		
       24:   27:		case 2: return 'a'; 
       25:   28:		case 3: return 'x'; 
       30:   29:		case 4: return '('; 
       29:   30:		case 5: return ')'; 
       20:   31:		case 6: return '['; 
       19:   32:		case 7: return ']'; 
       32:   33:		case 8: return '{'; 
       32:   34:		case 9: return '}'; 
        -:   35:	}
        -:   36: 
    #####:   37:    return 0;
        -:   38:}
        -:   39:
        -:   40:/***************************************************
        -:   41: * Function will randomly swap the characters of 
        -:   42: * the string passed in.
        -:   43: * Precondition: size is size of string
        -:   44: * Postcondition: string has had it's characters
        -:   45: * randomly swapped.
        -:   46: * ************************************************/
function inputString called 242 returned 100% blocks executed 100%
      242:   47:void inputString(char * test, const int SIZE)
        -:   48:{
      242:   49:	int i =0;
      242:   50:    int rNum = 0;
      242:   51:	char myChar = 0;
        -:   52:	
     1452:   53:    for(i = 0; i < SIZE; ++i){
branch  0 taken 83%
branch  1 taken 17% (fallthrough)
     1210:   54:		rNum = rand() % SIZE;       
call    0 returned 100%
     1210:   55:        myChar = test[i];
     1210:   56:		test[i] = test[rNum];
     1210:   57:        test[rNum] = myChar;
        -:   58:	}
      242:   59:}
        -:   60:
function testme called 1 returned 0% blocks executed 100%
        1:   61:void testme()
        -:   62:{
        -:   63:    
        1:   64:  int tcCount = 0;
        -:   65:  char c;
        1:   66:  int state = 0;
        1:   67:  char s [] = "teser";
        1:   68:  const int SIZE = strlen(s);
        -:   69:  while (1)
        -:   70:  {
      242:   71:    tcCount++;
      242:   72:    c = inputChar();
call    0 returned 100%
      242:   73:    inputString(s, SIZE);
call    0 returned 100%
      242:   74:    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);
call    0 returned 100%
        -:   75:
      242:   76:    if (c == '[' && state == 0) state = 1;
branch  0 taken 8% (fallthrough)
branch  1 taken 92%
branch  2 taken 5% (fallthrough)
branch  3 taken 95%
      242:   77:    if (c == '(' && state == 1) state = 2;
branch  0 taken 12% (fallthrough)
branch  1 taken 88%
branch  2 taken 3% (fallthrough)
branch  3 taken 97%
      242:   78:    if (c == '{' && state == 2) state = 3;
branch  0 taken 13% (fallthrough)
branch  1 taken 87%
branch  2 taken 3% (fallthrough)
branch  3 taken 97%
      242:   79:    if (c == ' '&& state == 3) state = 4;
branch  0 taken 13% (fallthrough)
branch  1 taken 87%
branch  2 taken 3% (fallthrough)
branch  3 taken 97%
      242:   80:    if (c == 'a' && state == 4) state = 5;
branch  0 taken 10% (fallthrough)
branch  1 taken 90%
branch  2 taken 4% (fallthrough)
branch  3 taken 96%
      242:   81:    if (c == 'x' && state == 5) state = 6;
branch  0 taken 10% (fallthrough)
branch  1 taken 90%
branch  2 taken 4% (fallthrough)
branch  3 taken 96%
      242:   82:    if (c == '}' && state == 6) state = 7;
branch  0 taken 13% (fallthrough)
branch  1 taken 87%
branch  2 taken 3% (fallthrough)
branch  3 taken 97%
      242:   83:    if (c == ')' && state == 7) state = 8;
branch  0 taken 12% (fallthrough)
branch  1 taken 88%
branch  2 taken 3% (fallthrough)
branch  3 taken 97%
      242:   84:    if (c == ']' && state == 8) state = 9;
branch  0 taken 8% (fallthrough)
branch  1 taken 92%
branch  2 taken 5% (fallthrough)
branch  3 taken 95%
      242:   85:    if (s[0] == 'r' && s[1] == 'e'
branch  0 taken 17% (fallthrough)
branch  1 taken 83%
branch  2 taken 50% (fallthrough)
branch  3 taken 50%
       20:   86:       && s[2] == 's' && s[3] == 'e'
branch  0 taken 40% (fallthrough)
branch  1 taken 60%
branch  2 taken 25% (fallthrough)
branch  3 taken 75%
        2:   87:       && s[4] == 't' && s[5] == '\0'
branch  0 taken 100% (fallthrough)
branch  1 taken 0%
branch  2 taken 100% (fallthrough)
branch  3 taken 0%
        2:   88:       && state == 9)
branch  0 taken 50% (fallthrough)
branch  1 taken 50%
        -:   89:    {
        1:   90:      printf("error ");
call    0 returned 100%
        1:   91:      exit(200);
call    0 returned 0%
        -:   92:    }
      241:   93:  }
        -:   94:}
        -:   95:
        -:   96:
function main called 1 returned 0% blocks executed 80%
        1:   97:int main(int argc, char *argv[])
        -:   98:{
        1:   99:    srand(time(NULL));
call    0 returned 100%
call    1 returned 100%
        1:  100:    testme();
call    0 returned 0%
    #####:  101:    return 0;
        -:  102:} 