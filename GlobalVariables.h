//
// Created by eabag on 03/05/2021.
//

#ifndef OTHELLO_PROJECT_GLOBALVARIABLES_H
#define OTHELLO_PROJECT_GLOBALVARIABLES_H

#define WIDTH 8
#define HEIGHT 8

#define EMPTY 0
#define BLACK 1
#define WHITE 2

//initialising global variables board, total player score
extern int turn_timer;
extern int board[HEIGHT][WIDTH];
extern char name1[20];
extern char name2[20];
extern int blkplayerscore;
extern int whtplayerscore;

#endif //OTHELLO_PROJECT_GLOBALVARIABLES_H
