#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "penguins.h"

extern int player_number, penguins, x, y, rows, columns;

int check_if_current_players_penguins_can_be_placed(Player playa);
/*
This function checks if the Player structure object playa, given as a parameter, 
Can place any of its penguins i.e. if any Penguin structure object in its dynamic 
Penguin array attribute pingu has their attribute called flag set to 1.
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

int check_if_current_players_penguins_can_move(Player playa, int** board);
/*
This function uses the function:
    - int check_if_penguin_can_move(int** board, int x_penguin, int y_penguin)

to check if any penguin belonging to the given player can move in any direction.
It returns 0 if no penguin belonging to the player can move and 1 if one or more
penguins can indeed move. 
*/

int determine_quadrant_with_least_penguins(Player playa, int** board);
/*
DEPRECATED - HELPER FOR ALGORITHM WHICH IS NO LONGER USED (I am keeping it just in case)

This function determines the quadrant in which the given player has the least amount
of penguins. It returns an array of int of size 4. The values of this array denote:
    - index: 0 - the amount of players penguins in the upper left quadrant
    - index: 1 - the amount of players penguins in the upper right quadrant
    - index: 2 - the amount of players penguins in the bottom left quadrant
    - index: 3 - the amount of players penguins in the bottom right quadrant
*/

void determine_which_quadrants_are_full(int** board, int quadrants[4]);
/*
DEPRECATED - HELPER FOR ALGORITHM WHICH IS NO LONGER USED (I am keeping it just in case)

This function determines if a quadrant of the board is already full i.e. no penguin can be placed.
It does so by iterating through the tiles of each quadrant in search of a tile storing a 10 value.
If it doesn't find such a tile, it sets the value of in an array of ints called quadrants to 999. 
The index of the value corresponds to the quadrant it just examined as per the convention described
in the comment for int determine_quadrant_with_least_penguins(Player playa, int** board) function.
*/

void automatic_placement_quadrant_method(Player playa, int** board);
/*
DEPRECATED - PLACING ALGORITHM WHICH IS NO LONGER USED (I am keeping it just in case)

This function sets the coordinates to place penguin with the preference for quadrants of
the board with the lowest amount of player's penguins in them. Once it learns which quadrant
has the least penguins of the given player it then iterates through it starting from the 
upper left corner and searches for a value of 10 on the board tiles denoting one fish. When it
finds such a tile it sets the coordinates for penguin placement (x and y) according to the 
indexing from 1 convention and returns void.
*/

void automatic_placement_chess_method(Player playa, int** board);
/*
This function sets the coordinates to place penguin with the preference for the centre of the
board. It initially sets them to half of the column and row size respectively and starts to move away
from the center of the board in a spiral motion i.e. right-down-left-up-right-down. The current direction
of the algorithm is denoted by int dir. Its values can be:
    - 1 denoting right direction
    - 2 denoting down direction
    - 3 denoting left direction
    - 4 denoting up direction

The function keeps increasing the radius of the spiral with each iteration in such a way as to never check 
the same tile twice. Once the parameter int n, denoting the amount of moves the algorithm has to move in 
the currently set direction to fulfill the spiral movement reaches 2 the algorithm starts checking if the 
value of the tile is 10. If it is then those coordinates are set as the coordinates to place the penguin 
and the function returns void. 

The idea behind the algorithm is to allow the penguins more movement space once the game starts, similarly
to how in chess figures at the center of the board are more active. The function waits until n is bigger than 2
to make sure that the penquins are also placed sufficiently far away fro meach other as to not
block each other off. 
*/

Player place_penguin(Player playa, int** board);
/* 
This function places the penguin of a given player on the board according to the coordinates
stored in the global int variables x and y. Since those variables store coordinates in the starting
from 1 idnexing convention it has to convert it to the starting from 0 indexing convetion to allow for
operation on the two dimensional int array storing the board values. It collects the fish from that tile 
adds it to the players score as well as records the position of the penguin in one of the objects in the players 
dynamic Penguin array attribute, which denotes the penguin that has just been placed. The function
also changes the value of the tile where the penguin was placed to the players index.
*/

int determine_best_direction_to_move_penguin_fishwise(int** board, int x_penguin, int y_penguin);
/* 
This function determines which direction from the penguins current coordinates has more fish. 
It takes into consideration all of the different cases of current penguin location which could result
in a segmentation fault e.g. an upper right corner of the board and check only the tiles which actually
exist for such a loaction, which in the mentioned case would be a tile down and a tile left.

The function stores the amount of fish present on each examined tile in a size 4 int array with indexes
signifying the directions towards which the tiles are located: 
    - 0 - right
    - 1 - down
    - 2 - left
    - 3 - up

Once the function records the amounts of fish for each possible direction it then determines which
direction has the biggest amount of fish available and returns int best_move representing the index
denoting that direction according to the above convention.    
*/

void automatically_pick_movement_coordinates(Player playa, int** board);
/* 
This function picks a penguin belonging to the given player semi-randomly and then (if it can move)
sets the coordinates for it to move to with the preference for the tile with most fish. This tile is 
determiend by the int signifying the direction returned by the function:
    - int determine_best_direction_to_move_penguin_fishwise(int** board, int x_penguin, int y_penguin)

It sets the coordinates of the penguin to be moved (global int x_penguin and y_penguin) accoridng to the 
indexing from 1 convention. It takes their values from the attributes of the chosen penguin structure object.

It sets the coordinates to move the penguin (global int x and y) accoridng to the indexing from 1 convention
and returns void if successfull.

In the case where the randomly picked penguin cannot move it increments the penguin_num int variable storing
the index of the penguin by 1 and checks again while also incrementing a counter variable by 1. If the counter 
variable value reaches the amount of penguins then the loop stops. 
*/

Player move_penguin(int** board, Player playa, int x_penguin, int y_penguin, int x, int y);
/*
/* 
This function moves the penguin located at coordinates denoted by the global int variables x_penguin and y_penguin
of a given player to the coordinates stored in the global int variables x and y. Since all four of
those variables store coordinates in the starting from 1 idnexing convention it has to convert it to the starting 
from 0 indexing convetion to allow for operation on the two dimensional int array storing the board values. It collects 
the fish from that tile and adds it to the players score as well as records the new position of the penguin in one of 
the objects in the players dynamic Penguin array attribute, which denotes the penguin that has just been placed. 
The function also changes the value of the tile where the penguin was placed to the players index.
*/
