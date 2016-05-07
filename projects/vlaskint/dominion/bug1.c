#tatyan vlaskin
whoseTurn() Function test
        no bugs detected

NumHandCards()
        no bugs detected

isGameOver()
        no bugs detected

compare()
        no bugs detected

SMITHY CARD TEST
        bug detected: ERROR: Hand Count Should be: 7. Instead Hand Count is: 6
        this makes sense because for the last assignment, I have introduced a bug into this function:
        Bug: in for statement the loop is started at 1 instead of 0

ADVENTURE CARD TEST
        no errors were detected in my test because the test that I have implemented tests only for the final count of the cards
        however it does not check if any treasure cards were chosen and incorrectly discarded.
        The bug that I have introduced last week: if (cardDrawn == copper || cardDrawn == silver || cardDrawn != gold)
        thus gold card, which is treasure card is incorrectly discardec and we are not aware of this
        the test for this function has to be optimazed to check for the cards that were discarded

COUNCIL_ROOM CARD TEST
        bug detected: ERROR: Hand Count Should be: 9. Instead Hand Count is: 8
        this makes sense because last week, I have  commented out the following code form the function //state->numBuys++; is removed from the function
        thus the buy card is not added

VILLAGE CARD TEST
            bug detected: ERROR: Num Action Should be: 3. Instead Num Actiont is: 4
            this makes sense becasue last week, I have introduced the following bug into the vilalge card
            Bug:  state->numActions = state->numActions + 2; is replaced with  state->numActions = state->numActions + 3;
