//
// Created by eabag on 03/05/2021.
//

#include <stdio.h>
#include "ValidMoveTest.h"
#include "BoardandOpponent.h"
#include "GlobalVariables.h"

//initialising 1 and 0, height amd width etc....
#define WIDTH 8
#define HEIGHT 8

#define EMPTY 0
#define BLACK 1
#define WHITE 2

int turn_timer = 0;

// initialising board
void initialise_board() {
    int i,j;
    for(j = 0 ; j < HEIGHT ; ++j){
        for(i = 0 ; i < WIDTH ; ++i){
            board[j][i] = EMPTY;
        }
    }


    //initialize position of starting black and white part
    board[HEIGHT / 2 - 1][WIDTH / 2 - 1] = BLACK;
    board[HEIGHT / 2    ][WIDTH / 2 - 1] = WHITE;
    board[HEIGHT / 2 - 1][WIDTH / 2    ] = WHITE;
    board[HEIGHT / 2    ][WIDTH / 2    ] = BLACK;

    //other properties
    turn_timer = 0;
}


// find opponent of current player playing
int opponent (int player) {
    if (player == WHITE) {
        return BLACK;
    }else{
        return WHITE;
    }
}


// print board and score
void print_board(){
    int i,j;
    blkplayerscore = 0;
    whtplayerscore = 0;

    printf("\n     <------ Turn %d ------>\n",turn_timer);

    /* board */
    for(j = 0 ; j < HEIGHT ; ++j){
        printf("%2d |",j+1);
        for(i = 0 ; i < WIDTH ; ++i){
            switch(board[j][i]){
                case EMPTY:
                    printf(" - ");
                    break;
                case BLACK:
                    printf(" B ");
                    blkplayerscore = blkplayerscore + 1;
                    break;
                case WHITE:
                    printf(" W ");
                    whtplayerscore = whtplayerscore + 1;
                    break;
                default:
                    break;
            }
        }
        printf("\n");
    }

    printf("     a  b  c  d  e  f  g  h\n");//Prints column letters

    printf("\n");
    printf("%s's score is %d\n", name1, blkplayerscore);
    printf("%s's score is %d\n", name2, whtplayerscore);
    printf("\n");

}