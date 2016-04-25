CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe unittest1 unittest1.txt unittest2 unittest2.exe unittest3 unittest3.exe unittest4 unittest4.exe cardtest1 cardtest1.exe cardtest2 cardtest2.exe cardtest3 cardtest3.exe cardtest4 cardtest4.exe *.gcov *.gcda *.gcno *.so *.out
	
unittest1: unittest1.c dominion.o rngs.o
	gcc -o unittest1 -g unittest1.c dominion.o rngs.o $(CFLAGS)

unittest2: unittest2.c dominion.o rngs.o
	gcc -o unittest2 -g unittest2.c dominion.o rngs.o $(CFLAGS)

unittest3: unittest3.c dominion.o rngs.o
	gcc -o unittest3 -g unittest3.c dominion.o rngs.o $(CFLAGS)
	
unittest4: unittest4.c dominion.o rngs.o
	gcc -o unittest4 -g unittest4.c dominion.o rngs.o $(CFLAGS)
	
cardtest1: cardtest1.c dominion.o rngs.o
	gcc -o cardtest1 -g cardtest1.c dominion.o rngs.o $(CFLAGS)
	
cardtest2: cardtest2.c dominion.o rngs.o
	gcc -o cardtest2 -g cardtest2.c dominion.o rngs.o $(CFLAGS)
	
cardtest3: cardtest3.c dominion.o rngs.o
	gcc -o cardtest3 -g cardtest3.c dominion.o rngs.o $(CFLAGS)
	
cardtest4: cardtest4.c dominion.o rngs.o
	gcc -o cardtest4 -g cardtest4.c dominion.o rngs.o $(CFLAGS)
	
runts:
	./unittest1 >> unittestresults.out
	gcov -b unittest1.c >> unittestresults.out
	@echo "************************************" >> unittestresults.out
	@echo "* Running Unit Test 2...           *" >> unittestresults.out
	@echo "************************************" >> unittestresults.out
	./unittest2 >> unittestresults.out
	gcov -b unittest2.c >> unittestresults.out
	@echo "************************************" >> unittestresults.out
	@echo "* Running Unit Test 3...           *" >> unittestresults.out
	@echo "************************************" >> unittestresults.out
	./unittest3 >> unittestresults.out
	gcov -b unittest3.c >> unittestresults.out
	@echo "************************************" >> unittestresults.out
	@echo "* Running Unit Test 4...           *" >> unittestresults.out
	@echo "************************************" >> unittestresults.out
	./unittest4 >> unittestresults.out
	gcov -b unittest4.c >> unittestresults.out
	@echo "************************************" >> unittestresults.out
	@echo "* Running Card Test 1...           *" >> unittestresults.out
	@echo "************************************" >> unittestresults.out
	./cardtest1 >> unittestresults.out
	gcov -b cardtest1.c >> unittestresults.out
	@echo "************************************" >> unittestresults.out
	@echo "* Running Card Test 2...           *" >> unittestresults.out
	@echo "************************************" >> unittestresults.out
	./cardtest2 >> unittestresults.out
	gcov -b cardtest2.c >> unittestresults.out
	@echo "************************************" >> unittestresults.out
	@echo "* Running Card Test 3...           *" >> unittestresults.out
	@echo "************************************" >> unittestresults.out
	./cardtest3 >> unittestresults.out
	gcov -b cardtest3.c >> unittestresults.out
	@echo "************************************" >> unittestresults.out
	@echo "* Running Card Test 4...           *" >> unittestresults.out
	@echo "************************************" >> unittestresults.out
	./cardtest4 >> unittestresults.out
	gcov -b cardtest4.c >> unittestresults.out
	@echo "************************************" >> unittestresults.out
	@echo "* Dom Function Coverage...         *" >> unittestresults.out
	@echo "************************************" >> unittestresults.out
	gcov dominion.c -b -f >> unittestresults.out
	@echo "************************************" >> unittestresults.out
	@echo "* Dominion Coverage...             *" >> unittestresults.out
	@echo "************************************" >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
	
unittestresults.out: all unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 runts