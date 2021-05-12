/*
Evergeen Abagha 20432286
Othello board game
*/

#include <stdio.h>
#include <time.h>
#include "FlipDiscs.h"
#include "ValidMoveTest.h"
#include "RulesAndEndgame.h"
#include "BoardandOpponent.h"


//initialising 1 and 0, height amd width etc....
#define WIDTH 8
#define HEIGHT 8

#define EMPTY 0
#define BLACK 1
#define WHITE 2

//initialising global variables board, total player score
int turn_timer;
int board[HEIGHT][WIDTH];
char name1[20];
char name2[20];
int blkplayerscore;
int whtplayerscore;


int main(void) {

    //variables for the user input
    //user input for x and y values
    int x_axis_value;
    int y_axis_value;
    char xaxis;


    //keeps track of current player
    int bw;

    // used for condition of do while loop
    int holder1 = 1;

    //condition to swap the player
    int flip = 0;

    //user input if they want to see rules
    int see_rules = 0;

    printf("Welcome to the game Othello!\n\n");

    printf("Do you want to read the rules of Othello? (enter 1 for yes or 2 for no) \n");
    scanf("%d", &see_rules);

    //if user gives random input
    if (!(see_rules == 1 || see_rules == 2)) {
        printf("I will assume you know the rules\n");
        see_rules = 2;
        fflush(stdin);
    }

    printf("\n");

    //if user chooses to see the rules
    if (see_rules == 1) {
        printf("\n");
        rules();//calling rules
    }

    printf("You will be prompted to enter your name, enter it as one word please.\n\n");

    //getting users name
    printf("Enter player1's name (You will be the black player): ");
    scanf("%s", name1);

    printf("\n");

    //getting users name
    printf("Enter player2's name (you will be the white player): ");
    scanf("%s", name2);


    /* initialize boards and printing it */
    initialise_board();
    print_board();


    /* starting player is set to black */
    //bw used to track who current player is
    bw = BLACK;
    do {

        //if current player is black
        if (bw == BLACK) {

            //player assigned to blacks turn
            printf("%s's turn (Black)\n", name1);

            /* user input */
            printf("Enter value in format 'ld', l = letter on x-axis (a-h), d = number on y-axis (1-8) i.e f3\n");
            // scanf(" %c",&xaxis);
            scanf(" %c%d", &xaxis, &y_axis_value);
            x_axis_value = convert_letter_to_number(xaxis);

            // printf("Enter value on y axis: ");
            // scanf("%d",&y_axis_value);
            // printf("\n");

            // functions that take in users input and does two things
            // is_move_valid function checks if the move is valid
            // anylegalmove flips the opponents items you have flanked
            if (is_move_valid(bw, x_axis_value - 1, y_axis_value - 1)) {
                if (anylegalmove(bw, x_axis_value - 1, y_axis_value - 1)) {

                    //increment flip to swap player and print board
                    flip = 1;
                    print_board();
                }
            }
        } else {//if it's the player assigned to white's turn
            printf("%s's turn (White)\n", name2);

            printf("Enter value in format 'ld' l = letter on x-axis (a-h), d = number on y-axis (1-8) i.e f3\n");
            // scanf(" %c",&xaxis);
            scanf(" %c%d", &xaxis, &y_axis_value);
            x_axis_value = convert_letter_to_number(xaxis);

            printf("\n");

            // functions that take in users input and does two things
            // is_move_valid function checks if the move is valid
            // anylegalmove flips the opponents items you have flanked
            if (is_move_valid(bw, x_axis_value - 1, y_axis_value - 1)) {
                if (anylegalmove(bw, x_axis_value - 1, y_axis_value - 1)) {
                    // increment flip and print board
                    flip = 1;
                    print_board();
                }
            }
        }

        // if the flip variable hasn't been incremented the move was invalid
        if (flip == 0) {
            printf("invalid place to put a disc!\n\n");
        }

        // if the flip variable in incremented (when a user completes turn)
        // then swap user
        if (flip == 1) {
            flip = 0;
            bw = bw == WHITE ? BLACK : WHITE;//next turn change
        }

        //function to choose whether player is skipping or game ends
        holder1 = Skip_or_End_game(bw);

        // if the Skip_or_End_game function returns 10
        // it means the player chose to pass, this code swaps the player
        if (holder1 == 10) {

            if (bw == BLACK) {
                bw = WHITE;
            }

            if (bw == WHITE) {
                bw = BLACK;
            }

        }

    }
    while (holder1 != 0);//while condition for do while loop

    //making pointer and opening file
    FILE * fp;
    fp = fopen("othello-results.txt","w");

    //initialising time from time.h
    time_t timeanddate;
    time(&timeanddate);

    printf("\n\n\nThe game is over!!\n");
    printf("The final board with the scores is:\n");
    //printing final board
    print_board();

    // if the player with the black disc wins do this
    if (blkplayerscore > whtplayerscore) {

        printf("The winner of the game is %s with %d discs in possession.\n", name1, blkplayerscore);

        //writing to file
        fprintf(fp, "%s (black) won the game\n", name1);

        fprintf(fp, "They had a score of %d discs \n", blkplayerscore);

        fprintf(fp, "The time of the game was: %s\n", ctime(&timeanddate));
    }

    // if the player with the white disc wins do this
    if (whtplayerscore > blkplayerscore) {
        printf("The winner of the game is %s with %d discs in possession.\n", name2, whtplayerscore);

        //writing to file
        fprintf(fp, "%s (White) won the game\n", name2);

        fprintf(fp, "They had a score of %d discs\n", whtplayerscore);

        fprintf(fp, "The time of the game was: %s\n", ctime(&timeanddate));
    }

    // if both players draw do this
    if (blkplayerscore == whtplayerscore) {
        printf("Its a draw with both players having %d discs in possession.\n",whtplayerscore);

        //writing to file
        fprintf(fp, "The time of the game was: %s\n", ctime(&timeanddate));

        fprintf(fp, "%s (Black) ", name1);
        fprintf(fp, "had a score of %d discs \n\n", blkplayerscore);

        fprintf(fp, "%s (White) ", name2);
        fprintf(fp, "had a score of %d discs \n", whtplayerscore);

    }

    //closing file
    fclose(fp);

    return 0;
}
