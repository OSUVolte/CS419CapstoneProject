CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
	
card1:  dominion.o rngs.o cardtest1.c 
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o cardtest1.c rngs.o -o cardtest1 -lm -g	

card2:  dominion.o rngs.o cardtest2.c 
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o cardtest2.c rngs.o -o cardtest2 -lm -g	

card3:  dominion.o rngs.o cardtest3.c 
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o cardtest3.c rngs.o -o cardtest3 -lm -g	

card4:  dominion.o rngs.o cardtest4.c 
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o cardtest4.c rngs.o -o cardtest4 -lm -g	

unit1: dominion.o rngs.o unittest1.c
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o unittest1.c rngs.o -o unittest1 -lm -g	

unit2: dominion.o rngs.o unittest2.c
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o unittest2.c rngs.o -o unittest2 -lm -g	

unit3: dominion.o rngs.o unittest3.c
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o unittest3.c rngs.o -o unittest3 -lm -g	

unit4: dominion.o rngs.o unittest4.c
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o unittest4.c rngs.o -o unittest4 -lm -g	

unittestresults.out: unit1 unit2 unit3 unit4 card1 card2 card3 card4 dominion.o 
	echo "***********UNIT TEST 1******************" >& unittestresults.out  
	./unittest1 >> unittestresults.out
	gcov unittest1 -f -b >> unittestresults.out
	echo "************UNIT TEST 2******************" >> unittestresults.out
	echo "" >> unittestresults.out
	./unittest2 >> unittestresults.out  
	gcov unittest2 -f -b >> unittestresults.out
	echo "************UNIT TEST 3******************" >> unittestresults.out
	echo "" >> unittestresults.out
	./unittest3 >> unittestresults.out
	gcov unittest3 -f -b >> unittestresults.out
	echo "************UNIT TEST 4******************" >> unittestresults.out
	echo "" >> unittestresults.out
	./unittest4 >> unittestresults.out
	gcov unittest4 -f -b >> unittestresults.out
	echo "************CARD TEST 1******************" >> unittestresults.out
	echo "" >> unittestresults.out
	./cardtest1 >> unittestresults.out
	gcov cardtest1 -f -b >> unittestresults.out
	echo "************CARD TEST 2******************" >> unittestresults.out
	echo "" >> unittestresults.out
	./cardtest2 >> unittestresults.out
	gcov cardtest2 -f -b >> unittestresults.out
	echo "************CARD TEST 3******************" >> unittestresults.out
	echo "" >> unittestresults.out
	./cardtest3 >> unittestresults.out
	gcov cardtest3 -f -b >> unittestresults.out 
	echo "************CARD TEST 4******************" >> unittestresults.out
	echo "" >> unittestresults.out
	./cardtest4 >> unittestresults.out
	gcov cardtest4 -f -b >> unittestresults.out
	echo "************DOMINION******************" >> unittestresults.out
	echo "" >> unittestresults.out
	gcov dominion -f -b >> unittestresults.out
 
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

all: playdom player testDrawCard testBuyCard badTestDrawCard card1 card2 card3 card4 unit1 unit2 unit3 unit4

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe cardtest1 cardtest2 cardtest3 cardtest4 unittest1 unittest2 unittest3 unittest4 .gcov *.gcda *.gcno *.so
