/******************************************************************
 * Carolyn Cheung
 * CS 362
 * Assignment 4
 * Description: random tester for adventurer and smithy
 ******************************************************************/

randomtestadventurer

    This test uncovered the bug I added at the start of the class.
    It was able to detect that the player did not remove the right
    amount of treasures from their deck. Instead of drawing 2 treasure
    cards, the players are only drawing one. This was detected not
    through a checking of the players hand after the card was played,
    but detected by checking the expected deck size and real deck size.
    I already accounted for the fact that some decks may contain 1 or
    0 treasures, so I am fairly confident that the test is very accurate
    and thorough.
    
    After running gcov: 
    File 'randomtestadventurer.c'
    Lines executed:84.00% of 75
    Branches executed:91.67% of 48
    Taken at least once:70.83% of 48
    Calls executed:75.86% of 29
    Creating 'randomtestadventurer.c.gcov'

    File 'dominion.c'
    Lines executed:25.09% of 570
    Branches executed:25.66% of 417
    Taken at least once:18.94% of 417
    Calls executed:13.00% of 100
    Creating 'dominion.c.gcov'
    
    I think I should add more tests, such as a test to detect the
    number of treasures in the players hand before and after playing
    adventurer. This way I can more easily narrow down why the bug is
    happening.
    
randomtestcard (smithy)

    This test would fail sometimes for some reason I'm not sure of.
    After calling the playSmithy() function on the testing state, the
    copied state would change its deckcount to 0, even though nothing
    was done to the copied state. I'm not sure why it does it only for
    a few of them, but otherwise the tests ran fine. Since my test
    did not discover the bug I put in, which was to discard the card at
    position zero, I think I should add in a function that checks the players
    hand and makes sure that the proper cards were discarded/added.
    
    After running gcov: 
    File 'randomtestcard.c'
    Lines executed:81.08% of 74
    Branches executed:100.00% of 24
    Taken at least once:66.67% of 24
    Calls executed:72.41% of 29
    Creating 'randomtestcard.c.gcov'

    File 'dominion.c'
    Lines executed:28.42% of 570
    Branches executed:27.58% of 417
    Taken at least once:20.38% of 417
    Calls executed:17.00% of 100
    Creating 'dominion.c.gcov'
    
    Aside from comparing the hands between game states, I think my test
    covers smithy fairly well. I'm not sure why the unchanged gamestate
    deckcount changes to zero, but I'm fairly confident that it's not related
    to a bug in the smithy function itself. That said, I may add tests to
    check the unchanged gamestate is completely unchanged before and after
    calling the function on the tested gamestate.