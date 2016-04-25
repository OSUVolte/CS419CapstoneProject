/***************************************************************************************
* Operational profile: in what range of values will the program operate, define the
* input space
* Specification oracle: Judges the correctness of the test point.  Defines pass
* fail of the test
* Random Test case generator: Responsible for generating the random tests
* **************************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

/*************************************
 * Function will randomly return one
 * of the characters from the switch
 * statement
 * Precondition: none
 * Postcondition: char is returned
 * ***********************************/
char inputChar()
{
    int c = (rand() % 9) + 1;
	
	switch(c){
		case 1: return ' '; 		
		case 2: return 'a'; 
		case 3: return 'x'; 
		case 4: return '('; 
		case 5: return ')'; 
		case 6: return '['; 
		case 7: return ']'; 
		case 8: return '{'; 
		case 9: return '}'; 
	}
 
    return 0;
}

/***************************************************
 * Function will randomly swap the characters of 
 * the string passed in.
 * Precondition: size is size of string
 * Postcondition: string has had it's characters
 * randomly swapped.
 * ************************************************/
void inputString(char * test, const int SIZE)
{
	int i =0;
    int rNum = 0;
	char myChar = 0;
	
    for(i = 0; i < SIZE; ++i){
		rNum = rand() % SIZE;       
        myChar = test[i];
		test[i] = test[rNum];
        test[rNum] = myChar;
	}
}

void testme()
{
    
  int tcCount = 0;
  char c;
  int state = 0;
  char s [] = "teser";
  const int SIZE = strlen(s);
  while (1)
  {
    tcCount++;
    c = inputChar();
    inputString(s, SIZE);
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
