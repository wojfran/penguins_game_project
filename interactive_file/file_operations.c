#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "player.h"

extern int rows, columns, penguins;
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

Player read_player_id(FILE* input) {
    char id[20];
    int index;
    int score;

    printf("\nPlayer:\n");

    fscanf(input, " %19s", id);
    if (strcmp(id, player_name) == 0) printf("\nThis is us:\n");
    printf("ID: %s\n", id);
    fscanf(input, " %d", &index);
    printf("Index: %d\n", index);
    fscanf(input, "%d", &score);
    printf("Score: %d\n", score);
     
    Player bob = create_player(penguins, index, score);

    printf("%d %d", bob.index, bob.score);
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