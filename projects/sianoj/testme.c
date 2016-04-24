#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function
	//create a list of choices for the letter c
	char choicesForC[9] = {'[', '(', '{', ' ', 'a', 'x', '}', ')', ']'}; 
	//pick a random index
	int randIndex = rand() % 9;
	//return the character at the random index
	return choicesForC[randIndex];
}

char *inputString()
{
    // TODO: rewrite this function
	//create a list of the valid characters for s
	char choicesForS[4] = {'r', 'e', 's', 't'};
	
	//create a string that will have the potential to become the reset string
	char* outputString = malloc(6*sizeof(char));
	
	//populate the output string with values from choices for s
	int i, randIndex;
	for(i = 0; i < 5; i++){
		//pick a random index from choices for s
		randIndex = rand() % 4;
		//populate the thing at that random value in to the output string
		outputString[i] = choicesForS[randIndex];
	}

	//put the null terminator at the end of the string
	outputString[5] = '\0';

	//return the output string
	return outputString;
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
