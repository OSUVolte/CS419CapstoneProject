/******************************************************************************
** Filename: testme.c
** Test functions added by Emily Snyder
** Spring 2016
** CS 362-400
******************************************************************************/ 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // list all of the characters used in the function that needs to be tested
    char possibleChars[] = "[({ ax})]rest";

    // randomly select one of the desired characters
    int randomPos = rand() % strlen(possibleChars);
    char randomChar = possibleChars[randomPos];
    return randomChar;
}

char *inputString()
{
    // length of string used in the function that needs to be tested
    int length = 6; 
    int i;
    char *randString = (char*) malloc(sizeof(char) * length);
    // fill string with the randomly generated characters
    for (i = 0; i < length - 1; i++) {
      randString[i] = inputChar();
    }
    randString[i] = '\0';  // null terminate the string
    return randString;
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
