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
            playa.pingu[i].x = x;
            playa.pingu[i].y = y;
            playa.pingu[i].flag = 0;
            break;
        }
    }
}

void move_penguin(int x_penguin, int y_penguin, int x, int y){

}