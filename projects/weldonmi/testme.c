#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function
    //return ' ';

	/*
	1ST AND 2ND DRAFT

	int bias, value = rand() % 9;
	//printf("%d ", value);

	//tested against 5 because this gave the most even
	//distrubution among the numbers tested, can be
	//changed to another if different bias is desired
	if(bias < 5)
		value = rand() % 9;

	if(value == 0)
		return '[';
	else if(value == 1)
		return '(';
	else if(value == 2)
		return '{';
	else if(value == 3)
		return ' ';
	else if(value == 4)
		return 'a';
	else if(value == 5)
		return 'x';
	else if(value == 6)
		return '}';
	else if(value == 7)
		return ')';
	else if(value == 8)
		return ']';
	*/

	//3RD DRAFT
	//ASCII range includes punctuation and special characters
	int startASCII = 32;
	int endASCII = 95;

	return (char) ((rand() % endASCII) + startASCII);
}

char *inputString()
{
    // TODO: rewrite this function

	//1ST-3RD DRAFT, used to focus efforts on inputChar()
	//directly returns the phrase required to exit, not random
	//return "reset\0";

	//4TH DRAFT
	//5 is the number required to be able to send the word
	//"reset\0" into testme(), should not be changed as
	//final null character in s[5] is needed
	int value, outputSize = 5;
	char *validChars = "reset";
	char *output = malloc(sizeof(char) * outputSize);

	int i;
	for(i = 0; i < outputSize; i++){
		value = rand () % strlen(validChars);
		output[i] = validChars[value];
	}

	return output;
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
