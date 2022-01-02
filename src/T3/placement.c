#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "gameplay_functions.h"

#define END_PP 1

//int placement_game_status(penguins);

//int placement_possible(current_player, penguins);

int get_placement_x();

int get_placement_y();

//int valid_placement(board, x, y);

// executing placement
void execute_placement(struct board_tile** board, struct player* players, int curr_player, struct placement p) {
	/*
	int nbr_of_players = get_nbr_of_players(); // save number of players in variable
	int nbr_of_penguins = get_nbr_of_penguins(); // save number of penguins in variable
	while (placement_game_status(nbr_of_penguins) != END_PP) {
		// Loop for asking every player the coordinates
		for (int i = 0; i < nbr_of_players; i++) {
				show_board();
				int x = get_placement_x();
				int y = get_placement_y();
				int valid = valid_placement(board, x, y);
				while (valid == 0)
				{
					printf("Invalid coordinates, try again\n");
					int x = get_placement_x();
					int y = get_placement_y();
					int valid = valid_placement(board, x, y);
				}
				board[coord_x][coord_y] = players[i].id; // show player's id on the board
				nbr_of_penguins--; // reduce number of penguins after every successful placement
			}
	}
	*/
}

// check if there is left some penguins
// arguments: number of penguins (integer)
// returns: 1 if number of penguins equals 0; 0 otherwise 
int placement_game_status(struct board_tile** board, struct player* players) {
	int penguins = 0;
	if (penguins != 0) {
		return 0;
	}
	else {
		return 1;
	}
}

// check if current_player has penguins
// arguments: current_player, number of penguins (integer)
// returns: 1 if current players has penguins, 0 otherwise
int placement_possible(struct board_tile** board, struct player* players, int curr_player) {

}

// ask user to enter X coordinate
// returns this coordinate
int get_placement_x() {
	int coord_x;
	printf("Enter X coordinate (only tiles with 1 fish): ");
	scanf("%d", &coord_x);
	return coord_x;
}

// ask user to enter Y coordinate
// returns this coordinate
int get_placement_y() {
	int coord_y;
	printf("Enter Y coordinate (only tiles with 1 fish): ");
	scanf("%d", &coord_y);
	return coord_y;
}

// check if player entered valid coordinate
// arguments: board (map), X coordinate from get_placement_x function, Y coordinate from get_placement_y function
// returns 1 if coords valid, 0 otherwise
int valid_placement(struct board_tile** board, struct placement p) {
	/*
	if ((coord_x > 0) && (coord_y > 0) && (coord_x < board[x]) && (coord_y < board[y]) && board[coord_x][coord_y] == -1)
		return 1;
	else
		return 0;
	*/
}
