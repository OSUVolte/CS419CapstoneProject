#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    char returnChar = ' ';
	int randomNumber = rand() % 14;
	
	switch (randomNumber)
	{
		case 0:
			returnChar = '[';
			break;
		case 1:
			returnChar = '(';
			break;
		case 2:
			returnChar = '{';
			break;
		case 3:
			returnChar = ' ';
			break;
		case 4:
			returnChar = 'a';
			break;
		case 5:
			returnChar = 'x';
			break;
		case 6:
			returnChar = '}';
			break;
		case 7:
			returnChar = ')';
			break;
		case 8:
			returnChar = ']';
			break;
		case 9:
			returnChar = 'r';
			break;
		case 10:
			returnChar = 'e';
			break;
		case 11:
			returnChar = 's';
			break;
		case 12:
			returnChar = 't';
			break;
		case 13:
			returnChar = '\0';
			break;
		default:
			break;
	}
    return returnChar;
}

char *inputString()
{
    char* returnString = malloc(sizeof(char) * 6);
	
	int i;
	for (i = 0; i < 6; i++)
	{
		returnString[i] = inputChar();
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
      printf("error ");
      exit(200);
    }
	
	free(s);
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
