#ifndef AUTOFUN
#define AUTOFUN
// function is run by main if game is played in autonomous mode, executes command given in command line arguments
// arguments: game state, number of command line arguments, command line arguments
// returns: no value
void execute_autonomous_command(struct GameState* state, int argc, char **argv);
// these functions only run in autonomous mode, check if command line arguments are valid - according to documentation
// arguments: number of command line arguments, command line arguments
// returns: no value 
void invalid_cla_check(int argc, char **argv);
#endif
