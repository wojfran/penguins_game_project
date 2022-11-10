#include <stdio.h>
#include <stdlib.h>


int x, y; // board dimensions
int penguins; // number of penguins
int players; // numeber of players
int current_player = 1; //integer signifying the current player
int score; // keeps score
int counter; // used to count the inability to make a move,
             // once it is equal the number of players the phase is finished

void input_board_dimensions() {

}

int check_if_input_is_correct(){
    
}

void input_number_of_players_and_penguins() {
    if (check_if_input_is_correct()){
        
    } else {

    }
}

void generate_board(){

}

void display_board(){

}

void change_current_player(){
    if(current_player != players){
        current_player++;
    } else current_player = 1;
}

int check_if_current_player_has_penguins_in_hand(){

} //returns 1 or 0

int check_if_space_on_the_board(){

} //returns 1 or 0

int are_coordinates_valid() {

}//returns 1 or 0

void ask_for_coordinates(){


    if (are_coordinates_valid()){
        
    } else {

    }
}

void place_penguin(int x, int y){

}

void move_penguin(int x, int y, int penguin_number){

}

void update_score(int player, int score){

}


int main(){
    input_board_dimensions();
    input_number_of_players_and_penguins();
    generate_board();
    
    // placement phase:
    while(counter != players){
        if (check_if_current_player_has_penguins_in_hand() && check_if_space_on_the_board()){
            show_board();
            ask_for_coordinates();
            place_penguin(x, y);
            update_score(current_player, score);
            change_current_player();
        } else {
            counter++;
            change_current_player();
        }
    }


    // movement phase:
    // WIP

int check_if_at_least_one_player_has_penguins_to_move(){
}
void ask_about_ability_to_move(){ 
if (check_if_at_least_one_player_has_penguins_to_move()){
}
else{ 
printf("the end”);
}
}

int can_current_player_make_move(){
    }
void ask_about_ability_to_move_current_player()
{if (can_current_player_make_move()){}
else {
change_current_player;
}
}

while(can_current_player_make_move()) 
show_board();{
void change_penguin(){}

int is_chosen_penguin_blocked(){}

void chosen_penguin(){
if ( is_chosen_penguin_blocked()){}
else{
change_penguin;}
}

int are_coordinates_move_valid(){}
    void  ask_for_coordinates_move (){
       } 
      while(are_coordinates_valid()){
       void place_chosen_penguin(){};
       update_score();
    void remove_collected_fishes_from_board(){};
       change_current_player();
}
}// WIP
