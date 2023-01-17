#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "penguins.h"

/* Declaration -  extern int player_number allocates the memory for each player's number, penguin amount and dimensions
of the board. */
extern int player_number, penguins, x, y, rows, columns;

int determine_quadrant_with_least_penguins(Player playa, int** board);

void automatic_placement_quadrant_method(Player playa, int** board);

void determine_which_quadrants_are_full(int** board, int quadrants[4]);

void automatic_placement_chess_method(Player playa, int** board);

/* Function place_penguin is required to place the penguins on the board. */
Player place_penguin(Player playa, int** board);

int determine_best_direction_to_move_penguin_fishwise(int** board, int x_penguin, int y_penguin);

void automatically_pick_movement_coordinates(Player playa, int** board);

/* Function move_penguin is expected to move the penguin to the right place on a board. */
Player move_penguin(int** board, Player playa, int x_penguin, int y_penguin, int x, int y);
