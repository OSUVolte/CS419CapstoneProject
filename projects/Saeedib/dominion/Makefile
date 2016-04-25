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

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so

testresults: unittest1.c  unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.o rngs.o
	gcc -o unittest1 -g unittest1.c dominion.o rngs.o $(CFLAGS)
	./unittest1 > unittestresults.txt
	echo "_________________________________________________________" >> unittestresults.txt
	echo "_________________________________________________________" >> unittestresults.txt

	gcc -o unittest2 -g unittest2.c dominion.o rngs.o $(CFLAGS)
	./unittest2 >> unittestresults.txt
	echo "_________________________________________________________" >> unittestresults.txt
	echo "_________________________________________________________" >> unittestresults.txt

	gcc -o unittest3 -g unittest3.c dominion.o rngs.o $(CFLAGS)
	./unittest3 >> unittestresults.txt
	echo "_________________________________________________________" >> unittestresults.txt
	echo "_________________________________________________________" >> unittestresults.txt

	gcc -o unittest4 -g unittest4.c dominion.o rngs.o $(CFLAGS)
	./unittest4 >> unittestresults.txt
	echo "_________________________________________________________" >> unittestresults.txt
	echo "_________________________________________________________" >> unittestresults.txt

	gcc -o cardtest1 -g cardtest1.c dominion.o rngs.o $(CFLAGS)
	./cardtest1 >> unittestresults.txt
	echo "_________________________________________________________" >> unittestresults.txt
	echo "_________________________________________________________" >> unittestresults.txt

	gcc -o cardtest2 -g cardtest2.c dominion.o rngs.o $(CFLAGS)
	./cardtest2 >> unittestresults.txt
	echo "_________________________________________________________" >> unittestresults.txt
	echo "_________________________________________________________" >> unittestresults.txt

	gcc -o cardtest3 -g cardtest3.c dominion.o rngs.o $(CFLAGS)
	./cardtest3 >> unittestresults.txt
	echo "_________________________________________________________" >> unittestresults.txt
	echo "_________________________________________________________" >> unittestresults.txt

	gcc -o cardtest4 -g cardtest4.c dominion.o rngs.o $(CFLAGS)
	./cardtest4 >> unittestresults.txt
	echo "_________________________________________________________" >> unittestresults.txt

	echo "Coverage test: " > coverage1.c
	gcov unittest1.gnda >> coverage1.c
	echo "_________________________________________________________" >> coverage1.c
	gcov unittest2.gnda >> coverage1.c
	echo "_________________________________________________________" >> coverage1.c
	gcov unittest3.gnda >> coverage1.c
	echo "_________________________________________________________" >> coverage1.c
	gcov unittest4.gnda >> coverage1.c
	echo "_________________________________________________________" >> coverage1.c
	gcov cardtest1.gnda >> coverage1.c
	echo "_________________________________________________________" >> coverage1.c
	gcov cardtest2.gnda >> coverage1.c
	echo "_________________________________________________________" >> coverage1.c
	gcov cardtest3.gnda >> coverage1.c
	echo "_________________________________________________________" >> coverage1.c
	gcov cardtest4.gnda >> coverage1.c
	echo "_________________________________________________________" >> coverage1.c
	echo "End of tests" >> coverage1.c

	rm -f unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4

unittestresults.out:
	make testresults
	cat coverage1.c >> unittestresults.txt
	cat unittestresults.txt >> unittestresults.out
	rm unittestresults.txt
	
