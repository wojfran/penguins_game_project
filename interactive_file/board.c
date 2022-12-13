#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "player.h"

extern int penguins;

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

void generate_board(int** board){
    int i, j;
    srand(time(0));
    for(i = 0; i < rows; i++){
        for (j = 0; j < columns; j++){
            board[i][j] = rand() % 3 + 1;
        }
    }
};

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
            if (board[i][j] == 0) {
                printf("     |");
            }
            else if(board[i][j] < 4) {
                printf("  %d  |", board[i][j]);
            } else {
                printf(" %dP%d |", (board[i][j]%10), (board[i][j]/100));
            }
        }
        printf("\n");
    }
};

void free_board_memory(int** board, int x){
    int i;
    for(int i = 0; i < rows; i++){
        free(board[i]);
    }
    free(board);
};

void display_board_raw(int** board, int rows, int columns) {
    for(int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            printf(" %d ", board[i][j]);
        }
        printf("\n");
    } 
}

int read_penguins_from_board(int** board, Player* players) {
    for(int k = 0; k < player_number; k++) {
        int penguin_counter = 0;
        for(int i = 0; i < rows; i++){
            for (int j = 0; j < columns; j++){
                if (board[i][j] % 10 > 9 || board[i][j] % 10 < 0) {
                    printf("One value on the board seems to not fit the format!\n");
                } else if (board[i][j] % 10 == players[k].index) {
                    if (penguin_counter == penguins) {
                        printf("The player with the index %d is cheating! You have too many penguins on the board!\n");
                        return 0;
                    } else {
                        players[k].pingu[penguin_counter].x = j;
                        players[k].pingu[penguin_counter].y = i;
                        penguin_counter++;
                    }                    
                }
            }
        }
    } 
    return 1;
}

void display_board_file_format(int** board, int rows, int columns) {
    printf("   ");
    for(int i = 0; i < columns; i++){
        if(i>9) {
            printf("  %d ", i+1);
        } else printf("  %d ", i+1);
    }
    printf("\n");
    printf("   ");
    for(int i = 0; i < columns; i++){
        printf("----");
    }
    printf("\n");

    for(int i = 0; i < rows; i++){
        if (i+1 > 9) {
            printf(" %d |", i+1);
        } else printf(" %d|", i+1);
        for (int j = 0; j < columns; j++){
            if(board[i][j] >= 10) {
                printf(" %d ", board[i][j]);
            } else if (board[i][j] > 0) {
                printf(" 0%d ", board[i][j]);
            } else if(board[i][j] == 0) {
                printf(" 00 ");
            }
        }
        printf("\n");
    } 
}