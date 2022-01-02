#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structures.h"
//#include "command_line_ui.c"
//#include <conio.h>
//#include "input.c"
void generate_board(struct board_tile** board, int x_size, int y_size)
{
    srand(time(0));
    for (int j = 0; j < y_size; j++) // Map generation
    {
        for (int i = 0; i < x_size; i++)
        {
            board[i][j].fishes = (rand() % 3 + 1); // random value for fish on a tile
            if ((j == 0) || (j == (y_size - 1)) || (i == 0) || (i == (x_size - 1)))
            {
                board[i][j].fishes = 0; // making tiles on the perimetr ocean
            }
        }
    }
}
void show_board(struct board_tile** board, int x_size, int y_size)
{
    printf("   ");
    for (int i = 0; i < x_size; i++)
    {
        printf("%4d", i); // x counter
        if (i == x_size - 1)
        {
            printf("\n");
        }
    }
    for (int j = 0; j < y_size; j++)
    {
        for (int i = 0; i < x_size; i++)
        {
            if ((j == 0) && (i == 0))
            {
                printf("%-4d", j); // first line, index
                printf("| %-2d", board[i][j].fishes);
            }
            else
            {
                printf("| %-2d", board[i][j].fishes);
            }
            if (i == x_size - 1)
            {
                printf("|\n");
                if (j != (y_size - 1))
                {
                    printf("%-4d", j + 1);
                }
            }
        }
    }
}
/* int main()
{
    int x = get_x_dimension();
    int y = get_y_dimension();
    int len = sizeof(struct board_tile*) * y + sizeof(struct board_tile) * x * y;
    struct board_tile** board  = (struct board_tile **)malloc(len);
    generate_board(x, y,board);
    show_board(x, y,board);
     int position_x = input_x(x);
    int position_y = input_y(y);
     checking who1x is the current player
     checking if there are any penguins left who can move
     getting cords
    checking if there is a current player's penguin on that tile
    getting cords to move on
     checking if cords are valid
     switch players
} */
