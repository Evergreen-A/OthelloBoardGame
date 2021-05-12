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

// finding bracketting peice to check if the move is valid
int findbracketpiece(int xmove,int ymove,int bw,int dx,int dy) {

//while the current peice is an opponents peice continue in the same direction
    while (board[ymove][xmove] == opponent(bw)){
        xmove = xmove + dx;
        ymove = ymove + dy;
    }

// if the peice is a bracketting peice return 1 / 1
    if (board[ymove][xmove] == bw){
        return 1;
    }
    else return 0;
}



//This function checks if a move in a certain direction would flip at least one opponents disc
//then calls another function to check for a bracketting peice to make sure a whole row can be flipped
int couldflip (int bw,int x,int y,int dx,int dy) {
    int xmove, ymove;
    xmove = x + dx;
    ymove = y + dy;

    //if the co-ordinate currently at is your opponents disc keep going
    //in that direction until you find a bracketting peice or not
    if (board[ymove][xmove] == opponent(bw)){
        return findbracketpiece(x+dx, y+dy, bw, dx, dy);
    } else return 0;
}



/* a valid move must be a non-perimeter square */
int perimeter_test (int x, int y) {
    if ( ((x >= 0) && (y <= 7)) || ((y >= 0) && (x <= 7)) )
        return 1;
    else return 0;
}

//function that tests if move is valid
int is_move_valid (int bw, int x, int y) {

    int i = 0;
    int j = 0;

    //checks if user inputs arent on the board
    if (!perimeter_test(x, y)) return 0;

    //if user input is an empty square continue, if not return 0
    if (board[y][x] == EMPTY) {

        //while loop from 0 - 7
        while (i<=7){

            //switch cases with i to check all directions the board can go
            switch(i)
            {
                //if i == 0 call function for this direction
                case 0:
                    if (couldflip(bw, x, y,  0, -1) != 0) {
                        j++;
                    }
                    break;

                case 1:
                    if (couldflip(bw, x, y,  0,  1) != 0) {
                        j++;
                    }
                    break;

                case 2:
                    if (couldflip(bw, x, y, -1,  0) != 0) {
                        j++;
                    }
                    break;

                case 3:
                    if (couldflip(bw, x, y,  1,  0) != 0) {
                        j++;
                    }
                    break;

                case 4:
                    if (couldflip(bw, x, y, -1, -1) != 0) {
                        j++;
                    }
                    break;

                case 5:
                    if (couldflip(bw, x, y,  1, -1) != 0) {
                        j++;
                    }
                    break;

                case 6:
                    if (couldflip(bw, x, y, -1,  1) != 0) {
                        j++;
                    }
                    break;

                case 7:
                    if (couldflip(bw, x, y,  1,  1) != 0) {
                        j++;
                    }
                    break;

                default:
                    printf("You shouldn't see this text");
            }//end of switch case
            i++;
        }//end of while loop
        if (j == 0) return 0; else return 1;
    }//end of if condition
    else return 0;
}//end of function


int test_all_available_moves (int player) {

    //variables
    int xmove, ymove, valid = 0;

    //loop through all squares in the grid and call function is_move_valid
    for (ymove = 0; ymove <= 7; ymove++) {
        for (xmove = 0; xmove <= 7; xmove++) {
            if(is_move_valid(player, xmove, ymove)){
                valid++;
            }
        }
    }

//extra function I implemented that tells the user how many valid moves there are
    if (player == BLACK) {
        printf("There are %d valid positions to place a disc for '%s' (Black)\n", valid, name1);
    }

    if (player == WHITE) {
        printf("There are %d valid positions to place a disc for '%s' (white)\n", valid, name2);
    }

    if (valid > 0) {
        return 1;
    } else return 0;

}

int convert_letter_to_number(char letter){
    //function to convert input letter to number
    //Using simple if statements and returning the correct value
    if(letter == 'a' || letter == 'A'){
        return 1;
    }
    if(letter == 'b' || letter == 'B'){
        return 2;
    }
    if(letter == 'c' || letter == 'C'){
        return 3;
    }
    if(letter == 'd' || letter == 'D'){
        return 4;
    }
    if(letter == 'e' || letter == 'E'){
        return 5;
    }
    if(letter == 'f' || letter == 'F'){
        return 6;
    }
    if(letter == 'g' || letter == 'G'){
        return 7;
    }
    if(letter == 'h' || letter == 'H'){
        return 8;
    }else{
        return -1;
    }

}