#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "penguins.h"
extern int player_number, penguins, x, y;


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
    int player_index = (board[y_penguin][x_penguin]%10);

    if (playa.index != player_index){
        printf("wrong player! dork");
        printf("%d\n%d", playa.index, player_index);
    } else {
        playa.pingu[penguin_index].x=x-1;
        playa.pingu[penguin_index].y=y-1;
        playa.score += board[y-1][x-1];
        board[y-1][x-1] = playa.index + 100*(penguin_index);
        board[y_penguin][x_penguin] = 0;
    }
}