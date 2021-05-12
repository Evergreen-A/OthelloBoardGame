# Softwareproject2
Software engineering project on Othello board game.
To begin, I have to break up the entire program into different components
To begin, I have to break up the entire program into different components


Initialisation

Made #defines for EMPTY = 0 BLACK = 1 WHITE = 2

• Taking in user input for name, assigning disc colour
 - Take in user name using scanf into a global character array
 - set colour to black (bw = black)

• Setting up board and score tracker
 - 2d array + initial black and white in the middle
 - Made black start first using array notation (board[HEIGHT / 2 - 1][WIDTH / 2 - 1] = BLACK;)
 - The current score found if, you count the 2d array and increment a counter for each value in the 2d array corresponding to a player black or white.

• Set up function to print 2d array (board)
 - Two for loops and a switch case
   if EMPTY print -
   if BLACK print B
   if WHITE print W



The game
• Take user input of where to make a move.
 - User input from keyboard
 - Take in x-axis and y-axis using scanf

• Is the move valid?
 - function that checks if number is in the perimeter and not past the board size
  if ( ((x >= 0) && (y <= 7)) || ((y >= 0) && (x <= 7)) )

 - function that checks if input is to an empty position and returns something
  if (input == empty)

 - If the placed disc can capture at least one disc of other colour
   multiple comparisons needed


  first step is to check if a disc position + a move in a direction holds an opponents' disc
  if (move + direction == opponent peice){

  if it does, continue in that direction and look for a bracketting peice that will allow you to flip
  the entire row, if you can flip an entire row with no errors (like a space inbetween)
  then this is a valid move
  }

  if you check in all directions and there is no opponent disc next to your disc
  this is not a valid move

• Flip the row/column/diagonal
If a move a user attempts to make is successful we then call a flipping function
The flipping function is recursive and explained more in depth above the function in the .c file

we make all squares on the board = the current player and swap the current player

• Skipping and ending the game
If the user doesnt have a valid move they can input pass to skip their turn
I then call the valid move function to check if they have any moves, if they do
their inout to skip is denied and they are told that they have valid moves if not
they can skip

if they skip and the opponent skips because they also dont have a valid move the game ends



Ending The game
• Deciding the winner and printing the board
Compare the both players's score and the bigger one wins
Then print out the winner (name) the score, and the final board.

• Writing to file
#include <time.h> to get the current time
using fprintf, print the date and time of the game and the result of the game to a file othello-results.txt.




