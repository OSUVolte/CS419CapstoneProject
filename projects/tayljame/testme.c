/**************
Author: James Taylor
Date: 10/25/15
Updated: 4/24/16

**************/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>





char inputChar()
{

int numC;
char c;
//char subSet [9] = {'[', '(', '{', ' ', 'a', 'x', '}', ')', ']'};
//random block to include all ascii characters between 32-125
    numC = rand()%95 + 32;
    c = (char) numC;
//random block for small array for only tested values, random number generates array index to test
//    numC = rand() % 9;
//    c = subSet[numC];

return c;

}

char *inputString()
{

//char arrayString[6] = {'r', 'e', 's', 'e', 't', '\0'};
char arrayString[6];
int i;

for (i=0; i < 5; i++)
    {

    arrayString[i] = (rand() % 26) + 97;

    }
      arrayString[5] = '\0';
    return arrayString;

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