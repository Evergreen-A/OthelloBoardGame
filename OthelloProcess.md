# Softwareproject2
Software engineering project on Othello board game.
To begin, I have to break up the entire program into different components

Initialisation
• Taking in user input for name, assigning disc colour
• Setting up board and score tracker
 - 2d array + initial black and white in the middle
 - Make black start first
 - The current score can be found if, you count the 2d array and
   increment a counter for each value in the 2d array corresponding
   to a player black or white.
• Set up function to print 2d array

The game
• Take user input of where to make a move.
 - User input from keyboard
 - Format of ld (letter(a-h) / number(1-8))
 - letter is x-axis number is y-axis
 - check if input is value in ld format

• Is the move valid?
 - If ld format is in-between a-h and 1-8 (not on the edge of board)
  simple if check

 - If disc is already there
 simple if check

 - If the placed disc can capture at least one disc of other colour
 multiple comparisons and need to check direction
 
if move + direction = an opponent peice
return a New function that checks for a bracketing peice of the current players color
it takes in next step

to find opponent do an if condition to check whos turn it is,
if white opponent is black, vice versa

int (funtion_to_check_if_peice_in_middle_is_opposite){


if (turn = black){
 int oppdisc = movechoice + direction;
 if(board[oppdisc] == White){
   int nextstep = oppdisc + direction
   return checking_for_bracket_of_same_colour_blackplayer(nextstep)
 }
}

if (turn = white){
 int oppdisc = movechoice + direction;
 if(board[oppdisc] == black){
   int nextstep = oppdisc + direction
   return checking_for_bracket_of_same_colour_whiteplayer(nextstep)
 }
}

}


int (checking_for_bracket_of_same_colour_blackplayer){
while (board[nextstep] == white) nextstep = nextstep + direction;
if (board[nextstep] == black) return nextstep;
else return 0;
}



