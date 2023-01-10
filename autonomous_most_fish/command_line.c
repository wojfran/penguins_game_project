#include <stdio.h>
#include <string.h>

int check_first_parameter(char* argument) {
    if (strcmp(argument, "phase=placement") == 0) {
        return 1;
    } else if (strcmp(argument, "phase=movement") == 0) {
        return 2;
    } else if (strcmp(argument, "name") == 0) {
        return 3;
    } else {
        printf("Invalid first commandline parameter. It should be one "
        "of these:\n- 'phase=placement'\n- 'phase=movement'\n- 'name'\n");
        return 0;
    }
};

int read_commandline_penguin_amount(char* penguins) {
    char* token = strtok(penguins, "=");
    //printf("%s", token);
    if (strcmp(token, "penguins") == 0) {
        token = strtok(NULL, "=");
        int penguins = atoi(token);
        if (penguins > 9 || penguins < 1) {
            printf("Wrong amount of penguins given in command line\n");
            return -1;
        } else {
            return penguins;
        }
    } else {
        printf("Wrong commandline parameters, in the placement phase",
        "the second parameter should be in this format 'penguins=3'",  
        "with the number after '=' greater than 0 and smaller than 10");
        return -1;
    }
};
