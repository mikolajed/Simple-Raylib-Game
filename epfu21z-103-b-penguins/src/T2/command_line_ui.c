#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "gameplay_functions.h"

/*
input parameters: none
return: integer
this function asks a user for an input and returns an integer for number of players.
*/
int get_nbr_of_players() {
    int number_of_players;
    printf("Enter the number of players(from 1 to 9): ");
    scanf("%i", &number_of_players);
    while (number_of_players <= 1 || number_of_players >= 9) {
        printf("Wrong number of players. Please try again: ");
        scanf("%i", &number_of_players);
    }
    return number_of_players;

}
/*
input parameters: struct player* players, int number_of_players
return: none
this function gets an array and number of players as an input and asks each player for name, simultaneously assigning names to array.
*/
void init_players(struct player* players, int number_of_players) {
    for (int i = 0; i < number_of_players; i++) {
        //if you only ask for one char you dont need an array of chars
        char ch;
        printf("Enter the name of the %ist player(only one character): ", i + 1);
        scanf(" %c", &ch);
        while (ch < 'A' || ch > 'z') {
            printf("Invalid name, try again: ");
            scanf("%c", &ch);
        }
        players[i].name = ch;
    }
}

/*
input parameters: none
return: integer
this function asks a user for number of columns of a board.
*/
int get_x_dimension() {
    int y;
    printf("Enter how many rows you want in the board(from 2 to 16):");
    scanf("%i", &y);
    while (y < 2 || y > 16) {
        printf("Wrong number of columns. Please try again: ");
        scanf("%i", &y);
    }
    return y;
}
/*
input parameters: none
return: integer
this function asks a user for number of rows of a board.
*/
int get_y_dimension() {
    int y;
    printf("Enter how many rows you want in the board(from 2 to 16):");
    scanf("%i", &y);
    while (y < 2 || y > 16) {
        printf("Wrong number of columns. Please try again: ");
        scanf("%i", &y);
    }
    return y;
}


