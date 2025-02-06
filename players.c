/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <Vinujen>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "players.h"

// Returns true if the player name matches one of the existing players
bool player_exists(player *players, int num_players, char *name)
{
    for (int i = 0; i < num_players; i++) {
        if (strcm(players[i].name, name) == 0) { // strcmp() to compare names
        return true;

        }
    }
    return false;
}

// Go through the list of players and update the score for the 
// player given their name
void update_score(player *players, int num_players, char *name, int score)
{ 
    for (int i = 0; i < num_players; i++) {
        if (strcm(players[i].name, name) == 0) { // strcmp() to compare names
    players[i].score += score;
    return;
        } 
}
printf("Player %s not found!\n", name);
}

// Splits a player input string into name and score using strtok()

void parse_player_input(char *input, char *name, int *score) {
    char *token = strtok(NULL, ",");
    if (token != NULL) {
        if (token != NULL) {
            strcpy(name, token);
            token = strtok(NULL, ",");
        }
        if (token != NULL) {
            *score = atoi(token);
        }
    }
}
// Combines a player's name and score into a single formatted string
void format_player_output(player *p, char *output) {
    sprintf(output, "%s: %d points", p->name, p->score);  // Use strcat() to append if needed
}
// Displays all players and their scores
void display_players(player *players, int num_players) {
    printf("\nJeopardy Players:\n");
    printf("-----------------\n");
    for (int i = 0; i < num_players; i++) {
        if (strlen(players[i].name) > 0) {  // strlen() to check if name is valid
            printf("%s: %d points\n", players[i].name, players[i].score);
        }
    }
    printf("-----------------\n");
}
