#include "player.h"

extern int columns, rows;

int** allocate_memory_for_board(int columns, int rows);
/* 
This function allocates memory for a dynamicaly allocated 2d array of integers which is the
board for the purposes of the game. It takes two integers, x and y, as its arguments. They
denote the dimensions of the board that will be created. First the function allocates memory 
for the "columns" of the board and then it iterates through them to allocate memory for the 
rows.
*/

void generate_board(int** board);
/*
This function generates the board for the game. It takes an alread allocated 2d dynamic
array of integers (int** board) as its argument and fills it with a random assortment of 
1, 2 or 3 signifying the amount of fish on the tile.
*/

void free_board_memory(int** board, int x);
/*
This function frees the memory allocated while creating a dynamically allocated 2d int array
for the board.
*/

void display_board_raw(int** board, int rows, int columns);
/*
This function displays the values stored in the board two dimensional array without any other
formatting then printing them with a two space long horizontal separation. Used primarily for
diagnostics.
*/

int read_penguins_from_board(int** board, Player* players);
/*
This function iterates the board in search of a value of which a modulo yields a non-zero value.
Such a value denotes a player penguin standing on the given tile. The function then reads the 
coordinates of that tile and records the position of the penguin belonging to the player with the
index given by the modulo 10 of the tile value. Those coordinates are then assigned to the appropriate
Penguin structure object stored in the players Penguin structure dynamic array. 

The function additionally checks if all of the values of the board fit the format of the game, as well as
whether some of the players aren't cheating by placing more penguins on the board than they should.

The function also informs the user through output if a Player in the given Player array still hasn't placed
all of their penguins on the board. 

In the case of the movement phase, when the amount of penguins is not explicitly given in the command-line 
parameters, the function deduces the amount of penguins using a counter variable and assigns the coutned value
to the global int penguins variable storing the amount of penguins that each player should have in the game. It 
distinguishes what mode the game is currently in by checking ig the penguisn global variable is set to -1, as
thats its default value signifying that it has not been set yet, as is the case in the movement phase. 
*/

void display_board_file_format(int** board, int rows, int columns);
/*
This function prints the board two dimensional int array in a formatted way. The printout posseseses a column
and row with numbers of respectively rows and columns alongside it. Furthermore it separates each row with a line
of minus signs. This makes the board display more readable. 
*/
