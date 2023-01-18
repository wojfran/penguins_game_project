int check_first_parameter(char* argument);
/*
This function checks the first parameter of the comman-line parameters. This
parameter denotes the phase of the game. It then returns an int denoting each of 
the phases:
    - 1 - placement phase
    - 2 - movement phase
    - 3 - name command

If the given command-line parameter doesn't match the convention it prints a warning
and returns 0. 
*/

int read_commandline_penguin_amount(char* penguins);
/*
This function read the penguin amount from command_line parameters.
Returns -1 and prints warning if unsuccesfful.
*/
