#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
	int random;
	int gate = rand() % 20;		//to test out unexpected values
	if(gate == 1)
		random = rand() % 512;
	else
		random = rand() % (127 - 32) + 32;
	char out = (char)random;
	return out;
}
char *inputString()
{
	int luck = 0;
	int limit = rand() % 64 + 1;
	int len = rand() % limit + 1;
//	len = 6; 	//with this restriction it produces 735,091,890,625 outcomes. without it (127-32) ^ 64
	luck = 0;	// change this number to increase the luck of finding the error 0 to 6
	char * out = malloc(sizeof(char) * len);
	for(int i = 0; i < len-1; i++)
	{
		out[i] = inputChar();
	}
	// without this it will take a very very very long time but it eventually finds it.I tested it on flip
	// it took days and millions of attempts  but it found it
	switch (luck)
	{
		case 6:
			out[5] = '\0';
		case 5:
			out[4] = 't';
		case 4:
			out[3] = 'e';
		case 3:
			out[2] = 's';
		case 2:
			out[1] = 'e';
		case 1:
			out[0] = 'r';
		default:
			break;
	}
	out[len-1] = '\0';
	return out;
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
