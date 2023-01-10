#ifndef PENGUINS_H
#define PENGUINS_H
#include <stdio.h>
#include <stdlib.h>
extern int player_number, penguins, x, y, columns, rows;

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

#endif