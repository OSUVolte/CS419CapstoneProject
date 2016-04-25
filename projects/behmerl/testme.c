#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>


char inputChar()
{
    // TODO: rewrite this function

   //This has an array of various values 
   //that is randomly selected a value to be 
   //passed in for the function
	char randVal;
	//initializing random num
	int randNum;
	time_t t;
//	char str1[34] = "abcdefghijklmnopqrstuvwxyz[]() {}";
	char str1[34] = "abcdefghijklmnopqrstuvwxyz[]() {}";
	srand((unsigned) time(&t));
	randNum=rand() % 34;
	randVal = str1[randNum];
         return randVal;
}

 char *inputString()
{
    // TODO: rewrite this function
    typedef char * string;
    char*  randStr;
    string str[6];
    //initializing random num	
    int randNum;
    time_t t;

    str[0] = "reset";
    str[1] = "hello";
    str[2] = "third";
    str[3] = "sword";
    str[4] = "walks";
    str[5] = "moons";
    //setting up a random number generator to 
    //get the different strings in the array of 
    //strings 
    srand((unsigned) time(&t));
    randNum=rand() % 6;
    randStr = str[randNum];
    return randStr;
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

