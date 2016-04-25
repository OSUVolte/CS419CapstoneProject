/********************************
Author: Luke Brewbaker
Date:  4/20/16
Modified: 4/20/16
File: testme.c

Overview:
Rewrite the inputChar() and inputString() functions so that main will return the error


*******************************/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // For this i'll return a random char from a set of ascii codes. The list found here: http://www.ascii-code.com/. I start at character 33, which is an !, rather than 32 which is a black space.  It should end at character 126, which is the ~ key.
	
    return (rand() % 95) +32;
}

char *inputString()
{
	// define variables
    static char testString[6];
	int temp;
	char alpha[6] = "reset";
	
	// What this will do is check if testString is 5 chars long, because the 6th will have to be the \0 character.  Loop will create a random int, which will be used to point to that location in the array.
	for(int x = 0; x < 5; x++){
		temp = rand() % 5;
		testString[x] = alpha[temp];
		
	}
	
	testString[5] = '\0';
	return testString;
    
}

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
      printf("error \n ");
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
