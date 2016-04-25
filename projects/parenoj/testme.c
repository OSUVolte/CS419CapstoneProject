#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

/*
 * I've made this very loose. I've had it run for over 1 million iterations, 
 * but it always eventually finds the error by outputting "reset".
 *
 * It might take awhile, but I think it is worth it for range testing
 */


char inputChar()
{
	//This will give a random  ascii values 0 - 127
	char v = rand() % 128;
   
    return v;
}

char *inputString()
{
    //This will assign a random ascii value between 101 and 116 to the first 5 characters with the 6th character being null to terminate the string
    //(101 - 116) because this encompasses all of the lower cases letters of reset
    static char w[6];
    int i = 0;
    w[5] = '\0';
    for(i; i<5; i++)
    {
    	w[i] = rand() % 16 + 101;
    }
    //I intially had this just return "reset" but that was no fun.
    return w;
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

