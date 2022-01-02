#include <stdio.h>
//#include <structures.h>
//#include <gameplay_functions.h>

int current_player = 1;
int number_of_penguins;

int get_number_of_players() {}

int get_x_dimension() {}

int get_y_dimension() {}

int show_map() {}

int main() {
	int coord_x, coord_y;
	for (int i = 0; i < number_of_penguins; i++){
		for (int j = 0; j < get_number_of_players(); j++) {
			show_map();
			printf("Enter X coordinate (only tiles with 1 fish): ");
			scanf("%d", &coord_x);
			printf("Enter Y coordinate (only tiles with 1 fish): ");
			scanf("%d", &coord_y);
			while((coord_x < 0) || (coord_y < 0) || (coord_x > get_x_dimension()) || (coord_y > get_y_dimension())) //  || (board[coord_x][coord_y]) != 1
			{
				printf("Invalid coordinates, try again\n");
				printf("Enter X coordinate (only tiles with 1 fish): ");
				scanf("%d", &coord_x);
				printf("Enter Y coordinate (only tiles with 1 fish): ");
				scanf("%d", &coord_y);
			}
			board[coord_x][coord_y] = names_of_players[j]; // struct
				
		}
	}

	return 0;
}