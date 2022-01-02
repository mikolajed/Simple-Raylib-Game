//
// Created by timur on 12/5/21.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "command_line_ui.h"

/*
input parameters: none
return: integer
this function asks a user for an input and returns an integer for number of players.
*/
int get_nbr_of_players() {
    int number_of_players;
    printf("Enter the number of players(from 1 to 9):");
    scanf("%i", &number_of_players);
    while (number_of_players < 1 || number_of_players >= 9) {
        printf("Wrong number of players. Please try again:");
        scanf("%i", &number_of_players);
    }
    return number_of_players;

}

/*
input parameters: none
return: integer
this function asks a user for an input and returns an integer for number of penguins.
*/
int get_nbr_of_penguins() {
    int number_of_penguins;
    printf("Enter the number of penguins(from 1 to 5):");
    scanf("%i", &number_of_penguins);
    while (number_of_penguins < 1 || number_of_penguins >= 5) {
        printf("Wrong number of penguins. Please try again:");
        scanf("%i", &number_of_penguins);
    }
    return number_of_penguins;
}

/*
input parameters: struct player* players, int number_of_players
return: none
this function gets an array and number of players as an input and asks each player for name, simultaneously assigning names to array.
*/
void init_players(struct player* players, int number_of_players) {
    int i,bot;
    for (i = 0; i < number_of_players; i++) {
        char ch;
        printf("Enter the name of the %ist player(only one character):", i + 1);
        scanf(" %c", &ch);
        while (ch < 'A' || ch > 'z') {
            printf("Invalid name, try again:");
            scanf("%c", &ch);
        }
        printf("Is the player a bot(1 yes, 0 no): "); // We need to add cheching the values here
        scanf("%d",&bot);
        // assigning initial values
        players[i].id = i+1;
        players[i].name = ch;
        players[i].fish_collected = 0;
        players[i].movement_status = 0;
        players[i].bot = bot;
        players[i].bot_level = 0;
    }
    int penguins;
    printf("Amount of players each players has: ");
    scanf("%d", &penguins);
    for (i = 0; i < number_of_players; i++) {
        players[i].penguins = penguins;
        players[i].pen_not_placed = penguins;
    }
}

/*
input parameters: none
return: integer
this function asks a user for number of columns of a board.
*/
int get_x_dimension() {
    int x;
    printf("Enter how many columns you want in the board(from 2 to 16):");
    scanf("%i", &x);
    while (x < 2 || x > 16) {
        printf("Wrong number of columns. Please try again:");
        scanf("%i", &x);
    }
    return x;
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
        printf("Wrong number of rows. Please try again:");
        scanf("%i", &y);
    }
    return y;
}

/*
input parameters: int number_of_columns, int number_of_rows
return: movement type
this function asks a user for a movement and returns it.
*/
struct movement get_movement(int number_of_columns, int number_of_rows) {
    int fromX, fromY, toX, toY;
    printf("Enter x-coordinate you want to move your penguin from:");
    scanf("%i",&fromX);
    while (fromX > number_of_columns - 1 || fromX < 0) {
        printf("Wrong coordinates, please try again:");
        printf("Enter x-coordinate you want to move your penguin from:");
        scanf("%i", &fromX);
    }

    printf("Enter y-coordinate you want to move your penguin from:");
    scanf("%i",&fromY);
    while (fromY > number_of_rows - 1 || fromY < 0) {
        printf("Wrong coordinates, please try again:");
        printf("Enter y-coordinate you want to move your penguin from:");
        scanf("%i", &fromY);
    }
    printf("Enter x-coordinate you want to move your penguin on:");
    scanf("%i",&toX);
    while (toX > number_of_columns - 1 || toX < 0) {
        printf("Wrong coordinates, please try again:");
        printf("Enter x-coordinate you want to move your penguin on:");
        scanf("%i", &toX);
    }

    printf("Enter y-coordinate you want to move your penguin on:");
    scanf("%i",&toY);
    while (toY > number_of_rows - 1 || toY < 0) {
        printf("Wrong coordinates, please try again:");
        printf("Enter y-coordinate you want to move your penguin on:");
        scanf("%i", &toY);
    }

    struct movement m;
    m.from.x= fromX;
    m.from.y= fromY;
    m.to.x= toX;
    m.to.y= toY;
    return m;
}

/*
input parameters: int number_of_columns, int number_of_rows
return: placement type
this function asks a user for a placement of a penguin and returns it.
*/
struct placement get_placement(int number_of_columns, int number_of_rows) {
    int x, y;
    printf("Enter x-coordinate you want to place your penguin on:");
    scanf("%i",&x);
    while (x > number_of_columns - 1 || x < 0) {
        printf("Wrong coordinates, please try again:");
        scanf("%i", &x);
    }

    printf("Enter y-coordinate you want to place your penguin on:");
    scanf("%i",&y);
    while (y > number_of_rows - 1|| y < 0) {
        printf("Wrong coordinates, please try again:");
        scanf("%i", &y);
    }

    struct placement p = {x, y};
    return p;
}

void display_curr_player(struct player* players, int curr_player) {
   printf("It is %c player's turn\n", players[curr_player-1].name); 
}

void print_invalid_placement() {
    printf("Placement is invalid.\n");
}

void print_invalid_movement() {
    printf("Movement is invalid.\n");
}

void print_winner(struct player* players, int n, int winner) {
    printf("RANKING\n");
    printf("name | score\n");
    int i;
    for (i=0; i<n; ++i) {
        printf("%c: %d\n", players[i].name, players[i].fish_collected);
    }
}
//int get_difficulty_level() {
//    int level;
//    printf("Enter the level of difficulty(from 1 to 3): ");
//    scanf("%i", &level);
//
//    while (level <= 0 || level > 3) {
//        printf("Wrong level of difficulty. Please try again");
//        scanf("%i", &level);
//    }
//
//}

int check_if_ai() {
    int answer;
    printf("The player is a bot(1 yes,0 not): ");
    scanf("%d",&answer);
    return answer;
}

