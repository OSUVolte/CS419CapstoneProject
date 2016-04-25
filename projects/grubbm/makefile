CC = gcc
CFLAGS  = -g -Wall -coverage -fpic -lm

all: unittest1 unittest2 unittest3 unittest4 test1 test2 test3 test4

unittest1:  unittest1.o dominion.o rngs.o 
	$(CC) $(CFLAGS) -o unittest1 unittest1.o dominion.o rngs.o 


unittest2: unittest2.o dominion.o rngs.o 
	$(CC) $(CFLAGS) -o unittest2 unittest2.o dominion.o rngs.o 

unittest3: unittest3.o dominion.o rngs.o 
	$(CC) $(CFLAGS) -o unittest3 unittest3.o dominion.o rngs.o 

unittest4: unittest4.o dominion.o rngs.o 
	$(CC) $(CFLAGS) -o unittest4 unittest4.o dominion.o rngs.o 

cardtest1: cardtest1.o dominion.o rngs.o
	$(CC) $(CFLAGS) -o cardtest1 cardtest1.o dominion.o rngs.o 

cardtest2: cardtest2.o dominion.o rngs.o
	$(CC) $(CFLAGS) -o cardtest2 cardtest2.o dominion.o rngs.o 
	
cardtest3: cardtest3.o dominion.o rngs.o
	$(CC) $(CFLAGS) -o cardtest3 ctest3.o dominion.o rngs.o 
	
cardtest4: cardtest4.o dominion.o rngs.o
	$(CC) $(CFLAGS) -o cardtest4 ctest4.o dominion.o rngs.o 

unittest1.o:  unittest1.c rngs.h dominion.h dominion_helpers.h
	$(CC) $(CFLAGS) -c unittest1.c	

unittest2.o:  unittest2.c rngs.h dominion.h dominion_helpers.h
	$(CC) $(CFLAGS) -c unittest2.c	

unittest3.o:  unittest3.c rngs.h dominion.h dominion_helpers.h
	$(CC) $(CFLAGS) -c unittest3.c	

unittest4.o:  unittest4.c rngs.h dominion.h dominion_helpers.h
	$(CC) $(CFLAGS) -c unittest4.c	

cardtest1.o:  cardtest1.c rngs.h dominion.h dominion_helpers.h
	$(CC) $(CFLAGS) -c cardtest1.c

cardtest2.o:  cardtest2.c rngs.h dominion.h dominion_helpers.h
	$(CC) $(CFLAGS) -c cardtest2.c

cardtest3.o:  cardtest3.c rngs.h dominion.h dominion_helpers.h
	$(CC) $(CFLAGS) -c cardtest3.c
	
cardtest4.o:  cardtest4.c rngs.h dominion.h dominion_helpers.h
	$(CC) $(CFLAGS) -c cardtest4.c
	
dominion.o:  dominion.c dominion.h 
	$(CC) $(CFLAGS) -c dominion.c

rngs.o:  rngs.c rngs.h 
	$(CC) $(CFLAGS) -c rngs.c
	
ucTest:
	./unittest1 &> unittestresults.out
	gcov unittest1.c >> unittestresults.out
	./unittest2 >> unittestresults.out
	gcov unittest2.c >> unittestresults.out
	./unittest3 >> unittestresults.out
	gcov unittest3.c >> unittestresults.out
	./unittest4 >> unittestresults.out
	gcov unittest4.c >> unittestresults.out
	./cardtest1 >> unittestresults.out
	gcov cardtest1.c >> unittestresults.out
	./cardtest2 >> unittestresults.out
	gcov cardtest1.c >> unittestresults.out
	./cardtest3 >> unittestresults.out
	gcov cardtest1.c >> unittestresults.out
	./cardtest4 >> unittestresults.out
	gcov cardtest1.c >> unittestresults.out
	
	

clean: 
	$(RM) prog1 *.o *~
