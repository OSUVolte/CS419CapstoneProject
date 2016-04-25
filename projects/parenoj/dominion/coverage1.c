/*

	Coverage for Tests:
	
	Overall, my dominion.c.gcov file shows that I had 36.79% statement coverage. This seems low, but I
	was only testing specific functions, so many things by this standard would not be executed. I could 
	increase this percentage, of course, by writing unit tests for more of the functions within the program.
	Branches executed are at 43.41% which is also low because I did not test everything. Therefore, let us look
	deeper into the specific functions that I did test in order to gain a better understanding of the gcov results:
	
	Functions:
	
	fullDeckCount: I had decent coverage in fullDeckCount. All branches were taken at least once except
	for the if statement checking the discard deck because my tests for this function never placed any
	cards in the discard deck. That would be a way to improve my coverage. 
	
	isGameOver: This function had 100% statement coverage. Also, every branch was taken at least once but
	I feel I could increase the coverage of some of the less-taken branches. 
	
	scoreFor: This function had only 74% statement coverage. This is because there were a lot of situations that
	I didn't include in my test because I feel if one test works, similar situations will also work. Some examples
	are: I didn't test curse cards or duchy cards, but I tested estates and provinces which is comparable. Therefore,
	this caused my statement and branch coverage to be lower, but again, it was for a valid reason.
	
	handCard: This function had 100% code coverage, and no branches. This function was very simple to test. I made
	a few different combinations of cards in hand, and tested handCard for each of those situations.
	
	
	Cards:
	
	adventurerCard: This function only has 67% statement coverage, and some of the branches are never executed.
	This actually illustrates a bug, because one of the if statements uses the assignment operator (=) instead of
	the comparison operator (==), so one branch is never executed. This leads to further branches never executing.
	Examining the coverage for this card definitely leads to some glaring bugs.
	
	smithyCard: This function has 71% statement coverage, but only one branch of the only branching statement is
	ever taken. This illustrates a bug, because the conditional in the for loop is incorrect. Just looking at the 
	coverage for this file can show the issue. What should be executed 3 times, is never executed. Seeing this coverage
	issue leads to finding a bug.
	
	great_hallCard: This function has 100% statement coverage, and no branches. This function was very easy to test
	because it is very straight-forward.
	
	cutpurseCard: This function has 68% statement coverage, and not every branch was covered. After looking at the gcov
	file, I realize this is because my test cases assumed that the oppenent would have a copper. I never looked into the 
	other branch, what if their hand did not have a cooper? Looking at the coverage show me this. 
	
*/