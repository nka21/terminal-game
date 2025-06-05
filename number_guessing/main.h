#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Color definitions
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BOLD "\033[1m"

// Game settings
#define GAME_SPEED 2.0
#define MIN 0
#define MAX 9

int get_user_pred(void);
size_t run_pred_game(int target, double game_speed);
void print_result(size_t result);
void init_game(void);

#endif