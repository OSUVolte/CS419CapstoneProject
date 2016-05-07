/*

 randomtestadventurer.c:
 
    This random test uncovered many bugs in the adventurer card, most 
    of which were related to the bug I introduced earlier in the class. 
    Instead of drawing two treasure cards, the player only draws one card.
    This throws off many of my tests, including the size of the player's 
    hand and the size of the deck and discard piles.
 
    After running gcov, here are my results:
 
    Function 'playAdventurer'
    Lines executed:100.00% of 18
    Branches executed:100.00% of 12
    Taken at least once:91.67% of 12
    No calls
 
    One feature I would have liked to implement but did not is
    a random seed for each of my 2000 test loops. However when I tried 
    to implement the feature, I occasionally received segmentation 
    faults when I ran the tester. For the sake of
    expedience, I hardcoded the seed as 1500.
 

randomtestcard.c:
    
    For this random test, I used the village card. Again, there were many
    bugs detected, all of which are related to the bug I introduced earlier
    in the class. Instead of incrementing the numActions by two, the 
    function now decrements the variable.

    After running gcov, here are my results:
 
    Function 'playVillage'
    Lines executed:100.00% of 5
    No branches
    No calls
 




*/