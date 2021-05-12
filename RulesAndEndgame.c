//
// Created by eabag on 03/05/2021.
//

#include <stdio.h>
#include "ValidMoveTest.h"
#include "RulesAndEndgame.h"
#include "BoardandOpponent.h"
#include "GlobalVariables.h"

//initialising 1 and 0, height amd width etc....
#define WIDTH 8
#define HEIGHT 8

#define EMPTY 0
#define BLACK 1
#define WHITE 2

//skip or end game function that either skips or ends the game
int Skip_or_End_game (int currentplayer) {

    //variables
    int oppo;//opponent
    char pass;//user choice to pass
    oppo = opponent(currentplayer);

    //if the test_all_available_moves function returns a number > 0 (1)
    //for the current players turn
    if (test_all_available_moves(currentplayer) > 0) return 5;

    //if the test_all_available_moves function returns a number > 0 (1)
    //for opponent players' turn
    if (test_all_available_moves(oppo) > 0) {

        if (currentplayer == BLACK) {
            printf("%s has no moves and must pass.\n", name1);
        }

        if (currentplayer == WHITE) {
            printf("%s has no moves and must pass.\n", name2);
        }

        printf("Enter P to pass.\n");
        scanf(" %c",&pass);

        return 10;
    }

    return 0;
}


void rules(void){
    printf("Here is a link to othello rules:\n");
    printf("https://www.worldothello.org/about/about-othello/othello-rules/official-rules/english\n\n");
}