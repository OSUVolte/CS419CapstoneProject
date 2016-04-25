/***********************************
* Name: Trent Richardson
* Random Testing Quiz 2 - testme.c
* CS362-400
* ASCII assistance: http://www.theasciicode.com.ar/ascii-printable-characters/capital-letter-z-uppercase-ascii-code-90.html
***********************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    char ch;

     ch = rand() % (126 + 1 - 32) + 32; //return a random ASCII character

    return ch;
}

char *inputString()
{
    char *string = (char*)malloc(sizeof(char) * 6); //allocate 5 letter string and null terminator
     char ch;

     int i;
     for (i = 0; i < 5; i++)
     {
          ch = rand() % (122 + 1 - 97) + 97; //return a random ASCII character (lowercase letters)
          string[i] = ch;
     }

     string[5] = '\0'; //set last one to the null terminator

    return string;
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
