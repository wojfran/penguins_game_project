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

void display_board();
/*
This function displays the board by printing each row in one line, when the row ends a newline
char is printed and a new row begins. It takes an alread allocated 2d dynamic array of integers 
(int** board) as its argument.
*/

void free_board_memory(int** board, int x);
/*
This function frees the memory allocated while creating a dynamically allocated 2d int array
for the board.
*/

void display_board_raw(int** board, int rows, int columns);

int read_penguins_from_board(int** board, Player* players);
