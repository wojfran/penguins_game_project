#include "player.h"

int check_if_penguin_belongs_to_player(int** board, Player playa, int x, int y);
/*
This function checks if the penguin situated on the x and y coordinates of the board (indexing 
from 0 convetion) given as a dynamic int 2d array in function parameters belongs to the Player 
structure object playa also given as a function parameter. It does so by iteratign through the
players dynamic array of Penguin structure objects attribute called pingu and checking if 
any of the Penguin objects in that array have its coordinate parameters set to x and y.
If it finds such a penguin the function returns 1, else it prints the appropriate warning.
*/

int check_if_coordinate_matches_board(int b_dimension, int x);
/*
This function checks if the given coordinate matches its dimesnion of the board.

int b_dimension signifies the dimension of the board (either rows or columns) and
int x denotes the coordinate under examination, in the case of columns it should be 
an x value, in the case of rows it should be a y value.

If the coordinate is bigger than 0 and not greater than the dimension the function
returns 1, else it prints a warning and returns 0. 
*/

int check_if_given_dimension_is_ok(int x);
/*
This method checks if the int x given as function parameter is within the acceptable bounds
for a value of the board row/column i.e. bigger than 1 and smaller than 100. If it is acceptable
the functions returns 1, else it prints a warning and returns 0. 
*/

int check_if_ice_has_fish(int** board, int x, int y);
/*
This method checks if the tile of the board with the coordinates x and y given as parameters
along with the dynamic int 2d array storing the board has any fish on itself i.e. the value stored
by it is between 1 and 3 (inclusive). If so it returns 1 else it prints an appropriate warning
and returns 0. 
*/

int check_if_number_of_players_or_penguins_correct(int num);
/*
This function checks if the integer num given as a parameter is within the range of 
1 to 4 (inclusive). It is used to determine whether the amount of desired players or penguins
given as input is acceptable. 

The assumption is that no more than 4 players and 4 penguins are allowed. The possibility of
picking 1 player is left there mostly for diagnostics, unless someone is very lonely ;)
*/

int check_if_penguin_is_not_flying(int x_penguin, int y_penguin, int x, int y);
/*
This function checks if the deltas between given parameters x_penguin and x, as
well as bewteen y_penguin and y are acceptable i.e. if a move from the coordinates
x_penguin, y_penguin can be made to x, y within the rules of the game. This means 
that the only possible change of cooridnates is a change to the right, left, up or down
by 1. No diagonal moves are tolerated.

If the move is acceptable, the function returns 1, else it prints a warning and returns 0.
*/

int check_if_current_players_penguins_can_be_placed(Player playa);
/*
This function checks if the Player structure object playa, given as a parameter, 
can place any of its penguins i.e. if any Penguin structure object in its dynamic 
Penguin array attribute pingu has their attribute called flag set to 1.
*/

int can_any_penguins_be_placed(Player* playa);
/*
Used in the placement phase, checks if any player stored in the given dynamic
Player structure array has has any penguins which can be placed. It does so 
by iterating through the array and with each iteration, iterating over the Player
object's pingu (dynamic Penguin structure array) attribute holding the players penguins.
If the flag attribute of at least one Penguin object is set to 1 (denoting that it hasn't
been placed) the function returns 1, else it returns 0.
*/

int check_if_penguin_can_move(int** board, int x_penguin, int y_penguin); 
/*
This function check if the penguin of the given coordinates x_penguin and y_penguin
stored in the indexing from 0 convention can move in any direction. 

Since depending on the location of the penguin on the board only a select amount of
directions can be checked i.e. a penguin in the upper left corner could possibly only 
go right and down, the function considers all of the possible location scenarios in order
to protect the program from a segmentation fault. 

Once the function determines the location scenario that the penguin is in, it begins
to check if the available directions are plausible i.e. if the value on the tile in that
direction is bigger than 0 and modulo 10 yields zero, signifying that the tile is not 
empty and is not occupied.
*/


int can_any_penguins_move(Player* playa, int** board);
/*
This function iterates through avery penguin stored in the dynamic Penguin structure array
attribute of every Player object on the dynamic Player structure array playa given as a 
parameter.

With each iteration it checks if the given penguin can move using the:
    - int check_if_penguin_can_move(int** board, int x_penguin, int y_penguin)
function. If this helper function determines that one of these penguins can move
the function stops iterating and returns 1, else if no penguins can move it returns 0.
*/
