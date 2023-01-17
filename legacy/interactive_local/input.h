#include "player.h"

void set_board_dimensions();
// a function which asks players for board dimensions(length and width)

void set_number_of_players_and_penguins();
 // used for determining numbers of players and penguins

void ask_for_coordinates_to_place_penguin(Player playa, int** board);
 // this function lets user to enter the coordinates that they want to move

void ask_for_penguin_id(Player playa);
// this function asks for input id from the player 

void ask_for_penguin_coordinates(Player playa, int** board);
 // it supposed to let user to specify coordinates where they want to move their penguins

void ask_for_coordinates_to_move_penguin(Player playa, int** board);

int check_if_penguin_belongs_to_player(int** board, int x, int y);
// checks if the specified coordinates for a penguin to place are valid

int check_if_coordinate_matches_board(int b_dimension, int x);

int check_if_given_dimension_is_ok(int x);

int check_if_ice_has_fish(int** board, int x, int y);

int check_if_number_of_players_or_penguins_correct(int num);

int check_if_penguin_is_not_flying(int x_penguin, int y_penguin, int x, int y);

int check_if_penguin_can_move(int** board, int x_penguin, int y_penguin); 

int can_any_penguins_move(Player* playa, int** board);
