#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char retString[6];
char ARRAYSET[10] = {'[','(','{',' ','a','x','}',')',']'};

char inputChar()
{
	char resultChar;
	int randNum;

	randNum = 9 * (rand() / (RAND_MAX + 1.0));
	resultChar = (char) randNum;

    return ARRAYSET[randNum];
}

char *inputString()
{
	int randNum, i;
	char value;
	int length = 6;

	for(i = 0; i < 5; i++)
	{
		randNum = 16 * (rand() / (RAND_MAX + 1.0));
		randNum = randNum + 101;
		value = (char) randNum;
		retString[i] = value;
	}

	retString[5] = '\0';

    return retString;
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
    /*if(tcCount % 100000 == 0) {
        printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);
        printf("%s \n", s);
    }*/
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' ' && state == 3) state = 4;
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
      /*printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);
      printf("%s \n", s);*/
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
