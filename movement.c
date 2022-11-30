#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "penguins.h"
extern int player_number, penguins, x, y;


void place_penguin(Player playa, int** board){
    for(int i = 0; i < penguins; i++){
        if (playa.pingu[i].flag == 1){
            playa.score+=board[x-1][y-1];
            board[x-1][y-1] = playa.index;
            playa.pingu[i].x = x;
            playa.pingu[i].y = y;
            playa.pingu[i].flag = 0;
            break;
        }
    }
    
};