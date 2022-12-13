#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"
#include "input.h"
#include "penguins.h"
#include "player.h"
#include "movement.h"
#include "command_line.h"
#include "file_operations.h"

char* player_name = "gus";
int x;
int y; // board dimensions, later used to store input coordinates
int rows, columns;
int x_penguin, y_penguin; // storage for chosen penguin coordinates
int player_number; // number of players
int penguins; // number of penguins
int current_penguin = 1;
int current_player = -1; //integer signifying the current player
int score; // keeps score
int counter; // used to count the inability to make a move,
             // once it is equal the number of players the phase is finished

int main(int argc, char* argv[]){
    system("clear");
    Player* players;

    // checking of any commandline parameters were given
    if (argc > 1) {

        //determining the mode (or the lack of it)
        int mode = check_first_parameter(argv[1]);

        //selecting appropriate mode
        if (mode == 1) {
            // placement mode
            // checking if there is a correct amount of commandline parameters
            if (argc == 5) {

                // reading maximum amount of penguins per player
                penguins = read_commandline_penguin_amount(argv[2]);

                // checking if the amount of penguins is correct
                if (penguins == -1) {
                    return 2;
                } 

                printf("The read amount of penguins is: \n%d\n\n", penguins);

                // reading the input text file
                FILE* input;
                input = fopen(argv[3], "r");
                

                // checking if the fopen function was successful
                // ie. if file could be read
                if (input == NULL) {
                    printf("Input board file could not be opened.\n");
                    return 2;
                }
                

                // reading the dimensions of the board 
                // as well as checking if they were properly read
                if (read_dimensions(input)) {
                    printf("The following dimension were read:\n"
                    "Rows(y): %d\nColumns(x): %d\n\n", rows, columns);
                } else return 2;
                
                // allocating memory for the board to be read
                int** board = allocate_memory_for_board(columns, rows);

                // generating the board values from the input file
                // as well as checking if they were properly read
                // and no value was outside of the permitted range
                if(generate_board_file(input, board)) {
                    printf("Such a board was read:\n");
                    display_board_raw(board, rows, columns);
                } else return 2;
                
                // allocating memory for the players to be generated from file
                Player* players = players = malloc(10 * sizeof(Player));
                
                // generating players out of file data
                // as well as checking if they are valid
                // ie. if there arent't any duplicates
                if(generate_players_from_file(input, players, 10)) {
                    printf("The following players were read from file:\n");
                    for (int i = 0; i < player_number; i++) {
                        printf("\nPlayer[%d]: id(%s), ind(%d), score(%d)", i, players[i].id, players[i].index, players[i].score);
                    }
                } else return 2;

                printf("\nThe current player is players[%d]\nThe Current number of players is: %d\n", current_player, player_number);

                if (read_penguins_from_board(board, players)) {
                    printf("\nThe read penguins have the following coordinates: \n");
                    print_all_players_penguin_coordinates(players);
                } else return 2;

                

                deallocate_players(players, player_number);     
                free_board_memory(board, columns);
            } else {
                printf("Wrong amount of commandline parameters "
                "they should be of this format:\n'penguins.exe "
                "phase=placement penguins=3 inputboard.txt outpuboard.txt'");
                return 2;
            }
        } else if (mode == 2) {

        } else if (mode == 3) {

        } else if (mode == 0) {

        } else {
            return 2;
        }
    } else printf("No commandline arguments were given.\n");
    //if (check_first_parameter(argv[1])){};
}