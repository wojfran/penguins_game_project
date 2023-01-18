#ifndef PLAYER_H
#define PLAYER_H
#include "penguins.h"
extern int player_number, penguins, current_player;

typedef struct Player {
    int index;
    int score;
    Penguin* pingu;
} Player;
/*
Structure representing a player/team taking part in the game. It hold the following attributes:
    - int index, this is the index of the player/team, no two players/teams can have the same index
    - int score, self-explanatory, it holds the current score of the player/team
    - Penguin* pingu, a dynamic array of Penguin structures, representing the penguins
    belonging to the player, its size is the amount of penguins chosen at the start of the game
*/

Player create_player(int penguins, int index);
/* 
Creates players to be used on the board. 
It allocates memory for the Penguins* pingu dynamic array according to the 
amount of penguisn chosen at the beginning of the game (stored in int penguins). 
*/

Player* generate_players(int players, int penguins);
/*
This function is used to create and allocate memory to a dynamic array of 
Player structure objects. Each player in the array has the amount of penguins given
in the function parameter int penguins. The parameter int players describes the amount
of players to be created and allocated. 
*/

void deallocate_players(Player* players, int player_number);
/*
This function deallocates the memory from the dynamic array of Player structures
given as a parameter called players. The other parameter int player_number tells
the function the size of the given array.
*/

void change_current_player();
/*
This function chenages the global int current_player variable denoting the index
of the player whose turn currently takes place.

If the value of current_player reaches the index of the last player, instead of
incrementing it the function sets it to one i.e. the index of the first player.
*/

void display_score_of_players(Player* players, int player_number);
/*
This function prints out the scores of the players.
*/

#endif
