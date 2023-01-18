#include <stdio.h>
#include "player.h"

int read_dimensions(FILE* input);
/*
This functions reads the dimensions of the board from the given file and
stores them in the global int column and row variables. It prints a warning
and returns 0 if they were read incorrectly.
*/

int read_board_values_from_file(FILE* input, int** board);
/*
This function assigns the values to the board according to the ones stored
in the given file. If the value does not match the convention, a warning
is printed and the function returns 0 else it returns 1. 
*/

Player read_player(FILE* input);
/*
This function reads a player recorded in the file and returns it. In the case where 
it reaches eof or is unable to read player attributes from the file, it creates a player
with index == 0 and id == "eof". This way a loop can now when to end reading the players
from the file. 
*/

int check_for_duplicate_player(Player bob, Player* players, int players_size);
/*
This function checks if the Player object named bob has the same index or id attribute as
any of the Player objects in the given players dynamic array. If so, an appropriate warning is printed
and the function returns 0, else the function returns 1.
*/

int read_players_from_file(FILE* input, Player* players);
/*
This function uses the Player read_player(FILE* input) function to read all of the 
players recorded in the file and stores them in the dynamic Player structure array.
It also check whether any of the read players are duplicates of already stored players.
*/

int write_game_state_to_output_file(FILE* output, int** board, Player* players);
/*
This function writes the state of the game to the given output file according to the project
specifications.
*/