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

unit1:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest1.c rngs.c -o unittest1 -lm -g

unit2:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest2.c rngs.c -o unittest2 -lm -g

unit3:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest3.c rngs.c -o unittest3 -lm -g

unit4:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest4.c rngs.c -o unittest4 -lm -g

card1:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest1.c rngs.c -o cardtest1 -lm -g

card2:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest2.c rngs.c -o cardtest2 -lm -g

card3:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest3.c rngs.c -o cardtest3 -lm -g

card4:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest4.c rngs.c -o cardtest4 -lm -g

myTest:
	./unittest1 &> unittestresults.out
	./unittest2 >> unittestresults.out
	./unittest3 >> unittestresults.out
	./unittest4 >> unittestresults.out
	./cardtest1 >> unittestresults.out
	./cardtest2 >> unittestresults.out
	./cardtest3 >> unittestresults.out
	./cardtest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out


unittestresults.out:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest1.c rngs.c -o unittest1 -lm -g
	./unittest1 &> unittestresults.out
	gcov dominion.c -b  >> unittestresults.out
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest2.c rngs.c -o unittest2 -lm -g
	./unittest2 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest3.c rngs.c -o unittest3 -lm -g
	./unittest3 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest4.c rngs.c -o unittest4 -lm -g
	./unittest4 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest1.c rngs.c -o cardtest1 -lm -g
	./cardtest1 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest2.c rngs.c -o cardtest2 -lm -g
	./cardtest2 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out	
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest3.c rngs.c -o cardtest3 -lm -g
	./cardtest3 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out	
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest4.c rngs.c -o cardtest4 -lm -g
	./cardtest4 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)

randomtestcard: randomtestcard.c dominion.o rngs.o
	gcc -o randomtestcard -g randomtestcard.c dominion.o rngs.o $(CFLAGS)



randomtestadventurer.out: clean randomtestadventurer
	./randomtestadventurer >> randomtestadventurer.out
	@echo "--------------------------------" >> randomtestadventurer.out
	@echo "Dominion Function Coverage" >> randomtestadventurer.out
	@echo "---------------------------------" >> randomtestadventurer.out
	gcov dominion.c -b -f >> randomtestadventurer.out
	@echo "--------------------------------" >> randomtestadventurer.out
	@echo "Dominion Coverage " >> randomtestadventurer.out
	@echo "-----------------------------------" >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out

randomtestcard.out: clean randomtestcard
	./randomtestcard >> randomtestcard.out
	@echo "----------------------------------" >> randomtestcard.out
	@echo "Dominion Function Coverage" >> randomtestcard.out
	@echo "----------------------------------" >> randomtestcard.out
	gcov dominion.c -b -f >> randomtestcard.out
	@echo "----------------------------------" >> randomtestcard.out
	@echo "Dominion Coverage " >> randomtestcard.out	
	@echo "----------------------------------" >> randomtestcard.out
	cat dominion.c.gcov >> randomtestcard.out


 






	

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so
