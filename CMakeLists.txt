cmake_minimum_required(VERSION 3.17)
project(Othello_project C)

set(CMAKE_C_STANDARD 11)

add_executable(Othello_project main.c ValidMoveTest.c ValidMoveTest.h FlipDiscs.c FlipDiscs.h RulesAndEndgame.c RulesAndEndgame.h BoardandOpponent.c BoardandOpponent.h GlobalVariables.h)