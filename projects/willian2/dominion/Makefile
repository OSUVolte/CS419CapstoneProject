CFLAGS = -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

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
	
unittestresults.out: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4
	./unittest1 >> unittestresult.out
	./unittest2 >> unittestresult.out
	./unittest3 >> unittestresult.out
	./unittest4 >> unittestresult.out
	./cardtest1 >> unittestresult.out
	./cardtest2 >> unittestresult.out
	./cardtest3 >> unittestresult.out
	./cardtest4 >> unittestresult.out
	gcov dominion.c -b >> unittestresult.out
	
	gcov unittest1.c >> unittestresult.out
	gcov unittest2.c >> unittestresult.out
	gcov unittest3.c >> unittestresult.out
	gcov unittest4.c >> unittestresult.out
	gcov cardtest1.c >> unittestresult.out
	gcov cardtest2.c >> unittestresult.out
	gcov cardtest3.c >> unittestresult.out
	gcov cardtest4.c >> unittestresult.out
	
	cat dominion.c.gcov >> unittestresult.out
	
randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
	
randomtestcard: randomtestcard.c dominion.o rngs.o
	gcc -o randomtestcard -g randomtestcard.c dominion.o rngs.o $(CFLAGS)
	
randomtestadventurer.out: randomtestadventurer
	./randomtestadventurer >> randomtestadventurer.out
	
	gcov dominion.c -b >> randomtestadventurer.out
	gcov randomtestadventurer.c -b >> randomtestadventurer.out
	#cat dominion.c.gcov >> randomtestadventurer.out
	cat randomtestadventurer.c.gcov >> randomtestadventurer.out
	
randomtestcard.out: randomtestcard
	./randomtestcard >> randomtestcard.out
	
	gcov dominion.c -b >> randomtestcard.out
	gcov randomtestcard.c -b >> randomtestcard.out
	#cat dominion.c.gcov >> randomtestcard.out
	cat randomtestcard.c.gcov >> randomtestcard.out
	



clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randomtestadventurer randomtestcard *.gcov *.gcda *.gcno *.so
