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

void move_penguin(Penguin penguin, int x, int y);
/*
Function that moves the penguin from the coordinates in which the chosen 
penguin object is currently on to x and y coordiates. It should check if 
the penguin can move to those coordinates 
*/
/*
void place_penguin(Player playa, int** board);

It should create a penguin object at the given coordinates if they are valid
ie. if they exist on the board and if a penguin can be placed there
*/

int can_any_penguins_move();
/*
Checks if any of the created penguins objects has a tile next to them to 
which it can move
*/
#endif