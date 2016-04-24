/***************************************************************************
** Author: James Pool
** ONID: 932664412
** OSU Email: poolj@oregonstate.edu
** Date: 23 April 2016
**
** Program Filename: testme.c
** Description: This is the source file for Quiz 2: Random Testing. The 
**				functions inputChar() and inputString() were implemented
**				to produce random values.
**
** Note: The ASCII range for printable characters is 0x20 (decimal 32) to
**		 0x7E (decimal 126). C strings also always require a null terminator
**		'\0' therefore the final value for inputString(), randomString[5],
**		must always be the null terminator.
***************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
	/* Return a random character */
	return (char)(rand() % (127 - 32) + 32);  /* Range: 32 to 126 (All ASCII characters) */
}

char *inputString()
{
	char* randomString;
	randomString = (char *)malloc(6);  /* Allocate space for random string */

	if ((rand() % 1000) == 0) {  /* 0.1% chance of sending reset */
		randomString[0] = 'r';
		randomString[1] = 'e';
		randomString[2] = 's';
		randomString[3] = 'e';
		randomString[4] = 't';
	}
	else {
		for (int i = 0; i < 5; i++) {
			randomString[i] = inputChar();  /* Get random printable character */
		}
	}

	randomString[5] = '\0';
    return randomString;
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