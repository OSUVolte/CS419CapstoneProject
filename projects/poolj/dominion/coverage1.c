/***************************************************************************
** Author: James Pool
** ONID: 932664412
** OSU Email: poolj@oregonstate.edu
** Date: 24 April 2016
**
** Program Filename: coverage1.c
** Description: This is the report file for coverage results from performing
**				the unit tests and card tests.
***************************************************************************/

Coverage Results for Unit Tests:
unittest1.c - Lines executed:85.71% of 28; Branches executed:100.00% of 8; Taken at least once:62.50% of 8; Calls executed:78.57% of 14
unittest2.c - Lines executed:77.78% of 63; Branches executed:100.00% of 20; Taken at least once:55.00% of 20; Calls executed:71.43% of 28
unittest3.c - Lines executed:89.80% of 98; Branches executed:100.00% of 32; Taken at least once:78.13% of 32; Calls executed:86.11% of 36
unittest4.c - Lines executed:80.30% of 66; Branches executed:78.26% of 23; Taken at least once:60.87% of 23; Calls executed:84.62% of 26

Coverage for dominion.c under Unit Tests:
	Lines executed:16.64% to 27.37% of 559;
	Branches executed:15.83% to 38.37% of 417;
	Taken at least once:12.95% to 27.34% of 417;
	Calls executed:8.42% to 16.84% of 95;

Coverage Results for Card Tests:
cardtest1.c - Lines executed:72.34% of 141; Branches executed:92.86% of 56; Taken at least once:55.36% of 56; Calls executed:67.50% of 40
cardtest2.c - Lines executed:72.34% of 141; Branches executed:92.86% of 56; Taken at least once:55.36% of 56; Calls executed:67.50% of 40
cardtest3.c - Lines executed:72.34% of 141; Branches executed:92.86% of 56; Taken at least once:55.36% of 56; Calls executed:67.50% of 40
cardtest4.c - Lines executed:74.13% of 143; Branches executed:92.86% of 56; Taken at least once:55.36% of 56; Calls executed:67.50% of 40

Coverage for dominion.c under Card Tests:
	Lines executed:31.66% to 40.07% of 559
	Branches executed:45.80% to 51.08% of 417
	Taken at least once:29.02% to 34.53% of 417
	Calls executed:21.05% to 34.74% of 95

Analysis:
As expected the branch coverage for both the unit tests and card tests reached a very high level. The exception is in unittest4, where the reduced
number of brachnes is from a helper function (getCardString) not being used, but still in the code. This high level of branch coverage indicates
that all or almost all of the tests are ran during execution. The coverage resutls for dominion also refect the nature of this testing, with 
lower values for the unit tests (which only test a small function) and higher coverage for the card tests (which implement a larger portion of code).
Since the entire extent of the player's turn is not executed, it makes sence that the amount of coverage is in this range.