/* -----------------------------------------------------------------------
 * Martha Gebremariam
 * CS362_SP2016
 * Assignment 3
 * Description: Unit test for getCost() function in dominion.c
 * 
 * The following lines were also included makefile:
 *
 * unittest3: unittest3.c dominion.o rngs.o
 * gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */



#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {
    int passedTest=0;
    int failedTest=0;
    printf("\n\n*************************\n");
    printf ("TESTING getCost()\n");
    printf("*************************\n\n");

    printf("testing cost of curse\n");
    printf("returned = %d, expected = %d\n\n", getCost(0), 0);
    if (getCost(0) == 0){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(getCost(0) == 0);
 
    printf("testing cost of estate\n");
    printf("returned = %d, expected = %d\n\n", getCost(1), 2);
    if (getCost(1) == 2){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(getCost(1) == 2);
    

    printf("testing cost of duchy\n");
    printf("returned = %d, expected = %d\n\n", getCost(2), 5);
    if (getCost(2) == 5){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(getCost(2) == 5);
    
    printf("testing cost of province\n");
    printf("returned = %d, expected = %d\n\n", getCost(3), 8);
    if (getCost(3) == 8){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(getCost(3) == 8);
    
    printf("testing cost of copper\n");
    printf("returned = %d, expected = %d\n\n", getCost(4), 0);
    if (getCost(4) == 0){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(getCost(4) == 0);
    
    printf("testing cost of silver\n");
    printf("returned = %d, expected = %d\n\n", getCost(5), 3);
    if (getCost(5) == 3){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(getCost(5) == 3);
    
    printf("testing cost of gold\n");
    printf("returned = %d, expected = %d\n\n", getCost(6), 6);
    if (getCost(6) == 6){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(getCost(6) == 6);
    
    printf("testing cost of adventurer\n");
    printf("returned = %d, expected = %d\n\n", getCost(7), 6);
    if (getCost(7) == 6){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(getCost(7) == 6);
    
    printf("testing cost of council_room\n");
    printf("returned = %d, expected = %d\n\n", getCost(8), 5);
    if (getCost(8) == 5){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(getCost(8) == 5);
 
    printf("testing cost of feast\n");
    printf("returned = %d, expected = %d\n\n", getCost(9), 4);
    if (getCost(9) == 4){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(getCost(9) == 4);
    
    printf("testing cost of gardens\n");
    printf("returned = %d, expected = %d\n\n", getCost(10), 4);
    if (getCost(10) == 4){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(getCost(10) == 4);
    
    printf("testing cost of mine\n");
    printf("returned = %d, expected = %d\n\n", getCost(11), 5);
    if (getCost(11) == 5){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(getCost(11) == 5);
    
    printf("testing cost of remodel\n");
    printf("returned = %d, expected = %d\n\n", getCost(12), 4);
    if (getCost(12) == 4){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(getCost(12) == 4);
    
    printf("testing cost of smithy\n");
    printf("returned = %d, expected = %d\n\n", getCost(13), 4);
    if (getCost(13) == 4){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(getCost(13) == 4);
    
    printf("testing cost of village\n");
    printf("returned = %d, expected = %d\n\n", getCost(14), 3);
    if (getCost(14) == 3){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(getCost(14) == 3);
        
    printf("testing cost of baron\n");
    printf("returned = %d, expected = %d\n\n", getCost(15), 4);
    if (getCost(15) == 4){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(getCost(15) == 4);
    
    printf("testing cost of greathall\n");
    printf("returned = %d, expected = %d\n\n", getCost(16), 3);
    if (getCost(16) == 3){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(getCost(16) == 3);
 
    printf("testing cost of minion\n");
    printf("returned = %d, expected = %d\n\n", getCost(17), 5);
    if (getCost(17) == 5){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(getCost(17) == 5);
    
    printf("testing cost of steward\n");
    printf("returned = %d, expected = %d\n\n", getCost(18), 3);
    if (getCost(18) == 3){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(getCost(18) == 3);
    
    printf("testing cost of tribute\n");
    printf("returned = %d, expected = %d\n\n", getCost(19), 5);
    if (getCost(19) == 5){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(getCost(19) == 5);
    
    printf("testing cost of ambassador\n");
    printf("returned = %d, expected = %d\n\n", getCost(20), 3);
    if (getCost(20) == 3){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(getCost(20) == 3);
    
    printf("testing cost of cutpurse\n");
    printf("returned = %d, expected = %d\n\n", getCost(21), 4);
    if (getCost(21) == 4){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(getCost(21) == 4);
    
    printf("testing cost of embargo\n");
    printf("returned = %d, expected = %d\n\n", getCost(22), 2);
    if (getCost(22) == 2){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(getCost(22) == 2);
    
    printf("testing cost of outpost\n");
    printf("returned = %d, expected = %d\n\n", getCost(23), 5);
    if (getCost(23) == 5){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(getCost(23) == 5);

    printf("testing cost of salvager\n");
    printf("returned = %d, expected = %d\n\n", getCost(24), 4);
    if (getCost(24) == 4){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(getCost(24) == 4);
    
    printf("testing cost of sea_hag\n");
    printf("returned = %d, expected = %d\n\n", getCost(25), 4);
    if (getCost(25) == 4){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(getCost(25) == 4);
    
    printf("testing cost of treasure_map\n");
    printf("returned = %d, expected = %d\n\n", getCost(26), 4);
    if (getCost(26) == 4){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(getCost(26) == 4);
    
    printf("testing cost of unknown (out of bound card)\n");
    printf("returned = %d, expected = %d\n\n", getCost(27), -1);
    if (getCost(27) == -1){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(getCost(27) == -1);
    
    printf("Passed %d and failed %d of the unittest3 tests\n", passedTest, failedTest);
    return 0;
}
