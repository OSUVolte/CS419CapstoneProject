#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function
	
	int randInt = rand() % 11;
	char randChar;
	
	if (randInt == 0) randChar = '[';
	if (randInt == 1) randChar = ']';
	if (randInt == 2) randChar = '(';
	if (randInt == 3) randChar = ')';
	if (randInt == 4) randChar = '{';
	if (randInt == 5) randChar = '}';
	if (randInt == 6) randChar = ' ';
	if (randInt == 7) randChar = 'a';
	if (randInt == 8) randChar = 'x';
	if (randInt == 9) randChar = '$';
	if (randInt == 10) randChar = '#';
	
    return randChar;
}

char *inputString()
{
    // TODO: rewrite this function
	
	int randInt = rand() % 3;
	char *randStr;
	
	if (randInt == 0) randStr = "continue\0";
	if (randInt == 1) randStr = "change\0";
	if (randInt == 2) randStr = "reset\0";
	
    return randStr;
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
