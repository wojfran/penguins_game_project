#ifndef PLAYER_H
#define PLAYER_H
#include "penguins.h"
extern int player_number, penguins;

typedef struct Player {
    int score;
    Penguin* pingu;
} Player;
/*
 Structure Player holds three integers, players which has information about number of
 players, current_player which is signifying the current player and counter which counts the inability of players to
 make a move, once it is equal to number of all players the game ends.
 */

Player create_player(int penguins);

Player* generate_players(int players, int penguins);

void deallocate_players(Player* players, int player_number);

void change_current_player(int current_player);
/*
Function that changes current player after his move.
 */

int check_if_current_player_has_penguins_in_hand();
/*
 Checks if current_player - which is equal to 1, has any penguins in hand; outputs 1 or 0.
 */

int check_if_current_players_penguins_can_move(int counter);
/*
This function checks if player's penguins have ability to move; outputs 1 or 0.
 */

int does_penguin_belong_to_current_player();
/*
A function that checks if a particular penguin belong to current player; outputs 1 or 0.
 */

void update_score(int player, int score);
/*
 Function which updates score for each particular player.
 */

int can_any_penguins_be_placed(Player* playa);
/*
Used in the placement phase, checks if any player still can place a penguin
according to the input penguin number
*/

#endif