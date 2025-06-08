#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Color definitions
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

// Game settings
#define HAND_COUNT 3
#define ADJUSTMENT_VALUE 3
#define GAME_SPEED 1

typedef enum {
    ROCK,
    SCISSORS,
    PAPER,
    INVALID_HAND
} hand_t;

typedef enum {
    DRAW,
    LOSE,
    WIN
} result_t;

typedef struct {
    hand_t player_hand;
    hand_t computer_hand;
    result_t result;
} game_t;

void init_game(void);
const char *get_hand_name(hand_t hand);
hand_t get_user_hand(void);
hand_t get_computer_hand(void);
result_t judge_result(hand_t player_hand, hand_t computer_hand);
void play_janken(hand_t player_hand, hand_t computer_hand);

#endif