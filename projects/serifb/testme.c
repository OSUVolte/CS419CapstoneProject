#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
<<<<<<< HEAD
	// create am array ffor the random chars
    char ch[] = "abcdefghijklmnopqrstuvwxyz [](){}";
	//generate a random int based on the length of the ch array
	int randInt = rand() % strlen(ch);
	
	//return the char array value as ddenoted by the rand int
=======
	char ch[] = { '[', ']', '{', '}', '(', ')', ' ', 'a'. 'x' };
	int randInt = rand() % sizeof(ch);

>>>>>>> origin/master
	return ch[randInt];
}

char *inputString()
{
<<<<<<< HEAD
    
=======
	char ch[] = { 'r', 'e', 's', 'e', 't'};
	char *s = (char*)malloc(sizeof(char));
	int i;

	for (i = 0; i < 5; i++)
	{
		s[i] = ch[rand() % sizeof(ch)];
	}

	s[5] = '\0';

	return s;
>>>>>>> origin/master
}

void testme()
{
<<<<<<< HEAD
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
=======
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
>>>>>>> origin/master
}


int main(int argc, char *argv[])
{
<<<<<<< HEAD
    srand(time(NULL));
    testme();
    return 0;
=======
	srand(time(NULL));
	testme();
	return 0;
>>>>>>> origin/master
}