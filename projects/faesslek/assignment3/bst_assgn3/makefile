CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: tests.out

tests.out: unittest1.c unittest2.c unittest3.c unittest4.c unittest5.c bst.c compare.c
	echo "Result for running BST tests:" > tests.out
	
	echo "unittest1.c:" >> tests.out
	gcc -o unittest1 compare.c bst.c unittest1.c $(CFLAGS)
	unittest1 >> tests.out
	gcov bst.c >> tests.out
	
	echo "unittest2.c:" >> tests.out
	gcc -o unittest2 compare.c bst.c unittest2.c $(CFLAGS)
	unittest2 >> tests.out
	gcov bst.c >> tests.out
	
	echo "unittest3.c:" >> tests.out
	gcc -o unittest3 compare.c bst.c unittest3.c $(CFLAGS)
	unittest3 >> tests.out
	gcov bst.c >> tests.out
	
	echo "unittest4.c:" >> tests.out
	gcc -o unittest4 compare.c bst.c unittest4.c $(CFLAGS)
	unittest4 >> tests.out
	gcov bst.c >> tests.out
	
	echo "unittest5.c:" >> tests.out
	gcc -o unittest5 compare.c bst.c unittest5.c $(CFLAGS)
	unittest5 >> tests.out
	gcov bst.c >> tests.out

clean:
	rm tests.out

cleanall: 
	rm tests.out unittest1 unittest2 unittest3 unittest4 unittest5 *.gcda *.gcno *.gcov
