/* created by James Guerra for random quiz 2. see randomstring.c for rest of quiz. 
program randomly generates chars, and a random string of chars, 
before testing them in an infintie loop until a very specific 
sequence of randomly generated chars occurs*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // function to generate random characters
	int randNum = rand() % 128; //generates random number between 0 and 127
	char randChar = (char) randNum; //assigns char value based on the int generated
	
    return randChar;
}

char *inputString()
{
    char *randString;
	char array[5];
	for(int i =0; i<= 4; i++){ //assigns random chars to  string array
		array[i] = inputChar(); 
	}
	array[5] = '/0';   //end string  
	randString = array; //creates pointer to array for returning purposes
    return randString;
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