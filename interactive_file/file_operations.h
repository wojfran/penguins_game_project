#include <stdio.h>

int read_dimensions(FILE* input);

int generate_board_file(FILE* input, int** board);

Player read_player(FILE* input);

int generate_players_from_file(FILE* input, Player* players, int size_of_players);