#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>


char inputChar()
{
    // TODO: rewrite this function
    
    time_t t;
    srand((unsigned) time(&t));
    char random = "[({ ax})]"[rand() % 9];
    
    /*
    char random;
    
    for (int i = 0; i < 9; i++)
    {
    
    	random = "[({ ax})]"[i];
    
    }
    
    */
    
    return random;
}

char *inputString()
{
    // TODO: rewrite this function
    
    //reset\0
    
    //char chars[] = 
    
    
    /*
    char characters[] = "reset";
    char *string = (char*)( malloc(6*sizeof(char)));
    for (int i = 0; i < 5; ++i)
    {
    
    	string[i] = characters[rand() % 5];
    	
    }
    string[5] = 0;
    return string;
    */
    
    
    char characters1[] = "rrr";
    char characters2[] = "ebi";
    char characters3[] = "sss";
    char characters4[] = "emj";
    char characters5[] = "txn";
    char *string = (char*)(malloc(6*sizeof(char)));
    int i = 0;
    for (i = 0; i < 5; i++)
    {
    	if (i == 0)
    	{
    		string[i] = characters1[rand() % 3];
    	}
    	if (i == 1)
    	{
    		string[i] = characters2[rand() % 3];
    	}
    	if (i == 2)
    	{
    		string[i] = characters3[rand() % 3];
    	}
    	if (i == 3)
    	{
    		string[i] = characters4[rand() % 3];
    	}
    	if (i == 4)
    	{
    		string[i] = characters5[rand() % 3];
    	}
    	
    	
    	
    }
    string[5] = 0;
    return string;
    
    
     //return "reset\0";
    
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
    
    //char c1 = inputChar();
    
    //char *c = inputString();
    
    return 0;
}