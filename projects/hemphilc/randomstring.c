/* Corey Hemphill
 * hemphilc@oregonstate.edu
 * CS362_400 - Software Engineering II
 * Quiz II
 * April 24, 2016
 * randomstring.c
 */

/* ---------------------------------------------------------------------------------
The inputChar() function simply take the lowest character in the domain, the
' ' char, and adds a random value modded by 94 to cover the valid domain (' ' 
through '}') of characters that the testme() function is trying to find in 
order to advance its state. This function is about as straightforward as they 
get.

char inputChar() {
	return ' ' + (rand() % 94);
}
--------------------------------------------------------------------------------- */


/* ---------------------------------------------------------------------------------
The inputString() function is a little less straigtforward than inputChar(),
but still very simple. The main difference is that the domain of characters
is far less ('r', 'e', 's', 't'). The scope of the randomity of this function
was not clearly specified, so rather than test for permutations of all of the
letters and chars to get the string "reset", (which takes absolutely forever
in most cases), the function grabs random 5 letter permutations of the letters 
'r', 'e', 's', and 't' until it happens to snag the string "reset".

char *inputString() {
	int i;
	char c;
	char *s = malloc(6 * sizeof(char));
	char str[] = "rest";
	for(i = 0; i < 5; i++) {
		c = str[rand() % 4];
		s[i] = c;
	}
	s[6] = '\0';
	return s;
}
--------------------------------------------------------------------------------- */

