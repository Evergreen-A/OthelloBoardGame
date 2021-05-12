//
// Created by eabag on 03/05/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "FlipDiscs.h"
#include "ValidMoveTest.h"
#include "GlobalVariables.h"

//initialising 1 and 0, height amd width etc....
#define WIDTH 8
#define HEIGHT 8

#define EMPTY 0
#define BLACK 1
#define WHITE 2


//recursive function because dx and dy values given before keep getting added
//on to make it continue checking in that direction to go down just keep
//adding 1 to the y value, to go up just -1 from y value etc....

int check_direction(int bw,int x,int y,int dx,int dy){

    if(x < 0 || WIDTH <= x) return 0;
    if(y < 0 || HEIGHT <= y) return 0;

    // if there is a gap in the line to flip return 0
    if(board[y][x] == EMPTY) return 0;

    //if there is a bracketting disc
    if(board[y][x] == bw) return 1;
    else {
        if(check_direction(bw, x + dx, y + dy, dx, dy)){
            //flipping the items into the players' colour
            board[y][x] = bw;
            return 1;
        } else return 0;
    }
}



//check if If the placed disc can capture at least one disc of other colour then flip them
int any_legal_direction(int bw,int x,int y){
    int dir_count = 0;

// counts the number of directions that discs are going to be flipped
    dir_count += check_direction(bw, x, y - 1,  0, -1);
    dir_count += check_direction(bw, x, y + 1,  0,  1);//down
    dir_count += check_direction(bw, x - 1, y, -1,  0);//left
    dir_count += check_direction(bw, x + 1, y,  1,  0);//right

    dir_count += check_direction(bw, x - 1, y - 1, -1, -1);//up left
    dir_count += check_direction(bw, x + 1, y - 1,  1, -1);//up right
    dir_count += check_direction(bw, x - 1, y + 1, -1,  1);//down left
    dir_count += check_direction(bw, x + 1, y + 1,  1,  1);//down right

    return dir_count;
}


int anylegalmove(int bw,int x,int y){

    /* If the position player has chosen is occupied return 0 */
    if(board[y][x] != EMPTY) return 0;

    // If function is > 0 (a move can be made)
    // make the position player has chosen swap

    if(any_legal_direction(bw,x,y) > 0){
        board[y][x] = bw;
        turn_timer++;
        return 1;
    } else return 0;
}
