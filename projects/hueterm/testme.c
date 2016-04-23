/************************************************************************
Michael Hueter (hueterm@oregonstate.edu)
CS 362 Random Testing Quiz 2
23 April 2016
**************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

/************************************************************************
  function: inputChar()
  description: Generate a pseudo-random character.
  params: none
  returns: A random ASCII character from the list of 43 below
**************************************************************************/
char inputChar()
{
    // generate a pseudo-random character from this list of 43 ASCII values
    char randomCharacter = "abcdefghijklmnopqrstuvwxyz0123456789([{}]) "[random () % 43];
    return randomCharacter;
}
/************************************************************************
  function: inputString()
  description: Generate a pseudo-random string (6 character array).
  params: none
  returns: A 5 letter string with the last 4 letters random.
**************************************************************************/
char *inputString()
{
    char *randomString = malloc(sizeof(char) * 6);
    int x = 0;

    randomString[0] = 'r';
    // call inputChar() to generate random characters for letters 4 and 5
    for (x = 1; x < 5; x++){
      randomString[x] = inputChar();
    }

    randomString[5] = '\0'; // null terminate the string

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
    };
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
