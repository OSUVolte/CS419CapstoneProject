cmake_minimum_required(VERSION 3.5)
project(dominion)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    badTestDrawCard.c
    betterTestDrawCard.c
    dominion.c
    dominion.h
    dominion_helpers.h
    interface.c
    interface.h
    playdom.c
    player.c
    rngs.c
    rngs.h
    rt.c
    supplyTest.c
    testBuyCard.c
    testDrawCard.c
    testInit.c
    testShuffle.c unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c coverage1.c bug1.c)

add_executable(dominion ${SOURCE_FILES} unittest1.c unittest2.c)