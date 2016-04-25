#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define INP_STR_LEN 6
typedef enum {false, true} bool;

char inputChar()
{
    //randomly determine which character to generate
    //only choose characters that are checked for/used in testme()
    //srand(time(NULL));
    //srand(0);
    int selector = rand() % 9;

    //determine which character has been randomly chosen
    char c;
    if (selector == 0) {
        c = '[';
    } else if (selector == 1) {
        c = '(';
    } else if (selector == 2) {
        c = '{';
    } else if (selector == 3) {
        c = ' ';
    } else if (selector == 4) {
        c = 'a';
    } else if (selector == 5) {
        c = 'x';
    } else if (selector == 6) {
        c = '}';
    } else if (selector == 7) {
        c = ')';
    } else if (selector == 8) {
        c = ']';
    } else {
        //something went wrong with random number. Should never hit this
	c = ' ';
    }

    return c;
}

char *inputString()
{
    int randomNum = rand() % 500;

    //Keep track of whether this function has been called previously
    //that way we don't keep allocating memory for the same string
    //static bool executed = false;
    char* returnString = (char*)malloc(INP_STR_LEN*sizeof(char));
    if (randomNum == 0) {
        returnString[0] = 'r';
	returnString[1] = 'e';
	returnString[2] = 's';
	returnString[3] = 'e';
	returnString[4] = 't';
	returnString[5] = '\0';
    } else {
        returnString[0] = (rand() % 26) + 97;
        returnString[1] = (rand() % 26) + 97;
        returnString[2] = (rand() % 26) + 97;
        returnString[3] = (rand() % 26) + 97;
        returnString[4] = (rand() % 26) + 97;
        returnString[5] = '\0';
    }
    return returnString;
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
      printf("error \n");
      exit(200);
    }
    free(s);
    s = 0;
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    //srand(0);
    testme();
    return 0;
}
