#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
	// i need '[]' , '()' , '{}' , ' ' , 'a' , 'x'
	char *characters = "[](){} ax";
    int r = rand() % 9;
    return characters[r];
}

char *inputString()
{
	//i need to jumble characters around until i get reset
    char characters[] = "etrse";
	char* container = (char*)calloc(strlen(characters)+1, sizeof(char)); //reset allocated memory to zero
	int r; //random number generated
	char startPlaceholder; char endPlaceholder;
	int i;
	int size = strlen(characters)-1; //printf("size of characters: %d\n", strlen(characters));
	//go from 0 to 4
	while(size != 0){ //printf("	size: %d\n", size);
		r = rand() % size; //get random number between 0 and 4 printf("r: %d\n", r);
		//switch place with random generated letter
		startPlaceholder = characters[r];
		endPlaceholder = characters[size]; //hold last letter //printf("characters[r]: %c\n", characters[r]); printf("characters[size]: %c\n", characters[size]);		
		characters[r] = endPlaceholder; 
		characters[size] = startPlaceholder; //printf("characters[r]: %c\n", characters[r]); printf("characters[size]: %c\n", characters[size]);
		//move move index down
		size--; //printf("CHARACTERS: %s\n", characters);
	}
	//copy over string
	for(i = 0; i < strlen(characters); i++) { //printf("i: %d\n", i);
        container[i] = characters[i];
    }

    return container;
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
	  free(s); //the way the function was written, need to free memory
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}