using Gcov's statement coverage I get 33.81% of 562 lines and a branch coverage of 32.37% of 417 lines covered within
dominion. This is a fairly decent number as we only have 8 unit tests in total: 4 card tests and 4 function tests.

each of the unittests had around 10% statement coverage individually, with obvious overlap, which isnt bad. The overall coverage of dominion
is currently lacking as only a third of the branches have been executed. In actuality only a fourth of the branches have
been tested at least once, so dominion does more testing.

I did run into all of the bugs that I had created in addition to some possible bugs that may have been accidently introduced
when I did refactoring. Such as adventurer not removing itself from the hand. This was not one of my intended 4 required bugs
as I did not document it previously.

//Full output of dominion:
p3 ~/dominion 209% gcov -b dominion
File 'dominion.c'
Lines executed:33.81% of 562
Branches executed:32.37% of 417
Taken at least once:25.66% of 417
Calls executed:18.09% of 94
Creating 'dominion.c.gcov'


