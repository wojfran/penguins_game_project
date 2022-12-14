#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "penguins.h"

/* Declaration -  extern int player_number allocates the memory for each player's number, penguin amount and dimensions
of the board. */
extern int player_number, penguins, x, y;

/* Function place_penguin is required to place the penguins on the board. */
Player place_penguin(Player playa, int** board);

/* Function move_penguin is expected to move the penguin to the right place on a board. */
Player move_penguin(int** board, Player playa, int x_penguin, int y_penguin, int x, int y);
