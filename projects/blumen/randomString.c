Nathalie Blume
Quiz 2

1. Code examination: Inside an infinite while-loop, a random character and a random string are generated. These values
together with the value (so far) of a variable "state" are printed. The character must take on a specific non-consecutive
succesion of values ('[', '(', '{', ' ', 'a', 'x', '}', ')', ']') to allow "state" to progress incrementally from value 1
to value 9. Only once "state" = 9 is the random string tested. When the random string reads "reset\0" then the error is
printed.

2. The main hurdle in writing the random selectors was deciding what character and string pools the random values should
be drawn from. No information about the user/usual source of input was available. I only knew that the pool of characters
must include '[', '(', '{', ' ', 'a', 'x', '}', ')', ']' and that the pool of words must include 'reset\0'. Boundary
conditions may include 'reset' (no \0) and capital A, X. The main constraint on choosing a pool was computational complexity/
time to find the error.

3. For inputChar(), I chose for as my sampling population all ASCII printable characters (character code 32-127).

4. For inputString(), I considered generating random strings of lengths 0-20 from all ASCII printable characters. However
the number of possible combinations was enormous, and one one of these combinations ('reset\0') produced the error. I considered
limiting word length to the set {0, 4, 5, 6, 10} and the character population to [A-z] but still my computer could have run the
program for days before completing. So I elected to generate random strings of 5 characters from the [a-z] set, plus "\0".
There were 9765626 character combinations to test.

6. I coded the random character generator using the decimal values of the characters and a simple if imperfect random generator.
(I was not looking for fair odds but for good coverage of the character pool across many iterations).

7. I ran the program once and found the error in about 45 minutes. With more time and/or computational power I would try
a broader word population. I would also look for information on the regular input source to see if I could limit the
word population in some reasonable way.
