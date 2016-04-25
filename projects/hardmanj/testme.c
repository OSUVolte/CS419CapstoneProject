#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
	char inputchars[] = "[({ ax})]rest"	;	//All possible characters
    char randomchar = inputchars[rand() % strlen(inputchars)];	//grab random char from array
    return randomchar;
}

char *inputString()
{
    int i=0,length=6;	//Init i for For loop, and length of string to 6
	char *str = (char*) malloc(sizeof(char) * length);	//allocate string
	for (i=0; i<length-1; i++)
	{
		str[i] = inputChar();	//fill first 5 chars with random chars 
	}
	str[length-1] = '\0';	//set null terminator in last char of string
			
    return str;
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
