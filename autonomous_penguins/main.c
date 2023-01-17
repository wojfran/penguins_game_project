#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"
#include "penguins.h"
#include "player.h"
#include "movement.h"
#include "command_line.h"
#include "file_operations.h"

char* player_name = "Pengwings";
int x;
int y; // board dimensions, later used to store input coordinates
int rows, columns;
int x_penguin, y_penguin; // storage for chosen penguin coordinates
int player_number; // number of players
int penguins = -1; // number of penguins
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
        if (mode == 1 || mode == 2) {
            
            if (mode == 1) {
                // reading maximum amount of penguins per player
                penguins = read_commandline_penguin_amount(argv[2]);

                // checking if the amount of penguins is correct
                if (penguins == -1) {
                    printf("The amount of penguins could not be read.\n");
                    return 3;
                } 

                printf("The read amount of penguins is: \n%d\n\n", penguins);
            }

            // reading the input text file
            FILE* input;
            if (mode == 1) input = fopen(argv[3], "r");
            else if (mode == 2) input = fopen(argv[2], "r");
            else {
                printf("Invalid mode. \n");
                return 3;
            }
                

            // checking if the fopen function was successful
            // ie. if file could be read
            if (input == NULL) {
                printf("Input board file could not be opened.\n");
                return 3;
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
            if(read_board_values_from_file(input, board)) {
                printf("Such a board was read:\n");
                display_board_file_format(board, rows, columns);
            } else return 2;
                
            // allocating memory for the players to be generated from file
            Player* players = players = malloc(10 * sizeof(Player));
                
            // generating players out of file data
            // as well as checking if they are valid
            // ie. if there arent't any duplicates
            int check = read_players_from_file(input, players);
            if(check == 1 || mode == 1) {
                printf("\nThe following players were read from file:\n");
                for (int i = 0; i < player_number; i++) {
                    printf("\nPlayer[%d]: id(%s), ind(%d), score(%d)", i, players[i].id, players[i].index, players[i].score);
                }
            } else if (check == 2 && mode == 2) {
                printf("It seems that we (%s) are not a part of this game as its "
                "the movement phase already and our name isn't in the input file :(\n", players[current_player].id);
                return 2;
            } else return 3;

            printf("\n\nThe current player is players[%d]\nThe number of players is: %d\n", current_player, player_number);

            fclose(input);

            // reading penguins from board, assigning them
            // the values of their coordinates as well as
            // assigning them to their respective players
            if (read_penguins_from_board(board, players)) {
                printf("\nThe read penguins have the following coordinates: \n");
                print_all_players_penguin_coordinates(players);
                printf("\n");
            } else return 3;

            if (mode == 1) {
                // check if the player with our id name has penguins
                // to be placed and if so ask for coordinates, then
                // place penguin. if we have already placed our penguins
                // returns 1
                if (check_if_current_players_penguins_can_be_placed(players[current_player])){
                    display_board_file_format(board, rows, columns);
                    printf("\n*\n");
                    automatic_placement_chess_method(players[current_player], board);
                    printf("\n*\n");
                    
                    players[current_player] = place_penguin(players[current_player], board);
                } else {
                    printf("We have already placed all our penguins. ");
                    return 1;
                }
            } else if (mode == 2) {
                // check if the player with our id name has penguins
                // to be placed and if so ask for coordinates, then
                // place penguin. if we have already placed our penguins
                // returns 1
                if (check_if_current_players_penguins_can_move(players[current_player], board)){
                    display_board_file_format(board, rows, columns);
                    automatically_pick_movement_coordinates(players[current_player], board);
                    players[current_player] = move_penguin(board, players[current_player], x_penguin, y_penguin, x, y);
                } else {
                    printf("Our penguins cannot move :(\n");
                    return 1;
                }
            } else {
                printf("Invalid mode. \n");
                return 3;
            }

            display_board_file_format(board, rows, columns);
            
            FILE* output;
            if (mode == 1) output = fopen(argv[4], "w");
            else if (mode == 2) output = fopen(argv[3], "w");
            else {
                printf("Invalid mode. \n");
                return 3;
            }
            
            // checking if the fopen function was successful
            // ie. if file could be read
            if (output == NULL) {
                printf("Output board file could not be opened.\n");
                return 3;
            }

            write_game_state_to_output_file(output, board, players);

            fclose(output);
            if (mode == 1) deallocate_players(players, player_number);    
            free_board_memory(board, columns);
            return 0;

        } else if (mode == 3) {
            printf("%s\n", player_name);
            return 0;
        } else if (mode == 0) {
            return 2;
        }
    } else printf("No commandline arguments were given.\n");
}