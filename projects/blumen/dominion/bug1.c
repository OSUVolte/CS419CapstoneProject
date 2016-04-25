File testSuite.c did not find any bugs in the original, un-refactored code.

In the re-factored code that was engineered to contain mistakes, the test suite
found the following errors:

    * Smithy: detected that 4 cards were added instead of 3
    * Smithy: did not detect any discrepency in discarding Smithy because that fell outside the card's code.
    * Adventurer: detected that copper was never tested.
    * Adventurer: did not detect any irregularity in discarding Adventurer because that fell outside the card's code.
    * Feast: did not detect that too little money was added to purse because testSuite only looked for buys that
        exceeded the purse. Need to improve testSuite.
    * Feast: detected error where a card is not gained after purchase
    * Council_Room: detected error where opponents fail to gain a card.
    * No bugs were found in the methods, which agreed with the fact that no bugs
    were introduced into any method in week 2.
