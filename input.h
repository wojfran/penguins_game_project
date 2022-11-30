#include "player.h"

void set_board_dimensions();
// a function which asks players for board dimensions(length and width)

void set_number_of_players_and_penguins();
 // used for determining numbers of players and penguins

void ask_for_coordinates_to_place_penguin(Player playa);
 // this function lets user to enter the coordinates that they want to move

void ask_for_penguin_id(Player playa);

void ask_for_penguin_coordinates(Player playa, int** board);
 // it supposed to let user to specify coordinates where they want to move their penguins

int are_coordinates_valid(int** board, int x, int y);
// checks if the specified coordinates for a penguin to place are valid