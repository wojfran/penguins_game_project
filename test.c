#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "input.h"

int x = NULL;
int y = NULL; // board dimensions, later used to store input coordinates
int x_penguin, y_penguin; // storage for chosen penguin coordinates
int players; // number of players
int penguins; // number of penguins
int current_player = 1; //integer signifying the current player
int score; // keeps score
int counter; // used to count the inability to make a move,
             // once it is equal the number of players the phase is finished

int main(){
    set_board_dimensions(&x, &y);
    printf("\nThose are the global x and y values:\n%d\n%d\n", x, y);
    
    int** board = allocate_memory_for_board(x, y);
    generate_board(board);

    display_board(board);
    free_board_memory(board, x);
}