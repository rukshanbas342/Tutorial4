/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#ifndef PLAYERS_H_
#define PLAYERS_H_

#include <stdbool.h>

#define MAX_LEN 256

// Player struct for each player
typedef struct {
    char name[MAX_LEN];
    int score;
} player;

// Returns true if the player name matches one of the existing players
extern bool player_exists(player *players, int num_players, char *name);

// Go through the list of players and update the score for the 
// player given their name
extern void update_score(player *players, int num_players, char *name, int score);

// Parses a player's input string into name and score
extern void parse_player_input(char *input, char *name, int *score);

// Formats a player's name and score into a single string
extern void format_player_output(player *p, char *output);

// Displays all players and their scores
extern void display_players(player *players, int num_players);

#endif /* PLAYERS_H_ */
