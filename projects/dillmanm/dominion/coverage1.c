It is important to recognize that this project really focused on testing only 8 functions,
4 core functions and 4 card effects. As such, coverage will probably not be as complete
as you'd hope from a total test suite. Additionally, since this was a unit test, I used
the preconditional logic that exists for each function and avoided boundary conditions
that would never occur due to constraints imposed by card scarcity, choice limitations, etc.
In this way, error checking done by calling functions shields the called functions from bad values.
Random error checking would execute far more of these boundary conditions than a unit test.

function buyCard called 7 returned 100% blocks executed 100%
Overall, this is quite good coverage, and branches seemed to have around an 80/20 split.
I also had 100 percent statement coverage.

function isGameOver called 24 returned 100% blocks executed 100%
	Again 100% statement coverage with varying splits on branch coverage. A decently
	well covered method.

gainCard:
function gainCard called 10 returned 100% blocks executed 100%
My test suite attained 100 percent branch and statement coverage for the gainCard function.

discardCard:
function discardCard called 18 returned 100% blocks executed 89%

The discard card function had a few sparse lines that were never executed.
There was a case that I missed, namely discarding the last card in the hand, which
had a testing fallthrough and the other branch was taken 100 percent of the time.
This is a case I would add to strengthen the oracle of my test suite.

adventurer:
function playAdventurer called 2 returned 100% blocks executed 81%
My testing suite fell quite a bit short on this particular card. Namely, I found a large bug
that occurred when I made an infinite loop where there were no treasures in the discard or deck,
but then I never introduced the case where there were enough treasures in the deck and discard
combined, which left out almost all of the statements involving temphands. I would reintroduce
this case on the next iteration of my test suite.

smithy:
The smithy function had 100 percent statement and branch coverage.

great hall:
Great hall had 100 percent statement and branch coverage.

village:
the vilalge had 100 percent statement and branch coverage.