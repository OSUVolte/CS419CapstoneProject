// gcov for unittest1 (testing whoseTurn() function)

File 'unittest1.c'
Lines executed:100.00% of 10
Branches executed:100.00% of 4
Taken at least once:75.00% of 4
Calls executed:66.67% of 3

        -:    0:Source:unittest1.c
        -:    0:Graph:unittest1.gcno
        -:    0:Data:unittest1.gcda
        -:    0:Runs:1
        -:    0:Programs:1
        -:    1:// Unit test for whoseTurn() function
        -:    2:
        -:    3:#include "dominion.h"
        -:    4:#include "rngs.h"
        -:    5:#include <stdlib.h>
        -:    6:#include <stdio.h>
        -:    7:#include <assert.h>
        -:    8:
function main called 1 returned 100% blocks executed 89%
        1:    9:int main()
        -:   10:{
        -:   11:        struct gameState Game;
        -:   12:
        1:   13:        int turn = 1;
        1:   14:        int i = 0;
        -:   15:
       22:   16:        while(turn <= 20)
branch  0 taken 95%
branch  1 taken 5% (fallthrough)
        -:   17:        {
       20:   18:                Game.whoseTurn = turn;
       20:   19:                i = whoseTurn(&Game);
call    0 returned 100%
        -:   20:
       20:   21:                assert(i == turn);
branch  0 taken 0% (fallthrough)
branch  1 taken 100%
call    2 never executed
       20:   22:                turn++;
        -:   23:        }
        -:   24:
        1:   25:        printf("whoseTurn unit test passed\n");
call    0 returned 100%
        -:   26:
        1:   27:        return 0;
        -:   28:}

// gcov for unittest2 (testing initializeGame() function)

File 'unittest2.c'
Lines executed:100.00% of 6
Branches executed:100.00% of 2
Taken at least once:50.00% of 2
Calls executed:66.67% of 3

        -:    0:Source:unittest2.c
        -:    0:Graph:unittest2.gcno
        -:    0:Data:unittest2.gcda
        -:    0:Runs:1
        -:    0:Programs:1
        -:    1:// Unit test for initializeGame() function
        -:    2:
        -:    3:#include "dominion.h"
        -:    4:#include "rngs.h"
        -:    5:#include <stdlib.h>
        -:    6:#include <stdio.h>
        -:    7:#include <assert.h>
        -:    8:
function main called 1 returned 100% blocks executed 83%
        1:    9:int main()
        -:   10:{
        -:   11:        struct gameState Game;
        -:   12:
        -:   13:        // Just listing random 10 cards
        1:   14:        int card[10] = {adventurer, feast, gardens, mine, remodel, smithy, village, council_room, great_hall, minion};
        -:   15:
        1:   16:        int i = initializeGame(2,card,2,&Game);
call    0 returned 100%
        -:   17:
        1:   18:        assert(i == 0);
branch  0 taken 0% (fallthrough)
branch  1 taken 100%
call    2 never executed
        -:   19:
        1:   20:        printf("initializeGame unit test passed\n");
call    0 returned 100%
        -:   21:
        1:   22:        return 0;
        -:   23:}
~                  

// gcov for unittest3 (testing isGameOver() function)

File 'unittest3.c'
Lines executed:100.00% of 8
Branches executed:100.00% of 2
Taken at least once:50.00% of 2
Calls executed:75.00% of 4

        -:    0:Source:unittest3.c
        -:    0:Graph:unittest3.gcno
        -:    0:Data:unittest3.gcda
        -:    0:Runs:1
        -:    0:Programs:1
        -:    1:// Unit test for isGameOver() function
        -:    2:
        -:    3:#include "dominion.h"
        -:    4:#include "rngs.h"
        -:    5:#include <stdlib.h>
        -:    6:#include <stdio.h>
        -:    7:#include <assert.h>
        -:    8:
function main called 1 returned 100% blocks executed 86%
        1:    9:int main()
        -:   10:{
        -:   11:        struct gameState Game;
        -:   12:
        1:   13:        int card[10] = {adventurer, feast, gardens, mine, remodel, smithy, village, council_room, great_hall, minion};
        -:   14:        int i;
        -:   15:
        1:   16:        initializeGame(2,card,2,&Game);
call    0 returned 100%
        -:   17:
        1:   18:        Game.supplyCount[province] = 0;
        -:   19:
        1:   20:        i = isGameOver(&Game);
call    0 returned 100%
        -:   21:
        1:   22:        assert(i == 1);
branch  0 taken 0% (fallthrough)
branch  1 taken 100%
call    2 never executed
        -:   23:
        1:   24:        printf("isGameOver unit test passed\n");
call    0 returned 100%
        -:   25:
        1:   26:        return 0;
        -:   27:}

// gcov for unittest4 (testing numHandCards() function)

File 'unittest4.c'
Lines executed:100.00% of 7
Branches executed:100.00% of 2
Taken at least once:50.00% of 2
Calls executed:75.00% of 4

        -:    0:Source:unittest4.c
        -:    0:Graph:unittest4.gcno
        -:    0:Data:unittest4.gcda
        -:    0:Runs:1
        -:    0:Programs:1
        -:    1:// Unit test for numHandCards() function
        -:    2:
        -:    3:#include "dominion.h"
        -:    4:#include "rngs.h"
        -:    5:#include <stdlib.h>
        -:    6:#include <stdio.h>
        -:    7:#include <assert.h>
        -:    8:
function main called 1 returned 100% blocks executed 86%
        1:    9:int main()
        -:   10:{
        -:   11:        struct gameState Game;
        -:   12:
        1:   13:        int card[10] = {adventurer, feast, gardens, mine, remodel, smithy, village, council_room, great_hall, minion};
        -:   14:
        1:   15:        initializeGame(2,card,2,&Game);
call    0 returned 100%
        -:   16:
        1:   17:        int i = numHandCards(&Game);
call    0 returned 100%
        -:   18:
        -:   19:        // Each player should have 5 cards
        1:   20:        assert(i == 5);
branch  0 taken 0% (fallthrough)
branch  1 taken 100%
call    2 never executed
        -:   21:
        1:   22:        printf("numHandCards unit test passed\n");
call    0 returned 100%
        -:   23:
        1:   24:        return 0;
        -:   25:}


// gcov for cardtest1 (testing adventurer card)

File 'cardtest1.c'
Lines executed:100.00% of 6
Branches executed:100.00% of 2
Taken at least once:50.00% of 2
Calls executed:75.00% of 4

        -:    0:Source:cardtest1.c
        -:    0:Graph:cardtest1.gcno
        -:    0:Data:cardtest1.gcda
        -:    0:Runs:1
        -:    0:Programs:1
        -:    1:// Card test for adventurer
        -:    2:
        -:    3:#include "dominion.h"
        -:    4:#include "dominion_helpers.h"
        -:    5:#include "rngs.h"
        -:    6:#include <stdlib.h>
        -:    7:#include <stdio.h>
        -:    8:#include <assert.h>
        -:    9:
function main called 1 returned 100% blocks executed 86%
        1:   10:int main()
        -:   11:{
        -:   12:        struct gameState Game;
        -:   13:
        1:   14:        int card[10] = {adventurer, feast, gardens, mine, remodel, smithy, village, council_room, great_hall, minion};
        -:   15:        int bonus;
        -:   16:
        1:   17:        initializeGame(2,card,1,&Game);
call    0 returned 100%
        -:   18:
        1:   19:        assert(cardEffect(adventurer,0,0,0,&Game,0,&bonus) == 0);
call    0 returned 100%
branch  1 taken 0% (fallthrough)
branch  2 taken 100%
call    3 never executed
        -:   20:
        1:   21:        printf("Adventurer card test passed\n");
call    0 returned 100%
        -:   22:
        1:   23:        return 0;
        -:   24:}

// gcov for cardtest2 (testing smithy card) 

File 'cardtest2.c'
Lines executed:100.00% of 8
Branches executed:100.00% of 6
Taken at least once:50.00% of 6
Calls executed:62.50% of 8

        -:    0:Source:cardtest2.c
        -:    0:Graph:cardtest2.gcno
        -:    0:Data:cardtest2.gcda
        -:    0:Runs:2
        -:    0:Programs:1
        -:    1:// Card test for smithy
        -:    2:
        -:    3:#include "dominion.h"
        -:    4:#include "dominion_helpers.h"
        -:    5:#include "rngs.h"
        -:    6:#include <stdlib.h>
        -:    7:#include <stdio.h>
        -:    8:#include <assert.h>
        -:    9:
function main called 2 returned 100% blocks executed 77%
        2:   10:int main()
        -:   11:{
        -:   12:        struct gameState Game;
        -:   13:
        2:   14:        int card[10] = {adventurer, feast, gardens, mine, remodel, smithy, village, council_room, great_hall, minion};
        -:   15://      int bonus;
        -:   16:
        2:   17:        initializeGame(2,card,2,&Game);
call    0 returned 100%
        -:   18:
        -:   19:        // Player should have 5 cards
        2:   20:        assert(numHandCards(&Game) == 5);
call    0 returned 100%
branch  1 taken 0% (fallthrough)
branch  2 taken 100%
call    3 never executed
        -:   21:
        2:   22:        assert(cardEffect(smithy,0,0,0,&Game,0,0) == 0);
call    0 returned 100%
branch  1 taken 0% (fallthrough)
branch  2 taken 100%
call    3 never executed
        -:   23:
        -:   24:        // Player should have 7 cards now; player draws 3 cards and discard the smithy card
        2:   25:        assert(numHandCards(&Game) == 7);
call    0 returned 100%
branch  1 taken 0% (fallthrough)
branch  2 taken 100%
call    3 never executed
        -:   26:
        2:   27:        printf("smithy card test passed\n");
call    0 returned 100%
        -:   28:
        2:   29:        return 0;
        -:   30:}

// gcov for cardtest3 (testing great hall card)

Lines executed:100.00% of 11
Branches executed:100.00% of 10
Taken at least once:50.00% of 10
Calls executed:50.00% of 10

        -:    0:Source:cardtest3.c
        -:    0:Graph:cardtest3.gcno
        -:    0:Data:cardtest3.gcda
        -:    0:Runs:1
        -:    0:Programs:1
        -:    1:// Card test for great hall
        -:    2:
        -:    3:#include "dominion.h"
        -:    4:#include "dominion_helpers.h"
        -:    5:#include "rngs.h"
        -:    6:#include <stdlib.h>
        -:    7:#include <stdio.h>
        -:    8:#include <assert.h>
        -:    9:
function main called 1 returned 100% blocks executed 71%
        1:   10:int main()
        -:   11:{
        -:   12:        struct gameState Game;
        -:   13:
        1:   14:        int card[10] = {adventurer, feast, gardens, mine, remodel, smithy, village, council_room, great_hall, minion};
        1:   15:        initializeGame(2,card,1,&Game);
call    0 returned 100%
        -:   16:
        1:   17:        Game.numActions = 0;
        -:   18:
        -:   19:        // Player should have 5 cards
        1:   20:        assert(numHandCards(&Game) == 5);
call    0 returned 100%
branch  1 taken 0% (fallthrough)
branch  2 taken 100%
call    3 never executed
        -:   21:        // Player should have 0 actions
        1:   22:        assert(Game.numActions == 0);
branch  0 taken 0% (fallthrough)
branch  1 taken 100%
call    2 never executed
        -:   23:
        1:   24:        assert(cardEffect(great_hall,0,0,0,&Game,0,0) == 0);
call    0 returned 100%
branch  1 taken 0% (fallthrough)
branch  2 taken 100%
call    3 never executed
        -:   25:
        -:   26:        // Player now should have 5 (or 6 cards? this is the one I'm confused on);
        -:   27:        // draws 1 additional card, but this counts as a victory card...
        1:   28:        assert(numHandCards(&Game) == 5);
call    0 returned 100%
branch  1 taken 0% (fallthrough)
branch  2 taken 100%
call    3 never executed
        -:   29:        // Player now should have +1 action
        1:   30:        assert(Game.numActions == 1);
branch  0 taken 0% (fallthrough)
branch  1 taken 100%
call    2 never executed
        -:   31:
        1:   32:        printf("Great Hall card test passed\n");
call    0 returned 100%
        -:   33:
        1:   34:        return 0;
        -:   35:}

// gcov for cardtest4 (testing village card)

Lines executed:100.00% of 11
Branches executed:100.00% of 10
Taken at least once:50.00% of 10
Calls executed:50.00% of 10

        -:    0:Source:cardtest4.c
        -:    0:Graph:cardtest4.gcno
        -:    0:Data:cardtest4.gcda
        -:    0:Runs:1
        -:    0:Programs:1
        -:    1:// Card test for village
        -:    2:
        -:    3:#include "dominion.h"
        -:    4:#include "dominion_helpers.h"
        -:    5:#include "rngs.h"
        -:    6:#include <stdlib.h>
        -:    7:#include <stdio.h>
        -:    8:#include <assert.h>
        -:    9:
function main called 1 returned 100% blocks executed 71%
        1:   10:int main()
        -:   11:{
        -:   12:        struct gameState Game;
        -:   13:
        1:   14:        int card[10] = {adventurer, feast, gardens, mine, remodel, smithy, village, council_room, great_hall, minion};
        1:   15:        initializeGame(2,card,1,&Game);
call    0 returned 100%
        -:   16:
        1:   17:        Game.numActions = 0;
        -:   18:
        -:   19:        // Player should have 5 cards
        1:   20:        assert(numHandCards(&Game) == 5);
call    0 returned 100%
branch  1 taken 0% (fallthrough)
branch  2 taken 100%
call    3 never executed
        -:   21:        // Player should have 0 actions
        1:   22:        assert(Game.numActions == 0);
branch  0 taken 0% (fallthrough)
branch  1 taken 100%
call    2 never executed
        -:   23:
        1:   24:        assert(cardEffect(village,0,0,0,&Game,0,0) == 0);
call    0 returned 100%
branch  1 taken 0% (fallthrough)
branch  2 taken 100%
call    3 never executed
        -:   25:
        -:   26:        // Player should still have 5 cards; draws 1 additional card, but discard the village card
        1:   27:        assert(numHandCards(&Game) == 5);
call    0 returned 100%
branch  1 taken 0% (fallthrough)
branch  2 taken 100%
call    3 never executed
        -:   28:        // Player now should have +2 actions
        1:   29:        assert(Game.numActions == 2);
branch  0 taken 0% (fallthrough)
branch  1 taken 100%
call    2 never executed
        -:   30:
        1:   31:        printf("Village card test passed\n");
call    0 returned 100%
        -:   32:
        1:   33:        return 0;
        -:   34:}


// Looks like all the lines and branches were executed, which is what 
// I was hoping for. I tested these with the original dominion.c file.