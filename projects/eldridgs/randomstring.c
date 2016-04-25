Susan Eldridge
CS362
Spring 2016
Random Testing Quiz

First, I added a random char generater that would encompass chars from 40 to 125.  This includes all
of the lower case letters as well as (), [] and {} which are all needed possibilities for the state
to change.  The state must be a 9 for the error to occur.

Next, the randomstring has to be able to contain at least 'r', 'e', 's', 't' and the terminating character null ('/0')
so here I filled the s array with only random lower case numbers (no brackets which were included before).

Eventually, the state will get to 9 (when the previous states have all been reached and the correct
char is found) and then when the random letters line up for the string, the error will be found.
