#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

/***********************************************
**  Function: inputChar()
**  Description: Returns a random ASCII char
**  between dec [32 to 127] )(i.e. Space to Del)
**  This will ensure that there is a chance to 
**  produce a random char that can advance there
**  test state.
************************************************/

char inputChar()
{
    // TODO: rewrite this function

    return (rand() % 95) + 32;
}


/***********************************************
**  Function: inputString()
**  Description: Returns a pseudo random string
**  NOTE: In order to make sure that the error 
**  could be reached in a feasible amount of time
**  the input was "adjusted" in order to increae
**  the probability that the returned random
**  string would contain the characters in the 
**  order r, e, s, e, t.  
************************************************/

char *inputString()
{
    // TODO: rewrite this function
	
	//inputString index
	int i;
	
	//pool index
	int pI;
	
	//declare inputString to produce string with indices [0 to 5]
	static char inputString[6];
	
	//create character pool with higher probability to yield r,e,s,e,t	
	char poolChars[16] = "testertesterABC";
		
		for (i = 0; i < 5; i++)
		{
			pI = rand() % 15;
			inputString[i] = poolChars[pI];
		}
		
		//add null terminator to c string
		inputString[5] = '\0';
	
    return inputString;
}


/***********************************************
**  Function: testme()
**  Description: Makes calls to inputChar() and
**  inputString().  As inputChar() returns chars
**  that match conditionals; the test state is 
**  advanced until state 9 if applicable.  When
**  the test state reaches state 9, a string 
**  "reset" will produce an error.
************************************************/

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
