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
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

unittestresults.out: unittest*.c cardtest*.c testUtilities.c dominion.o rngs.o
	echo "Result for running dominion tests:" > unittestresults.out
	
	gcc -o unittest1.out unittest1.c testUtilities.c dominion.o rngs.o -g  $(CFLAGS)
	./unittest1.out >> unittestresults.out
	
	gcc -o unittest2.out unittest2.c testUtilities.c dominion.o rngs.o -g  $(CFLAGS)
	./unittest2.out >> unittestresults.out
	
	gcc -o unittest3.out unittest3.c testUtilities.c dominion.o rngs.o -g  $(CFLAGS)
	./unittest3.out >> unittestresults.out
	
	gcc -o unittest4.out unittest4.c testUtilities.c dominion.o rngs.o -g  $(CFLAGS)
	./unittest4.out >> unittestresults.out
	
	gcc -o cardtest1.out cardtest1.c testUtilities.c dominion.o rngs.o -g  $(CFLAGS)
	./cardtest1.out >> cardtestresults.out
#	
#	gcc -o cardtest2.out cardtest2.c dominion.o rngs.o -g  $(CFLAGS)
#	./cardtest2.out >> cardtestresults.out
#	
#	gcc -o cardtest3.out cardtest3.c dominion.o rngs.o -g  $(CFLAGS)
#	./cardtest3.out >> cardtestresults.out
#	
#	gcc -o cardtest4.out cardtest4.c dominion.o rngs.o -g  $(CFLAGS)
#	./cardtest4.out >> cardtestresults.out
#	
	
	
#	for cFile in $(ls unittest*.c) ; do \
#    		gcc -o $compileFile $cFile dominion.c -g  $(CFLAGS); \
#    		./$compileFile >> unittestresults.out; \
#    		gcov $cFile >> unittestresults.out; \
#	done
	
#	for cFile in $(ls cardtest*.c) ; do \
#    		compileFile=${cFile%.*}.out; \
#    		gcc -o $compileFile $cFile dominion.c -g  $(CFLAGS); \
#    		./$compileFile >> unittestresults.out; \
#    		gcov $cFile >> unittestresults.out; \
#	done

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *test?.out 
