Coverage:

unittest1: shuffle()
	Unit test 1 is showing line coverage of 71%. This is pretty good considering
	there are a lot of conditions that shouldn't be met by the code. This
	leaves some code lines that shouldn't run when the code works correctly.
	95% of the branches were covered though, which is strange. This seems very
	high since a lot of the branches are supposed to go false. This may indicate
	my tests aren't very good.

	Looking at the dominion file for the coverage of shuffle it says that the
	block coverage in the function is 100%, 100% of the function calls for the
	39 function calls my test makes. Every branch was taken at least once,
	and the lines were all run a good number of times excepting the few
	boundary conditions in the functions (deck = 0).

	This is a pretty good indicator that my test is getting into the right areas
	but if the tests aren't interpreted right, I could still be making false
	conclusions. I have a feeling something in shuffle isn't right more than
	I've found, I just haven't been able to find it yet.

unittest2: fullDeckCount()
	Unit test 2 is showing line coverage of 86.6% of the lines. This is also
	pretty good for the same reason as before. Many of the test conditions
	are not supposed to run because its expected to be good. So in this case
	the higher values are a good clue that either my tests are testing wrong
	and executing too much of my code, or that a lot is wrong with
	fullDeckCount(). 100% of the branches were covered in this unit test...
	I don't think that's a good sign for my tests. My test should have some
	unrun branches because there should be some false conditions in there
	somewhere...

	The block coverage in dominion.c is 100%, 100% of the calls. Every branch
	had coverage, and every line was covered plenty of times.

	I didn't find any bugs in this particular code, but just because I've
	covered a lot doesn't mean I didn't miss any. Just looking at the code
	it looks correct though, so I feel good that I didn't miss anything.

unittest3: isGameOver()
	Unit test 3 is showing line coverage of 84% in the unit test file. Every
	branch was tested again, which is strange again. Another possible bad sign.

	In dominion.c 100% of the blocks were executed 100% of the 25 calls. This
	is a good sign. Although my unit test may not be checking enough stuff,
	the code is all being run. This is further confirmed by the fact that every
	branch was taken, and every line was run.

	If I checked more conditions in the unit test I think I would uncover more
	information. I think that's how I would improve this particular test suite.

unittest4: discardCard()
	Unit test 4 is showing 53% of my lines covered in the test. At this point
	I had gotten my bearings on how I wanted to test, and I think this number
	indicates it well. There were many more conditions being explicitly checked
	meaning that there would be way more lines not executed. 69% of the branches
	were taken so I think that's a good sign on the test side.

	In dominion.c 100% of the blocks were executed 89% of the time. This is
	pretty good coverage especially since I noticed the redundant code. The
	redundant condition is confirmed by the fact that even though I have tests
	set up to access the "last card in hand" branch, it wasn't run a single
	time. The rest of the branches had 100% coverage though if you exclude that
	branch which is a sign of decent tests.

	I found quite a few issues with this code not doing what it was supposed to
	do, and the increased specificity of my tests would probably uncover more
	issues as the code was patched. This was the first unit test that felt like
	I knew what I was doing.

cardtest1: adventurerCard()
	Card test 1 is showing line coverage of 80%, with branch coverage of 86%.
	This is getting back towards the poor indicators that too many branches
	are being covered. This was my first time figuring out how to test the card
	functions, and was particularly strange because I had intetnionally put a
	bug in the code like 2 weeks ago. I had to work through the mental block
	that I was testing for what the card was supposed to do, not what it was
	doing (although that still helps).

	In dominion.c, the card has 100% block coverage 80% of the time. The
	branches aren't all covered but I left out a couple branches when I chose
	to only use copper as my test treasure. I could test silver and gold further
	but I stuck to copper since all the conditional checks were the same.
	Looking at the branch coverage and lines run, I'm beginning to see some
	that aren't covered. This is strange because I tried to access those lines,
	but the bug I introduced in the function makes them inaccessible by
	throwing an infinite loop if I try to access those lines. This is not ideal
	but if I fixed the bugs I believe my tests would reach those locations.

	All in all this was a tough test. I could have done a lot better, but
	remembering I need to test expected outcome and not just what's going on
	was a tough mental change.

cardtest2: smithyCard()
	Card test 2 is showing line coverage of 69%. This is more inline with what
	I would hope for. 71% of the branches are executed, which is a better
	balance than card test 1. I think I was getting my focus back in this test
	and I had more specific checks.

	In dominion.c the card has 100% block coverage 100% of the time. The
	branches are all covered as well which is a good sign. I know what the bug
	I introduced was, and it isn't particularly inhibitive of coverage. It does,
	however throw the whole outcome out of whack.

	This test found a lot of issues with the smithy card as written. I think the
	percentages are a good indicator this was one of my better unit tests. The
	coverage is good in dominion, and the test isn't near 100% covered. If I
	look at the outcomes, the smithy card didn't pass a single test either. I
	could still improve the test suite but this was the first one that really
	established what the card was supposed to do in the test.

cardtest3: villageCard()
	Card test 3 is showing line coverage of 72%. This is close to smithy, and
	with a branch coverage of 76% is still a pretty good indicator that I had
	a lot of conditional checks.

	In dominion.c, there was 100% block coverage every time. This was to be
	expected because its such a short function without conditions. The one
	branch was covered and every line was run several times.

	This test came down to the outcomes more than coverage. Coverage doesn't
	mean much in a test that doesn't have conditions. The unit test in this
	case shows how many things I was checking for having no branches in the
	actual function though. This is a sign that probably some good testing was
	going on.

cardtest4: stewardCard()
	Card test 4 is showing line coverage of 70%, and 81% branch coverage. This
	is getting pretty high on the branch coverage but the steward card was a lot
	harder to create a bunch of conditionals for. I called it several times
	with the different action choices, so it was a lot to test for. I really am
	surprised that there were 81% of the branches covered. I believed I had
	many more tests than that.

	The dominion.c coverage is actually pretty bad compared to what I expected.
	There was 100% block coverage in 60% of the calls, and several key branches
	were missed. Upon inspection, my tests bailed out before getting to these
	branches. They were supposed to test them, but the conditions checked
	stopped the test function and returned before the branches could be reached.

	The unit test is actually pretty good looking with what its SUPPOSED to do,
	but poor unit test structure causes the test functions to bail before the
	full tests are complete. If I refactored the tests, they would get the
	coverage numbers up much higher, and the tests would be better. This
	particular test suite would be really helpful in incremental bug fixes as it
	would allow you to check and then fix one thing at a time, slowly expanding
	the test coverage. Ideally though, all the bugs would still be found in
	a single run and the test should probably be refactored.
