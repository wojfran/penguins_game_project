#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "file_operations.h"
#include "player.h"

extern int rows, columns, penguins, player_number, current_player;
extern char* player_name;

int read_dimensions(FILE* input) {
    int i = fscanf(input, "%d %d", &rows, &columns);
    if (i != 2) {
        printf("Dimensions were not properly assigned, check the input file format.\n");
        return 0;
    } else return 1;
};

int read_board_values_from_file(FILE* input, int** board) {
    int floe_value;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++){
            int check = fscanf(input, "%d", &floe_value);
            if (floe_value < 40 && floe_value >= 0) {
                if ((floe_value % 10 != 0) && (floe_value > 9)) floe_value = floe_value % 10;
                board[i][j] = floe_value;
            } else {
                printf("Integer within the wrong range read in the space of the"
                "file describing the board.\n");
                return 0;
            }
            if (check != 1) {
                printf("There seems to be a problem with scanning the ice floe values"
                "in the space of the file describing the board.\n");
                return 0;
            }
        }
    }

    return 1;  
};

Player read_player(FILE* input) {
    char id[20];
    int index;
    int score;
    int check;
    

    if (feof(input)) {
        Player end = create_player(0, "eof", -1, -1);
        return end;
    }
    
    check = fscanf(input, " %19s", id);
    fscanf(input, " %d", &index);
    fscanf(input, "%d", &score);

    if(check < 0) {
        Player end = create_player(0, "eof", -1, -1);
        return end;
    }

    Player bob = create_player(penguins==-1 ? 10: penguins, id, index, score);
    

    return bob;
}

int check_for_duplicate_player(Player bob, Player* players, int players_size) {
    for (int i = 0; i < players_size; i++) {
        if (strcmp(bob.id, players[i].id) == 0) {
            printf("\nYou cannot have two players of the same id name!\n");
            return 0;
        } else if (bob.index == players[i].index) {
            printf("\nYou cannot have two players of the same index!\n");
            return 0;
        }
    }
    return 1;
}

int read_players_from_file(FILE* input, Player* players) {
    int i = 0;
    do {
        Player storage = read_player(input);
        if (storage.index == -1) {
            if (current_player == -1) {
                Player me = create_player(penguins, player_name, i, 0);
                while(!check_for_duplicate_player(me, players, 10)){
                    me.index++;
                }
                current_player = i;
                players[i] = me;
                i++;
                player_number = i;
                return 2;
            }
            player_number = i;
            return 1;
        } else if (check_for_duplicate_player(storage, players, 10)){
            if (strcmp(storage.id, player_name) == 0) {
                current_player = i;
            }
            
            players[i] = storage;
            i++;
        } else {
            return 0;
        }
    } while (1);
}

int write_game_state_to_output_file(FILE* output, int** board, Player* players) {

    fprintf(output, "%d %d\n", rows, columns);

    for(int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            if (board[i][j] < 10) {
                fprintf(output, "0%d ", board[i][j]);
            } else fprintf(output, "%d ", board[i][j]);
        }
        fprintf(output, "\n");
    }

    for (int i = 0; i < player_number; i++) {
        fprintf(output, "%s %d %d\n", players[i].id, players[i].index, players[i].score);
    }
}