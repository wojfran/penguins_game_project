#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

int generate_board_file(FILE* input, int** board) {
    int floe_value;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++){
            int check = fscanf(input, "%d", &floe_value);
            if (floe_value < 40 && floe_value >= 0) {
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

    if (feof(input)) {
        Player end = create_player(0, "eof", -1, -1);
        return end;
    }
    
    //printf("\nPlayer:\n");
    fscanf(input, " %19s", id);
    //printf("ID: %s\n", id);
    fscanf(input, " %d", &index);
    //printf("Index: %d\n", index);
    fscanf(input, "%d", &score);
    //printf("Score: %d\n", score);

    Player bob = create_player(penguins, id, index, score);

    return bob;
}

// there needs to be an additional a test implemented
// as when there are spaces after the score of the player
// the program malfunctions
int generate_players_from_file(FILE* input, Player* players, int size_of_players) {
    int i = 0;
    do {
        Player storage = read_player(input);
        
        if (storage.index == -1) {
            player_number = i;
            return 1;
        } else if (check_for_duplicate_player(storage, players, 10) == 1){
            if (strcmp(storage.id, player_name) == 0) current_player = i;
            players[i] = storage;
            i++;
        } else return 0;
    } while (1);
}

int check_for_duplicate_player(Player new, Player* players, int players_size) {
    for (int i = 0; i < players_size; i++) {
        if (strcmp(new.id, players[i].id) == 0) {
            printf("You cannot have two players of the same id name!\n");
            return 0;
        } else if (new.index == players[i].index) {
            printf("You cannot have two players of the same index!\n");
            return 0;
        }
    }
    return 1;
}

/*
                char buffer[25];

                // preventing the first line to be included in the generation
                fgets(buffer, sizeof(buffer), input);
                
                // reading the values of consecutive ice floes
                for (int i = 0; i < rows; i++) {
                    fgets(buffer, sizeof(buffer), input);

                    //printf("%s", buffer);
                    int column_counter = 0;
                    char* floe = strtok(buffer, " \n");
                    //printf("%s", floe);
                    
                    while(floe){
                        int floe_value = atoi(floe);
                        printf(" %d ", floe_value);
                        board[i][column_counter] = floe_value;
                        floe = strtok(NULL, " ");
                        column_counter++;
                    }
                
                }   
                */