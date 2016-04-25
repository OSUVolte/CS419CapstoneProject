/*********************************************************************************************
 * Developer: Nick Martin (martinn6)
 * Date: 20160422
 * Project: Quiz 2
 * Description:  
 * *******************************************************************************************/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function
	// printf("%d\n", '[');
	// printf("%d\n", '(');
	// printf("%d\n", '{');
	// printf("%d\n", ' ');
	// printf("%d\n", 'a');
	// printf("%d\n", 'x');
	// printf("%d\n", '}');
	// printf("%d\n", ')');
	// printf("%d\n", ']');

	int chars[9];
	chars[0] = 32;
	chars[1] = 40;
	chars[2] = 41;
	chars[3] = 91;
	chars[4] = 93;
	chars[5] = 97;
	chars[6] = 120;
	chars[7] = 123;
	chars[8] = 125;
	int rand = (random() % 9);
	char randomletter = (char)chars[rand];
    return randomletter;
}

char *inputString()
{
	// TODO: rewrite this function
	int chars[5];
	int rand;
	char randomletter;
	char s[5];
	chars[0] = 0; //\0
	chars[1] = 101; //e
	chars[2] = 114; //r
	chars[3] = 115; //s
	chars[4] = 116; //t
	
	for(int x=0; x<5; x++)	
	{
		rand = (random() % 5);
		randomletter = (char)chars[rand];
		s[x] = randomletter;
    }
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
