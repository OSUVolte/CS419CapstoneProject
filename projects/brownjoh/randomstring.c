//John Brown  CS_362_400_S2016
// Quiz 2

/*

To implement the random testing, I chose a brute force approach.
Rather than picking interesting values (smaller set  that includes the target
value)  I had my char value choose randomly from any printable character and
the random string to be  randomly generated from a-z 5 legnth strings.  The
char condition was met much more quickly.  Even though the char had many more
characters to choose from and needed 9 matches, there was no combination of
successes needed, while for the string, we are basically  trying to guess the
5 letter word using random letters.  Error condition was met actually a little
quicker than I assumed it would statistically  speaking, but I only attempted
the one triggering.  It would be interesting to see how much the timing may
vary after several  runs.  It took a total of 1,280,727 iterations to trigger
the error and 408.544 seconds or a little under 7 minutes.  The randomness of
the  functions was implemented using simple char arithmetic moded over the
range of characters selected.  It is interesting to think that  I truly did
use random printable characters and if the combination of characters truly did
represent an error, this random test would  absoultely have uncovered it.  The
would have happened without even knowing what the triggering combination was.



*/