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
        if (strcmp(players[i].name, name) == 0) { // strcmp() to compare names
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
        if (strcmp(players[i].name, name) == 0) { // strcmp() to compare names
            players[i].score += score;
            return; // Exit function after updating score
        } 
    }
    // If the function has not returned, the player was not found
    printf("Player %s not found!\n", name);
}


// Splits a player input string into name and score using strtok()
void parse_player_input(char *input, char *name, int *score) {
    // Get first token (player name)
    char *token = strtok(input, ",");
    if (token != NULL) {
        strcpy(name, token);

        // Get second token (score)
        token = strtok(NULL, ",");
        if (token != NULL) {
            *score = atoi(token);
        } else {
            *score = 0; // Default to 0 if no score is provided
            printf("Warning: No score found for player %s, defaulting to 0.\n", name);
        }
    } else {
        printf("Error: Invalid input format. Expected: \"Name,Score\"\n");
    }
}

// Combines a player's name and score into a single formatted string
void format_player_output(player *p, char *output) {
    sprintf(output, "%s: %d points", p->name, p->score);
}

// Combines a player's name and score into a single formatted string
void display_players(player *players, int num_players) {
    printf("\nJeopardy Players:\n");
    printf("-----------------\n");
    for (int i = 0; i < num_players; i++) {
        char output[MAX_LEN];  // Buffer to store formatted string
        format_player_output(&players[i], output);
        printf("%s\n", output);
    }
    printf("-----------------\n");
}


