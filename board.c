#include <stdio.h>
#include <stdlib.h>
#include "board.h"

int** allocate_memory_for_board(int columns, int rows) {
    int** board = NULL;
    int i;

    board = (int**) malloc(rows * sizeof(int*));

    if (board == NULL) {
        printf("Unable to allocate memory for rows:(\n");
        return -1;
    }

    for (int i = 0; i < rows; i++) {
        board[i] = (int*) malloc(columns * sizeof(int));
        if (board[i] == NULL) {
            free_board_memory(board, rows);
            printf("Unable to allocate memory for columns:(\n");
            return -1;
        }
    }
    return board;    
};
/* 
This function allocates memory for a dynamicaly allocated 2d array of integers which is the
board for the purposes of the game. It takes two integers, x and y, as its arguments. They
denote the dimensions of the board that will be created. First the function allocates memory 
for the "columns" of the board and then it iterates through them to allocate memory for the 
rows.
*/

void generate_board(int** board){
    int i, j;
    srand(time(0));
    for(i = 0; i < rows; i++){
        for (j = 0; j < columns; j++){
            board[i][j] = rand() % 3 + 1;
        }
    }
};
/*
This function generates the board for the game. It takes an alread allocated 2d dynamic
array of integers (int** board) as its argument and fills it with a random assortment of 
1, 2 or 3 signifying the amount of fish on the tile.
*/

void display_board(int** board){
    int i, j;

    printf("    ");
    for(i = 0; i < columns; i++){
        if(i>9) {
            printf("  %d  ", i+1);
        } else printf("   %d  ", i+1);
    }
    printf("\n");
    printf("     ");
    for(i = 0; i < columns; i++){
        printf("------");
    }
    printf("\n");


    for(i = 0; i < rows; i++){
        if (i+1 > 9) {
            printf(" %d |", i+1);
        } else printf("  %d |", i+1);
        for (j = 0; j < columns; j++){
            if(board[i][j] < 10) {
                printf("  %d  |", board[i][j]);
            } else {
                printf(" %dP%d |", (board[i][j]%10), (board[i][j]/100));
            }
        }
        printf("\n");
    }
};
/*
This function displays the board by printing each row in one line, when the row ends a newline
char is printed and a new row begins. It takes an alread allocated 2d dynamic array of integers 
(int** board) as its argument.
*/

void free_board_memory(int** board, int x){
    int i;
    for(int i = 0; i < rows; i++){
        free(board[i]);
    }
    free(board);
};

int check_if_space_on_the_board();
/*used in the placement phase.Checks if there any space on the board
 for penguins,what the players have not yet placed*/

void update_board();
/*it should show all board changes that occur during the game*/
