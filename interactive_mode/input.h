#include "player.h"

void set_board_dimensions();
/*
This function asks player to input the board dimensions and uses the function:

    - int check_if_given_dimension_is_ok(int x)

to check if the dimension given as input is acceptbale i.e. greater than 1 and 
smaller than 100. If that condition is not fulfilled a warning will be printed 
and the player will be asked for input continuosuly until it is correct. Once the 
input is correct it will store the input values in the global int variables called
rows and columns.
*/

void set_number_of_players_and_penguins();
/*
This function asks the player to input the amount of players which will be playing
the game and the amount of penguins which shall be given to each player. Both of these
values are checked using the function:

    -   int check_if_number_of_players_or_penguins_correct(int num)

and have to be within the bound of 1-4 (inclusive). If the given input does not 
conform with those bounds a warning will be printed and the player will be asked for
input continuosuly until it is correct. Once the input is correct it will store the 
input values in the global int variables called players and penguins.
*/

void ask_for_coordinates_to_place_penguin(Player playa, int** board);
/*
This function asks the player to input the board coordinates to place their penguin in 
the placement phase (in indexing from 1 convention). It uses functions:

    - int check_if_coordinate_matches_board(int b_dimension, int x)
    - int check_if_ice_has_fish(int** board, int x, int y)

to check if the coordinates given as input match the board i.e. are not out of bounds
and whether the tile of those coordinates contains any fish i.e. is not empty and is not
occupied by another penguin. If the given input does not conform with those bounds an 
appropriate warning will be printed and the player will be asked for input continuosuly 
until it is correct, else the global int x and y variables will be set to the
input values.
*/

void ask_for_penguin_coordinates(Player playa, int** board);
/*
This function asks the player to input the board coordinates of the penguin belonging
to them that they wish to move during the movement phase (in indexing from 1 convention). 
It uses functions:

    - int check_if_coordinate_matches_board(int b_dimension, int x)
    - int check_if_penguin_belongs_to_player(int** board, Player playa, int x, int y)
    - int check_if_penguin_can_move(board, x_penguin, y_penguin)

to check if the coordinates given as input match the board i.e. are not out of bounds, 
whether the tile contains the penguin belonging to the player and if so whether that penguin
can move in any direction. If the given input does not conform with those bounds an 
appropriate warning will be printed and the player will be asked for input continuosuly 
until it is correct, else the global int x_penguin and y_penguin variables will be set to the
input values.
*/

void ask_for_coordinates_to_move_penguin(Player playa, int** board);
/*
This function asks the player (given as input parameter) to input the board coordinates of 
the board (given as input parameter) where they wish to move their penguin 
(picked by ask_for_penguin_coordinates function) during the movement 
phase (in indexing from 1 convention). It uses functions:

    - int check_if_coordinate_matches_board(int b_dimension, int x)
    - int check_if_ice_has_fish(int** board, int x, int y)
    - int check_if_penguin_is_not_flying(int x_penguin, int y_penguin, int x, int y)

to check if the coordinates given as input match the board i.e. are not out of bounds, 
whether the tile of those coordinates contains any fish i.e. is not empty and is not
occupied by another penguin, as well as if movement of the penguins conforms to the rules
of the game i.e. if it a one tile movement to the right, left, up or down.
If the given input does not conform with those bounds an appropriate warning will be 
printed and the player will be asked for input continuosuly until it is correct, else 
the global int x and y variables will be set to the input values.
*/
