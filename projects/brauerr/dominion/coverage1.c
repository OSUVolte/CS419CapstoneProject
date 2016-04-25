//coverage1.c describing coverage from running gcov on all 8 unit and card tests for assignment 3

//overall coverage results:
/*
  Lines executed:  42.0% of 600
  Branches Executed:  51.89% of 449
  Taken at least Once:  36.08% of 449
  Calls executed:  26.67% of 105
*/

//overall coverage comments:
/*
lines - overall statement coverage
branches executed - branches evaluated
branches taken once - branches actually taken (evaluated to true)
calls - percentage of calls to other functions that have been used in code
*/

//ways to improve coverage:
/*
  run tests randomly initializing game state with all of the possible kingdom cards
  build unit tests for each kingdom card - since a large amount of the code coverage
  has to do with the effects of the individual cards when played
  
  ensure inputs to unit test functions include all possible inputs to trigger branch paths
  do same for card tests - for example with the different potential choices
  
  could use gcov output files to look into more detail on this - ensuring branches/statements
  are all covered for each branch taken
  
  from there could also investigate if there are orphaned functions - and dig deeper into where 
  they are to be called in code and why they haven't been in unit and card tests
  
  do more robust testing of helper functions at first - and then implement these once
  testing passes in higher level unit tests and functions to increase coverage / calls
  
  build out a fully functioning simulator to play hands - perhaps randomly choosing action 
  cards and choices, where applicable
*/