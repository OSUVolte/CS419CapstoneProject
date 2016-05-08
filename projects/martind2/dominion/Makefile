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

unittests: unittest1.c unittest2.c unittest3.c unittest4.c dominion.o rngs.o
	gcc -o unit-test1 unittest1.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o unit-test2 unittest2.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o unit-test3 unittest3.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o unit-test4 unittest4.c -g dominion.o rngs.o $(CFLAGS)

cardtests: cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.o rngs.o
	gcc -o card-test1 cardtest1.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o card-test2 cardtest2.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o card-test3 cardtest3.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o card-test4 cardtest4.c -g dominion.o rngs.o $(CFLAGS)

unittestresults.out: unittests cardtests
	echo '' > unittestresults.out
	echo '#### #### #### TEST OUTPUT #### #### ####' >> unittestresults.out
	echo '' >> unittestresults.out
	./unit-test1 >> unittestresults.out
	echo '' >> unittestresults.out
	./unit-test2 >> unittestresults.out
	echo '' >> unittestresults.out
	./unit-test3 >> unittestresults.out
	echo '' >> unittestresults.out
	./unit-test4 >> unittestresults.out
	echo '' >> unittestresults.out
	./card-test1 >> unittestresults.out
	echo '' >> unittestresults.out
	./card-test2 >> unittestresults.out
	echo '' >> unittestresults.out
	./card-test3 >> unittestresults.out
	echo '' >> unittestresults.out
	./card-test4 >> unittestresults.out
	echo '' >> unittestresults.out
	echo '#### #### #### TESTED COVERAGE #### #### ####' >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	echo '' >> unittestresults.out
	sed -n -e 277,314p dominion.c.gcov >> unittestresults.out
	echo '' >> unittestresults.out
	sed -n -e 355,393p dominion.c.gcov >> unittestresults.out
	echo '' >> unittestresults.out
	sed -n -e 395,420p dominion.c.gcov >> unittestresults.out
	echo '' >> unittestresults.out
	sed -n -e 1206,1234p dominion.c.gcov >> unittestresults.out
	echo '' >> unittestresults.out
	sed -n -e 1267,1279p dominion.c.gcov >> unittestresults.out
	echo '' >> unittestresults.out
	sed -n -e 1236,1265p dominion.c.gcov >> unittestresults.out
	echo '' >> unittestresults.out
	sed -n -e 1281,1294p dominion.c.gcov >> unittestresults.out
	echo '' >> unittestresults.out
	sed -n -e 1352,1378p dominion.c.gcov >> unittestresults.out
	echo '' >> unittestresults.out
	echo '#### #### #### ALL COVERAGE #### #### ####' >> unittestresults.out
	echo '' >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
	echo '' >> unittestresults.out
	gcov dominion.c >> unittestresults.out

randomtests: randomtestadventurer.c randomtestcard.c dominion.o rngs.o
	gcc -o randomtestcard randomtestcard.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o $(CFLAGS)
	echo '' > randomtestcard.out
	./randomtestcard >> randomtestcard.out
	echo '' > randomtestadventurer.out
	./randomtestadventurer >> randomtestadventurer.out
	

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so
