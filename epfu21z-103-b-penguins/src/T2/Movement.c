#include <stdio.h>
#include "input.c"
#include "stuctures.h"
#include "gameplay_functions.h"
int input_x(int x)
{
    int position_x;
    printf("Enter x coordinate of the penguin you want to choose: ");
    scanf("%d", &position_x);
    if (position_x > 1 && position_x <= x)
    {
        return position_x;   
    }
    else
    {
        printf("invalid cooordinates\n");
        input_x(x);
    }
}
int input_y(int y)
{
    int position_y;
    printf("Enter y coordinate of the penguin you want to choose: ");
    scanf("%d", &position_y);
    if (position_y > 1 && position_y <= y)
    {
        return position_y;
    }
    else
    {
        printf("invalid cooordinates\n");
        input_y(y);
    }
}
int check_possible_moves()
{
}
int choosing_penguin()
{
}
int moving_penguin()
{
}
int checking_valid_cords()
{
}
/* int main()
{
    int x = get_x_dimension();
    int y = get_y_dimension();
    int position_x = input_x(x);
    int position_y = input_y(y);
    // checking what is the current player
    // checking if there are any penguins left who can move
    // getting cords
    // checking if there is a current player's penguin on that tile
    // getting cords to move on
    // checking if cords are valid
    // switch players
} */
