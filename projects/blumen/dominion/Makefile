CFLAGS = -Wall -fpic -coverage -lm

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

testSuite1: testSuite1.c randomtestcard.c dominion.o rngs.o
	gcc -o testSuite1 -g  testSuite1.c randomtestcard.c dominion.o rngs.o $(CFLAGS)

runtests1: testSuite1 
	./testSuite1 &> randomtestcard.out
	gcov -b -c dominion.c >> randomtestcard.out
	cat dominion.c.gcov >> randomtestcard.out

randomtestcard.out: playdom player testSuite1 runtests1 clean

testSuite2: testSuite2.c randomtestadventurer.c dominion.o rngs.o
	gcc -o testSuite2 -g  testSuite2.c randomtestadventurer.c dominion.o rngs.o $(CFLAGS)

runtests2: testSuite2 
	./testSuite2 &> randomtestadventurer.out
	gcov -b -c dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out

randomtestadventurer.out: playdom player testSuite2 runtests2 clean

testSuite: testSuite.c unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c randomtestadventurer.c randomtestcard.c dominion.o rngs.o
	gcc -o testSuite -g  testSuite.c unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c randomtestadventurer.c randomtestcard.c dominion.o rngs.o $(CFLAGS)

runtests: testSuite 
	./testSuite &> unittestresults.out
	gcov -b -c dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
	
unittestresults.out: playdom player testSuite runtests
