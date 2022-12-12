#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "penguins.h"
extern int player_number, penguins, x, y, x_penguin, y_penguin;


void place_penguin(Player playa, int** board){
    for(int i = 0; i < penguins; i++){
        if (playa.pingu[i].flag == 1){
            playa.score+=board[y-1][x-1];
            board[y-1][x-1] = playa.index + 100*(i+1);
            playa.pingu[i].x = x-1;
            playa.pingu[i].y = y-1;
            playa.pingu[i].flag = 0;
            break;
        }
    }
}

void move_penguin(int** board, Player playa, int x_penguin, int y_penguin, int x, int y){
    int penguin_index = (board[y_penguin][x_penguin]/100);
    //int player_index = (board[y_penguin][x_penguin]%10);

    //printf("\n%d\n", x-1);
    //printf("\n%d\n", y-1);
    //printf("\n%d\n", penguin_index);
    //printf("\n%d\n", player_index);
    playa.pingu[penguin_index-1].x=x-1;
    playa.pingu[penguin_index-1].y=y-1;
    playa.score += board[y-1][x-1];
    board[y-1][x-1] = playa.index + 100*(penguin_index);
    board[y_penguin][x_penguin] = 0;
    system("clear");
}

