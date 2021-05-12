//
// Created by eabag on 03/05/2021.
//

#include <stdio.h>
#include <stdlib.h>

#ifndef OTHELLO_PROJECT_VALIDMOVETEST_H
#define OTHELLO_PROJECT_VALIDMOVETEST_H

int findbracketpiece(int xmove,int ymove,int bw,int dx,int dy);
int couldflip (int bw,int x,int y,int dx,int dy);
int perimeter_test (int x, int y);
int is_move_valid (int bw, int x, int y);
int test_all_available_moves (int player);
int convert_letter_to_number(char letter);

#endif //OTHELLO_PROJECT_VALIDMOVETEST_H

