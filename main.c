#include <stdio.h>
#include <stdlib.h>


int x, y; // board dimensions, later used to store input coordinates
int x_penguin, y_penguin; // storage for chosen penguin coordinates
int players; // numeber of players
int current_player = 1; //integer signifying the current player
int score; // keeps score
int counter; // used to count the inability to make a move,
             // once it is equal the number of players the phase is finished

void input_board_dimensions() { 

} // input

int check_if_input_is_correct(){
    
} // input

void input_number_of_players_and_penguins() {
    if (check_if_input_is_correct()){
        
    } else {

    }
} // input

void generate_board(){

} // board

int can_any_penguins_be_placed(){

} // returns 1 or 0
// penguin

void display_board(){

} // board

void change_current_player(){
    if(current_player != players){
        current_player++;
    } else current_player = 1;
} // player

int check_if_current_player_has_penguins_in_hand(){

} // returns 1 or 0
// player

int check_if_space_on_the_board(){

} // returns 1 or 0
// board

int are_coordinates_valid() {

}// returns 1 or 0
// input

void ask_for_coordinates(){


    if (are_coordinates_valid()){
        
    } else {

    }
} //input

int check_if_current_players_penguins_can_move(){

} // returns 1 or 0
// penguin

void ask_for_penguin_coordinates(){

    if (does_penguin_belong_to_current_player() && are_coordinates_valid()){

    } else {

    }
} // input

int can_any_penguins_move(){

} // returns 1 or 0
// penguin

int does_penguin_belong_to_current_player(){

} // returns 1 or 0
// player

void place_penguin(int x, int y){

} // penguin

void move_penguin(int x_penguin, int y_penguin, int x, int y){

} // penguin

void update_score(int player, int score){

} // player

void update_board(){

} //board


int main(){
    input_board_dimensions();
    input_number_of_players_and_penguins();
    generate_board();
    
    // placement phase:
    while(can_any_penguins_be_placed()){
        if (check_if_current_player_has_penguins_in_hand() && check_if_space_on_the_board()){
            show_board();
            ask_for_coordinates();
            place_penguin(x, y);
            update_score(current_player, score);
            update_board();
            change_current_player();
        } else {
            change_current_player();
        }
    }

    // movement phase:
    // WIP
    while(can_any_penguins_move()){
        if (check_if_current_players_penguins_can_move){
            show_board();
            ask_for_penguin_coordinates();
            ask_for_coordinates();
            move_penguin(x_penguin, y_penguin, x, y);
            update_score(current_player, score);
            update_board();
            change_current_player();
        } else {
            change_current_player();
        }
    }
}