#ifndef PENGUINS_H
#define PENGUINS_H
#include <stdio.h>
#include <stdlib.h>
extern int player_number, penguins, x, y;

typedef struct Penguin {
    int x, y, flag;
} Penguin;
/*
Structure penguin, it holds three integers, the first two, x and y 
simply describe the position of the penguin on the board. In the placement
phase a flag equal to 1 means that the penguin can be placed. Once placed
the flag changes to 0 and remains so up until in the game phase the pegnuin
is not able to move. Once this happens the flag gets turned back to 1
and the penguin is out of the game.
*/

void move_penguin(Penguin penguin, int x, int y);
/*
Function that moves the penguin from the coordinates in which the chosen 
penguin object is currently on to x and y coordiates. It should check if 
the penguin can move to those coordinates 
*/
/*
void place_penguin(Player playa, int** board){
    playa.score+=board[x][y];
    board[x][y] = 8;

    for(int i = 1; i <= penguins; i++){
        if (playa.pingu[i].flag == 1){
            playa.pingu[i].x = x;
            playa.pingu[i].y = y;
            playa.pingu[i].flag = 0;
        }
    }
    

};

It should create a penguin object at the given coordinates if they are valid
ie. if they exist on the board and if a penguin can be placed there
*/

int can_any_penguins_move(){};
/*
Checks if any of the created penguins objects has a tile next to them to 
which it can move
*/

#endif