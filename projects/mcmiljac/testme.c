// Jake McMillen; mcmiljac@oregonstate.edu
// CS 362 - Quiz 2 (Random Testing)
// 24 April 2016

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

/*  Function: inputchar()
	Description: Generates a random integer in range 0-127 and returns corresponding ASCII char
*/
char inputChar()
{
    int c = rand() % 128;
	return (char) c; 
}

/*  Function: inputString()
	Description: Returns a pointer to a string of length 5 consisting of 5 random lowercase letters
*/
char *inputString()
{    
	static char s[6];
	int i;
	for (i = 0; i < 5; i++){
		s[i] = 'a' + rand() % 26;
	}
	s[5] = '\0';
    return s;	
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
