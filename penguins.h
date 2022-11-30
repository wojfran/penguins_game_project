#ifndef PENGUINS_H
#define PENGUINS_H
extern int player_number, penguins, x, y;

typedef struct Penguin {
    int x, y, flag;
} Penguin;
/*
Structure penguin, it holds three integers, the first two, x and y 
simply describe the position of the penguin on the board.
*/

int can_any_penguins_move();
/*
Checks if any of the created penguins objects has a tile next to them to 
which it can move
*/
#endif