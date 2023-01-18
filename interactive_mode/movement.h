#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "penguins.h"

/* Declaration -  extern int player_number allocates the memory for each player's number, penguin amount and dimensions
of the board. */
extern int player_number, penguins, x, y;

void place_penguin(Player* playa, int** board);
/* 
This function places the penguin of the player pointed by the given Player pointer on the board according to
the coordinates stored in the global int variables x and y. Since those variables store coordinates in the starting
from 1 idnexing convention it has to convert it to the starting from 0 indexing convetion to allow for
operation on the two dimensional int array storing the board values. It collects the fish from that tile 
adds it to the players score as well as records the position of the penguin in one of the objects in the players 
dynamic Penguin array attribute, which denotes the penguin that has just been placed. The function
also changes the value of the tile where the penguin was placed to the players index.
*/

void move_penguin(int** board, Player* playa, int x_penguin, int y_penguin, int x, int y);
/* 
This function moves the penguin located at coordinates denoted by the global int variables x_penguin and y_penguin
of the player pointed by the given Player pointer to the coordinates stored in the global int variables x and y. Since all four of
those variables store coordinates in the starting from 1 idnexing convention it has to convert it to the starting 
from 0 indexing convetion to allow for operation on the two dimensional int array storing the board values. It collects 
the fish from that tile and adds it to the players score as well as records the new position of the penguin in one of 
the objects in the players dynamic Penguin array attribute, which denotes the penguin that has just been placed. 
The function also changes the value of the tile where the penguin was placed to the players index.
*/