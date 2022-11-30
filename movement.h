#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "penguins.h"
extern int player_number, penguins, x, y;

void place_penguin(Player playa, int** board);

void move_penguin(int** board, Player playa, int x_penguin, int y_penguin, int x, int y);