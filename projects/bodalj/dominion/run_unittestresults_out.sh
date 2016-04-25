fout='unittestresults.out'
>$fout
make clean
make unittest1 
echo "-- unittest1 results --" >> $fout
./unittest1 >> $fout
echo >> $fout
echo "-- gcov for function 'shuffle' in unittest1 --" >> $fout
gcov -fb dominion.c | grep -A 4 "^Function 'shuffle'" >> $fout

make clean
make unittest2 
echo >> $fout
echo "-- unittest2 results --" >> $fout
./unittest2 >> $fout
echo >> $fout
echo "-- gcov for function 'getCost' in unittest2 --" >> $fout
gcov -fb dominion.c | grep -A 4 "^Function 'getCost'" >> $fout


make clean
make unittest3 
echo >> $fout
echo "-- unittest3 results --" >> $fout
./unittest3 >> $fout
echo >> $fout
echo "-- gcov for function 'discardCard' in unittest3 --" >> $fout
gcov -fb dominion.c | grep -A 4 "^Function 'discardCard'" >> $fout

make clean
make unittest4
echo >> $fout
echo "-- unittest4 results --" >> $fout
./unittest4 >> $fout
echo >> $fout
echo "-- gcov for function 'whoseTurn' in unittest4 --" >> $fout
gcov -fb dominion.c | grep -A 4 "^Function 'whoseTurn'" >> $fout

make clean
make cardtest1
echo >> $fout
echo "-- cardtest1 results --" >> $fout
./cardtest1 >> $fout
echo >> $fout
echo "-- gcov for function 'playSmithy' in cardtest1 --" >> $fout
gcov -fb dominion.c | grep -A 4 "^Function 'playSmithy'" >> $fout

make clean
make cardtest2
echo >> $fout
echo "-- cardtest2 results --" >> $fout
./cardtest2 >> $fout
echo >> $fout
echo "-- gcov for function 'playAdventurer' in cardtest2 --" >> $fout
gcov -fb dominion.c | grep -A 4 "^Function 'playAdventurer'" >> $fout

make clean
make cardtest3
echo >> $fout
echo "-- cardtest3 results --" >> $fout
./cardtest3 >> $fout
echo >> $fout
echo "-- gcov for function 'playVillage' in cardtest3 --" >> $fout
gcov -fb dominion.c | grep -A 4 "^Function 'playVillage'" >> $fout

make clean
make cardtest4
echo >> $fout
echo "-- cardtest4 results --" >> $fout
./cardtest4 >> $fout
echo >> $fout
echo "-- gcov for function 'playGreatHall' in cardtest4 --" >> $fout
gcov -fb dominion.c | grep -A 4 "^Function 'playGreatHall'" >> $fout

make clean
make unittest1
make unittest2
make unittest3
make unittest4
make cardtest1
make cardtest2
make cardtest3
make cardtest4
./unittest1
./unittest2
./unittest3
./unittest4
./cardtest1
./cardtest2
./cardtest3
./cardtest4
echo >> $fout
echo >> $fout
echo "Total code coverage for all submitted unit tests against dominion.c" >> $fout
gcov -fb dominion.c >> $fout
